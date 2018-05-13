// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_PAIR_ASSOC_CONTAINER_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_PAIR_ASSOC_CONTAINER_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_associative_container.hpp>
#include <boost/concept/traits/introspection/nested_type/has_mapped_type.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_pair_assoc_cont_impl.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>

//[reference__is_pair_associative_container
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_pair_associative_container
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
          _bct_is_associative_container_<T>
        , _mpl_eval_if_<
            _bct_has_mapped_type_<T>
          , _mpl_eval_if_<
              _bct_is_runtime_pair_<
                typename _bct_value_type_of_<T>::type
              >
            , _mpl_eval_if_<
                _std_is_same_<
                  typename _std_add_const_<
                    typename _bct_key_type_of_<T>::type
                  >::type
                , typename _std_add_const_<
                    typename _bct_first_type_of_<
                      typename _bct_value_type_of_<T>::type
                    >::type
                  >::type
                >
              , _mpl_if_<
                  _std_is_same_<
                    typename _bct_second_type_of_<
                      typename _bct_value_type_of_<T>::type
                    >::type
                  , typename _bct_mapped_type_of_<T>::type
                  >
                , _mpl_true_
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
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_associative_container<T>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_mapped_type<T>
              , ::boost::concept::traits::_detail::metafunction
                ::is_pair_associative_container_impl<T>
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

