// Copyright (C) 2012-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_U_SM_ASSOC_PTR_CONTAINER_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_U_SM_ASSOC_PTR_CONTAINER_HPP

#include \
<boost/concept/traits/introspection/nested_type/is_iterator_bool_pair_of.hpp>
#include <boost/concept/traits/introspection/member_function/has_insert.hpp>
#include <boost/concept/traits/trivial_access/key_type_of.hpp>
#include <boost/concept/policy/use_default.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_pointer.hpp>
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_unique_simple_associative_ptr_container_impl
      : ::boost::concept::traits::has_insert<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            typename ::boost::remove_const<T>::type
          , typename ::boost::add_pointer<
#else
            typename ::std::remove_const<T>::type
          , typename ::std::add_pointer<
#endif
                typename ::boost::concept::traits::key_type_of<T>::type
            >::type
          , ::boost::concept::policy::use_default
          , ::boost::concept::policy::use_default
          , ::boost::concept::traits::is_iterator_bool_pair_of<
                ::boost::mpl::_
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
              , typename ::boost::remove_const<T>::type
#else
              , typename ::std::remove_const<T>::type
#endif
            >
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_associative_container.hpp>
#include <boost/concept/traits/introspection/nested_type/has_mapped_type.hpp>
#include \
<boost/concept/traits/_detail/metafunction/has_ptr_container_members.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

//[reference__is_unique_simple_associative_ptr_container
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_unique_simple_associative_ptr_container
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_is_ptr_container_<T>
          , _mpl_eval_if_<
                _bct_is_associative_container_<T>
              , _mpl_if_<
                    _bct_has_mapped_type_<T>
                  , _mpl_false_
                  , _bct_has_insert_<
                        typename _std_remove_const_<T>::type
                      , typename _std_add_pointer_<
                            typename _bct_key_type_of_<T>::type
                        >::type
                      , boost::concept::policy::use_default
                      , boost::concept::policy::use_default
                      , _is_iterator_bool_pair_of_<
                            _mpl_placeholder_
                          , typename _std_remove_const_<T>::type
                        >
                    >
                >
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::_detail::metafunction
            ::has_ptr_container_members<T>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::is_associative_container<T>
              , ::boost::mpl::if_<
                    ::boost::concept::traits::has_mapped_type<T>
                  , ::boost::mpl::false_
                  , ::boost::concept::traits::_detail::metafunction
                    ::is_unique_simple_associative_ptr_container_impl<T>
                >
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

