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

