// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// Include all necessary Boost.Container header files
// before including any header file that uses Boost.MPL
// to avoid ambiguity errors between size_t and boost::mpl::size_t.
#include <boost/container/map.hpp>
#include <boost/container/flat_map.hpp>

#include <boost/concept/traits/query/is_runtime_pair.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

#include <boost/fusion/container/vector.hpp>
#include <boost/fusion/support/pair.hpp>
#include <boost/tuple/tuple.hpp>
#include <utility>

//[test__is_runtime_pair__pairs_and_heterogeneous_containers
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            std::pair<int,int const>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            std::pair<int,int const> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            std::pair<int&,int const&>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            std::pair<int&,int const&> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_runtime_pair<
            boost::tuples::tuple<int&,int const&>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_runtime_pair<
            boost::tuples::tuple<int&,int const&> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_runtime_pair<
            boost::fusion::pair<int&,int const&>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_runtime_pair<
            boost::fusion::pair<int&,int const&> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_runtime_pair<
            boost::fusion::vector<int&,int const&>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_runtime_pair<
            boost::fusion::vector<int&,int const&> const
        >
    ));
}
//]

#include <boost/range/iterator_range.hpp>
#include <boost/range/sub_range.hpp>
#include <boost/range/counting_range.hpp>
#include <boost/range/irange.hpp>
#include <string>
#include <boost/config.hpp>

#if defined BOOST_NO_CX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

//[test__is_runtime_pair__ranges
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            std::pair<
                std::string::const_iterator
              , std::string::const_iterator
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            std::pair<
                std::string::const_iterator
              , std::string::const_iterator
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_runtime_pair<
            boost::iterator_range<std::string::iterator>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_runtime_pair<
            boost::iterator_range<std::string::iterator> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_runtime_pair<
            boost::sub_range<
                std::pair<
                    std::string::const_iterator
                  , std::string::const_iterator
                >
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_runtime_pair<
            boost::sub_range<
                std::pair<
                    std::string::const_iterator
                  , std::string::const_iterator
                >
            > const
        >
    ));
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_runtime_pair<
#if defined BOOST_NO_CX11_DECLTYPE
            BOOST_TYPEOF((boost::counting_range(0, 1)))
#else
            decltype(boost::counting_range(0, 1))
#endif
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_runtime_pair<
#if defined BOOST_NO_CX11_DECLTYPE
            BOOST_TYPEOF((boost::counting_range(0, 1))) const
#else
            decltype(boost::counting_range(0, 1)) const
#endif
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_runtime_pair<
#if defined BOOST_NO_CX11_DECLTYPE
            BOOST_TYPEOF((boost::irange(0, 1)))
#else
            decltype(boost::irange(0, 1))
#endif
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_runtime_pair<
#if defined BOOST_NO_CX11_DECLTYPE
            BOOST_TYPEOF((boost::irange(0, 1))) const
#else
            decltype(boost::irange(0, 1)) const
#endif
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_runtime_pair<
#if defined BOOST_NO_CX11_DECLTYPE
            BOOST_TYPEOF((boost::irange(0, 4, 2)))
#else
            decltype(boost::irange(0, 4, 2))
#endif
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_runtime_pair<
#if defined BOOST_NO_CX11_DECLTYPE
            BOOST_TYPEOF((boost::irange(0, 4, 2))) const
#else
            decltype(boost::irange(0, 4, 2)) const
#endif
        >
    ));
    //->
}
//]

#include <boost/concept/traits/introspection/is_convertible_to_cref_of.hpp>
#include <boost/unordered_map.hpp>
#include <boost/ptr_container/ptr_map.hpp>
#include <boost/ptr_container/ptr_unordered_map.hpp>
#include <boost/mpl/placeholders.hpp>
#include <set>
#include <map>

