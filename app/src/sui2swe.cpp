/**
 * @file sui2swe.cpp
 */

#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <unordered_map>

#include "sui2swe.h"
#include "utils.h"

using namespace std;

vector<string> get_object_data(string other_tx) {
	vector<string> otx_elems;
	SplitString(other_tx, ' ', otx_elems);
	// otx_object_id, otx_tx_digest
	return vector<string>({otx_elems[0], otx_elems[2]});
}

int string_to_number(string s) {
	int n;
	stringstream ss(s);
	ss >> n;
	return n;
}

void Sui2Swe::file_to_graph(const string &filename){
	string s = file_to_string(filename);

	vector<string> lines;
	SplitString(s, '\n', lines);

	// transaction_digest, timestamp_ms, shared_objects_tx_digest, shared_objects_str, created_str, mutated_str, gas_used
	vector<string> headers;
	SplitString(lines[0], ',', headers);

	for (unsigned i = 1; i < lines.size(); i++) {
		vector<string> elems;
		SplitString(lines[i], ',', elems);
		// cout << "0: " << elems[0] << endl;
		// cout << "1: " << elems[1] << endl;
		// cout << "s: " << stoi(Trim(elems[1])) << endl;
		// cout << "2: " << elems[2] << endl;

		string tx_digest = elems[0];

		// timestamps[tx_digest] = stoi(elems[1]);
		// if (!txs.count(tx_digest)) txs[tx_digest] = unordered_map<string, string>(); // init map for this tx

		if (!gas_used.count(tx_digest)) gas_used[tx_digest] = unordered_map<string, int>(); // init new map (if not exists)
		// gas_used[tx_digest][tx_digest] = stoi(elems[6]);

		vector<string> shared_otxs;
		vector<string> created_otxs;
		vector<string> mutated_otxs;

		// NOTE: Shared txs are INPUT, so graph maps the direction as {otx_tx_digest -> tx_digest}
		if (!elems[3].empty()) {
			vector<string> shared_otxs;
			SplitString(elems[3], '|', shared_otxs);

			for (string shared_otx : shared_otxs) {
				vector<string> otx_data = get_object_data(shared_otx);
				string otx_object_id = otx_data[0];
				string otx_tx_digest = otx_data[1];

				if (!txs.count(otx_tx_digest)) txs[otx_tx_digest] = unordered_map<string, pair<string, int>>(); // init map for this tx
				// TODO: fix gas
				txs[otx_tx_digest][tx_digest] = make_pair(otx_object_id, 1); // string_to_number(elems[6])
			}
		}

		// NOTE: Mutated & Created txs are OUTPUT, so graph maps the direction as {tx_digest -> otx_tx_digest}
		for (unsigned j = 4; j <= 5; j++) {
			if (elems[j].empty()) continue; // skip empty fields
			vector<string> output_txs;
			SplitString(elems[j], '|', output_txs);

			for (string output_tx : output_txs) {
				vector<string> otx_data = get_object_data(output_tx);
				string otx_object_id = otx_data[0];
				string otx_tx_digest = otx_data[1];

				if (!txs.count(tx_digest)) txs[tx_digest] = unordered_map<string, pair<string, int>>(); // init map for this tx
				// TODO: fix gas
				txs[tx_digest][otx_tx_digest] = make_pair(otx_object_id, 1); // string_to_number(elems[6])
			}
		}

		// graph = Graph(txs);
	}
}