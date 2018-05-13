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
#include <boost/shared_container_iterator.hpp>
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

#include <boost/concept/traits/query/is_indexable_iterator.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

#include <boost/optional.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_array.hpp>
#include <boost/shared_array.hpp>
#include <boost/intrusive_ptr.hpp>
#include <boost/make_unique.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

//[test__is_indexable_iterator__dereferenceable_types
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<int*>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<int const*>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<boost::optional<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<boost::weak_ptr<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<boost::scoped_ptr<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<boost::shared_ptr<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::scoped_array<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::shared_array<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::intrusive_ptr<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(boost::make_unique<int>())
#else
//->
            decltype(boost::make_unique<int>())
//<-
#endif
//->
        >
    ));
}
//]

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>

//[test__is_indexable_iterator__std_container_iterators
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            std::vector<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            std::vector<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            std::vector<int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            std::vector<int>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            std::deque<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            std::deque<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            std::deque<int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            std::deque<int>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::list<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::list<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::list<int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::list<int>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::set<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::set<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::set<int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::set<int>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::map<int,int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::map<int,int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::map<int,int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::map<int,int>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::multiset<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::multiset<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::multiset<int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::multiset<int>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::multimap<int,int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::multimap<int,int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::multimap<int,int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::multimap<int,int>::const_reverse_iterator
        >
    ));
}
//]

#include <iterator>

//[test__is_indexable_iterator__std_iterators
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::istream_iterator<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::ostream_iterator<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::istreambuf_iterator<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::ostreambuf_iterator<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::back_insert_iterator<std::vector<int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::front_insert_iterator<std::deque<int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::insert_iterator<std::set<int> >
        >
    ));
}
//]

#include <boost/move/iterator.hpp>

//[test__is_indexable_iterator__move_iterators
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::vector<int>::iterator>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::vector<int>::const_iterator>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::vector<int>::reverse_iterator>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::vector<int>::const_reverse_iterator>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::deque<int>::iterator>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::deque<int>::const_iterator>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::deque<int>::reverse_iterator>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::deque<int>::const_reverse_iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::list<int>::iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::list<int>::const_iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::list<int>::reverse_iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::list<int>::const_reverse_iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::set<int>::iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::set<int>::const_iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::set<int>::reverse_iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::set<int>::const_reverse_iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::map<int,int>::iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::map<int,int>::const_iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::map<int,int>::reverse_iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::map<int,int>::const_reverse_iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::multiset<int>::iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::multiset<int>::const_iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::multiset<int>::reverse_iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::multiset<int>::const_reverse_iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::multimap<int,int>::iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::multimap<int,int>::const_iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::multimap<int,int>::reverse_iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<
                std::multimap<int,int>::const_reverse_iterator
            >
        >
    ));
}
//]

#include <boost/unordered_set.hpp>
#include <boost/unordered_map.hpp>

//[test__is_indexable_iterator__boost_container_iterators
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::string::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::string::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::string::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::string::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::vector<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::vector<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::vector<int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::vector<int>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::stable_vector<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::stable_vector<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::stable_vector<int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::stable_vector<int>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::static_vector<int,1>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::static_vector<int,1>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::static_vector<int,1>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::static_vector<int,1>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::small_vector<int,1>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::small_vector<int,1>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::small_vector<int,1>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::small_vector<int,1>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::deque<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::deque<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::deque<int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::deque<int>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::list<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::list<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::list<int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::list<int>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::slist<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::slist<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::set<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::set<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::set<int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::set<int>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::map<int,int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::map<int,int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::map<int,int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::map<int,int>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::multiset<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::multiset<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::multiset<int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::multiset<int>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::multimap<int,int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::multimap<int,int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::multimap<int,int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::multimap<int,int>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::flat_set<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::flat_set<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::flat_set<int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::flat_set<int>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::flat_map<int,int>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::flat_map<int,int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::flat_map<int,int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::flat_map<int,int>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::flat_multiset<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::flat_multiset<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::flat_multiset<int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::flat_multiset<int>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::flat_multimap<int,int>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::flat_multimap<int,int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::flat_multimap<int,int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::container::flat_multimap<int,int>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::unordered::unordered_set<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::unordered::unordered_set<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::unordered::unordered_map<int,int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::unordered::unordered_map<int,int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::unordered::unordered_multiset<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::unordered::unordered_multiset<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::unordered::unordered_multimap<int,int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::unordered::unordered_multimap<int,int>::const_iterator
        >
    ));
}
//]

