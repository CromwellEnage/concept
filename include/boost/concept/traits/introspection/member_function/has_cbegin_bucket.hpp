// Copyright (C) 2016-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_CBEGIN_BUCKET_HPP
#define \
BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_CBEGIN_BUCKET_HPP

#include <boost/utility/declref.hpp>
#include <boost/utility/declval.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_cbegin_bucket_impl
      : ::boost::mpl::apply1<
            ResultPlaceholderExpr
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF_KEYWORD
#else
          , decltype
#endif
            (
                ::boost::declcref<T>().cbegin(
                    ::boost::declval<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                        typename ::boost::remove_const<T>::type::size_type
#else
                        typename ::std::remove_const<T>::type::size_type
#endif
                    >()
                )
            )
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
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    class has_cbegin_bucket
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _ch(
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
                        ::boost::declref<B>().cbegin(
                            ::boost::declval<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                                typename ::boost::remove_const<B>::type
#else
                                typename ::std::remove_const<B>::type
#endif
                                ::size_type
                            >()
                        )
                    )
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _ch(...);

     public:
        typedef ::boost::mpl::bool_<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_cbegin_bucket<T>
                        ::_ch<T>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                >
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/member_function_fwd.hpp>
#include <boost/concept/traits/introspection/nested_type/has_size_type.hpp>
#include \
<boost/concept/traits/introspection/nested_type/is_local_iterator_of.hpp>
#include <boost/mpl/eval_if.hpp>

//[reference__has_cbegin_bucket
namespace boost { namespace concept { namespace traits {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_cbegin_bucket
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_has_size_type_<T>
          , _mpl_eval_if_<
                _is_valid_expression_(
                    _declcref_<T>().cbegin(
                        _declval_<
                            typename _std_remove_const_<T>::type::size_type
                        >()
                    )
                )
              , _mpl_apply1_<
                    ResultPlaceholderExpr
                  , _decltype_(
                        _declcref_<T>().cbegin(
                            _declval_<
                                typename _std_remove_const_<T>::type
                                ::size_type
                            >()
                        )
                    )
                >
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::mpl::eval_if<
            typename ::boost::mpl::eval_if<
                ::boost::concept::traits::has_size_type<T>
              , ::boost::concept::traits::_detail::metafunction
                ::has_cbegin_bucket<T>
              , ::boost::mpl::false_
            >::type
          , ::boost::concept::traits::_detail::metafunction
            ::has_cbegin_bucket_impl<T,ResultPlaceholderExpr>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

