// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/traits/query/is_multiplicative.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

//[test__is_multiplicative__builtin
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<signed char>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<signed char const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<unsigned char>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<unsigned char const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<signed short>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<signed short const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<unsigned short>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<unsigned short const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<signed int>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<signed int const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<unsigned int>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<unsigned int const>
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<signed long>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<signed long const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<unsigned long>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<unsigned long const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<float>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<float const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<double>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<double const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<long double>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<long double const>
    ));
    //->
}
//]

#include <boost/multiprecision/cpp_int.hpp>

//[test__is_multiplicative__multiprecision
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::multiprecision::cpp_int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::multiprecision::cpp_rational
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::multiprecision::uint128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::multiprecision::uint256_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::multiprecision::uint512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::multiprecision::uint1024_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::multiprecision::int128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::multiprecision::int256_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::multiprecision::int512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::multiprecision::int1024_t
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::multiprecision::checked_cpp_int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::multiprecision::checked_cpp_rational
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::multiprecision::checked_uint128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::multiprecision::checked_uint256_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::multiprecision::checked_uint512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::multiprecision::checked_uint1024_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::multiprecision::checked_int128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::multiprecision::checked_int256_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::multiprecision::checked_int512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::multiprecision::checked_int1024_t
        >
    ));
    //->
}
//]

#include <boost/mpl/inherit.hpp>

//[test__is_multiplicative__minimal
namespace test {

    struct minimal
    {
        minimal operator*(minimal const&) const;
        minimal operator/(minimal const&) const;
        minimal& operator*=(minimal const&);
        minimal& operator/=(minimal const&);
    };

    struct mini_multiplicative
    {
    };

    struct mini_quotient
    {
        mini_multiplicative operator*(mini_multiplicative const&) const;
    };

    mini_multiplicative
        operator*(mini_multiplicative const&, mini_quotient const&);

    mini_multiplicative
        operator/(mini_multiplicative const&, mini_quotient const&);

    mini_quotient
        operator/(mini_multiplicative const&, mini_multiplicative const&);

    mini_multiplicative&
        operator*=(mini_multiplicative&, mini_quotient const&);

    mini_multiplicative&
        operator/=(mini_multiplicative&, mini_quotient const&);

    struct failure
    {
        failure operator*(failure&);
        failure operator/(failure&);
    };
}

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<test::minimal>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<test::minimal const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::mpl::inherit<test::minimal>::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::mpl::inherit<test::minimal>::type const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            test::minimal
          , boost::mpl::inherit<test::minimal>::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            test::minimal const
          , boost::mpl::inherit<test::minimal>::type const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::mpl::inherit<test::minimal>::type
          , test::minimal
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::mpl::inherit<test::minimal>::type const
          , test::minimal const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            test::mini_multiplicative
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            test::mini_multiplicative const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            test::mini_multiplicative
          , test::mini_quotient
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            test::mini_multiplicative const
          , test::mini_quotient const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<test::failure>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<test::failure const>
    ));
}
//]

#include <boost/concept_archetype.hpp>
#include <boost/concept/archetype/indexable_iterator.hpp>
#include <boost/concept/archetype/mutable_indexable_iterator.hpp>
#include <boost/iterator/iterator_traits.hpp>

