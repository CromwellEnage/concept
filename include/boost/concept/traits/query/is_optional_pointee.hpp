// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_OPTIONAL_POINTEE_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_OPTIONAL_POINTEE_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_logically_negatable.hpp>
#include <boost/concept/traits/_detail/metafunction/is_dereferenceable.hpp>
#include <boost/mpl/if.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#else
#include <type_traits>
#endif

//[reference__is_optional_pointee
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_optional_pointee
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
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
              , _bct_is_logically_negatable_<T>
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::mpl::if_<
            typename ::boost::concept::traits::_detail::metafunction
            ::is_dereferenceable<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::remove_const<
                    typename ::boost::remove_reference<T>::type
                >::type
#else
                typename ::std::remove_const<
                    typename ::std::remove_reference<T>::type
                >::type
#endif
            >::type
          , ::boost::concept::traits::is_logically_negatable<T>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

