// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_FUSION_FWD_ITERATOR_IMPL_HPP
#define \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_FUSION_FWD_ITERATOR_IMPL_HPP

#include <boost/utility/declref.hpp>
#include <boost/fusion/iterator/distance.hpp>
#include <boost/fusion/iterator/equal_to.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
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

    template <typename T, typename U>
    struct has_fusion_forward_iterator_operators
      : ::boost::mpl::if_<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            ::boost::is_same<
#else
            ::std::is_same<
#endif
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF_KEYWORD
#else
                decltype
#endif
                ((
                    ::boost::fusion::distance(
                        ::boost::declcref<T>()
                      , ::boost::declcref<U>()
                    )
                ))
              , typename ::boost::fusion::result_of::distance<T,U>::type
            >
          , ::boost::concept::traits::is_mpl_integral_constant<
                typename ::boost::fusion::result_of::distance<T,U>::type
            >
          , ::boost::mpl::false_
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query/is_equality_comparable.hpp>
#include <boost/concept/traits/query/is_mpl_boolean_constant.hpp>
#include <boost/concept/traits/query/is_mpl_integral_constant.hpp>
#include <boost/concept/traits/introspection/nested_type/has_type.hpp>
#include <boost/tti/detail/dnullptr.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_pointer.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename U>
    class is_fusion_forward_iterator_impl
    {
        template <typename X, typename Y>
        static ::boost::type_traits::yes_type
            _check(
#if defined BOOST_NO_CX11_HDR_TYPE_TRAITS
                typename ::boost::add_pointer<
#else
                typename ::std::add_pointer<
#endif
#if defined BOOST_NO_CX11_DECLTYPE
                    BOOST_TYPEOF_KEYWORD
#else
                    decltype
#endif
                    ((
                        ::boost::fusion::distance(
                            ::boost::declcref<X>()
                          , ::boost::declcref<Y>()
                        )
                    ))
                >::type
            );

        template <typename X, typename Y>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef typename ::boost::mpl::eval_if_c<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::is_fusion_forward_iterator_impl<T,U>
                        ::_check<T,U>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                  , ::boost::mpl::eval_if<
                        ::boost::concept::traits::is_equality_comparable<T,U>
                      , ::boost::mpl::eval_if<
                            ::boost::concept::traits::is_mpl_boolean_constant<
                                ::boost::fusion::result_of::equal_to<T,U>
                            >
                          , ::boost::mpl::eval_if<
                                ::boost::concept::traits::has_type<
                                    ::boost::fusion::result_of::distance<T,U>
                                >
                              , ::boost::concept::traits
                                ::_detail::metafunction
                                ::has_fusion_forward_iterator_operators<T,U>
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

