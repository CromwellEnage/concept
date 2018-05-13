// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/traits/query/is_boolean_expression.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

//[test__is_boolean_expression__builtin
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<signed char>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<signed char const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<unsigned char>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<unsigned char const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<signed short>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<signed short const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<unsigned short>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<unsigned short const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<signed int>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<signed int const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<unsigned int>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<unsigned int const>
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<signed long>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<signed long const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<unsigned long>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<unsigned long const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<float>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<float const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<double>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<double const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<long double>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<long double const>
    ));
    //->
}
//]

#include <boost/multiprecision/cpp_int.hpp>

//[test__is_boolean_expression__multiprecision
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::multiprecision::cpp_int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::multiprecision::cpp_rational
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::multiprecision::uint128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::multiprecision::uint256_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::multiprecision::uint512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::multiprecision::uint1024_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::multiprecision::int128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::multiprecision::int256_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::multiprecision::int512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::multiprecision::int1024_t
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::multiprecision::checked_cpp_int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::multiprecision::checked_cpp_rational
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::multiprecision::checked_uint128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::multiprecision::checked_uint256_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::multiprecision::checked_uint512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::multiprecision::checked_uint1024_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::multiprecision::checked_int128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::multiprecision::checked_int256_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::multiprecision::checked_int512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::multiprecision::checked_int1024_t
        >
    ));
    //->
}
//]

#include <boost/concept_archetype.hpp>
#include <boost/concept/archetype/indexable_iterator.hpp>
#include <boost/concept/archetype/mutable_indexable_iterator.hpp>

//[test__is_boolean_expression__archetypes
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::boolean_archetype
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::equality_comparable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::less_than_comparable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::comparable_archetype<>
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::addable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::subtractable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::multipliable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::dividable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::modable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::void_generator_archetype
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::generator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::unary_function_archetype<short,char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::binary_function_archetype<int,short,char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::input_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::input_iterator_archetype_no_proxy<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::output_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::input_output_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::forward_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::mutable_forward_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::bidirectional_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::mutable_bidirectional_iterator_archetype<char>
        >
    ));
    //->
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::concept::indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::concept::mutable_indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::random_access_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
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

//[test__is_boolean_expression__std_iterators
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            std::vector<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            std::vector<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            std::deque<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            std::deque<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            std::list<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            std::list<char>::const_iterator
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            std::set<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            std::set<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            std::map<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            std::map<char,char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            std::multiset<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            std::multiset<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            std::multimap<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
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

//[test__is_boolean_expression__other
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            std::complex<float>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            std::complex<float> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            std::pair<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            std::pair<int,int> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::logic::tribool
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::logic::tribool const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::rational<signed int>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::rational<signed int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::numeric::interval<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::numeric::interval<double> const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::math::quaternion<float>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::math::quaternion<float> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::math::octonion<float>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::math::octonion<float> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::function1<char,char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::function1<char,char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            boost::variant<short,std::pair<int,int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
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
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

//[test__is_boolean_expression__dereferenceable_types
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<int*>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<int const*>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<boost::optional<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<boost::weak_ptr<int> >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<boost::scoped_ptr<int> >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<boost::shared_ptr<int> >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::scoped_array<int>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::shared_array<int>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            boost::intrusive_ptr<int>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
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
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            std::function<char(char)>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            std::function<char(char)> const
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_FUNCTIONAL

#if !defined BOOST_NO_CXX11_HDR_ARRAY
#include <array>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
            std::array<char,1>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_boolean_expression<
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
        boost::concept::traits::is_boolean_expression<
            std::forward_list<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
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
        boost::concept::traits::is_boolean_expression<
            std::unordered_set<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            std::unordered_set<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            std::unordered_multiset<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
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
        boost::concept::traits::is_boolean_expression<
            std::unordered_map<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            std::unordered_map<char,char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            std::unordered_multimap<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_boolean_expression<
            std::unordered_multimap<char,char>::const_iterator
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_UNORDERED_MAP

