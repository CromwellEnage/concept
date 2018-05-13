// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/archetype/accumulator.hpp>
#include <boost/concept/traits/query/is_accumulator.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

//[test__is_accumulator__archetype
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_accumulator<
            boost::concept::accumulator_archetype<int>
        >
    ));
}
//]

#include <boost/accumulators/statistics.hpp>
#include <boost/mpl/int.hpp>

//[test__is_accumulator__impls
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_accumulator<
            boost::accumulators::impl::sum_impl<double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_accumulator<
            boost::accumulators::impl::count_impl
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_accumulator<
            boost::accumulators::impl::max_impl<double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_accumulator<
            boost::accumulators::impl::min_impl<double>
        >
    ));
    // ...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_accumulator<
            boost::accumulators::impl::rolling_sum_impl<double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_accumulator<
            boost::accumulators::impl::rolling_count_impl<unsigned long>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_accumulator<
            boost::accumulators::impl::mean_impl<double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_accumulator<
            boost::accumulators::impl::immediate_mean_impl<double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_accumulator<
            boost::accumulators::impl::rolling_mean_impl<double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_accumulator<
            boost::accumulators::impl::median_impl<double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_accumulator<
            boost::accumulators::impl::weighted_median_impl<double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_accumulator<
            boost::accumulators::impl::with_density_median_impl<double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_accumulator<
            boost::accumulators::impl
            ::with_p_square_cumulative_distribution_median_impl<double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_accumulator<
            boost::accumulators::impl
            ::with_p_square_cumulative_distribution_weighted_median_impl<
                double
              , double
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_accumulator<
            boost::accumulators::impl::moment_impl<boost::mpl::int_<2>,int>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_accumulator<
            boost::accumulators::impl
            ::weighted_moment_impl<boost::mpl::int_<2>,double,double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_accumulator<
            boost::accumulators::impl::density_impl<double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_accumulator<
            boost::accumulators::impl::weighted_density_impl<double,double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_accumulator<
            boost::accumulators::impl::kurtosis_impl<double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_accumulator<
            boost::accumulators::impl::weighted_kurtosis_impl<double,double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_accumulator<
            boost::accumulators::impl
            ::p_square_cumulative_distribution_impl<double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_accumulator<
            boost::accumulators::impl
            ::weighted_p_square_cumulative_distribution_impl<double,double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_accumulator<
            boost::accumulators::impl::rolling_window_impl<double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_accumulator<
            boost::accumulators::impl::rolling_window_plus1_impl<double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_accumulator<
            boost::accumulators::impl::skewness_impl<double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_accumulator<
            boost::accumulators::impl::weighted_skewness_impl<double>
        >
    ));
    //->
}
//]

