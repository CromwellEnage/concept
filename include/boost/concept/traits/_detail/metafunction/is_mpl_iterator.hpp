// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_MPL_ITERATOR_HPP
#define BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_MPL_ITERATOR_HPP

#include <boost/concept/traits/query/is_mpl_integral_constant.hpp>
#include <boost/concept/traits/introspection/nested_type/has_type.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/iterator_category.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/less_equal.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Tag>
    class is_mpl_iterator
    {
        typedef typename ::boost::mpl::iterator_category<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                    typename ::boost::remove_const<T>::type
#else
                    typename ::std::remove_const<T>::type
#endif
                >::type
                _category;

     public:
        typedef typename ::boost::mpl::if_<
                    ::boost::concept::traits::is_mpl_integral_constant<
                        _category
                    >
                  , ::boost::mpl::less_equal<Tag,_category>
                  , ::boost::mpl::false_
                >::type
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

