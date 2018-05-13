// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_UBLAS_MATRIX_EXPRESSION_HPP
#define \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_UBLAS_MATRIX_EXPRESSION_HPP

#include <boost/concept/traits/trivial_access/iterator1_of.hpp>
#include <boost/concept/traits/trivial_access/iterator2_of.hpp>
#include <boost/concept/traits/trivial_access/reverse_iterator1_of.hpp>
#include <boost/concept/traits/trivial_access/reverse_iterator2_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename UMFC>
    struct is_ublas_matrix_expression_with_iters
      : ::boost::mpl::eval_if<
            typename ::boost::mpl::eval_if<
                typename ::boost::mpl::eval_if<
                    typename ::boost::mpl::apply1<
                        UMFC
                      , typename ::boost::concept::traits
                        ::reverse_iterator2_of<T>::type
                    >::type
                  , ::boost::mpl::apply1<
                        UMFC
                      , typename ::boost::concept::traits
                        ::reverse_iterator1_of<T>::type
                    >
                  , ::boost::mpl::false_
                >::type
              , ::boost::mpl::apply1<
                    UMFC
                  , typename ::boost::concept::traits::iterator2_of<T>::type
                >
              , ::boost::mpl::false_
            >::type
          , ::boost::mpl::apply1<
                UMFC
              , typename ::boost::concept::traits::iterator1_of<T>::type
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query/is_callable.hpp>
#include <boost/concept/traits/trivial_access/value_type_of.hpp>
#include <boost/concept/traits/trivial_access/size_type_of.hpp>
#include <boost/concept/traits/introspection/nested_type/has_reference.hpp>
#include <boost/concept/traits/introspection/member_function/has_begin1.hpp>
#include <boost/concept/traits/introspection/member_function/has_end1.hpp>
#include <boost/concept/traits/introspection/member_function/has_begin2.hpp>
#include <boost/concept/traits/introspection/member_function/has_end2.hpp>
#include <boost/concept/traits/introspection/member_function/has_rbegin1.hpp>
#include <boost/concept/traits/introspection/member_function/has_rend1.hpp>
#include <boost/concept/traits/introspection/member_function/has_rbegin2.hpp>
#include <boost/concept/traits/introspection/member_function/has_rend2.hpp>
#include <boost/mpl/if.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_convertible.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename UMFC>
    struct is_ublas_matrix_expression_impl
      : ::boost::mpl::eval_if<
          ::boost::concept::traits::is_callable<
            T(
                typename ::boost::concept::traits::size_type_of<T>::type
              , typename ::boost::concept::traits::size_type_of<T>::type
            )
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
          , ::boost::is_convertible<
#else
          , ::std::is_convertible<
#endif
              ::boost::mpl::_
            , typename ::boost::concept::traits::value_type_of<T>::type
            >
          >
        , ::boost::mpl::eval_if<
            ::boost::concept::traits::has_reference<T>
          , ::boost::mpl::eval_if<
              ::boost::concept::traits::has_begin1<T>
            , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_begin2<T>
              , ::boost::mpl::eval_if<
                  ::boost::concept::traits::has_rbegin1<T>
                , ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_rbegin2<T>
                  , ::boost::mpl::eval_if<
                      ::boost::concept::traits::has_end1<T>
                    , ::boost::mpl::eval_if<
                        ::boost::concept::traits::has_end2<T>
                      , ::boost::mpl::eval_if<
                          ::boost::concept::traits::has_rend1<T>
                        , ::boost::mpl::if_<
                            ::boost::concept::traits::has_rend2<T>
                          , ::boost::concept::traits::_detail::metafunction
                            ::is_ublas_matrix_expression_with_iters<T,UMFC>
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
            , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
          >
        , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type/has_value_type.hpp>
#include \
<boost/concept/traits/introspection/nested_type/is_type_category_of.hpp>
#include <boost/concept/traits/introspection/member_function/has_size1.hpp>
#include <boost/concept/traits/introspection/member_function/has_size2.hpp>
#include <boost/numeric/ublas/fwd.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename UMFC>
    struct is_ublas_matrix_expression
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_type_category_of<
                ::boost::numeric::ublas::matrix_tag
              , T
            >
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_value_type<T>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_size1<T const>
                  , ::boost::mpl::eval_if<
                        ::boost::concept::traits::has_size2<T const>
                      , ::boost::mpl::if_<
                            ::boost::concept::traits::_detail::metafunction
                            ::is_ublas_matrix_expression_impl<T const,UMFC>
                          , ::boost::concept::traits::_detail::metafunction
                            ::is_ublas_matrix_expression_impl<T,UMFC>
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
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

