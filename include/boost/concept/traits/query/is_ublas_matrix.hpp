// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_UBLAS_MATRIX_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_UBLAS_MATRIX_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_bidirectional_iterator.hpp>
#include <boost/concept/traits/query/is_indexable_iterator.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_minimal_or_mutable_ds.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_ublas_matrix_expression.hpp>
#include \
<boost/concept/traits/_detail/metafunction/has_computed_assignment_ops.hpp>
#include <boost/mpl/placeholders.hpp>

//[reference__is_ublas_matrix
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_ublas_matrix
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
          _bct_is_ublas_matrix_expression_<T>
        , _mpl_eval_if_<
            _std_is_base_of_<
              _numeric_ublas_matrix_container_<
                typename _std_remove_const_<T>::type
              >
            , typename _std_remove_const_<T>::type
            >
          , _mpl_eval_if_<
              _std_is_const_<T>
            , _mpl_true_
            , _mpl_eval_if_<
                _bct_has_insert_element_2dim_<T>
              , _mpl_if_<
                  _bct_has_erase_element_2dim_<T>
                , _bct_has_resize_2dim_<T>
                , _mpl_false_
                >
              , _mpl_false_
              >
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
            ::has_computed_assignment_ops< ::boost::mpl::_1>
        >
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

