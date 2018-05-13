// Copyright (C) 2014-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/traits/trivial_access/result_of.hpp>

#include <utility>
#include <boost/any.hpp>
#include <boost/function.hpp>
#include <boost/functional/hash.hpp>
#include <boost/mpl/inherit.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>
#include <boost/mpl/aux_/has_type.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/is_convertible.hpp>
#include <boost/type_traits/is_void.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/typeof/typeof.hpp>
#endif

//[test__result_of
MPL_TEST_CASE()
{
//<-
#if defined(BOOST_NO_CXX11_DECLTYPE)
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF((&std::pair<char,short>::first))
            >::type
          , char
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::any::empty)()
            >::type
          , bool
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::any::swap)(boost::any&)
            >::type
          , boost::any&
        >
    ));
#else   // !defined(BOOST_NO_CXX11_DECLTYPE)
//->
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&std::pair<char,short>::first)
            >::type
          , char
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::any::empty)()
            >::type
          , bool
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::any::swap)(boost::any&)
            >::type
          , boost::any&
        >
    ));
//<-
#endif  // BOOST_NO_CXX11_DECLTYPE
//->

    typedef boost::mpl::inherit<boost::any>::type any_more;

//<-
#if defined(BOOST_NO_CXX11_DECLTYPE)
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&any_more::empty)()
            >::type
          , bool
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&any_more::swap)(boost::any&)
            >::type
          , boost::any&
        >
    ));
#else   // !defined(BOOST_NO_CXX11_DECLTYPE)
//->
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&any_more::empty)()
            >::type
          , bool
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&any_more::swap)(boost::any&)
            >::type
          , boost::any&
        >
    ));
//<-
#endif  // BOOST_NO_CXX11_DECLTYPE
//->
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::plus<int>(int,int)
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::minus<int>(int,int)
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::multiplies<int>(int,int)
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::divides<int>(int,int)
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::modulus<int>(int,int)
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::negate<int>(int)
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::equal_to<int>(int,int)
            >::type
          , bool
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::not_equal_to<int>(int,int)
            >::type
          , bool
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::less<int>(int,int)
            >::type
          , bool
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::greater<int>(int,int)
            >::type
          , bool
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::less_equal<int>(int,int)
            >::type
          , bool
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::greater_equal<int>(int,int)
            >::type
          , bool
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::logical_and<bool>(bool,bool)
            >::type
          , bool
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::logical_or<bool>(bool,bool)
            >::type
          , bool
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::logical_not<bool>(bool)
            >::type
          , bool
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::bit_and<unsigned>(unsigned,unsigned)
            >::type
          , unsigned
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::bit_or<unsigned>(unsigned,unsigned)
            >::type
          , unsigned
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::bit_xor<unsigned>(unsigned,unsigned)
            >::type
          , unsigned
        >
    ));
    //->
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::hash<char const*>(char const*)
            >::type
          , std::size_t
        >
    ));
//<-
#if defined(BOOST_NO_CXX11_DECLTYPE)
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::function1<int&,int>(int)
            >::type
          , int
        >
    ));
#else
//->
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::function1<int&,int>(int)
            >::type
          , int&
        >
    ));
//<-
#endif
#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
#if defined(BOOST_NO_CXX11_DECLTYPE)
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::function1<bool&&,char>(char)
            >::type
          , bool
        >
    ));
#else
//->
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::function1<bool&&,char>(char)
            >::type
          , bool&&
        >
    ));
//<-
#endif
#endif  // BOOST_NO_CXX11_RVALUE_REFERENCES
//->
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
                boost::function1<void,void*>(void*)
            >::type
        >
    ));
//<-
#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
#if defined(BOOST_NO_CXX11_DECLTYPE)
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::function2<bool&&,char,char>(char,char)
            >::type
          , bool
        >
    ));
#else
//->
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::function2<bool&&,char,char>(char,char)
            >::type
          , bool&&
        >
    ));
//<-
#endif
#endif  // BOOST_NO_CXX11_RVALUE_REFERENCES
#if defined(BOOST_NO_CXX11_DECLTYPE)
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::function2<char&,short,long>(short,long)
            >::type
          , char
        >
    ));
#else
//->
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::function2<char&,short,long>(short,long)
            >::type
          , char&
        >
    ));
//<-
#endif
//->
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
                boost::function2<void,float,double>(float,double)
            >::type
        >
    ));
}
//]

//[test__result_of__no_return
MPL_TEST_CASE()
{
//<-
#if defined(BOOST_NO_CXX11_DECLTYPE)
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::any::empty)(boost::any const&)
            >
        >::type
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::any::swap)()
            >
        >::type
    ));
#else   // !defined(BOOST_NO_CXX11_DECLTYPE)
//->
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                decltype(&boost::any::empty)(boost::any const&)
            >
        >::type
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<decltype(&boost::any::swap)()>
        >::type
    ));
