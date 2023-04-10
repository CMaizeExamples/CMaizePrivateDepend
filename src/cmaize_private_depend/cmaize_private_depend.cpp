#include "cmaize_private_depend/cmaize_private_depend.hpp"

namespace cmaize_private_depend {

int call_cmaize_private_depend() {
    return cmake_private::call_cmake_private() + 2;
}

} // namespace cmaize_private_depend
