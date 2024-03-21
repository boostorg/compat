#ifndef BOOST_COMPAT_INVOKE_HPP_INCLUDED
#define BOOST_COMPAT_INVOKE_HPP_INCLUDED

// Copyright 2024 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost/compat/mem_fn.hpp>
#include <boost/compat/detail/returns.hpp>
#include <utility>

namespace boost {
namespace compat {

template<class F, class... A>
auto invoke( F&& f, A&&... a )
BOOST_COMPAT_RETURNS( std::forward<F>(f)(std::forward<A>(a)...) )

template<class M, class T, class... A>
auto invoke( M T::* pm, A&&... a )
BOOST_COMPAT_RETURNS( mem_fn(pm)(std::forward<A>(a)...) )

} // namespace compat
} // namespace boost

#endif // BOOST_COMPAT_INVOKE_HPP_INCLUDED
