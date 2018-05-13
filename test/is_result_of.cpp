// Copyright (C) 2014-2015 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/traits/introspection/is_result_of.hpp>
#include <utility>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

//[test__is_result_of__std_adaptors
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<int,std::plus<int>(int,int)>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<int,std::minus<int>(int,int)>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<int,std::multiplies<int>(int,int)>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<int,std::divides<int>(int,int)>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<int,std::modulus<int>(int,int)>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<int,std::negate<int>(int)>
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<bool,std::equal_to<int>(int,int)>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<bool,std::not_equal_to<int>(int,int)>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<bool,std::less<int>(int,int)>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<bool,std::greater<int>(int,int)>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<bool,std::less_equal<int>(int,int)>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<bool,std::greater_equal<int>(int,int)>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<bool,std::logical_and<bool>(bool,bool)>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<bool,std::logical_or<bool>(bool,bool)>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<bool,std::logical_not<bool>(bool)>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            unsigned
          , std::bit_and<unsigned>(unsigned,unsigned)
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            unsigned
          , std::bit_or<unsigned>(unsigned,unsigned)
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            unsigned
          , std::bit_xor<unsigned>(unsigned,unsigned)
        >
    ));
    //->
}
//]

#include <boost/function.hpp>
#include <boost/functional/hash.hpp>
#include <boost/config.hpp>

//[test__is_result_of__boost_adaptors
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            std::size_t
          , boost::hash<char const*>(char const*)
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            int
#else
//->
            int&
//<-
#endif
//->
          , boost::function1<int&,int>(int)
        >
    ));
//<-
#if !defined BOOST_NO_CXX11_RVALUE_REFERENCES
//->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            bool
#else
//->
            bool&&
//<-
#endif
//->
          , boost::function1<bool&&,char>(char)
        >
    ));
//<-
#endif  // !defined BOOST_NO_CXX11_RVALUE_REFERENCES
//->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            void
          , boost::function1<void,void*>(void*)
        >
    ));
//<-
#if !defined BOOST_NO_CXX11_RVALUE_REFERENCES
//->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            bool
#else
//->
            bool&&
//<-
#endif
//->
          , boost::function2<bool&&,char,char>(char,char)
        >
    ));
//<-
#endif  // !defined BOOST_NO_CXX11_RVALUE_REFERENCES
//->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            char
#else
//->
            char&
//<-
#endif
//->
          , boost::function2<char&,short,long>(short,long)
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            void
          , boost::function2<void,float,double>(float,double)
        >
    ));
}
//]

#include <boost/any.hpp>
#include <boost/mpl/inherit.hpp>

#if defined BOOST_NO_CX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

//[test__is_result_of__members
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            char
//<-
#if defined BOOST_NO_CX11_DECLTYPE
          , BOOST_TYPEOF((&std::pair<char,short>::first))
#else
//->
          , decltype(&std::pair<char,short>::first)
//<-
#endif
//->
        >
    ));
    BOOST_MPL_ASSERT((
//<-
#if defined BOOST_NO_CX11_DECLTYPE
        boost::concept::traits::is_result_of<bool,BOOST_TYPEOF(&boost::any::empty)()>
#else
//->
        boost::concept::traits::is_result_of<bool,decltype(&boost::any::empty)()>
//<-
#endif
//->
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
//<-
#if defined BOOST_NO_CX11_DECLTYPE
            boost::any
          , BOOST_TYPEOF(&boost::any::swap)(boost::any&)
#else
//->
            boost::any&
          , decltype(&boost::any::swap)(boost::any&)
//<-
#endif
//->
        >
    ));

    typedef boost::mpl::inherit<boost::any>::type any_more;

    BOOST_MPL_ASSERT((
//<-
#if defined BOOST_NO_CX11_DECLTYPE
        boost::concept::traits::is_result_of<bool,BOOST_TYPEOF(&any_more::empty)()>
#else
//->
        boost::concept::traits::is_result_of<bool,decltype(&any_more::empty)()>
//<-
#endif
//->
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            boost::any
          , BOOST_TYPEOF(&any_more::swap)(boost::any&)
#else
//->
            boost::any&
          , decltype(&any_more::swap)(boost::any&)
//<-
#endif
//->
        >
    ));
}
//]