//[test__is_multiplicative__archetypes
MPL_TEST_CASE()
{
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::boolean_archetype
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::boolean_archetype const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::equality_comparable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::equality_comparable_archetype<> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::less_than_comparable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::less_than_comparable_archetype<> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::comparable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::comparable_archetype<> const
        >
    ));
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::addable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::addable_archetype<> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::subtractable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::subtractable_archetype<> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::multipliable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::multipliable_archetype<> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::dividable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::dividable_archetype<> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::modable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::modable_archetype<> const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::void_generator_archetype
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::void_generator_archetype const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::generator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::generator_archetype<char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::unary_function_archetype<short,char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::unary_function_archetype<short,char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::binary_function_archetype<int,short,char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::binary_function_archetype<int,short,char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::input_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::input_iterator_archetype<char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::input_iterator_archetype<char>
          , boost::iterators::iterator_difference<
                boost::input_iterator_archetype<char>
            >::type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::input_iterator_archetype_no_proxy<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::input_iterator_archetype_no_proxy<char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::input_iterator_archetype_no_proxy<char>
          , boost::iterators::iterator_difference<
                boost::input_iterator_archetype_no_proxy<char>
            >::type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::output_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::output_iterator_archetype<char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::output_iterator_archetype<char>
          , boost::iterators::iterator_difference<
                boost::output_iterator_archetype<char>
            >::type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::input_output_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::input_output_iterator_archetype<char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::input_output_iterator_archetype<char>
          , boost::iterators::iterator_difference<
                boost::input_output_iterator_archetype<char>
            >::type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::forward_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::forward_iterator_archetype<char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::forward_iterator_archetype<char>
          , boost::iterators::iterator_difference<
                boost::forward_iterator_archetype<char>
            >::type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::mutable_forward_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::mutable_forward_iterator_archetype<char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::mutable_forward_iterator_archetype<char>
          , boost::iterators::iterator_difference<
                boost::mutable_forward_iterator_archetype<char>
            >::type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::bidirectional_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::bidirectional_iterator_archetype<char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::bidirectional_iterator_archetype<char>
          , boost::iterators::iterator_difference<
                boost::bidirectional_iterator_archetype<char>
            >::type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::mutable_bidirectional_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::mutable_bidirectional_iterator_archetype<char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::mutable_bidirectional_iterator_archetype<char>
          , boost::iterators::iterator_difference<
                boost::mutable_bidirectional_iterator_archetype<char>
            >::type const
        >
    ));
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::concept::indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::concept::indexable_iterator_archetype<char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::concept::indexable_iterator_archetype<char>
          , boost::iterators::iterator_difference<
                boost::concept::indexable_iterator_archetype<char>
            >::type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::concept::mutable_indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::concept::mutable_indexable_iterator_archetype<char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::concept::mutable_indexable_iterator_archetype<char>
          , boost::iterators::iterator_difference<
                boost::concept::mutable_indexable_iterator_archetype<char>
            >::type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::random_access_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::random_access_iterator_archetype<char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::random_access_iterator_archetype<char>
          , boost::iterators::iterator_difference<
                boost::random_access_iterator_archetype<char>
            >::type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::mutable_random_access_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::mutable_random_access_iterator_archetype<char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::mutable_random_access_iterator_archetype<char>
          , boost::iterators::iterator_difference<
                boost::mutable_random_access_iterator_archetype<char>
            >::type const
        >
    ));
}
//]

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>

//[test__is_multiplicative__std_iterators
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::vector<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::vector<char>::iterator
          , boost::iterators::iterator_difference<
                std::vector<char>::iterator
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::vector<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::vector<char>::const_iterator
          , boost::iterators::iterator_difference<
                std::vector<char>::const_iterator
            >::type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::deque<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::deque<char>::iterator
          , boost::iterators::iterator_difference<
                std::deque<char>::iterator
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::deque<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::deque<char>::const_iterator
          , boost::iterators::iterator_difference<
                std::deque<char>::const_iterator
            >::type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::list<char>::iterator
          , boost::iterators::iterator_difference<
                std::list<char>::iterator
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::list<char>::const_iterator
          , boost::iterators::iterator_difference<
                std::list<char>::const_iterator
            >::type const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::set<char>::iterator
          , boost::iterators::iterator_difference<
                std::set<char>::iterator
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::set<char>::const_iterator
          , boost::iterators::iterator_difference<
                std::set<char>::const_iterator
            >::type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::map<char,char>::iterator
          , boost::iterators::iterator_difference<
                std::map<char,char>::iterator
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::map<char,char>::const_iterator
          , boost::iterators::iterator_difference<
                std::map<char,char>::const_iterator
            >::type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::multiset<char>::iterator
          , boost::iterators::iterator_difference<
                std::multiset<char>::iterator
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::multiset<char>::const_iterator
          , boost::iterators::iterator_difference<
                std::multiset<char>::const_iterator
            >::type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::multimap<char,char>::iterator
          , boost::iterators::iterator_difference<
                std::multimap<char,char>::iterator
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::multimap<char,char>::const_iterator
          , boost::iterators::iterator_difference<
                std::multimap<char,char>::const_iterator
            >::type const
        >
    ));
    //->
}
//]

#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/vector_sparse.hpp>
#include <boost/numeric/ublas/vector_proxy.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>

