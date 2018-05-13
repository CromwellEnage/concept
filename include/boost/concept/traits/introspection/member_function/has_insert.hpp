// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_INSERT_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_INSERT_HPP

#include <boost/utility/declref.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <
        typename T
      , typename Param1
      , typename Param2
      , typename Param3
      , typename ResultPlaceholderExpr
    >
    struct has_insert_impl
      : ::boost::mpl::apply1<
            ResultPlaceholderExpr
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF_KEYWORD
#else
          , decltype
#endif
            ((
                ::boost::declref<T>().insert(
                    ::boost::declref<Param1>()
                  , ::boost::declref<Param2>()
                  , ::boost::declref<Param3>()
                )
            ))
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/policy/use_default.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <
        typename T
      , typename Param1
      , typename Param2
      , typename ResultPlaceholderExpr
    >
    struct has_insert_impl<
        T
      , Param1
      , Param2
      , ::boost::concept::policy::use_default
      , ResultPlaceholderExpr
    > : ::boost::mpl::apply1<
            ResultPlaceholderExpr
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF_KEYWORD
#else
          , decltype
#endif
            ((
                ::boost::declref<T>().insert(
                    ::boost::declref<Param1>()
                  , ::boost::declref<Param2>()
                )
            ))
        >::type
    {
    };

    template <typename T, typename ResultPlaceholderExpr, typename Param>
    struct has_insert_impl<
        T
      , Param
      , ::boost::concept::policy::use_default
      , ::boost::concept::policy::use_default
      , ResultPlaceholderExpr
    > : ::boost::mpl::apply1<
            ResultPlaceholderExpr
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF_KEYWORD
#else
          , decltype