#if !defined BOOST_NO_CXX11_HDR_FUNCTIONAL
#include <functional>

//[test__is_result_of__std_functional
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_result_of<std::size_t,std::hash<char const*>()>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            std::size_t
          , std::hash<char const*>(char const*)
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_result_of<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            int
#else
//->
            int&
//<-
#endif
//->
          , std::function<int&(int)>()
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            int
#else
//->
            int&
//<-
#endif
//->
          , std::function<int&(int)>(int)
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_result_of<bool,std::function<bool(char)>()>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<bool,std::function<bool(char)>(char)>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_result_of<void,std::function<void(void*)>()>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<void,std::function<void(void*)>(void*)>
    ));
//<-
#if !defined BOOST_NO_CXX11_RVALUE_REFERENCES
//->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_result_of<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            bool
#else
//->
            bool&&
//<-
#endif
//->
          , std::function<bool&&(char,char)>()
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            bool
#else
//->
            bool&&
//<-
#endif
//->
          , std::function<bool&&(char,char)>(char,char)
        >
    ));
//<-
#endif  // BOOST_NO_CXX11_RVALUE_REFERENCES
//->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_result_of<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            char
#else
//->
            char&
//<-
#endif
//->
          , std::function<char&(short,long)>()
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            char
#else
//->
            char&
//<-
#endif
//->
          , std::function<char&(short,long)>(short,long)
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_result_of<
            void
          , std::function<void(float,double)>()
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            void
          , std::function<void(float,double)>(float,double)
        >
    ));
}
//]
#endif  // BOOST_NO_CXX11_HDR_FUNCTIONAL

#if !defined BOOST_NO_CXX11_HDR_RANDOM
#include <random>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<std::uint_fast32_t,std::minstd_rand0()>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            std::uint_fast32_t
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::minstd_rand0::min)()
#else
          , decltype(&std::minstd_rand0::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            std::uint_fast32_t
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::minstd_rand0::max)()
#else
          , decltype(&std::minstd_rand0::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<std::uint_fast32_t,std::minstd_rand()>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            std::uint_fast32_t
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::minstd_rand::min)()
#else
          , decltype(&std::minstd_rand::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            std::uint_fast32_t
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::minstd_rand::max)()
#else
          , decltype(&std::minstd_rand::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<std::uint_fast32_t,std::mt19937()>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            std::uint_fast32_t
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::mt19937::min)()
#else
          , decltype(&std::mt19937::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            std::uint_fast32_t
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::mt19937::max)()
#else
          , decltype(&std::mt19937::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<std::uint_fast64_t,std::mt19937_64()>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            std::uint_fast64_t
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::mt19937_64::min)()
#else
          , decltype(&std::mt19937_64::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            std::uint_fast64_t
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::mt19937_64::max)()
#else
          , decltype(&std::mt19937_64::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<std::uint_fast32_t,std::ranlux24_base()>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            std::uint_fast32_t
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::ranlux24_base::min)()
#else
          , decltype(&std::ranlux24_base::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            std::uint_fast32_t
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::ranlux24_base::max)()
#else
          , decltype(&std::ranlux24_base::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<std::uint_fast64_t,std::ranlux48_base()>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            std::uint_fast64_t
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::ranlux48_base::min)()
#else
          , decltype(&std::ranlux48_base::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            std::uint_fast64_t
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::ranlux48_base::max)()
#else
          , decltype(&std::ranlux48_base::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<std::uint_fast32_t,std::ranlux24()>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            std::uint_fast32_t
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::ranlux24::min)()
#else
          , decltype(&std::ranlux24::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            std::uint_fast32_t
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::ranlux24::max)()
#else
          , decltype(&std::ranlux24::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<std::uint_fast64_t,std::ranlux48()>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            std::uint_fast64_t
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::ranlux48::min)()
#else
          , decltype(&std::ranlux48::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            std::uint_fast64_t
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::ranlux48::max)()
#else
          , decltype(&std::ranlux48::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<std::uint_fast32_t,std::knuth_b()>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            std::uint_fast32_t
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::knuth_b::min)()
#else
          , decltype(&std::knuth_b::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            std::uint_fast32_t
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::knuth_b::max)()
#else
          , decltype(&std::knuth_b::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<unsigned int,std::random_device()>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            unsigned int
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::random_device::min)()
#else
          , decltype(&std::random_device::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            unsigned int
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::random_device::max)()
#else
          , decltype(&std::random_device::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_result_of<int,std::uniform_int_distribution<>()>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            int
          , std::uniform_int_distribution<>(std::knuth_b&)
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            int
          , std::uniform_int_distribution<>(
                std::knuth_b&
              , std::uniform_int_distribution<>::param_type const&
            )
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            void
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::uniform_int_distribution<>::reset)()
#else
          , decltype(&std::uniform_int_distribution<>::reset)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            int
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::uniform_int_distribution<>::min)()
#else
          , decltype(&std::uniform_int_distribution<>::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            int
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::uniform_int_distribution<>::max)()
#else
          , decltype(&std::uniform_int_distribution<>::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_result_of<
            double
          , std::uniform_real_distribution<>()
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
          , std::uniform_real_distribution<>(std::knuth_b&)
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
          , std::uniform_real_distribution<>(
                std::knuth_b&
              , std::uniform_real_distribution<>::param_type const&
            )
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            void
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::uniform_real_distribution<>::reset)()
#else
          , decltype(&std::uniform_real_distribution<>::reset)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::uniform_real_distribution<>::min)()
