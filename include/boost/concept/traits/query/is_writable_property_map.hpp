// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_WRITABLE_PROPERTY_MAP_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_WRITABLE_PROPERTY_MAP_HPP

#include <boost/utility/declref.hpp>
#include <boost/tti/detail/dnullptr.hpp>
#include <boost/property_map/property_map.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
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

    template <typename T, typename Key>
    class has_writable_property_map_ops
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
                    BOOST_TYPEOF_KEYWORD
#else
                    decltype
#endif
                    ((
                        put(
                            ::boost::declref<B>()
                          , ::boost::declcref<Key>()
                          , ::boost::declref<
                                typename ::boost::property_traits<
                                    T
                                >::value_type
                            >()
                        )
                    ))
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef ::boost::mpl::bool_<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_writable_property_map_ops<T,Key>
                        ::_check<T>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                >
                type;
    };

    template <typename T>
    struct is_writable_property_map_with_void_input_key
      : ::boost::concept::traits::_detail::metafunction
        ::has_writable_property_map_ops<
            T
          , typename ::boost::property_traits<T>::key_type
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type/has_key_type.hpp>
#include <boost/concept/policy/use_default.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_convertible.hpp>
#include <boost/type_traits/is_same.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Key>
    struct has_writable_property_map_category
      : ::boost::mpl::eval_if<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            ::boost::is_convertible<
#else
            ::std::is_convertible<
#endif
                typename ::boost::property_traits<T>::category
              , ::boost::writable_property_map_tag
            >
          , ::boost::mpl::eval_if<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                ::boost::is_same<Key,::boost::concept::policy::use_default>
#else
                ::std::is_same<Key,::boost::concept::policy::use_default>
#endif
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_key_type<
                        ::boost::property_traits<T>
                    >
                  , ::boost::concept::traits::_detail::metafunction
                    ::is_writable_property_map_with_void_input_key<T>
                  , ::boost::mpl::false_
                >
              , ::boost::concept::traits::_detail::metafunction
                ::has_writable_property_map_ops<T,Key>
            >
          , ::boost::mpl::false_
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type/has_value_type.hpp>
#include <boost/concept/traits/introspection/nested_type/has_category.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_const.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Key>
    struct is_writable_property_map_impl
      : ::boost::mpl::eval_if<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            ::boost::is_const<T>
#else
            ::std::is_const<T>
#endif
          , ::boost::mpl::false_
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_value_type<
                    ::boost::property_traits<T>
                >
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_category<
                        ::boost::property_traits<T>
                    >
                  , ::boost::concept::traits::_detail::metafunction
                    ::has_writable_property_map_category<T,Key>
                  , ::boost::mpl::false_
                >
              , ::boost::mpl::false_
            >
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#endif

//[reference__is_writable_property_map
namespace boost { namespace concept { namespace traits {

    template <typename T, typename Key>
    struct is_writable_property_map
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
          _std_is_const_<T>
        , _mpl_false_
        , _mpl_eval_if_<
            _bct_has_value_type_<
              _property_traits_<typename _std_remove_const_<T>::type>
            >
          , _mpl_eval_if_<
              _bct_has_category_<
                _property_traits_<typename _std_remove_const_<T>::type>
              >
            , _mpl_eval_if_<
                _std_is_convertible_<
                  typename _property_traits_<
                    typename _std_remove_const_<T>::type
                  >::category
                , boost::writable_property_map_tag
                >
              , _mpl_eval_if_<
                  _std_is_same_<Key,boost::concept::policy::use_default>
                , _mpl_if_<
                    _bct_has_key_<
                      _property_traits_<
                        typename _std_remove_const_<T>::type
                      >
                    >
                  , _is_valid_expression_(
                      put(
                        _declref_<T>()
                      , _declcref_<
                          typename _property_traits_<
                            typename _std_remove_const_<T>::type
                          >::key_type
                        >()
                      , _declref<
                          typename _property_traits_<T>::value_type
                        >()
                      )
                    )
                  , _mpl_false_
                  >
                , _mpl_identity_<
                    _is_valid_expression_(
                      put(
                        _declref_<T>()
                      , _declcref_<
                          typename _std_remove_const_<
                            typename _std_remove_reference_<Key>::type
                          >::type
                        >()
                      , _declref<
                          typename _property_traits_<T>::value_type
                        >()
                      )
                    )
                  >
                >
              , _mpl_false_
              >
            , _mpl_false_
            >
          , _mpl_false_
          >
        >::type
//<-
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::concept::traits::_detail::metafunction
        ::is_writable_property_map_impl<
            T
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
          , typename ::boost::remove_const<
                typename ::boost::remove_reference<Key>::type
            >::type
#else
          , typename ::std::remove_const<
                typename ::std::remove_reference<Key>::type
            >::type
#endif
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

