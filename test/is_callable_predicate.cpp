// Copyright (C) 2014-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/traits/query/is_callable.hpp>
#include <boost/concept/traits/query/is_boolean_expression.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/config.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

#include <boost/concept_archetype.hpp>

//[test__is_callable_predicate__archetypes
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::void_generator_archetype()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::generator_archetype<char>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::unary_function_archetype<short,char>(short const&)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::binary_function_archetype<int,short,char>(
                int const&
              , short const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
}
//]

#include <utility>

//[test__is_callable_predicate__std_adaptors
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::plus<int>(int,int)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::minus<int>(int,int)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::multiplies<int>(int,int)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::divides<int>(int,int)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::modulus<int>(int,int)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::negate<int>(int)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::equal_to<int>(int,int)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::not_equal_to<int>(int,int)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::less<int>(int,int)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::greater<int>(int,int)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::less_equal<int>(int,int)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::greater_equal<int>(int,int)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::logical_and<bool>(bool,bool)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::logical_or<bool>(bool,bool)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::logical_not<bool>(bool)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::bit_and<unsigned>(unsigned,unsigned)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::bit_or<unsigned>(unsigned,unsigned)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::bit_xor<unsigned>(unsigned,unsigned)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    //->
}
//]

#include <boost/function.hpp>
#include <boost/functional/hash.hpp>

//[test__is_callable_predicate__boost_adaptors
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::hash<char const*>(char const*)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::function1<int&,int>(int)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
//<-
#if !defined BOOST_NO_CXX11_RVALUE_REFERENCES
//->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::function1<bool&&,char>(char)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
//<-
#endif
//->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::function1<void,void*>(void*)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
//<-
#if !defined BOOST_NO_CXX11_RVALUE_REFERENCES
//->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::function2<bool&&,char,char>(char,char)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
//<-
#endif
//->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::function2<char&,short,long>(short,long)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::function2<void,float,double>(float,double)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
}
//]

#include <boost/any.hpp>
#include <boost/mpl/inherit.hpp>

#if defined BOOST_NO_CX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

//[test__is_callable_predicate__members
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
//<-
#if defined BOOST_NO_CX11_DECLTYPE
            BOOST_TYPEOF((&std::pair<char,short>::first))
#else
//->
            decltype(&std::pair<char,short>::first)
//<-
#endif
//->
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
//<-
#if defined BOOST_NO_CX11_DECLTYPE
            BOOST_TYPEOF(&boost::any::empty)()
#else
//->
            decltype(&boost::any::empty)()
//<-
#endif
//->
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
//<-
#if defined BOOST_NO_CX11_DECLTYPE
            BOOST_TYPEOF(&boost::any::swap)(boost::any&)
#else
//->
            decltype(&boost::any::swap)(boost::any&)
//<-
#endif
//->
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));

    typedef boost::mpl::inherit<boost::any>::type any_more;

    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
//<-
#if defined BOOST_NO_CX11_DECLTYPE
            BOOST_TYPEOF(&any_more::empty)()
#else
//->
            decltype(&any_more::empty)()
//<-
#endif
//->
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
//<-
#if defined BOOST_NO_CX11_DECLTYPE
            BOOST_TYPEOF(&any_more::swap)(boost::any&)
#else
//->
            decltype(&any_more::swap)(boost::any&)
//<-
#endif
//->
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
}
//]

#include <boost/concept/archetype/value_generator.hpp>
#include <boost/random.hpp>

//[test__is_callable_predicate__boost_random
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::minstd_rand0()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::minstd_rand0::min)()
#else
//->
            decltype(&boost::random::minstd_rand0::min)()
//<-
#endif
//->
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::minstd_rand0::max)()
#else
//->
            decltype(&boost::random::minstd_rand0::max)()
//<-
#endif
//->
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::minstd_rand()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::minstd_rand::min)()
#else
            decltype(&boost::random::minstd_rand::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::minstd_rand::max)()
