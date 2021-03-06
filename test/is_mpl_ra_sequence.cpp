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

#include <boost/concept/traits/query/is_mpl_sequence.hpp>
#include <boost/concept/traits/query/is_mpl_ra_iterator.hpp>
#include <boost/mpl/placeholders.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>

//[test__is_mpl_random_access_sequence__containers
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            std::vector<int>
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            std::vector<int> const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            std::deque<int>
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            std::deque<int> const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            std::list<int>
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            std::list<int> const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            std::set<int>
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            std::set<int> const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            std::map<int,int>
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            std::map<int,int> const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            std::multiset<int>
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            std::multiset<int> const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            std::multimap<int,int>
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            std::multimap<int,int> const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
}
//]

#include <boost/fusion/mpl.hpp>
#include <boost/fusion/support/pair.hpp>
#include <boost/fusion/adapted/std_pair.hpp>

//[test__is_mpl_random_access_sequence__pairs
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            std::pair<int,int>
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            std::pair<int,int> const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::container::map<int,int>::value_type
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::container::map<int,int>::value_type const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::container::multimap<int,int>::value_type
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::container::multimap<int,int>::value_type const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::pair<int,int>
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::pair<int,int> const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
}
//]

#if !defined BOOST_MSVC
#include <boost/fusion/adapted/boost_array.hpp>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::array<int,1>
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::array<int,1> const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
}
#endif

#include <boost/mpl/vector.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/list_c.hpp>
#include <boost/mpl/set.hpp>
#include <boost/mpl/set_c.hpp>
#include <boost/mpl/map.hpp>
#include <boost/mpl/range_c.hpp>

//[test__is_mpl_random_access_sequence__mpl_sequences
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::vector_c<char,' '>
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::vector_c<char,' '> const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::deque<long double>
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::deque<long double> const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::list_c<char,' '>
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::list_c<char,' '> const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::set_c<char,' '>
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::set_c<char,' '> const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::map<boost::mpl::pair<short,long> >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::map<boost::mpl::pair<short,long> > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::range_c<int,0,1>
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::range_c<int,0,1> const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
}
//]

#include <boost/mpl/begin_end.hpp>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::begin<boost::mpl::vector_c<char,' '> >::type
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::begin<boost::mpl::vector_c<char,' '> const>::type
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::begin<boost::mpl::deque<long double> >::type
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::begin<boost::mpl::deque<long double> const>::type
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::begin<boost::mpl::list_c<char,' '> >::type
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::begin<boost::mpl::list_c<char,' '> const>::type
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::begin<boost::mpl::set_c<char,' '> >::type
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::begin<boost::mpl::set_c<char,' '> const>::type
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::begin<
                boost::mpl::map<boost::mpl::pair<short,long> >
            >::type
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::begin<
                boost::mpl::map<boost::mpl::pair<short,long> > const
            >::type
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::begin<boost::mpl::range_c<int,0,1> >::type
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::begin<boost::mpl::range_c<int,0,1> const>::type
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
}

#include <boost/mpl/empty_sequence.hpp>
#include <boost/mpl/single_view.hpp>
#include <boost/mpl/filter_view.hpp>
#include <boost/mpl/iterator_range.hpp>
#include <boost/mpl/joint_view.hpp>
#include <boost/mpl/zip_view.hpp>
#include <boost/mpl/transform_view.hpp>
#include <boost/mpl/negate.hpp>

