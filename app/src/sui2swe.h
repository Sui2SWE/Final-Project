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

#include "graph.h"
#include "algo.cpp"


typedef vector<vector<string>> V2D;

// typedef unordered_map<string, unordered_map<string, string>> ConnectedTxs; // {tx_digest : {tx_dgiest : obj_id, ...}, ...}

typedef unordered_map<string, unordered_map<string, int>> GasTxs; // {tx_digest : {tx_digest : gas, tx_digest : gas, ...}, ...}

class Sui2Swe {
	public:
		// Sui2Swe();

		void file_to_graph(const string &filename);

		void create_graph();

		ConnectedTxs txs;

		unordered_map<string, int> timestamps;

		GasTxs gas_used;
	
		// Graph graph;
	private:
};
