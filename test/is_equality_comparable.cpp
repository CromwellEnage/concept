// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/traits/query/is_equality_comparable.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

//[test__is_equality_comparable__builtin
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<signed char>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<signed char const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<unsigned char>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<unsigned char const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<signed short>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<signed short const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<unsigned short>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<unsigned short const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<signed int>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<signed int const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<unsigned int>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<unsigned int const>
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<signed long>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<signed long const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<unsigned long>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<unsigned long const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<float>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<float const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<double>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<double const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<long double>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<long double const>
    ));
    //->
}
//]

#include <boost/multiprecision/cpp_int.hpp>

//[test__is_equality_comparable__multiprecision
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::multiprecision::cpp_int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::multiprecision::cpp_rational
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::multiprecision::uint128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::multiprecision::uint256_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::multiprecision::uint512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::multiprecision::uint1024_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::multiprecision::int128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::multiprecision::int256_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::multiprecision::int512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::multiprecision::int1024_t
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::multiprecision::checked_cpp_int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::multiprecision::checked_cpp_rational
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::multiprecision::checked_uint128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::multiprecision::checked_uint256_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::multiprecision::checked_uint512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::multiprecision::checked_uint1024_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::multiprecision::checked_int128_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::multiprecision::checked_int256_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::multiprecision::checked_int512_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::multiprecision::checked_int1024_t
        >
    ));
    //->
}
//]

#include <boost/mpl/inherit.hpp>

//[test__is_equality_comparable__minimal
namespace test {

    struct minimal
    {
        bool operator==(minimal const&) const;
    };

    bool operator!=(minimal const&, minimal const&);
}

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<test::minimal>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<test::minimal const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::mpl::inherit<test::minimal>::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::mpl::inherit<test::minimal>::type const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            test::minimal
          , boost::mpl::inherit<test::minimal>::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            test::minimal const
          , boost::mpl::inherit<test::minimal>::type const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::mpl::inherit<test::minimal>::type
          , test::minimal
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::mpl::inherit<test::minimal>::type const
          , test::minimal const
        >
    ));
}
//]

#include <boost/concept_archetype.hpp>
#include <boost/concept/archetype/indexable_iterator.hpp>
#include <boost/concept/archetype/mutable_indexable_iterator.hpp>

//[test__is_equality_comparable__archetypes
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::boolean_archetype
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::equality_comparable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_equality_comparable<
            boost::less_than_comparable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_equality_comparable<
            boost::comparable_archetype<>
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_equality_comparable<
            boost::addable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_equality_comparable<
            boost::subtractable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_equality_comparable<
            boost::multipliable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_equality_comparable<
            boost::dividable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_equality_comparable<
            boost::modable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_equality_comparable<
            boost::void_generator_archetype
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_equality_comparable<
            boost::generator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_equality_comparable<
            boost::unary_function_archetype<short,char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_equality_comparable<
            boost::binary_function_archetype<int,short,char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::input_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::input_iterator_archetype_no_proxy<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::output_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::input_output_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::forward_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::mutable_forward_iterator_archetype<char>
        >
    ));
    //->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::bidirectional_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::mutable_bidirectional_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::concept::indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::concept::mutable_indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random_access_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
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

//[test__is_equality_comparable__std_iterators
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::vector<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::vector<char>::iterator
          , std::vector<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::vector<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::deque<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::deque<char>::iterator
          , std::deque<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::deque<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::list<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::list<char>::iterator
          , std::list<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::list<char>::const_iterator
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::set<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::set<char>::iterator
          , std::set<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::set<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::map<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::map<char,char>::iterator
          , std::map<char,char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::map<char,char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::multiset<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::multiset<char>::iterator
          , std::multiset<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::multiset<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::multimap<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::multimap<char,char>::iterator
          , std::multimap<char,char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::multimap<char,char>::const_iterator
        >
    ));
    //->
}
//]

#include <boost/random.hpp>

