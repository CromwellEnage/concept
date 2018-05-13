// Copyright (C) 2013-2015 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <utility>
#include <boost/config.hpp>

#if !defined BOOST_NO_CXX11_HDR_TUPLE
#include <tuple>
#endif

#if !defined BOOST_NO_CXX11_HDR_ARRAY
#include <array>
#endif

#if !defined BOOST_NO_CXX11_HDR_FORWARD_LIST
#include <forward_list>
#endif

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_SET
#include <unordered_set>
#endif

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_MAP
#include <unordered_map>
#endif

#if defined BOOST_HAS_TR1_ARRAY
#include <boost/tr1/array.hpp>
#endif

#if defined BOOST_HAS_TR1_UNORDERED_SET
#include <boost/tr1/unordered_set.hpp>
#endif

#if defined BOOST_HAS_TR1_UNORDERED_MAP
#include <boost/tr1/unordered_map.hpp>
#endif

#if !defined BOOST_MSVC
#include <boost/array.hpp>
#include <boost/ptr_container/ptr_array.hpp>
#endif

#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/ptr_container/ptr_deque.hpp>
#include <boost/ptr_container/ptr_circular_buffer.hpp>
#include <boost/ptr_container/ptr_list.hpp>
#include <boost/ptr_container/ptr_set.hpp>
#include <boost/ptr_container/ptr_map.hpp>
#include <boost/ptr_container/ptr_unordered_set.hpp>
#include <boost/ptr_container/ptr_unordered_map.hpp>

#include <boost/container/string.hpp>
#include <boost/container/vector.hpp>
#include <boost/container/stable_vector.hpp>
#include <boost/container/static_vector.hpp>
#include <boost/container/deque.hpp>
#include <boost/container/list.hpp>
#include <boost/container/slist.hpp>
#include <boost/container/set.hpp>
#include <boost/container/map.hpp>
#include <boost/container/flat_set.hpp>
#include <boost/container/flat_map.hpp>
#include <boost/unordered_set.hpp>
#include <boost/unordered_map.hpp>

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/sequenced_index.hpp>
#include <boost/multi_index/random_access_index.hpp>
#include <boost/multi_index/key_extractors.hpp>

#include <boost/bimap.hpp>
#include <boost/bimap/set_of.hpp>
#include <boost/bimap/multiset_of.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include <boost/bimap/unordered_multiset_of.hpp>
#include <boost/bimap/list_of.hpp>
#include <boost/bimap/vector_of.hpp>

#include <boost/heap/priority_queue.hpp>
#include <boost/heap/binomial_heap.hpp>
#include <boost/heap/d_ary_heap.hpp>
#include <boost/heap/fibonacci_heap.hpp>
#include <boost/heap/pairing_heap.hpp>
#include <boost/heap/skew_heap.hpp>

#include <boost/circular_buffer.hpp>
#include <boost/multi_array.hpp>

#include <boost/concept/traits/introspection/member_function/has_emplace_back.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

//[test__has_emplace_back__std_containers
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::has_emplace_back<std::vector<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::vector<int> const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::has_emplace_back<std::vector<int>,int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::vector<int> const,int>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::has_emplace_back<std::deque<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::deque<int> const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::has_emplace_back<std::deque<int>,int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::deque<int> const,int>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::has_emplace_back<std::list<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::list<int> const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::has_emplace_back<std::list<int>,int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::list<int> const,int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::set<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::set<int> const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::set<int>,int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::set<int> const,int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::map<int,int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::map<int,int> const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::map<int,int>,int,int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::map<int,int> const,int,int>
    ));
//<-
#if !defined BOOST_NO_CXX11_HDR_TUPLE
//->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            std::map<int,int>
          , std::piecewise_construct_t
          , std::tuple<BOOST_RV_REF(int)>
          , std::tuple<BOOST_RV_REF(int)>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            std::map<int,int> const
          , std::piecewise_construct_t
          , std::tuple<BOOST_RV_REF(int)>
          , std::tuple<BOOST_RV_REF(int)>
        >
    ));
//<-
#endif
//->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::multiset<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::multiset<int> const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::multiset<int>,int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::multiset<int> const,int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::multimap<int,int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::multimap<int,int> const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::multimap<int,int>,int,int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            std::multimap<int,int> const
          , int
          , int
        >
    ));
//<-
#if !defined BOOST_NO_CXX11_HDR_TUPLE
//->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            std::multimap<int,int>
          , std::piecewise_construct_t
          , std::tuple<BOOST_RV_REF(int)>
          , std::tuple<BOOST_RV_REF(int)>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            std::multimap<int,int> const
          , std::piecewise_construct_t
          , std::tuple<BOOST_RV_REF(int)>
          , std::tuple<BOOST_RV_REF(int)>
        >
    ));
//<-
#endif
//->
}
//]

MPL_TEST_CASE()
{
#if !defined BOOST_NO_CXX11_HDR_ARRAY
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::array<int,1>,int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            std::array<int,1>
          , std::array<int,1>::const_iterator
          , int
        >
    ));