#else
          , decltype(&std::uniform_real_distribution<>::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::uniform_real_distribution<>::max)()
#else
          , decltype(&std::uniform_real_distribution<>::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_result_of<bool,std::bernoulli_distribution()>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            bool
          , std::bernoulli_distribution(std::knuth_b&)
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            bool
          , std::bernoulli_distribution(
                std::knuth_b&
              , std::bernoulli_distribution::param_type const&
            )
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            void
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::bernoulli_distribution::reset)()
#else
          , decltype(&std::bernoulli_distribution::reset)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            bool
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::bernoulli_distribution::min)()
#else
          , decltype(&std::bernoulli_distribution::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            bool
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::bernoulli_distribution::max)()
#else
          , decltype(&std::bernoulli_distribution::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_result_of<int,std::binomial_distribution<>()>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            int
          , std::binomial_distribution<>(std::knuth_b&)
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            int
          , std::binomial_distribution<>(
                std::knuth_b&
              , std::binomial_distribution<>::param_type const&
            )
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            void
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::binomial_distribution<>::reset)()
#else
          , decltype(&std::binomial_distribution<>::reset)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            int
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::binomial_distribution<>::min)()
#else
          , decltype(&std::binomial_distribution<>::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            int
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::binomial_distribution<>::max)()
#else
          , decltype(&std::binomial_distribution<>::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_result_of<int,std::geometric_distribution<>()>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            int
          , std::geometric_distribution<>(std::knuth_b&)
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            int
          , std::geometric_distribution<>(
                std::knuth_b&
              , std::geometric_distribution<>::param_type const&
            )
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            void
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::geometric_distribution<>::reset)()
#else
          , decltype(&std::geometric_distribution<>::reset)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            int
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::geometric_distribution<>::min)()
#else
          , decltype(&std::geometric_distribution<>::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            int
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::geometric_distribution<>::max)()
#else
          , decltype(&std::geometric_distribution<>::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_result_of<
            int
          , std::negative_binomial_distribution<>()
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            int
          , std::negative_binomial_distribution<>(std::knuth_b&)
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            int
          , std::negative_binomial_distribution<>(
                std::knuth_b&
              , std::negative_binomial_distribution<>::param_type const&
            )
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            void
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::negative_binomial_distribution<>::reset)()
#else
          , decltype(&std::negative_binomial_distribution<>::reset)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            int
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::negative_binomial_distribution<>::min)()
#else
          , decltype(&std::negative_binomial_distribution<>::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            int
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::negative_binomial_distribution<>::max)()
#else
          , decltype(&std::negative_binomial_distribution<>::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_result_of<int,std::poisson_distribution<>()>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            int
          , std::poisson_distribution<>(std::knuth_b&)
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            int
          , std::poisson_distribution<>(
                std::knuth_b&
              , std::poisson_distribution<>::param_type const&
            )
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            void
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::poisson_distribution<>::reset)()
#else
          , decltype(&std::poisson_distribution<>::reset)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            int
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::poisson_distribution<>::min)()
#else
          , decltype(&std::poisson_distribution<>::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            int
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::poisson_distribution<>::max)()
#else
          , decltype(&std::poisson_distribution<>::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_result_of<int,std::discrete_distribution<>()>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            int
          , std::discrete_distribution<>(std::knuth_b&)
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            int
          , std::discrete_distribution<>(
                std::knuth_b&
              , std::discrete_distribution<>::param_type const&
            )
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            void
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::discrete_distribution<>::reset)()
#else
          , decltype(&std::discrete_distribution<>::reset)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            int
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::discrete_distribution<>::min)()
#else
          , decltype(&std::discrete_distribution<>::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            int
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::discrete_distribution<>::max)()
#else
          , decltype(&std::discrete_distribution<>::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_result_of<
            double
          , std::exponential_distribution<>()
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
          , std::exponential_distribution<>(std::knuth_b&)
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
          , std::exponential_distribution<>(
                std::knuth_b&
              , std::exponential_distribution<>::param_type const&
            )
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            void
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::exponential_distribution<>::reset)()
#else
          , decltype(&std::exponential_distribution<>::reset)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::exponential_distribution<>::min)()
