// #include <catch2/catch_test_macros.hpp>

// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <vector>
// #include <set>

// #include "sui2swe.h"

// TEST_CASE("test 1", "[weight=5][create_graph]") {
// 	Sui2Swe s;

// 	s.file_to_graph("../../data/tx-data.csv");

// 	for (auto const& [tx_digest, other_txs] : s.txs) {
// 		cout << "=====================================" << endl;
// 		cout << ">>> TX: " << tx_digest << endl;
// 		for (auto const& [otx_tx_digest, otx_obj_id] : other_txs) {
// 			cout << "<< OTX: " << otx_tx_digest << "\t-> obj id: " << otx_obj_id << endl;
// 		}
// 	}

// 	REQUIRE(true);
// }