// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_OUTPUT_ITERATOR_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_OUTPUT_ITERATOR_HPP

#include <boost/concept/traits/introspection/is_convertible_to_cref_of.hpp>
#include <boost/concept/traits/declref.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/typeof/typeof.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_output_iterator_post_increment
      : ::boost::concept::traits::is_convertible_to_cref_of<
#if defined(BOOST_NO_CXX11_DECLTYPE)
            BOOST_TYPEOF_KEYWORD(::boost::concept::traits::declref<T>()++)
#else
            decltype(::boost::concept::traits::declref<T>()++)
#endif
          , T
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/tti/detail/dnullptr.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/declval.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

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
    class has_output_iterator_operators
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
                        >()++ = ::boost::declval<V>()
                    )
#else
                    decltype(
                        *::boost::concept::traits::declref<
                            B
                        >()++ = ::boost::declval<V>()
                    )
#endif
                >::type
            );

        template <typename B, typename V>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef typename ::boost::mpl::if_c<
            sizeof(
                ::boost::concept::traits::_detail::metafunction
                ::has_output_iterator_operators<T,Value,_mutable_T>
                ::BOOST_NESTED_TEMPLATE
                _check<_mutable_T,Value>(BOOST_TTI_DETAIL_NULLPTR)
            ) == sizeof(::boost::type_traits::yes_type)
          , ::boost::concept::traits::_detail::metafunction
            ::has_output_iterator_post_increment<_mutable_T>
          , ::boost::mpl::false_
        >::type type;
    };

    template <typename T, typename B>
    class has_output_iterator_operators<T,void,B>
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
    struct has_output_iterator_default_operators
      : ::boost::concept::traits::_detail::metafunction
        ::has_output_iterator_operators<
            T
          , typename ::boost::concept::traits::iterator_value_of<T>::type
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_writable_iterator.hpp>
#include <boost/concept/traits/query/is_incrementable.hpp>
#include <boost/concept/policy/use_default.hpp>
#include <boost/mpl/eval_if.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/is_same.hpp>
#endif

//[reference__is_output_iterator
namespace boost { namespace concept { namespace traits {

    template <typename T, typename Value>
    struct is_output_iterator
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _bct_is_incrementable_<
                typename _std_remove_const_<
                    typename _std_remove_reference_<T>::type
                >::type
            >
          , _mpl_eval_if_<
                _bct_is_writable_iterator_<T,Value>
              , _mpl_eval_if_<
                    _bct_is_convertible_to_cref_of_<
                        _decltype_(
                            _bct_declref_<
                                typename _std_remove_const_<
                                    typename _std_remove_reference_<T>::type
                                >::type
                            >()++
                        )
                      , T
                    >
                  , _mpl_if_<
                        _std_is_same_<
                            Value
                          , boost::concept::policy::use_default
                        >
                      , _is_valid_expression_(
                            *_bct_declref_<
                                typename _std_remove_const_<
                                    typename _std_remove_reference_<T>::type
                                >::type
                            >()++ = _declval_<
                                typename _bct_iterator_value_of_<T>::type
                            >()
                        )
                      , _is_valid_expression_(
                            *_bct_declref_<
                                typename _std_remove_const_<
                                    typename _std_remove_reference_<T>::type
                                >::type
                            >()++ = _declval_<Value>()
                        )
                    >
                  , _mpl_false_
                >
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_incrementable<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::remove_const<
                    typename ::boost::remove_reference<T>::type
                >::type
#else
                typename ::std::remove_const<
                    typename ::std::remove_reference<T>::type
                >::type
#endif
            >
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::is_writable_iterator<T,Value>
              , ::boost::mpl::eval_if<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                    ::boost::is_same<
#else
                    ::std::is_same<
#endif
                        Value
                      , ::boost::concept::policy::use_default
                    >
                  , ::boost::concept::traits::_detail::metafunction
                    ::has_output_iterator_default_operators<T>
                  , ::boost::concept::traits::_detail::metafunction
                    ::has_output_iterator_operators<T,Value>
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

