// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_FUSION_FWD_SEQUENCE_IMPL_HPP
#define \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_FUSION_FWD_SEQUENCE_IMPL_HPP

#include <boost/concept/traits/query/is_mpl_boolean_constant.hpp>
#include <boost/concept/traits/query/is_mpl_integral_constant.hpp>
#include <boost/utility/declref.hpp>
#include <boost/fusion/sequence/intrinsic/begin.hpp>
#if !defined BOOST_CONCEPT_CONFIG_BUG_ATTEMPTS_TO_DEREF_MPL_SET_END
#include <boost/fusion/sequence/intrinsic/end.hpp>
#endif
#include <boost/fusion/sequence/intrinsic/empty.hpp>
#include <boost/fusion/sequence/intrinsic/size.hpp>
#include <boost/fusion/sequence/intrinsic/front.hpp>
#include <boost/fusion/iterator/deref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/is_convertible.hpp>
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_fusion_forward_sequence_range
      : ::boost::mpl::eval_if<
#if defined BOOST_NO_CXX11_DECLTYPE
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            ::boost::is_same<
#else
            ::std::is_same<
#endif
                BOOST_TYPEOF_KEYWORD
#else   // !defined BOOST_NO_CXX11_DECLTYPE
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            ::boost::is_convertible<
#else
            ::std::is_convertible<
#endif
                decltype
#endif  // BOOST_NO_CXX11_DECLTYPE
                (::boost::fusion::begin(::boost::declref<T>()))
              , typename ::boost::fusion::result_of::begin<T>::type
            >
#if !defined BOOST_CONCEPT_CONFIG_BUG_ATTEMPTS_TO_DEREF_MPL_SET_END
          , ::boost::mpl::eval_if<
#if defined BOOST_NO_CXX11_DECLTYPE
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                ::boost::is_same<
#else
                ::std::is_same<
#endif
                    BOOST_TYPEOF_KEYWORD
#else   // !defined BOOST_NO_CXX11_DECLTYPE
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                ::boost::is_convertible<
#else
                ::std::is_convertible<
#endif
                    decltype
#endif  // BOOST_NO_CXX11_DECLTYPE
                    (::boost::fusion::end(::boost::declref<T>()))
                  , typename ::boost::fusion::result_of::end<T>::type
                >
#endif  // BOOST_CONCEPT_CONFIG_BUG_ATTEMPTS_TO_DEREF_MPL_SET_END
              , ::boost::mpl::eval_if<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                    ::boost::is_convertible<
#else
                    ::std::is_convertible<
#endif
                        ::boost::fusion::result_of::empty<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                            typename ::boost::remove_const<T>::type
#else
                            typename ::std::remove_const<T>::type
#endif
                        >
#if defined BOOST_NO_CXX11_DECLTYPE
                      , BOOST_TYPEOF_KEYWORD
#else
                      , decltype
#endif
                        (::boost::fusion::empty(::boost::declcref<T>()))
                    >
                  , ::boost::mpl::eval_if<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                        ::boost::is_same<
#else
                        ::std::is_same<
#endif
                            typename ::boost::fusion::result_of::size<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                                typename ::boost::remove_const<T>::type
#else
                                typename ::std::remove_const<T>::type
#endif
                            >::type
#if defined BOOST_NO_CXX11_DECLTYPE
                          , BOOST_TYPEOF_KEYWORD
#else
                          , decltype
#endif
                            (::boost::fusion::size(::boost::declcref<T>()))
                        >
                      , ::boost::mpl::eval_if<
                            ::boost::concept::traits::is_mpl_boolean_constant<
                                ::boost::fusion::result_of::empty<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                                    typename ::boost::remove_const<T>::type
#else
                                    typename ::std::remove_const<T>::type
#endif
                                >
                            >
                          , ::boost::concept::traits
                            ::is_mpl_integral_constant<
                                typename ::boost::fusion::result_of::size<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                                    typename ::boost::remove_const<T>::type
#else
                                    typename ::std::remove_const<T>::type
#endif
                                >::type
                            >
                          , ::boost::mpl::false_
                        >
                      , ::boost::mpl::false_
                    >
                  , ::boost::mpl::false_
                >
#if !defined BOOST_CONCEPT_CONFIG_BUG_ATTEMPTS_TO_DEREF_MPL_SET_END
              , ::boost::mpl::false_
            >
