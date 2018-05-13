// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_FUSION_ASSOC_SEQUENCE_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_FUSION_ASSOC_SEQUENCE_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_fusion_assoc_iterator.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_fusion_seq_empty_or_not.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_fusion_fwd_sequence_impl.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_fusion_asc_sequence_impl.hpp>
#include <boost/fusion/support/category_of.hpp>
#include <boost/mpl/placeholders.hpp>

//[reference__is_fusion_associative_sequence
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_fusion_associative_sequence
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            typename _mpl_eval_if_<
                typename _mpl_eval_if_<
                    _fusion_traits_is_sequence_<T>
                  , _fusion_traits_is_associative_<T>
                  , _mpl_eval_if_<
                        _bct_has_is_view_<T>
                      , _mpl_if_<
                            _fusion_traits_is_view_<T>
                          , _fusion_traits_is_associative_<T>
                          , _mpl_false_
                        >
                      , _mpl_false_
                    >
                  , _mpl_false_
                >::type
              , _bct_is_fusion_forward_sequence_<T>
              , _mpl_false_
            >::type
          , _mpl_eval_if_<
                _fusion_result_of_empty_<
                    typename _std_remove_const_<T>::type
                >
              , _mpl_true_
              , _mpl_eval_if_<
                  _mpl_and_<
                    _bct_is_fusion_associative_iterator_<
                      typename _fusion_result_of_begin_<T>::type
                    >
                  , _bct_has_type_<
                      _fusion_result_of_key_of_<
                        typename _fusion_result_of_begin_<T>::type
                      >
                    >
                  , _bct_has_type_<
                      _fusion_result_of_deref_data_<
                        typename _fusion_result_of_begin_<T>::type
                      >
                    >
                  , _bct_has_type_<
                      _fusion_result_of_value_of_data_<
                        typename _fusion_result_of_begin_<T>::type
                      >
                    >
                  >
                , _mpl_eval_if_<
                    _mpl_and_<
                      _std_is_convertible_<
                        _decltype_(
                          _fusion_deref_data_(
                            _declref_<
                              typename _fusion_result_of_begin_<
                                T
                              >::type
                            >()
                          )
                        )
                      , typename _fusion_result_of_value_of_data_<
                          typename _fusion_result_of_begin_<T>::type
                        >::type
                      >
                    , _bct_is_mpl_boolean_constant_<
                        _fusion_result_of_has_key_<
                          T
                        , typename _fusion_result_of_key_of_<
                            typename _fusion_result_of_begin_<T>::type
                          >::type
                        >
                      >
                    , _is_valid_expression_(
                        _fusion_has_key_<
                          typename _fusion_result_of_key_of_<
                            typename _fusion_result_of_begin_<T>::type
                          >::type
                        >(_declref_<T>())
                      )
                    >
                  , _mpl_eval_if_<
                      _fusion_result_of_has_key_<
                        T
                      , typename _fusion_result_of_key_of_<
                          typename _fusion_result_of_begin_<T>::type
                        >::type
                      >
                    , _mpl_if_<
                        _mpl_and_<
                          _bct_has_type_<
                            _fusion_result_of_value_at_key_<
                              T
                            , typename _fusion_result_of_key_of_<
                                typename _fusion_result_of_begin_<
                                  T
                                >::type
                              >::type
                            >
                          >
                        , _is_valid_expression_(
                            _fusion_at_key_<
                              typename _fusion_result_of_key_of_<
                                typename _fusion_result_of_begin_<
                                  T
                                >::type
                              >::type
                            >(_declref_<T>())
                          )
                        >
                      , _std_is_convertible_<
                          _decltype_(
                            _fusion_at_key_<
                              typename _fusion_result_of_key_of_<
                                typename _fusion_result_of_begin_<
                                  T
                                >::type
                              >::type
                            >(_declref_<T>())
                          )
                        , typename _fusion_result_of_value_at_key_<
                            T
                          , typename _fusion_result_of_key_of_<
                              typename _fusion_result_of_begin_<
                                T
                              >::type
                            >::type
                          >::type
                        >
                      , _mpl_false_
                      >
                    , _mpl_false_
                    >
                  , _mpl_false_
                  >
                , _mpl_false_
                >
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::concept::traits::_detail::metafunction
        ::is_fusion_sequence_empty_or_not<
            T
          , ::boost::fusion::traits::is_associative< ::boost::mpl::_>
          , ::boost::concept::traits::is_fusion_associative_iterator<
                ::boost::mpl::_
            >
          , ::boost::concept::traits::_detail::metafunction
            ::is_fusion_forward_sequence_impl< ::boost::mpl::_>
          , ::boost::concept::traits::_detail::metafunction
            ::is_nonempty_fusion_associative_sequence<
                ::boost::mpl::_
              , ::boost::mpl::_
            >
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

