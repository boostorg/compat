// Copyright 2024 Ruben Perez Hidalgo.
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost/compat/to_array.hpp>

#include <utility>

namespace compat = boost::compat;

// Most array members are not constexpr until late C++ standards,
// so we just test that code compiles
constexpr int input[] = {1, 2, 3};
constexpr auto output_lvalue = compat::to_array(input);
constexpr auto output_rvalue = compat::to_array(std::move(input));

int main() {}
