// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_ALLOCATE_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_ALLOCATE_HPP

#include <boost/concept/traits/trivial_access/allocator_size_of.hpp>
#include <boost/concept/traits/declref.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/type_traits/declval.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/typeof/typeof.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename U, typename ResultPlaceholderExpr>
    struct has_allocate_impl
      : ::boost::mpl::apply1<
            ResultPlaceholderExpr
#if defined(BOOST_NO_CXX11_DECLTYPE)
          , BOOST_TYPEOF_KEYWORD((
                ::boost::concept::traits::declref<T>().allocate(
                    ::boost::declval<
                        typename ::boost::concept::traits
                        ::allocator_size_of<T>::type
                    >()
                  , ::boost::declval<U>()
                )
            ))
#else
          , decltype(
                ::boost::concept::traits::declref<T>().allocate(
                    ::boost::declval<
                        typename ::boost::concept::traits
                        ::allocator_size_of<T>::type
                    >()
                  , ::boost::declval<U>()
                )
            )
#endif  // BOOST_NO_CXX11_DECLTYPE
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/policy/use_default.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename U, typename ResultPlaceholderExpr>
    struct has_allocate_impl<
        T
      , ::boost::concept::policy::use_default
      , ResultPlaceholderExpr
    > : ::boost::mpl::apply1<
            ResultPlaceholderExpr
#if defined(BOOST_NO_CXX11_DECLTYPE)
          , BOOST_TYPEOF_KEYWORD(
                ::boost::concept::traits::declref<T>().allocate(
                    ::boost::declval<
                        typename ::boost::concept::traits
                        ::allocator_size_of<T>::type
                    >()
                )
            )
#else
          , decltype(
                ::boost::concept::traits::declref<T>().allocate(
                    ::boost::declval<
                        typename ::boost::concept::traits
                        ::allocator_size_of<T>::type
                    >()
                )
            )
#endif  // BOOST_NO_CXX11_DECLTYPE
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/tti/detail/dnullptr.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/add_pointer.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename U>
    class has_allocate
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
                        ::boost::declref<B>().allocate(
                            ::boost::declval<
                                typename ::boost::concept::traits
                                ::allocator_size_of<B>::type
                            >()
                          , ::boost::declval<V>()
                        )
                    )
#else
                    decltype(
                        ::boost::declref<B>().allocate(
                            ::boost::declval<
                                typename ::boost::concept::traits
                                ::allocator_size_of<B>::type
                            >()
                          , ::boost::declval<V>()
                        )
                    )
#endif  // BOOST_NO_CXX11_DECLTYPE
                >::type
            );

        template <typename B, typename V>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef typename ::boost::mpl::eval_if_c<
            sizeof(
                ::boost::concept::traits::_detail::metafunction
                ::has_allocate<T,U>::BOOST_NESTED_TEMPLATE
                _check<T,U>(BOOST_TTI_DETAIL_NULLPTR)
            ) == sizeof(::boost::type_traits::yes_type)
          , ::boost::concept::traits::_detail::metafunction
            ::has_allocate_impl<T,U>
          , ::boost::mpl::false_
        >::type type;
    };

    template <typename T>
    class has_allocate<T,::boost::concept::policy::use_default>
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check(
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::add_pointer<
#else
                typename ::std::add_pointer<
#endif
#if defined(BOOST_NO_CXX11_DECLTYPE)
                    BOOST_TYPEOF_KEYWORD(
                        ::boost::declref<B>().allocate(
                            ::boost::declval<
                                typename ::boost::concept::traits
                                ::allocator_size_of<B>::type
                            >()
                        )
                    )
#else
                    decltype(
                        ::boost::declref<B>().allocate(
                            ::boost::declval<
                                typename ::boost::concept::traits
                                ::allocator_size_of<B>::type
                            >()
                        )
                    )
#endif  // BOOST_NO_CXX11_DECLTYPE
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef typename ::boost::mpl::eval_if_c<
            sizeof(
                ::boost::concept::traits::_detail::metafunction
                ::has_allocate<T,::boost::concept::policy::use_default>
                ::BOOST_NESTED_TEMPLATE _check<T>(BOOST_TTI_DETAIL_NULLPTR)
            ) == sizeof(::boost::type_traits::yes_type)
          , ::boost::concept::traits::_detail::metafunction
            ::has_allocate_impl<T,::boost::concept::policy::use_default>
          , ::boost::mpl::false_
        >::type type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/member_function_fwd.hpp>
#include <boost/concept/traits/introspection/nested_type/has_pointer.hpp>
#include <boost/concept/traits/introspection/nested_type/has_value_type.hpp>
#include <boost/mpl/if.hpp>

//[reference__has_allocate
namespace boost { namespace concept { namespace traits {

    template <typename T, typename U, typename ResultPlaceholderExpr>
    struct has_allocate
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            typename _mpl_if_<
                _bct_has_pointer_<T>
              , _mpl_true_
              , _bct_has_value_type_<T>
            >::type
          , _mpl_eval_if_<
                _std_is_same_<U,boost::concept::policy::use_default>
              , _mpl_eval_if_<
                    _is_valid_expression_(
                        _bct_declref_<T>().allocate(
                            _declval_<
                                typename _bct_allocator_size_of_<T>::type
                            >()
                        )
                    )
                  , _mpl_apply1_<
                        ResultPlaceholderExpr
                      , _decltype_(
                            _bct_declref_<T>().allocate(
                                _declval_<
                                    typename _bct_allocator_size_of_<T>::type
                                >()
                            )
                        )
                    >
                  , _mpl_false_
                >
              , _mpl_eval_if_<
                    _is_valid_expression_(
                        _bct_declref_<T>().allocate(
                            _declval_<
                                typename _bct_allocator_size_of_<T>::type
                            >()
                          , _declval_<U>()
                        )
                    )
                  , _mpl_apply1_<
                        ResultPlaceholderExpr
                      , _decltype_(
                            _bct_declref_<T>().allocate(
                                _declval_<
                                    typename _bct_allocator_size_of_<T>::type
                                >()
                            )
                          , _declval_<U>()
                        )
                    >
                  , _mpl_false_
                >
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::eval_if<
            typename ::boost::mpl::if_<
                ::boost::concept::traits::has_pointer<T>
              , ::boost::mpl::true_
              , ::boost::concept::traits::has_value_type<T>
            >::type
          , ::boost::concept::traits::_detail::metafunction
            ::has_allocate<T,U,ResultPlaceholderExpr>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

