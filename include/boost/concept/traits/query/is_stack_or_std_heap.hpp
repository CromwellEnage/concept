// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_STACK_OR_STD_HEAP_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_STACK_OR_STD_HEAP_HPP

#include <boost/concept/traits/introspection/member_function/has_top.hpp>
#include \
<boost/concept/traits/_detail/metafunction/has_std_cont_adapt_members.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_stack_or_std_heap_impl
      : ::boost::mpl::if_<
            ::boost::concept::traits::_detail::metafunction
            ::has_std_container_adaptor_members<T>
          , ::boost::concept::traits::has_top<T const>
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

//[reference__is_stack_or_std_heap
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_stack_or_std_heap
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_has_push_<typename _std_remove_const_<T>::type>
          , _mpl_eval_if_<
                _bct_has_pop_<typename _std_remove_const_<T>::type>
              , _mpl_eval_if_<
                    _bct_has_size_<
                        typename _std_add_const_<T>::type
                    >
                  , _mpl_if_<
                        _bct_has_empty_<
                            typename _std_add_const_<T>::type
                        >
                      , _bct_has_top_<
                            typename _std_add_const_<T>::type
                        >
                      , _mpl_false_
                    >
                  , _mpl_false_
                >
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::concept::traits::_detail::metafunction
        ::is_stack_or_std_heap_impl<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            typename ::boost::remove_const<T>::type
#else
            typename ::std::remove_const<T>::type
#endif
        >
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

