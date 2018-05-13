// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/traits/query/is_math_rational_type.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

//[test__is_math_rational_type__builtin
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<signed char>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<signed char const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<unsigned char>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<unsigned char const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<signed short>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<signed short const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<unsigned short>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<unsigned short const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<signed int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<signed int const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<unsigned int>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<unsigned int const>
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<signed long>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<signed long const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<unsigned long>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<unsigned long const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<float>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<float const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<double>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<double const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<long double>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<long double const>
    ));
    //->
}
//]

#include <complex>

//[test__is_math_rational_type__std_complex
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            std::complex<float>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            std::complex<float> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            std::complex<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            std::complex<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            std::complex<long double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            std::complex<long double> const
        >
    ));
}
//]

#include <boost/multiprecision/cpp_int.hpp>

//[test__is_math_rational_type__multiprecision
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::multiprecision::cpp_int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::multiprecision::cpp_rational
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::multiprecision::uint128_t
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::multiprecision::uint256_t
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::multiprecision::uint512_t
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::multiprecision::uint1024_t
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::multiprecision::int128_t
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::multiprecision::int256_t
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::multiprecision::int512_t
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::multiprecision::int1024_t
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::multiprecision::checked_cpp_int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::multiprecision::checked_cpp_rational
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::multiprecision::checked_uint128_t
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::multiprecision::checked_uint256_t
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::multiprecision::checked_uint512_t
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::multiprecision::checked_uint1024_t
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::multiprecision::checked_int128_t
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::multiprecision::checked_int256_t
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::multiprecision::checked_int512_t
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::multiprecision::checked_int1024_t
        >
    ));
    //->
}
//]

#include <boost/mpl/inherit.hpp>

//[test__is_math_rational_type__minimal
namespace test {

    struct minimal
    {
        typedef int int_type;
        int_type numerator() const;
        int_type denominator() const;
        minimal operator+() const;
        minimal operator+(minimal const&) const;
        minimal& operator+=(minimal const&);
        minimal operator-() const;
        minimal operator-(minimal const&) const;
        minimal& operator-=(minimal const&);
        minimal operator*(minimal const&) const;
        minimal& operator*=(minimal const&);
        minimal operator/(minimal const&) const;
        minimal& operator/=(minimal const&);
        bool operator==(minimal const&) const;
        bool operator!=(minimal const&) const;
        bool operator<(minimal const&) const;
        bool operator>(minimal const&) const;
        bool operator<=(minimal const&) const;
        bool operator>=(minimal const&) const;
    };
}

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_rational_type<test::minimal>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_rational_type<test::minimal const>
    ));
}
//]

#include <boost/concept_archetype.hpp>
#include <boost/concept/archetype/indexable_iterator.hpp>
#include <boost/concept/archetype/mutable_indexable_iterator.hpp>
#include <boost/iterator/iterator_traits.hpp>

//[test__is_math_rational_type__archetypes
MPL_TEST_CASE()
{
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::boolean_archetype
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::boolean_archetype const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::equality_comparable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::equality_comparable_archetype<> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::less_than_comparable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::less_than_comparable_archetype<> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::comparable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::comparable_archetype<> const
        >
    ));
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::addable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::addable_archetype<> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::subtractable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::subtractable_archetype<> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::multipliable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::multipliable_archetype<> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::dividable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::dividable_archetype<> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::modable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::modable_archetype<> const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::void_generator_archetype
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::void_generator_archetype const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::generator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::generator_archetype<char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::unary_function_archetype<short,char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::unary_function_archetype<short,char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::binary_function_archetype<int,short,char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::binary_function_archetype<int,short,char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::input_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::input_iterator_archetype<char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::input_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::input_iterator_archetype_no_proxy<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::input_iterator_archetype_no_proxy<char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::output_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::output_iterator_archetype<char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::input_output_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::input_output_iterator_archetype<char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::forward_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::forward_iterator_archetype<char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::mutable_forward_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::mutable_forward_iterator_archetype<char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::bidirectional_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::bidirectional_iterator_archetype<char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::mutable_bidirectional_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::mutable_bidirectional_iterator_archetype<char> const
        >
    ));
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::concept::indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::concept::indexable_iterator_archetype<char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::concept::mutable_indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::concept::mutable_indexable_iterator_archetype<char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::random_access_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::random_access_iterator_archetype<char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::mutable_random_access_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::mutable_random_access_iterator_archetype<char> const
        >
    ));
}
//]

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>