#else
            decltype(&boost::random::minstd_rand::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
        boost::random::rand48()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::rand48::min)()
#else
            decltype(&boost::random::rand48::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::rand48::max)()
#else
            decltype(&boost::random::rand48::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::ecuyer1988()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::ecuyer1988::min)()
#else
            decltype(&boost::random::ecuyer1988::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::ecuyer1988::max)()
#else
            decltype(&boost::random::ecuyer1988::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::knuth_b()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::knuth_b::min)()
#else
            decltype(&boost::random::knuth_b::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::knuth_b::max)()
#else
            decltype(&boost::random::knuth_b::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::kreutzer1986()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::kreutzer1986::min)()
#else
            decltype(&boost::random::kreutzer1986::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::kreutzer1986::max)()
#else
            decltype(&boost::random::kreutzer1986::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::taus88()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::taus88::min)()
#else
            decltype(&boost::random::taus88::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::taus88::max)()
#else
            decltype(&boost::random::taus88::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::hellekalek1995()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::hellekalek1995::min)()
#else
            decltype(&boost::random::hellekalek1995::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::hellekalek1995::max)()
#else
            decltype(&boost::random::hellekalek1995::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::mt11213b()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::mt11213b::min)()
#else
            decltype(&boost::random::mt11213b::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::mt11213b::max)()
#else
            decltype(&boost::random::mt11213b::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::mt19937()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::mt19937::min)()
#else
            decltype(&boost::random::mt19937::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::mt19937::max)()
#else
            decltype(&boost::random::mt19937::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::mt19937_64()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::mt19937_64::min)()
#else
            decltype(&boost::random::mt19937_64::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::mt19937_64::max)()
#else
            decltype(&boost::random::mt19937_64::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::lagged_fibonacci607()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::lagged_fibonacci607::min)()
#else
            decltype(&boost::random::lagged_fibonacci607::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::lagged_fibonacci607::max)()
#else
            decltype(&boost::random::lagged_fibonacci607::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::lagged_fibonacci1279()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::lagged_fibonacci1279::min)()
#else
            decltype(&boost::random::lagged_fibonacci1279::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::lagged_fibonacci1279::max)()
#else
            decltype(&boost::random::lagged_fibonacci1279::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::lagged_fibonacci2281()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::lagged_fibonacci2281::min)()
#else
            decltype(&boost::random::lagged_fibonacci2281::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::lagged_fibonacci2281::max)()
#else
            decltype(&boost::random::lagged_fibonacci2281::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::lagged_fibonacci3217()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::lagged_fibonacci3217::min)()
#else
            decltype(&boost::random::lagged_fibonacci3217::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::lagged_fibonacci3217::max)()
#else
            decltype(&boost::random::lagged_fibonacci3217::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::lagged_fibonacci4423()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::lagged_fibonacci4423::min)()
#else
            decltype(&boost::random::lagged_fibonacci4423::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::lagged_fibonacci4423::max)()
#else
            decltype(&boost::random::lagged_fibonacci4423::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::lagged_fibonacci9689()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::lagged_fibonacci9689::min)()
#else
            decltype(&boost::random::lagged_fibonacci9689::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::lagged_fibonacci9689::max)()
#else
            decltype(&boost::random::lagged_fibonacci9689::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::lagged_fibonacci19937()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::lagged_fibonacci19937::min)()
#else
            decltype(&boost::random::lagged_fibonacci19937::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::lagged_fibonacci19937::max)()
#else
            decltype(&boost::random::lagged_fibonacci19937::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::lagged_fibonacci23209()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::lagged_fibonacci23209::min)()
#else
            decltype(&boost::random::lagged_fibonacci23209::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::lagged_fibonacci23209::max)()
#else
            decltype(&boost::random::lagged_fibonacci23209::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::ranlux3()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::ranlux3::min)()
#else
            decltype(&boost::random::ranlux3::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::ranlux3::max)()
#else
            decltype(&boost::random::ranlux3::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::ranlux4()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::ranlux4::min)()