//<-
#endif  // BOOST_NO_CXX11_DECLTYPE
//->
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::plus<int>()>
        >::type
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::minus<int>()>
        >::type
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::multiplies<int>()>
        >::type
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::divides<int>()>
        >::type
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::modulus<int>()>
        >::type
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::negate<int>()>
        >::type
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::equal_to<int>()>
        >::type
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::not_equal_to<int>()>
        >::type
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::less<int>()>
        >::type
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::greater<int>()>
        >::type
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::less_equal<int>()>
        >::type
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::greater_equal<int>()>
        >::type
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::logical_and<bool>()>
        >::type
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::logical_or<bool>()>
        >::type
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::logical_not<bool>()>
        >::type
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::bit_and<unsigned>()>
        >::type
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::bit_or<unsigned>()>
        >::type
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::bit_xor<unsigned>()>
        >::type
    ));
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<boost::hash<char const*>()>
        >::type
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<boost::function1<int&,int>()>
        >::type
    ));
//<-
#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
//->
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<boost::function1<bool&&,char>()>
        >::type
    ));
//<-
#endif
//->
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<boost::function1<void,void*>()>
        >::type
    ));
//<-
#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
//->
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                boost::function2<bool&&,char,char>()
            >
        >::type
    ));
//<-
#endif
//->
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                boost::function2<char&,short,long>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                boost::function2<void,float,double>()
            >
        >::type
    ));
    // ...
}
//]

#include <boost/concept/archetype/value_generator.hpp>
#include <boost/random.hpp>
#include <boost/cstdint.hpp>

//[test__result_of__boost_random
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::minstd_rand0()
            >::type
          , boost::uint32_t
        >
    ));
//<-
#if defined(BOOST_NO_CXX11_DECLTYPE)
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::minstd_rand0::min)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::minstd_rand0::max)()
            >::type
          , boost::uint32_t
        >
    ));
#else   // !defined(BOOST_NO_CXX11_DECLTYPE)
//->
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::minstd_rand0::min)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::minstd_rand0::max)()
            >::type
          , boost::uint32_t
        >
    ));
//<-
#endif  // BOOST_NO_CXX11_DECLTYPE
//->
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::minstd_rand()
            >::type
          , boost::uint32_t
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::rand48()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::ecuyer1988()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::knuth_b()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::kreutzer1986()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::taus88()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::hellekalek1995()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::mt11213b()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::mt19937()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::mt19937_64()
            >::type
          , boost::uint64_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::lagged_fibonacci607()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::lagged_fibonacci1279()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::lagged_fibonacci2281()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::lagged_fibonacci3217()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::lagged_fibonacci4423()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::lagged_fibonacci9689()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::lagged_fibonacci19937()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::lagged_fibonacci23209()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::ranlux3()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::ranlux4()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::ranlux64_3()
            >::type
          , boost::uint64_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::ranlux64_4()
            >::type
          , boost::uint64_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::ranlux3_01()
            >::type
          , float
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::ranlux4_01()
            >::type
          , float
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::ranlux64_3_01()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::ranlux64_4_01()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::ranlux24()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::ranlux48()
            >::type
          , boost::uint64_t
        >
    ));
#if defined(BOOST_NO_CXX11_DECLTYPE)
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::minstd_rand::min)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::minstd_rand::max)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::rand48::min)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::rand48::max)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::ecuyer1988::min)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::ecuyer1988::max)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::knuth_b::min)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::knuth_b::max)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::kreutzer1986::min)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::kreutzer1986::max)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::taus88::min)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::taus88::max)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::hellekalek1995::min)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::hellekalek1995::max)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::mt11213b::min)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::mt11213b::max)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::mt19937::min)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::mt19937::max)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::mt19937_64::min)()
            >::type
          , boost::uint64_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::mt19937_64::max)()
            >::type
          , boost::uint64_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::lagged_fibonacci607::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::lagged_fibonacci607::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::lagged_fibonacci1279::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::lagged_fibonacci1279::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::lagged_fibonacci2281::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::lagged_fibonacci2281::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::lagged_fibonacci3217::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::lagged_fibonacci3217::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::lagged_fibonacci4423::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::lagged_fibonacci4423::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::lagged_fibonacci9689::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::lagged_fibonacci9689::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::lagged_fibonacci19937::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::lagged_fibonacci19937::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::lagged_fibonacci23209::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::lagged_fibonacci23209::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::ranlux3::min)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::ranlux3::max)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::ranlux4::min)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::ranlux4::max)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::ranlux64_3::min)()
            >::type
          , boost::uint64_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::ranlux64_3::max)()
            >::type
          , boost::uint64_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::ranlux64_4::min)()
            >::type
          , boost::uint64_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::ranlux64_4::max)()
            >::type
          , boost::uint64_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::ranlux3_01::min)()
            >::type
          , float
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::ranlux3_01::max)()
            >::type
          , float
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::ranlux4_01::min)()
            >::type
          , float
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::ranlux4_01::max)()
            >::type
          , float
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::ranlux64_3_01::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::ranlux64_3_01::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::ranlux64_4_01::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::ranlux64_4_01::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::ranlux24::min)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::ranlux24::max)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::ranlux48::min)()
            >::type
          , boost::uint64_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::ranlux48::max)()
            >::type
          , boost::uint64_t
        >
    ));
