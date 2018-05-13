// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// Include all necessary Boost.Container header files
// before including any header file that uses Boost.MPL
// to avoid ambiguity errors between size_t and boost::mpl::size_t.
#include <boost/container/map.hpp>
#include <boost/config.hpp>

#if !defined BOOST_MSVC
// Include this header file before any header file that uses Boost.MPL
// to avoid ambiguity errors between size_t and boost::mpl::size_t.
#include <boost/array.hpp>
#endif

#include <boost/concept/traits/query/is_fusion_bidir_iterator.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>

//[test__is_fusion_bidirectional_iterator__container_iterators
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            std::vector<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            std::vector<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            std::deque<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            std::deque<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            std::list<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            std::list<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            std::set<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            std::set<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            std::map<int,int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            std::map<int,int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            std::multiset<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            std::multiset<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            std::multimap<int,int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            std::multimap<int,int>::const_iterator
        >
    ));
}
//]

#include <boost/fusion/sequence/intrinsic/begin.hpp>
#include <boost/fusion/sequence/intrinsic/end.hpp>
#include <boost/fusion/adapted/std_pair.hpp>

//[test__is_fusion_bidirectional_iterator__pair_iterators
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<std::pair<int,int> >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<std::pair<int,int> const>::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::container::map<int,int>::value_type
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::container::map<int,int>::value_type const
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::container::multimap<int,int>::value_type
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::container::multimap<int,int>::value_type const
            >::type
        >
    ));
}
//]

#if !defined BOOST_MSVC
#include <boost/fusion/adapted/boost_array.hpp>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<boost::array<int,1> >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<boost::array<int,1> const>::type
        >
    ));
}
#endif

#include <boost/fusion/adapted/mpl.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/list_c.hpp>
#include <boost/mpl/set.hpp>
#include <boost/mpl/set_c.hpp>
#include <boost/mpl/map.hpp>
#include <boost/mpl/range_c.hpp>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::mpl::vector_c<char,' '>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::mpl::vector_c<char,' '> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::mpl::deque<long double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::mpl::deque<long double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::mpl::list_c<char,' '>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::mpl::list_c<char,' '> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::mpl::set_c<char,' '>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::mpl::set_c<char,' '> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::mpl::map<boost::mpl::pair<short,long> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::mpl::map<boost::mpl::pair<short,long> > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::mpl::range_c<int,0,1>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::mpl::range_c<int,0,1> const
        >
    ));
}

//[test__is_fusion_bidirectional_iterator__mpl_sequence_iterators
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::vector_c<char,' '>
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::vector_c<char,' '> const
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::deque<long double>
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::deque<long double> const
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::list_c<char,' '>
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::list_c<char,' '> const
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::set_c<char,' '>
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::set_c<char,' '> const
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::map<boost::mpl::pair<short,long> >
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::map<boost::mpl::pair<short,long> > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::range_c<int,0,1>
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::range_c<int,0,1> const
            >::type
        >
    ));
}
//]

#include <boost/mpl/empty_sequence.hpp>
#include <boost/mpl/single_view.hpp>
#include <boost/mpl/filter_view.hpp>
#include <boost/mpl/iterator_range.hpp>
#include <boost/mpl/joint_view.hpp>
#include <boost/mpl/zip_view.hpp>
#include <boost/mpl/transform_view.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/negate.hpp>

