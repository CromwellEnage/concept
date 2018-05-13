// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_CAPACITY_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_CAPACITY_HPP

#include <boost/utility/declref.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_capacity_impl
      : ::boost::mpl::apply1<
            ResultPlaceholderExpr
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF_KEYWORD(::boost::declcref<T>().capacity())
#else
          , decltype(::boost::declcref<T>().capacity())
#endif
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/tti/detail/dnullptr.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_pointer.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    class has_capacity_expr
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
                    BOOST_TYPEOF_KEYWORD(::boost::declcref<B>().capacity())
#else
                    decltype(::boost::declcref<B>().capacity())
#endif
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef ::boost::mpl::bool_<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_capacity_expr<T>
                        ::_check<T>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                >
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/mpl/if.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_std_capacity
      : ::boost::mpl::if_<
            typename ::boost::concept::traits::_detail::metafunction
            ::has_capacity_expr<T>::type
          , ::boost::concept::traits::_detail::metafunction
            ::has_capacity_impl<T,ResultPlaceholderExpr>
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/remove_const.hpp>
#if !defined BOOST_NO_CXX11_DECLTYPE
#include <boost/type_traits/remove_reference.hpp>
#endif
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_ptr_capacity
      : ::boost::concept::traits::_detail::metafunction::has_std_capacity<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF_KEYWORD(
                ::boost::declref<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                    typename ::boost::remove_const<T>::type
#else
                    typename ::std::remove_const<T>::type
#endif
                >().base()
            )
#else   // !defined BOOST_NO_CXX11_DECLTYPE
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            typename ::boost::remove_const<
                typename ::boost::remove_reference<
#else
            typename ::std::remove_const<
                typename ::std::remove_reference<
#endif
                    decltype(
                        ::boost::declref<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                            typename ::boost::remove_const<T>::type
#else
                            typename ::std::remove_const<T>::type
#endif
                        >().base()
                    )
                >::type
            >::type
#endif  // BOOST_NO_CXX11_DECLTYPE
          , ResultPlaceholderExpr
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/member_function_fwd.hpp>
#include \
<boost/concept/traits/introspection/nested_type/is_capacity_type_of.hpp>
#include \
<boost/concept/traits/_detail/metafunction/has_ptr_container_members.hpp>

//[reference__has_capacity
namespace boost { namespace concept { namespace traits {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_capacity
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_is_ptr_container_<T>
          , _mpl_eval_if_<
                _is_valid_expression_(
                    _declref_<
                        typename _std_remove_const_<
                            typename _std_remove_reference_<
                                _decltype_(_declref_<T>().base())
                            >::type
                        >::type
                    >().capacity()
                )
              , _mpl_apply1_<
                    ResultPlaceholderExpr
                  , _decltype_(
                        _declref_<
                            typename _std_remove_const_<
                                typename _std_remove_reference_<
                                    _decltype_(_declref_<T>().base())
                                >::type
                            >::type
                        >().capacity()
                    )
                >
              , _mpl_false_
            >
          , _mpl_eval_if_<
                _is_valid_expression_(_declcref_<T>().capacity())
              , _mpl_apply1_<
                    ResultPlaceholderExpr
                  , _decltype_(_declcref_<T>().capacity())
                >
              , _mpl_false_
            >
        >::type
//<-
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::mpl::if_<
            ::boost::concept::traits::_detail::metafunction
            ::has_ptr_container_members<T>
          , ::boost::concept::traits::_detail::metafunction
            ::has_ptr_capacity<T,ResultPlaceholderExpr>
          , ::boost::concept::traits::_detail::metafunction
            ::has_std_capacity<T,ResultPlaceholderExpr>
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

