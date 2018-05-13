// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_WRITABLE_ITERATOR_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_WRITABLE_ITERATOR_HPP

#include <boost/concept/traits/declref.hpp>
#include <boost/tti/detail/dnullptr.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/declval.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/typeof/typeof.hpp>
#endif

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/add_pointer.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <
        typename T
      , typename Value
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      , typename _mutable_T = typename ::boost::remove_const<
            typename ::boost::remove_reference<T>::type
        >::type
#else
      , typename _mutable_T = typename ::std::remove_const<
            typename ::std::remove_reference<T>::type
        >::type
#endif
    >
    class has_writable_iterator_operator
    {
        template <typename B, typename V>
        static ::boost::type_traits::yes_type
            _check(
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::add_pointer<
#else
                typename ::std::add_pointer<
#endif
#if defined(BOOST_NO_CXX11_DECLTYPE)
                    BOOST_TYPEOF_KEYWORD(
                        *::boost::concept::traits::declref<
                            B
                        >() = ::boost::declval<V>()
                    )
#else
                    decltype(
                        *::boost::concept::traits::declref<
                            B
                        >() = ::boost::declval<V>()
                    )
#endif
                >::type
            );

        template <typename B, typename V>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::boost::concept::traits::_detail::metafunction
                ::has_writable_iterator_operator<T,Value>
                ::BOOST_NESTED_TEMPLATE
                _check<_mutable_T,Value>(BOOST_TTI_DETAIL_NULLPTR)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };

    template <typename T, typename B>
    class has_writable_iterator_operator<T,void,B>
    {
     public:
        typedef ::boost::mpl::false_ type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/trivial_access/iterator_value_of.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_writable_iterator_default
      : ::boost::concept::traits::_detail::metafunction
        ::has_writable_iterator_operator<
            T
          , typename ::boost::concept::traits::iterator_value_of<T>::type
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/policy/use_default.hpp>
#include <boost/mpl/eval_if.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/is_same.hpp>
#endif

//[reference__is_writable_iterator
namespace boost { namespace concept { namespace traits {

    template <typename T, typename Value>
    struct is_writable_iterator
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_if_<
            _std_is_same_<Value,boost::concept::policy::use_default>
          , _is_valid_expression_(
                *_bct_declref_<
                    typename _std_remove_const_<
                        typename _std_remove_reference_<T>::type
                    >::type
                >() = _declval_<
                    typename _bct_iterator_value_of_<T>::type
                >()
            )
          , _is_valid_expression_(
                *_bct_declref_<
                    typename _std_remove_const_<
                        typename _std_remove_reference_<T>::type
                    >::type
                >() = _declval_<Value>()
            )
        >::type
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::mpl::eval_if<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
            ::boost::is_same<Value,::boost::concept::policy::use_default>
#else
            ::std::is_same<Value,::boost::concept::policy::use_default>
#endif
          , ::boost::concept::traits::_detail::metafunction
            ::is_writable_iterator_default<T>
          , ::boost::concept::traits::_detail::metafunction
            ::has_writable_iterator_operator<T,Value>
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#include <boost/iterator/indirect_iterator.hpp>

namespace boost { namespace concept { namespace traits {

    template <
        typename I
      , typename V
      , typename C
      , typename R
      , typename D
      , typename Value
    >
    struct is_writable_iterator<
        ::boost::iterators::indirect_iterator<I,V,C,R,D>
      , Value
    > : ::boost::concept::traits::is_writable_iterator<I,Value>
    {
    };

    template <
        typename I
      , typename V
      , typename C
      , typename R
      , typename D
      , typename Value
    >
    struct is_writable_iterator<
        ::boost::iterators::indirect_iterator<I,V,C,R,D> const
      , Value
    > : ::boost::concept::traits::is_writable_iterator<I,Value>
    {
    };

    template <
        typename I
      , typename V
      , typename C
      , typename R
      , typename D
      , typename Value
    >
    struct is_writable_iterator<
        ::boost::iterators::indirect_iterator<I,V,C,R,D>&
      , Value
    > : ::boost::concept::traits::is_writable_iterator<I,Value>
    {
    };

    template <
        typename I
      , typename V
      , typename C
      , typename R
      , typename D
      , typename Value
    >
    struct is_writable_iterator<
        ::boost::iterators::indirect_iterator<I,V,C,R,D> const&
      , Value
    > : ::boost::concept::traits::is_writable_iterator<I,Value>
    {
    };
}}}  // namespace boost::concept::traits

#include <boost/iterator/transform_iterator.hpp>

namespace boost { namespace concept { namespace traits {

    template <typename U, typename I, typename R, typename V, typename Value>
    struct is_writable_iterator<
        ::boost::iterators::transform_iterator<U,I,R,V>
      , Value
    > : ::boost::concept::traits::is_writable_iterator<I,Value>
    {
    };

    template <typename U, typename I, typename R, typename V, typename Value>
    struct is_writable_iterator<
        ::boost::iterators::transform_iterator<U,I,R,V> const
      , Value
    > : ::boost::concept::traits::is_writable_iterator<I,Value>
    {
    };

    template <typename U, typename I, typename R, typename V, typename Value>
    struct is_writable_iterator<
        ::boost::iterators::transform_iterator<U,I,R,V>&
      , Value
    > : ::boost::concept::traits::is_writable_iterator<I,Value>
    {
    };

    template <typename U, typename I, typename R, typename V, typename Value>
    struct is_writable_iterator<
        ::boost::iterators::transform_iterator<U,I,R,V> const&
      , Value
    > : ::boost::concept::traits::is_writable_iterator<I,Value>
    {
    };
}}}  // namespace boost::concept::traits

#endif  // include guard

