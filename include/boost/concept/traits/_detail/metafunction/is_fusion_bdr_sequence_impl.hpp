// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_FUSION_BDR_SEQUENCE_IMPL_HPP
#define \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_FUSION_BDR_SEQUENCE_IMPL_HPP

#include <boost/utility/declref.hpp>
#include <boost/fusion/sequence/intrinsic/end.hpp>
#include <boost/fusion/sequence/intrinsic/back.hpp>
#include <boost/fusion/iterator/deref.hpp>
#include <boost/fusion/iterator/prior.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_same.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_fusion_bidirectional_sequence_back
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
      : ::boost::mpl::if_<
            ::boost::is_same<
#else
      : ::boost::mpl::eval_if<
            ::std::is_same<
#endif
                typename ::boost::fusion::result_of::back<T>::type
#if defined BOOST_NO_CXX11_DECLTYPE
              , BOOST_TYPEOF_KEYWORD
#else
              , decltype
#endif
                (::boost::fusion::back(::boost::declref<T>()))
            >
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
          , ::boost::is_same<
#else
          , ::boost::mpl::if_<
                ::std::is_same<
#endif
                    typename ::boost::fusion::result_of::deref<
                        typename ::boost::fusion::result_of::prior<
                            typename ::boost::fusion::result_of::end<T>::type
                        >::type
                    >::type
                  , typename ::boost::fusion::result_of::back<T>::type
#if !defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                >
              , ::boost::mpl::true_
              , ::boost::mpl::false_
#endif
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
    class is_nonempty_fusion_bidirectional_sequence_impl
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
                    (::boost::fusion::back(::boost::declcref<B>()))
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef typename ::boost::mpl::eval_if_c<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::is_nonempty_fusion_bidirectional_sequence_impl<T>
                        ::_check<T>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                  , ::boost::mpl::eval_if<
                        ::boost::concept::traits::has_type<
                            ::boost::fusion::result_of::back<T>
                        >
                      , ::boost::concept::traits::_detail::metafunction
                        ::has_fusion_bidirectional_sequence_back<T>
                      , ::boost::mpl::false_
                    >
                  , ::boost::mpl::false_
                >::type
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include \
<boost/concept/traits/_detail/metafunction/is_fusion_fwd_sequence_impl.hpp>
#include \
<boost/concept/traits/_detail/metafunction/has_fusion_bdr_iterator_ops.hpp>
#include <boost/mpl/apply.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename ItrPredPlaceholderExpr>
    class is_nonempty_fusion_bidirectional_sequence
    {
        typedef typename ::boost::fusion::result_of::end<T>::type _End;

     public:
        typedef typename ::boost::mpl::eval_if<
                    typename ::boost::mpl::eval_if<
                        typename ::boost::mpl::eval_if<
                            typename ::boost::concept::traits
                            ::_detail::metafunction
                            ::is_nonempty_fusion_forward_sequence<
                                T
                              , ItrPredPlaceholderExpr
                            >::type
                          , ::boost::mpl::apply1<ItrPredPlaceholderExpr,_End>
                          , ::boost::mpl::false_
                        >::type
                      , ::boost::concept::traits::_detail::metafunction
                        ::has_fusion_bidirectional_iterator_ops<
                            _End
                          , ItrPredPlaceholderExpr
                        >
                      , ::boost::mpl::false_
                    >::type
                  , ::boost::concept::traits::_detail::metafunction
                    ::is_nonempty_fusion_bidirectional_sequence_impl<T>
                  , ::boost::mpl::false_
                >::type
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

