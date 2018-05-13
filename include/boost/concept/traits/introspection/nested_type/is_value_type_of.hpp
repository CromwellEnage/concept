// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_NESTED_TYPE_IS_VALUE_TYPE_OF_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_NESTED_TYPE_IS_VALUE_TYPE_OF_HPP

#include <boost/concept/traits/trivial_access/value_type_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/is_same.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T1, typename T2>
    struct is_value_type_of_value
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      : ::boost::is_same<
#else
      : ::boost::mpl::if_<
            ::std::is_same<
#endif
                typename ::boost::concept::traits::value_type_of<T2>::type
              , T1
            >
#if !defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
          , ::boost::mpl::true_
          , ::boost::mpl::false_
        >::type
#endif
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/declref.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/typeof/typeof.hpp>
#elif defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T1, typename T2>
    struct is_value_type_of_begin_impl
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      : ::boost::is_same<
#else
      : ::boost::mpl::if_<
            ::std::is_same<
#endif
#if defined(BOOST_NO_CXX11_DECLTYPE)
                BOOST_TYPEOF_KEYWORD(
                    *::boost::concept::traits::declref<T2>().begin()
                )
#else   // !defined(BOOST_NO_CXX11_DECLTYPE)
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::remove_const<
                    typename ::boost::remove_reference<
#else
                typename ::std::remove_const<
                    typename ::std::remove_reference<
#endif
                        decltype(
                            *::boost::concept::traits::declref<T2>().begin()
                        )
                    >::type
                >::type
#endif  // BOOST_NO_CXX11_DECLTYPE
              , T1
            >
#if !defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
          , ::boost::mpl::true_
          , ::boost::mpl::false_
        >::type
#endif
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/tti/detail/dnullptr.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/add_pointer.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T1, typename T2>
    class is_value_type_of_begin
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
                    BOOST_TYPEOF_KEYWORD(
                        *::boost::concept::traits::declref<B>().begin()
                    )
#else
                    decltype(*::boost::concept::traits::declref<B>().begin())
#endif
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef typename ::boost::mpl::if_c<
            sizeof(
                ::boost::concept::traits::_detail::metafunction
                ::is_value_type_of_begin<T1,T2>
                ::_check<T2>(BOOST_TTI_DETAIL_NULLPTR)
            ) == sizeof(::boost::type_traits::yes_type)
          , ::boost::concept::traits::_detail::metafunction
            ::is_value_type_of_begin_impl<T1,T2>
          , ::boost::mpl::false_
        >::type type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type_fwd.hpp>
#include <boost/concept/traits/introspection/nested_type/has_value_type.hpp>
#include <boost/concept/traits/introspection/member_function/has_begin.hpp>
#include <boost/mpl/eval_if.hpp>

//[reference__is_value_type_of
namespace boost { namespace concept { namespace traits {

    template <typename T1, typename T2>
    struct is_value_type_of
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            typename _mpl_eval_if_<
                _bct_has_value_type_<T2>
              , _mpl_if_<
                    _std_is_same_<
                        typename _bct_value_type_of_<T2>::type
                      , T1
                    >
                  , _mpl_true_
                  , _mpl_false_
                >
              , _mpl_false_
            >::type
          , _mpl_true_
          , _mpl_eval_if_<
                _bct_has_begin_<T2>
              , _mpl_eval_if_<
                    _is_valid_expression_(*_declref_<T2>().begin())
                  , _mpl_if_<
                        _std_is_same_<
                            typename _std_remove_const_<
                                typename _std_remove_reference_<
                                    _decltype_(*_declref_<T2>().begin())
                                >::type
                            >::type
                          , T1
                        >
                      , _mpl_true_
                      , _mpl_false_
                    >
                  , _mpl_false_
                >
              , _mpl_false_
            >
        >::type
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::mpl::eval_if<
            typename ::boost::mpl::if_<
                ::boost::concept::traits::has_value_type<T2>
              , ::boost::concept::traits::_detail::metafunction
                ::is_value_type_of_value<T1,T2>
              , ::boost::mpl::false_
            >::type
          , ::boost::mpl::true_
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_begin<T2>
              , ::boost::concept::traits::_detail::metafunction
                ::is_value_type_of_begin<T1,T2>
              , ::boost::mpl::false_
            >
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

