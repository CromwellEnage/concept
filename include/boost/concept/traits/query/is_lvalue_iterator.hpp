// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_LVALUE_ITERATOR_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_LVALUE_ITERATOR_HPP

#include <boost/concept/traits/declref.hpp>
#include <boost/iterator/iterator_traits.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/typeof/typeof.hpp>
#endif

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/type_traits/is_convertible.hpp>
#else
#include <boost/type_traits/is_same.hpp>
#endif
#else   // !defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/mpl/if.hpp>
#include <type_traits>
#endif  // BOOST_NO_CXX11_HDR_TYPE_TRAITS

#if !defined(BOOST_NO_CXX17_ITERATOR_TRAITS)
#include <iterator>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_lvalue_iterator_impl
#if defined(BOOST_NO_CXX11_DECLTYPE)
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      : ::boost::is_convertible<
#else
      : ::boost::mpl::if_<
            ::std::is_convertible<
#endif
                BOOST_TYPEOF_KEYWORD(*::boost::concept::traits::declref<T>())
              , typename ::boost::iterators::iterator_value<
#else   // !defined(BOOST_NO_CXX11_DECLTYPE)
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      : ::boost::is_same<
#else
      : ::boost::mpl::if_<
            ::std::is_same<
#endif
                decltype(*::boost::concept::traits::declref<T>())
              , typename ::boost::iterators::iterator_reference<
#endif  // BOOST_NO_CXX11_DECLTYPE
#if defined(BOOST_NO_CXX17_ITERATOR_TRAITS)
                    T
#else
                    ::std::iterator_traits<T>
#endif
                >::type
            >
#if !defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
          , ::boost::mpl::true_
          , ::boost::mpl::false_
        >::type
#endif
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/_detail/metafunction/is_dereferenceable.hpp>
#include <boost/mpl/eval_if.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/concept/traits/introspection/nested_type/has_value_type.hpp>
#else
#include <boost/concept/traits/introspection/nested_type/has_reference.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_lvalue_iterator
      : ::boost::mpl::eval_if<
            typename ::boost::concept::traits::_detail::metafunction
            ::is_dereferenceable<T>::type
          , ::boost::mpl::eval_if<
#if defined(BOOST_NO_CXX11_DECLTYPE)
                ::boost::concept::traits::has_value_type<
#else
                ::boost::concept::traits::has_reference<
#endif
#if defined(BOOST_NO_CXX17_ITERATOR_TRAITS)
                    T
#else
                    ::std::iterator_traits<T>
#endif
                >
              , ::boost::concept::traits::_detail::metafunction
                ::is_lvalue_iterator_impl<T>
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#endif

//[reference__is_lvalue_iterator
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_lvalue_iterator
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _bct_has_reference_<
                _std_iterator_traits_<
                    typename _std_remove_const_<
                        typename _std_remove_reference_<T>::type
                    >::type
                >
            >
          , _mpl_eval_if_<
                _is_valid_expression_(
                    *_bct_declref_<
                        typename _std_remove_const_<
                            typename _std_remove_reference_<T>::type
                        >::type
                    >()
                )
              , _mpl_eval_if_<
                    _std_is_void_<
                        _decltype_(
                            *_bct_declref_<
                                typename _std_remove_const_<
                                    typename _std_remove_reference_<T>::type
                                >::type
                            >()
                        )
                    >
                  , _mpl_false_
                  , _mpl_if_<
                        _std_is_same_<
                            _decltype_(
                                *_bct_declref_<
                                    typename _std_remove_const_<
                                        typename _std_remove_reference_<
                                            T
                                        >::type
                                    >::type
                                >()
                            )
                          , typename _iterator_reference_<
                                _std_iterator_traits_<
                                    typename _std_remove_const_<
                                        typename _std_remove_reference_<
                                            T
                                        >::type
                                    >::type
                                >
                            >::type
                        >
                      , _mpl_true_
                      , _mpl_false_
                    >
                >
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::concept::traits::_detail::metafunction::is_lvalue_iterator<
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
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

