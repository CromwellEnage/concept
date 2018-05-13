// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/traits/query/is_edge_mutable_graph.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/properties.hpp>

//[test__is_edge_mutable_graph__adjacency_list
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_edge_mutable_graph<
            boost::adjacency_list<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_edge_mutable_graph<
            boost::adjacency_list<boost::setS,boost::setS>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_edge_mutable_graph<
            boost::adjacency_list<
                boost::setS
              , boost::setS
              , boost::bidirectionalS
              , boost::property<boost::vertex_rank_t,int>
              , boost::property<boost::edge_weight_t,double>
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_edge_mutable_graph<
            boost::adjacency_list<
                boost::setS
              , boost::setS
              , boost::undirectedS
              , boost::property<boost::vertex_rank_t,int>
              , boost::property<boost::edge_weight_t,double>
            >
        >
    ));
}
//]

#if defined LIBS_CONCEPT_TEST_WITH_ADJACENCY_MATRIX

#include <boost/graph/adjacency_matrix.hpp>

//[test__is_edge_mutable_graph__adjacency_matrix
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_edge_mutable_graph<
            boost::adjacency_matrix<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_edge_mutable_graph<
            boost::adjacency_matrix<boost::bidirectionalS>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_edge_mutable_graph<
            boost::adjacency_matrix<boost::undirectedS>
        >
    ));
}
//]

#endif  // LIBS_CONCEPT_TEST_WITH_ADJACENCY_MATRIX

#include <boost/graph/grid_graph.hpp>
#include <boost/graph/edge_list.hpp>
#include <list>
#include <utility>

//[test__is_edge_mutable_graph__other
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_edge_mutable_graph<
            boost::grid_graph<5>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_edge_mutable_graph<
            boost::edge_list<std::list<std::pair<int,int> >::iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_edge_mutable_graph<
            boost::edge_list<
                std::pair<
                    boost::adjacency_list<>::vertex_descriptor
                  , boost::adjacency_list<>::vertex_descriptor
                >*
            >
        >
    ));
}
//]

