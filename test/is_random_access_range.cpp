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

#include <boost/concept/traits/query/is_range.hpp>
#include <boost/concept/traits/query/is_random_access_iterator.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>

//[test__is_random_access_range__std_containers
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            std::vector<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            std::vector<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            std::deque<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            std::deque<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::list<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::list<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::set<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::set<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::map<int,int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::map<int,int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::multiset<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::multiset<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::multimap<int,int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::multimap<int,int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
}
//]

#include <boost/unordered_set.hpp>
#include <boost/unordered_map.hpp>

//[test__is_random_access_range__boost_containers
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::container::string
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::container::string const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::container::vector<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::container::vector<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::container::stable_vector<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::container::stable_vector<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::container::static_vector<int,1>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::container::static_vector<int,1> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::container::small_vector<int,1>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::container::small_vector<int,1> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::container::deque<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::container::deque<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::container::list<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::container::list<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::container::slist<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::container::slist<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::container::set<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::container::set<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::container::map<int,int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::container::map<int,int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::container::multiset<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::container::multiset<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::container::multimap<int,int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::container::multimap<int,int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::container::flat_set<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::container::flat_set<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::container::flat_map<int,int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::container::flat_map<int,int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::container::flat_multiset<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::container::flat_multiset<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::container::flat_multimap<int,int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::container::flat_multimap<int,int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::unordered::unordered_set<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::unordered::unordered_set<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::unordered::unordered_map<int,int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::unordered::unordered_map<int,int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::unordered::unordered_multiset<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::unordered::unordered_multiset<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::unordered::unordered_multimap<int,int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::unordered::unordered_multimap<int,int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
}
//]

#include <boost/range/iterator_range.hpp>
#include <boost/range/sub_range.hpp>
#include <boost/range/counting_range.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/adaptors.hpp>

#include <boost/function.hpp>
#include <boost/regex.hpp>
#include <utility>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

//[test__is_random_access_range__ranges
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            std::pair<
                boost::container::string::iterator
              , boost::container::string::iterator
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            std::pair<
                boost::container::string::const_iterator
              , boost::container::string::const_iterator
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::iterator_range<boost::container::string::iterator>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::iterator_range<
                boost::container::string::const_iterator
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::sub_range<
                boost::iterator_range<boost::container::string::iterator>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::sub_range<
                boost::iterator_range<boost::container::string::const_iterator>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((boost::counting_range(0, 1)))
#else
//->
            decltype(boost::counting_range(0, 1))
//<-
#endif
//->
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((boost::counting_range(0, 1))) const
#else
//->
            decltype(boost::counting_range(0, 1)) const
//<-
#endif
//->
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((boost::irange(0, 1)))
#else
//->
            decltype(boost::irange(0, 1))
//<-
#endif
//->
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((boost::irange(0, 1))) const
#else
//->
            decltype(boost::irange(0, 1)) const
//<-
#endif
//->
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((boost::irange(0, 4, 2)))
#else
//->
            decltype(boost::irange(0, 4, 2))
//<-
#endif
//->
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((boost::irange(0, 4, 2))) const
#else
//->
            decltype(boost::irange(0, 4, 2)) const
//<-
#endif
//->
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                std::vector<int>() | boost::adaptors::adjacent_filtered(
                    boost::function2<bool,int,int>()
                )
            ))
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                std::vector<int>() | boost::adaptors::adjacent_filtered(
                    boost::function2<bool,int,int>()
                )
            )) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                std::list<int>() | boost::adaptors::adjacent_filtered(
                    boost::function2<bool,int,int>()
                )
            ))
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                std::list<int>() | boost::adaptors::adjacent_filtered(
                    boost::function2<bool,int,int>()
                )
            )) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::container::slist<int>()
              | boost::adaptors::adjacent_filtered(
                    boost::function2<bool,int,int>()
                )
            ))
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::container::slist<int>()
              | boost::adaptors::adjacent_filtered(
                    boost::function2<bool,int,int>()
                )
            )) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((std::deque<int>() | boost::adaptors::copied(0, 1)))
#else
            decltype(std::deque<int>() | boost::adaptors::copied(0, 1))
#endif
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((std::deque<int>() | boost::adaptors::copied(0, 1))) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                std::vector<int>() | boost::adaptors::filtered(
                    boost::function1<bool,int>()
                )
            ))
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                std::vector<int>() | boost::adaptors::filtered(
                    boost::function1<bool,int>()
                )
            )) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                std::list<int>() | boost::adaptors::filtered(
                    boost::function1<bool,int>()
                )
            ))
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                std::list<int>() | boost::adaptors::filtered(
                    boost::function1<bool,int>()
                )
            )) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::container::slist<int>() | boost::adaptors::filtered(
                    boost::function1<bool,int>()
                )
            ))
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::container::slist<int>() | boost::adaptors::filtered(
                    boost::function1<bool,int>()
                )
            )) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((std::vector<int>() | boost::adaptors::indexed()))
