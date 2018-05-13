// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_EDGE_MUTABLE_GRAPH_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_EDGE_MUTABLE_GRAPH_HPP

#include <boost/concept/traits/query/is_boolean_expression.hpp>
#include <boost/graph/detail/graph_traits.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_same.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename AddResult>
    struct is_edge_addable_graph
      : ::boost::mpl::if_<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            ::boost::is_same<
#else
            ::std::is_same<
#endif
                typename AddResult::first_type
              , typename ::boost::graph::graph_traits<T>::edge_descriptor
            >
          , ::boost::concept::traits::is_boolean_expression<
                typename AddResult::second_type
            >
          , ::boost::mpl::false_
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query/is_runtime_pair.hpp>
#include <boost/utility/declref.hpp>
#include <boost/mpl/eval_if.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_edge_mutable_graph_ops_impl
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_runtime_pair<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF_KEYWORD
#else
                decltype
#endif
                ((
                    add_edge(
                        ::boost::declref<
                            typename ::boost::graph::graph_traits<T>
                            ::vertex_descriptor
                        >()
                      , ::boost::declref<
                            typename ::boost::graph::graph_traits<T>
                            ::vertex_descriptor
                        >()
                      , ::boost::declref<T>()
                    )
                ))
            >
          , ::boost::concept::traits::_detail::metafunction
            ::is_edge_addable_graph<
                T
#if defined BOOST_NO_CXX11_DECLTYPE
              , BOOST_TYPEOF_KEYWORD
#else
              , decltype
#endif
                ((
                    add_edge(
                        ::boost::declref<
                            typename ::boost::graph::graph_traits<T>
                            ::vertex_descriptor
                        >()
                      , ::boost::declref<
                            typename ::boost::graph::graph_traits<T>
                            ::vertex_descriptor
                        >()
                      , ::boost::declref<T>()
                    )
                ))
            >
          , ::boost::mpl::false_
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/tti/detail/dnullptr.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined BOOST_NO_CXX11_HDR_FUNCTIONAL
#include <boost/function.hpp>
#else
#include <functional>
#endif

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_pointer.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    class has_edge_mutable_graph_ops
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
                    BOOST_TYPEOF_KEYWORD
#else
                    decltype
#endif
                    ((
                        add_edge(
                            ::boost::declref<
                                typename ::boost::graph::graph_traits<B>
                                ::vertex_descriptor
                            >()
                          , ::boost::declref<
                                typename ::boost::graph::graph_traits<B>
                                ::vertex_descriptor
                            >()
                          , ::boost::declref<B>()
                        )
                    ))
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check_add(...);

        template <typename B>
        static ::boost::type_traits::yes_type
            _check_remove_uv(
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
                        remove_edge(
                            ::boost::declref<
                                typename ::boost::graph::graph_traits<B>
                                ::vertex_descriptor
                            >()
                          , ::boost::declref<
                                typename ::boost::graph::graph_traits<B>
                                ::vertex_descriptor
                            >()
                          , ::boost::declref<B>()
                        )
                    )
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check_remove_uv(...);

        template <typename B>
        static ::boost::type_traits::yes_type
            _check_remove_e(
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
                        remove_edge(
                            ::boost::declref<
                                typename ::boost::graph::graph_traits<B>
                                ::edge_descriptor
                            >()
                          , ::boost::declref<B>()
                        )
                    ))
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check_remove_e(...);

        template <typename B>
        static ::boost::type_traits::yes_type
            _check_remove_e_p(
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
                        remove_edge_if(
                            ::boost::declref<
                                typename ::boost::graph::graph_traits<B>
                                ::edge_descriptor
                            >()
                          , ::boost::declval<
#if defined BOOST_NO_CXX11_HDR_FUNCTIONAL
                                ::boost::function1<
                                    bool
                                  , typename ::boost::graph::graph_traits<B>
                                    ::edge_descriptor
                                >
#else
                                ::std::function<
                                    bool(
                                        typename ::boost::graph
                                        ::graph_traits<B>::edge_descriptor
                                    )
                                >
#endif
                            >()
                          , ::boost::declref<B>()
                        )
                    ))
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check_remove_e_p(...);

     public:
        typedef typename ::boost::mpl::if_c<
                    (
                        sizeof(
                            ::boost::concept::traits::_detail::metafunction
                            ::has_edge_mutable_graph_ops<T>
                            ::_check_add<T>(BOOST_TTI_DETAIL_NULLPTR)
                        ) == sizeof(::boost::type_traits::yes_type)
                    ) && (
                        sizeof(
                            ::boost::concept::traits::_detail::metafunction
                            ::has_edge_mutable_graph_ops<T>
                            ::_check_remove_uv<T>(BOOST_TTI_DETAIL_NULLPTR)
                        ) == sizeof(::boost::type_traits::yes_type)
                    ) && (
                        sizeof(
                            ::boost::concept::traits::_detail::metafunction
                            ::has_edge_mutable_graph_ops<T>
                            ::_check_remove_e<T>(BOOST_TTI_DETAIL_NULLPTR)
                        ) == sizeof(::boost::type_traits::yes_type)
                    )
                  , ::boost::concept::traits::_detail::metafunction
                    ::has_edge_mutable_graph_ops_impl<T>
                  , ::boost::mpl::false_
                >::type
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_graph.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_const.hpp>
#endif

