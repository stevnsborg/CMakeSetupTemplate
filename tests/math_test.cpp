#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../src/math.h"

TEST_CASE("Addition of two integers", "[addValues]") {
	REQUIRE(addValues(1, 2) == 3);
	REQUIRE(addValues(-1, 1) == 0);
	REQUIRE(addValues(-1, -1) == -2);
	REQUIRE(addValues(0, 0) == 0);
})