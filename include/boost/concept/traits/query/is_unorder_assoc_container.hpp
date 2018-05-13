// Copyright (C) 2016-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_UNORDER_ASSOC_CONTAINER_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_UNORDER_ASSOC_CONTAINER_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_input_iterator.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_minimal_or_mutable_ds.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_unorder_assoc_cont_impl.hpp>
#include <boost/mpl/placeholders.hpp>

//[reference__is_unordered_associative_container
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_unordered_associative_container
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
          _bct_is_hashed_associative_container_<T>
        , _mpl_eval_if_<
            _bct_has_begin_bucket_<
              typename _std_add_const_<T>::type
            >
          , _mpl_eval_if_<
              _bct_has_end_bucket_<
                typename _std_add_const_<T>::type
              >
            , _mpl_eval_if_<
                _bct_has_begin_bucket_<
                  typename _std_remove_const_<T>::type
                >
              , _mpl_eval_if_<
                  _bct_has_end_bucket_<
                    typename _std_remove_const_<T>::type
                  >
                , _mpl_eval_if_<
                    _bct_has_cbegin_bucket_<
                      typename _std_add_const_<T>::type
                    >
                  , _mpl_eval_if_<
                      _bct_has_cend_bucket_<
                        typename _std_add_const_<T>::type
                      >
                    , _mpl_eval_if_<
                        _bct_has_cbegin_<
                          typename _std_add_const_<T>::type
                        >
                      , _mpl_eval_if_<
                          _bct_has_cend_<
                            typename _std_add_const_<T>::type
                          >
                        , _mpl_if_<
                            _bct_has_rehash_<
                              typename _std_remove_const_<T>::type
                            >
                          , _bct_has_reserve_<
                              typename _std_remove_const_<T>::type
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
          , ::boost::concept::traits::is_input_iterator< ::boost::mpl::_1>
          , ::boost::concept::traits::_detail::metafunction
            ::is_minimal_unordered_associative_container_impl<
                ::boost::mpl::_1
              , ::boost::mpl::_2
            >
          , ::boost::concept::traits::_detail::metafunction
            ::is_mutable_unordered_associative_container_impl<
                ::boost::mpl::_1
            >
        >
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

