// Copyright (C) 2012-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_SEQUENCE_IMPL_HPP
#define BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_SEQUENCE_IMPL_HPP

#include \
<boost/concept/traits/introspection/member_function/has_insert_after.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_erase_after.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_forward_list_members
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_insert_after<
                T
              , typename T::const_iterator
              , typename T::value_type
            >
          , ::boost::mpl::if_<
                ::boost::concept::traits::has_erase_after<
                    T
                  , typename T::const_iterator
                >
              , ::boost::concept::traits::has_erase_after<
                    T
                  , typename T::const_iterator
                  , typename T::const_iterator
                >
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include \
<boost/concept/traits/introspection/nested_type/is_iterator_bool_pair_of.hpp>
#include <boost/concept/traits/introspection/nested_type/is_iterator_of.hpp>
#include <boost/concept/traits/introspection/member_function/has_insert.hpp>
#include <boost/concept/policy/use_default.hpp>
#include <boost/utility/declref.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#elif defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_sequence_insert
      : ::boost::concept::traits::has_insert<
            T
          , typename T::iterator
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF_KEYWORD(*::boost::declcref<T>().begin())
#else
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
          , typename ::boost::remove_const<
                typename ::boost::remove_reference<
#else
          , typename ::std::remove_const<
                typename ::std::remove_reference<
#endif
                    decltype(*::boost::declcref<T>().begin())
                >::type
            >::type
#endif  // BOOST_NO_CXX11_DECLTYPE
          , ::boost::concept::policy::use_default
          , ::boost::mpl::if_<
                ::boost::concept::traits::is_iterator_of<
                    ::boost::mpl::_1
                  , T
                >
              , ::boost::mpl::true_
              , ::boost::concept::traits::is_iterator_bool_pair_of<
                    ::boost::mpl::_1
                  , T
                >
            >
        >
    {
    };

    template <typename T>
    struct has_ptr_sequence_insert
      : ::boost::mpl::if_<
            ::boost::concept::traits::has_insert<
                T
              , typename T::iterator
#if defined BOOST_NO_CXX11_DECLTYPE
              , BOOST_TYPEOF_KEYWORD(&*::boost::declref<T>().begin())
#else
              , decltype(&*::boost::declref<T>().begin())
#endif
            >
          , ::boost::concept::traits::_detail::metafunction::has_sequence_insert<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF_KEYWORD(::boost::declref<T>().base())
#else
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::remove_const<
                    typename ::boost::remove_reference<
#else
                typename ::std::remove_const<
                    typename ::std::remove_reference<
#endif
                        decltype(::boost::declref<T>().base())
                    >::type
                >::type
#endif  // BOOST_NO_CXX11_DECLTYPE
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/member_function/has_clear.hpp>
#include <boost/concept/traits/introspection/member_function/has_resize.hpp>
#include <boost/concept/traits/_detail/metafunction/is_container_impl.hpp>
#include <boost/concept/traits/_detail/metafunction/has_sequence_erase.hpp>
#include \
<boost/concept/traits/_detail/metafunction/has_ptr_container_members.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename UMFC>
    struct is_sequence_impl
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::_detail::metafunction
            ::is_minimal_container_impl<T,UMFC>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::_detail::metafunction
                ::has_sequence_erase<T>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_clear<T>
                  , ::boost::mpl::eval_if<
                        ::boost::concept::traits::has_resize<T>
                      , ::boost::mpl::if_<
                            ::boost::concept::traits::_detail::metafunction
                            ::has_ptr_container_members<T>
                          , ::boost::concept::traits::_detail::metafunction
                            ::has_ptr_sequence_insert<T>
                          , ::boost::concept::traits::_detail::metafunction
                            ::has_sequence_insert<T>
                        >
                      , ::boost::mpl::false_
                    >
                  , ::boost::mpl::false_
                >
              , ::boost::concept::traits::_detail::metafunction
                ::has_forward_list_members<T>
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

