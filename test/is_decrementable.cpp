// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/traits/query/is_decrementable.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

//[test__is_decrementable__builtin
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<signed char>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<signed char const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<unsigned char>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<unsigned char const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<signed short>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<signed short const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<unsigned short>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<unsigned short const>
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<signed int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<signed int const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<unsigned int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<unsigned int const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<signed long>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<signed long const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<unsigned long>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<unsigned long const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<float>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<float const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<double>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<double const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<long double>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<long double const>
    ));
    //->
}
//]

#include <boost/multiprecision/cpp_int.hpp>

//[test__is_decrementable__multiprecision
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::multiprecision::cpp_int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::multiprecision::cpp_rational
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::multiprecision::uint128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::multiprecision::uint256_t
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::multiprecision::uint512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::multiprecision::uint1024_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::multiprecision::int128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::multiprecision::int256_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::multiprecision::int512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::multiprecision::int1024_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::multiprecision::checked_cpp_int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::multiprecision::checked_cpp_rational
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::multiprecision::checked_uint128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::multiprecision::checked_uint256_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::multiprecision::checked_uint512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::multiprecision::checked_uint1024_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::multiprecision::checked_int128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::multiprecision::checked_int256_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::multiprecision::checked_int512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::multiprecision::checked_int1024_t
        >
    ));
    //->
}
//]

#include <boost/mpl/inherit.hpp>

//[test__is_decrementable__minimal
namespace test {

    struct minimal
    {
        minimal& operator--();
        void operator--(int);
    };

    struct okay
    {
        okay& operator--() const;
        okay& operator--(int) const;
    };

    struct failure
    {
        failure operator--();
        failure& operator--(int);
    };
}

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<test::minimal>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<test::minimal const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::mpl::inherit<test::minimal>::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::mpl::inherit<test::minimal>::type const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<test::okay>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<test::okay const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<test::failure>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<test::failure const>
    ));
}
//]

#include <boost/concept_archetype.hpp>
#include <boost/concept/archetype/indexable_iterator.hpp>
#include <boost/concept/archetype/mutable_indexable_iterator.hpp>

//[test__is_decrementable__archetypes
MPL_TEST_CASE()
{
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::boolean_archetype
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::equality_comparable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::less_than_comparable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::comparable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::addable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::subtractable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::multipliable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::dividable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::modable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::void_generator_archetype
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::generator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::unary_function_archetype<short,char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::binary_function_archetype<int,short,char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::input_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::input_iterator_archetype_no_proxy<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::output_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::input_output_iterator_archetype<char>
        >
    ));
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::forward_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::mutable_forward_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::bidirectional_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::mutable_bidirectional_iterator_archetype<char>
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::concept::indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::concept::mutable_indexable_iterator_archetype<char>
        >
    ));
    //->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::random_access_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::mutable_random_access_iterator_archetype<char>
        >
    ));
}
//]

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>

//[test__is_decrementable__std_iterators
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            std::vector<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            std::vector<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            std::deque<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            std::deque<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            std::list<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            std::list<char>::const_iterator
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            std::set<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            std::set<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            std::map<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            std::map<char,char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            std::multiset<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            std::multiset<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            std::multimap<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
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

//[test__is_decrementable__other
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            std::complex<float>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            std::complex<float> const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            std::pair<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            std::pair<int,int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::compressed_pair<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::compressed_pair<int,int> const
        >
    ));
    //->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            boost::rational<signed int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::rational<signed int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::numeric::interval<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::numeric::interval<double> const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::math::quaternion<float>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::math::quaternion<float> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::math::octonion<float>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::math::octonion<float> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::function1<char,char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::function1<char,char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            boost::variant<short,std::pair<int,int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
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
        boost::concept::traits::is_decrementable<
            std::function<char(char)>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
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
        boost::concept::traits::is_decrementable<
            std::array<char,1>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_decrementable<
            std::array<char,1>::const_iterator
        >
    ));
}
#endif

#if !defined BOOST_NO_CXX11_HDR_FORWARD_LIST
#include <forward_list>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            std::forward_list<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            std::forward_list<char>::const_iterator
        >
    ));
}
#endif

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_SET
#include <unordered_set>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            std::unordered_set<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            std::unordered_set<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            std::unordered_multiset<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            std::unordered_multiset<char>::const_iterator
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_UNORDERED_SET

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_MAP
#include <unordered_map>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            std::unordered_map<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            std::unordered_map<char,char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            std::unordered_multimap<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_decrementable<
            std::unordered_multimap<char,char>::const_iterator
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_UNORDERED_MAP