//[test__is_multiplicative__ublas_vectors
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::vector<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::vector<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::vector<double>
          , boost::numeric::ublas::vector<double>::value_type const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::unit_vector<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::unit_vector<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::unit_vector<double>
          , boost::numeric::ublas::unit_vector<double>::value_type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::zero_vector<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::zero_vector<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::zero_vector<double>
          , boost::numeric::ublas::zero_vector<double>::value_type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::scalar_vector<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::scalar_vector<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::scalar_vector<double>
          , boost::numeric::ublas::scalar_vector<double>::value_type const
        >
    ));
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::mapped_vector<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::mapped_vector<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::mapped_vector<double>
          , boost::numeric::ublas::mapped_vector<double>::value_type const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::compressed_vector<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::compressed_vector<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::compressed_vector<double>
          , boost::numeric::ublas::compressed_vector<double>::value_type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::coordinate_vector<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::coordinate_vector<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::coordinate_vector<double>
          , boost::numeric::ublas::coordinate_vector<double>::value_type const
        >
    ));
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::vector_range<
                boost::numeric::ublas::vector<double>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::vector_range<
                boost::numeric::ublas::vector<double>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::vector_range<
                boost::numeric::ublas::vector<double>
            >
          , boost::numeric::ublas::vector_range<
                boost::numeric::ublas::vector<double>
            >::value_type const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::vector_slice<
                boost::numeric::ublas::vector<double>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::vector_slice<
                boost::numeric::ublas::vector<double>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::vector_slice<
                boost::numeric::ublas::vector<double>
            >
          , boost::numeric::ublas::vector_slice<
                boost::numeric::ublas::vector<double>
            >::value_type const
        >
    ));
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::matrix_row<
                boost::numeric::ublas::matrix<double>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::matrix_row<
                boost::numeric::ublas::matrix<double>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::matrix_row<
                boost::numeric::ublas::matrix<double>
            >
          , boost::numeric::ublas::matrix_row<
                boost::numeric::ublas::matrix<double>
            >::value_type const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::matrix_column<
                boost::numeric::ublas::matrix<double>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::matrix_column<
                boost::numeric::ublas::matrix<double>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::matrix_column<
                boost::numeric::ublas::matrix<double>
            >
          , boost::numeric::ublas::matrix_column<
                boost::numeric::ublas::matrix<double>
            >::value_type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::matrix_vector_range<
                boost::numeric::ublas::matrix<double>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::matrix_vector_range<
                boost::numeric::ublas::matrix<double>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::matrix_vector_range<
                boost::numeric::ublas::matrix<double>
            >
          , boost::numeric::ublas::matrix_vector_range<
                boost::numeric::ublas::matrix<double>
            >::value_type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::matrix_vector_slice<
                boost::numeric::ublas::matrix<double>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::matrix_vector_slice<
                boost::numeric::ublas::matrix<double>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::matrix_vector_slice<
                boost::numeric::ublas::matrix<double>
            >
          , boost::numeric::ublas::matrix_vector_slice<
                boost::numeric::ublas::matrix<double>
            >::value_type const
        >
    ));
    //->
}
//]

#include <boost/numeric/ublas/triangular.hpp>
#include <boost/numeric/ublas/symmetric.hpp>
#include <boost/numeric/ublas/hermitian.hpp>
#include <boost/numeric/ublas/banded.hpp>
#include <boost/numeric/ublas/matrix_sparse.hpp>

//[test__is_multiplicative__ublas_matrices
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::matrix<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::matrix<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::matrix<double>
          , boost::numeric::ublas::matrix<double>::value_type const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::lower
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::lower
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::lower
            >
          , boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::lower
            >::value_type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::upper
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::upper
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::upper
            >
          , boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::upper
            >::value_type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::lower
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::lower
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::lower
            >
          , boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::lower
            >::value_type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::upper
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::upper
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::upper
            >
          , boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::upper
            >::value_type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::lower
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::lower
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::lower
            >
          , boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::lower
            >::value_type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::upper
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::upper
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::upper
            >
          , boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::upper
            >::value_type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::lower
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::lower
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::lower
            >
          , boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::lower
            >::value_type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::upper
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::upper
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::upper
            >
          , boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::upper
            >::value_type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::lower
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::lower
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::lower
            >
          , boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::lower
            >::value_type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::upper
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::upper
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::upper
            >
          , boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::upper
            >::value_type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::banded_matrix<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::banded_matrix<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::banded_matrix<double>
          , boost::numeric::ublas::banded_matrix<double>::value_type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::banded_adaptor<
                boost::numeric::ublas::matrix<double>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::banded_adaptor<
                boost::numeric::ublas::matrix<double>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::banded_adaptor<
                boost::numeric::ublas::matrix<double>
            >
          , boost::numeric::ublas::banded_adaptor<
                boost::numeric::ublas::matrix<double>
            >::value_type const
        >
    ));
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::mapped_matrix<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::mapped_matrix<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::mapped_matrix<double>
          , boost::numeric::ublas::mapped_matrix<double>::value_type const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::compressed_matrix<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::compressed_matrix<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::compressed_matrix<double>
          , boost::numeric::ublas::compressed_matrix<double>::value_type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::coordinate_matrix<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::coordinate_matrix<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::coordinate_matrix<double>
          , boost::numeric::ublas::coordinate_matrix<double>::value_type const
        >
    ));
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::matrix_range<
                boost::numeric::ublas::matrix<double>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::matrix_range<
                boost::numeric::ublas::matrix<double>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::matrix_range<
                boost::numeric::ublas::matrix<double>
            >
          , boost::numeric::ublas::matrix_range<
                boost::numeric::ublas::matrix<double>
            >::value_type const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::matrix_slice<
                boost::numeric::ublas::matrix<double>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::matrix_slice<
                boost::numeric::ublas::matrix<double>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::matrix_slice<
                boost::numeric::ublas::matrix<double>
            >
          , boost::numeric::ublas::matrix_slice<
                boost::numeric::ublas::matrix<double>
            >::value_type const
        >
    ));
    //->
}
//]