#else   // !defined(BOOST_NO_CXX11_DECLTYPE)
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::minstd_rand::min)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::minstd_rand::max)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::rand48::min)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::rand48::max)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::ecuyer1988::min)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::ecuyer1988::max)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::knuth_b::min)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::knuth_b::max)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::kreutzer1986::min)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::kreutzer1986::max)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::taus88::min)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::taus88::max)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::hellekalek1995::min)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::hellekalek1995::max)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::mt11213b::min)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::mt11213b::max)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::mt19937::min)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::mt19937::max)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::mt19937_64::min)()
            >::type
          , boost::uint64_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::mt19937_64::max)()
            >::type
          , boost::uint64_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::lagged_fibonacci607::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::lagged_fibonacci607::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::lagged_fibonacci1279::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::lagged_fibonacci1279::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::lagged_fibonacci2281::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::lagged_fibonacci2281::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::lagged_fibonacci3217::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::lagged_fibonacci3217::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::lagged_fibonacci4423::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::lagged_fibonacci4423::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::lagged_fibonacci9689::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::lagged_fibonacci9689::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::lagged_fibonacci19937::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::lagged_fibonacci19937::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::lagged_fibonacci23209::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::lagged_fibonacci23209::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::ranlux3::min)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::ranlux3::max)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::ranlux4::min)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::ranlux4::max)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::ranlux64_3::min)()
            >::type
          , boost::uint64_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::ranlux64_3::max)()
            >::type
          , boost::uint64_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::ranlux64_4::min)()
            >::type
          , boost::uint64_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::ranlux64_4::max)()
            >::type
          , boost::uint64_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::ranlux3_01::min)()
            >::type
          , float
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::ranlux3_01::max)()
            >::type
          , float
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::ranlux4_01::min)()
            >::type
          , float
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::ranlux4_01::max)()
            >::type
          , float
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::ranlux64_3_01::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::ranlux64_3_01::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::ranlux64_4_01::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::ranlux64_4_01::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::ranlux24::min)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::ranlux24::max)()
            >::type
          , boost::uint32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::ranlux48::min)()
            >::type
          , boost::uint64_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::ranlux48::max)()
            >::type
          , boost::uint64_t
        >
    ));
#endif  // BOOST_NO_CXX11_DECLTYPE
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                boost::random::uniform_smallint<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::uniform_smallint<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::uniform_smallint<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , boost::random::uniform_smallint<>::param_type const&
                )
            >::type
          , int
        >
    ));
//<-
#if defined(BOOST_NO_CXX11_DECLTYPE)
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::uniform_smallint<>::min)()
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::uniform_smallint<>::max)()
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::uniform_smallint<>::reset)()
            >::type
        >
    ));
#else   // !defined(BOOST_NO_CXX11_DECLTYPE)
//->
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::uniform_smallint<>::min)()
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::uniform_smallint<>::max)()
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
                decltype(&boost::random::uniform_smallint<>::reset)()
            >::type
        >
    ));