#endif

#if !defined BOOST_NO_CXX11_HDR_FORWARD_LIST
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::forward_list<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::forward_list<int> const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::forward_list<int>,int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::forward_list<int> const,int>
    ));
#endif

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_SET
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::unordered_set<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::unordered_set<int> const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::unordered_set<int>,int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::unordered_set<int> const,int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::unordered_multiset<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::unordered_multiset<int> const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::unordered_multiset<int>,int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            std::unordered_multiset<int> const
          , int
        >
    ));
#endif

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_MAP
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::unordered_map<int,int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::unordered_map<int,int> const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::unordered_map<int,int>,int,int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            std::unordered_map<int,int> const
          , int
          , int
        >
    ));
#if !defined BOOST_NO_CXX11_HDR_TUPLE
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            std::unordered_map<int,int>
          , std::piecewise_construct_t
          , std::tuple<BOOST_RV_REF(int)>
          , std::tuple<BOOST_RV_REF(int)>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            std::unordered_map<int,int> const
          , std::piecewise_construct_t
          , std::tuple<BOOST_RV_REF(int)>
          , std::tuple<BOOST_RV_REF(int)>
        >
    ));
#endif
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            std::unordered_multimap<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            std::unordered_multimap<int,int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            std::unordered_multimap<int,int>
          , int
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            std::unordered_multimap<int,int> const
          , int
          , int
        >
    ));
#if !defined BOOST_NO_CXX11_HDR_TUPLE
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            std::unordered_multimap<int,int>
          , std::piecewise_construct_t
          , std::tuple<BOOST_RV_REF(int)>
          , std::tuple<BOOST_RV_REF(int)>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            std::unordered_multimap<int,int> const
          , std::piecewise_construct_t
          , std::tuple<BOOST_RV_REF(int)>
          , std::tuple<BOOST_RV_REF(int)>
        >
    ));
#endif
#endif  // BOOST_NO_CXX11_HDR_UNORDERED_MAP

#if defined BOOST_HAS_TR1_ARRAY
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::tr1::array<int,1> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::tr1::array<int,1> const>
    ));
#endif

#if defined BOOST_HAS_TR1_UNORDERED_SET
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<std::tr1::unordered_set<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            std::tr1::unordered_set<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            std::tr1::unordered_multiset<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            std::tr1::unordered_multiset<int> const
        >
    ));
#endif

#if defined BOOST_HAS_TR1_UNORDERED_MAP
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            std::tr1::unordered_map<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            std::tr1::unordered_map<int,int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            std::tr1::unordered_multimap<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            std::tr1::unordered_multimap<int,int> const
        >
    ));
#endif

#if !defined BOOST_MSVC
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::array<int,1> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::array<int,1> const>
    ));
#endif
}

//[test__has_emplace_back__ptr_containers
MPL_TEST_CASE()
{
//<-
#if !defined BOOST_MSVC
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::ptr_array<int,1> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::ptr_array<int,1> const>
    ));
#endif

//->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::ptr_vector<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::ptr_vector<int> const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::ptr_deque<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::ptr_deque<int> const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::ptr_circular_buffer<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::ptr_circular_buffer<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::ptr_list<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::ptr_list<int> const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::ptr_set<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::ptr_set<int> const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::ptr_map<int,int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::ptr_map<int,int> const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::ptr_multiset<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::ptr_multiset<int> const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::ptr_multimap<int,int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::ptr_multimap<int,int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::ptr_unordered_set<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::ptr_unordered_set<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::ptr_unordered_map<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::ptr_unordered_map<int,int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::ptr_unordered_multiset<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::ptr_unordered_multiset<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::ptr_unordered_multimap<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::ptr_unordered_multimap<int,int> const
        >
    ));
}
//]

//[test__has_emplace_back__boost_containers
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::container::string>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::container::string const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::has_emplace_back<boost::container::vector<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::container::vector<int> const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::has_emplace_back<boost::container::vector<int>,int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::vector<int> const
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::has_emplace_back<
            boost::container::stable_vector<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::stable_vector<int> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::has_emplace_back<
            boost::container::stable_vector<int>
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::stable_vector<int> const
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::has_emplace_back<
            boost::container::static_vector<int,1>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::static_vector<int,1> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::has_emplace_back<
            boost::container::static_vector<int,1>
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::static_vector<int,1> const
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::has_emplace_back<boost::container::deque<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::container::deque<int> const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::has_emplace_back<boost::container::deque<int>,int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::deque<int> const
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::has_emplace_back<boost::container::list<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::container::list<int> const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::has_emplace_back<boost::container::list<int>,int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::list<int> const
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::container::slist<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::container::slist<int> const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::container::slist<int>,int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::slist<int> const
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::container::set<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::container::set<int> const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<boost::container::set<int>,int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::set<int> const
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::map<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::map<int,int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::map<int,int>
          , int
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::map<int,int> const
          , int
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::multiset<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::multiset<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::multiset<int>
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::multiset<int> const
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::multimap<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::multimap<int,int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::multimap<int,int>
          , int
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::multimap<int,int> const
          , int
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::flat_set<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::flat_set<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::flat_set<int>
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::flat_set<int> const
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::flat_map<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::flat_map<int,int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::flat_map<int,int>
          , int
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::flat_map<int,int> const
          , int
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::flat_multiset<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::flat_multiset<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::flat_multiset<int>
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::flat_multiset<int> const
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::flat_multimap<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::flat_multimap<int,int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::flat_multimap<int,int>
          , int
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::container::flat_multimap<int,int> const
          , int
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::unordered::unordered_set<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::unordered::unordered_set<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::unordered::unordered_set<int>
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::unordered::unordered_set<int> const
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::unordered::unordered_map<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::unordered::unordered_map<int,int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::unordered::unordered_map<int,int>
          , int
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::unordered::unordered_map<int,int> const
          , int
          , int
        >
    ));
