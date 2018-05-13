// Copyright (C) 2011-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_PTR_CONTAINER_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_PTR_CONTAINER_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_container.hpp>
#include \
<boost/concept/traits/_detail/metafunction/has_ptr_container_members.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

//[reference__is_ptr_container
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_ptr_container
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_is_container_<T>
          , _mpl_if_<
                _bct_has_base_<
                    typename _std_remove_const_<T>::type
                  , _bct_is_container_<
                        typename _std_remove_reference_<
                            _mpl_placeholder_
                        >::type
                    >
                  , _mpl_false_
                >
              , _bct_has_auto_type_<T>
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::if_<
            ::boost::concept::traits::is_container<T>
          , ::boost::concept::traits::_detail::metafunction
            ::has_ptr_container_members<T>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

