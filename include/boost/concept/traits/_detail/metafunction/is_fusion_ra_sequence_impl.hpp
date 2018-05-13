// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_FUSION_RA_SEQUENCE_IMPL_HPP
#define \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_FUSION_RA_SEQUENCE_IMPL_HPP

#include \
<boost/concept/traits/_detail/metafunction/has_fusion_bdr_iterator_ops.hpp>
#include <boost/utility/declref.hpp>
#include <boost/fusion/sequence/intrinsic/end.hpp>
#include <boost/fusion/sequence/intrinsic/empty.hpp>
#include <boost/fusion/sequence/intrinsic/back.hpp>
#include <boost/fusion/sequence/intrinsic/at_c.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/fusion/sequence/intrinsic/value_at.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/type_traits/is_convertible.hpp>
#endif
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_fusion_random_access_sequence_at
      : ::boost::mpl::eval_if<
#if defined BOOST_NO_CXX11_DECLTYPE
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            ::boost::is_convertible<
#else
            ::std::is_convertible<
#endif
#else   // !defined BOOST_NO_CXX11_DECLTYPE
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            ::boost::is_same<
#else
            ::std::is_same<
#endif
#endif  // BOOST_NO_CXX11_DECLTYPE
                typename ::boost::fusion::result_of::at<
                    T
                  , ::boost::mpl::minus<
                        typename ::boost::fusion::result_of::size<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                            typename ::boost::remove_const<T>::type
#else
                            typename ::std::remove_const<T>::type
#endif
                        >::type
                      , ::boost::mpl::int_<1>
                    >
                >::type
#if defined BOOST_NO_CXX11_DECLTYPE
              , BOOST_TYPEOF_KEYWORD
#else
              , decltype
#endif
                ((
                    ::boost::fusion::at<
                        ::boost::mpl::minus<
                            typename ::boost::fusion::result_of::size<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                                typename ::boost::remove_const<T>::type
#else
                                typename ::std::remove_const<T>::type
#endif
                            >::type
                          , ::boost::mpl::int_<1>
                        >
                    >(::boost::declref<T>())
                ))
            >
          , ::boost::mpl::eval_if<
#if defined BOOST_NO_CXX11_DECLTYPE
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                ::boost::is_convertible<
#else
                ::std::is_convertible<
#endif
#else   // !defined BOOST_NO_CXX11_DECLTYPE
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                ::boost::is_same<
#else
                ::std::is_same<
#endif
#endif  // BOOST_NO_CXX11_DECLTYPE
                    typename ::boost::fusion::result_of::at_c<
                        T
                      , ::boost::mpl::minus<
                            typename ::boost::fusion::result_of::size<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                                typename ::boost::remove_const<T>::type
#else
                                typename ::std::remove_const<T>::type
#endif
                            >::type
                          , ::boost::mpl::int_<1>
                        >::value
                    >::type
#if defined BOOST_NO_CXX11_DECLTYPE
                  , BOOST_TYPEOF_KEYWORD
#else
                  , decltype
#endif
                    ((
                        ::boost::fusion::at_c<
                            ::boost::mpl::minus<
                                typename ::boost::fusion::result_of::size<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                                    typename ::boost::remove_const<T>::type
#else
                                    typename ::std::remove_const<T>::type
#endif
                                >::type
                              , ::boost::mpl::int_<1>
                            >::value
                        >(::boost::declref<T>())
                    ))
                >
              , ::boost::mpl::eval_if<
#if defined BOOST_NO_CXX11_DECLTYPE
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                    ::boost::is_convertible<
#else
                    ::std::is_convertible<
#endif
#else   // !defined BOOST_NO_CXX11_DECLTYPE
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                    ::boost::is_same<
#else
                    ::std::is_same<
#endif
#endif  // BOOST_NO_CXX11_DECLTYPE
                        typename ::boost::fusion::result_of::at_c<T,0>::type
#if defined BOOST_NO_CXX11_DECLTYPE
                      , BOOST_TYPEOF_KEYWORD
#else
                      , decltype
#endif
                        (::boost::fusion::at_c<0>(::boost::declref<T>()))
                    >
                  , ::boost::mpl::eval_if<
#if defined BOOST_NO_CXX11_DECLTYPE
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                        ::boost::is_convertible<
#else
                        ::std::is_convertible<
#endif
#else   // !defined BOOST_NO_CXX11_DECLTYPE
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                        ::boost::is_same<
#else
                        ::std::is_same<
#endif
#endif  // BOOST_NO_CXX11_DECLTYPE
                            typename ::boost::fusion::result_of::at<
                                T
                              , ::boost::mpl::int_<0>
                            >::type
#if defined BOOST_NO_CXX11_DECLTYPE
                          , BOOST_TYPEOF_KEYWORD
#else
                          , decltype
#endif
                            (
                                ::boost::fusion::at< ::boost::mpl::int_<0> >(
                                    ::boost::declref<T>()
                                )
                            )
                        >
                      , ::boost::mpl::eval_if<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                            ::boost::is_same<
#else
                            ::std::is_same<
