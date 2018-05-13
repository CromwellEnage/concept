// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_MPL_RA_ITERATOR_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_MPL_RA_ITERATOR_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/introspection/nested_type/has_category.hpp>
#include <boost/concept/traits/_detail/metafunction/is_mpl_iterator.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/iterator_tags.hpp>
#include <boost/mpl/eval_if.hpp>

//[reference__is_mpl_random_access_iterator
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_mpl_random_access_iterator
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_has_category_<T>
          , _mpl_if_<
                _bct_is_mpl_integral_constant_<
                    typename _mpl_iterator_category_<
                        typename _std_remove_const_<T>::type
                    >::type
                >
              , _mpl_less_equal_<
                    typename _mpl_iterator_category_<
                        typename _std_remove_const_<T>::type
                    >::type
                  , _mpl_random_access_iterator_tag_
                >
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_category<T>
          , ::boost::concept::traits::_detail::metafunction
            ::is_mpl_iterator<T,::boost::mpl::random_access_iterator_tag>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