//[test__is_fusion_bidirectional_iterator__mpl_sequence_view_iterators
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<boost::mpl::empty_sequence>::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::empty_sequence const
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::single_view<int>
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::single_view<int> const
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::filter_view<
                    boost::mpl::vector<void,boost::mpl::empty_sequence>
                  , boost::concept::traits::is_fusion_bidirectional_iterator<
                        boost::mpl::_
                    >
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::filter_view<
                    boost::mpl::vector<void,boost::mpl::empty_sequence const>
                  , boost::concept::traits::is_fusion_bidirectional_iterator<
                        boost::mpl::_
                    >
                > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::iterator_range<
                    boost::mpl::begin<boost::mpl::vector<int> >::type
                  , boost::mpl::end<boost::mpl::vector<int> >::type
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::iterator_range<
                    boost::mpl::begin<boost::mpl::vector<int> >::type
                  , boost::mpl::end<boost::mpl::vector<int> >::type
                > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::iterator_range<
                    boost::mpl::begin<boost::mpl::deque<int> >::type
                  , boost::mpl::end<boost::mpl::deque<int> >::type
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::iterator_range<
                    boost::mpl::begin<boost::mpl::deque<int> >::type
                  , boost::mpl::end<boost::mpl::deque<int> >::type
                > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::iterator_range<
                    boost::mpl::begin<boost::mpl::list<int> >::type
                  , boost::mpl::end<boost::mpl::list<int> >::type
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::iterator_range<
                    boost::mpl::begin<boost::mpl::list<int> >::type
                  , boost::mpl::end<boost::mpl::list<int> >::type
                > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::iterator_range<
                    boost::mpl::begin<boost::mpl::set<int> >::type
                  , boost::mpl::end<boost::mpl::set<int> >::type
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::iterator_range<
                    boost::mpl::begin<boost::mpl::set<int> >::type
                  , boost::mpl::end<boost::mpl::set<int> >::type
                > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::iterator_range<
                    boost::mpl::begin<
                        boost::mpl::map<boost::mpl::pair<short,long> >
                    >::type
                  , boost::mpl::end<
                        boost::mpl::map<boost::mpl::pair<short,long> >
                    >::type
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::iterator_range<
                    boost::mpl::begin<
                        boost::mpl::map<boost::mpl::pair<short,long> >
                    >::type
                  , boost::mpl::end<
                        boost::mpl::map<boost::mpl::pair<short,long> >
                    >::type
                > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::joint_view<
                    boost::mpl::vector<int>
                  , boost::mpl::deque<int>
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::joint_view<
                    boost::mpl::vector<int>
                  , boost::mpl::deque<int>
                > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::zip_view<
                    boost::mpl::deque<
                        boost::mpl::vector_c<char,' '>
                      , boost::mpl::list_c<short,0,1>
                      , boost::mpl::set_c<long,4,3,2>
                    >
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::zip_view<
                    boost::mpl::deque<
                        boost::mpl::vector_c<char,' '>
                      , boost::mpl::list_c<short,0,1>
                      , boost::mpl::set_c<long,4,3,2>
                    >
                > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::transform_view<
                    boost::mpl::vector_c<int,6,7,5>
                  , boost::mpl::negate<boost::mpl::_>
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::mpl::transform_view<
                    boost::mpl::vector_c<int,6,7,5>
                  , boost::mpl::negate<boost::mpl::_>
                > const
            >::type
        >
    ));
}
//]

#include <boost/fusion/container/vector.hpp>
#include <boost/fusion/container/deque.hpp>
#include <boost/fusion/container/list.hpp>
#include <boost/fusion/container/set.hpp>
#include <boost/fusion/container/map.hpp>
#include <boost/fusion/adapted/boost_tuple.hpp>
#include <boost/fusion/support/pair.hpp>
#include <boost/ref.hpp>

//[test__is_fusion_bidirectional_iterator__heterogeneous_container_iterators
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::tuples::tuple<char&,short&,int&>
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::tuples::tuple<char&,short&,int&> const
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<boost::fusion::vector<int> >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::vector<int> const
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<boost::fusion::deque<int> >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::deque<int> const
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<boost::fusion::nil>::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<boost::fusion::nil const>::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<boost::fusion::cons<int> >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::cons<int> const
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<boost::fusion::list<int> >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::list<int> const
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<boost::fusion::set<int> >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::set<int> const
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::map<
                    boost::fusion::pair<int,boost::reference_wrapper<int> >
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::map<boost::fusion::pair<int,int&> > const
            >::type
        >
    ));
}
//]

#include <boost/fusion/view/single_view.hpp>
#include <boost/fusion/view/filter_view.hpp>
#include <boost/fusion/view/iterator_range.hpp>
#include <boost/fusion/view/joint_view.hpp>
#include <boost/fusion/view/zip_view.hpp>
#include <boost/fusion/view/transform_view.hpp>
#include <boost/fusion/view/reverse_view.hpp>
#include <boost/fusion/view/nview.hpp>
#include <boost/fusion/view/repetitive_view.hpp>
#include <boost/fusion/view/flatten_view.hpp>
#include <functional>

