// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_SINGLE_PASS_ITERATOR_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_SINGLE_PASS_ITERATOR_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_incrementable_iterator.hpp>
#include \
<boost/concept/traits/introspection/nested_type/is_iterator_traversal_of.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_dereferenceable.hpp>
#include <boost/iterator/iterator_categories.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#else
#include <type_traits>
#endif

#if !defined( \
BOOST_CONCEPT_CONFIG_BUG_ADJACENT_FILTERED_RANGE_ITERATOR_NOT_EQ_COMP \
)
#include <boost/concept/traits/query/is_equality_comparable.hpp>
#include <boost/mpl/if.hpp>
#endif

//[reference__is_single_pass_iterator
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_single_pass_iterator
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _is_valid_expression_(
                *_bct_declref_<
                    typename _std_remove_const_<
                        typename _std_remove_reference_<T>::type
                    >::type
                >()
            )
          , _mpl_if_<
                _std_is_void_<
                    _decltype_(
                        *_bct_declref_<
                            typename _std_remove_const_<
                                typename _std_remove_reference_<T>::type
                            >::type
                        >()
                    )
                >
              , _mpl_false_
              , _mpl_eval_if_<
                    _bct_is_incrementable_iterator_<T>
                  , _mpl_if_<
                        _bct_is_iterator_traversal_of_<
                            boost::iterators::single_pass_traversal_tag
                          , T
                        >
                      , _bct_is_equality_comparable_<T>
                      , _mpl_false_
                    >
                  , _mpl_false_
                >
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::mpl::eval_if<
            typename ::boost::concept::traits::_detail::metafunction
            ::is_dereferenceable<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::remove_const<
                    typename ::boost::remove_reference<T>::type
                >::type
#else
                typename ::std::remove_const<
                    typename ::std::remove_reference<T>::type
                >::type
#endif
            >::type
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::is_incrementable_iterator<T>
#if !defined( \
BOOST_CONCEPT_CONFIG_BUG_ADJACENT_FILTERED_RANGE_ITERATOR_NOT_EQ_COMP \
)
              , ::boost::mpl::if_<
                    ::boost::concept::traits::is_equality_comparable<T>
#endif
                  , ::boost::concept::traits::is_iterator_traversal_of<
                        ::boost::iterators::single_pass_traversal_tag
                      , T
                    >
#if !defined( \
BOOST_CONCEPT_CONFIG_BUG_ADJACENT_FILTERED_RANGE_ITERATOR_NOT_EQ_COMP \
)
                  , ::boost::mpl::false_
                >
#endif
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