//[test__is_runtime_pair__value_types
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            std::map<int,int>::value_type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            std::map<int,int>::value_type const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            std::multimap<int,int>::value_type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            std::multimap<int,int>::value_type const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::container::map<int,int>::value_type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::container::map<int,int>::value_type const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::container::multimap<int,int>::value_type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::container::multimap<int,int>::value_type const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::container::flat_map<int,int>::value_type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::container::flat_map<int,int>::value_type const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::container::flat_multimap<int,int>::value_type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::container::flat_multimap<int,int>::value_type const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::unordered::unordered_map<int,int>::value_type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::unordered::unordered_map<int,int>::value_type const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::unordered::unordered_multimap<int,int>::value_type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::unordered::unordered_multimap<int,int>::value_type const
        >
    ));
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_runtime_pair<
            boost::ptr_map<int,int>::value_type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::ptr_map<int,int>::value_type
          , boost::concept::traits::is_convertible_to_cref_of<
                boost::mpl::_
              , boost::ptr_map<int,int>::value_type::first_type
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_runtime_pair<
            boost::ptr_map<int,int>::value_type const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::ptr_map<int,int>::value_type const
          , boost::concept::traits::is_convertible_to_cref_of<
                boost::mpl::_
              , boost::ptr_map<int,int>::value_type::first_type
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_runtime_pair<
            boost::ptr_multimap<int,int>::value_type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::ptr_multimap<int,int>::value_type
          , boost::concept::traits::is_convertible_to_cref_of<
                boost::mpl::_
              , boost::ptr_multimap<int,int>::value_type::first_type
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_runtime_pair<
            boost::ptr_multimap<int,int>::value_type const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::ptr_multimap<int,int>::value_type const
          , boost::concept::traits::is_convertible_to_cref_of<
                boost::mpl::_
              , boost::ptr_multimap<int,int>::value_type::first_type
            >
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_runtime_pair<
            boost::ptr_unordered_map<int,int>::value_type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::ptr_unordered_map<int,int>::value_type
          , boost::concept::traits::is_convertible_to_cref_of<
                boost::mpl::_
              , boost::ptr_unordered_map<int,int>::value_type::first_type
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_runtime_pair<
            boost::ptr_unordered_map<int,int>::value_type const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::ptr_unordered_map<int,int>::value_type const
          , boost::concept::traits::is_convertible_to_cref_of<
                boost::mpl::_
              , boost::ptr_unordered_map<int,int>::value_type::first_type
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_runtime_pair<
            boost::ptr_unordered_multimap<int,int>::value_type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::ptr_unordered_multimap<int,int>::value_type
          , boost::concept::traits::is_convertible_to_cref_of<
                boost::mpl::_
              , boost::ptr_unordered_multimap<int,int>::value_type::first_type
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_runtime_pair<
            boost::ptr_unordered_multimap<int,int>::value_type const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::ptr_unordered_multimap<int,int>::value_type const
          , boost::concept::traits::is_convertible_to_cref_of<
                boost::mpl::_
              , boost::ptr_unordered_multimap<int,int>::value_type::first_type
            >
        >
    ));
    //->
}
//]

#include <boost/bimap.hpp>
#include <boost/bimap/set_of.hpp>
#include <boost/bimap/multiset_of.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include <boost/bimap/unordered_multiset_of.hpp>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map::value_type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::left_map::value_type const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map::value_type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::bimaps::bimap<
                boost::bimaps::set_of<char>
              , boost::bimaps::multiset_of<short>
            >::right_map::value_type const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map::value_type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::left_map::value_type const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map::value_type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            boost::bimaps::bimap<
                boost::bimaps::unordered_set_of<char>
              , boost::bimaps::unordered_multiset_of<short>
            >::right_map::value_type const
        >
    ));
}

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_MAP
#include <unordered_map>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            std::unordered_map<int,int>::value_type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            std::unordered_map<int,int>::value_type const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            std::unordered_multimap<int,int>::value_type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            std::unordered_multimap<int,int>::value_type const
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_UNORDERED_MAP

#if defined BOOST_HAS_TR1_UNORDERED_MAP
#include <boost/tr1/unordered_map.hpp>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            std::tr1::unordered_map<int,int>::value_type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            std::tr1::unordered_map<int,int>::value_type const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            std::tr1::unordered_multimap<int,int>::value_type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_runtime_pair<
            std::tr1::unordered_multimap<int,int>::value_type const
        >
    ));
}
#endif  // BOOST_HAS_TR1_UNORDERED_MAP

