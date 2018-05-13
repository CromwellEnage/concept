// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_FUSION_RA_SEQUENCE_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_FUSION_RA_SEQUENCE_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_fusion_ra_iterator.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_fusion_seq_empty_or_not.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_fusion_fwd_sequence_impl.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_fusion_ra_sequence_impl.hpp>
#include <boost/fusion/support/category_of.hpp>
#include <boost/mpl/placeholders.hpp>

//[reference__is_fusion_random_access_sequence
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_fusion_random_access_sequence
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            typename _mpl_eval_if_<
                typename _mpl_eval_if_<
                    _fusion_traits_is_sequence_<T>
                  , _fusion_traits_is_random_access_<T>
                  , _mpl_eval_if_<
                        _bct_has_is_view_<T>
                      , _mpl_if_<
                            _fusion_traits_is_view_<T>
                          , _fusion_traits_is_random_access_<T>
                          , _mpl_false_
                        >
                      , _mpl_false_
                    >
                  , _mpl_false_
                >::type
              , _bct_is_fusion_bidirectional_sequence_<T>
              , _mpl_false_
            >::type
          , _mpl_eval_if_<
                _fusion_result_of_empty_<
                    typename _std_remove_const_<T>::type
                >
              , _mpl_true_
              , _mpl_eval_if_<
                    _mpl_and_<
                        _bct_is_fusion_random_access_iterator_<
                            typename _fusion_result_of_begin_<T>::type
                        >
                      , _bct_is_fusion_random_access_iterator_<
                            typename _fusion_result_of_end_<T>::type
                        >
                      , _bct_has_type_<
                            _fusion_result_of_at_c_<T,0>
                        >
                      , _bct_has_type_<
                            _fusion_result_of_at_<
                                T
                              , _mpl_int_<0>
                            >
                        >
                      , _bct_has_type_<
                            _fusion_result_of_value_at_c_<T,0>
                        >
                      , _bct_has_type_<
                            _fusion_result_of_value_at_<
                                T
                              , _mpl_int_<0>
                            >
                        >
                      , _is_valid_expression_(
                            _fusion_at_< _mpl_int_<0> >(
                                _declref_<T>()
                            )
                        )
                      , _is_valid_expression_(
                            _fusion_at_c_<0>(_declref_<T>())
                        )
                    >
                  , _mpl_and_<
                        _std_is_same_<
                            _decltype_(
                                _fusion_at_c_<0>(_declref_<T>())
                            )
                          , typename _fusion_result_of_at_c_<T,0>::type
                        >
                      , _std_is_same_<
                            _decltype_(
                                _fusion_at_< _mpl_int_<0> >(
                                    _declref_<T>()
                                )
                            )
                          , typename _fusion_result_of_at_<
                                T
                              , _mpl_int_<0>
                            >::type
                        >
                      , _std_is_same_<
                            typename _fusion_result_of_at_c_<T,0>::type
                          , typename _fusion_result_of_front_<T>::type
                        >
                      , _std_is_same_<
                            typename _fusion_result_of_at_<
                                T
                              , _mpl_int_<0>
                            >::type
                          , typename _fusion_result_of_front_<T>::type
                        >
                      , _std_is_same_<
                            typename _fusion_result_of_at_c_<
                                T
                              , _mpl_minus_<
                                    _fusion_result_of_size_<T>
                                  , _mpl_int_<1>
                                >::value
                            >::type
                          , typename _fusion_result_of_back_<T>::type
                        >
                      , _std_is_same_<
                            typename _fusion_result_of_at_<
                                T
                              , _mpl_minus_<
                                    _fusion_result_of_size_<T>
                                  , _mpl_int_<1>
                                >
                            >::type
                          , typename _fusion_result_of_back_<T>::type
                        >
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
          , ::boost::fusion::traits::is_random_access< ::boost::mpl::_>
          , ::boost::concept::traits::is_fusion_random_access_iterator<
                ::boost::mpl::_
            >
          , ::boost::concept::traits::_detail::metafunction
            ::is_fusion_forward_sequence_impl< ::boost::mpl::_>
          , ::boost::concept::traits::_detail::metafunction
            ::is_nonempty_fusion_random_access_sequence<
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