#include <boost/iterator/iterator_facade.hpp>
#include <boost/iterator/iterator_adaptor.hpp>
#include <boost/iterator/reverse_iterator.hpp>
#include <boost/iterator/permutation_iterator.hpp>
#include <boost/iterator/filter_iterator.hpp>
#include <boost/iterator/transform_iterator.hpp>
#include <boost/iterator/indirect_iterator.hpp>
#include <boost/iterator/zip_iterator.hpp>
#include <boost/iterator/counting_iterator.hpp>
#include <boost/iterator/function_input_iterator.hpp>
#include <boost/function_output_iterator.hpp>
#include <boost/function.hpp>
#include <boost/regex.hpp>

//[test__is_indexable_iterator__boost_iterators
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::iterators::reverse_iterator<
                boost::container::vector<bool>::iterator
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::iterators::reverse_iterator<
                boost::container::vector<bool>::const_iterator
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::iterators::reverse_iterator<
                boost::container::list<char>::iterator
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::iterators::reverse_iterator<
                boost::container::list<char>::const_iterator
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::iterators::permutation_iterator<
                boost::container::vector<signed char>::iterator
              , boost::container::list<
                    boost::iterators::iterator_difference<
                        boost::container::vector<signed char>::iterator
                    >::type
                >::iterator
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::iterators::filter_iterator<
                boost::function1<bool,short>
              , short*
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::iterators::filter_iterator<
                boost::function1<bool,short>
              , short const*
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::iterators::transform_iterator<
                boost::function1<
                    boost::container::deque<unsigned char>
                  , unsigned int
                >
              , unsigned int*
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::iterators::transform_iterator<
                boost::function1<
                    boost::container::deque<unsigned char>
                  , unsigned int
                >
              , unsigned int const*
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::iterators::indirect_iterator<int**,int>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::iterators::indirect_iterator<int* const*,int>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::iterators::zip_iterator<
                boost::tuples::tuple<
                    boost::container::vector<float>::iterator
                  , boost::container::deque<double>::iterator
                >
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::iterators::counting_iterator<unsigned short>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::iterators::function_input_iterator<
                boost::function0<unsigned int>
              , unsigned int
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::function_output_iterator<boost::function1<void,int> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::iterators::shared_container_iterator<
                boost::container::vector<bool>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::regex_iterator<boost::container::string::iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::regex_token_iterator<boost::container::string::iterator>
        >
    ));
}
//]

#include <boost/range/iterator.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/range/sub_range.hpp>
#include <boost/range/counting_range.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/adaptors.hpp>
#include <boost/range/begin.hpp>
#include <utility>

//[test__is_indexable_iterator__range_iterators
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::range_iterator<
                std::pair<
                    boost::container::string::iterator
                  , boost::container::string::iterator
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::range_iterator<
                std::pair<
                    boost::container::string::const_iterator
                  , boost::container::string::const_iterator
                > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::range_iterator<
                boost::iterator_range<boost::container::string::iterator>
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::range_iterator<
                boost::iterator_range<
                    boost::container::string::const_iterator
                > const
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::range_iterator<
                boost::sub_range<
                    boost::iterator_range<boost::container::string::iterator>
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::range_iterator<
                boost::sub_range<
                    boost::iterator_range<
                        boost::container::string::const_iterator
                    > const
                >
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((boost::begin(boost::counting_range(0, 1))))
#else
//->
            decltype(boost::begin(boost::counting_range(0, 1)))
//<-
#endif
//->
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((boost::const_begin(boost::counting_range(0, 1))))
#else
//->
            decltype(boost::const_begin(boost::counting_range(0, 1)))
//<-
#endif
//->
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((boost::begin(boost::irange(0, 1))))
#else
//->
            decltype(boost::begin(boost::irange(0, 1)))
//<-
#endif
//->
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((boost::const_begin(boost::irange(0, 1))))
#else
//->
            decltype(boost::const_begin(boost::irange(0, 1)))
//<-
#endif
//->
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((boost::begin(boost::irange(0, 4, 2))))
#else
//->
            decltype(boost::begin(boost::irange(0, 4, 2)))
//<-
#endif
//->
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((boost::const_begin(boost::irange(0, 4, 2))))
#else
//->
            decltype(boost::const_begin(boost::irange(0, 4, 2)))
