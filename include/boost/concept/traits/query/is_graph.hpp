// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_GRAPH_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_GRAPH_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_null_vertex.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_edge_descriptor.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_directed_category.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_edge_parallel_category.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_traversal_category.hpp>
#include <boost/graph/detail/graph_traits.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

//[reference__is_graph
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_graph
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_has_null_vertex_<
                _graph_traits_<T>
            >
          , _mpl_eval_if_<
                _bct_has_edge_descriptor_<
                    _graph_traits_<T>
                >
              , _mpl_eval_if_<
                    _bct_has_directed_category_<
                        _graph_traits_<T>
                    >
                  , _mpl_if_<
                        _bct_has_edge_parallel_category_<
                            _graph_traits_<T>
                        >
                      , _bct_has_traversal_category_<
                            _graph_traits_<T>
                        >
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
            ::boost::concept::traits::has_null_vertex<
                ::boost::graph::graph_traits<T>
            >
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_edge_descriptor<
                    ::boost::graph::graph_traits<T>
                >
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_directed_category<
                        ::boost::graph::graph_traits<T>
                    >
                  , ::boost::mpl::if_<
                        ::boost::concept::traits::has_edge_parallel_category<
                            ::boost::graph::graph_traits<T>
                        >
                      , ::boost::concept::traits::has_traversal_category<
                            ::boost::graph::graph_traits<T>
                        >
                      , ::boost::mpl::false_
                    >
                  , ::boost::mpl::false_
                >
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