#else
            decltype(&boost::random::ranlux4::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::ranlux4::max)()
#else
            decltype(&boost::random::ranlux4::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::ranlux64_3()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::ranlux64_3::min)()
#else
            decltype(&boost::random::ranlux64_3::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::ranlux64_3::max)()
#else
            decltype(&boost::random::ranlux64_3::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::ranlux64_4()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::ranlux64_4::min)()
#else
            decltype(&boost::random::ranlux64_4::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::ranlux64_4::max)()
#else
            decltype(&boost::random::ranlux64_4::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::ranlux3_01()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::ranlux3_01::min)()
#else
            decltype(&boost::random::ranlux3_01::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::ranlux3_01::max)()
#else
            decltype(&boost::random::ranlux3_01::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::ranlux4_01()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::ranlux4_01::min)()
#else
            decltype(&boost::random::ranlux4_01::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::ranlux4_01::max)()
#else
            decltype(&boost::random::ranlux4_01::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::ranlux64_3_01()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::ranlux64_3_01::min)()
#else
            decltype(&boost::random::ranlux64_3_01::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::ranlux64_3_01::max)()
#else
            decltype(&boost::random::ranlux64_3_01::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::ranlux64_4_01()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::ranlux64_4_01::min)()
#else
            decltype(&boost::random::ranlux64_4_01::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::ranlux64_4_01::max)()
#else
            decltype(&boost::random::ranlux64_4_01::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::ranlux24()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::ranlux24::min)()
#else
            decltype(&boost::random::ranlux24::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::ranlux24::max)()
#else
            decltype(&boost::random::ranlux24::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::ranlux48()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::ranlux48::min)()
#else
            decltype(&boost::random::ranlux48::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::ranlux48::max)()
#else
            decltype(&boost::random::ranlux48::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::random::uniform_smallint<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::uniform_smallint<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::uniform_smallint<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , boost::random::uniform_smallint<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::uniform_smallint<>::min)()
#else
//->
            decltype(&boost::random::uniform_smallint<>::min)()
//<-
#endif
//->
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::uniform_smallint<>::max)()
#else
//->
            decltype(&boost::random::uniform_smallint<>::max)()
//<-
#endif
//->
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::uniform_smallint<>::reset)()
#else
//->
            decltype(&boost::random::uniform_smallint<>::reset)()
//<-
#endif
//->
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::random::uniform_int_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::uniform_int_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::uniform_int_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , boost::random::uniform_int_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::uniform_int_distribution<>::min)()
#else
            decltype(&boost::random::uniform_int_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::uniform_int_distribution<>::max)()
#else
            decltype(&boost::random::uniform_int_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::uniform_int_distribution<>::reset)()
#else
            decltype(&boost::random::uniform_int_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::random::uniform_01<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::uniform_01<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::uniform_01<>::min)()
#else
            decltype(&boost::random::uniform_01<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::uniform_01<>::max)()
#else
            decltype(&boost::random::uniform_01<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::random::uniform_real_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::uniform_real_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::uniform_real_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , boost::random::uniform_real_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::uniform_real_distribution<>::min)()
#else
            decltype(&boost::random::uniform_real_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::uniform_real_distribution<>::max)()
#else
            decltype(&boost::random::uniform_real_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::uniform_real_distribution<>::reset)()
#else
            decltype(&boost::random::uniform_real_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::random::poisson_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::poisson_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::poisson_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , boost::random::poisson_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::poisson_distribution<>::min)()
#else
            decltype(&boost::random::poisson_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::poisson_distribution<>::max)()
#else
            decltype(&boost::random::poisson_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::poisson_distribution<>::reset)()
#else
            decltype(&boost::random::poisson_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::random::exponential_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::exponential_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::exponential_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , boost::random::exponential_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::exponential_distribution<>::min)()
#else
            decltype(&boost::random::exponential_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::exponential_distribution<>::max)()
#else
            decltype(&boost::random::exponential_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::exponential_distribution<>::reset)()