//<-
#endif
//->
        >
    ));
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    std::vector<int>() | boost::adaptors::adjacent_filtered(
                        boost::function2<bool,int,int>()
                    )
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    std::vector<int>() | boost::adaptors::adjacent_filtered(
                        boost::function2<bool,int,int>()
                    )
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    std::list<int>() | boost::adaptors::adjacent_filtered(
                        boost::function2<bool,int,int>()
                    )
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    std::list<int>() | boost::adaptors::adjacent_filtered(
                        boost::function2<bool,int,int>()
                    )
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    boost::container::slist<int>()
                  | boost::adaptors::adjacent_filtered(
                        boost::function2<bool,int,int>()
                    )
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    boost::container::slist<int>()
                  | boost::adaptors::adjacent_filtered(
                        boost::function2<bool,int,int>()
                    )
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    std::deque<int>() | boost::adaptors::copied(0, 1)
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    std::deque<int>() | boost::adaptors::copied(0, 1)
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    std::vector<int>() | boost::adaptors::filtered(
                        boost::function1<bool,int>()
                    )
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    std::vector<int>() | boost::adaptors::filtered(
                        boost::function1<bool,int>()
                    )
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    std::list<int>() | boost::adaptors::filtered(
                        boost::function1<bool,int>()
                    )
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    std::list<int>() | boost::adaptors::filtered(
                        boost::function1<bool,int>()
                    )
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    boost::container::slist<int>()
                  | boost::adaptors::filtered(
                        boost::function1<bool,int>()
                    )
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    boost::container::slist<int>()
                  | boost::adaptors::filtered(
                        boost::function1<bool,int>()
                    )
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((boost::begin(std::vector<int>() | boost::adaptors::indexed())))
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    std::vector<int>() | boost::adaptors::indexed()
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((boost::begin(std::list<int>() | boost::adaptors::indexed())))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    std::list<int>() | boost::adaptors::indexed()
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    boost::container::slist<int>()
                  | boost::adaptors::indexed()
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    boost::container::slist<int>()
                  | boost::adaptors::indexed()
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    std::vector<char*>() | boost::adaptors::indirected
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    std::vector<char*>() | boost::adaptors::indirected
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((boost::begin(std::list<char*>() | boost::adaptors::indirected)))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    std::list<char*>() | boost::adaptors::indirected
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    boost::container::slist<char*>()
                  | boost::adaptors::indirected
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    boost::container::slist<char*>()
                  | boost::adaptors::indirected
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((boost::begin(std::map<int,int>() | boost::adaptors::map_keys)))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    std::map<int,int>() | boost::adaptors::map_keys
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    boost::container::flat_map<int,int>()
                  | boost::adaptors::map_keys
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    boost::container::flat_map<int,int>()
                  | boost::adaptors::map_keys
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    boost::unordered::unordered_map<int,int>()
                  | boost::adaptors::map_keys
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    boost::unordered::unordered_map<int,int>()
                  | boost::adaptors::map_keys
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    std::map<int,int>() | boost::adaptors::map_values
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    std::map<int,int>() | boost::adaptors::map_values
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    boost::container::flat_map<int,int>()
                  | boost::adaptors::map_values
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    boost::container::flat_map<int,int>()
                  | boost::adaptors::map_values
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    boost::unordered::unordered_map<int,int>()
                  | boost::adaptors::map_values
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    boost::unordered::unordered_map<int,int>()
                  | boost::adaptors::map_values
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    std::vector<int>() | boost::adaptors::replaced(0, 1)
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    std::vector<int>() | boost::adaptors::replaced(0, 1)
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    std::list<int>() | boost::adaptors::replaced(0, 1)
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    std::list<int>() | boost::adaptors::replaced(0, 1)
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    boost::container::slist<int>()
                  | boost::adaptors::replaced(0, 1)
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    boost::container::slist<int>()
                  | boost::adaptors::replaced(0, 1)
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    std::vector<int>() | boost::adaptors::replaced_if(
                        boost::function1<bool,int>()
                      , 0
                    )
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    std::vector<int>() | boost::adaptors::replaced_if(
                        boost::function1<bool,int>()
                      , 0
                    )
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    std::list<int>() | boost::adaptors::replaced_if(
                        boost::function1<bool,int>()
                      , 0
                    )
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    std::list<int>() | boost::adaptors::replaced_if(
                        boost::function1<bool,int>()
                      , 0
                    )
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    boost::container::slist<int>()
                  | boost::adaptors::replaced_if(
                        boost::function1<bool,int>()
                      , 0
                    )
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    boost::container::slist<int>()
                  | boost::adaptors::replaced_if(
                        boost::function1<bool,int>()
                      , 0
                    )
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((boost::begin(std::vector<int>() | boost::adaptors::reversed)))
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    std::vector<int>() | boost::adaptors::reversed
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((boost::begin(std::list<int>() | boost::adaptors::reversed)))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    std::list<int>() | boost::adaptors::reversed
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    std::deque<int>() | boost::adaptors::sliced(0, 1)
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    std::deque<int>() | boost::adaptors::sliced(0, 1)
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((boost::begin(std::vector<int>() | boost::adaptors::strided(2))))
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    std::vector<int>() | boost::adaptors::strided(2)
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((boost::begin(std::list<int>() | boost::adaptors::strided(2))))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    std::list<int>() | boost::adaptors::strided(2)
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    boost::container::slist<int>()
                  | boost::adaptors::strided(2)
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    boost::container::slist<int>()
                  | boost::adaptors::strided(2)
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((  // This should be BOOST_MPL_ASSERT.
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    boost::container::string() | boost::adaptors::tokenized(
                        boost::regex("\\w+")
                    )
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((  // This should be BOOST_MPL_ASSERT.
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    boost::container::string() | boost::adaptors::tokenized(
                        boost::regex("\\w+")
                    )
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    std::vector<int>() | boost::adaptors::transformed(
                        boost::function1<int const&,int>()
                    )
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    std::vector<int>() | boost::adaptors::transformed(
                        boost::function1<int const&,int>()
                    )
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    std::list<int>() | boost::adaptors::transformed(
                        boost::function1<int const&,int>()
                    )
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    std::list<int>() | boost::adaptors::transformed(
                        boost::function1<int const&,int>()
                    )
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    boost::container::slist<int>()
                  | boost::adaptors::transformed(
                        boost::function1<int const&,int>()
                    )
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    boost::container::slist<int>()
                  | boost::adaptors::transformed(
                        boost::function1<int const&,int>()
                    )
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((boost::begin(std::vector<int>() | boost::adaptors::uniqued)))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    std::vector<int>() | boost::adaptors::uniqued
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((boost::begin(std::list<int>() | boost::adaptors::uniqued)))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    std::list<int>() | boost::adaptors::uniqued
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::begin(
                    boost::container::slist<int>() | boost::adaptors::uniqued
                )
            ))
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::const_begin(
                    boost::container::slist<int>() | boost::adaptors::uniqued
                )
            ))
        >
    ));
    //->
}
//]