//[reference__is_edge_mutable_graph
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_edge_mutable_graph
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
                            _decltype_(
                                add_edge(
                                    _declref_<
                                        typename _graph_traits_<T>
                                        ::vertex_descriptor
                                    >()
                                  , _declref_<
                                        typename _graph_traits_<T>
                                        ::vertex_descriptor
                                    >()
                                  , _declref_<T>()
                                )
                            )
                        )
                      , _is_valid_expression_(
                            _decltype_(
                                remove_edge(
                                    _declref_<
                                        typename _graph_traits_<T>
                                        ::vertex_descriptor
                                    >()
                                  , _declref_<
                                        typename _graph_traits_<T>
                                        ::vertex_descriptor
                                    >()
                                  , _declref_<T>()
                                )
                            )
                        )
                      , _is_valid_expression_(
                            _decltype_(
                                remove_edge(
                                    _declref_<
                                        typename _graph_traits_<T>
                                        ::edge_descriptor
                                    >()
                                  , _declref_<T>()
                                )
                            )
                        )
                      , _is_valid_expression_(
                            _decltype_(
                                remove_edge_if(
                                    _declref_<
                                        typename _graph_traits_<T>
                                        ::edge_descriptor
                                    >()
                                  , _declval_<
                                        _std_function_<
                                            bool(
                                                typename _graph_traits_<T>
                                                ::edge_descriptor
                                            )
                                        >
                                    >()
                                  , _declref_<T>()
                                )
                            )
                        )
                    >
                  , _mpl_eval_if_<
                        _bct_is_runtime_pair_<
                            _decltype_(
                                add_edge(
                                    _declref_<
                                        typename _graph_traits_<T>
                                        ::vertex_descriptor
                                    >()
                                  , _declref_<
                                        typename _graph_traits_<T>
                                        ::vertex_descriptor
                                    >()
                                  , _declref_<T>()
                                )
                            )
                        >
                      , _mpl_if_<
                            _std_is_same_<
                                typename _decltype_(
                                    add_edge(
                                        _declref_<
                                            typename _graph_traits_<T>
                                            ::vertex_descriptor
                                        >()
                                      , _declref_<
                                            typename _graph_traits_<T>
                                            ::vertex_descriptor
                                        >()
                                      , _declref_<T>()
                                    )
                                )::first_type
                              , typename _graph_traits_<T>::edge_descriptor
                            >
                          , _bct_is_boolean_expression_<
                                typename _decltype_(
                                    add_edge(
                                        _declref_<
                                            typename _graph_traits_<T>
                                            ::vertex_descriptor
                                        >()
                                      , _declref_<
                                            typename _graph_traits_<T>
                                            ::vertex_descriptor
                                        >()
                                      , _declref_<T>()
                                    )
                                )::second_type
                            >
                          , _mpl_false_
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
                ::has_edge_mutable_graph_ops<T>
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

