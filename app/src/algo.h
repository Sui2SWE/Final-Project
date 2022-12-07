/**
 * @file algo.h
 */

#ifndef ALGO_H

#pragma once
#include <vector>
#include <list>
#include <stack>
#include <set>

#include "graph.h"

class Algo {
	public:
		static bool DFS(ConnectedTxs txs, string start, string goal);
		static pair<string, int> shortestPath(unordered_map<string, int> &dist, unordered_map<string, bool> &visited);
		static int djikstra(ConnectedTxs txs, string src, string dest);
		static void topologicalSort();
};

#endif