#if !defined BOOST_NO_CXX11_HDR_ARRAY
#include <array>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            std::array<int,1>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            std::array<int,1>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            std::array<int,1>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            std::array<int,1>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::array<int,1>::iterator>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::array<int,1>::const_iterator>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::array<int,1>::reverse_iterator>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::array<int,1>::const_reverse_iterator>
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_ARRAY

#if !defined BOOST_NO_CXX11_HDR_FORWARD_LIST
#include <forward_list>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::forward_list<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::forward_list<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::forward_list<int>::iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::forward_list<int>::const_iterator>
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_FORWARD_LIST

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_SET
#include <unordered_set>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::unordered_set<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::unordered_set<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::unordered_multiset<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::unordered_multiset<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::unordered_set<int>::iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::unordered_set<int>::const_iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::unordered_multiset<int>::iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::unordered_multiset<int>::const_iterator>
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_UNORDERED_SET

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_MAP
#include <unordered_map>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::unordered_map<int,int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::unordered_map<int,int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::unordered_multimap<int,int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::unordered_multimap<int,int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::unordered_map<int,int>::iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::unordered_map<int,int>::const_iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<std::unordered_multimap<int,int>::iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::move_iterator<
                std::unordered_multimap<int,int>::const_iterator
            >
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_UNORDERED_MAP

#if defined BOOST_HAS_TR1_ARRAY
#include <boost/tr1/array.hpp>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            std::tr1::array<int,1>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            std::tr1::array<int,1>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            std::tr1::array<int,1>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            std::tr1::array<int,1>::const_reverse_iterator
        >
    ));
}
#endif  // BOOST_HAS_TR1_ARRAY