//<-
#endif  // BOOST_NO_CXX11_DECLTYPE
//->
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                boost::random::uniform_int_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::uniform_int_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::uniform_int_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , boost::random::uniform_int_distribution<>
                    ::param_type const&
                )
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<boost::random::uniform_01<>()>
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::uniform_01<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                boost::random::uniform_real_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::uniform_real_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::uniform_real_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , boost::random::uniform_real_distribution<>
                    ::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                boost::random::poisson_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::poisson_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::poisson_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , boost::random::poisson_distribution<>::param_type const&
                )
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                boost::random::exponential_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::exponential_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::exponential_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , boost::random::exponential_distribution<>
                    ::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                boost::random::gamma_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::gamma_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::gamma_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , boost::random::gamma_distribution<>::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                boost::random::weibull_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::weibull_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::weibull_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , boost::random::weibull_distribution<>::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                boost::random::extreme_value_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::extreme_value_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::extreme_value_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , boost::random::extreme_value_distribution<>
                    ::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                boost::random::beta_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::beta_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::beta_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , boost::random::beta_distribution<>::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                boost::random::laplace_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::laplace_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::laplace_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , boost::random::laplace_distribution<>::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                boost::random::normal_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::normal_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::normal_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , boost::random::normal_distribution<>::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                boost::random::lognormal_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::lognormal_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::lognormal_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , boost::random::lognormal_distribution<>::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                boost::random::chi_squared_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::chi_squared_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::chi_squared_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , boost::random::chi_squared_distribution<>
                    ::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                boost::random::non_central_chi_squared_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::non_central_chi_squared_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::non_central_chi_squared_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , boost::random::non_central_chi_squared_distribution<>
                    ::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                boost::random::cauchy_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::cauchy_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::cauchy_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , boost::random::cauchy_distribution<>::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                boost::random::fisher_f_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::fisher_f_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::fisher_f_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , boost::random::fisher_f_distribution<>::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                boost::random::student_t_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::student_t_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::student_t_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , boost::random::student_t_distribution<>::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                boost::random::discrete_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::discrete_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::discrete_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , boost::random::discrete_distribution<>::param_type const&
                )
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                boost::random::piecewise_constant_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::piecewise_constant_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::piecewise_constant_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , boost::random::piecewise_constant_distribution<>
                    ::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                boost::random::piecewise_linear_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::piecewise_linear_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::piecewise_linear_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , boost::random::piecewise_linear_distribution<>
                    ::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                boost::random::triangle_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::triangle_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::triangle_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , boost::random::triangle_distribution<>::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                boost::random::uniform_on_sphere<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_convertible<
            boost::concept::traits::result_of<
                boost::random::uniform_on_sphere<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , std::vector<double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                boost::random::uniform_on_sphere<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , boost::random::uniform_on_sphere<>::param_type const&
                )
            >::type
          , std::vector<double>
        >
    ));
#if defined(BOOST_NO_CXX11_DECLTYPE)
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(
                    &boost::random::uniform_int_distribution<>::min
                )()
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(
                    &boost::random::uniform_int_distribution<>::max
                )()
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(
                    &boost::random::uniform_int_distribution<>::reset
                )()
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::uniform_01<>::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::uniform_01<>::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(
                    &boost::random::uniform_real_distribution<>::min
                )()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(
                    &boost::random::uniform_real_distribution<>::max
                )()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(
                    &boost::random::uniform_real_distribution<>::reset
                )()
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::poisson_distribution<>::min)()
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::poisson_distribution<>::max)()
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::poisson_distribution<>::reset)()
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(
                    &boost::random::exponential_distribution<>::min
                )()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(
                    &boost::random::exponential_distribution<>::max
                )()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(
                    &boost::random::exponential_distribution<>::reset
                )()
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::gamma_distribution<>::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::gamma_distribution<>::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::gamma_distribution<>::reset)()
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::weibull_distribution<>::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::weibull_distribution<>::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::weibull_distribution<>::reset)()
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(
                    &boost::random::extreme_value_distribution<>::min
                )()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(
                    &boost::random::extreme_value_distribution<>::max
                )()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(
                    &boost::random::extreme_value_distribution<>::reset
                )()
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::beta_distribution<>::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::beta_distribution<>::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
                BOOST_TYPEOF(&boost::random::beta_distribution<>::reset)()
            >::type
        >
    ));
#else   // !defined(BOOST_NO_CXX11_DECLTYPE)
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::uniform_int_distribution<>::min)()
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::uniform_int_distribution<>::max)()
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
                decltype(&boost::random::uniform_int_distribution<>::reset)()
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::uniform_01<>::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::uniform_01<>::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::uniform_real_distribution<>::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::uniform_real_distribution<>::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
                decltype(&boost::random::uniform_real_distribution<>::reset)()
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::poisson_distribution<>::min)()
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::poisson_distribution<>::max)()
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
                decltype(&boost::random::poisson_distribution<>::reset)()
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::exponential_distribution<>::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::exponential_distribution<>::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
                decltype(&boost::random::exponential_distribution<>::reset)()
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::gamma_distribution<>::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::gamma_distribution<>::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
                decltype(&boost::random::gamma_distribution<>::reset)()
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::weibull_distribution<>::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::weibull_distribution<>::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
                decltype(&boost::random::weibull_distribution<>::reset)()
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::extreme_value_distribution<>::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::extreme_value_distribution<>::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
                decltype(
                    &boost::random::extreme_value_distribution<>::reset
                )()
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::beta_distribution<>::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                decltype(&boost::random::beta_distribution<>::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
                decltype(&boost::random::beta_distribution<>::reset)()
            >::type
        >
    ));
#endif
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&boost::random::laplace_distribution<>::min)()
#else
                decltype(&boost::random::laplace_distribution<>::min)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&boost::random::laplace_distribution<>::max)()
#else
                decltype(&boost::random::laplace_distribution<>::max)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&boost::random::laplace_distribution<>::reset)()
