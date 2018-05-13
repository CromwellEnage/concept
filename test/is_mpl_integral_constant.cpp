// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/traits/query/is_mpl_integral_constant.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/char.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/long.hpp>
#include <boost/mpl/size_t.hpp>
#include <boost/mpl/arithmetic.hpp>
#include <boost/mpl/comparison.hpp>
#include <boost/mpl/logical.hpp>

//[test__is_mpl_integral_constant__boost_mpl
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<int>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::integral_c<short,1>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<boost::mpl::true_>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<boost::mpl::false_>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<boost::mpl::char_<' '> >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<boost::mpl::int_<1> >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<boost::mpl::long_<1> >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<boost::mpl::size_t<1> >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::negate<boost::mpl::char_<' '> >
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::negate<boost::mpl::int_<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::negate<boost::mpl::long_<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::negate<boost::mpl::size_t<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::negate<boost::mpl::integral_c<short,1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::plus<boost::mpl::char_<' '>,boost::mpl::int_<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::plus<boost::mpl::char_<' '>,boost::mpl::long_<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::plus<boost::mpl::char_<' '>,boost::mpl::size_t<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::plus<
                boost::mpl::char_<' '>
              , boost::mpl::integral_c<short,1>
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::plus<boost::mpl::int_<0>,boost::mpl::long_<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::plus<boost::mpl::int_<1>,boost::mpl::size_t<0> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::plus<
                boost::mpl::int_<0>
              , boost::mpl::integral_c<short,1>
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::plus<boost::mpl::long_<1>,boost::mpl::size_t<0> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::plus<
                boost::mpl::long_<0>
              , boost::mpl::integral_c<short,1>
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::plus<
                boost::mpl::size_t<1>
              , boost::mpl::integral_c<short,0>
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::minus<boost::mpl::char_<' '>,boost::mpl::int_<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::minus<boost::mpl::char_<' '>,boost::mpl::long_<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::minus<boost::mpl::char_<' '>,boost::mpl::size_t<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::minus<
                boost::mpl::char_<' '>
              , boost::mpl::integral_c<short,1>
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::minus<boost::mpl::int_<1>,boost::mpl::long_<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::minus<boost::mpl::int_<1>,boost::mpl::size_t<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::minus<
                boost::mpl::int_<1>
              , boost::mpl::integral_c<short,1>
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::minus<boost::mpl::long_<1>,boost::mpl::size_t<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::minus<
                boost::mpl::long_<1>
              , boost::mpl::integral_c<short,1>
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::minus<
                boost::mpl::size_t<1>
              , boost::mpl::integral_c<short,1>
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::times<boost::mpl::char_<' '>,boost::mpl::int_<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::times<boost::mpl::char_<' '>,boost::mpl::long_<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::times<boost::mpl::char_<' '>,boost::mpl::size_t<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::times<
                boost::mpl::char_<' '>
              , boost::mpl::integral_c<short,1>
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::times<boost::mpl::int_<1>,boost::mpl::long_<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::times<boost::mpl::int_<1>,boost::mpl::size_t<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::times<
                boost::mpl::int_<1>
              , boost::mpl::integral_c<short,1>
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::times<boost::mpl::long_<1>,boost::mpl::size_t<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::times<
                boost::mpl::long_<1>
              , boost::mpl::integral_c<short,1>
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::times<
                boost::mpl::size_t<1>
              , boost::mpl::integral_c<short,1>
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::divides<boost::mpl::char_<' '>,boost::mpl::int_<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::divides<boost::mpl::char_<' '>,boost::mpl::long_<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::divides<boost::mpl::char_<' '>,boost::mpl::size_t<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::divides<
                boost::mpl::char_<' '>
              , boost::mpl::integral_c<short,1>
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::divides<boost::mpl::int_<1>,boost::mpl::long_<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::divides<boost::mpl::int_<1>,boost::mpl::size_t<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::divides<
                boost::mpl::int_<1>
              , boost::mpl::integral_c<short,1>
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::divides<boost::mpl::long_<1>,boost::mpl::size_t<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::divides<
                boost::mpl::long_<1>
              , boost::mpl::integral_c<short,1>
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::divides<
                boost::mpl::size_t<1>
              , boost::mpl::integral_c<short,1>
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::modulus<boost::mpl::char_<' '>,boost::mpl::int_<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::modulus<boost::mpl::char_<' '>,boost::mpl::long_<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::modulus<boost::mpl::char_<' '>,boost::mpl::size_t<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::modulus<
                boost::mpl::char_<' '>
              , boost::mpl::integral_c<short,1>
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::modulus<boost::mpl::int_<1>,boost::mpl::long_<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::modulus<boost::mpl::int_<1>,boost::mpl::size_t<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::modulus<
                boost::mpl::int_<1>
              , boost::mpl::integral_c<short,1>
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::modulus<boost::mpl::long_<1>,boost::mpl::size_t<1> >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::modulus<
                boost::mpl::long_<1>
              , boost::mpl::integral_c<short,1>
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::modulus<
                boost::mpl::size_t<1>
              , boost::mpl::integral_c<short,1>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::not_<boost::mpl::true_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::and_<boost::mpl::false_,boost::mpl::true_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::or_<boost::mpl::false_,boost::mpl::true_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::equal_to<boost::mpl::long_<1>,boost::mpl::size_t<1> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::not_equal_to<
                boost::mpl::char_<' '>
              , boost::mpl::integral_c<short,1>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::less<
                boost::mpl::int_<1>
              , boost::mpl::integral_c<short,1>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::greater<
                boost::mpl::long_<1>
              , boost::mpl::integral_c<short,1>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::less_equal<
                boost::mpl::size_t<1>
              , boost::mpl::integral_c<short,1>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::greater_equal<
                boost::mpl::negate<boost::mpl::char_<' '> >
              , boost::mpl::integral_c<short,1>
            >
        >
    ));
    //->
}
//]