#if defined BOOST_HAS_TR1_UNORDERED_SET
#include <boost/tr1/unordered_set.hpp>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::tr1::unordered_set<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::tr1::unordered_set<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::tr1::unordered_multiset<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::tr1::unordered_multiset<int>::const_iterator
        >
    ));
}
#endif  // BOOST_HAS_TR1_UNORDERED_SET

#if defined BOOST_HAS_TR1_UNORDERED_MAP
#include <boost/tr1/unordered_map.hpp>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::tr1::unordered_map<int,int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::tr1::unordered_map<int,int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::tr1::unordered_multimap<int,int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            std::tr1::unordered_multimap<int,int>::const_iterator
        >
    ));
}
#endif  // BOOST_HAS_TR1_UNORDERED_MAP

#if !defined BOOST_MSVC
#include <boost/array.hpp>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::array<int,1>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::array<int,1>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::array<int,1>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::array<int,1>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_array<int,1>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_array<int,1>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_array<int,1>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_array<int,1>::const_reverse_iterator
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

//[test__is_indexable_iterator__ptr_container_iterators
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_vector<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_vector<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_vector<int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_vector<int>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_deque<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_deque<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_deque<int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_deque<int>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_circular_buffer<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_circular_buffer<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_circular_buffer<int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_circular_buffer<int>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_list<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_list<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_list<int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_list<int>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_set<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_set<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_set<int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_set<int>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_map<int,int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_map<int,int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_map<int,int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_map<int,int>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_multiset<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_multiset<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_multiset<int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_multiset<int>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_multimap<int,int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_multimap<int,int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_multimap<int,int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_multimap<int,int>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_unordered_set<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_unordered_set<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_unordered_map<int,int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_unordered_map<int,int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_unordered_multiset<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_unordered_multiset<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_unordered_multimap<int,int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::ptr_unordered_multimap<int,int>::const_iterator
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

//[test__is_indexable_iterator__multi_index_iterators
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
        boost::concept::traits::is_indexable_iterator<
            boost::multi_index::nth_index<your_multi_index_ds,0>::type
            ::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::multi_index::nth_index<your_multi_index_ds,0>::type
            ::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::multi_index::nth_index<your_multi_index_ds,1>::type
            ::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::multi_index::nth_index<your_multi_index_ds,1>::type
            ::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::multi_index::nth_index<your_multi_index_ds,2>::type
            ::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::multi_index::nth_index<your_multi_index_ds,2>::type
            ::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::multi_index::nth_index<your_multi_index_ds,3>::type
            ::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::multi_index::nth_index<your_multi_index_ds,3>::type
            ::const_iterator
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

//[test__is_indexable_iterator__bimap_iterators
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            >::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            >::left_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            >::left_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            >::right_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            >::right_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            >::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            >::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            >::left_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            >::left_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            >::right_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            >::right_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            >::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            >::left_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            >::left_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            >::right_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            >::right_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::set_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::set_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::set_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::set_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::set_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::set_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::set_of<short>
            >::right_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::set_of<short>
            >::right_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::multiset_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::multiset_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::list_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::list_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::list_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::list_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::list_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::list_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::list_of<short>
            >::right_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::list_of<short>
            >::right_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::vector_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::vector_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::set_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::set_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::set_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::set_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::set_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::set_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::set_of<short>
            >::right_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::set_of<short>
            >::right_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::multiset_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::multiset_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::list_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::list_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::list_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::list_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::list_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::list_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::list_of<short>
            >::right_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::list_of<short>
            >::right_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            >::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            >::left_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            >::left_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            >::right_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            >::right_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            >::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            >::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            >::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            >::left_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            >::left_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            >::right_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            >::right_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            >::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            >::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            >::left_map::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            >::left_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            >::left_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            >::left_map::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            >::right_map::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            >::right_map::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            >::right_map::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            >::right_map::const_reverse_iterator
        >
    ));
}
//]

#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/vector_sparse.hpp>
#include <boost/numeric/ublas/vector_proxy.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>