#else
                decltype(&boost::random::laplace_distribution<>::reset)()
#endif
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&boost::random::normal_distribution<>::min)()
#else
                decltype(&boost::random::normal_distribution<>::min)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&boost::random::normal_distribution<>::max)()
#else
                decltype(&boost::random::normal_distribution<>::max)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&boost::random::normal_distribution<>::reset)()
#else
                decltype(&boost::random::normal_distribution<>::reset)()
#endif
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&boost::random::lognormal_distribution<>::min)()
#else
                decltype(&boost::random::lognormal_distribution<>::min)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&boost::random::lognormal_distribution<>::max)()
#else
                decltype(&boost::random::lognormal_distribution<>::max)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF
#else
                decltype
#endif
                (&boost::random::lognormal_distribution<>::reset)()
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF
#else
                decltype
#endif
                (&boost::random::chi_squared_distribution<>::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF
#else
                decltype
#endif
                (&boost::random::chi_squared_distribution<>::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF
#else
                decltype
#endif
                (&boost::random::chi_squared_distribution<>::reset)()
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF
#else
                decltype
#endif
                (
                    &boost::random::non_central_chi_squared_distribution<>
                    ::min
                )()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF
#else
                decltype
#endif
                (
                    &boost::random::non_central_chi_squared_distribution<>
                    ::max
                )()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF
#else
                decltype
#endif
                (
                    &boost::random::non_central_chi_squared_distribution<>
                    ::reset
                )()
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&boost::random::cauchy_distribution<>::min)()
#else
                decltype(&boost::random::cauchy_distribution<>::min)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&boost::random::cauchy_distribution<>::max)()
#else
                decltype(&boost::random::cauchy_distribution<>::max)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&boost::random::cauchy_distribution<>::reset)()
#else
                decltype(&boost::random::cauchy_distribution<>::reset)()
#endif
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&boost::random::fisher_f_distribution<>::min)()
#else
                decltype(&boost::random::fisher_f_distribution<>::min)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&boost::random::fisher_f_distribution<>::max)()
#else
                decltype(&boost::random::fisher_f_distribution<>::max)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&boost::random::fisher_f_distribution<>::reset)()
#else
                decltype(&boost::random::fisher_f_distribution<>::reset)()
#endif
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&boost::random::student_t_distribution<>::min)()
#else
                decltype(&boost::random::student_t_distribution<>::min)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&boost::random::student_t_distribution<>::max)()
#else
                decltype(&boost::random::student_t_distribution<>::max)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF
#else
                decltype
#endif
                (&boost::random::student_t_distribution<>::reset)()
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&boost::random::discrete_distribution<>::min)()
#else
                decltype(&boost::random::discrete_distribution<>::min)()
#endif
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&boost::random::discrete_distribution<>::max)()
#else
                decltype(&boost::random::discrete_distribution<>::max)()
#endif
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&boost::random::discrete_distribution<>::reset)()
#else
                decltype(&boost::random::discrete_distribution<>::reset)()
#endif
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF
#else
                decltype
#endif
                (&boost::random::piecewise_constant_distribution<>::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF
#else
                decltype
#endif
                (&boost::random::piecewise_constant_distribution<>::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF
#else
                decltype
#endif
                (&boost::random::piecewise_constant_distribution<>::reset)()
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF
#else
                decltype
#endif
                (&boost::random::piecewise_linear_distribution<>::min)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF
#else
                decltype
#endif
                (&boost::random::piecewise_linear_distribution<>::max)()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF
#else
                decltype
#endif
                (&boost::random::piecewise_linear_distribution<>::reset)()
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&boost::random::triangle_distribution<>::min)()
#else
                decltype(&boost::random::triangle_distribution<>::min)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&boost::random::triangle_distribution<>::max)()
#else
                decltype(&boost::random::triangle_distribution<>::max)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&boost::random::triangle_distribution<>::reset)()
#else
                decltype(&boost::random::triangle_distribution<>::reset)()
#endif
            >::type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&boost::random::uniform_on_sphere<>::min)()
#else
                decltype(&boost::random::uniform_on_sphere<>::min)()
#endif
            >::type
          , std::vector<double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&boost::random::uniform_on_sphere<>::max)()
#else
                decltype(&boost::random::uniform_on_sphere<>::max)()
#endif
            >::type
          , std::vector<double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&boost::random::uniform_on_sphere<>::reset)()
#else
                decltype(&boost::random::uniform_on_sphere<>::reset)()
#endif
            >::type
        >
    ));
    //->
}
//]

#if !defined(BOOST_NO_CXX11_HDR_FUNCTIONAL)
#include <functional>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::hash<char const*>()>
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::hash<char const*>(char const*)
            >::type
          , std::size_t
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::function<int&(int)>()>
        >::type
    ));