#else
            decltype(&boost::random::exponential_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::random::gamma_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::gamma_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::gamma_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , boost::random::gamma_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::gamma_distribution<>::min)()
#else
            decltype(&boost::random::gamma_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::gamma_distribution<>::max)()
#else
            decltype(&boost::random::gamma_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::gamma_distribution<>::reset)()
#else
            decltype(&boost::random::gamma_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::random::weibull_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::weibull_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::weibull_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , boost::random::weibull_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::weibull_distribution<>::min)()
#else
            decltype(&boost::random::weibull_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::weibull_distribution<>::max)()
#else
            decltype(&boost::random::weibull_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::weibull_distribution<>::reset)()
#else
            decltype(&boost::random::weibull_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::random::extreme_value_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::extreme_value_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::extreme_value_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , boost::random::extreme_value_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::extreme_value_distribution<>::min)()
#else
            decltype(&boost::random::extreme_value_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::extreme_value_distribution<>::max)()
#else
            decltype(&boost::random::extreme_value_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            (&boost::random::extreme_value_distribution<>::reset)()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::random::beta_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::beta_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::beta_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , boost::random::beta_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::beta_distribution<>::min)()
#else
            decltype(&boost::random::beta_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::beta_distribution<>::max)()
#else
            decltype(&boost::random::beta_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::beta_distribution<>::reset)()
#else
            decltype(&boost::random::beta_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::random::laplace_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::laplace_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::laplace_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , boost::random::laplace_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::laplace_distribution<>::min)()
#else
            decltype(&boost::random::laplace_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::laplace_distribution<>::max)()
#else
            decltype(&boost::random::laplace_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::laplace_distribution<>::reset)()
#else
            decltype(&boost::random::laplace_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::random::normal_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::normal_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::normal_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , boost::random::normal_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::normal_distribution<>::min)()
#else
            decltype(&boost::random::normal_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::normal_distribution<>::max)()
#else
            decltype(&boost::random::normal_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::normal_distribution<>::reset)()
#else
            decltype(&boost::random::normal_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::random::lognormal_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::lognormal_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::lognormal_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , boost::random::lognormal_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::lognormal_distribution<>::min)()
#else
            decltype(&boost::random::lognormal_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::lognormal_distribution<>::max)()
#else
            decltype(&boost::random::lognormal_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::lognormal_distribution<>::reset)()
#else
            decltype(&boost::random::lognormal_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::random::chi_squared_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::chi_squared_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::chi_squared_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , boost::random::chi_squared_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::chi_squared_distribution<>::min)()
#else
            decltype(&boost::random::chi_squared_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::chi_squared_distribution<>::max)()
#else
            decltype(&boost::random::chi_squared_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::chi_squared_distribution<>::reset)()
#else
            decltype(&boost::random::chi_squared_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::random::non_central_chi_squared_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::non_central_chi_squared_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::non_central_chi_squared_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , boost::random::non_central_chi_squared_distribution<>
                ::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            (&boost::random::non_central_chi_squared_distribution<>::min)()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            (&boost::random::non_central_chi_squared_distribution<>::max)()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            (&boost::random::non_central_chi_squared_distribution<>::reset)()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::random::cauchy_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::cauchy_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::cauchy_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , boost::random::cauchy_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::cauchy_distribution<>::min)()
#else
            decltype(&boost::random::cauchy_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::cauchy_distribution<>::max)()
#else
            decltype(&boost::random::cauchy_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::cauchy_distribution<>::reset)()
#else
            decltype(&boost::random::cauchy_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::random::fisher_f_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::fisher_f_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::fisher_f_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , boost::random::fisher_f_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::fisher_f_distribution<>::min)()
#else
            decltype(&boost::random::fisher_f_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::fisher_f_distribution<>::max)()
#else
            decltype(&boost::random::fisher_f_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::fisher_f_distribution<>::reset)()
