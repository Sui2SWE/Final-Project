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


void Sui2Swe::file_to_connected_txs(const string &filename){
	string s = file_to_string(filename);

	vector<string> lines;
	SplitString(s, '\n', lines);

	// transaction_digest, timestamp_ms, shared_objects_tx_digest, shared_objects_str, created_str, mutated_str, gas_used
	vector<string> headers;
	SplitString(lines[0], ',', headers);

	for (unsigned i = 1; i < lines.size(); i++) {
		vector<string> elems;
		SplitString(lines[i], ',', elems);

		string tx_digest = elems[0];

		// timestamps[tx_digest] = stoi(elems[1]);
		txs[tx_digest] = ConnectedTxData(); // init vector for this tx

		if (!gas_used.count(tx_digest)) gas_used[tx_digest] = unordered_map<string, unsigned int>(); // init new map (if not exists)
		// gas_used[tx_digest][tx_digest] = stoi(elems[6]);


		for (unsigned j = 2; j < 5; j++) {
			if (elems[j].empty()) continue; // skip empty fields
			vector<string> other_txs;
			SplitString(elems[j], '|', other_txs);

			for (string other_tx : other_txs) {
				vector<string> otx_elems;
				SplitString(other_tx, ' ', otx_elems);

				string otx_object_id = otx_elems[0];
				string otx_tx_digest = otx_elems[2];
				txs[tx_digest].push_back(make_pair(otx_tx_digest, otx_object_id)); // make_pair implicitly infers type
			}
		}
	}
}