#endif
                                typename ::boost::fusion::result_of::at<
                                    T
                                  , ::boost::mpl::minus<
                                        typename ::boost::fusion::result_of
                                        ::size<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                                            typename ::boost::remove_const<
#else
                                            typename ::std::remove_const<
#endif
                                                T
                                            >::type
                                        >::type
                                      , ::boost::mpl::int_<1>
                                    >
                                >::type
                              , typename ::boost::fusion::result_of
                                ::back<T>::type
                            >
                          , ::boost::mpl::eval_if<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                                ::boost::is_same<
#else
                                ::std::is_same<
#endif
                                    typename ::boost::fusion::result_of::at_c<
                                        T
                                      , ::boost::mpl::minus<
                                            typename ::boost::fusion
                                            ::result_of::size<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                                                typename ::boost
                                                ::remove_const<
#else
                                                typename ::std::remove_const<
#endif
                                                    T
                                                >::type
                                            >::type
                                          , ::boost::mpl::int_<1>
                                        >::value
                                    >::type
                                  , typename ::boost::fusion::result_of
                                    ::back<T>::type
                                >
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                              , ::boost::mpl::if_<
                                    ::boost::is_same<
#else
                              , ::boost::mpl::eval_if<
                                    ::std::is_same<
#endif
                                        typename ::boost::fusion::result_of
                                        ::at<T,::boost::mpl::int_<0> >::type
                                      , typename ::boost::fusion::result_of
                                        ::front<T>::type
                                    >
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                                  , ::boost::is_same<
#else
                                  , ::boost::mpl::if_<
                                        ::std::is_same<
#endif
                                            typename ::boost::fusion
                                            ::result_of::at_c<T,0>::type
                                          , typename ::boost::fusion
                                            ::result_of::front<T>::type
#if !defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                                        >
                                      , ::boost::mpl::true_
                                      , ::boost::mpl::false_
#endif
                                    >
                                  , ::boost::mpl::false_
                                >
                              , ::boost::mpl::false_
                            >
                          , ::boost::mpl::false_
                        >
                      , ::boost::mpl::false_
                    >
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

#include <boost/concept/traits/introspection/nested_type/has_type.hpp>
#include <boost/tti/detail/dnullptr.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_pointer.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    class is_nonempty_fusion_random_access_seq_impl
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check_at(
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
                        ::boost::fusion::at< ::boost::mpl::int_<0> >(
                            ::boost::declref<B>()
                        )
                    )
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check_at(...);

        template <typename B>
        static ::boost::type_traits::yes_type
            _check_at_c(
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
                    (::boost::fusion::at_c<0>(::boost::declref<B>()))
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check_at_c(...);

     public:
        typedef typename ::boost::mpl::eval_if_c<
                    (
                        sizeof(
                            ::boost::concept::traits::_detail::metafunction
                            ::is_nonempty_fusion_random_access_seq_impl<T>
                            ::_check_at<T>(BOOST_TTI_DETAIL_NULLPTR)
                        ) == sizeof(::boost::type_traits::yes_type)
                    ) && (
                        sizeof(
                            ::boost::concept::traits::_detail::metafunction
                            ::is_nonempty_fusion_random_access_seq_impl<T>
                            ::_check_at_c<T>(BOOST_TTI_DETAIL_NULLPTR)
                        ) == sizeof(::boost::type_traits::yes_type)
                    )
                  , ::boost::mpl::eval_if<
                        ::boost::concept::traits::has_type<
                            ::boost::fusion::result_of::at_c<T,0>
                        >
                      , ::boost::mpl::eval_if<
                            ::boost::concept::traits::has_type<
                                ::boost::fusion::result_of::at<
                                    T
                                  , ::boost::mpl::int_<0>
                                >
                            >
                          , ::boost::mpl::eval_if<
                                ::boost::concept::traits::has_type<
                                    ::boost::fusion::result_of
                                    ::value_at_c<T,0>
                                >
                              , ::boost::mpl::eval_if<
                                    ::boost::concept::traits::has_type<
                                        ::boost::fusion::result_of::value_at<
                                            T
                                          , ::boost::mpl::int_<0>
                                        >
                                    >
                                  , ::boost::concept::traits
                                    ::_detail::metafunction
                                    ::has_fusion_random_access_sequence_at<T>
                                  , ::boost::mpl::false_
                                >
                              , ::boost::mpl::false_
                            >
                          , ::boost::mpl::false_
                        >
                      , ::boost::mpl::false_
                    >
                  , ::boost::mpl::false_
                >::type
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include \
<boost/concept/traits/_detail/metafunction/is_fusion_bdr_sequence_impl.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename ItrPredPlaceholderExpr>
    struct is_nonempty_fusion_random_access_sequence
      : ::boost::mpl::eval_if<
            typename ::boost::concept::traits::_detail::metafunction
            ::is_nonempty_fusion_bidirectional_sequence<
                T
              , ItrPredPlaceholderExpr
            >::type
          , ::boost::concept::traits::_detail::metafunction
            ::is_nonempty_fusion_random_access_seq_impl<T>
          , ::boost::mpl::false_
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