#else
            decltype(&boost::random::fisher_f_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::random::student_t_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::student_t_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::student_t_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , boost::random::student_t_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::student_t_distribution<>::min)()
#else
            decltype(&boost::random::student_t_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::student_t_distribution<>::max)()
#else
            decltype(&boost::random::student_t_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::student_t_distribution<>::reset)()
#else
            decltype(&boost::random::student_t_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::random::discrete_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::discrete_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::discrete_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , boost::random::discrete_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::discrete_distribution<>::min)()
#else
            decltype(&boost::random::discrete_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::discrete_distribution<>::max)()
#else
            decltype(&boost::random::discrete_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::discrete_distribution<>::reset)()
#else
            decltype(&boost::random::discrete_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::random::piecewise_constant_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::piecewise_constant_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::piecewise_constant_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , boost::random::piecewise_constant_distribution<>
                ::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            (&boost::random::piecewise_constant_distribution<>::min)()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            (&boost::random::piecewise_constant_distribution<>::max)()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            (&boost::random::piecewise_constant_distribution<>::reset)()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::random::piecewise_linear_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::piecewise_linear_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::piecewise_linear_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , boost::random::piecewise_linear_distribution<>
                ::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            (&boost::random::piecewise_linear_distribution<>::min)()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            (&boost::random::piecewise_linear_distribution<>::max)()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
            decltype
#endif
            (&boost::random::piecewise_linear_distribution<>::reset)()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::random::triangle_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::triangle_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::random::triangle_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , boost::random::triangle_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::triangle_distribution<>::min)()
#else
            decltype(&boost::random::triangle_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::triangle_distribution<>::max)()
#else
            decltype(&boost::random::triangle_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::triangle_distribution<>::reset)()
#else
            decltype(&boost::random::triangle_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::random::uniform_on_sphere<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::random::uniform_on_sphere<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::random::uniform_on_sphere<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , boost::random::uniform_on_sphere<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::uniform_on_sphere<>::min)()
#else
            decltype(&boost::random::uniform_on_sphere<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::uniform_on_sphere<>::max)()
#else
            decltype(&boost::random::uniform_on_sphere<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&boost::random::uniform_on_sphere<>::reset)()
#else
            decltype(&boost::random::uniform_on_sphere<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    //->
}
//]

#if !defined BOOST_NO_CXX11_HDR_FUNCTIONAL
#include <functional>

//[test__is_callable_predicate__std_functional
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::hash<char const*>(char const*)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::function<int&(int)>(int)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::function<bool(char)>(char)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            std::function<void(void*)>(void*)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
//<-
#if !defined BOOST_NO_CXX11_RVALUE_REFERENCES
//->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::function<bool&&(char,char)>(char,char)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
//<-
#endif
//->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::function<char&(short,long)>(short,long)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            std::function<void(float,double)>(float,double)
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
}
//]
#endif  // !defined BOOST_NO_CXX11_HDR_FUNCTIONAL

#if !defined BOOST_NO_CXX11_HDR_RANDOM
#include <random>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::minstd_rand0()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::minstd_rand0::min)()
#else
            decltype(&std::minstd_rand0::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::minstd_rand0::max)()
#else
            decltype(&std::minstd_rand0::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::minstd_rand()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::minstd_rand::min)()
#else
            decltype(&std::minstd_rand::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::minstd_rand::max)()
#else
            decltype(&std::minstd_rand::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::mt19937()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::mt19937::min)()
#else
            decltype(&std::mt19937::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::mt19937::max)()
#else
            decltype(&std::mt19937::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::mt19937_64()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::mt19937_64::min)()
#else
            decltype(&std::mt19937_64::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::mt19937_64::max)()
#else
            decltype(&std::mt19937_64::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::ranlux24_base()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::ranlux24_base::min)()
#else
            decltype(&std::ranlux24_base::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::ranlux24_base::max)()
#else
            decltype(&std::ranlux24_base::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::ranlux48_base()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::ranlux48_base::min)()
