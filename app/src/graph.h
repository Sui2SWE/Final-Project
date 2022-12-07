/**
 * @file graph.h
 */

#pragma once
#include <vector>
#include <list>
#include <fstream>
#include <unordered_map>
// #include <pair>

using namespace std;

typedef unordered_map<string, unordered_map<string, pair<string, int>>> ConnectedTxs; // {tx_digest : {tx_dgiest : (obj_id, gas_price), ...}, ...}

class Graph {
	public:
		class Node {
			public:
				string tx_id;
				int cost;
				Node(string id) {
					this->tx_id = id;
					this->cost = 2147483647; // int max
				};
		};

		class Edge {
			public:
				string obj_id;
				int weight;
				Edge(string id, int weight) {
					this->obj_id = id;
					this->weight = weight;
				}
		};

		Graph(ConnectedTxs txs);

    list<Node> *adj;
		int num_nodes;
};