//[test__is_indexable_iterator__ublas_vector_iterators
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::vector<double>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::vector<double>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::vector<double>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::vector<double>::const_reverse_iterator
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::c_vector<double,1>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::c_vector<double,1>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::c_vector<double,1>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::c_vector<double,1>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::fixed_vector<double,1>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::fixed_vector<double,1>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::fixed_vector<double,1>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::fixed_vector<double,1>
            ::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::bounded_vector<double,1>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::bounded_vector<double,1>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::bounded_vector<double,1>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::bounded_vector<double,1>
            ::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::unit_vector<>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::unit_vector<>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::zero_vector<>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::zero_vector<>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::scalar_vector<>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::scalar_vector<>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::mapped_vector<double>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::mapped_vector<double>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::mapped_vector<double>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::mapped_vector<
                double
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::compressed_vector<double>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::compressed_vector<double>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::compressed_vector<double>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::compressed_vector<
                double
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::coordinate_vector<double>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::coordinate_vector<double>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::coordinate_vector<double>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::coordinate_vector<
                double
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::vector_range<
                boost::numeric::ublas::vector<double>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::vector_range<
                boost::numeric::ublas::vector<double>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::vector_range<
                boost::numeric::ublas::vector<double>
            >::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::vector_range<
                boost::numeric::ublas::vector<double>
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::vector_slice<
                boost::numeric::ublas::vector<double>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::vector_slice<
                boost::numeric::ublas::vector<double>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::vector_slice<
                boost::numeric::ublas::vector<double>
            >::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::vector_slice<
                boost::numeric::ublas::vector<double>
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_row<
                boost::numeric::ublas::matrix<double>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_row<
                boost::numeric::ublas::matrix<double>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_row<
                boost::numeric::ublas::matrix<double>
            >::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_row<
                boost::numeric::ublas::matrix<double>
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_column<
                boost::numeric::ublas::matrix<double>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_column<
                boost::numeric::ublas::matrix<double>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_column<
                boost::numeric::ublas::matrix<double>
            >::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_column<
                boost::numeric::ublas::matrix<double>
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_vector_range<
                boost::numeric::ublas::matrix<double>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_vector_range<
                boost::numeric::ublas::matrix<double>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_vector_range<
                boost::numeric::ublas::matrix<double>
            >::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_vector_range<
                boost::numeric::ublas::matrix<double>
            >::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_vector_slice<
                boost::numeric::ublas::matrix<double>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_vector_slice<
                boost::numeric::ublas::matrix<double>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_vector_slice<
                boost::numeric::ublas::matrix<double>
            >::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_vector_slice<
                boost::numeric::ublas::matrix<double>
            >::const_reverse_iterator
        >
    ));
    //->
}
//]

#include <boost/numeric/ublas/vector_of_vector.hpp>
#include <boost/numeric/ublas/triangular.hpp>
#include <boost/numeric/ublas/symmetric.hpp>
#include <boost/numeric/ublas/hermitian.hpp>
#include <boost/numeric/ublas/banded.hpp>
#include <boost/numeric/ublas/matrix_sparse.hpp>

