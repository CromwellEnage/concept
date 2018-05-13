// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_TRIVIAL_ACCESS_VOID_POINTER_OF_HPP
#define BOOST_CONCEPT_TRAITS_TRIVIAL_ACCESS_VOID_POINTER_OF_HPP

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct void_pointer_of_actual
    {
        typedef typename T::void_pointer type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct const_void_pointer_of_actual
    {
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
        typedef typename ::boost::remove_const<
#else
        typedef typename ::std::remove_const<
#endif
            T
        >::type::const_void_pointer type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include \
<boost/concept/traits/_detail/metafunction/pointer_of_actual_or_value.hpp>

#if defined(BOOST_NO_CXX11_POINTER_TRAITS)
#include <boost/intrusive/pointer_traits.hpp>
#else
#include <memory>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct void_pointer_of_rebind
    {
#if defined(BOOST_NO_CXX11_POINTER_TRAITS)
        typedef ::boost::intrusive::pointer_traits<
#else
        typedef ::std::pointer_traits<
#endif
            typename ::boost::concept::traits::_detail::metafunction
            ::pointer_of_actual_or_value<T>::type
        >::BOOST_NESTED_TEMPLATE rebind<void> type;
    };

    template <typename T>
    struct const_void_pointer_of_rebind
    {
#if defined(BOOST_NO_CXX11_POINTER_TRAITS)
        typedef ::boost::intrusive::pointer_traits<
#else
        typedef ::std::pointer_traits<
#endif
            typename ::boost::concept::traits::_detail::metafunction
            ::pointer_of_actual_or_value<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::remove_const<T>::type
#else
                typename ::std::remove_const<T>::type
#endif
            >::type
        >::BOOST_NESTED_TEMPLATE rebind<void const> type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type/has_void_pointer.hpp>
#include <boost/type_erasure/is_placeholder.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct const_void_pointer_of_impl
      : ::boost::mpl::eval_if<
            ::boost::type_erasure::is_placeholder<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::remove_const<T>::type
#else
                typename ::std::remove_const<T>::type
#endif
            >
          , ::boost::mpl::identity<void>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_void_pointer<T>
              , ::boost::concept::traits::_detail::metafunction
                ::const_void_pointer_of_actual<T>
              , ::boost::concept::traits::_detail::metafunction
                ::const_void_pointer_of_rebind<T>
            >
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/config/workaround.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS) || ( \
        BOOST_WORKAROUND(BOOST_MSVC, >= 1700) && \
        BOOST_WORKAROUND(BOOST_MSVC, < 1800) \
    )
#include <boost/type_traits/is_const.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct void_pointer_of
      : ::boost::mpl::eval_if<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS) || ( \
        BOOST_WORKAROUND(BOOST_MSVC, >= 1700) && \
        BOOST_WORKAROUND(BOOST_MSVC, < 1800) \
    )
            ::boost::is_const<T>
#else
            ::std::is_const<T>
#endif
          , ::boost::concept::traits::_detail::metafunction
            ::const_void_pointer_of_impl<T>
          , ::boost::mpl::eval_if<
                ::boost::type_erasure::is_placeholder<T>
              , ::boost::mpl::identity<void>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_void_pointer<T>
                  , ::boost::concept::traits::_detail::metafunction
                    ::void_pointer_of_actual<T>
                  , ::boost::concept::traits::_detail::metafunction
                    ::void_pointer_of_rebind<T>
                >
            >
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/trivial_access_fwd.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_reference.hpp>
#endif

//[reference__void_pointer_of
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct void_pointer_of
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _type_erasure_is_placeholder_<
                typename _std_remove_const_<
                    typename _std_remove_reference_<T>::type
                >::type
            >
          , _mpl_identity_<void>
          , _mpl_if_<
                _std_is_const_<
                    typename _std_remove_reference_<T>::type
                >
              , typename _std_allocator_traits_<
                    typename _std_remove_const_<
                        typename _std_remove_reference_<T>::type
                    >::type
                >::const_void_pointer
              , typename _std_allocator_traits_<
                    typename _std_remove_reference_<T>::type
                >::void_pointer
            >
        >
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::concept::traits::_detail::metafunction
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
        ::void_pointer_of<typename ::boost::remove_reference<T>::type>
#else
        ::void_pointer_of<typename ::std::remove_reference<T>::type>
#endif
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#if defined(BOOST_NO_CXX11_TEMPLATE_ALIASES)

namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct void_pointer_of_t
      : ::boost::concept::traits::void_pointer_of<T>::type
    {
    };
}}}  // namespace boost::concept::traits

#endif

#endif  // include guard

