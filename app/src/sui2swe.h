/**
 * @file sui2swe.h
 */

#pragma once

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

typedef vector<vector<string>> V2D;

typedef vector<pair<string, string>> ConnectedTxData; // <tx_digest, obj_id>

typedef unordered_map<string, ConnectedTxData> ConnectedTxs;

typedef unordered_map<string, unordered_map<string, unsigned int>> GasTxs; // {tx_digest : {tx_digest : gas, tx_digest : gas, ...}, ...}

class Sui2Swe {
	public:
		// Sui2Swe();

		void file_to_connected_txs(const string &filename);

		ConnectedTxs txs;

		unordered_map<string, unsigned int> timestamps;

		GasTxs gas_used;
	
	private:
};