#if defined(BOOST_NO_CXX11_DECLTYPE)
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::function<int&(int)>(int)
            >::type
          , int
        >
    ));
#else
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::function<int&(int)>(int)
            >::type
          , int&
        >
    ));
#endif
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::function<bool(char)>()>
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::function<bool(char)>(char)
            >::type
          , bool
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::function<void(void*)>()>
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
                std::function<void(void*)>(void*)
            >::type
        >
    ));
#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                std::function<bool&&(char,char)>()
            >
        >::type
    ));
#if defined(BOOST_NO_CXX11_DECLTYPE)
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::function<bool&&(char,char)>(char,char)
            >::type
          , bool
        >
    ));
#else
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::function<bool&&(char,char)>(char,char)
            >::type
          , bool&&
        >
    ));
#endif
#endif  // BOOST_NO_CXX11_RVALUE_REFERENCES
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                std::function<char&(short,long)>()
            >
        >::type
    ));
#if defined(BOOST_NO_CXX11_DECLTYPE)
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::function<char&(short,long)>(short,long)
            >::type
          , char
        >
    ));
#else
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::function<char&(short,long)>(short,long)
            >::type
          , char&
        >
    ));
#endif
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                std::function<void(float,double)>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
                std::function<void(float,double)>(float,double)
            >::type
        >
    ));
}
#endif  // !defined(BOOST_NO_CXX11_HDR_FUNCTIONAL)

#if !defined(BOOST_NO_CXX11_HDR_RANDOM)
#include <random>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<std::minstd_rand0()>::type
          , std::uint_fast32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::minstd_rand0::min)()
#else
                decltype(&std::minstd_rand0::min)()
#endif
            >::type
          , std::uint_fast32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::minstd_rand0::max)()
#else
                decltype(&std::minstd_rand0::max)()
#endif
            >::type
          , std::uint_fast32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<std::minstd_rand()>::type
          , std::uint_fast32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::minstd_rand::min)()
#else
                decltype(&std::minstd_rand::min)()
#endif
            >::type
          , std::uint_fast32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::minstd_rand::max)()
#else
                decltype(&std::minstd_rand::max)()
#endif
            >::type
          , std::uint_fast32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<std::mt19937()>::type
          , std::uint_fast32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::mt19937::min)()
#else
                decltype(&std::mt19937::min)()
#endif
            >::type
          , std::uint_fast32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::mt19937::max)()
#else
                decltype(&std::mt19937::max)()
#endif
            >::type
          , std::uint_fast32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<std::mt19937_64()>::type
          , std::uint_fast64_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::mt19937_64::min)()
#else
                decltype(&std::mt19937_64::min)()
#endif
            >::type
          , std::uint_fast64_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::mt19937_64::max)()
#else
                decltype(&std::mt19937_64::max)()
#endif
            >::type
          , std::uint_fast64_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<std::ranlux24_base()>::type
          , std::uint_fast32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::ranlux24_base::min)()
#else
                decltype(&std::ranlux24_base::min)()
#endif
            >::type
          , std::uint_fast32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::ranlux24_base::max)()
#else
                decltype(&std::ranlux24_base::max)()
#endif
            >::type
          , std::uint_fast32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<std::ranlux48_base()>::type
          , std::uint_fast64_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::ranlux48_base::min)()
#else
                decltype(&std::ranlux48_base::min)()
#endif
            >::type
          , std::uint_fast64_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::ranlux48_base::max)()
#else
                decltype(&std::ranlux48_base::max)()
#endif
            >::type
          , std::uint_fast64_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<std::ranlux24()>::type
          , std::uint_fast32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::ranlux24::min)()
#else
                decltype(&std::ranlux24::min)()
#endif
            >::type
          , std::uint_fast32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::ranlux24::max)()
#else
                decltype(&std::ranlux24::max)()
#endif
            >::type
          , std::uint_fast32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<std::ranlux48()>::type
          , std::uint_fast64_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::ranlux48::min)()
#else
                decltype(&std::ranlux48::min)()
#endif
            >::type
          , std::uint_fast64_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::ranlux48::max)()
#else
                decltype(&std::ranlux48::max)()
#endif
            >::type
          , std::uint_fast64_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<std::knuth_b()>::type
          , std::uint_fast32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::knuth_b::min)()
#else
                decltype(&std::knuth_b::min)()
#endif
            >::type
          , std::uint_fast32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::knuth_b::max)()
#else
                decltype(&std::knuth_b::max)()
#endif
            >::type
          , std::uint_fast32_t
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<std::random_device()>::type
          , unsigned int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::random_device::min)()
#else
                decltype(&std::random_device::min)()
#endif
            >::type
          , unsigned int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::random_device::max)()
#else
                decltype(&std::random_device::max)()
