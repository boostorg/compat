#ifndef BOOST_COMPAT_NONTYPE_HPP_INCLUDED
#define BOOST_COMPAT_NONTYPE_HPP_INCLUDED

// Copyright 2024 Christian Mazakas
// Copyright 2025 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost/config.hpp>

#if defined(__cpp_nontype_template_parameter_auto) && __cpp_nontype_template_parameter_auto >= 201606L
#define BOOST_COMPAT_HAS_AUTO_NTTP
#endif

namespace boost {
namespace compat {

#if defined(BOOST_COMPAT_HAS_AUTO_NTTP)

template <auto V>
struct nontype_t {
  explicit nontype_t() = default;
};

# if defined(__cpp_variable_templates) && __cpp_variable_templates >= 201304L

template<auto V>
BOOST_INLINE_CONSTEXPR nontype_t<V> nontype {};

# endif

#endif

} // namespace compat
} // namespace boost

#endif // BOOST_COMPAT_NONTYPE_HPP_INCLUDED
