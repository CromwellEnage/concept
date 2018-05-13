// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_COMPRESSED_PAIR_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_COMPRESSED_PAIR_HPP

#include <boost/concept/traits/query/is_callable.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/concept/traits/introspection/nested_type/is_first_type_of.hpp>
#else
#include \
<boost/concept/traits/introspection/nested_type/is_first_reference_of.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_compressed_pair_first_predicate
    {
        template <typename F>
        struct apply
        {
            typedef ::boost::concept::traits::is_callable<
                F()
              , ::boost::concept::traits
#if defined(BOOST_NO_CXX11_DECLTYPE)
                ::is_first_type_of< ::boost::mpl::_,T>
#else
                ::is_first_reference_of< ::boost::mpl::_,T>
#endif
            > type;
        };
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include \
<boost/concept/traits/introspection/nested_type/is_second_type_of.hpp>
#else
#include \
<boost/concept/traits/introspection/nested_type/is_second_reference_of.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_compressed_pair_second_predicate
    {
        template <typename S>
        struct apply
        {
            typedef ::boost::concept::traits::is_callable<
                S()
              , ::boost::concept::traits
#if defined(BOOST_NO_CXX11_DECLTYPE)
                ::is_second_type_of< ::boost::mpl::_,T>
#else
                ::is_second_reference_of< ::boost::mpl::_,T>
#endif
            > type;
        };
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_runtime_pair.hpp>

//[reference__is_compressed_pair
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_compressed_pair
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _bct_is_runtime_pair_<
            T
          , _bct_is_callable_<
                _mpl_placeholder_()
              , _bct_is_first_reference_of_<
                    _mpl_placeholder_
                  , T
                >
            >
          , _bct_is_callable_<
                _mpl_placeholder_()
              , _bct_is_second_reference_of_<
                    _mpl_placeholder_
                  , T
                >
            >
        >
//<-
#else
      : ::boost::concept::traits::is_runtime_pair<
            T
          , ::boost::concept::traits::_detail::metafunction
            ::is_compressed_pair_first_predicate<T>
          , ::boost::concept::traits::_detail::metafunction
            ::is_compressed_pair_second_predicate<T>
        >
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

