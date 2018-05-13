// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_ALLOCATE_CLONE_HPP
#define \
BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_ALLOCATE_CLONE_HPP

#include <boost/concept/traits/declref.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/typeof/typeof.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename U, typename ResultPlaceholderExpr>
    struct has_allocate_clone_impl
      : ::boost::mpl::apply1<
            ResultPlaceholderExpr
#if defined(BOOST_NO_CXX11_DECLTYPE)
          , BOOST_TYPEOF_KEYWORD(
                ::boost::concept::traits::declref<T>().allocate_clone(
                    ::boost::concept::traits::declcref<U>()
                )
            )
#else
          , decltype(
                ::boost::concept::traits::declref<T>().allocate_clone(
                    ::boost::concept::traits::declcref<U>()
                )
            )
#endif
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/tti/detail/dnullptr.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/add_pointer.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename U>
    class has_allocate_clone
    {
        template <typename B, typename C>
        static ::boost::type_traits::yes_type
            _check(
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::add_pointer<
#else
                typename ::std::add_pointer<
#endif
#if defined(BOOST_NO_CXX11_DECLTYPE)
                    BOOST_TYPEOF_KEYWORD(
                        ::boost::concept::traits::declref<B>().allocate_clone(
                            boost::concept::traits::declcref<C>()
                        )
                    )
#else
                    decltype(
                        ::boost::concept::traits::declref<B>().allocate_clone(
                            boost::concept::traits::declcref<C>()
                        )
                    )
#endif
                >::type
            );

        template <typename B, typename C>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::boost::concept::traits::_detail::metafunction
                ::has_allocate_clone<T,U>::BOOST_NESTED_TEMPLATE
                _check<T,U>(BOOST_TTI_DETAIL_NULLPTR)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/member_function_fwd.hpp>
#include <boost/concept/traits/introspection/is_raw_pointer_of.hpp>
#include <boost/mpl/if.hpp>

//[reference__has_allocate_clone
namespace boost { namespace concept { namespace traits {

    template <typename T, typename U, typename ResultPlaceholderExpr>
    struct has_allocate_clone
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _is_valid_expression_(
                _bct_declref_<T>().allocate_clone(
                    _bct_declcref_<U>()
                )
            )
          , _mpl_apply1_<
                ResultPlaceholderExpr
              , _decltype_(
                    _bct_declref_<T>().allocate_clone(
                        _bct_declcref_<U>()
                    )
                )
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::if_<
            typename ::boost::concept::traits::_detail::metafunction
            ::has_allocate_clone<T,U>::type
          , ::boost::concept::traits::_detail::metafunction
            ::has_allocate_clone_impl<T,U,ResultPlaceholderExpr>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

