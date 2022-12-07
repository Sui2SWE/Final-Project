#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>

#include "sui2swe.h"
#include "algo.h"

typedef unordered_map<string, unordered_map<string, pair<string, int>>> ConnectedTxs;

ConnectedTxs txs_example_1 = {
	{
		"tx1", {
			{"tx2", {"obj2", 1}},
			{"tx3", {"obj3", 1}},
		},
	},
	{
		"tx2", {
			{"tx4", {"obj4", 2}},
		},
	},
	{
		"tx3", {
			{"tx5", {"obj5", 3}},
		},
	},
	{
		"tx4", {
			{"tx5", {"obj5", 1}},
		},
	},
	{
		"tx5", {},
	},
};

TEST_CASE("test dfs empty", "[weight=5][algo=dfs][type=dummy]") {
	bool found = Algo::DFS({}, "tx1", "tx5");
	REQUIRE(!found);
}

TEST_CASE("test dfs find", "[weight=5][algo=dfs][type=dummy]") {
	bool found = Algo::DFS(txs_example_1, "tx1", "tx5");
	REQUIRE(found);
}

TEST_CASE("test dfs NO find", "[weight=5][algo=dfs][type=dummy]") {
	bool found = Algo::DFS(txs_example_1, "tx2", "tx3");
	REQUIRE(!found);
}

TEST_CASE("test djikstra empty", "[weight=5][algo=djikstra][type=dummy]") {
	int num = Algo::djikstra({}, "tx1", "tx5");
	REQUIRE(num == -1);
}

TEST_CASE("test djikstra find", "[weight=5][algo=djikstra][type=dummy]") {
	ConnectedTxs graph = {
		{"tx1", {{"tx2", make_pair("obj2", 2)}}},
		// {"tx2", {{"tx1", make_pair("obj1", 1)}, {"tx2", make_pair("obj2", 2)}, {"tx3", make_pair("obj3", 3)}}},
		// {"tx3", {{"tx1", make_pair("obj1", 1)}, {"tx2", make_pair("obj2", 2)}, {"tx3", make_pair("obj3", 3)}}},
		// {"tx4", {{"tx1", make_pair("obj1", 1)}, {"tx2", make_pair("obj2", 2)}, {"tx3", make_pair("obj3", 3)}}},
		// {"tx5", {{"tx1", make_pair("obj1", 1)}, {"tx2", make_pair("obj2", 2)}, {"tx3", make_pair("obj3", 3)}}},
		{"tx2", {}}
	};

	int num = Algo::djikstra(graph, "tx1", "tx2");
	REQUIRE(num == 2);
}

// TEST_CASE("test dfs NO find", "[weight=5][algo=dfs][type=dummy]") {
// 	bool found = Algo::DFS(graph, "tx2", "tx3");
// 	REQUIRE(!found);
// }