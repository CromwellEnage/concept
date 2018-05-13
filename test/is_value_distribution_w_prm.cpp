// Copyright (C) 2014-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/traits/query/is_value_distribution_w_prm.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

#include <boost/random.hpp>

//[test__is_value_distribution_with_param__boost_random
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::minstd_rand0
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
           boost::random::minstd_rand
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::rand48
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::ecuyer1988
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::knuth_b
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::kreutzer1986
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::taus88
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::hellekalek1995
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::mt11213b
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::mt19937
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::mt19937_64
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::lagged_fibonacci607
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::lagged_fibonacci1279
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::lagged_fibonacci2281
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::lagged_fibonacci3217
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::lagged_fibonacci4423
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::lagged_fibonacci9689
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::lagged_fibonacci19937
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::lagged_fibonacci23209
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::ranlux3
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::ranlux4
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::ranlux64_3
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::ranlux64_4
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::ranlux3_01
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::ranlux4_01
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::ranlux64_3_01
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::ranlux64_4_01
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::ranlux24
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::ranlux48
        >
    ));
    //->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::uniform_smallint<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::uniform_int_distribution<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::uniform_01<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::uniform_real_distribution<>
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::poisson_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::exponential_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::gamma_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::weibull_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::extreme_value_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::beta_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::laplace_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::normal_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::lognormal_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::chi_squared_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::non_central_chi_squared_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::cauchy_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::fisher_f_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::student_t_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::discrete_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::piecewise_constant_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::piecewise_linear_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::triangle_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::random::uniform_on_sphere<>
        >
    ));
    //->
}
//]

#include <boost/config.hpp>

#if !defined BOOST_NO_CXX11_HDR_RANDOM
#include <random>

//[test__is_value_distribution_with_param__std_random
MPL_TEST_CASE()
{
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            std::minstd_rand0
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            std::minstd_rand
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            std::mt19937
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            std::mt19937_64
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            std::ranlux24_base
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            std::ranlux48_base
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            std::ranlux24
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            std::ranlux48
        >
    ));
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            std::knuth_b
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            std::random_device
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            std::uniform_int_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            std::uniform_real_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            std::bernoulli_distribution
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            std::binomial_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            std::geometric_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            std::negative_binomial_distribution<>
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            std::poisson_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            std::discrete_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            std::exponential_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            std::gamma_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            std::weibull_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            std::extreme_value_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            std::normal_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            std::lognormal_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            std::chi_squared_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            std::cauchy_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            std::fisher_f_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            std::student_t_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            std::piecewise_constant_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            std::piecewise_linear_distribution<>
        >
    ));
    //->
}
//]
#endif  // BOOST_NO_CXX11_HDR_RANDOM

