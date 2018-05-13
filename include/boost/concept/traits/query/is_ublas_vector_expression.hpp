// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_UBLAS_VECTOR_EXPRESSION_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_UBLAS_VECTOR_EXPRESSION_HPP

#include <boost/concept/traits/query/is_callable.hpp>
#include <boost/concept/traits/trivial_access/value_type_of.hpp>
#include <boost/concept/traits/trivial_access/size_type_of.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_convertible.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_ublas_vector_expression_element_operator
      : ::boost::concept::traits::is_callable<
            T(typename ::boost::concept::traits::size_type_of<T>::type)
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
          , ::boost::is_convertible<
#else
          , ::std::is_convertible<
#endif
                ::boost::mpl::_
              , typename ::boost::concept::traits::value_type_of<T>::type
            >
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/remove_const.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_ublas_vector_expression_impl
      : ::boost::mpl::if_<
            ::boost::concept::traits::_detail::metafunction
            ::has_ublas_vector_expression_element_operator<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::add_const<T>::type
#else
                typename ::std::add_const<T>::type
#endif
            >
          , ::boost::concept::traits::_detail::metafunction
            ::has_ublas_vector_expression_element_operator<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::remove_const<T>::type
#else
                typename ::std::remove_const<T>::type
#endif
            >
          , ::boost::mpl::false_
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/introspection/nested_type/has_value_type.hpp>
#include <boost/concept/traits/introspection/nested_type/has_size_type.hpp>
#include \
<boost/concept/traits/introspection/nested_type/is_type_category_of.hpp>
#include <boost/numeric/ublas/fwd.hpp>
#include <boost/mpl/eval_if.hpp>

//[reference__is_ublas_vector_expression
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_ublas_vector_expression
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
          _bct_has_value_type_<T>
        , _mpl_eval_if_<
            _bct_has_size_type_<T>
          , _mpl_eval_if_<
              _bct_is_type_category_of_<
                boost::numeric::ublas::vector_tag
              , T
              >
            , _mpl_if_<
                _bct_is_callable_<
                  typename _std_add_const_<T>::type(
                    typename _std_remove_const<T>_::type::size_type
                  )
                , _std_is_convertible_<
                    _mpl_placeholder_
                  , typename _std_remove_const_<T>::type::value_type
                  >
                >
              , _bct_is_callable_<
                  typename _std_remove_const<T>::type(
                    typename _std_remove_const<T>_::type::size_type
                  )
                , _std_is_convertible_<
                    _mpl_placeholder_
                  , typename _std_remove_const_<T>::type::value_type
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
            ::boost::concept::traits::has_value_type<T>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_size_type<T>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::is_type_category_of<
                        ::boost::numeric::ublas::vector_tag
                      , T
                    >
                  , ::boost::concept::traits::_detail::metafunction
                    ::is_ublas_vector_expression_impl<T>
                  , ::boost::mpl::false_
                >
              , ::boost::mpl::false_
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