//[test__is_indexable_iterator__ublas_matrix_iterators
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix<double>::iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix<double>::const_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix<double>::iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix<double>::const_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix<double>::reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix<double>::const_reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix<double>::reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix<double>::const_reverse_iterator2
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::c_matrix<double,1,1>::iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::c_matrix<double,1,1>::const_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::c_matrix<double,1,1>::iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::c_matrix<double,1,1>::const_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::c_matrix<double,1,1>::reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::c_matrix<double,1,1>
            ::const_reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::c_matrix<double,1,1>::reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::c_matrix<double,1,1>
            ::const_reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::fixed_matrix<double,1,1>::iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::fixed_matrix<double,1,1>::const_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::fixed_matrix<double,1,1>::iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::fixed_matrix<double,1,1>::const_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::fixed_matrix<double,1,1>::reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::fixed_matrix<double,1,1>
            ::const_reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::fixed_matrix<double,1,1>::reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::fixed_matrix<double,1,1>
            ::const_reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::bounded_matrix<double,1,1>::iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::bounded_matrix<double,1,1>::const_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::bounded_matrix<double,1,1>::iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::bounded_matrix<double,1,1>::const_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::bounded_matrix<double,1,1>
            ::reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::bounded_matrix<double,1,1>
            ::const_reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::bounded_matrix<double,1,1>
            ::reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::bounded_matrix<double,1,1>
            ::const_reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::identity_matrix<>::iterator1
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::identity_matrix<>::const_iterator1
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::identity_matrix<>::iterator2
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::identity_matrix<>::const_iterator2
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::identity_matrix<>::reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::identity_matrix<>::const_reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::identity_matrix<>::reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::identity_matrix<>::const_reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::zero_matrix<>::iterator1
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::zero_matrix<>::const_iterator1
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::zero_matrix<>::iterator2
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::zero_matrix<>::const_iterator2
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::zero_matrix<>::reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::zero_matrix<>::const_reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::zero_matrix<>::reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::zero_matrix<>::const_reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::scalar_matrix<>::iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::scalar_matrix<>::const_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::scalar_matrix<>::iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::scalar_matrix<>::const_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::scalar_matrix<>::reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::scalar_matrix<>::const_reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::scalar_matrix<>::reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::scalar_matrix<>::const_reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::generalized_vector_of_vector<
                double
            >::iterator1
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::generalized_vector_of_vector<
                double
            >::const_iterator1
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::generalized_vector_of_vector<
                double
            >::iterator2
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::generalized_vector_of_vector<
                double
            >::const_iterator2
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::generalized_vector_of_vector<
                double
            >::reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::generalized_vector_of_vector<
                double
            >::const_reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::generalized_vector_of_vector<
                double
            >::reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::generalized_vector_of_vector<
                double
            >::const_reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::lower
            >::iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::lower
            >::const_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::lower
            >::iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::lower
            >::const_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::lower
            >::reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::lower
            >::const_reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::lower
            >::reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::lower
            >::const_reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::upper
            >::iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::upper
            >::const_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::upper
            >::iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::upper
            >::const_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::upper
            >::reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::upper
            >::const_reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::upper
            >::reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::upper
            >::const_reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::lower
            >::iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::lower
            >::const_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::lower
            >::iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::lower
            >::const_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::lower
            >::reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::lower
            >::const_reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::lower
            >::reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::lower
            >::const_reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::upper
            >::iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::upper
            >::const_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::upper
            >::iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::upper
            >::const_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::upper
            >::reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::upper
            >::const_reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::upper
            >::reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::upper
            >::const_reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::lower
            >::iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::lower
            >::const_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::lower
            >::iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::lower
            >::const_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::lower
            >::reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::lower
            >::const_reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::lower
            >::reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::lower
            >::const_reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::upper
            >::iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::upper
            >::const_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::upper
            >::iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::upper
            >::const_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::upper
            >::reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::upper
            >::const_reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::upper
            >::reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::upper
            >::const_reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::lower
            >::iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::lower
            >::const_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::lower
            >::iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::lower
            >::const_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::lower
            >::reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::lower
            >::const_reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::lower
            >::reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::lower
            >::const_reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::upper
            >::iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::upper
            >::const_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::upper
            >::iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::upper
            >::const_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::upper
            >::reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::upper
            >::const_reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::upper
            >::reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::upper
            >::const_reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::lower
            >::iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::lower
            >::const_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::lower
            >::iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::lower
            >::const_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::lower
            >::reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::lower
            >::const_reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::lower
            >::reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::lower
            >::const_reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::upper
            >::iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::upper
            >::const_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::upper
            >::iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::upper
            >::const_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::upper
            >::reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::upper
            >::const_reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::upper
            >::reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::upper
            >::const_reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::banded_matrix<double>::iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::banded_matrix<double>::const_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::banded_matrix<double>::iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::banded_matrix<double>::const_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::banded_matrix<double>::reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::banded_matrix<
                double
            >::const_reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::banded_matrix<double>::reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::banded_matrix<
                double
            >::const_reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::banded_adaptor<
                boost::numeric::ublas::matrix<double>
            >::iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::banded_adaptor<
                boost::numeric::ublas::matrix<double>
            >::const_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::banded_adaptor<
                boost::numeric::ublas::matrix<double>
            >::iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::banded_adaptor<
                boost::numeric::ublas::matrix<double>
            >::const_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::banded_adaptor<
                boost::numeric::ublas::matrix<double>
            >::reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::banded_adaptor<
                boost::numeric::ublas::matrix<double>
            >::const_reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::banded_adaptor<
                boost::numeric::ublas::matrix<double>
            >::reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::banded_adaptor<
                boost::numeric::ublas::matrix<double>
            >::const_reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::mapped_matrix<double>::iterator1
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::mapped_matrix<double>::const_iterator1
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::mapped_matrix<double>::iterator2
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::mapped_matrix<double>::const_iterator2
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::mapped_matrix<double>::reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::mapped_matrix<
                double
            >::const_reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::mapped_matrix<double>::reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::mapped_matrix<
                double
            >::const_reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::compressed_matrix<double>::iterator1
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::compressed_matrix<double>::const_iterator1
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::compressed_matrix<double>::iterator2
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::compressed_matrix<double>::const_iterator2
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::compressed_matrix<
                double
            >::reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::compressed_matrix<
                double
            >::const_reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::compressed_matrix<
                double
            >::reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::compressed_matrix<
                double
            >::const_reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::coordinate_matrix<double>::iterator1
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::coordinate_matrix<double>::const_iterator1
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::coordinate_matrix<double>::iterator2
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::coordinate_matrix<double>::const_iterator2
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::coordinate_matrix<
                double
            >::reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::coordinate_matrix<
                double
            >::const_reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::coordinate_matrix<
                double
            >::reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::coordinate_matrix<
                double
            >::const_reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_range<
                boost::numeric::ublas::matrix<double>
            >::iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_range<
                boost::numeric::ublas::matrix<double>
            >::const_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_range<
                boost::numeric::ublas::matrix<double>
            >::iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_range<
                boost::numeric::ublas::matrix<double>
            >::const_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_range<
                boost::numeric::ublas::matrix<double>
            >::reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_range<
                boost::numeric::ublas::matrix<double>
            >::const_reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_range<
                boost::numeric::ublas::matrix<double>
            >::reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_range<
                boost::numeric::ublas::matrix<double>
            >::const_reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_slice<
                boost::numeric::ublas::matrix<double>
            >::iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_slice<
                boost::numeric::ublas::matrix<double>
            >::const_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_slice<
                boost::numeric::ublas::matrix<double>
            >::iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_slice<
                boost::numeric::ublas::matrix<double>
            >::const_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_slice<
                boost::numeric::ublas::matrix<double>
            >::reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_slice<
                boost::numeric::ublas::matrix<double>
            >::const_reverse_iterator1
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_slice<
                boost::numeric::ublas::matrix<double>
            >::reverse_iterator2
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::matrix_slice<
                boost::numeric::ublas::matrix<double>
            >::const_reverse_iterator2
        >
    ));
    //->
}
//]

