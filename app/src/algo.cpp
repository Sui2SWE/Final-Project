/**
 * @file algo.cpp
 */

#include "algo.h"

bool Algo::DFS(ConnectedTxs txs, string start, string goal) {
	stack<string> s;
	unordered_map<string, bool> visited;

	if (!txs.count(start)) {
		// cout << "Start node not found" << endl;
		return false;
	}

	for (auto const& [tx, other_txs] : txs) { // vertex
		visited[tx] = false;
	}

	s.push(start);
	while (!s.empty()) {
		string tx = s.top();
		s.pop();

		if (!visited[tx]) {
			visited[tx] = true;
			for (auto const& [otx_tx, otx_obj_id] : txs[tx]) { // adjacent vertices
				if (!visited[otx_tx]) {
					s.push(otx_tx);
				}
			}
		}
	}

	return visited.count(goal) > 0 && visited[goal];
}

// Function to find the minimum distance node from the set of
// nodes not yet included in shortest path tree
pair<string, int> Algo::shortestPath(
	unordered_map<string, int> &dist,
	unordered_map<string, bool> &visited
) {
	// Initialize min value
	int min_gas = 2147483647; // max int
	string min_node;

	for (const auto &[tx_digest, gas_used]: dist) {
		if (!visited[tx_digest] && min_gas > gas_used) {
			min_gas = gas_used;
			min_node = tx_digest;
		}
	}

	return make_pair(min_node, min_gas);
}

// Function to print the shortest path and distance
// from source to destination using Dijkstra's algorithm
int Algo::djikstra(
	ConnectedTxs txs,
	string src,
	string dest
) {
	unordered_map<string, int> dist;
	unordered_map<string, bool> visited;

	// Intialize all distances as MAX and visited as false
	for (const auto &[tx_digest, adj] : txs) {
		dist[tx_digest] = 2147483647; // max int
		visited[tx_digest] = false;
	}

	dist[src] = 0; // start is at 0

	for (size_t i = 0; i < txs.size() - 1; i++) {
		// Find the minimum distance node from the set of nodes not yet
		// included in shortest path tree
		const auto [min_node, min_gas] = Algo::shortestPath(dist, visited);

		// Mark the selected node as visited
		visited[min_node] = true;

		// Update distance value of the adjacent nodes of the selected node
		for (const auto &[adj_tx_digest, adj_tx_data]: txs[min_node]) {
			const auto &[adj_tx_obj_id, adj_tx_gas] = adj_tx_data;
			// If the node is not visited and there is a path from source
			// to the node through the selected node with distance
			// less than the current distance of the node
			if (!visited[adj_tx_digest] && dist[min_node] + adj_tx_gas < dist[adj_tx_digest]) {
				dist[adj_tx_digest] = dist[min_node] + adj_tx_gas;
			}
		}
	}

	// cout << "Shortest distance from " << src << " to " << dest << ": "
	// 			<< dist[dest] << endl;
	return dist[dest] == 0 ? -1 : dist[dest];
}
