// Copyright (C) 2012-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_BACK_INSERTION_SEQUENCE_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_BACK_INSERTION_SEQUENCE_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_input_iterator.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_minimal_or_mutable_ds.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_back_ins_sequence_impl.hpp>
#include <boost/mpl/placeholders.hpp>

//[reference__is_back_insertion_sequence
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_back_insertion_sequence
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_is_sequence_<T>
          , _mpl_eval_if_<
                _bct_has_back_<typename _std_add_const_<T>::type>
              , _mpl_if_<
                    _bct_has_push_back_<
                        typename _std_remove_const_<T>::type
                    >
                  , _bct_has_pop_back_<
                        typename _std_remove_const_<T>::type
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
            ::is_back_insertion_sequence_impl<
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

