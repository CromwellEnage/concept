// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_LVALUE_PROPERTY_MAP_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_LVALUE_PROPERTY_MAP_HPP

#include <boost/utility/declref.hpp>
#include <boost/property_map/property_map.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_convertible.hpp>
#include <boost/type_traits/is_same.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Key>
    struct has_lvalue_property_map_ops_impl
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
      : ::boost::mpl::if_<
            ::boost::is_convertible<
#else
      : ::boost::mpl::eval_if<
            ::std::is_convertible<
#endif
                typename ::boost::property_traits<T>::category
              , ::boost::lvalue_property_map_tag
            >
#if defined BOOST_NO_CXX11_DECLTYPE
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
          , ::boost::is_convertible<
#else
          , ::boost::mpl::if_<
                ::std::is_convertible<
#endif
                    typename ::boost::property_traits<T>::reference
                  , BOOST_TYPEOF_KEYWORD
#else   // !defined BOOST_NO_CXX11_DECLTYPE
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
          , ::boost::is_same<
#else
          , ::boost::mpl::if_<
                ::std::is_same<
#endif
                    typename ::boost::property_traits<T>::reference
                  , decltype
#endif  // BOOST_NO_CXX11_DECLTYPE
                    (::boost::declref<T>()[::boost::declcref<Key>()])
#if !defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                >
              , ::boost::mpl::true_
              , ::boost::mpl::false_
#endif
            >
          , ::boost::mpl::false_
        >
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

    template <typename T, typename Key>
    class has_lvalue_property_map_ops
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
                    (::boost::declref<B>()[::boost::declcref<Key>()])
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef typename ::boost::mpl::eval_if_c<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_lvalue_property_map_ops<T,Key>
                        ::_check<T>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                  , ::boost::concept::traits::_detail::metafunction
                    ::has_lvalue_property_map_ops_impl<T,Key>
                  , ::boost::mpl::false_
                >::type
                type;
    };

    template <typename T>
    struct is_lvalue_property_map_with_void_input_key
      : ::boost::concept::traits::_detail::metafunction
        ::has_lvalue_property_map_ops<
            T
          , typename ::boost::property_traits<T>::key_type
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query/is_readable_property_map.hpp>
#include <boost/concept/traits/introspection/nested_type/has_key_type.hpp>
#include <boost/concept/policy/use_default.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/remove_const.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Key>
    class is_readonly_lvalue_property_map_impl
    {
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
        typedef typename ::boost::remove_const<T>::type _mutable_T;
#else
        typedef typename ::std::remove_const<T>::type _mutable_T;
#endif

     public:
        typedef typename ::boost::mpl::eval_if<
                    ::boost::concept::traits::is_readable_property_map<
                        _mutable_T
                      , Key
                    >
                  , ::boost::mpl::eval_if<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                        ::boost::is_same<
#else
                        ::std::is_same<
#endif
                            Key
                          , ::boost::concept::policy::use_default
                        >
                      , ::boost::mpl::eval_if<
                            ::boost::concept::traits::has_key_type<
                                ::boost::property_traits<_mutable_T>
                            >
                          , ::boost::concept::traits::_detail::metafunction
                            ::is_lvalue_property_map_with_void_input_key<
                                _mutable_T
                            >
                          , ::boost::mpl::false_
                        >
                      , ::boost::concept::traits::_detail::metafunction
                        ::has_lvalue_property_map_ops<_mutable_T,Key>
                    >
                  , ::boost::mpl::false_
                >::type
                type;
    };

    template <typename T, typename Key>
    struct has_mutable_lvalue_property_map_ops_impl
      : ::boost::mpl::eval_if<
#if defined BOOST_NO_CXX11_DECLTYPE
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            ::boost::is_convertible<
#else
            ::std::is_convertible<
#endif
                typename ::boost::property_traits<T>::reference
              , BOOST_TYPEOF_KEYWORD
#else  // !defined BOOST_NO_CXX11_DECLTYPE
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            ::boost::is_same<
#else
            ::std::is_same<
#endif
                typename ::boost::property_traits<T>::reference
              , decltype
