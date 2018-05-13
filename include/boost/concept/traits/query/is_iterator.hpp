// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_ITERATOR_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_ITERATOR_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/_detail/metafunction/is_iterator.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#else
#include <type_traits>
#endif

//[reference__is_iterator
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_iterator
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _bct_is_lvalue_assignable_<
                typename _std_remove_const_<
                    typename _std_remove_reference_<T>::type
                >::type
            >
          , _mpl_eval_if_<
                _is_valid_expression_(
                    *_bct_declref_<
                        typename _std_remove_const_<
                            typename _std_remove_reference_<T>::type
                        >::type
                    >()
                )
              , _mpl_if_<
                    _std_is_void_<
                        _decltype_(
                            *_bct_declref_<
                                typename _std_remove_const_<
                                    typename _std_remove_reference_<T>::type
                                >::type
                            >()
                        )
                    >
                  , _mpl_false_
                  , _is_valid_expression_(
                        ++_bct_declref_<
                            typename _std_remove_const_<
                                typename _std_remove_reference_<T>::type
                            >::type
                        >()
                    )
                >
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::concept::traits::_detail::metafunction::is_iterator<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
            typename ::boost::remove_const<
                typename ::boost::remove_reference<T>::type
            >::type
#else
            typename ::std::remove_const<
                typename ::std::remove_reference<T>::type
            >::type
#endif
        >
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