#else
            decltype(std::vector<int>() | boost::adaptors::indexed())
#endif
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((std::vector<int>() | boost::adaptors::indexed())) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((std::list<int>() | boost::adaptors::indexed()))
#else
            decltype(std::list<int>() | boost::adaptors::indexed())
#endif
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((std::list<int>() | boost::adaptors::indexed())) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((boost::container::slist<int>() | boost::adaptors::indexed()))
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::container::slist<int>() | boost::adaptors::indexed()
            )) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((std::vector<char*>() | boost::adaptors::indirected))
#else
            decltype(std::vector<char*>() | boost::adaptors::indirected)
#endif
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((std::vector<char*>() | boost::adaptors::indirected)) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((std::list<char*>() | boost::adaptors::indirected))
#else
            decltype(std::list<char*>() | boost::adaptors::indirected)
#endif
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((std::list<char*>() | boost::adaptors::indirected)) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((boost::container::slist<char*>() | boost::adaptors::indirected))
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::container::slist<char*>() | boost::adaptors::indirected
            )) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((std::map<int,int>() | boost::adaptors::map_keys))
#else
            decltype(std::map<int,int>() | boost::adaptors::map_keys)
#endif
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((std::map<int,int>() | boost::adaptors::map_keys)) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::container::flat_map<int,int>()
              | boost::adaptors::map_keys
            ))
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::container::flat_map<int,int>()
              | boost::adaptors::map_keys
            )) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::unordered::unordered_map<int,int>()
              | boost::adaptors::map_keys
            ))
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::unordered::unordered_map<int,int>()
              | boost::adaptors::map_keys
            )) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((std::map<int,int>() | boost::adaptors::map_values))
#else
            decltype(std::map<int,int>() | boost::adaptors::map_values)
#endif
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((std::map<int,int>() | boost::adaptors::map_values)) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::container::flat_map<int,int>()
              | boost::adaptors::map_values
            ))
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::container::flat_map<int,int>()
              | boost::adaptors::map_values
            )) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::unordered::unordered_map<int,int>()
              | boost::adaptors::map_values
            ))
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::unordered::unordered_map<int,int>()
              | boost::adaptors::map_values
            )) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((std::vector<int>() | boost::adaptors::replaced(0, 1)))
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((std::vector<int>() | boost::adaptors::replaced(0, 1))) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((std::list<int>() | boost::adaptors::replaced(0, 1)))
#else
            decltype(std::list<int>() | boost::adaptors::replaced(0, 1))
#endif
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((std::list<int>() | boost::adaptors::replaced(0, 1))) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::container::slist<int>()
              | boost::adaptors::replaced(0, 1)
            ))
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::container::slist<int>()
              | boost::adaptors::replaced(0, 1)
            )) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                std::vector<int>() | boost::adaptors::replaced_if(
                    boost::function1<bool,int>()
                  , 0
                )
            ))
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                std::vector<int>() | boost::adaptors::replaced_if(
                    boost::function1<bool,int>()
                  , 0
                )
            )) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                std::list<int>() | boost::adaptors::replaced_if(
                    boost::function1<bool,int>()
                  , 0
                )
            ))
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                std::list<int>() | boost::adaptors::replaced_if(
                    boost::function1<bool,int>()
                  , 0
                )
            )) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::container::slist<int>() | boost::adaptors::replaced_if(
                    boost::function1<bool,int>()
                  , 0
                )
            ))
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::container::slist<int>() | boost::adaptors::replaced_if(
                    boost::function1<bool,int>()
                  , 0
                )
            )) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((std::vector<int>() | boost::adaptors::reversed))
#else
            decltype(std::vector<int>() | boost::adaptors::reversed)
#endif
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((std::vector<int>() | boost::adaptors::reversed)) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((std::list<int>() | boost::adaptors::reversed))
#else
            decltype(std::list<int>() | boost::adaptors::reversed)
#endif
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((std::list<int>() | boost::adaptors::reversed)) const
#else
            decltype(std::list<int>() | boost::adaptors::reversed) const
#endif
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((std::deque<int>() | boost::adaptors::sliced(0, 1)))
#else
            decltype(std::deque<int>() | boost::adaptors::sliced(0, 1))