//[test__is_math_rational_type__std_iterators
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            std::vector<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            std::vector<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            std::deque<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            std::deque<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            std::list<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            std::list<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            std::set<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            std::set<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            std::map<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            std::map<char,char>::const_iterator
        >
    ));
}
//]

#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/vector_sparse.hpp>
#include <boost/numeric/ublas/vector_proxy.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>

//[test__is_math_rational_type__ublas_vectors
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::vector<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::vector<double> const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::unit_vector<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::unit_vector<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::zero_vector<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::zero_vector<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::scalar_vector<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::scalar_vector<double> const
        >
    ));
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::mapped_vector<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::mapped_vector<double> const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::compressed_vector<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::compressed_vector<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::coordinate_vector<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::coordinate_vector<double> const
        >
    ));
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::vector_range<
                boost::numeric::ublas::vector<double>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::vector_range<
                boost::numeric::ublas::vector<double>
            > const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::vector_slice<
                boost::numeric::ublas::vector<double>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::vector_slice<
                boost::numeric::ublas::vector<double>
            > const
        >
    ));
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::matrix_row<
                boost::numeric::ublas::matrix<double>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::matrix_row<
                boost::numeric::ublas::matrix<double>
            > const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::matrix_column<
                boost::numeric::ublas::matrix<double>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::matrix_column<
                boost::numeric::ublas::matrix<double>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::matrix_vector_range<
                boost::numeric::ublas::matrix<double>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::matrix_vector_range<
                boost::numeric::ublas::matrix<double>
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::matrix_vector_slice<
                boost::numeric::ublas::matrix<double>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::matrix_vector_slice<
                boost::numeric::ublas::matrix<double>
            > const
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

//[test__is_math_rational_type__ublas_matrices
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::matrix<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::matrix<double> const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::lower
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::lower
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::upper
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::triangular_matrix<
                double
              , boost::numeric::ublas::upper
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::lower
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::lower
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::upper
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::triangular_adaptor<
                boost::numeric::ublas::matrix<double>
              , boost::numeric::ublas::upper
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::lower
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::lower
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::upper
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::symmetric_matrix<
                double
              , boost::numeric::ublas::upper
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::lower
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::lower
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::upper
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::hermitian_matrix<
                std::complex<double>
              , boost::numeric::ublas::upper
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::lower
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::lower
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::upper
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::hermitian_adaptor<
                boost::numeric::ublas::matrix<std::complex<double> >
              , boost::numeric::ublas::upper
            > const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::banded_matrix<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::banded_matrix<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::banded_adaptor<
                boost::numeric::ublas::matrix<double>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::banded_adaptor<
                boost::numeric::ublas::matrix<double>
            > const
        >
    ));
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::mapped_matrix<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::mapped_matrix<double> const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::compressed_matrix<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::compressed_matrix<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::coordinate_matrix<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::coordinate_matrix<double> const
        >
    ));
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::matrix_range<
                boost::numeric::ublas::matrix<double>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::matrix_range<
                boost::numeric::ublas::matrix<double>
            > const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::matrix_slice<
                boost::numeric::ublas::matrix<double>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::matrix_slice<
                boost::numeric::ublas::matrix<double>
            > const
        >
    ));
    //->
}
//]

#include <boost/numeric/ublas/storage.hpp>

//[test__is_math_rational_type__ublas_storage
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::unbounded_array<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::unbounded_array<double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::bounded_array<double,1>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::bounded_array<double,1> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::range
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::range const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::map_std<int,double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::map_std<int,double> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::ublas::map_array<int,double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
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
#include <utility>

//[test__is_math_rational_type__other
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            std::pair<int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            std::pair<int,int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::logic::tribool
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::logic::tribool const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_rational_type<
            boost::rational<signed int>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_rational_type<
            boost::rational<signed int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::interval<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::numeric::interval<double> const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::math::quaternion<float>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::math::quaternion<float> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::math::octonion<float>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::math::octonion<float> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::function1<char,char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::function1<char,char> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            boost::variant<short,std::pair<int,int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
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
        boost::concept::traits::is_math_rational_type<
            std::function<char(char)>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
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
        boost::concept::traits::is_math_rational_type<
            std::array<char,1>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
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
        boost::concept::traits::is_math_rational_type<
            std::forward_list<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
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
        boost::concept::traits::is_math_rational_type<
            std::unordered_set<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            std::unordered_set<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            std::unordered_multiset<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
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
        boost::concept::traits::is_math_rational_type<
            std::unordered_map<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            std::unordered_map<char,char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            std::unordered_multimap<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_math_rational_type<
            std::unordered_multimap<char,char>::const_iterator
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_UNORDERED_MAP

