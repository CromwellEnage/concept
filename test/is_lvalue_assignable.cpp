// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/traits/query/is_lvalue_assignable.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

//[test__is_lvalue_assignable__builtin
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<signed char>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<signed char const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<unsigned char>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<unsigned char const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<signed short>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<signed short const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<unsigned short>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<unsigned short const>
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<signed int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<signed int const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<unsigned int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<unsigned int const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<signed long>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<signed long const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<unsigned long>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<unsigned long const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<float>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<float const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<double>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<double const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<long double>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<long double const>
    ));
    //->
}
//]

#include <boost/multiprecision/cpp_int.hpp>

//[test__is_lvalue_assignable__multiprecision
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::multiprecision::cpp_int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::multiprecision::cpp_rational
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::multiprecision::uint128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::multiprecision::uint256_t
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::multiprecision::uint512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::multiprecision::uint1024_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::multiprecision::int128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::multiprecision::int256_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::multiprecision::int512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::multiprecision::int1024_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::multiprecision::checked_cpp_int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::multiprecision::checked_cpp_rational
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::multiprecision::checked_uint128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::multiprecision::checked_uint256_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::multiprecision::checked_uint512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::multiprecision::checked_uint1024_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::multiprecision::checked_int128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::multiprecision::checked_int256_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::multiprecision::checked_int512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::multiprecision::checked_int1024_t
        >
    ));
    //->
}
//]

#include <boost/mpl/inherit.hpp>
#include <boost/core/noncopyable.hpp>
#include <boost/concept_archetype.hpp>

//[test__is_lvalue_assignable__minimal
namespace test {

    struct not_assignable_archetype_const_assignable
    {
        boost::noncopyable unused;
        not_assignable_archetype_const_assignable&
            operator=(boost::assignable_archetype<>&);
    };

    class unassignable
    {
        unassignable& operator=(unassignable const&);
    };
}

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::assignable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::assignable_archetype<>
          , boost::assignable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::assignable_archetype<> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::assignable_archetype<> const
          , boost::assignable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            test::not_assignable_archetype_const_assignable
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            test::not_assignable_archetype_const_assignable
          , boost::assignable_archetype<> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            test::not_assignable_archetype_const_assignable
          , boost::assignable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::mpl::inherit<boost::noncopyable>::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::mpl::inherit<boost::noncopyable>::type
          , boost::mpl::inherit<boost::noncopyable>::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            test::unassignable
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            test::unassignable
          , test::unassignable
        >
    ));
}
//]

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>

//[test__is_lvalue_assignable__std_iterators
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::vector<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            std::vector<char>::iterator
          , std::vector<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::vector<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::vector<char>::const_iterator
          , std::vector<char>::iterator
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::deque<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            std::deque<char>::iterator
          , std::deque<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::deque<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::deque<char>::const_iterator
          , std::deque<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::list<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            std::list<char>::iterator
          , std::list<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::list<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::list<char>::const_iterator
          , std::list<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::set<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::set<char>::iterator
          , std::set<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::set<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::set<char>::const_iterator
          , std::set<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::map<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            std::map<char,char>::iterator
          , std::map<char,char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::map<char,char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::map<char,char>::const_iterator
          , std::map<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::multiset<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::multiset<char>::iterator
          , std::multiset<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::multiset<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::multiset<char>::const_iterator
          , std::multiset<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::multimap<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            std::multimap<char,char>::iterator
          , std::multimap<char,char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::multimap<char,char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::multimap<char,char>::const_iterator
          , std::multimap<char,char>::iterator
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

//[test__is_lvalue_assignable__ublas_vectors
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::vector<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::vector<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::vector<double>
          , boost::numeric::ublas::unit_vector<double> const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::unit_vector<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::unit_vector<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::unit_vector<double>
          , boost::numeric::ublas::zero_vector<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::zero_vector<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::zero_vector<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::zero_vector<double>
          , boost::numeric::ublas::unit_vector<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::scalar_vector<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::scalar_vector<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::scalar_vector<double>
          , boost::numeric::ublas::unit_vector<double> const
        >
    ));
#if defined BOOST_UBLAS_CPP_GE_2011
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::fixed_vector<double,1>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::fixed_vector<double,1> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::fixed_vector<double,1>
          , boost::numeric::ublas::unit_vector<double> const
        >
    ));