#else
            decltype(&std::ranlux48_base::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::ranlux48_base::max)()
#else
            decltype(&std::ranlux48_base::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::ranlux24()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::ranlux24::min)()
#else
            decltype(&std::ranlux24::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::ranlux24::max)()
#else
            decltype(&std::ranlux24::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::ranlux48()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::ranlux48::min)()
#else
            decltype(&std::ranlux48::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::ranlux48::max)()
#else
            decltype(&std::ranlux48::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::knuth_b()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::knuth_b::min)()
#else
            decltype(&std::knuth_b::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::knuth_b::max)()
#else
            decltype(&std::knuth_b::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::random_device()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::random_device::min)()
#else
            decltype(&std::random_device::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::random_device::max)()
#else
            decltype(&std::random_device::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            std::uniform_int_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::uniform_int_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::uniform_int_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , std::uniform_int_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::uniform_int_distribution<>::min)()
#else
            decltype(&std::uniform_int_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::uniform_int_distribution<>::max)()
#else
            decltype(&std::uniform_int_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::uniform_int_distribution<>::reset)()
#else
            decltype(&std::uniform_int_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            std::uniform_real_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::uniform_real_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::uniform_real_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , std::uniform_real_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::uniform_real_distribution<>::min)()
#else
            decltype(&std::uniform_real_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::uniform_real_distribution<>::max)()
#else
            decltype(&std::uniform_real_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::uniform_real_distribution<>::reset)()
