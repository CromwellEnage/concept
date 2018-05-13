// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_HAS_AUTO_TYPE_POP_BACK_HPP
#define BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_HAS_AUTO_TYPE_POP_BACK_HPP

#include <boost/utility/declref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_same.hpp>
#if !defined BOOST_NO_CXX11_DECLTYPE
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#endif
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_auto_type_pop_back_impl
      : ::boost::mpl::if_<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            ::boost::is_same<
#else
            ::std::is_same<
#endif
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF_KEYWORD(::boost::declref<T>().pop_back())
#else
                decltype(::boost::declref<T>().pop_back())
#endif
              , typename T::auto_type
            >
          , ::boost::concept::traits::has_pop_back<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF_KEYWORD(::boost::declref<T>().base())
#else
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::remove_const<
                    typename ::boost::remove_reference<
#else
                typename ::std::remove_const<
                    typename ::std::remove_reference<
#endif
                        decltype(::boost::declref<T>().base())
                    >::type
                >::type
#endif  // BOOST_NO_CXX11_HDR_TYPE_TRAITS
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/tti/detail/dnullptr.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_pointer.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    class has_auto_type_pop_back
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check(
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
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef typename ::boost::mpl::if_c<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_auto_type_pop_back<T>
                        ::_check<T>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                  , ::boost::concept::traits::_detail::metafunction
                    ::has_auto_type_pop_back_impl<T>
                  , ::boost::mpl::false_
                >::type
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

