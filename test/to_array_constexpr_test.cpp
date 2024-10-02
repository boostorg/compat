// Copyright 2024 Ruben Perez Hidalgo.
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost/compat/to_array.hpp>

#include <utility>

namespace compat = boost::compat;

int main()
{
    // Most array members are not constexpr until late C++ standards,
    // so we just test that code compiles
    constexpr int input[] = {1, 2, 3};
    constexpr auto output_lvalue = compat::to_array(input);
    constexpr auto output_rvalue = compat::to_array(static_cast<decltype(input)&&>(input));
    static_cast<void>(output_lvalue);
    static_cast<void>(output_rvalue);
}
