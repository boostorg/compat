// Copyright 2024 Ruben Perez Hidalgo.
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost/compat/to_array.hpp>
#include <boost/core/lightweight_test.hpp>

#include <array>
#include <memory>
#include <vector>

namespace compat = boost::compat;

int main()
{
    {
        // lvalue, regular C array
        int input[] = {1, 2};
        auto output = compat::to_array(input);
        static_assert(std::is_same<decltype(output), std::array<int, 2>>::value, "");
        BOOST_TEST_EQ(output[0], 1);
        BOOST_TEST_EQ(output[1], 2);
    }
    {
        // lvalue, values not moved
        const std::vector<int> vec{1, 2};
        std::vector<int> input[]{vec};
        auto output = compat::to_array(input);
        static_assert(std::is_same<decltype(output), std::array<std::vector<int>, 1>>::value, "");
        BOOST_TEST_ALL_EQ(output[0].begin(), output[0].end(), vec.begin(), vec.end());
        BOOST_TEST_ALL_EQ(input[0].begin(), input[0].end(), vec.begin(), vec.end());  // input not modified
    }
    {
        // rvalue, regular C array
        int input[] = {5, 6};
        auto output = compat::to_array(std::move(input));
        static_assert(std::is_same<decltype(output), std::array<int, 2>>::value, "");
        BOOST_TEST_EQ(output[0], 5);
        BOOST_TEST_EQ(output[1], 6);
    }
    {
        // rvalue, values moved
        const std::vector<int> vec{1, 2};
        std::vector<int> input[]{vec};
        auto output = compat::to_array(std::move(input));
        static_assert(std::is_same<decltype(output), std::array<std::vector<int>, 1>>::value, "");
        BOOST_TEST_ALL_EQ(output[0].begin(), output[0].end(), vec.begin(), vec.end());
        BOOST_TEST(input[0].empty());  // input left in a moved-from state
    }
    {
        // rvalue, move-only types work
        std::unique_ptr<int> input[] = {std::unique_ptr<int>{new int(42)}};
        int* ptr = input[0].get();
        auto output = compat::to_array(std::move(input));
        static_assert(std::is_same<decltype(output), std::array<std::unique_ptr<int>, 1>>::value, "");
        BOOST_TEST_EQ(output[0].get(), ptr);
        BOOST_TEST_EQ(input[0].get(), nullptr);  // input left in a moved-from state
    }

    return boost::report_errors();
}
