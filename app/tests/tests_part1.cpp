#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>

#include "sui2swe.h"

TEST_CASE("test 1", "[weight=5]") {
	Sui2Swe s;

	s.file_to_connected_txs("../../data/tx-data.csv");

	for (auto const& [tx_digest, other_txs] : s.txs) {
		cout << "=====================================" << endl;
		cout << ">>> TX: " << tx_digest << endl;
		for (pair<string, string> otx : other_txs) {
			cout << "<< OTX: " << otx.first << "\t-> obj id: " << otx.second << endl;
		}
	}

	REQUIRE(true);
}