//[test__is_equality_comparable__boost_random
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::minstd_rand0
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::minstd_rand
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::rand48
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::ecuyer1988
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::knuth_b
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::kreutzer1986
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::taus88
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::hellekalek1995
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::mt11213b
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::mt19937
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::mt19937_64
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::lagged_fibonacci607
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::lagged_fibonacci1279
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::lagged_fibonacci2281
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::lagged_fibonacci3217
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::lagged_fibonacci4423
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::lagged_fibonacci9689
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::lagged_fibonacci19937
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::lagged_fibonacci23209
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::ranlux3
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::ranlux4
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::ranlux64_3
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::ranlux64_4
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::ranlux3_01
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::ranlux4_01
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::ranlux64_3_01
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::ranlux64_4_01
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::ranlux24
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::ranlux48
        >
    ));
    //->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::uniform_smallint<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::uniform_int_distribution<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_equality_comparable<
            boost::random::uniform_01<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::uniform_real_distribution<>
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::poisson_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::exponential_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::gamma_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::weibull_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::extreme_value_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::beta_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::laplace_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::normal_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::lognormal_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::chi_squared_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::non_central_chi_squared_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::cauchy_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::fisher_f_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::student_t_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::discrete_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::piecewise_constant_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::piecewise_linear_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::triangle_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::random::uniform_on_sphere<>
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

//[test__is_equality_comparable__other
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::complex<float>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::complex<float> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::pair<int,int>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::pair<int,int> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::logic::tribool
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::logic::tribool const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::rational<signed int>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::rational<signed int> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::numeric::interval<double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::numeric::interval<double> const
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::math::quaternion<float>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::math::quaternion<float> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::math::octonion<float>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::math::octonion<float> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_equality_comparable<
            boost::function1<char,char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_equality_comparable<
            boost::function1<char,char> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::variant<short,std::pair<int,int> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
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

//[test__is_equality_comparable__dereferenceable_types
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<int*>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<int const*>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<boost::optional<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_equality_comparable<boost::weak_ptr<int> >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_equality_comparable<
            boost::scoped_ptr<int>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::shared_ptr<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_equality_comparable<
            boost::scoped_array<int>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::shared_array<int>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::intrusive_ptr<int>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
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

#if !defined BOOST_NO_CXX11_HDR_FUNCTIONAL && \
    !defined BOOST_NO_CXX11_NULLPTR
#include <functional>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::function<char(char)>
          , std::nullptr_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::function<char(char)> const
          , std::nullptr_t
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_FUNCTIONAL, BOOST_NO_CXX11_NULLPTR

#if !defined BOOST_NO_CXX11_HDR_ARRAY
#include <array>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::array<char,1>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::array<char,1>::iterator
          , std::array<char,1>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::array<char,1>::const_iterator
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_ARRAY

#if !defined BOOST_NO_CXX11_HDR_FORWARD_LIST
#include <forward_list>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::forward_list<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::forward_list<char>::iterator
          , std::forward_list<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::forward_list<char>::const_iterator
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_FORWARD_LIST

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_SET
#include <unordered_set>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::unordered_set<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::unordered_set<char>::iterator
          , std::unordered_set<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::unordered_set<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::unordered_multiset<char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::unordered_multiset<char>::iterator
          , std::unordered_multiset<char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
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
        boost::concept::traits::is_equality_comparable<
            std::unordered_map<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::unordered_map<char,char>::iterator
          , std::unordered_map<char,char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::unordered_map<char,char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::unordered_multimap<char,char>::iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::unordered_multimap<char,char>::iterator
          , std::unordered_multimap<char,char>::const_iterator
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::unordered_multimap<char,char>::const_iterator
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_UNORDERED_MAP

#if !defined BOOST_NO_CXX11_HDR_RANDOM
#include <random>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<std::minstd_rand0>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<std::minstd_rand>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<std::mt19937>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<std::mt19937_64>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<std::ranlux24_base>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<std::ranlux48_base>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<std::ranlux24>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<std::ranlux48>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<std::knuth_b>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_equality_comparable<std::random_device>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::uniform_int_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::uniform_real_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::bernoulli_distribution
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::binomial_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::geometric_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::negative_binomial_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::poisson_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::discrete_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::exponential_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::gamma_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::weibull_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::extreme_value_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::normal_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::lognormal_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::chi_squared_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::cauchy_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::fisher_f_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::student_t_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::piecewise_constant_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            std::piecewise_linear_distribution<>
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_RANDOM

