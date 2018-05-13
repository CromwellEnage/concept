// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_INCIDENCE_GRAPH_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_INCIDENCE_GRAPH_HPP

#include <boost/utility/declval.hpp>
#include <boost/graph/detail/graph_traits.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <utility>
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
    struct has_incidence_graph_ops_impl
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
      : ::boost::mpl::if_<
            ::boost::is_same<
#else
      : ::boost::mpl::eval_if<
            ::std::is_same<
#endif
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF_KEYWORD
#else
                decltype
#endif
                ((
                    out_edges(
                        ::boost::declval<
                            typename ::boost::graph::graph_traits<T>
                            ::vertex_descriptor const
                        >()
                      , ::boost::declval<T const>()
                    )
                ))
              , ::std::pair<
                    typename ::boost::graph::graph_traits<T>
                    ::out_edge_iterator
                  , typename ::boost::graph::graph_traits<T>
                    ::out_edge_iterator
                >
            >
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
          , ::boost::is_same<
#else
          , ::boost::mpl::if_<
                ::std::is_same<
#endif
#if defined BOOST_NO_CXX11_DECLTYPE
                    BOOST_TYPEOF_KEYWORD
#else
                    decltype
#endif
                    ((
                        out_degree(
                            ::boost::declval<
                                typename ::boost::graph::graph_traits<T>
                                ::vertex_descriptor const
                            >()
                          , ::boost::declval<T const>()
                        )
                    ))
                  , typename ::boost::graph::graph_traits<T>::degree_size_type
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

    template <typename T>
    class has_incidence_graph_ops
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check_range(
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
                        out_edges(
                            ::boost::declval<
                                typename ::boost::graph::graph_traits<B>
                                ::vertex_descriptor const
                            >()
                          , ::boost::declval<B const>()
                        )
                    ))
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check_range(...);

        template <typename B>
        static ::boost::type_traits::yes_type
            _check_count(
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
                        out_degree(
                            ::boost::declval<
                                typename ::boost::graph::graph_traits<B>
                                ::vertex_descriptor const
                            >()
                          , ::boost::declval<B const>()
                        )
                    ))
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check_count(...);

     public:
        typedef typename ::boost::mpl::eval_if_c<
                    (
                        sizeof(
                            ::boost::concept::traits::_detail::metafunction
                            ::has_incidence_graph_ops<T>
                            ::_check_range<T>(BOOST_TTI_DETAIL_NULLPTR)
                        ) == sizeof(::boost::type_traits::yes_type)
                    ) && (
                        sizeof(
                            ::boost::concept::traits::_detail::metafunction
                            ::has_incidence_graph_ops<T>
                            ::_check_count<T>(BOOST_TTI_DETAIL_NULLPTR)
                        ) == sizeof(::boost::type_traits::yes_type)
                    )
                  , ::boost::concept::traits::_detail::metafunction
                    ::has_incidence_graph_ops_impl<T>
                  , ::boost::mpl::false_
                >::type
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include \
<boost/concept/traits/introspection/nested_type/has_out_edge_iterator.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_degree_size_type.hpp>
#include <boost/concept/traits/introspection/free_function/has_source.hpp>
#include <boost/concept/traits/introspection/free_function/has_target.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/remove_const.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    class is_incidence_graph_impl
    {
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
        typedef typename ::boost::remove_const<T>::type _mutable_T;
#else
        typedef typename ::std::remove_const<T>::type _mutable_T;
#endif

     public:
        typedef typename ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_source<_mutable_T>
                  , ::boost::mpl::eval_if<
                        ::boost::concept::traits::has_target<_mutable_T>
                      , ::boost::mpl::eval_if<
                            ::boost::concept::traits::has_out_edge_iterator<
                                ::boost::graph::graph_traits<_mutable_T>
                            >
                          , ::boost::mpl::eval_if<
                                ::boost::concept::traits
                                ::has_degree_size_type<
                                    ::boost::graph::graph_traits<_mutable_T>
                                >
                              , ::boost::concept::traits
                                ::_detail::metafunction
                                ::has_incidence_graph_ops<_mutable_T>
                              , ::boost::mpl::false_
                            >
                          , ::boost::mpl::false_
                        >
                      , ::boost::mpl::false_
                    >
                  , ::boost::mpl::false_
                >::type
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_graph.hpp>

//[reference__is_incidence_graph
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_incidence_graph
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_is_graph_<T>
          , _mpl_eval_if_<
                _mpl_and_<
                    _bct_has_source_<
                        typename _std_remove_const_<T>::type
                    >
                  , _bct_has_target_<
                        typename _std_remove_const_<T>::type
                    >
                  , _bct_has_out_edge_iterator_<
                        _graph_traits_<
                            typename _std_remove_const_<T>::type
                        >
                    >
                  , _bct_has_degree_size_type_<
                        _graph_traits_<
                            typename _std_remove_const_<T>::type
                        >
                    >
                >
              , _mpl_eval_if_<
                    _mpl_and_<
                        _is_valid_expression_(
                            out_edges(
                                _declval_<
                                    typename _graph_traits_<
                                        typename _std_remove_const_<T>::type
                                    >::vertex_descriptor const
                                >()
                              , _declval_<
                                    typename _std_add_const_<T>::type
                                >()
                            )
                        )
                      , _is_valid_expression_(
                            out_degree(
                                _declval_<
                                    typename _graph_traits_<
                                        typename _std_remove_const_<T>::type
                                    >::vertex_descriptor const
                                >()
                              , _declval_<
                                    typename _std_add_const_<T>::type
                                >()
                            )
                        )
                    >
                  , _mpl_if_<
                        _mpl_and_<
                            _std_is_same_<
                                _decltype_(
                                    out_edges(
                                        _declval_<
                                            typename _graph_traits_<
                                                typename _std_remove_const_<
                                                    T
                                                >::type
                                            >::vertex_descriptor const
                                        >()
                                      , _declval_<
                                            typename _std_add_const_<T>::type
                                        >()
                                    )
                                )
                              , _std_pair_<
                                    typename _graph_traits_<
                                        typename _std_remove_const_<T>::type
                                    >::out_edge_iterator
                                  , typename _graph_traits_<
                                        typename _std_remove_const_<T>::type
                                    >::out_edge_iterator
                                >
                            >
                          , _std_is_same_<
                                _decltype_(
                                    out_degree(
                                        _declval_<
                                            typename _graph_traits_<
                                                typename _std_remove_const_<
                                                    T
                                                >::type
                                            >::vertex_descriptor const
                                        >()
                                      , _declval_<
                                            typename _std_add_const_<T>::type
                                        >()
                                    )
                                )
                              , typename _graph_traits_<
                                    typename _std_remove_const_<T>::type
                                >::degree_size_type
                            >
                        >
                      , _mpl_true_
                      , _mpl_false_
                    >
                  , _mpl_false_
                >
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_graph<T>
          , ::boost::concept::traits::_detail::metafunction
            ::is_incidence_graph_impl<T>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

