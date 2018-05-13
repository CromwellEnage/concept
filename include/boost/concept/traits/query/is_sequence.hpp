// Copyright (C) 2012-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_SEQUENCE_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_SEQUENCE_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_input_iterator.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_minimal_or_mutable_ds.hpp>
#include <boost/concept/traits/_detail/metafunction/is_sequence_impl.hpp>
#include <boost/mpl/placeholders.hpp>

//[reference__is_sequence
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_sequence
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_is_container_<T>
          , _mpl_eval_if_<
                _bct_has_erase_<
                    typename _std_remove_const_<T>::type
                  , typename _std_remove_const_<T>::type::iterator
                >
              , _mpl_eval_if_<
                    _bct_has_clear_<typename _std_remove_const_<T>::type>
                  , _mpl_eval_if_<
                        _bct_has_resize_<
                            typename _std_remove_const_<T>::type
                        >
                      , _mpl_eval_if_<
                            _bct_is_ptr_container_<T>
                          , _mpl_if_<
                                _bct_has_insert_<
                                    typename _std_remove_const_<T>::type
                                  , typename _std_remove_const_<T>::type
                                    ::iterator
                                  , _decltype_(&*_declref_<T>().begin())
                                >
                              , _bct_has_insert_<
                                    typename _std_remove_const_<
                                        typename _std_remove_reference_<
                                            _decltype_(_declref_<T>.base())
                                        >::type
                                    >::type
                                  , typename _std_remove_const_<
                                        typename _std_remove_reference_<
                                            _decltype_(_declref_<T>.base())
                                        >::type
                                    >::type::iterator
                                  , _decltype_(
                                        *_declcref_<
                                            _decltype_(_declref_<T>.base())
                                        >().begin()
                                    )
                                  , boost::concept::policy::use_default
                                  , _mpl_if_<
                                        _bct_is_iterator_of_<
                                            _mpl_placeholder_1_
                                          , T
                                        >
                                      , _mpl_true_
                                      , _bct_is_iterator_bool_pair_of_<
                                            _mpl_placeholder_1_
                                          , T
                                        >
                                    >
                                >
                              , _mpl_false_
                            >
                          , _bct_has_insert_<
                                typename _std_remove_const_<T>::type
                              , typename _std_remove_const_<T>::type::iterator
                              , _decltype_(*_declcref_<T>().begin())
                              , boost::concept::policy::use_default
                              , _mpl_if_<
                                    _bct_is_iterator_of_<
                                        _mpl_placeholder_1_
                                      , T
                                    >
                                  , _mpl_true_
                                  , _bct_is_iterator_bool_pair_of_<
                                        _mpl_placeholder_1_
                                      , T
                                    >
                                >
                            >
                        >
                      , _mpl_false_
                    >
                  , _mpl_false_
                >
              , _mpl_eval_if_<
                    _bct_has_insert_after_<
                        typename _std_remove_const_<T>::type
                      , typename _std_remove_const_<T>::type::const_iterator
                      , typename _std_remove_const_<T>::type::value_type
                    >
                  , _mpl_if_<
                        _bct_has_erase_after_<
                            typename _std_remove_const_<T>::type
                          , typename _std_remove_const_<T>::type
                            ::const_iterator
                        >
                      , _bct_has_erase_after_<
                            typename _std_remove_const_<T>::type
                          , typename _std_remove_const_<T>::type
                            ::const_iterator
                          , typename _std_remove_const_<T>::type
                            ::const_iterator
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
            ::is_sequence_impl< ::boost::mpl::_1,::boost::mpl::_2>
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