#endif
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((std::deque<int>() | boost::adaptors::sliced(0, 1))) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((std::vector<int>() | boost::adaptors::strided(2)))
#else
            decltype(std::vector<int>() | boost::adaptors::strided(2))
#endif
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((std::vector<int>() | boost::adaptors::strided(2))) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((std::list<int>() | boost::adaptors::strided(2)))
#else
            decltype(std::list<int>() | boost::adaptors::strided(2))
#endif
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((std::list<int>() | boost::adaptors::strided(2))) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((boost::container::slist<int>() | boost::adaptors::strided(2)))
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::container::slist<int>() | boost::adaptors::strided(2)
            )) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((  // This should be BOOST_MPL_ASSERT.
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::container::string() | boost::adaptors::tokenized(
                    boost::regex("\\w+")
                )
            ))
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((  // This should be BOOST_MPL_ASSERT.
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::container::string() | boost::adaptors::tokenized(
                    boost::regex("\\w+")
                )
            )) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                std::vector<int>() | boost::adaptors::transformed(
                    boost::function1<int const&,int>()
                )
            ))
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                std::vector<int>() | boost::adaptors::transformed(
                    boost::function1<int const&,int>()
                )
            )) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                std::list<int>() | boost::adaptors::transformed(
                    boost::function1<int const&,int>()
                )
            ))
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                std::list<int>() | boost::adaptors::transformed(
                    boost::function1<int const&,int>()
                )
            )) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::container::slist<int>() | boost::adaptors::transformed(
                    boost::function1<int const&,int>()
                )
            ))
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::container::slist<int>() | boost::adaptors::transformed(
                    boost::function1<int const&,int>()
                )
            )) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((std::vector<int>() | boost::adaptors::uniqued))
#else
            decltype(std::vector<int>() | boost::adaptors::uniqued)
#endif
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((std::vector<int>() | boost::adaptors::uniqued)) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((std::list<int>() | boost::adaptors::uniqued))
#else
            decltype(std::list<int>() | boost::adaptors::uniqued)
#endif
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF((std::list<int>() | boost::adaptors::uniqued)) const
#else
            decltype(std::list<int>() | boost::adaptors::uniqued) const
#endif
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((boost::container::slist<int>() | boost::adaptors::uniqued))
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            ((
                boost::container::slist<int>() | boost::adaptors::uniqued
            )) const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
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
        boost::concept::traits::is_range<
            std::array<int,1>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            std::array<int,1> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
}
#endif

#if !defined BOOST_NO_CXX11_HDR_FORWARD_LIST
#include <forward_list>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::forward_list<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::forward_list<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
}
#endif

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_SET
#include <unordered_set>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::unordered_set<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::unordered_set<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::unordered_multiset<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::unordered_multiset<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_UNORDERED_SET

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_MAP
#include <unordered_map>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::unordered_map<int,int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::unordered_map<int,int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::unordered_multimap<int,int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::unordered_multimap<int,int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_UNORDERED_MAP

#if defined BOOST_HAS_TR1_ARRAY
#include <boost/tr1/array.hpp>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            std::tr1::array<int,1>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            std::tr1::array<int,1> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
}
#endif

#if defined BOOST_HAS_TR1_UNORDERED_SET
#include <boost/tr1/unordered_set.hpp>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::tr1::unordered_set<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::tr1::unordered_set<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::tr1::unordered_multiset<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::tr1::unordered_multiset<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
}
#endif  // BOOST_HAS_TR1_UNORDERED_SET

#if defined BOOST_HAS_TR1_UNORDERED_MAP
#include <boost/tr1/unordered_map.hpp>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::tr1::unordered_map<int,int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::tr1::unordered_map<int,int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::tr1::unordered_multimap<int,int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            std::tr1::unordered_multimap<int,int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
}
#endif  // BOOST_HAS_TR1_UNORDERED_MAP

#if !defined BOOST_MSVC
#include <boost/array.hpp>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::array<int,1>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::array<int,1> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::ptr_array<int,1>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::ptr_array<int,1> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
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

//[test__is_random_access_range__ptr_containers
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::ptr_vector<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::ptr_vector<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::ptr_deque<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::ptr_deque<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::ptr_circular_buffer<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::ptr_circular_buffer<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::ptr_list<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::ptr_list<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::ptr_set<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::ptr_set<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::ptr_map<int,int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::ptr_map<int,int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::ptr_multiset<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::ptr_multiset<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::ptr_multimap<int,int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::ptr_multimap<int,int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::ptr_unordered_set<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::ptr_unordered_set<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::ptr_unordered_map<int,int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::ptr_unordered_map<int,int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::ptr_unordered_multiset<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::ptr_unordered_multiset<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::ptr_unordered_multimap<int,int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::ptr_unordered_multimap<int,int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
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

