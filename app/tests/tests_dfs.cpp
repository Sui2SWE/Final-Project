#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>

#include "sui2swe.h"
#include "algo.h"

ConnectedTxs txs_example_1 = {
	{
		"tx1", {
			{"tx2", "obj2"},
			{"tx3", "obj3"},
		},
	},
	{
		"tx2", {
			{"tx4", "obj4"},
		},
	},
	{
		"tx3", {
			{"tx5", "obj5"},
		},
	},
	{
		"tx4", {
			{"tx5", "obj5"},
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