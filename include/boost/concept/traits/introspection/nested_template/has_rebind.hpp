// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_NESTED_TEMPLATE_HAS_REBIND_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_NESTED_TEMPLATE_HAS_REBIND_HPP

#include <boost/mpl/has_xxx.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    BOOST_MPL_HAS_XXX_TEMPLATE_NAMED_DEF(has_rebind, rebind, false)
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type_fwd.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#endif

//[reference__has_rebind
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct has_rebind
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_has_template_named_(rebind)<
            typename _std_remove_const_<
                typename _std_remove_reference_<T>::type
            >::type
        >::type
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::concept::traits::_detail::metafunction::has_rebind<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
            typename ::boost::remove_const<
                typename ::boost::remove_reference<T>::type
            >::type
#else
            typename ::std::remove_const<
                typename ::std::remove_reference<T>::type
            >::type
#endif
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