//[test__is_fusion_bidirectional_iterator__heterogeneous_view_iterators
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::single_view<int>
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::single_view<int> const
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::filter_view<
                    boost::fusion::vector<
                        void*
                      , boost::fusion::result_of::begin<
                            boost::mpl::empty_sequence
                        >::type
                    >
                  , boost::concept::traits::is_fusion_bidirectional_iterator<
                        boost::mpl::_
                    >
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::filter_view<
                    boost::fusion::vector<
                        void*
                      , boost::fusion::result_of::begin<
                            boost::mpl::empty_sequence const
                        >::type
                    >
                  , boost::concept::traits::is_fusion_bidirectional_iterator<
                        boost::mpl::_
                    >
                > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::filter_view<
                    boost::fusion::set<
                        void*
                      , boost::fusion::result_of::begin<
                            boost::mpl::empty_sequence
                        >::type
                    >
                  , boost::concept::traits::is_fusion_bidirectional_iterator<
                        boost::mpl::_
                    >
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::filter_view<
                    boost::fusion::set<
                        void*
                      , boost::fusion::result_of::begin<
                            boost::mpl::empty_sequence const
                        >::type
                    >
                  , boost::concept::traits::is_fusion_bidirectional_iterator<
                        boost::mpl::_
                    >
                > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::iterator_range<
                    boost::fusion::result_of::begin<
                        boost::fusion::vector<int>
                    >::type
                  , boost::fusion::result_of::end<
                        boost::fusion::vector<int>
                    >::type
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::iterator_range<
                    boost::fusion::result_of::begin<
                        boost::fusion::vector<int> const
                    >::type
                  , boost::fusion::result_of::end<
                        boost::fusion::vector<int> const
                    >::type
                > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::iterator_range<
                    boost::fusion::result_of::begin<
                        boost::fusion::deque<int>
                    >::type
                  , boost::fusion::result_of::end<
                        boost::fusion::deque<int>
                    >::type
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::iterator_range<
                    boost::fusion::result_of::begin<
                        boost::fusion::deque<int> const
                    >::type
                  , boost::fusion::result_of::end<
                        boost::fusion::deque<int> const
                    >::type
                > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::iterator_range<
                    boost::fusion::result_of::begin<
                        boost::fusion::list<int>
                    >::type
                  , boost::fusion::result_of::end<
                        boost::fusion::list<int>
                    >::type
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::iterator_range<
                    boost::fusion::result_of::begin<
                        boost::fusion::list<int> const
                    >::type
                  , boost::fusion::result_of::end<
                        boost::fusion::list<int> const
                    >::type
                > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::iterator_range<
                    boost::fusion::result_of::begin<
                        boost::fusion::set<int>
                    >::type
                  , boost::fusion::result_of::end<
                        boost::fusion::set<int>
                    >::type
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::iterator_range<
                    boost::fusion::result_of::begin<
                        boost::fusion::set<int> const
                    >::type
                  , boost::fusion::result_of::end<
                        boost::fusion::set<int> const
                    >::type
                > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::iterator_range<
                    boost::fusion::result_of::begin<
                        boost::fusion::map<boost::fusion::pair<int,int> >
                    >::type
                  , boost::fusion::result_of::end<
                        boost::fusion::map<boost::fusion::pair<int,int> >
                    >::type
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::iterator_range<
                    boost::fusion::result_of::begin<
                        boost::fusion::map<
                            boost::fusion::pair<int,int>
                        > const
                    >::type
                  , boost::fusion::result_of::end<
                        boost::fusion::map<
                            boost::fusion::pair<int,int>
                        > const
                    >::type
                > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::joint_view<
                    boost::fusion::vector<int>
                  , boost::fusion::deque<int>
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::joint_view<
                    boost::fusion::vector<int>
                  , boost::fusion::deque<int>
                > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::zip_view<
                    boost::fusion::vector<
                        boost::fusion::vector<int>&
                      , boost::fusion::single_view<int>&
                    >
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::zip_view<
                    boost::fusion::vector<
                        boost::fusion::vector<int>&
                      , boost::fusion::single_view<int>&
                    >
                > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::zip_view<
                    boost::fusion::vector<
                        boost::fusion::vector<int>&
                      , boost::fusion::deque<int>&
                    >
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::zip_view<
                    boost::fusion::vector<
                        boost::fusion::vector<int>&
                      , boost::fusion::deque<int>&
                    >
                > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::zip_view<
                    boost::fusion::vector<
                        boost::fusion::vector<int>&
                      , boost::fusion::list<int>&
                    >
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::zip_view<
                    boost::fusion::vector<
                        boost::fusion::vector<int>&
                      , boost::fusion::list<int>&
                    >
                > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::transform_view<
                    boost::fusion::vector<int>
                  , boost::fusion::single_view<int>
                  , std::plus<int>
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::transform_view<
                    boost::fusion::vector<int>
                  , boost::fusion::single_view<int>
                  , std::plus<int>
                > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::transform_view<
                    boost::fusion::vector<int>
                  , boost::fusion::deque<int>
                  , std::plus<int>
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::transform_view<
                    boost::fusion::vector<int>
                  , boost::fusion::deque<int>
                  , std::plus<int>
                > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::transform_view<
                    boost::fusion::vector<int>
                  , boost::fusion::list<int>
                  , std::plus<int>
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::transform_view<
                    boost::fusion::vector<int>
                  , boost::fusion::list<int>
                  , std::plus<int>
                > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::reverse_view<boost::fusion::deque<int> >
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::reverse_view<boost::fusion::deque<int> > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::reverse_view<
                    boost::fusion::map<
                        boost::fusion::pair<
                            int
                          , boost::reference_wrapper<int>
                        >
                    >
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::reverse_view<
                    boost::fusion::map<boost::fusion::pair<int,int&> >
                > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::nview<
                    boost::fusion::list<char,short,long>
                  , boost::mpl::vector_c<int,2,0,1>
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::nview<
                    boost::fusion::list<char,short,long>
                  , boost::mpl::vector_c<int,2,0,1>
               > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::repetitive_view<
                    boost::fusion::vector<char,short,int>
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::repetitive_view<
                    boost::fusion::vector<char,short,int>
                > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::flatten_view<
                    boost::fusion::vector<
                        char
                      , boost::fusion::list<short,int>
                      , long
                    >
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_fusion_bidirectional_iterator<
            boost::fusion::result_of::begin<
                boost::fusion::flatten_view<
                    boost::fusion::vector<
                        char
                      , boost::fusion::list<short,int>
                      , long
                    >
                > const
            >::type
        >
    ));
}
//]