#else
          , decltype(&std::exponential_distribution<>::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::exponential_distribution<>::max)()
#else
          , decltype(&std::exponential_distribution<>::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_result_of<double,std::gamma_distribution<>()>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
          , std::gamma_distribution<>(std::knuth_b&)
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
          , std::gamma_distribution<>(
                std::knuth_b&
              , std::gamma_distribution<>::param_type const&
            )
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            void
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::gamma_distribution<>::reset)()
#else
          , decltype(&std::gamma_distribution<>::reset)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::gamma_distribution<>::min)()
#else
          , decltype(&std::gamma_distribution<>::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::gamma_distribution<>::max)()
#else
          , decltype(&std::gamma_distribution<>::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_result_of<double,std::weibull_distribution<>()>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
          , std::weibull_distribution<>(std::knuth_b&)
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
          , std::weibull_distribution<>(
                std::knuth_b&
              , std::weibull_distribution<>::param_type const&
            )
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            void
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::weibull_distribution<>::reset)()
#else
          , decltype(&std::weibull_distribution<>::reset)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::weibull_distribution<>::min)()
#else
          , decltype(&std::weibull_distribution<>::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::weibull_distribution<>::max)()
#else
          , decltype(&std::weibull_distribution<>::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_result_of<
            double
          , std::extreme_value_distribution<>()
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
          , std::extreme_value_distribution<>(std::knuth_b&)
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
          , std::extreme_value_distribution<>(
                std::knuth_b&
              , std::extreme_value_distribution<>::param_type const&
            )
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            void
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::extreme_value_distribution<>::reset)()
#else
          , decltype(&std::extreme_value_distribution<>::reset)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::extreme_value_distribution<>::min)()
#else
          , decltype(&std::extreme_value_distribution<>::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::extreme_value_distribution<>::max)()
#else
          , decltype(&std::extreme_value_distribution<>::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_result_of<double,std::normal_distribution<>()>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
          , std::normal_distribution<>(std::knuth_b&)
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
          , std::normal_distribution<>(
                std::knuth_b&
              , std::normal_distribution<>::param_type const&
            )
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            void
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::normal_distribution<>::reset)()
#else
          , decltype(&std::normal_distribution<>::reset)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::normal_distribution<>::min)()
#else
          , decltype(&std::normal_distribution<>::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::normal_distribution<>::max)()
#else
          , decltype(&std::normal_distribution<>::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_result_of<double,std::lognormal_distribution<>()>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
          , std::lognormal_distribution<>(std::knuth_b&)
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
          , std::lognormal_distribution<>(
                std::knuth_b&
              , std::lognormal_distribution<>::param_type const&
            )
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            void
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::lognormal_distribution<>::reset)()
#else
          , decltype(&std::lognormal_distribution<>::reset)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::lognormal_distribution<>::min)()