#endif
            >::type
          , unsigned int
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                std::uniform_int_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::uniform_int_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::uniform_int_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , std::uniform_int_distribution<>::param_type const&
                )
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::uniform_int_distribution<>::min)()
#else
                decltype(&std::uniform_int_distribution<>::min)()
#endif
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::uniform_int_distribution<>::max)()
#else
                decltype(&std::uniform_int_distribution<>::max)()
#endif
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::uniform_int_distribution<>::reset)()
#else
                decltype(&std::uniform_int_distribution<>::reset)()
#endif
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                std::uniform_real_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::uniform_real_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::uniform_real_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , std::uniform_real_distribution<>::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::uniform_real_distribution<>::min)()
#else
                decltype(&std::uniform_real_distribution<>::min)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::uniform_real_distribution<>::max)()
#else
                decltype(&std::uniform_real_distribution<>::max)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::uniform_real_distribution<>::reset)()
#else
                decltype(&std::uniform_real_distribution<>::reset)()
#endif
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::bernoulli_distribution()>
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::bernoulli_distribution(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , bool
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::bernoulli_distribution(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , std::bernoulli_distribution::param_type const&
                )
            >::type
          , bool
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::bernoulli_distribution::min)()
#else
                decltype(&std::bernoulli_distribution::min)()
#endif
            >::type
          , bool
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::bernoulli_distribution::max)()
#else
                decltype(&std::bernoulli_distribution::max)()
#endif
            >::type
          , bool
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::bernoulli_distribution::reset)()
#else
                decltype(&std::bernoulli_distribution::reset)()
#endif
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::binomial_distribution<>()>
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::binomial_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::binomial_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , std::binomial_distribution<>::param_type const&
                )
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::binomial_distribution<>::min)()
#else
                decltype(&std::binomial_distribution<>::min)()
#endif
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::binomial_distribution<>::max)()
#else
                decltype(&std::binomial_distribution<>::max)()
#endif
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::binomial_distribution<>::reset)()
#else
                decltype(&std::binomial_distribution<>::reset)()
#endif
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::geometric_distribution<>()>
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::geometric_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::geometric_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , std::geometric_distribution<>::param_type const&
                )
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::geometric_distribution<>::min)()
#else
                decltype(&std::geometric_distribution<>::min)()
#endif
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::geometric_distribution<>::max)()
#else
                decltype(&std::geometric_distribution<>::max)()
#endif
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::geometric_distribution<>::reset)()
#else
                decltype(&std::geometric_distribution<>::reset)()
#endif
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                std::negative_binomial_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::negative_binomial_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::negative_binomial_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , std::negative_binomial_distribution<>::param_type const&
                )
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::negative_binomial_distribution<>::min)()
#else
                decltype(&std::negative_binomial_distribution<>::min)()
#endif
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::negative_binomial_distribution<>::max)()
#else
                decltype(&std::negative_binomial_distribution<>::max)()
#endif
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::negative_binomial_distribution<>::reset)()
#else
                decltype(&std::negative_binomial_distribution<>::reset)()
#endif
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::poisson_distribution<>()>
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::poisson_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::poisson_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , std::poisson_distribution<>::param_type const&
                )
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::poisson_distribution<>::min)()
#else
                decltype(&std::poisson_distribution<>::min)()
#endif
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::poisson_distribution<>::max)()
#else
                decltype(&std::poisson_distribution<>::max)()
#endif
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::poisson_distribution<>::reset)()
#else
                decltype(&std::poisson_distribution<>::reset)()
#endif
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::discrete_distribution<>()>
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::discrete_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::discrete_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , std::discrete_distribution<>::param_type const&
                )
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::discrete_distribution<>::min)()
#else
                decltype(&std::discrete_distribution<>::min)()
#endif
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::discrete_distribution<>::max)()
#else
                decltype(&std::discrete_distribution<>::max)()
#endif
            >::type
          , int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::discrete_distribution<>::reset)()
#else
                decltype(&std::discrete_distribution<>::reset)()
#endif
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                std::exponential_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::exponential_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::exponential_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , std::exponential_distribution<>::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::exponential_distribution<>::min)()
#else
                decltype(&std::exponential_distribution<>::min)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::exponential_distribution<>::max)()
#else
                decltype(&std::exponential_distribution<>::max)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::exponential_distribution<>::reset)()
#else
                decltype(&std::exponential_distribution<>::reset)()
#endif
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::gamma_distribution<>()>
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::gamma_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::gamma_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , std::gamma_distribution<>::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::gamma_distribution<>::min)()
#else
                decltype(&std::gamma_distribution<>::min)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::gamma_distribution<>::max)()
#else
                decltype(&std::gamma_distribution<>::max)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::gamma_distribution<>::reset)()
#else
                decltype(&std::gamma_distribution<>::reset)()
