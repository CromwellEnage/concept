// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_ASSOCIATIVE_CONTAINER_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_ASSOCIATIVE_CONTAINER_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_input_iterator.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_minimal_or_mutable_ds.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_assoc_container_impl.hpp>
#include <boost/mpl/placeholders.hpp>

//[reference__is_associative_container
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_associative_container
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_is_container_<T>
          , _mpl_eval_if_<
                _bct_has_equal_range_<
                    typename _std_add_const_<T>::type
                >
              , _mpl_eval_if_<
                    _bct_has_equal_range_<
                        typename _std_remove_const_<T>::type
                    >
                  , _mpl_eval_if_<
                        _bct_has_find_<
                            typename _std_add_const_<T>::type
                        >
                      , _mpl_eval_if_<
                            _bct_has_find_<
                                typename _std_remove_const_<T>::type
                            >
                          , _mpl_eval_if_<
                                _bct_has_count_<
                                    typename _std_add_const_<T>::type
                                >
                              , _mpl_eval_if_<
                                    _bct_has_max_size_<
                                        typename _std_add_const_<T>::type
                                    >
                                  , _mpl_eval_if_<
                                        _bct_has_size_<
                                            typename _std_add_const_<T>::type
                                        >
                                      , _mpl_eval_if_<
                                            _std_is_const_<T>
                                          , _mpl_true_
                                          , _mpl_eval_if_<
                                              _bct_has_erase_<
                                                T
                                              , _bct_is_size_type_of_<
                                                  _mpl_placeholder_
                                                , T
                                                >
                                              , typename _bct_key_type_of_<
                                                  T
                                                >::type
                                              >
                                            , _bct_has_clear_<T>
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
            ::is_minimal_associative_container_impl<
                ::boost::mpl::_1
              , ::boost::mpl::_2
            >
          , ::boost::concept::traits::_detail::metafunction
            ::is_mutable_associative_container_impl< ::boost::mpl::_1>
        >
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

