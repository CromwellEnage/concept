// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_BACK_INS_SEQUENCE_IMPL_HPP
#define \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_BACK_INS_SEQUENCE_IMPL_HPP

#include <boost/concept/traits/introspection/member_function/has_back.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_push_back.hpp>
#include <boost/concept/traits/introspection/member_function/has_pop_back.hpp>
#include <boost/concept/traits/_detail/metafunction/is_sequence_impl.hpp>
#include \
<boost/concept/traits/_detail/metafunction/has_ptr_container_members.hpp>
#include \
<boost/concept/traits/_detail/metafunction/has_auto_type_pop_back.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename UMFC>
    struct is_back_insertion_sequence_impl
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::_detail::metafunction
            ::is_sequence_impl<T,UMFC>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_back<T const>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_push_back<T>
                  , ::boost::mpl::eval_if<
                        ::boost::concept::traits::_detail::metafunction
                        ::has_ptr_container_members<T>
                      , ::boost::concept::traits::_detail::metafunction
                        ::has_auto_type_pop_back<T>
                      , ::boost::concept::traits::has_pop_back<T>
                    >
                  , ::boost::mpl::false_
                >
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