#endif
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::bounded_vector<double,1>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::bounded_vector<double,1> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::bounded_vector<double,1>
          , boost::numeric::ublas::unit_vector<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::c_vector<double,1>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::c_vector<double,1> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::c_vector<double,1>
          , boost::numeric::ublas::unit_vector<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::mapped_vector<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::mapped_vector<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::mapped_vector<double>
          , boost::numeric::ublas::unit_vector<double> const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::compressed_vector<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::compressed_vector<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::compressed_vector<double>
          , boost::numeric::ublas::unit_vector<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::coordinate_vector<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::coordinate_vector<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::coordinate_vector<double>
          , boost::numeric::ublas::unit_vector<double> const
        >
    ));
    //->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::vector_range<
                boost::numeric::ublas::vector<double>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::vector_range<
                boost::numeric::ublas::vector<double>
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::vector_range<
                boost::numeric::ublas::vector<double>
            >
          , boost::numeric::ublas::unit_vector<double> const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::vector_slice<
                boost::numeric::ublas::vector<double>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::vector_slice<
                boost::numeric::ublas::vector<double>
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::vector_slice<
                boost::numeric::ublas::vector<double>
            >
          , boost::numeric::ublas::unit_vector<double> const
        >
    ));
    //->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::matrix_row<
                boost::numeric::ublas::matrix<double>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::matrix_row<
                boost::numeric::ublas::matrix<double>
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::matrix_row<
                boost::numeric::ublas::matrix<double>
            >
          , boost::numeric::ublas::unit_vector<double> const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::matrix_column<
                boost::numeric::ublas::matrix<double>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::matrix_column<
                boost::numeric::ublas::matrix<double>
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::matrix_column<
                boost::numeric::ublas::matrix<double>
            >
          , boost::numeric::ublas::unit_vector<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::matrix_vector_range<
                boost::numeric::ublas::matrix<double>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::matrix_vector_range<
                boost::numeric::ublas::matrix<double>
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::matrix_vector_range<
                boost::numeric::ublas::matrix<double>
            >
          , boost::numeric::ublas::unit_vector<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::matrix_vector_slice<
                boost::numeric::ublas::matrix<double>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::matrix_vector_slice<
                boost::numeric::ublas::matrix<double>
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::matrix_vector_slice<
                boost::numeric::ublas::matrix<double>
            >
          , boost::numeric::ublas::unit_vector<double> const
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

//[test__is_lvalue_assignable__ublas_matrices
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::matrix<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::matrix<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::matrix<double>
          , boost::numeric::ublas::identity_matrix<double> const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::identity_matrix<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::identity_matrix<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::identity_matrix<double>
          , boost::numeric::ublas::zero_matrix<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::zero_matrix<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::zero_matrix<double> const
        >
    ));
#if defined BOOST_UBLAS_CPP_GE_2011
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::fixed_matrix<double,1,1>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::fixed_matrix<double,1,1> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::fixed_matrix<double,1,1>
          , boost::numeric::ublas::identity_matrix<double> const
        >
    ));
#endif
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::bounded_matrix<double,1,1>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::bounded_matrix<double,1,1> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::bounded_matrix<double,1,1>
          , boost::numeric::ublas::identity_matrix<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::c_matrix<double,1,1>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::c_matrix<double,1,1> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::c_matrix<double,1,1>
          , boost::numeric::ublas::identity_matrix<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::generalized_vector_of_vector<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::generalized_vector_of_vector<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::generalized_vector_of_vector<double>
          , boost::numeric::ublas::identity_matrix<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::vector_of_vector<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::vector_of_vector<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::vector_of_vector<double>
          , boost::numeric::ublas::identity_matrix<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::zero_matrix<double>
          , boost::numeric::ublas::identity_matrix<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::lower
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::lower
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::lower
            >
          , boost::numeric::ublas::identity_matrix<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::upper
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::upper
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::upper
            >
          , boost::numeric::ublas::identity_matrix<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::lower
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::lower
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::lower
            >
          , boost::numeric::ublas::identity_matrix<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::upper
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::upper
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::upper
            >
          , boost::numeric::ublas::identity_matrix<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::lower
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::lower
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::lower
            >
          , boost::numeric::ublas::identity_matrix<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::upper
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::upper
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::upper
            >
          , boost::numeric::ublas::identity_matrix<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::lower
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::lower
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::lower
            >
          , boost::numeric::ublas::identity_matrix<
                std::complex<double>
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::upper
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::upper
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::upper
            >
          , boost::numeric::ublas::identity_matrix<
                std::complex<double>
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::lower
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::lower
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::lower
            >
          , boost::numeric::ublas::identity_matrix<
                std::complex<double>
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::upper
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::upper
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::upper
            >
          , boost::numeric::ublas::identity_matrix<
                std::complex<double>
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::banded_matrix<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::banded_matrix<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::banded_matrix<double>
          , boost::numeric::ublas::identity_matrix<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::banded_adaptor<
                boost::numeric::ublas::matrix<double>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::banded_adaptor<
                boost::numeric::ublas::matrix<double>
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::banded_adaptor<
                boost::numeric::ublas::matrix<double>
            >
          , boost::numeric::ublas::identity_matrix<double> const
        >
    ));
    //->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::mapped_matrix<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::mapped_matrix<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::mapped_matrix<double>
          , boost::numeric::ublas::identity_matrix<double> const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::compressed_matrix<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::compressed_matrix<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::compressed_matrix<double>
          , boost::numeric::ublas::identity_matrix<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::coordinate_matrix<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::coordinate_matrix<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::coordinate_matrix<double>
          , boost::numeric::ublas::identity_matrix<double> const
        >
    ));
    //->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::matrix_range<
                boost::numeric::ublas::matrix<double>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::matrix_range<
                boost::numeric::ublas::matrix<double>
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::matrix_range<
                boost::numeric::ublas::matrix<double>
            >
          , boost::numeric::ublas::identity_matrix<double> const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::matrix_slice<
                boost::numeric::ublas::matrix<double>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::matrix_slice<
                boost::numeric::ublas::matrix<double>
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::matrix_slice<
                boost::numeric::ublas::matrix<double>
            >
          , boost::numeric::ublas::identity_matrix<double> const
        >
    ));
    //->
}
//]

