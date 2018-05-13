// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_DATA_HAS_LEFT_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_DATA_HAS_LEFT_HPP

#include <boost/utility/declref.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename PlaceholderExpr>
    struct has_left_impl
      : ::boost::mpl::apply1<
            PlaceholderExpr
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF_TPL(::boost::declref<T>().left)
#else
          , decltype(::boost::declref<T>().left)
#endif
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_left_default
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
      : ::boost::is_same<
#else
      : ::boost::mpl::if_<
            ::std::is_same<
#endif
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF_TPL(::boost::declref<T>().left)
#else
                decltype(::boost::declref<T>().left)
#endif
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
              , typename ::boost::remove_const<T>::type::left_map
#else
              , typename ::std::remove_const<T>::type::left_map
#endif
            >
#if !defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
          , ::boost::mpl::true_
          , ::boost::mpl::false_
        >::type
#endif
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type/has_left_map.hpp>
#include <boost/concept/policy/use_default.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_left_impl<T,::boost::concept::policy::use_default>
      : ::boost::mpl::if_<
            ::boost::concept::traits::has_left_map<T>
          , ::boost::concept::traits::_detail::metafunction
            ::has_left_default<T>
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/tti/detail/dnullptr.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_pointer.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    class has_left_expr
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check(
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::add_pointer<
#else
                typename ::std::add_pointer<
#endif
#if defined BOOST_NO_CXX11_DECLTYPE
                    BOOST_TYPEOF_TPL(::boost::declref<B>().left)
#else
                    decltype(::boost::declref<B>().left)
#endif
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef ::boost::mpl::bool_<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_left_expr<T>
                        ::_check<T>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                >
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/member_data_fwd.hpp>

//[reference__has_left
namespace boost { namespace concept { namespace traits {

    template <typename T, typename PlaceholderExpr>
    struct has_left
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _is_valid_expression_(_declref_<T>().left)
          , _mpl_eval_if_<
                _std_is_same_<
                    PlaceholderExpr
                  , boost::concept::traits::use_default
                >
              , _mpl_eval_if_<
                    _bct_has_left_map_<T>
                  , _mpl_if_<
                        _std_is_same_<
                            _decltype_(_declref_<T>().left)
                          , typename _std_remove_const_<T>::type::left_map
                        >
                      , _mpl_true_
                      , _mpl_false_
                    >
                  , _mpl_false_
                >
              , _mpl_apply1_<
                    PlaceholderExpr
                  , _decltype_(_declref_<T>().left)
                >
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::if_<
            typename ::boost::concept::traits::_detail::metafunction
            ::has_left_expr<T>::type
          , ::boost::concept::traits::_detail::metafunction
            ::has_left_impl<T,PlaceholderExpr>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

