// Copyright (C) 2012-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GRAPH_DETAIL_GRAPH_TRAITS_HPP
#define BOOST_GRAPH_DETAIL_GRAPH_TRAITS_HPP

#include \
<boost/concept/traits/introspection/nested_type/has_vertex_descriptor.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_edge_descriptor.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_adjacency_iterator.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_out_edge_iterator.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_in_edge_iterator.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_vertex_iterator.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_edge_iterator.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_directed_category.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_edge_parallel_category.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_traversal_category.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_vertices_size_type.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_edges_size_type.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_degree_size_type.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_null_vertex.hpp>
#include <boost/concept/traits/trivial_access/vertex_descriptor_of.hpp>
#include <boost/concept/traits/trivial_access/edge_descriptor_of.hpp>
#include <boost/concept/traits/trivial_access/adjacency_iterator_of.hpp>
#include <boost/concept/traits/trivial_access/out_edge_iterator_of.hpp>
#include <boost/concept/traits/trivial_access/in_edge_iterator_of.hpp>
#include <boost/concept/traits/trivial_access/vertex_iterator_of.hpp>
#include <boost/concept/traits/trivial_access/edge_iterator_of.hpp>
#include <boost/concept/traits/trivial_access/vertices_size_type_of.hpp>
#include <boost/concept/traits/trivial_access/edges_size_type_of.hpp>
#include <boost/concept/traits/trivial_access/degree_size_type_of.hpp>
#include <boost/concept/traits/trivial_access/directed_category_of.hpp>
#include <boost/concept/traits/trivial_access/edge_parallel_category_of.hpp>
#include <boost/concept/traits/trivial_access/traversal_category_of.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace graph {

    template <
        typename T
      , typename EnableIf = ::boost::concept::traits::has_null_vertex<T>
    >
    struct graph_traits
    {
        typedef typename ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_vertex_descriptor<T>
                  , ::boost::concept::traits::vertex_descriptor_of<T>
                  , ::boost::mpl::identity<void>
                >::type
                vertex_descriptor;
        typedef typename ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_edge_descriptor<T>
                  , ::boost::concept::traits::edge_descriptor_of<T>
                  , ::boost::mpl::identity<void>
                >::type
                edge_descriptor;
        typedef typename ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_adjacency_iterator<T>
                  , ::boost::concept::traits::adjacency_iterator_of<T>
                  , ::boost::mpl::identity<void>
                >::type
                adjacency_iterator;
        typedef typename ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_out_edge_iterator<T>
                  , ::boost::concept::traits::out_edge_iterator_of<T>
                  , ::boost::mpl::identity<void>
                >::type
                out_edge_iterator;
        typedef typename ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_in_edge_iterator<T>
                  , ::boost::concept::traits::in_edge_iterator_of<T>
                  , ::boost::mpl::identity<void>
                >::type
                in_edge_iterator;
        typedef typename ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_vertex_iterator<T>
                  , ::boost::concept::traits::vertex_iterator_of<T>
                  , ::boost::mpl::identity<void>
                >::type
                vertex_iterator;
        typedef typename ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_edge_iterator<T>
                  , ::boost::concept::traits::edge_iterator_of<T>
                  , ::boost::mpl::identity<void>
                >::type
                edge_iterator;
        typedef typename ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_vertices_size_type<T>
                  , ::boost::concept::traits::vertices_size_type_of<T>
                  , ::boost::mpl::identity<void>
                >::type
                vertices_size_type;
        typedef typename ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_edges_size_type<T>
                  , ::boost::concept::traits::edges_size_type_of<T>
                  , ::boost::mpl::identity<void>
                >::type
                edges_size_type;
        typedef typename ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_degree_size_type<T>
                  , ::boost::concept::traits::degree_size_type_of<T>
                  , ::boost::mpl::identity<void>
                >::type
                degree_size_type;
        typedef typename ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_directed_category<T>
                  , ::boost::concept::traits::directed_category_of<T>
                  , ::boost::mpl::identity<void>
                >::type
                directed_category;
        typedef typename ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_edge_parallel_category<T>
                  , ::boost::concept::traits::edge_parallel_category_of<T>
                  , ::boost::mpl::identity<void>
                >::type
                edge_parallel_category;
        typedef typename ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_traversal_category<T>
                  , ::boost::concept::traits::traversal_category_of<T>
                  , ::boost::mpl::identity<void>
                >::type
                traversal_category;

        static inline vertex_descriptor null_vertex()
        {
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            typedef typename ::boost::remove_const<T>::type _mutable_T;
#else
            typedef typename ::std::remove_const<T>::type _mutable_T;
#endif
            return _mutable_T::null_vertex();
        }
    };
}}  // namespace boost::graph

#include <boost/graph/graph_traits.hpp>
#include <boost/mpl/bool.hpp>

namespace boost { namespace graph {

    template <typename T>
    struct graph_traits<T,::boost::mpl::false_>
      : public ::boost::graph_traits<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            typename ::boost::remove_const<T>::type
#else
            typename ::std::remove_const<T>::type
#endif
        >
    {
    };
}}  // namespace boost::graph

#endif  // include guard

