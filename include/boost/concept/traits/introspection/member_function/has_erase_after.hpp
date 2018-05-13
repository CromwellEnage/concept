// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_ERASE_AFTER_HPP
#define \
BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_ERASE_AFTER_HPP

#include <boost/utility/declref.hpp>
#include <boost/mpl/apply.hpp>
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
      , typename ResultPlaceholderExpr
    >
    struct has_erase_after_impl
      : ::boost::mpl::apply1<
            ResultPlaceholderExpr
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF_KEYWORD
#else
          , decltype
#endif
            ((
                ::boost::declref<T>().erase_after(
                    ::boost::declref<Param1>()
                  , ::boost::declref<Param2>()
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

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_erase_after_impl<
        T
      , Param
      , ::boost::concept::policy::use_default
      , ResultPlaceholderExpr
    > : ::boost::mpl::apply1<
            ResultPlaceholderExpr
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF_KEYWORD
#else
          , decltype
#endif
            (
                ::boost::declref<T>().erase_after(
                    ::boost::declref<Param>()
                )
            )
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/tti/detail/dnullptr.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

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
      , typename ResultPlaceholderExpr
    >
    class has_erase_after
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
                        ::boost::declref<B>().erase_after(
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
                        ::has_erase_after<
                            T
                          , Param1
                          , Param2
                          , ResultPlaceholderExpr
                        >::BOOST_NESTED_TEMPLATE
                        _check<T,Param1,Param2>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                  , ::boost::concept::traits::_detail::metafunction
                    ::has_erase_after_impl<
                        T
                      , Param1
                      , Param2
                      , ResultPlaceholderExpr
                    >
                  , ::boost::mpl::false_
                >::type
                type;
    };

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    class has_erase_after<
        T
      , Param
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
                    (
                        ::boost::declref<B>().erase_after(
                            ::boost::declref<P>()
                        )
                    )
                >::type
            );

        template <typename B, typename P>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef typename ::boost::mpl::if_c<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_erase_after<
                            T
                          , Param
                          , ::boost::concept::policy::use_default
                          , ResultPlaceholderExpr
                        >::BOOST_NESTED_TEMPLATE
                        _check<T,Param>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                  , ::boost::concept::traits::_detail::metafunction
                    ::has_erase_after_impl<
                        T
                      , Param
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

//[reference__has_erase_after
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename Param1
      , typename Param2
      , typename ResultPlaceholderExpr
    >
    struct has_erase_after
//<-
#if defined BOOST_CONCEPT_TRAITS_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            typename _mpl_if_<
                _std_is_same_<Param2,boost::concept::policy::use_default>
              , _is_valid_expression_(
                    _declref_<T>().erase_after(
                        _declref_<Param1>()
                    )
                )
              , _is_valid_expression_(
                    _declref_<T>().erase_after(
                        _declref_<Param1>()
                      , _declref_<Param2>()
                    )
                )
            >::type
          , _mpl_eval_if_<
                _std_is_same_<Param2,boost::concept::policy::use_default>
              , _mpl_apply1_<
                    ResultPlaceholderExpr
                  , _decltype_(
                        _declref_<T>().erase_after(
                            _declref_<Param1>()
                        )
                    )
                >
              , _mpl_apply1_<
                    ResultPlaceholderExpr
                  , _decltype_(
                        _declref_<T>().erase_after(
                            _declref_<Param1>()
                          , _declref_<Param2>()
                        )
                    )
                >
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::concept::traits::_detail::metafunction
        ::has_erase_after<T,Param1,Param2,ResultPlaceholderExpr>::type
#endif  // BOOST_CONCEPT_TRAITS_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

