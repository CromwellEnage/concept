// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_HAS_FUSION_BDR_ITERATOR_OPS_HPP
#define \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_HAS_FUSION_BDR_ITERATOR_OPS_HPP

#include <boost/utility/declref.hpp>
#include <boost/fusion/iterator/equal_to.hpp>
#include <boost/fusion/iterator/prior.hpp>
#include <boost/fusion/iterator/advance.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename ItrPredPlaceholderExpr>
    struct has_fusion_bidirectional_iterator_funcs
      : ::boost::mpl::eval_if<
            ::boost::fusion::result_of::equal_to<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF_KEYWORD
#else
                decltype
#endif
                (::boost::fusion::advance_c<-1>(::boost::declcref<T>()))
              , typename ::boost::fusion::result_of::advance_c<T,-1>::type
            >
          , ::boost::mpl::eval_if<
                ::boost::fusion::result_of::equal_to<
#if defined BOOST_NO_CXX11_DECLTYPE
                    BOOST_TYPEOF_KEYWORD
#else
                    decltype
#endif
                    (
                        ::boost::fusion::advance<
                            ::boost::mpl::int_<-1>
                        >(::boost::declcref<T>())
                    )
                  , typename ::boost::fusion::result_of::advance<
                        T
                      , ::boost::mpl::int_<-1>
                    >::type
                >
              , ::boost::mpl::eval_if<
                    ::boost::fusion::result_of::equal_to<
#if defined BOOST_NO_CXX11_DECLTYPE
                        BOOST_TYPEOF_KEYWORD
#else
                        decltype
#endif
                        (::boost::fusion::prior(::boost::declcref<T>()))
                      , typename ::boost::fusion::result_of::prior<T>::type
                    >
                  , ::boost::mpl::eval_if<
                        ::boost::fusion::result_of::equal_to<
                            typename ::boost::fusion::result_of
                            ::prior<T>::type
                          , typename ::boost::fusion::result_of
                            ::advance<T,::boost::mpl::int_<-1> >::type
                        >
                      , ::boost::mpl::eval_if<
                            ::boost::fusion::result_of::equal_to<
                                typename ::boost::fusion::result_of
                                ::prior<T>::type
                              , typename ::boost::fusion::result_of
                                ::advance_c<T,-1>::type
                            >
                          , ::boost::mpl::eval_if<
                                typename ::boost::mpl::apply1<
                                    ItrPredPlaceholderExpr
                                  , typename ::boost::fusion::result_of
                                    ::prior<T>::type
                                >::type
                              , ::boost::mpl::eval_if<
                                    typename ::boost::mpl::apply1<
                                        ItrPredPlaceholderExpr
                                      ,  typename ::boost::fusion::result_of
                                        ::advance<T,::boost::mpl::int_<-1> >
                                        ::type
                                    >::type
                                  , ::boost::mpl::apply1<
                                        ItrPredPlaceholderExpr
                                      , typename ::boost::fusion::result_of
                                        ::advance_c<T,-1>::type
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
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename U>
    class has_fusion_bidirectional_iterator_ops
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check_prior(
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
                    (::boost::fusion::prior(::boost::declcref<B>()))
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check_prior(...);

        template <typename B>
        static ::boost::type_traits::yes_type
            _check_advance(
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
                        ::boost::fusion::advance<::boost::mpl::int_<-1> >(
                            ::boost::declcref<B>()
                        )
                    )
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check_advance(...);

        template <typename B>
        static ::boost::type_traits::yes_type
            _check_advance_c(
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
                    (::boost::fusion::advance_c<-1>(::boost::declcref<B>()))
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check_advance_c(...);

     public:
        typedef typename ::boost::mpl::eval_if_c<
                    (
                        sizeof(
                            ::boost::concept::traits::_detail::metafunction
                            ::has_fusion_bidirectional_iterator_ops<T,U>
                            ::_check_prior<T>(BOOST_TTI_DETAIL_NULLPTR)
                        ) == sizeof(::boost::type_traits::yes_type)
                    ) && (
                        sizeof(
                            ::boost::concept::traits::_detail::metafunction
                            ::has_fusion_bidirectional_iterator_ops<T,U>
                            ::_check_advance<T>(BOOST_TTI_DETAIL_NULLPTR)
                        ) == sizeof(::boost::type_traits::yes_type)
                    ) && (
                        sizeof(
                            ::boost::concept::traits::_detail::metafunction
                            ::has_fusion_bidirectional_iterator_ops<T,U>
                            ::_check_advance_c<T>(BOOST_TTI_DETAIL_NULLPTR)
                        ) == sizeof(::boost::type_traits::yes_type)
                    )
                  , ::boost::mpl::eval_if<
                        ::boost::concept::traits::has_type<
                            ::boost::fusion::result_of::prior<T>
                        >
                      , ::boost::mpl::eval_if<
                            ::boost::concept::traits::has_type<
                                ::boost::fusion::result_of::advance_c<T,-1>
                            >
                          , ::boost::mpl::eval_if<
                                ::boost::concept::traits::has_type<
                                    ::boost::fusion::result_of::advance<
                                        T
                                      , ::boost::mpl::int_<-1>
                                    >
                                >
                              , ::boost::concept::traits
                                ::_detail::metafunction
                                ::has_fusion_bidirectional_iterator_funcs<T,U>
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

#endif  // include guard

