// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_POP_BACK_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_POP_BACK_HPP

#include <boost/utility/declref.hpp>
#include <boost/tti/detail/dnullptr.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_pointer.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    class has_pop_back
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _chk(
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::add_pointer<
#else
                typename ::std::add_pointer<
#endif
#if defined BOOST_NO_CXX11_DECLTYPE
                    BOOST_TYPEOF_KEYWORD(::boost::declref<B>().pop_back())
#else
                    decltype(::boost::declref<B>().pop_back())
#endif
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _chk(...);

     public:
        typedef ::boost::mpl::bool_<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_pop_back<T>::_chk<T>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                >
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/member_function_fwd.hpp>

//[reference__has_pop_back
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct has_pop_back
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _is_valid_expression_(_declref_<T>().pop_back())
//<-
#else
      : ::boost::concept::traits::_detail::metafunction::has_pop_back<T>::type
#endif
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

