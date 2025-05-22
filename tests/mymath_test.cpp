#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "mymath.h"


TEST_CASE("Addition of two integers", "[addValues]") {
	REQUIRE(addValues(1, 2) == 3);
	REQUIRE(addValues(-1, 1) == 0);
	REQUIRE(addValues(-1, -1) == -2);
	REQUIRE(addValues(0, 0) == 0);
	REQUIRE(addValues(0, 0) == 1);
}