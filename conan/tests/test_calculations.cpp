#include "Calculations.h"

#include <catch2/catch_test_macros.hpp>


TEST_CASE("addThenMultiplyBy returns the expected result", "[calculations]") {
	REQUIRE(addThenMultiplyBy(1, 2) == 6);
}