#endif
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::weibull_distribution<>()>
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::weibull_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::weibull_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , std::weibull_distribution<>::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::weibull_distribution<>::min)()
#else
                decltype(&std::weibull_distribution<>::min)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::weibull_distribution<>::max)()
#else
                decltype(&std::weibull_distribution<>::max)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::weibull_distribution<>::reset)()
#else
                decltype(&std::weibull_distribution<>::reset)()
#endif
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                std::extreme_value_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::extreme_value_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::extreme_value_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , std::extreme_value_distribution<>::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::extreme_value_distribution<>::min)()
#else
                decltype(&std::extreme_value_distribution<>::min)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::extreme_value_distribution<>::max)()
#else
                decltype(&std::extreme_value_distribution<>::max)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::extreme_value_distribution<>::reset)()
#else
                decltype(&std::extreme_value_distribution<>::reset)()
#endif
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::normal_distribution<>()>
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::normal_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::normal_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , std::normal_distribution<>::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::normal_distribution<>::min)()
#else
                decltype(&std::normal_distribution<>::min)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::normal_distribution<>::max)()
#else
                decltype(&std::normal_distribution<>::max)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::normal_distribution<>::reset)()
#else
                decltype(&std::normal_distribution<>::reset)()
#endif
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::lognormal_distribution<>()>
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::lognormal_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::lognormal_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , std::lognormal_distribution<>::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::lognormal_distribution<>::min)()
#else
                decltype(&std::lognormal_distribution<>::min)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::lognormal_distribution<>::max)()
#else
                decltype(&std::lognormal_distribution<>::max)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::lognormal_distribution<>::reset)()
#else
                decltype(&std::lognormal_distribution<>::reset)()
#endif
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                std::chi_squared_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::chi_squared_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::chi_squared_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , std::chi_squared_distribution<>::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::chi_squared_distribution<>::min)()
#else
                decltype(&std::chi_squared_distribution<>::min)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::chi_squared_distribution<>::max)()
#else
                decltype(&std::chi_squared_distribution<>::max)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::chi_squared_distribution<>::reset)()
#else
                decltype(&std::chi_squared_distribution<>::reset)()
#endif
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::cauchy_distribution<>()>
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::cauchy_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::cauchy_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , std::cauchy_distribution<>::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::cauchy_distribution<>::min)()
#else
                decltype(&std::cauchy_distribution<>::min)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::cauchy_distribution<>::max)()
#else
                decltype(&std::cauchy_distribution<>::max)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::cauchy_distribution<>::reset)()
#else
                decltype(&std::cauchy_distribution<>::reset)()
#endif
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::fisher_f_distribution<>()>
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::fisher_f_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::fisher_f_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , std::fisher_f_distribution<>::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::fisher_f_distribution<>::min)()
#else
                decltype(&std::fisher_f_distribution<>::min)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::fisher_f_distribution<>::max)()
#else
                decltype(&std::fisher_f_distribution<>::max)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::fisher_f_distribution<>::reset)()
#else
                decltype(&std::fisher_f_distribution<>::reset)()
#endif
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<std::student_t_distribution<>()>
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::student_t_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::student_t_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , std::student_t_distribution<>::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::student_t_distribution<>::min)()
#else
                decltype(&std::student_t_distribution<>::min)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::student_t_distribution<>::max)()
#else
                decltype(&std::student_t_distribution<>::max)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::student_t_distribution<>::reset)()
#else
                decltype(&std::student_t_distribution<>::reset)()
#endif
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                std::piecewise_constant_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::piecewise_constant_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::piecewise_constant_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , std::piecewise_constant_distribution<>::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::piecewise_constant_distribution<>::min)()
#else
                decltype(&std::piecewise_constant_distribution<>::min)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::piecewise_constant_distribution<>::max)()
#else
                decltype(&std::piecewise_constant_distribution<>::max)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::piecewise_constant_distribution<>::reset)()
#else
                decltype(&std::piecewise_constant_distribution<>::reset)()
#endif
            >::type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::mpl::aux::has_type<
            boost::concept::traits::result_of<
                std::piecewise_linear_distribution<>()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::piecewise_linear_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
                std::piecewise_linear_distribution<>(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , std::piecewise_linear_distribution<>::param_type const&
                )
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::piecewise_linear_distribution<>::min)()
#else
                decltype(&std::piecewise_linear_distribution<>::min)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::piecewise_linear_distribution<>::max)()
#else
                decltype(&std::piecewise_linear_distribution<>::max)()
#endif
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
            boost::concept::traits::result_of<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF(&std::piecewise_linear_distribution<>::reset)()
#else
                decltype(&std::piecewise_linear_distribution<>::reset)()
#endif
            >::type
        >
    ));
}
#endif  // !defined(BOOST_NO_CXX11_HDR_RANDOM)