//[test__is_random_access_range__multi_index_containers
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
        boost::concept::traits::is_range<
            boost::multi_index::nth_index<your_multi_index_ds,0>::type
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::multi_index::nth_index<your_multi_index_ds,0>::type const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::multi_index::nth_index<your_multi_index_ds,1>::type
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::multi_index::nth_index<your_multi_index_ds,1>::type const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::multi_index::nth_index<your_multi_index_ds,2>::type
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::multi_index::nth_index<your_multi_index_ds,2>::type const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::multi_index::nth_index<your_multi_index_ds,3>::type
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::multi_index::nth_index<your_multi_index_ds,3>::type const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
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

//[test__is_random_access_range__bimap_views
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::list_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::set_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::list_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::set_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::set_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::set_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::set_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::set_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::set_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::multiset_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::multiset_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::list_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::list_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::list_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::list_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::list_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::list_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::vector_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::vector_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::set_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::set_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::set_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::set_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::set_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::set_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::multiset_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::multiset_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::list_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::list_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::list_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::list_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::list_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::list_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::vector_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::vector_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::unordered_multiset_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::set_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::list_of<char>
              , boost::bimaps::vector_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::set_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_set_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            >::left_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            >::left_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            >::right_map
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::bimaps::bimap<
                boost::bimaps::vector_of<short>
              , boost::bimaps::list_of<char>
            >::right_map const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
}
//]

#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/vector_sparse.hpp>
#include <boost/numeric/ublas/vector_proxy.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>

//[test__is_random_access_range__ublas_vectors
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::vector<double>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::vector<double> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::c_vector<double,1>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::c_vector<double,1> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::fixed_vector<double,1>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::fixed_vector<double,1> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::bounded_vector<double,1>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::bounded_vector<double,1> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::unit_vector<>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::unit_vector<> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::zero_vector<>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::zero_vector<> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::scalar_vector<>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::scalar_vector<> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::mapped_vector<double>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::mapped_vector<double> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::compressed_vector<double>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::compressed_vector<double> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::coordinate_vector<double>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::coordinate_vector<double> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    //->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::vector_range<
                boost::numeric::ublas::vector<double>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::vector_range<
                boost::numeric::ublas::vector<double>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::vector_slice<
                boost::numeric::ublas::vector<double>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::vector_slice<
                boost::numeric::ublas::vector<double>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    //->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::matrix_row<
                boost::numeric::ublas::matrix<double>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::matrix_row<
                boost::numeric::ublas::matrix<double>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::matrix_column<
                boost::numeric::ublas::matrix<double>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::matrix_column<
                boost::numeric::ublas::matrix<double>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::matrix_vector_range<
                boost::numeric::ublas::matrix<double>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::matrix_vector_range<
                boost::numeric::ublas::matrix<double>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::matrix_vector_slice<
                boost::numeric::ublas::matrix<double>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::matrix_vector_slice<
                boost::numeric::ublas::matrix<double>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    //->
}
//]

//[test__is_random_access_range__ublas_storage
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::unbounded_array<double>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::unbounded_array<double> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::bounded_array<double,1>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::bounded_array<double,1> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::range
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::range const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::map_std<int,double>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::map_std<int,double> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::map_array<int,double>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::numeric::ublas::map_array<int,double> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    //->
}
//]

//[test__is_random_access_range__boost_heaps
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::heap::priority_queue<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::heap::priority_queue<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::heap::binomial_heap<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::heap::binomial_heap<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::heap::d_ary_heap<int,boost::heap::arity<1> >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::heap::d_ary_heap<int,boost::heap::arity<1> > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::heap::d_ary_heap<
                int
              , boost::heap::mutable_<true>
              , boost::heap::arity<1>
            >
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::heap::d_ary_heap<
                int
              , boost::heap::mutable_<true>
              , boost::heap::arity<1>
            > const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::heap::fibonacci_heap<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::heap::fibonacci_heap<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::heap::pairing_heap<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::heap::pairing_heap<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::heap::skew_heap<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::heap::skew_heap<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
}
//]

#include <boost/circular_buffer.hpp>
#include <boost/multi_array.hpp>

//[test__is_random_access_range__misc_containers
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::circular_buffer<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::circular_buffer<int> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::multi_array<float,1>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::multi_array<float,1> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::multi_array<float,2>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::multi_array<float,2> const
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
}
//]