#endif
            (::boost::declref<T>().insert(::boost::declref<Param>()))
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/tti/detail/dnullptr.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_pointer.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <
        typename T
      , typename Param1
      , typename Param2
      , typename Param3
      , typename ResultPlaceholderExpr
    >
    class has_insert
    {
        template <typename B, typename P1, typename P2, typename P3>
        static ::boost::type_traits::yes_type
            _check(
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::add_pointer<
#else
                typename ::std::add_pointer<
#endif
#if defined BOOST_NO_CXX11_DECLTYPE
                    BOOST_TYPEOF_KEYWORD
#else
                    decltype
#endif
                    ((
                        ::boost::declref<B>().insert(
                            ::boost::declref<P1>()
                          , ::boost::declref<P2>()
                          , ::boost::declref<P3>()
                        )
                    ))
                >::type
            );

        template <typename B, typename P1, typename P2, typename P3>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef typename ::boost::mpl::if_c<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_insert<
                            T
                          , Param1
                          , Param2
                          , Param3
                          , ResultPlaceholderExpr
                        >::_check<T,Param1,Param2,Param3>(
                            BOOST_TTI_DETAIL_NULLPTR
                        )
                    ) == sizeof(::boost::type_traits::yes_type)
                  , ::boost::concept::traits::_detail::metafunction
                    ::has_insert_impl<
                        T
                      , Param1
                      , Param2
                      , Param3
                      , ResultPlaceholderExpr
                    >
                  , ::boost::mpl::false_
                >::type
                type;
    };

    template <
        typename T
      , typename Param1
      , typename Param2
      , typename ResultPlaceholderExpr
    >
    class has_insert<
        T
      , Param1
      , Param2
      , ::boost::concept::policy::use_default
      , ResultPlaceholderExpr
    >
    {
        template <typename B, typename P1, typename P2>
        static ::boost::type_traits::yes_type
            _check(
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::add_pointer<
#else
                typename ::std::add_pointer<
#endif
#if defined BOOST_NO_CXX11_DECLTYPE
                    BOOST_TYPEOF_KEYWORD
#else
                    decltype
#endif
                    ((
                        ::boost::declref<B>().insert(
                            ::boost::declref<P1>()
                          , ::boost::declref<P2>()
                        )
                    ))
                >::type
            );

        template <typename B, typename P1, typename P2>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef typename ::boost::mpl::if_c<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_insert<
                            T
                          , Param1
                          , Param2
                          , ::boost::concept::policy::use_default
                          , ResultPlaceholderExpr
                        >::_check<T,Param1,Param2>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                  , ::boost::concept::traits::_detail::metafunction
                    ::has_insert_impl<
                        T
                      , Param1
                      , Param2
                      , ::boost::concept::policy::use_default
                      , ResultPlaceholderExpr
                    >
                  , ::boost::mpl::false_
                >::type
                type;
    };

    template <typename T, typename ResultPlaceholderExpr, typename Param>
    class has_insert<
        T
      , Param
      , ::boost::concept::policy::use_default
      , ::boost::concept::policy::use_default
      , ResultPlaceholderExpr
    >
    {
        template <typename B, typename P>
        static ::boost::type_traits::yes_type
            _check(
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::add_pointer<
#else
                typename ::std::add_pointer<
#endif
#if defined BOOST_NO_CXX11_DECLTYPE
                    BOOST_TYPEOF_KEYWORD
#else
                    decltype
#endif
                    (::boost::declref<B>().insert(::boost::declref<P>()))
                >::type
            );

        template <typename B, typename P>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef typename ::boost::mpl::if_c<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_insert<
                            T
                          , Param
                          , ::boost::concept::policy::use_default
                          , ::boost::concept::policy::use_default
                          , ResultPlaceholderExpr
                        >::_check<T,Param>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                  , ::boost::concept::traits::_detail::metafunction
                    ::has_insert_impl<
                        T
                      , Param
                      , ::boost::concept::policy::use_default
                      , ::boost::concept::policy::use_default
                      , ResultPlaceholderExpr
                    >
                  , ::boost::mpl::false_
                >::type
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/member_function_fwd.hpp>
#include <boost/concept/traits/introspection/nested_type/is_iterator_of.hpp>

//[reference__has_insert
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename Param1
      , typename Param2
      , typename Param3
      , typename ResultPlaceholderExpr
    >
    struct has_insert
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            typename _mpl_eval_if_<
                _std_is_same_<Param3,boost::concept::policy::use_default>
              , _mpl_if_<
                    _std_is_same_<Param2,boost::concept::policy::use_default>
                  , _is_valid_expression_(
                        _declref_<T>().insert(_declref_<Param1>())
                    )
                  , _is_valid_expression_(
                        _declref_<T>().insert(
                            _declref_<Param1>()
                          , _declref_<Param2>()
                        )
                    )
                >
              , _is_valid_expression_(
                    _declref_<T>().insert(
                        _declref_<Param1>()
                      , _declref_<Param2>()
                      , _declref_<Param3>()
                    )
                )
            >::type
          , _mpl_eval_if_<
                _std_is_same_<Param3,boost::concept::policy::use_default>
              , _mpl_eval_if_<
                    _std_is_same_<Param2,boost::concept::policy::use_default>
                  , _mpl_apply1_<
                        ResultPlaceholderExpr
                      , _decltype_(
                            _declref_<T>().insert(
                                _declref_<Param1>()
                            )
                        )
                    >
                  , _mpl_apply_wrap1_<
                        ResultPlaceholderExpr
                      , _decltype_(
                            _declref_<T>().insert(
                                _declref_<Param1>()
                              , _declref_<Param2>()
                            )
                        )
                    >
                >
              , _mpl_apply_wrap1_<
                    ResultPlaceholderExpr
                  , _decltype_(
                        _declref_<T>().insert(
                            _declref_<Param1>()
                          , _declref_<Param2>()
                          , _declref_<Param3>()
                        )
                    )
                >
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::concept::traits::_detail::metafunction
        ::has_insert<T,Param1,Param2,Param3,ResultPlaceholderExpr>::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

