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
		static void shortestPath();
		static void topologicalSort();
};

#endif