#include <boost/type_traits.hpp>
#include <complex>

//[test__is_mpl_integral_constant__boost_type_traits
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<boost::true_type>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<boost::false_type>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::not_<std::true_type>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::and_<std::true_type,std::false_type>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::mpl::or_<std::true_type,std::false_type>
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_bit_and<int,int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_bit_and<int,double,bool>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_bit_and_assign<int,int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_bit_and_assign<int,double,bool>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_bit_or<int,int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_bit_or<int,double,bool>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_bit_or_assign<int,int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_bit_or_assign<int,double,bool>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_bit_xor<int,int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_bit_xor<int,double,bool>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_bit_xor_assign<int,int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_bit_xor_assign<int,double,bool>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_complement<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_complement<int*>
        >
    ));
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_dereference<char*>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_dereference<char>
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_divides<int const,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_divides<int,int,std::complex<int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_divides_assign<int const,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_divides_assign<int,int,std::complex<int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_equal_to<int,double,bool>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_equal_to<int,int,std::complex<int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_greater<int,double,bool>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_greater<int,int,std::complex<int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_greater_equal<int,double,bool>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_greater_equal<int,int,std::complex<int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_left_shift<int,int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_left_shift<int,double,bool>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_left_shift_assign<int,int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_left_shift_assign<int,double,bool>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_less<int,double,bool>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_less<int,int,std::complex<int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_less_equal<int,double,bool>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_less_equal<int,int,std::complex<int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_minus<int const,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_minus<int,int,std::complex<int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_minus_assign<int const,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_minus_assign<int,int,std::complex<int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_modulus<int const,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_modulus<int,int,std::complex<int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_modulus_assign<int const,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_modulus_assign<int,int,std::complex<int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_multiplies<int const,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_multiplies<int,int,std::complex<int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_multiplies_assign<int const,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_multiplies_assign<int,int,std::complex<int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_negate<int const>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_negate<int,std::complex<int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_not_equal_to<int,double,bool>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_not_equal_to<int,int,std::complex<int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_plus<int const,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_plus<int,int,std::complex<int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_plus_assign<int const,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_plus_assign<int,int,std::complex<int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_post_decrement<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_post_decrement<int const>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_post_increment<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_post_increment<int const>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_pre_decrement<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_pre_decrement<int const>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_pre_increment<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_pre_increment<int const>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_right_shift<int,int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_right_shift<int,double,bool>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_right_shift_assign<int,int,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_right_shift_assign<int,double,bool>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_unary_minus<int const>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_unary_minus<int,std::complex<int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_unary_plus<int const>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::has_unary_plus<int,std::complex<int> >
        >
    ));
    //->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::alignment_of<unsigned[1]>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::extent<int[3][4],2> >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::rank<char[][1][2][3]>
        >
    ));
}
//]