#include <boost/numeric/ublas/storage.hpp>

//[test__is_indexable_iterator__ublas_storage_iterators
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::unbounded_array<double>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::unbounded_array<double>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::bounded_array<double,1>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::bounded_array<double,1>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::range::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::range::const_reverse_iterator
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::map_std<int,double>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::map_std<int,double>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::map_std<int,double>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::map_std<int,double>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::map_array<int,double>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::map_array<int,double>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::map_array<int,double>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::numeric::ublas::map_array<
                int
              , double
            >::const_reverse_iterator
        >
    ));
    //->
}
//]

//[test__is_indexable_iterator__heap_iterators
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::heap::priority_queue<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::heap::priority_queue<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::heap::binomial_heap<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::heap::binomial_heap<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::heap::d_ary_heap<int,boost::heap::arity<1> >::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::heap::d_ary_heap<
                int
              , boost::heap::arity<1>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((  // interesting
        boost::concept::traits::is_indexable_iterator<
            boost::heap::d_ary_heap<
                int
              , boost::heap::mutable_<true>
              , boost::heap::arity<1>
            >::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((  // interesting
        boost::concept::traits::is_indexable_iterator<
            boost::heap::d_ary_heap<
                int
              , boost::heap::mutable_<true>
              , boost::heap::arity<1>
            >::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::heap::fibonacci_heap<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::heap::fibonacci_heap<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::heap::pairing_heap<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::heap::pairing_heap<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::heap::skew_heap<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_indexable_iterator<
            boost::heap::skew_heap<int>::const_iterator
        >
    ));
}
//]

#include <boost/circular_buffer.hpp>
#include <boost/multi_array.hpp>

//[test__is_indexable_iterator__misc_iterators
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::circular_buffer<int>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::circular_buffer<int>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::circular_buffer<int>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::circular_buffer<int>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::multi_array<float,1>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::multi_array<float,1>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::multi_array<float,1>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::multi_array<float,1>::const_reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::multi_array<float,2>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::multi_array<float,2>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::multi_array<float,2>::reverse_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::multi_array<float,2>::const_reverse_iterator
        >
    ));
}
//]