#endif
          , ::boost::mpl::false_
        >
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
    class has_fusion_forward_sequence_ops
    {
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
        typedef typename ::boost::remove_const<T>::type _mutable_T;
#else
        typedef typename ::std::remove_const<T>::type _mutable_T;
#endif

        template <typename B>
        static ::boost::type_traits::yes_type
            _check_begin(
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
                    (::boost::fusion::begin(::boost::declref<B>()))
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check_begin(...);

#if !defined BOOST_CONCEPT_CONFIG_BUG_ATTEMPTS_TO_DEREF_MPL_SET_END
        template <typename B>
        static ::boost::type_traits::yes_type
            _check_end(
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
                    (::boost::fusion::end(::boost::declref<B>()))
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check_end(...);
#endif  // !defined BOOST_CONCEPT_CONFIG_BUG_ATTEMPTS_TO_DEREF_MPL_SET_END

        template <typename B>
        static ::boost::type_traits::yes_type
            _check_emp(
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
                    (::boost::fusion::empty(::boost::declcref<B>()))
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check_emp(...);

        template <typename B>
        static ::boost::type_traits::yes_type
            _check_size(
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
                    (::boost::fusion::size(::boost::declcref<B>()))
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check_size(...);

     public:
        typedef typename ::boost::mpl::eval_if_c<
                    (
                        sizeof(
                            ::boost::concept::traits::_detail::metafunction
                            ::has_fusion_forward_sequence_ops<T>
                            ::_check_begin<T>(BOOST_TTI_DETAIL_NULLPTR)
                        ) == sizeof(::boost::type_traits::yes_type)
#if !defined BOOST_CONCEPT_CONFIG_BUG_ATTEMPTS_TO_DEREF_MPL_SET_END
                    ) && (
                        sizeof(
                            ::boost::concept::traits::_detail::metafunction
                            ::has_fusion_forward_sequence_ops<T>
                            ::_check_end<T>(BOOST_TTI_DETAIL_NULLPTR)
                        ) == sizeof(::boost::type_traits::yes_type)
#endif
                    ) && (
                        sizeof(
                            ::boost::concept::traits::_detail::metafunction
                            ::has_fusion_forward_sequence_ops<T>
                            ::_check_emp<_mutable_T>(BOOST_TTI_DETAIL_NULLPTR)
                        ) == sizeof(::boost::type_traits::yes_type)
                    ) && (
                        sizeof(
                            ::boost::concept::traits::_detail::metafunction
                            ::has_fusion_forward_sequence_ops<T>
                            ::_check_size<_mutable_T>(BOOST_TTI_DETAIL_NULLPTR)
                        ) == sizeof(::boost::type_traits::yes_type)
                    )
                  , ::boost::concept::traits::_detail::metafunction
                    ::is_fusion_forward_sequence_range<T>
                  , ::boost::mpl::false_
                >::type
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type/has_type.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_fusion_forward_sequence_impl
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_type<
                ::boost::fusion::result_of::size<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                    typename ::boost::remove_const<T>::type
#else
                    typename ::std::remove_const<T>::type
#endif
                >
            >
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_type<
                    ::boost::fusion::result_of::begin<T>
                >
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_type<
                        ::boost::fusion::result_of::end<T>
                    >
                  , ::boost::concept::traits::_detail::metafunction
                    ::has_fusion_forward_sequence_ops<T>
                  , ::boost::mpl::false_
                >
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#if !defined BOOST_CONCEPT_CONFIG_BUG_ATTEMPTS_TO_DEREF_MPL_SET_END
#include \
<boost/concept/traits/_detail/metafunction/is_fusion_fwd_iterator_impl.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_fusion_forward_sequence_front
      : ::boost::mpl::eval_if<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            ::boost::is_same<
#else
            ::std::is_same<
#endif
                typename ::boost::fusion::result_of::front<T>::type
#if defined BOOST_NO_CXX11_DECLTYPE
              , BOOST_TYPEOF_KEYWORD
#else
              , decltype
#endif
                (::boost::fusion::front(::boost::declref<T>()))
            >
          , ::boost::mpl::eval_if<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                ::boost::is_same<
#else
                ::std::is_same<
#endif
                    typename ::boost::fusion::result_of::deref<
                        typename ::boost::fusion::result_of::begin<T>::type
                    >::type
                  , typename ::boost::fusion::result_of::front<T>::type
                >
#if defined BOOST_CONCEPT_CONFIG_BUG_ATTEMPTS_TO_DEREF_MPL_SET_END
              , ::boost::mpl::true_
#else
              , ::boost::concept::traits::_detail::metafunction
                ::is_fusion_forward_iterator_impl<
                    typename ::boost::fusion::result_of::begin<T>::type
                  , typename ::boost::fusion::result_of::end<T>::type
                >
#endif
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    class is_nonempty_fusion_forward_sequence_impl
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
                    BOOST_TYPEOF_KEYWORD
#else
                    decltype
#endif
                    (::boost::fusion::front(::boost::declref<B>()))
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef typename ::boost::mpl::eval_if_c<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::is_nonempty_fusion_forward_sequence_impl<T>
                        ::_check<T>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                  , ::boost::mpl::eval_if<
                        ::boost::concept::traits::has_type<
                            ::boost::fusion::result_of::front<T>
                        >
                      , ::boost::concept::traits::_detail::metafunction
                        ::has_fusion_forward_sequence_front<T>
                      , ::boost::mpl::false_
                    >
                  , ::boost::mpl::false_
                >::type
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include \
<boost/concept/traits/_detail/metafunction/has_fusion_fwd_iterator_ops.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename ItrPredPlaceholderExpr>
    struct is_nonempty_fusion_forward_sequence
      : ::boost::mpl::eval_if<
            typename ::boost::mpl::eval_if<
                typename ::boost::mpl::apply1<
                    ItrPredPlaceholderExpr
                  , typename ::boost::fusion::result_of::begin<T>::type
                >::type
              , ::boost::concept::traits::_detail::metafunction
                ::has_fusion_forward_iterator_ops<
                    typename ::boost::fusion::result_of::begin<T>::type
                  , ItrPredPlaceholderExpr
                >
              , ::boost::mpl::false_
            >::type
          , ::boost::concept::traits::_detail::metafunction
            ::is_nonempty_fusion_forward_sequence_impl<T>
          , ::boost::mpl::false_
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