#else
          , decltype(&std::lognormal_distribution<>::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::lognormal_distribution<>::max)()
#else
          , decltype(&std::lognormal_distribution<>::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_result_of<
            double
          , std::chi_squared_distribution<>()
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
          , std::chi_squared_distribution<>(std::knuth_b&)
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
          , std::chi_squared_distribution<>(
                std::knuth_b&
              , std::chi_squared_distribution<>::param_type const&
            )
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            void
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::chi_squared_distribution<>::reset)()
#else
          , decltype(&std::chi_squared_distribution<>::reset)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::chi_squared_distribution<>::min)()
#else
          , decltype(&std::chi_squared_distribution<>::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::chi_squared_distribution<>::max)()
#else
          , decltype(&std::chi_squared_distribution<>::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_result_of<double,std::cauchy_distribution<>()>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
          , std::cauchy_distribution<>(std::knuth_b&)
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
          , std::cauchy_distribution<>(
                std::knuth_b&
              , std::cauchy_distribution<>::param_type const&
            )
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            void
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::cauchy_distribution<>::reset)()
#else
          , decltype(&std::cauchy_distribution<>::reset)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::cauchy_distribution<>::min)()
#else
          , decltype(&std::cauchy_distribution<>::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::cauchy_distribution<>::max)()
#else
          , decltype(&std::cauchy_distribution<>::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_result_of<double,std::fisher_f_distribution<>()>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
          , std::fisher_f_distribution<>(std::knuth_b&)
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
          , std::fisher_f_distribution<>(
                std::knuth_b&
              , std::fisher_f_distribution<>::param_type const&
            )
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            void
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::fisher_f_distribution<>::reset)()
#else
          , decltype(&std::fisher_f_distribution<>::reset)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::fisher_f_distribution<>::min)()
#else
          , decltype(&std::fisher_f_distribution<>::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::fisher_f_distribution<>::max)()
#else
          , decltype(&std::fisher_f_distribution<>::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_result_of<double,std::student_t_distribution<>()>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
          , std::student_t_distribution<>(std::knuth_b&)
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
          , std::student_t_distribution<>(
                std::knuth_b&
              , std::student_t_distribution<>::param_type const&
            )
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            void
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::student_t_distribution<>::reset)()
#else
          , decltype(&std::student_t_distribution<>::reset)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::student_t_distribution<>::min)()
#else
          , decltype(&std::student_t_distribution<>::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::student_t_distribution<>::max)()
#else
          , decltype(&std::student_t_distribution<>::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_result_of<
            double
          , std::piecewise_constant_distribution<>()
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
          , std::piecewise_constant_distribution<>(std::knuth_b&)
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
          , std::piecewise_constant_distribution<>(
                std::knuth_b&
              , std::piecewise_constant_distribution<>::param_type const&
            )
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            void
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::piecewise_constant_distribution<>::reset)()
#else
          , decltype(&std::piecewise_constant_distribution<>::reset)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::piecewise_constant_distribution<>::min)()
#else
          , decltype(&std::piecewise_constant_distribution<>::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::piecewise_constant_distribution<>::max)()
#else
          , decltype(&std::piecewise_constant_distribution<>::max)()
#endif
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_result_of<
            double
          , std::piecewise_linear_distribution<>()
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
          , std::piecewise_linear_distribution<>(std::knuth_b&)
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
          , std::piecewise_linear_distribution<>(
                std::knuth_b&
              , std::piecewise_linear_distribution<>::param_type const&
            )
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            void
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::piecewise_linear_distribution<>::reset)()
#else
          , decltype(&std::piecewise_linear_distribution<>::reset)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::piecewise_linear_distribution<>::min)()
#else
          , decltype(&std::piecewise_linear_distribution<>::min)()
#endif
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_result_of<
            double
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF(&std::piecewise_linear_distribution<>::max)()
#else
          , decltype(&std::piecewise_linear_distribution<>::max)()
#endif
        >
    ));
}
#endif  // BOOST_NO_CXX11_HDR_RANDOM

