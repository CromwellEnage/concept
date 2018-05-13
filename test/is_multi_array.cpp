// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// Include all necessary Boost.Container header files
// before including any header file that uses Boost.MPL
// to avoid ambiguity errors between size_t and boost::mpl::size_t.
#include <boost/container/string.hpp>
#include <boost/container/vector.hpp>
#include <boost/container/stable_vector.hpp>
#include <boost/container/static_vector.hpp>
#include <boost/container/small_vector.hpp>
#include <boost/container/deque.hpp>
#include <boost/container/list.hpp>
#include <boost/container/slist.hpp>
#include <boost/container/set.hpp>
#include <boost/container/map.hpp>
#include <boost/container/flat_set.hpp>
#include <boost/container/flat_map.hpp>

// Include these header files before any header file that uses Boost.MPL
// to avoid ambiguity errors between size_t and boost::mpl::size_t.
#include <boost/numeric/ublas/storage.hpp>
#include <boost/numeric/ublas/storage_sparse.hpp>

// Include all necessary Boost.Heap header files
// before including any header file that uses Boost.MPL
// to avoid ambiguity errors between size_t and boost::mpl::size_t.
#include <boost/heap/priority_queue.hpp>
#include <boost/heap/binomial_heap.hpp>
#include <boost/heap/d_ary_heap.hpp>
#include <boost/heap/fibonacci_heap.hpp>
#include <boost/heap/pairing_heap.hpp>
#include <boost/heap/skew_heap.hpp>

#include <boost/config.hpp>

#if !defined BOOST_MSVC
// Include this header file before any header file that uses Boost.MPL
// to avoid ambiguity errors between size_t and boost::mpl::size_t.
#include <boost/ptr_container/ptr_array.hpp>
#endif

#include <boost/concept/traits/query/is_multi_array.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>

//[test__is_multi_array__std_containers
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::vector<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::vector<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::deque<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::deque<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::list<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::list<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::set<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::set<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::map<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::map<int,int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::multiset<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::multiset<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::multimap<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::multimap<int,int> const
        >
    ));
}
//]

#include <boost/unordered_set.hpp>
#include <boost/unordered_map.hpp>

//[test__is_multi_array__boost_containers
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::string
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::string const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::vector<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::vector<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::stable_vector<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::stable_vector<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::static_vector<int,1>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::static_vector<int,1> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::small_vector<int,1>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::small_vector<int,1> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::deque<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::deque<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::list<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::list<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::slist<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::slist<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::set<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::set<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::map<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::map<int,int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::multiset<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::multiset<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::multimap<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::multimap<int,int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::flat_set<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::flat_set<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::flat_map<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::flat_map<int,int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::flat_multiset<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::flat_multiset<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::flat_multimap<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::container::flat_multimap<int,int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::unordered::unordered_set<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::unordered::unordered_set<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::unordered::unordered_map<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::unordered::unordered_map<int,int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::unordered::unordered_multiset<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::unordered::unordered_multiset<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::unordered::unordered_multimap<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::unordered::unordered_multimap<int,int> const
        >
    ));
}
//]

#if !defined BOOST_NO_CXX11_HDR_ARRAY
#include <array>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::array<int,1>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::array<int,1> const
        >
    ));
}
#endif

#if !defined BOOST_NO_CXX11_HDR_FORWARD_LIST
#include <forward_list>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::forward_list<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::forward_list<int> const
        >
    ));
}
#endif

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_SET
#include <unordered_set>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::unordered_set<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::unordered_set<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::unordered_multiset<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::unordered_multiset<int> const
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_UNORDERED_SET

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_MAP
#include <unordered_map>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::unordered_map<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::unordered_map<int,int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::unordered_multimap<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::unordered_multimap<int,int> const
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_UNORDERED_MAP

#if defined BOOST_HAS_TR1_ARRAY
#include <boost/tr1/array.hpp>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::tr1::array<int,1>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::tr1::array<int,1> const
        >
    ));
}
#endif

#if defined BOOST_HAS_TR1_UNORDERED_SET
#include <boost/tr1/unordered_set.hpp>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::tr1::unordered_set<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::tr1::unordered_set<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::tr1::unordered_multiset<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::tr1::unordered_multiset<int> const
        >
    ));
}
#endif  // BOOST_HAS_TR1_UNORDERED_SET

#if defined BOOST_HAS_TR1_UNORDERED_MAP
#include <boost/tr1/unordered_map.hpp>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::tr1::unordered_map<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::tr1::unordered_map<int,int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::tr1::unordered_multimap<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            std::tr1::unordered_multimap<int,int> const
        >
    ));
}
#endif  // BOOST_HAS_TR1_UNORDERED_MAP

#if !defined BOOST_MSVC
#include <boost/array.hpp>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::array<int,1>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::array<int,1> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::ptr_array<int,1>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::ptr_array<int,1> const
        >
    ));
}
#endif  // !defined BOOST_MSVC