#endif  // BOOST_NO_CXX11_DECLTYPE
                (
                    ::boost::declref<T>()[
                        ::boost::declcref<Key>()
                    ] = ::boost::declref<
                        typename ::boost::property_traits<T>::value_type
                    >()
                )
            >
          , ::boost::concept::traits::_detail::metafunction
            ::has_lvalue_property_map_ops<T,Key>
          , ::boost::mpl::false_
        >
    {
    };

    template <typename T, typename Key>
    class has_mutable_lvalue_property_map_ops
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
                    (
                        ::boost::declref<B>()[
                            ::boost::declcref<Key>()
                        ] = ::boost::declref<
                            typename ::boost::property_traits<B>::value_type
                        >()
                    )
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef typename ::boost::mpl::eval_if_c<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_mutable_lvalue_property_map_ops<T,Key>
                        ::_check<T>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                  , ::boost::concept::traits::_detail::metafunction
                    ::has_mutable_lvalue_property_map_ops_impl<T,Key>
                  , ::boost::mpl::false_
                >::type
                type;
    };

    template <typename T>
    struct is_mutable_lvalue_prop_map_with_void_input_key
      : ::boost::concept::traits::_detail::metafunction
        ::has_mutable_lvalue_property_map_ops<
            T
          , typename ::boost::property_traits<T>::key_type
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query/is_read_write_property_map.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Key>
    struct is_lvalue_property_map_impl
      : ::boost::mpl::eval_if<
            typename ::boost::mpl::eval_if<
                ::boost::concept::traits::is_read_write_property_map<T,Key>
              , ::boost::mpl::eval_if<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                    ::boost::is_void<Key>
#else
                    ::std::is_void<Key>
#endif
                  , ::boost::mpl::eval_if<
                        ::boost::concept::traits::has_key_type<
                            ::boost::property_traits<T>
                        >
                      , ::boost::concept::traits::_detail::metafunction
                        ::is_mutable_lvalue_prop_map_with_void_input_key<T>
                      , ::boost::mpl::false_
                    >
                  , ::boost::concept::traits::_detail::metafunction
                    ::has_mutable_lvalue_property_map_ops<T,Key>
                >
              , ::boost::mpl::false_
            >::type
          , ::boost::mpl::true_
          , ::boost::concept::traits::_detail::metafunction
            ::is_readonly_lvalue_property_map_impl<T,Key>
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits_fwd.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/remove_reference.hpp>
#endif

//[reference__is_lvalue_property_map
namespace boost { namespace concept { namespace traits {

