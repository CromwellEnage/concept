// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_FUSION_SEQ_EMPTY_OR_NOT_HPP
#define \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_FUSION_SEQ_EMPTY_OR_NOT_HPP

#include <boost/concept/traits/introspection/nested_type/has_is_view.hpp>
#include <boost/fusion/support/is_sequence.hpp>
#include <boost/fusion/support/is_view.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <
        typename T
      , typename TraitPredPlaceholderExpr
      , typename EmptyOrNotPredPlaceholderExpr
    >
    struct is_fusion_sequence_or_view
      : ::boost::mpl::eval_if<
            typename ::boost::mpl::eval_if<
                ::boost::fusion::traits::is_sequence<T>
              , ::boost::mpl::apply1<TraitPredPlaceholderExpr,T>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_is_view<T>
                  , ::boost::mpl::eval_if<
                        ::boost::fusion::traits::is_view<T>
                      , ::boost::mpl::apply1<TraitPredPlaceholderExpr,T>
                      , ::boost::mpl::false_
                    >
                  , ::boost::mpl::false_
                >
            >::type
          , ::boost::mpl::apply1<EmptyOrNotPredPlaceholderExpr,T>
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/fusion/sequence/intrinsic/empty.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <
        typename T
      , typename TraitPredPlaceholderExpr
      , typename ItrPredPlaceholderExpr
      , typename EmptyOrNotPredPlaceholderExpr
      , typename NonEmptyPredPlaceholderExpr
    >
    class is_fusion_sequence_empty_or_not
    {
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
        typedef typename ::boost::remove_const<T>::type _mutable_T;
#else
        typedef typename ::std::remove_const<T>::type _mutable_T;
#endif

     public:
        typedef typename ::boost::mpl::eval_if<
                    ::boost::concept::traits::_detail::metafunction
                    ::is_fusion_sequence_or_view<
                        T
                      , TraitPredPlaceholderExpr
                      , EmptyOrNotPredPlaceholderExpr
                    >
                  , ::boost::mpl::eval_if<
                        ::boost::fusion::result_of::empty<_mutable_T>
                      , ::boost::mpl::true_
                      , ::boost::mpl::apply2<
                            NonEmptyPredPlaceholderExpr
                          , T
                          , ItrPredPlaceholderExpr
                        >
                    >
                  , ::boost::mpl::false_
                >::type
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

