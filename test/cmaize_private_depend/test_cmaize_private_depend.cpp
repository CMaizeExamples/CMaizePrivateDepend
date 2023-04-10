#include <catch2/catch_test_macros.hpp>

#include <cmaize_private_depend/cmaize_private_depend.hpp>

using namespace cmaize_private_depend;

TEST_CASE("cmaize_private_depend") {
    SECTION("does_cmaize_private_depend_work") {
        REQUIRE(call_cmaize_private_depend() == 5);
    }
}
