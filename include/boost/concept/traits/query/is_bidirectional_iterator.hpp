// Copyright (C) 2012-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_BIDIRECTIONAL_ITERATOR_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_BIDIRECTIONAL_ITERATOR_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_forward_iterator.hpp>
#include \
<boost/concept/traits/introspection/nested_type/is_iterator_category_of.hpp>
#include <boost/concept/traits/_detail/metafunction/is_bidirectional.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#else
#include <type_traits>
#endif

#include <iterator>

//[reference__is_bidirectional_iterator
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_bidirectional_iterator
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _bct_is_decrementable_<
                typename _std_remove_const_<
                    typename _std_remove_reference_<T>::type
                >::type
            >
          , _mpl_eval_if_<
                _bct_is_forward_iterator_<T>
              , _mpl_if_<
                    _bct_is_iterator_category_of_<
                        std::bidirectional_iterator_tag
                      , T
                    >
                  , _bct_is_convertible_to_cref_of_<
                        _decltype_(
                            _bct_declref_<
                                typename _std_remove_const_<
                                    typename _std_remove_reference_<T>::type
                                >::type
                            >()--
                        )
                      , T
                    >
                  , _mpl_false_
                >
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::_detail::metafunction::is_bidirectional<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::remove_const<
                    typename ::boost::remove_reference<T>::type
                >::type
#else
                typename ::std::remove_const<
                    typename ::std::remove_reference<T>::type
                >::type
#endif
            >
          , ::boost::mpl::if_<
                ::boost::concept::traits::is_iterator_category_of<
                    ::std::bidirectional_iterator_tag
                  , T
                >
              , ::boost::concept::traits::is_forward_iterator<T>
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

