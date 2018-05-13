// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_UBLAS_MATRIX_EXPRESSION_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_UBLAS_MATRIX_EXPRESSION_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_bidirectional_iterator.hpp>
#include <boost/concept/traits/query/is_indexable_iterator.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_minimal_or_mutable_ds.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_ublas_matrix_expression.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_container_impl.hpp>
#include <boost/mpl/placeholders.hpp>

//[reference__is_ublas_matrix_expression
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_ublas_matrix_expression
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
          _std_is_base_of_<
            _numeric_ublas_matrix_expression_<
              typename _std_remove_const_<T>::type
            >
          , typename _std_remove_const_<T>::type
          >
        , _mpl_eval_if_<
            _mpl_and_<
              _bct_has_value_type_<T>
            , _bct_has_reference_<
                typename _std_add_const_<T>::type
              >
            , _bct_has_reference_<
                typename _std_remove_const_<T>::type
              >
            , _bct_has_size1_<
                typename _std_add_const_<T>::type
              >
            , _bct_has_size2_<
                typename _std_add_const_<T>::type
              >
            , _bct_has_begin1_<
                typename _std_add_const_<T>::type
              >
            , _bct_has_begin1_<
                typename _std_remove_const_<T>::type
              >
            , _bct_has_begin2_<
                typename _std_add_const_<T>::type
              >
            , _bct_has_begin2_<
                typename _std_remove_const_<T>::type
              >
            , _bct_has_end1_<
                typename _std_add_const_<T>::type
              >
            , _bct_has_end1_<
                typename _std_remove_const_<T>::type
              >
            , _bct_has_end2_<
                typename _std_add_const_<T>::type
              >
            , _bct_has_end2_<
                typename _std_remove_const_<T>::type
              >
            , _bct_has_rbegin1_<
                typename _std_add_const_<T>::type
              >
            , _bct_has_rbegin1_<
                typename _std_remove_const_<T>::type
              >
            , _bct_has_rbegin2_<
                typename _std_add_const_<T>::type
              >
            , _bct_has_rbegin2_<
                typename _std_remove_const_<T>::type
              >
            , _bct_has_rend1_<
                typename _std_add_const_<T>::type
              >
            , _bct_has_rend1_<
                typename _std_remove_const_<T>::type
              >
            , _bct_has_rend2_<
                typename _std_add_const_<T>::type
              >
            , _bct_has_rend2_<
                typename _std_remove_const_<T>::type
              >
            >
          , _mpl_eval_if_<
              _mpl_and_<
                _bct_is_indexable_iterator_<
                  typename _std_remove_const_<T>::type::iterator
                >
              , _bct_is_indexable_iterator_<
                  typename _std_remove_const_<T>::type::const_iterator
                >
              , _bct_is_indexable_iterator_<
                  typename _std_remove_const_<T>::type::reverse_iterator
                >
              , _bct_is_indexable_iterator_<
                  typename _std_remove_const_<T>::type::const_reverse_iterator
                >
              , _bct_is_callable_<
                  typename _std_add_const<T>_::type(
                    typename _std_remove_const<T>_::type::size_type
                  , typename _std_remove_const<T>_::type::size_type
                  )
                , _std_is_convertible_<
                    _mpl_placeholder_
                  , typename _std_remove_const_<T>::type::value_type
                  >
                >
              , _bct_is_callable_<
                  typename _std_remove_const<T>_::type(
                    typename _std_remove_const<T>_::type::size_type
                  , typename _std_remove_const<T>_::type::size_type
                  )
                , _std_is_convertible_<
                    _mpl_placeholder_
                  , typename _std_remove_const_<T>::type::value_type
                  >
                >
              >
            , _mpl_eval_if_<
                _std_is_const_<T>
              , _mpl_true_
              , _mpl_eval_if_<
                  _bct_has_assign_<T>
                , _mpl_eval_if_<
                    _bct_is_addition_assignable_<T>
                  , _mpl_eval_if_<
                      _bct_has_plus_assign_<T>
                    , _mpl_eval_if_<
                        _bct_is_subtraction_assignable_<T>
                      , _mpl_if_<
                          _bct_has_minus_assign_<T>
                        , _bct_is_multiplication_assignable_<
                            T
                          , typename T::value_type
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
          , ::boost::concept::traits::is_bidirectional_iterator< ::boost::mpl::_1>
          , ::boost::concept::traits::_detail::metafunction
            ::is_ublas_matrix_expression< ::boost::mpl::_1,::boost::mpl::_2>
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

