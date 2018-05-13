// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/traits/query/is_math_distribution.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

#include <boost/math/distributions/arcsine.hpp>
#include <boost/math/distributions/bernoulli.hpp>
#include <boost/math/distributions/beta.hpp>
#include <boost/math/distributions/binomial.hpp>
#include <boost/math/distributions/cauchy.hpp>
#include <boost/math/distributions/chi_squared.hpp>
#include <boost/math/distributions/exponential.hpp>
#include <boost/math/distributions/extreme_value.hpp>
#include <boost/math/distributions/fisher_f.hpp>
#include <boost/math/distributions/gamma.hpp>
#include <boost/math/distributions/geometric.hpp>
#include <boost/math/distributions/hyperexponential.hpp>
#include <boost/math/distributions/hypergeometric.hpp>
#include <boost/math/distributions/inverse_chi_squared.hpp>
#include <boost/math/distributions/inverse_gamma.hpp>
#include <boost/math/distributions/inverse_gaussian.hpp>
#include <boost/math/distributions/laplace.hpp>
#include <boost/math/distributions/logistic.hpp>
#include <boost/math/distributions/lognormal.hpp>
#include <boost/math/distributions/negative_binomial.hpp>
#include <boost/math/distributions/non_central_beta.hpp>
#include <boost/math/distributions/non_central_chi_squared.hpp>
#include <boost/math/distributions/non_central_f.hpp>
#include <boost/math/distributions/non_central_t.hpp>
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/pareto.hpp>
#include <boost/math/distributions/poisson.hpp>
#include <boost/math/distributions/rayleigh.hpp>
#include <boost/math/distributions/skew_normal.hpp>
#include <boost/math/distributions/students_t.hpp>
#include <boost/math/distributions/triangular.hpp>
#include <boost/math/distributions/uniform.hpp>
#include <boost/math/distributions/weibull.hpp>

//[test__is_math_distribution
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::arcsine
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::arcsine const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::bernoulli
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::bernoulli const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::beta_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::beta_distribution<> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::binomial
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::binomial const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::cauchy
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::cauchy const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::chi_squared
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::chi_squared const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::exponential
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::exponential const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::extreme_value
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::extreme_value const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::fisher_f
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::fisher_f const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::gamma_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::gamma_distribution<> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::geometric
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::geometric const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::hyperexponential
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::hyperexponential const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::hypergeometric
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::hypergeometric const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::inverse_chi_squared_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::inverse_chi_squared_distribution<> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::inverse_gamma_distribution<>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::inverse_gamma_distribution<> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::inverse_gaussian
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::inverse_gaussian const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::laplace
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::laplace const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::logistic
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::logistic const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::lognormal
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::lognormal const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::negative_binomial
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::negative_binomial const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::non_central_beta
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::non_central_beta const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::non_central_chi_squared
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::non_central_chi_squared const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::non_central_f
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::non_central_f const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::non_central_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::non_central_t const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::normal
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::normal const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::pareto
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::pareto const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::poisson
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::poisson const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::rayleigh
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::rayleigh const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::skew_normal
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::skew_normal const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::students_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::students_t const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::triangular
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::triangular const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::uniform
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::uniform const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::weibull
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_math_distribution<
            boost::math::weibull const
        >
    ));
}
//]