#include <boost/numeric/ublas/storage.hpp>
#include <boost/numeric/ublas/storage_sparse.hpp>

//[test__is_multiplicative__ublas_storage
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::unbounded_array<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::unbounded_array<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::bounded_array<double,1>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::bounded_array<double,1> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::range
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::range const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::map_std<int,double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::map_std<int,double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::map_array<int,double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::ublas::map_array<int,double> const
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

//[test__is_multiplicative__other
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            std::complex<float>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            std::complex<float> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::pair<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::pair<int,int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::logic::tribool
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::logic::tribool const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::rational<signed int>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::rational<signed int> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::interval<double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::numeric::interval<double> const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::math::quaternion<float>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::math::quaternion<float> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::math::quaternion<float>
          , float const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::math::quaternion<float>
          , std::complex<float> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::math::quaternion<float>
          , std::complex<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::math::octonion<float>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_multiplicative<
            boost::math::octonion<float> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::math::octonion<float>
          , float const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::math::octonion<float>
          , std::complex<float> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::math::octonion<float>
          , std::complex<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::math::octonion<float>
          , boost::math::quaternion<float> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::math::octonion<float>
          , boost::math::quaternion<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::function1<char,char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::function1<char,char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            boost::variant<short,std::pair<int,int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
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
        boost::concept::traits::is_multiplicative<
            std::function<char(char)>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::function<char(char)> const
        >
    ));
}
#endif

#if !defined BOOST_NO_CXX11_HDR_ARRAY
#include <array>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::array<char,1>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::array<char,1>::iterator
          , boost::iterators::iterator_difference<
                std::array<char,1>::iterator
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::array<char,1>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::array<char,1>::const_iterator
          , boost::iterators::iterator_difference<
                std::array<char,1>::const_iterator
            >::type const
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_ARRAY

#if !defined BOOST_NO_CXX11_HDR_FORWARD_LIST
#include <forward_list>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::forward_list<char>::iterator
          , boost::iterators::iterator_difference<
                std::forward_list<char>::iterator
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::forward_list<char>::const_iterator
          , boost::iterators::iterator_difference<
                std::forward_list<char>::const_iterator
            >::type const
        >
    ));
}
#endif

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_SET
#include <unordered_set>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::unordered_set<char>::iterator
          , boost::iterators::iterator_difference<
                std::unordered_set<char>::iterator
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::unordered_set<char>::const_iterator
          , boost::iterators::iterator_difference<
                std::unordered_set<char>::const_iterator
            >::type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::unordered_multiset<char>::iterator
          , boost::iterators::iterator_difference<
                std::unordered_multiset<char>::iterator
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::unordered_multiset<char>::const_iterator
          , boost::iterators::iterator_difference<
                std::unordered_multiset<char>::const_iterator
            >::type const
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_UNORDERED_SET

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_MAP
#include <unordered_map>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::unordered_map<char,char>::iterator
          , boost::iterators::iterator_difference<
                std::unordered_map<char,char>::iterator
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::unordered_map<char,char>::const_iterator
          , boost::iterators::iterator_difference<
                std::unordered_map<char,char>::const_iterator
            >::type const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::unordered_multimap<char,char>::iterator
          , boost::iterators::iterator_difference<
                std::unordered_multimap<char,char>::iterator
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_multiplicative<
            std::unordered_multimap<char,char>::const_iterator
          , boost::iterators::iterator_difference<
                std::unordered_multimap<char,char>::const_iterator
            >::type const
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_UNORDERED_MAP

