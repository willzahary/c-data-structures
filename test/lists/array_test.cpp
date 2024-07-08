//
// Created by William Henderson on 2024-07-07.
//

#include "catch2/catch_test_macros.hpp"
#include "../../src/lists/array.cpp"

TEST_CASE( "at", "[single-file]" ) {
	Array<int, 3> arr{};
	arr[0] = 1;
	arr[1] = 3;
	arr[2] = 5;
	REQUIRE( arr.at(0) == 1 );
	REQUIRE( arr.at(1) == 3 );
	REQUIRE( arr.at(2) == 5 );
}