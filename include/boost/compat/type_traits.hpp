#ifndef BOOST_COMPAT_TYPE_TRAITS_HPP_INCLUDED
#define BOOST_COMPAT_TYPE_TRAITS_HPP_INCLUDED

// Copyright 2024 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <type_traits>

namespace boost {
namespace compat {

template<class T> using remove_const_t = typename std::remove_const<T>::type;
template<class T> using remove_cv_t = typename std::remove_cv<T>::type;
template<class T> using remove_reference_t = typename std::remove_reference<T>::type;
template<class T> using remove_cvref_t = remove_cv_t< remove_reference_t<T> >;

template<bool B, class T = void> using enable_if_t = typename std::enable_if<B, T>::type;

} // namespace compat
} // namespace boost

#endif // BOOST_COMPAT_TYPE_TRAITS_HPP_INCLUDED
