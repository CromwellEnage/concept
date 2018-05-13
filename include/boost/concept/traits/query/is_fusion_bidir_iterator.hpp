// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_FUSION_BIDIR_ITERATOR_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_FUSION_BIDIR_ITERATOR_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_fusion_fwd_iterator_impl.hpp>
#include <boost/fusion/support/is_iterator.hpp>
#include <boost/fusion/support/category_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>

//[reference__is_fusion_bidirectional_iterator
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_fusion_bidirectional_iterator
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            typename _mpl_eval_if_<
                _fusion_is_fusion_iterator_<T>
              , _fusion_traits_is_bidirectional_<T>
              , _mpl_false_
            >::type
          , _mpl_eval_if_<
                _is_valid_expression_(
                    _fusion_distance_(
                        _declcref_<T>()
                      , _declcref_<T>()
                    )
                )
              , _mpl_eval_if_<
                    _bct_is_equality_comparable_<T>
                  , _mpl_eval_if_<
                        _bct_is_mpl_boolean_constant_<
                            _fusion_result_of_equal_to_<T,T>
                        >
                      , _mpl_eval_if_<
                            _bct_has_type_<
                                _fusion_result_of_distance_<T,T>
                            >
                          , _mpl_if_<
                                _std_is_same_<
                                    _fusion_distance_(
                                        _declcref_<T>()
                                      , _declcref_<T>()
                                    )
                                  , typename _fusion_result_of_distance_<
                                        T
                                      , T
                                    >::type
                                >
                              , _bct_is_mpl_integral_constant_<
                                    typename _fusion_result_of_distance_<
                                        T
                                      , T
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
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::mpl::eval_if<
            typename ::boost::mpl::eval_if<
                ::boost::fusion::is_fusion_iterator<T>
              , ::boost::fusion::traits::is_bidirectional<T>
              , ::boost::mpl::false_
            >::type
          , ::boost::concept::traits::_detail::metafunction
            ::is_fusion_forward_iterator_impl<T,T>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

