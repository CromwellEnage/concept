// Copyright (C) 2012-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_RANDOM_ACCESS_CONTAINER_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_RANDOM_ACCESS_CONTAINER_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_random_access_iterator.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_minimal_or_mutable_ds.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_indexable_container_impl.hpp>
#include <boost/mpl/placeholders.hpp>

//[reference__is_random_access_container
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_random_access_container
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
          _bct_is_reversible_container_<T>
        , _mpl_eval_if_<
            _bct_is_random_access_iterator_<
              typename _std_remove_const_<T>::type::const_reverse_iterator
            >
          , _mpl_eval_if_<
              _bct_is_random_access_iterator_<
                typename _std_remove_const_<T>::type::reverse_iterator
              >
            , _mpl_eval_if_<
                _bct_is_random_access_iterator_<
                  typename _std_remove_const_<T>::type::const_iterator
                >
              , _mpl_eval_if_<
                  _bct_is_random_access_iterator_<
                    typename _std_remove_const_<T>::type::iterator
                  >
                , _mpl_eval_if_<
                    _is_valid_expression_(
                      _declref_<T>[
                        _declval_<
                          typename _std_remove_const_<T>
                          ::type::size_type
                        >()
                      ]
                    )
                  , _mpl_eval_if_<
                      _is_valid_expression_(
                        _declref_<T>.at(
                          _declval_<
                            typename _std_remove_const_<T>
                            ::type::size_type
                          >()
                        )
                      )
                    , _mpl_if_<
                        _std_is_same_<
                          _decltype_(
                            _declref_<T>.at(
                              _declval_<
                                typename _std_remove_const_<T>
                                ::type::size_type
                              >()
                            )
                          )
                        , _decltype_(
                            _declref_<T>[
                              _declval_<
                                typename _std_remove_const_<T>
                                ::type::size_type
                              >()
                            ]
                          )
                        >
                      , _mpl_true_
                      , _mpl_false_
                      >
                    , _mpl_if_<
                        _std_is_same_<
                          _decltype_(*_declref_<T>.begin())
                        , _decltype_(
                            _declref_<T>[
                              _declval_<
                                typename _std_remove_const_<T>
                                ::type::size_type
                              >()
                            ]
                          )
                        >
                      , _mpl_true_
                      , _mpl_false_
                      >
                    >
                  , _mpl_false_
                  >
                , _mpl_false_
                >
              , _mpl_false_
              >
            , _mpl_false_
            >
          , _mpl_false_
          >
        , _mpl_false_
        >::type
//<-
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::concept::traits::_detail::metafunction
        ::is_minimal_or_mutable_ds<
            T
          , ::boost::concept::traits::is_random_access_iterator<
                ::boost::mpl::_1
            >
          , ::boost::concept::traits::_detail::metafunction
            ::is_indexable_container<
                ::boost::mpl::_1
              , ::boost::mpl::_2
            >
          , ::boost::concept::traits::_detail::metafunction
            ::is_mutable_container_impl< ::boost::mpl::_1>
        >
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

