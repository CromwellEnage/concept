// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_INDEXABLE_ITERATOR_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_INDEXABLE_ITERATOR_HPP

#include <boost/concept/traits/declref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/type_traits/declval.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/typeof/typeof.hpp>
#endif

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/is_convertible.hpp>
#include <boost/type_traits/is_same.hpp>
#else
#include <type_traits>
#endif

#if !defined(BOOST_NO_CXX17_ITERATOR_TRAITS)
#include <iterator>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Subscript>
    struct has_indexable_iterator_operator
    {
        template <typename Result>
        struct apply
        {
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
            typedef typename ::boost::mpl::if_<
                ::boost::is_convertible<
#else
            typedef typename ::boost::mpl::eval_if<
                ::std::is_convertible<
#endif
                    Result
                  , typename ::boost::iterators::iterator_value<
#if defined(BOOST_NO_CXX17_ITERATOR_TRAITS)
                        T
#else
                        ::std::iterator_traits<T>
#endif
                    >::type
                >
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
              , ::boost::is_same<
#else
              , ::boost::mpl::if_<
                    ::std::is_same<
#endif
#if defined(BOOST_NO_CXX11_DECLTYPE)
                        BOOST_TYPEOF_KEYWORD(
                            *(
                                ::boost::concept::traits::declref<
                                    T
                                >() + ::boost::declval<Subscript>()
                            )
                        )
#else
                        decltype(
                            *(
                                ::boost::concept::traits::declref<
                                    T
                                >() + ::boost::declval<Subscript>()
                            )
                        )
#endif
                      , Result
                    >
#if !defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                  , ::boost::mpl::true_
                  , ::boost::mpl::false_
                >
#endif
              , ::boost::mpl::false_
            >::type type;
        };
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query/is_additive.hpp>
#include <boost/concept/traits/query/is_subscriptable.hpp>
#include <boost/concept/traits/trivial_access/iterator_difference_of.hpp>
#include <boost/mpl/always.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/add_const.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <
        typename IsStrict
      , typename T
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      , typename _Difference = typename ::boost::add_const<
#else
      , typename _Difference = typename ::std::add_const<
#endif
            typename ::boost::concept::traits::iterator_difference_of<T>::type
        >::type
    >
    struct is_indexable_itr
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_additive<T,_Difference>
          , ::boost::mpl::if_<
                IsStrict
              , ::boost::concept::traits::is_subscriptable<
                    T
                  , _Difference
                  , ::boost::concept::traits::_detail::metafunction
                    ::has_indexable_iterator_operator<T,_Difference>
                >
              , ::boost::concept::traits::is_subscriptable<
                    T
                  , _Difference
                  , ::boost::mpl::always< ::boost::mpl::true_>
                >
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query/is_comparable.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename IsStrict>
    struct is_indexable_iterator
      : ::boost::mpl::if_<
            ::boost::concept::traits::_detail::metafunction::is_indexable_itr<
                IsStrict
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
              , typename ::boost::remove_const<
                    typename ::boost::remove_reference<T>::type
                >::type
#else
              , typename ::std::remove_const<
                    typename ::std::remove_reference<T>::type
                >::type
#endif
            >
          , ::boost::concept::traits::is_comparable<T>
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

