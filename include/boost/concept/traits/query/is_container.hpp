// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_CONTAINER_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_CONTAINER_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_input_iterator.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_minimal_or_mutable_ds.hpp>
#include <boost/concept/traits/_detail/metafunction/is_container_impl.hpp>
#include <boost/mpl/placeholders.hpp>

//[reference__is_container
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_container
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_has_value_type_<T>
          , _mpl_eval_if_<
                _bct_has_reference_<
                    typename _std_add_const_<T>::type
                >
              , _mpl_eval_if_<
                    _bct_is_range_<
                        typename _std_add_const_<T>::type
                      , _bct_is_input_iterator_<
                            _mpl_placeholder_
                        >
                    >
                  , _mpl_eval_if_<
                        _bct_has_iterator_<
                            typename _std_add_const_<T>::type
                        >
                      , _mpl_eval_if_<
                            _bct_has_reference_<
                                typename _std_add_const_<T>::type
                            >
                          , _mpl_if_<
                                _bct_is_range_<
                                    typename _std_remove_const_<T>::type
                                  , _bct_is_input_iterator_<
                                        _mpl_placeholder_
                                    >
                                >
                              , _bct_has_iterator_<
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
        >::type
//<-
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::concept::traits::_detail::metafunction
        ::is_minimal_or_mutable_ds<
            T
          , ::boost::concept::traits::is_input_iterator< ::boost::mpl::_>
          , ::boost::concept::traits::_detail::metafunction
            ::is_minimal_container_impl< ::boost::mpl::_,::boost::mpl::_>
          , ::boost::concept::traits::_detail::metafunction
            ::is_mutable_container_impl< ::boost::mpl::_>
        >
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

