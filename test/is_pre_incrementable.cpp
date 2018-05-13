// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/traits/query/is_pre_incrementable.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

//[test__is_pre_incrementable__builtin
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<signed char>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<signed char const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<unsigned char>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<unsigned char const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<signed short>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<signed short const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<unsigned short>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<unsigned short const>
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<signed int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<signed int const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<unsigned int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<unsigned int const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<signed long>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<signed long const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<unsigned long>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<unsigned long const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<float>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<float const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<double>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<double const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<long double>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<long double const>
    ));
    //->
}
//]

#include <boost/multiprecision/cpp_int.hpp>

//[test__is_pre_incrementable__multiprecision
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::multiprecision::cpp_int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::multiprecision::cpp_rational
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::multiprecision::uint128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::multiprecision::uint256_t
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::multiprecision::uint512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::multiprecision::uint1024_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::multiprecision::int128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::multiprecision::int256_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::multiprecision::int512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::multiprecision::int1024_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::multiprecision::checked_cpp_int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::multiprecision::checked_cpp_rational
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::multiprecision::checked_uint128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::multiprecision::checked_uint256_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::multiprecision::checked_uint512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::multiprecision::checked_uint1024_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::multiprecision::checked_int128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::multiprecision::checked_int256_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::multiprecision::checked_int512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::multiprecision::checked_int1024_t
        >
    ));
    //->
}
//]

#include <boost/mpl/inherit.hpp>

//[test__is_pre_incrementable__minimal
namespace test {

    struct minimal
    {
        minimal& operator++();
    };

    struct okay
    {
        okay& operator++() const;
    };

    struct failure
    {
        failure operator++();
    };
}

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<test::minimal>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<test::minimal const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::mpl::inherit<test::minimal>::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            boost::mpl::inherit<test::minimal>::type const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<test::okay>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<test::okay const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<test::failure>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<test::failure const>
    ));
}
//]

#include <boost/concept_archetype.hpp>
#include <boost/concept/archetype/indexable_iterator.hpp>
#include <boost/concept/archetype/mutable_indexable_iterator.hpp>

//[test__is_pre_incrementable__archetypes
MPL_TEST_CASE()
{
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            boost::boolean_archetype
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            boost::equality_comparable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            boost::less_than_comparable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            boost::comparable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            boost::addable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            boost::subtractable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            boost::multipliable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            boost::dividable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            boost::modable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            boost::void_generator_archetype
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            boost::generator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            boost::unary_function_archetype<short,char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            boost::binary_function_archetype<int,short,char>
        >
    ));
    //->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::input_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::input_iterator_archetype_no_proxy<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::output_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::input_output_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::forward_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::mutable_forward_iterator_archetype<char>
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::bidirectional_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::mutable_bidirectional_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::concept::indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::concept::mutable_indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::random_access_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::mutable_random_access_iterator_archetype<char>
        >
    ));
    //->
}
//]

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>

//[test__is_pre_incrementable__std_iterators
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            std::vector<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            std::vector<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            std::deque<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            std::deque<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            std::list<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            std::list<char>::const_iterator
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            std::set<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            std::set<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            std::map<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            std::map<char,char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            std::multiset<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            std::multiset<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            std::multimap<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            std::multimap<char,char>::const_iterator
        >
    ));
    //->
}
//]

#include <boost/logic/tribool.hpp>
#include <boost/rational.hpp>
#include <boost/numeric/interval/utility_fwd.hpp>
#include <boost/numeric/interval.hpp>
#include <boost/math/quaternion.hpp>
#include <boost/math/octonion.hpp>
#include <boost/function.hpp>
#include <boost/variant.hpp>
#include <boost/compressed_pair.hpp>
#include <complex>
#include <utility>

//[test__is_pre_incrementable__other
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            std::complex<float>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            std::complex<float> const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            std::pair<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            std::pair<int,int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            boost::compressed_pair<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            boost::compressed_pair<int,int> const
        >
    ));
    //->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            boost::rational<signed int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            boost::rational<signed int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            boost::numeric::interval<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            boost::numeric::interval<double> const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            boost::math::quaternion<float>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            boost::math::quaternion<float> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            boost::math::octonion<float>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            boost::math::octonion<float> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            boost::function1<char,char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            boost::function1<char,char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            boost::variant<short,std::pair<int,int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            boost::variant<short,std::pair<int,int> > const
        >
    ));
    //->
}
//]

#include <boost/config.hpp>

#if !defined BOOST_NO_CXX11_HDR_FUNCTIONAL
#include <functional>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            std::function<char(char)>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_pre_incrementable<
            std::function<char(char)> const
        >
    ));
}
#endif

#if !defined BOOST_NO_CXX11_HDR_ARRAY
#include <array>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            std::array<char,1>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            std::array<char,1>::const_iterator
        >
    ));
}
#endif

#if !defined BOOST_NO_CXX11_HDR_FORWARD_LIST
#include <forward_list>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            std::forward_list<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            std::forward_list<char>::const_iterator
        >
    ));
}
#endif

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_SET
#include <unordered_set>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            std::unordered_set<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            std::unordered_set<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            std::unordered_multiset<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            std::unordered_multiset<char>::const_iterator
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_UNORDERED_SET

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_MAP
#include <unordered_map>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            std::unordered_map<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            std::unordered_map<char,char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            std::unordered_multimap<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_pre_incrementable<
            std::unordered_multimap<char,char>::const_iterator
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_UNORDERED_MAP