//[test__is_mpl_random_access_sequence__mpl_sequence_views
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::empty_sequence
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::empty_sequence const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::single_view<int>
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::single_view<int> const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::filter_view<
                boost::mpl::vector<
                    void
                  , boost::mpl::begin<boost::mpl::empty_sequence>::type
                >
              , boost::concept::traits::is_mpl_random_access_iterator<
                    boost::mpl::_
                >
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::filter_view<
                boost::mpl::vector<
                    void
                  , boost::mpl::begin<boost::mpl::empty_sequence>::type
                >
              , boost::concept::traits::is_mpl_random_access_iterator<
                    boost::mpl::_
                >
            > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::iterator_range<
                boost::mpl::begin<boost::mpl::vector<int> >::type
              , boost::mpl::end<boost::mpl::vector<int> >::type
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::iterator_range<
                boost::mpl::begin<boost::mpl::vector<int> >::type
              , boost::mpl::end<boost::mpl::vector<int> >::type
            > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::iterator_range<
                boost::mpl::begin<boost::mpl::deque<int> >::type
              , boost::mpl::end<boost::mpl::deque<int> >::type
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::iterator_range<
                boost::mpl::begin<boost::mpl::deque<int> >::type
              , boost::mpl::end<boost::mpl::deque<int> >::type
            > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::iterator_range<
                boost::mpl::begin<boost::mpl::list<int> >::type
              , boost::mpl::end<boost::mpl::list<int> >::type
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::iterator_range<
                boost::mpl::begin<boost::mpl::list<int> >::type
              , boost::mpl::end<boost::mpl::list<int> >::type
            > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::iterator_range<
                boost::mpl::begin<boost::mpl::set<int> >::type
              , boost::mpl::end<boost::mpl::set<int> >::type
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::iterator_range<
                boost::mpl::begin<boost::mpl::set<int> >::type
              , boost::mpl::end<boost::mpl::set<int> >::type
            > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::iterator_range<
                boost::mpl::begin<
                    boost::mpl::map<boost::mpl::pair<short,long> >
                >::type
              , boost::mpl::end<
                    boost::mpl::map<boost::mpl::pair<short,long> >
                >::type
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::iterator_range<
                boost::mpl::begin<
                    boost::mpl::map<boost::mpl::pair<short,long> >
                >::type
              , boost::mpl::end<
                    boost::mpl::map<boost::mpl::pair<short,long> >
                >::type
            > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::joint_view<
                boost::mpl::vector<int>
              , boost::mpl::deque<int>
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::joint_view<
                boost::mpl::vector<int>
              , boost::mpl::deque<int>
            > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::zip_view<
                boost::mpl::deque<
                    boost::mpl::vector_c<char,' ','\n','\t'>
                  , boost::mpl::list_c<short,0,1,5>
                  , boost::mpl::set_c<long,4,3,2>
                >
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::zip_view<
                boost::mpl::deque<
                    boost::mpl::vector_c<char,' ','\n','\t'>
                  , boost::mpl::list_c<short,0,1,5>
                  , boost::mpl::set_c<long,4,3,2>
                >
            > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::transform_view<
                boost::mpl::vector_c<int,6,7,5>
              , boost::mpl::negate<boost::mpl::_>
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::mpl::transform_view<
                boost::mpl::vector_c<int,6,7,5>
              , boost::mpl::negate<boost::mpl::_>
            > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
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
#include <boost/ref.hpp>

//[test__is_mpl_random_access_sequence__heterogeneous_containers
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::tuples::tuple<char&,short&,int&>
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::tuples::tuple<char&,short&,int&> const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::vector<int>
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::vector<int> const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::deque<int>
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::deque<int> const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::nil
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::nil const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::cons<char,boost::fusion::cons<short> >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::cons<char,boost::fusion::cons<short> > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::list<int>
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::list<int> const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::set<int>
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::set<int> const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::map<
                boost::fusion::pair<int,boost::reference_wrapper<int> >
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::map<boost::fusion::pair<int,int&> > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
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

