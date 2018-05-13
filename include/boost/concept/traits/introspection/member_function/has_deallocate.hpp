// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_DEALLOCATE_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_DEALLOCATE_HPP

#include <boost/concept/traits/trivial_access/pointer_of.hpp>
#include <boost/concept/traits/trivial_access/allocator_size_of.hpp>
#include <boost/concept/traits/declref.hpp>
#include <boost/tti/detail/dnullptr.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/declval.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/typeof/typeof.hpp>
#endif

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/add_pointer.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    class has_deallocate
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check(
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::add_pointer<
#else
                typename ::std::add_pointer<
#endif
#if defined(BOOST_NO_CXX11_DECLTYPE)
                    BOOST_TYPEOF_KEYWORD((
                        ::boost::declref<B>().deallocate(
                            ::boost::declval<
                                typename ::boost::concept::traits
                                ::pointer_of<B>::type
                            >()
                          , ::boost::declval<
                                typename ::boost::concept::traits
                                ::allocator_size_of<B>::type
                            >()
                        )
                    ))
#else
                    decltype(
                        ::boost::declref<B>().deallocate(
                            ::boost::declval<
                                typename ::boost::concept::traits
                                ::pointer_of<B>::type
                            >()
                          , ::boost::declval<
                                typename ::boost::concept::traits
                                ::allocator_size_of<B>::type
                            >()
                        )
                    )
#endif  // BOOST_NO_CXX11_DECLTYPE
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::boost::concept::traits::_detail::metafunction
                ::has_deallocate<T>::_check<T>(BOOST_TTI_DETAIL_NULLPTR)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/member_function_fwd.hpp>
#include <boost/concept/traits/introspection/nested_type/has_pointer.hpp>
#include <boost/concept/traits/introspection/nested_type/has_value_type.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

//[reference__has_deallocate
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct has_deallocate
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_if_<
            typename _mpl_if_<
                _bct_has_pointer_<T>
              , _mpl_true_
              , _bct_has_value_type_<T>
            >::type
          , _is_valid_expression_(
                _bct_declref_<T>().deallocate(
                    _declval_<
                        typename _bct_pointer_of_<T>::type
                    >()
                  , _declval_<
                        typename _bct_allocator_size_of_<T>::type
                    >()
                )
            )
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::eval_if<
            typename ::boost::mpl::if_<
                ::boost::concept::traits::has_pointer<T>
              , ::boost::mpl::true_
              , ::boost::concept::traits::has_value_type<T>
            >::type
          , ::boost::concept::traits::_detail::metafunction::has_deallocate<T>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