#else
            decltype(&std::uniform_real_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            std::bernoulli_distribution()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::bernoulli_distribution(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::bernoulli_distribution(
                boost::concept::value_generator_archetype<unsigned int>&
              , std::bernoulli_distribution::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::bernoulli_distribution::min)()
#else
            decltype(&std::bernoulli_distribution::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::bernoulli_distribution::max)()
#else
            decltype(&std::bernoulli_distribution::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::bernoulli_distribution::reset)()
#else
            decltype(&std::bernoulli_distribution::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            std::binomial_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::binomial_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::binomial_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , std::binomial_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::binomial_distribution<>::min)()
#else
            decltype(&std::binomial_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::binomial_distribution<>::max)()
#else
            decltype(&std::binomial_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::binomial_distribution<>::reset)()
#else
            decltype(&std::binomial_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            std::geometric_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::geometric_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::geometric_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , std::geometric_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::geometric_distribution<>::min)()
#else
            decltype(&std::geometric_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::geometric_distribution<>::max)()
#else
            decltype(&std::geometric_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::geometric_distribution<>::reset)()
#else
            decltype(&std::geometric_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            std::negative_binomial_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::negative_binomial_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::negative_binomial_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , std::negative_binomial_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::negative_binomial_distribution<>::min)()
#else
            decltype(&std::negative_binomial_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::negative_binomial_distribution<>::max)()
#else
            decltype(&std::negative_binomial_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::negative_binomial_distribution<>::reset)()
#else
            decltype(&std::negative_binomial_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            std::poisson_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::poisson_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::poisson_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , std::poisson_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::poisson_distribution<>::min)()
#else
            decltype(&std::poisson_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::poisson_distribution<>::max)()
#else
            decltype(&std::poisson_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::poisson_distribution<>::reset)()
#else
            decltype(&std::poisson_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            std::discrete_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::discrete_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::discrete_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , std::discrete_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::discrete_distribution<>::min)()
#else
            decltype(&std::discrete_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::discrete_distribution<>::max)()
#else
            decltype(&std::discrete_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::discrete_distribution<>::reset)()
#else
            decltype(&std::discrete_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            std::exponential_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::exponential_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::exponential_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , std::exponential_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::exponential_distribution<>::min)()
#else
            decltype(&std::exponential_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::exponential_distribution<>::max)()
#else
            decltype(&std::exponential_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::exponential_distribution<>::reset)()
#else
            decltype(&std::exponential_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            std::gamma_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::gamma_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::gamma_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , std::gamma_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::gamma_distribution<>::min)()
#else
            decltype(&std::gamma_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::gamma_distribution<>::max)()
#else
            decltype(&std::gamma_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::gamma_distribution<>::reset)()
#else
            decltype(&std::gamma_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            std::weibull_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::weibull_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::weibull_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , std::weibull_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::weibull_distribution<>::min)()
#else
            decltype(&std::weibull_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::weibull_distribution<>::max)()
#else
            decltype(&std::weibull_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::weibull_distribution<>::reset)()
#else
            decltype(&std::weibull_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            std::extreme_value_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::extreme_value_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::extreme_value_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , std::extreme_value_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::extreme_value_distribution<>::min)()
#else
            decltype(&std::extreme_value_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::extreme_value_distribution<>::max)()
#else
            decltype(&std::extreme_value_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::extreme_value_distribution<>::reset)()
#else
            decltype(&std::extreme_value_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            std::normal_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::normal_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::normal_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , std::normal_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::normal_distribution<>::min)()
#else
            decltype(&std::normal_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::normal_distribution<>::max)()
#else
            decltype(&std::normal_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::normal_distribution<>::reset)()
#else
            decltype(&std::normal_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            std::lognormal_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::lognormal_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::lognormal_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , std::lognormal_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::lognormal_distribution<>::min)()
#else
            decltype(&std::lognormal_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::lognormal_distribution<>::max)()
#else
            decltype(&std::lognormal_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::lognormal_distribution<>::reset)()
#else
            decltype(&std::lognormal_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            std::chi_squared_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::chi_squared_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::chi_squared_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , std::chi_squared_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::chi_squared_distribution<>::min)()
#else
            decltype(&std::chi_squared_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::chi_squared_distribution<>::max)()
#else
            decltype(&std::chi_squared_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::chi_squared_distribution<>::reset)()
#else
            decltype(&std::chi_squared_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            std::cauchy_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::cauchy_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::cauchy_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , std::cauchy_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::cauchy_distribution<>::min)()
#else
            decltype(&std::cauchy_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::cauchy_distribution<>::max)()
#else
            decltype(&std::cauchy_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::cauchy_distribution<>::reset)()
#else
            decltype(&std::cauchy_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            std::fisher_f_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::fisher_f_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::fisher_f_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , std::fisher_f_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::fisher_f_distribution<>::min)()
#else
            decltype(&std::fisher_f_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::fisher_f_distribution<>::max)()
#else
            decltype(&std::fisher_f_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::fisher_f_distribution<>::reset)()
#else
            decltype(&std::fisher_f_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            std::student_t_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::student_t_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::student_t_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , std::student_t_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::student_t_distribution<>::min)()
#else
            decltype(&std::student_t_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::student_t_distribution<>::max)()
#else
            decltype(&std::student_t_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::student_t_distribution<>::reset)()
#else
            decltype(&std::student_t_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            std::piecewise_constant_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::piecewise_constant_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::piecewise_constant_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , std::piecewise_constant_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::piecewise_constant_distribution<>::min)()
#else
            decltype(&std::piecewise_constant_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::piecewise_constant_distribution<>::max)()
#else
            decltype(&std::piecewise_constant_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::piecewise_constant_distribution<>::reset)()
#else
            decltype(&std::piecewise_constant_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            std::piecewise_linear_distribution<>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::piecewise_linear_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            std::piecewise_linear_distribution<>(
                boost::concept::value_generator_archetype<unsigned int>&
              , std::piecewise_linear_distribution<>::param_type const&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::piecewise_linear_distribution<>::min)()
#else
            decltype(&std::piecewise_linear_distribution<>::min)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::piecewise_linear_distribution<>::max)()
#else
            decltype(&std::piecewise_linear_distribution<>::max)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF(&std::piecewise_linear_distribution<>::reset)()
#else
            decltype(&std::piecewise_linear_distribution<>::reset)()
#endif
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
}
#endif  // !defined BOOST_NO_CXX11_HDR_RANDOM