#include <boost/numeric/ublas/storage.hpp>
#include <boost/numeric/ublas/storage_sparse.hpp>

//[test__is_lvalue_assignable__ublas_storage
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::unbounded_array<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::unbounded_array<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::bounded_array<double,1>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::bounded_array<double,1> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::range
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::range const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::map_std<int,double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::map_std<int,double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::ublas::map_array<int,double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
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
#include <boost/compressed_pair.hpp>
#include <complex>
#include <utility>

//[test__is_lvalue_assignable__other
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::complex<float>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            std::complex<float> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::pair<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            std::pair<int,int> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::compressed_pair<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::compressed_pair<int,int> const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::logic::tribool
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::logic::tribool const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::rational<signed int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::rational<signed int> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::interval<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::numeric::interval<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::math::quaternion<float>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::math::quaternion<float> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::math::quaternion<float>
          , float const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::math::quaternion<float>
          , std::complex<float> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::math::quaternion<float>
          , std::complex<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::math::octonion<float>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::math::octonion<float> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::math::octonion<float>
          , std::complex<float> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::math::octonion<float>
          , std::complex<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::math::octonion<float>
          , boost::math::quaternion<float> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::math::octonion<float>
          , boost::math::quaternion<double> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::function1<char,char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::function1<char,char> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            boost::variant<short,std::pair<int,int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            boost::variant<short,std::pair<int,int> > const
        >
    ));
    //->
}
//]

//[test__is_lvalue_assignable__canonical
#include <boost/config.hpp>

#if !defined BOOST_NO_CXX11_DECLTYPE
namespace test {

    class canonical
    {
     public:
        canonical& operator=(canonical const&)
        {
            return *this;
        }
    };
}

#include <boost/concept/traits/introspection/is_lvalue_reference_of.hpp>
#include <boost/concept/policy/use_default.hpp>
#include <boost/mpl/placeholders.hpp>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            test::canonical
          , boost::concept::policy::use_default
          , boost::concept::traits::is_lvalue_reference_of<
                boost::mpl::_
              , test::canonical
            >
        >
    ));
}
#endif  // BOOST_NO_CXX11_DECLTYPE
//]

#if !defined BOOST_NO_CXX11_HDR_FUNCTIONAL
#include <functional>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::function<char(char)>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
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
        boost::concept::traits::is_lvalue_assignable<
            std::array<char,1>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            std::array<char,1>::iterator
          , std::array<char,1>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::array<char,1>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::array<char,1>::const_iterator
          , std::array<char,1>::iterator
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_ARRAY

#if !defined BOOST_NO_CXX11_HDR_FORWARD_LIST
#include <forward_list>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::forward_list<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            std::forward_list<char>::iterator
          , std::forward_list<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::forward_list<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::forward_list<char>::const_iterator
          , std::forward_list<char>::iterator
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_FORWARD_LIST

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_SET
#include <unordered_set>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::unordered_set<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::unordered_set<char>::iterator
          , std::unordered_set<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::unordered_set<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::unordered_set<char>::const_iterator
          , std::unordered_set<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::unordered_multiset<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::unordered_multiset<char>::iterator
          , std::unordered_multiset<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::unordered_multiset<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::unordered_multiset<char>::const_iterator
          , std::unordered_multiset<char>::iterator
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_UNORDERED_SET

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_MAP
#include <unordered_map>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::unordered_map<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            std::unordered_map<char,char>::iterator
          , std::unordered_map<char,char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::unordered_map<char,char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::unordered_map<char,char>::const_iterator
          , std::unordered_map<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::unordered_multimap<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_lvalue_assignable<
            std::unordered_multimap<char,char>::iterator
          , std::unordered_multimap<char,char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::unordered_multimap<char,char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_assignable<
            std::unordered_multimap<char,char>::const_iterator
          , std::unordered_multimap<char,char>::iterator
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_UNORDERED_MAP

