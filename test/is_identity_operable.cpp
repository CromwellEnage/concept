// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/traits/query/is_identity_operable.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

//[test__is_identity_operable__builtin
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<signed char>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<signed char const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<unsigned char>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<unsigned char const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<signed short>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<signed short const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<unsigned short>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<unsigned short const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<signed int>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<signed int const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<unsigned int>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<unsigned int const>
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<signed long>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<signed long const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<unsigned long>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<unsigned long const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<float>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<float const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<double>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<double const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<long double>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<long double const>
    ));
    //->
}
//]

#if defined LIBS_CONCEPT_TEST_USE_MULTIPRECISION_NUMERIC_TYPES
#include <boost/multiprecision/cpp_int.hpp>

//[test__is_identity_operable__multiprecision
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::multiprecision::cpp_int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::multiprecision::cpp_rational
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::multiprecision::uint128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::multiprecision::uint256_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::multiprecision::uint512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::multiprecision::uint1024_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::multiprecision::int128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::multiprecision::int256_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::multiprecision::int512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::multiprecision::int1024_t
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::multiprecision::checked_cpp_int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::multiprecision::checked_cpp_rational
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::multiprecision::checked_uint128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::multiprecision::checked_uint256_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::multiprecision::checked_uint512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::multiprecision::checked_uint1024_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::multiprecision::checked_int128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::multiprecision::checked_int256_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::multiprecision::checked_int512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::multiprecision::checked_int1024_t
        >
    ));
    //->
}
//]
#endif  // LIBS_CONCEPT_TEST_USE_MULTIPRECISION_NUMERIC_TYPES

//[test__is_identity_operable__minimal
namespace test {

    struct minimal_1
    {
        minimal_1 operator+() const;
    };

    struct minimal_2
    {
    };

    minimal_2 operator+(minimal_2 const&);

    struct incorrect_1
    {
        incorrect_1 operator+();
    };

    struct incorrect_2
    {
    };

    incorrect_2 operator+(incorrect_2&);
}

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<test::minimal_1>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<test::minimal_2>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<test::incorrect_1>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<test::incorrect_2>
    ));
}
//]

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>

//[test__is_identity_operable__std_iterators
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            std::vector<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            std::vector<char>::const_iterator
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            std::deque<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            std::deque<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            std::list<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            std::list<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            std::set<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            std::set<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            std::map<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            std::map<char,char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            std::multiset<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            std::multiset<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            std::multimap<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
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
#include <complex>
#include <utility>

//[test__is_identity_operable__other
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            std::complex<float>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            std::complex<float> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            std::pair<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            std::pair<int,int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            boost::logic::tribool
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            boost::logic::tribool const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::rational<signed int>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::rational<signed int> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::numeric::interval<double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::numeric::interval<double> const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::math::quaternion<float>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::math::quaternion<float> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::math::octonion<float>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            boost::math::octonion<float> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            boost::function1<char,char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            boost::function1<char,char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            boost::variant<short,std::pair<int,int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            boost::variant<short,std::pair<int,int> > const
        >
    ));
    //->
}
//]

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

//[test__is_identity_operable__dereferenceable_types
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<int*>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<int const*>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<boost::optional<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<boost::weak_ptr<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<boost::scoped_ptr<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<boost::shared_ptr<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            boost::scoped_array<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            boost::shared_array<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            boost::intrusive_ptr<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
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

#if !defined BOOST_NO_CXX11_HDR_FUNCTIONAL
#include <functional>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            std::function<char(char)>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
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
        boost::concept::traits::is_identity_operable<
            std::array<char,1>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_identity_operable<
            std::array<char,1>::const_iterator
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_ARRAY

#if !defined BOOST_NO_CXX11_HDR_FORWARD_LIST
#include <forward_list>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            std::forward_list<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            std::forward_list<char>::const_iterator
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_FORWARD_LIST

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_SET
#include <unordered_set>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            std::unordered_set<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            std::unordered_set<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            std::unordered_multiset<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
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
        boost::concept::traits::is_identity_operable<
            std::unordered_map<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            std::unordered_map<char,char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            std::unordered_multimap<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_identity_operable<
            std::unordered_multimap<char,char>::const_iterator
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_UNORDERED_MAP