//[test__is_mpl_random_access_sequence__heterogeneous_views
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::single_view<int>
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::single_view<int> const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::filter_view<
                boost::fusion::vector<
                    void*
                  , boost::mpl::begin<boost::mpl::empty_sequence>::type
                >
              , boost::concept::traits::is_mpl_random_access_iterator<
                    boost::mpl::_
                >
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::filter_view<
                boost::fusion::vector<
                    void*
                  , boost::mpl::begin<boost::mpl::empty_sequence>::type
                >
              , boost::concept::traits::is_mpl_random_access_iterator<
                    boost::mpl::_
                >
            > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::filter_view<
                boost::fusion::set<
                    void*
                  , boost::mpl::begin<boost::mpl::empty_sequence>::type
                >
              , boost::concept::traits::is_mpl_random_access_iterator<
                    boost::mpl::_
                >
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::filter_view<
                boost::fusion::set<
                    void*
                  , boost::mpl::begin<boost::mpl::empty_sequence>::type
                >
              , boost::concept::traits::is_mpl_random_access_iterator<
                    boost::mpl::_
                >
            > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::iterator_range<
                boost::fusion::result_of::begin<
                    boost::fusion::vector<int>
                >::type
              , boost::fusion::result_of::end<
                    boost::fusion::vector<int>
                >::type
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::iterator_range<
                boost::fusion::result_of::begin<
                    boost::fusion::vector<int> const
                >::type
              , boost::fusion::result_of::end<
                    boost::fusion::vector<int> const
                >::type
            > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::iterator_range<
                boost::fusion::result_of::begin<
                    boost::fusion::deque<int>
                >::type
              , boost::fusion::result_of::end<
                    boost::fusion::deque<int>
                >::type
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::iterator_range<
                boost::fusion::result_of::begin<
                    boost::fusion::deque<int> const
                >::type
              , boost::fusion::result_of::end<
                    boost::fusion::deque<int> const
                >::type
            > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::iterator_range<
                boost::fusion::result_of::begin<
                    boost::fusion::list<int>
                >::type
              , boost::fusion::result_of::end<
                    boost::fusion::list<int>
                >::type
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::iterator_range<
                boost::fusion::result_of::begin<
                    boost::fusion::list<int> const
                >::type
              , boost::fusion::result_of::end<
                    boost::fusion::list<int> const
                >::type
            > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::iterator_range<
                boost::fusion::result_of::begin<
                    boost::fusion::set<int>
                >::type
              , boost::fusion::result_of::end<boost::fusion::set<int> >::type
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::iterator_range<
                boost::fusion::result_of::begin<
                    boost::fusion::set<int> const
                >::type
              , boost::fusion::result_of::end<
                    boost::fusion::set<int> const
                >::type
            > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::iterator_range<
                boost::fusion::result_of::begin<
                    boost::fusion::map<boost::fusion::pair<int,int> >
                >::type
              , boost::fusion::result_of::end<
                    boost::fusion::map<boost::fusion::pair<int,int> >
                >::type
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::iterator_range<
                boost::fusion::result_of::begin<
                    boost::fusion::map<boost::fusion::pair<int,int> > const
                >::type
              , boost::fusion::result_of::end<
                    boost::fusion::map<boost::fusion::pair<int,int> > const
                >::type
            > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::joint_view<
                boost::fusion::vector<int>
              , boost::fusion::deque<int>
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::joint_view<
                boost::fusion::vector<int>
              , boost::fusion::deque<int>
            > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::zip_view<
                boost::fusion::vector<
                    boost::fusion::vector<int>&
                  , boost::fusion::single_view<int>&
                >
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::zip_view<
                boost::fusion::vector<
                    boost::fusion::vector<int>&
                  , boost::fusion::single_view<int>&
                >
            > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::zip_view<
                boost::fusion::vector<
                    boost::fusion::vector<int>&
                  , boost::fusion::deque<int>&
                >
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::zip_view<
                boost::fusion::vector<
                    boost::fusion::vector<int>&
                  , boost::fusion::deque<int>&
                >
            > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::zip_view<
                boost::fusion::vector<
                    boost::fusion::vector<int>&
                  , boost::fusion::list<int>&
                >
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::zip_view<
                boost::fusion::vector<
                    boost::fusion::vector<int>&
                  , boost::fusion::list<int>&
                >
            > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::transform_view<
                boost::fusion::vector<int>
              , boost::fusion::single_view<int>
              , std::plus<int>
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::transform_view<
                boost::fusion::vector<int>
              , boost::fusion::single_view<int>
              , std::plus<int>
            > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::transform_view<
                boost::fusion::vector<int>
              , boost::fusion::deque<int>
              , std::plus<int>
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::transform_view<
                boost::fusion::vector<int>
              , boost::fusion::deque<int>
              , std::plus<int>
            > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::transform_view<
                boost::fusion::vector<int>
              , boost::fusion::list<int>
              , std::plus<int>
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::transform_view<
                boost::fusion::vector<int>
              , boost::fusion::list<int>
              , std::plus<int>
            > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::reverse_view<boost::fusion::deque<int> >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::reverse_view<boost::fusion::deque<int> > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::reverse_view<
                boost::fusion::map<
                    boost::fusion::pair<int,boost::reference_wrapper<int> >
                >
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::reverse_view<
                boost::fusion::map<boost::fusion::pair<int,int&> >
            > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::nview<
                boost::fusion::list<char,short,long>
              , boost::mpl::vector_c<int,2,0,1>
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::nview<
                boost::fusion::list<char,short,long>
              , boost::mpl::vector_c<int,2,0,1>
            > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::repetitive_view<
                boost::fusion::vector<char,short,int>
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::repetitive_view<
                boost::fusion::vector<char,short,int>
            > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::flatten_view<
                boost::fusion::vector<
                    char
                  , boost::fusion::list<short,int>
                  , long
                >
            >
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_sequence<
            boost::fusion::flatten_view<
                boost::fusion::vector<
                    char
                  , boost::fusion::list<short,int>
                  , long
                >
            > const
          , boost::concept::traits::is_mpl_random_access_iterator<
                boost::mpl::_
            >
        >
    ));
}
//]