#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/ptr_container/ptr_deque.hpp>
#include <boost/ptr_container/ptr_circular_buffer.hpp>
#include <boost/ptr_container/ptr_list.hpp>
#include <boost/ptr_container/ptr_set.hpp>
#include <boost/ptr_container/ptr_map.hpp>
#include <boost/ptr_container/ptr_unordered_set.hpp>
#include <boost/ptr_container/ptr_unordered_map.hpp>

//[test__is_multi_array__ptr_containers
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::ptr_vector<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::ptr_vector<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::ptr_deque<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::ptr_deque<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::ptr_circular_buffer<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::ptr_circular_buffer<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::ptr_list<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::ptr_list<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::ptr_set<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::ptr_set<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::ptr_map<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::ptr_map<int,int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::ptr_multiset<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::ptr_multiset<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::ptr_multimap<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::ptr_multimap<int,int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::ptr_unordered_set<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::ptr_unordered_set<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::ptr_unordered_map<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::ptr_unordered_map<int,int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::ptr_unordered_multiset<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::ptr_unordered_multiset<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::ptr_unordered_multimap<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::ptr_unordered_multimap<int,int> const
        >
    ));
}
//]

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/sequenced_index.hpp>
#include <boost/multi_index/random_access_index.hpp>
#include <boost/multi_index/key_extractors.hpp>

//[test__is_multi_array__multi_index_containers
MPL_TEST_CASE()
{
    typedef boost::multi_index::multi_index_container<
                boost::container::string
              , boost::multi_index::indexed_by<
                    boost::multi_index::sequenced<>
                  , boost::multi_index::random_access<>
                  , boost::multi_index::ordered_non_unique<
                        boost::multi_index::identity<boost::container::string>
                    >
                  , boost::multi_index::hashed_unique<
                        boost::multi_index::identity<boost::container::string>
                    >
                >
            >
            your_multi_index_ds;

    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::multi_index::nth_index<your_multi_index_ds,0>::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::multi_index::nth_index<your_multi_index_ds,0>::type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::multi_index::nth_index<your_multi_index_ds,1>::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::multi_index::nth_index<your_multi_index_ds,1>::type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::multi_index::nth_index<your_multi_index_ds,2>::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::multi_index::nth_index<your_multi_index_ds,2>::type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::multi_index::nth_index<your_multi_index_ds,3>::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::multi_index::nth_index<your_multi_index_ds,3>::type const
        >
    ));
}
//]

#include <boost/bimap.hpp>
#include <boost/bimap/set_of.hpp>
#include <boost/bimap/multiset_of.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include <boost/bimap/unordered_multiset_of.hpp>
#include <boost/bimap/list_of.hpp>
#include <boost/bimap/vector_of.hpp>

//[test__is_multi_array__bimap_views
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::set_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::set_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::set_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::set_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::set_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::set_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::multiset_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::multiset_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::list_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::list_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::list_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::list_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::list_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::list_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::vector_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::vector_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::set_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::set_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::set_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::set_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::set_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::set_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::multiset_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::multiset_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::list_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::list_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::list_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::list_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::list_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::list_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::vector_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::vector_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            >::right_map const
        >
    ));
}
//]

#include <boost/numeric/ublas/vector.hpp>

//[test__is_multi_array__ublas
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::numeric::ublas::vector<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::numeric::ublas::vector<double> const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::numeric::ublas::c_vector<double,1>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::numeric::ublas::c_vector<double,1> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::numeric::ublas::fixed_vector<double,1>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::numeric::ublas::fixed_vector<double,1> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::numeric::ublas::bounded_vector<double,1>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::numeric::ublas::bounded_vector<double,1> const
        >
    ));
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::numeric::ublas::unbounded_array<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::numeric::ublas::unbounded_array<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::numeric::ublas::bounded_array<double,1>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::numeric::ublas::bounded_array<double,1> const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::numeric::ublas::map_std<int,double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::numeric::ublas::map_std<int,double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::numeric::ublas::map_array<int,double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::numeric::ublas::map_array<int,double> const
        >
    ));
    //->
}
//]

//[test__is_multi_array__boost_heaps
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::heap::priority_queue<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::heap::priority_queue<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::heap::binomial_heap<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::heap::binomial_heap<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::heap::d_ary_heap<int,boost::heap::arity<1> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::heap::d_ary_heap<int,boost::heap::arity<1> > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::heap::d_ary_heap<
                int
              , boost::heap::mutable_<true>
              , boost::heap::arity<1>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::heap::d_ary_heap<
                int
              , boost::heap::mutable_<true>
              , boost::heap::arity<1>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::heap::fibonacci_heap<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::heap::fibonacci_heap<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::heap::pairing_heap<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::heap::pairing_heap<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::heap::skew_heap<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::heap::skew_heap<int> const
        >
    ));
}
//]

#include <boost/circular_buffer.hpp>
#include <boost/multi_array.hpp>

//[test__is_multi_array__misc_containers
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::circular_buffer<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multi_array<
            boost::circular_buffer<int> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multi_array<
            boost::multi_array<float,1>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multi_array<
            boost::multi_array<float,1> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multi_array<
            boost::multi_array<float,2>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multi_array<
            boost::multi_array<float,2> const
        >
    ));
}
//]