//<-
#if !defined BOOST_NO_CXX11_HDR_TUPLE
//->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::unordered::unordered_map<int,int>
          , boost::unordered::piecewise_construct_t
          , std::tuple<BOOST_RV_REF(int)>
          , std::tuple<BOOST_RV_REF(int)>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::unordered::unordered_map<int,int> const
          , boost::unordered::piecewise_construct_t
          , std::tuple<BOOST_RV_REF(int)>
          , std::tuple<BOOST_RV_REF(int)>
        >
    ));
//<-
#endif
//->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::unordered::unordered_multiset<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::unordered::unordered_multiset<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::unordered::unordered_multiset<int>
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::unordered::unordered_multiset<int> const
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::unordered::unordered_multimap<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::unordered::unordered_multimap<int,int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::unordered::unordered_multimap<int,int>
          , int
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::unordered::unordered_multimap<int,int> const
          , int
          , int
        >
    ));
//<-
#if !defined BOOST_NO_CXX11_HDR_TUPLE
//->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::unordered::unordered_multimap<int,int>
          , boost::unordered::piecewise_construct_t
          , std::tuple<BOOST_RV_REF(int)>
          , std::tuple<BOOST_RV_REF(int)>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::unordered::unordered_multimap<int,int> const
          , boost::unordered::piecewise_construct_t
          , std::tuple<BOOST_RV_REF(int)>
          , std::tuple<BOOST_RV_REF(int)>
        >
    ));
//<-
#endif
//->
}
//]

//[test__has_emplace_back__multi_index_containers
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

    BOOST_MPL_ASSERT((
        boost::concept::traits::has_emplace_back<
            boost::multi_index::nth_index<your_multi_index_ds,0>::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::multi_index::nth_index<your_multi_index_ds,0>::type const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::has_emplace_back<
            boost::multi_index::nth_index<your_multi_index_ds,1>::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::multi_index::nth_index<your_multi_index_ds,1>::type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::multi_index::nth_index<your_multi_index_ds,2>::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::multi_index::nth_index<your_multi_index_ds,2>::type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::multi_index::nth_index<your_multi_index_ds,3>::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::multi_index::nth_index<your_multi_index_ds,3>::type const
        >
    ));
}
//]

//[test__has_emplace_back__bimap_views
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::set_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::set_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::set_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::set_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::set_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::set_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::multiset_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::multiset_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::list_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::list_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::list_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::list_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::list_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::list_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::vector_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::vector_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::set_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::set_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::set_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::set_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::set_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::set_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::multiset_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::multiset_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::list_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::list_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::list_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::list_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::list_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::list_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::vector_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::vector_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            >::left_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            >::left_map const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            >::right_map
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            >::right_map const
        >
    ));
}
//]

//[test__has_emplace_back__boost_heaps
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::heap::priority_queue<int>
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::heap::priority_queue<int> const
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::heap::binomial_heap<int>
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::heap::binomial_heap<int> const
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::heap::d_ary_heap<int,boost::heap::arity<1> >
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::heap::d_ary_heap<int,boost::heap::arity<1> > const
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::heap::d_ary_heap<
                int
              , boost::heap::mutable_<true>
              , boost::heap::arity<1>
            >
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::heap::d_ary_heap<
                int
              , boost::heap::mutable_<true>
              , boost::heap::arity<1>
            > const
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::heap::fibonacci_heap<int>
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::heap::fibonacci_heap<int> const
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::heap::pairing_heap<int>
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::heap::pairing_heap<int> const
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::heap::skew_heap<int>
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::heap::skew_heap<int> const
          , int
        >
    ));
}
//]

//[test__has_emplace_back__misc_containers
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::circular_buffer<int>
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::circular_buffer<int> const
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::multi_array<float,1>
          , float
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::multi_array<float,1> const
          , float
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::multi_array<float,2>
          , float
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::has_emplace_back<
            boost::multi_array<float,2> const
          , float
        >
    ));
}
//]

