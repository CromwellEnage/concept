// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_HAS_FUSION_ASC_ITERATOR_OPS_HPP
#define \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_HAS_FUSION_ASC_ITERATOR_OPS_HPP

#include <boost/utility/declref.hpp>
#include <boost/fusion/iterator/value_of_data.hpp>
#include <boost/fusion/iterator/deref_data.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_convertible.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_derefable_fusion_associative_iterator
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
      : ::boost::is_convertible<
#else
      : ::boost::mpl::if_<
            ::std::is_convertible<
#endif
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF_KEYWORD
#else
                decltype
#endif
                (::boost::fusion::deref_data(::boost::declref<T>()))
              , typename ::boost::fusion::result_of::value_of_data<T>::type
            >
#if !defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
          , ::boost::mpl::true_
          , ::boost::mpl::false_
        >
#endif
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type/has_type.hpp>
#include <boost/tti/detail/dnullptr.hpp>
#include <boost/fusion/iterator/key_of.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_pointer.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    class has_fusion_associative_iterator_ops
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
                    (::boost::fusion::deref_data(::boost::declcref<B>()))
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef typename ::boost::mpl::eval_if_c<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_fusion_associative_iterator_ops<T>
                        ::_check<T>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                  , ::boost::mpl::eval_if<
                        ::boost::concept::traits::has_type<
                            ::boost::fusion::result_of::value_of_data<T>
                        >
                      , ::boost::mpl::eval_if<
                            ::boost::concept::traits::has_type<
                                ::boost::fusion::result_of::deref_data<T>
                            >
                          , ::boost::mpl::eval_if<
                                ::boost::concept::traits::has_type<
                                    ::boost::fusion::result_of::key_of<T>
                                >
                              , ::boost::concept::traits
                                ::_detail::metafunction
                                ::is_derefable_fusion_associative_iterator<T>
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

