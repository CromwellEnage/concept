// Copyright (C) 2012-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_PAIR_ASSOC_PTR_CONTAINER_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_PAIR_ASSOC_PTR_CONTAINER_HPP

#include <boost/concept/traits/query/is_ptr_map_iterator.hpp>
#include <boost/concept/traits/trivial_access/iterator_of.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_pair_associative_ptr_container_impl
      : ::boost::concept::traits::is_ptr_map_iterator<
            typename ::boost::concept::traits::iterator_of<T>::type
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
#include <boost/mpl/eval_if.hpp>

//[reference__is_pair_associative_ptr_container
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_pair_associative_ptr_container
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_is_associative_container_<T>
          , _mpl_eval_if_<
                _bct_has_mapped_type_<T>
              , _mpl_if_<
                    _bct_is_ptr_container_<T>
                  , _bct_is_ptr_map_iterator_<
                        typename _bct_iterator_of_<T>::type
                    >
                  , _mpl_false_
                >
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_associative_container<T>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_mapped_type<T>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::_detail::metafunction
                    ::has_ptr_container_members<T>
                  , ::boost::concept::traits::_detail::metafunction
                    ::is_pair_associative_ptr_container_impl<T>
                  , ::boost::mpl::false_
                >
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::policy
//]

#endif  // include guard

