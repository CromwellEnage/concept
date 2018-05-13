// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_VERTEX_MUTABLE_GRAPH_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_VERTEX_MUTABLE_GRAPH_HPP

#include <boost/utility/declref.hpp>
#include <boost/graph/detail/graph_traits.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_same.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_vertex_mutable_graph_ops_impl
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
      : ::boost::is_same<
#else
      : ::boost::mpl::if_<
            ::std::is_same<
#endif
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF_KEYWORD(add_vertex(::boost::declref<T>()))
#else
                decltype(add_vertex(::boost::declref<T>()))
#endif
              , typename ::boost::graph::graph_traits<T>::vertex_descriptor
            >
#if !defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
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

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_pointer.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    class has_vertex_mutable_graph_ops
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check_add(
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::add_pointer<
#else
                typename ::std::add_pointer<
#endif
#if defined BOOST_NO_CXX11_DECLTYPE
                    BOOST_TYPEOF_KEYWORD(add_vertex(::boost::declref<B>()))
#else
                    decltype(add_vertex(::boost::declref<B>()))
#endif
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check_add(...);

        template <typename B>
        static ::boost::type_traits::yes_type
            _check_clear(
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
                        clear_vertex(
                            ::boost::declref<
                                typename ::boost::graph::graph_traits<B>
                                ::vertex_descriptor
                            >()
                          , ::boost::declref<B>()
                        )
                    ))
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check_clear(...);

        template <typename B>
        static ::boost::type_traits::yes_type
            _check_remove(
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
                        remove_vertex(
                            ::boost::declref<
                                typename ::boost::graph::graph_traits<B>
                                ::vertex_descriptor
                            >()
                          , ::boost::declref<B>()
                        )
                    ))
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check_remove(...);

     public:
        typedef typename ::boost::mpl::if_c<
                    (
                        sizeof(
                            ::boost::concept::traits::_detail::metafunction
                            ::has_vertex_mutable_graph_ops<T>
                            ::_check_add<T>(BOOST_TTI_DETAIL_NULLPTR)
                        ) == sizeof(::boost::type_traits::yes_type)
                    ) && (
                        sizeof(
                            ::boost::concept::traits::_detail::metafunction
                            ::has_vertex_mutable_graph_ops<T>
                            ::_check_clear<T>(BOOST_TTI_DETAIL_NULLPTR)
                        ) == sizeof(::boost::type_traits::yes_type)
                    ) && (
                        sizeof(
                            ::boost::concept::traits::_detail::metafunction
                            ::has_vertex_mutable_graph_ops<T>
                            ::_check_remove<T>(BOOST_TTI_DETAIL_NULLPTR)
                        ) == sizeof(::boost::type_traits::yes_type)
                    )
                  , ::boost::concept::traits::_detail::metafunction
                    ::has_vertex_mutable_graph_ops_impl<T>
                  , ::boost::mpl::false_
                >::type
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_graph.hpp>
#include <boost/mpl/eval_if.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_const.hpp>
#endif

//[reference__is_vertex_mutable_graph
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_vertex_mutable_graph
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _std_is_const_<T>
          , _mpl_false_
          , _mpl_eval_if_<
                _bct_is_graph_<T>
              , _mpl_eval_if_<
                    _mpl_and_<
                        _is_valid_expression_(
                            _decltype_(add_vertex(_declref_<T>()))
                        )
                      , _is_valid_expression_(
                            _decltype_(
                                clear_vertex(
                                    _declref_<
                                        typename _graph_traits_<T>
                                        ::vertex_descriptor
                                    >()
                                  , _declref_<T>()
                                )
                            )
                        )
                      , _is_valid_expression_(
                            _decltype_(
                                remove_vertex(
                                    _declref_<
                                        typename _graph_traits_<T>
                                        ::vertex_descriptor
                                    >()
                                  , _declref_<T>()
                                )
                            )
                        )
                    >
                  , _mpl_if_<
                        _std_is_same_<
                            _decltype_(add_vertex(_declref_<T>()))
                          , typename _graph_traits_<T>::vertex_descriptor
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
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::mpl::eval_if<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            ::boost::is_const<T>
#else
            ::std::is_const<T>
#endif
          , ::boost::mpl::false_
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::is_graph<T>
              , ::boost::concept::traits::_detail::metafunction
                ::has_vertex_mutable_graph_ops<T>
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