    template <typename T, typename Key>
    struct is_lvalue_property_map
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
          typename _mpl_eval_if_<
            _bct_is_read_write_property_map_<T,Key>
          , _mpl_eval_if_<
              _std_is_convertible_<
                typename _property_traits_<T>::category
              , boost::lvalue_property_map_tag
              >
            , _mpl_eval_if_<
                _std_is_same_<Key,boost::concept::policy::use_default>
              , _mpl_eval_if_<
                  _bct_has_key_type_< _property_traits_<T> >
                , _mpl_eval_if_<
                    _mpl_and_<
                      _is_valid_expression_(
                        _declref_<T>()[
                          _declcref_<
                            typename _property_traits_<T>::key_type
                          >()
                        ]
                      )
                    , _is_valid_expression_(
                        _declref_<T>()[
                          _declcref_<
                            typename _property_traits_<T>::key_type
                          >()
                        ] = _declref_<
                          typename _property_traits_<T>::value_type
                        >()
                      )
                    >
                  , _mpl_if_<
                      _mpl_and_<
                        _std_is_same_<
                          typename _property_traits_<T>::reference
                        , _decltype_(
                            _declref_<T>()[
                              _declcref_<
                                typename _property_traits_<T>::key_type
                              >()
                            ]
                          )
                        >
                      , _std_is_same_<
                          typename _property_traits_<T>::reference
                        , _decltype_(
                            _declref_<T>()[
                              _declcref_<
                                typename _property_traits_<T>::key_type
                              >()
                            ] = _declref_<
                              typename _property_traits_<T>::value_type
                            >()
                          )
                        >
                      >
                    , _mpl_true_
                    , _mpl_false_
                    >
                  , _mpl_false_
                  >
                , _mpl_false_
                >
              , _mpl_eval_if_<
                  _mpl_and_<
                    _is_valid_expression_(
                      _declref_<T>()[
                        _declcref_<
                          typename _std_remove_const_<
                            typename _std_remove_reference_<Key>::type
                          >::type
                        >()
                      ]
                    )
                  , _is_valid_expression_(
                      _declref_<T>()[
                        _declcref_<
                          typename _std_remove_const_<
                            typename _std_remove_reference_<Key>::type
                          >::type
                        >()
                      ] = _declref_<
                        typename _property_traits_<T>::value_type
                      >()
                    )
                  >
                , _mpl_if_<
                    _mpl_and_<
                      _std_is_same_<
                        typename _property_traits_<T>::reference
                      , _decltype_(
                          _declref_<T>()[
                            _declcref_<
                              typename _std_remove_const_<
                                typename _std_remove_reference_<Key>::type
                              >::type
                            >()
                          ]
                        )
                      >
                    , _std_is_same_<
                        typename _property_traits_<T>::reference
                      , _decltype_(
                          _declref_<T>()[
                            _declcref_<
                              typename _std_remove_const_<
                                typename _std_remove_reference_<Key>::type
                              >::type
                            >()
                          ] = _declref_<
                            typename _property_traits_<T>::value_type
                          >()
                        )
                      >
                    >
                  , _mpl_true_
                  , _mpl_false_
                  >
                , _mpl_false_
                >
              >
            , _mpl_false_
            >
          , _mpl_false_
          >::type
        , _mpl_true_
        , _mpl_eval_if_<
            _bct_is_readable_property_map_<T,Key>
          , _mpl_eval_if_<
              _std_is_convertible_<
                typename _property_traits_<
                  typename _std_remove_const_<T>::type
                >::category
              , boost::lvalue_property_map_tag
              >
            , _mpl_eval_if_<
                _std_is_same_<Key,boost::concept::policy::use_default>
              , _mpl_eval_if_<
                  _bct_has_key_type_<
                    _property_traits_<
                      typename _std_remove_const_<T>::type
                    >
                  >
                , _mpl_eval_if_<
                    _is_valid_expression_(
                      _declref_<
                        typename _std_remove_const_<T>::type
                      >()[
                        _declcref_<
                          typename _property_traits_<
                            typename _std_remove_const_<T>::type
                          >::key_type
                        >()
                      ]
                    )
                  , _mpl_if_<
                      _std_is_same_<
                        typename _property_traits_<
                          typename _std_remove_const_<T>::type
                        >::reference
                      , _decltype_(
                          _declref_<
                            typename _std_remove_const_<T>::type
                          >()[
                            _declcref_<
                              typename _property_traits_<
                                typename _std_remove_const_<T>::type
                              >::key_type
                            >()
                          ]
                        )
                      >
                    , _mpl_true_
                    , _mpl_false_
                    >
                  , _mpl_false_
                  >
                , _mpl_false_
                >
              , _mpl_eval_if_<
                  _is_valid_expression_(
                    _declref_<
                      typename _std_remove_const_<T>::type
                    >()[
                      _declcref_<
                        typename _std_remove_const_<
                          typename _std_remove_reference_<Key>::type
                        >::type
                      >()
                    ]
                  )
                , _mpl_if_<
                    _std_is_same_<
                      typename _property_traits_<
                        typename _std_remove_const_<T>::type
                      >::reference
                    , _decltype_(
                        _declref_<
                          typename _std_remove_const_<T>::type
                        >()[
                          _declcref_<
                            typename _std_remove_const_<
                              typename _std_remove_reference_<Key>::type
                            >::type
                          >()
                        ]
                      )
                    >
                  , _mpl_true_
                  , _mpl_false_
                  >
                , _mpl_false_
                >
              >
            , _mpl_false_
            >
          , _mpl_false_
          >
        >::type
//<-
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::concept::traits::_detail::metafunction
        ::is_lvalue_property_map_impl<
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