#include <boost/ratio.hpp>

//[test__is_mpl_integral_constant__boost_ratio
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::ratio<1>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::ratio_add<boost::ratio<1>,boost::ratio<2> >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::ratio_subtract<boost::ratio<1>,boost::ratio<2> >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::ratio_multiply<boost::ratio<1>,boost::ratio<2> >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::ratio_divide<boost::ratio<1>,boost::ratio<2> >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::ratio_equal<boost::ratio<1>,boost::ratio<2> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::ratio_not_equal<boost::ratio<1>,boost::ratio<2> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::ratio_less<boost::ratio<1>,boost::ratio<2> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::ratio_less_equal<boost::ratio<1>,boost::ratio<2> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::ratio_greater<boost::ratio<1>,boost::ratio<2> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            boost::ratio_greater_equal<boost::ratio<1>,boost::ratio<2> >
        >
    ));
}
//]

#include <boost/config.hpp>

#if !defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/move/move.hpp>

//[test__is_mpl_integral_constant__udts
class foo;

struct bar
{
    virtual ~bar() = 0;
};

struct baz : bar
{
    ~baz()
    {
    }

    BOOST_MOVABLE_BUT_NOT_COPYABLE(baz)

    virtual void reality()
    {
    }
};

enum en_espanol { uno, dos };

bool fighter(foo*);
//]

#include <type_traits>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

//[test__is_mpl_integral_constant__std_type_traits
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<std::true_type>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<std::false_type>
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_abstract<bar>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_abstract<void>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_arithmetic<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_arithmetic<void>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_array<char[]>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_array<char*>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_base_of<bar,baz>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_base_of<char,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_class<foo>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_class<void>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_compound<std::true_type>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_compound<void>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_const<short const>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_const<void>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_convertible<int const,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_convertible<int const*,int*>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_copy_constructible<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_copy_constructible<baz>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_copy_assignable<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_copy_assignable<baz>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_empty<std::true_type>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_empty<void>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_enum<en_espanol>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_enum<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_floating_point<float>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_floating_point<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
#if defined BOOST_NO_CXX11_DECLTYPE
            std::is_function<BOOST_TYPEOF(fighter)>
#else
            std::is_function<decltype(fighter)>
#endif
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_function<void>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_fundamental<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_fundamental<std::true_type>
        >
    ));
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_integral<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_integral<void>
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_lvalue_reference<int&>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_lvalue_reference<BOOST_RV_REF(int)>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_member_function_pointer<void (foo::*)(void) const>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_member_function_pointer<void>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_member_object_pointer<bar (foo::*)>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_member_object_pointer<void>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_object<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_object<void>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_pod<baz>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_pod<void>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_pointer<char*>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_pointer<char[]>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_polymorphic<baz>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_polymorphic<void>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_rvalue_reference<BOOST_RV_REF(int)>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_rvalue_reference<int&>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_same<foo,foo>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_same<foo,bar>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_scalar<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_scalar<void>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_signed<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_signed<unsigned>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_unsigned<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_unsigned<unsigned>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_void<bool>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_void<void>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_volatile<short volatile>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::is_volatile<void>
        >
    ));
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::alignment_of<unsigned[1]>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::extent<int[3][4],2>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mpl_integral_constant<
            std::rank<char[][1][2][3]>
        >
    ));
}
//]

#endif  // BOOST_NO_CXX11_HDR_TYPE_TRAITS

