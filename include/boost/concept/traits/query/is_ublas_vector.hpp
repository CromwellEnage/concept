// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_UBLAS_VECTOR_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_UBLAS_VECTOR_HPP

#include <boost/concept/traits/query/is_subscriptable.hpp>
#include <boost/concept/traits/trivial_access/value_type_of.hpp>
#include <boost/concept/traits/trivial_access/size_type_of.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_convertible.hpp>
#include <boost/type_traits/add_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_ublas_vector_with_subscript
      : ::boost::concept::traits::is_subscriptable<
            T
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
          , typename ::boost::add_const<
#else
          , typename ::std::add_const<
#endif
                typename ::boost::concept::traits::size_type_of<T>::type
            >::type
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
          , ::boost::is_convertible<
#else
          , ::boost::mpl::if_<
                ::std::is_convertible<
#endif
                    ::boost::mpl::_
                  , typename ::boost::concept::traits::value_type_of<T>::type
                >
#if !defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
              , ::boost::mpl::true_
              , ::boost::mpl::false_
            >
#endif
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include \
<boost/concept/traits/_detail/metafunction/has_computed_assignment_ops.hpp>
#include <boost/mpl/eval_if.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_ublas_vector_operators
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::_detail::metafunction
            ::is_ublas_vector_with_subscript<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::add_const<T>::type
#else
                typename ::std::add_const<T>::type
#endif
            >
          , ::boost::mpl::if_<
                ::boost::concept::traits::_detail::metafunction
                ::is_ublas_vector_with_subscript<T>
              , ::boost::concept::traits::_detail::metafunction
                ::has_computed_assignment_ops<T>
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_ublas_vector_expression.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_insert_element.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_erase_element.hpp>
#include <boost/concept/traits/introspection/member_function/has_clear.hpp>
#include <boost/concept/traits/introspection/member_function/has_swap.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_const.hpp>
#endif

//[reference__is_ublas_vector
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_ublas_vector
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_is_ublas_vector_expression_<T>
          , _mpl_eval_if_<
                _std_is_base_of_<
                    _numeric_ublas_vector_container_<
                        typename _std_remove_const_<T>::type
                    >
                  , typename _std_remove_const_<T>::type
                >
              , _mpl_eval_if_<
                    _bct_is_subscriptable_<
                        typename _std_add_const_<T>::type
                      , typename _std_add_const_<
                            typename _bct_size_type_of_<T>::type
                        >
                      , _mpl_if_<
                            _std_is_convertible_<
                                _mpl_placeholder_
                              , typename _bct_value_type_of_<T>::type
                            >
                          , _mpl_true_
                          , _mpl_false_
                        >
                    >
                  , _mpl_eval_if_<
                        _bct_is_subscriptable_<
                            typename _std_remove_const_<T>::type
                          , typename _std_add_const_<
                                typename _bct_size_type_of_<T>::type
                            >
                          , _mpl_if_<
                                _std_is_convertible_<
                                    _mpl_placeholder_
                                  , typename _bct_value_type_of_<T>::type
                                >
                              , _mpl_true_
                              , _mpl_false_
                            >
                        >
                      , _mpl_eval_if_<
                            _std_is_const_<T>
                          , _mpl_true_
                          , _mpl_eval_if_<
                                _bct_has_insert_element_<T>
                              , _mpl_eval_if_<
                                    _bct_has_erase_element_<T>
                                  , _mpl_if_<
                                        _bct_has_clear_<T>
                                      , _bct_has_resize_<T>
                                      , _mpl_false_
                                    >
                                  , _mpl_false_
                                >
                              , _mpl_false_
                            >
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
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_ublas_vector_expression<T>
          , ::boost::mpl::eval_if<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                ::boost::is_const<T>
#else
                ::std::is_const<T>
#endif
              , ::boost::concept::traits::_detail::metafunction
                ::is_ublas_vector_with_subscript<T>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::_detail::metafunction
                    ::has_ublas_vector_operators<T>
                  , ::boost::mpl::eval_if<
                        ::boost::concept::traits::has_insert_element<T>
                      , ::boost::mpl::eval_if<
                            ::boost::concept::traits::has_erase_element<T>
                          , ::boost::mpl::if_<
                                ::boost::concept::traits::has_clear<T>
                              , ::boost::concept::traits::has_swap<T>
                              , ::boost::mpl::false_
                            >
                          , ::boost::mpl::false_
                        >
                      , ::boost::mpl::false_
                    >
                  , ::boost::mpl::false_
                >
            >
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

