// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_HEAP_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_HEAP_HPP

#include <boost/concept/traits/query/is_stack_or_std_heap.hpp>
#include <boost/concept/traits/introspection/nested_type/has_pointer.hpp>
#include <boost/concept/traits/introspection/nested_type/has_reference.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_difference_type.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_value_compare.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_get_allocator.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_heap_impl
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_get_allocator<T const>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::is_stack_or_std_heap<T>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_difference_type<T>
                  , ::boost::mpl::eval_if<
                        ::boost::concept::traits::has_value_compare<T>
                      , ::boost::mpl::eval_if<
                            ::boost::concept::traits::has_reference<T const>
                          , ::boost::mpl::eval_if<
                                ::boost::concept::traits::has_pointer<T const>
                              , ::boost::mpl::if_<
                                    ::boost::concept::traits::has_reference<T>
                                  , ::boost::concept::traits::has_pointer<T>
                                  , ::boost::mpl::false_
                                >
                              , ::boost::mpl::false_
                            >
                          , ::boost::mpl::false_
                        >
                      , ::boost::mpl::false_
                    >
                  , ::boost::mpl::false_
                >
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >
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

//[reference__is_heap
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_heap
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_has_get_allocator_<
                typename _std_add_const_<T>::type
            >
          , _mpl_eval_if_<
                _bct_is_stack_or_std_heap_<T>
              , _mpl_eval_if_<
                    _bct_has_difference_type_<T>
                  , _mpl_eval_if_<
                        _bct_has_value_compare_<T>
                      , _mpl_eval_if_<
                            _bct_has_reference_<
                                typename _std_remove_const_<T>::type
                            >
                          , _mpl_eval_if_<
                                _bct_has_pointer_<
                                    typename _std_remove_const_<T>::type
                                >
                              , _mpl_if_<
                                    _bct_has_reference_<
                                        typename _std_add_const_<T>::type
                                    >
                                  , _bct_has_pointer_<
                                        typename _std_add_const_<T>::type
                                    >
                                  , _mpl_false_
                                >
                              , _mpl_false_
                            >
                          , _mpl_false_
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
      : ::boost::concept::traits::_detail::metafunction::is_heap_impl<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            typename ::boost::remove_const<T>::type
#else
            typename ::std::remove_const<T>::type
#endif
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

