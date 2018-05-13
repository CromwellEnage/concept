// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/traits/query/is_adaptable_unary_func.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

#include <boost/concept_archetype.hpp>
#include <boost/concept/archetype/indexable_iterator.hpp>
#include <boost/concept/archetype/mutable_indexable_iterator.hpp>

//[test__is_adaptable_unary_function__archetypes
MPL_TEST_CASE()
{
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::boolean_archetype
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::equality_comparable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::less_than_comparable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::comparable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::addable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::subtractable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::multipliable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::dividable_archetype<>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::modable_archetype<>
        >
    ));
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::void_generator_archetype
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::generator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::unary_function_archetype<short,char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::binary_function_archetype<int,short,char>
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::input_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::input_iterator_archetype_no_proxy<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::output_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::input_output_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::forward_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::mutable_forward_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::bidirectional_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::mutable_bidirectional_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::concept::indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::concept::mutable_indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::random_access_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::mutable_random_access_iterator_archetype<char>
        >
    ));
    //->
}
//]

#include <functional>

//[test__is_adaptable_unary_function__std_adaptors
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            std::plus<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            std::minus<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            std::multiplies<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            std::divides<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            std::modulus<int>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_unary_function<
            std::negate<int>
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            std::equal_to<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            std::not_equal_to<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            std::less<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            std::greater<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            std::less_equal<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            std::greater_equal<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            std::logical_and<bool>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            std::logical_or<bool>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_unary_function<
            std::logical_not<bool>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            std::bit_and<unsigned>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            std::bit_or<unsigned>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            std::bit_xor<unsigned>
        >
    ));
    //->
}
//]

#include <boost/function.hpp>
#include <boost/functional/hash.hpp>
#include <boost/config.hpp>

//[test__is_adaptable_unary_function__boost_adaptors
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::hash<char const*>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::function1<float&,int>
        >
    ));
//<-
#if !defined BOOST_NO_CXX11_RVALUE_REFERENCES
//->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::function1<bool&&,char>
        >
    ));
//<-
#endif
//->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::function1<void,void*>
        >
    ));
//<-
#if !defined BOOST_NO_CXX11_RVALUE_REFERENCES
//->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::function2<bool&&,char,char>
        >
    ));
//<-
#endif
//->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::function2<double&,short,long>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            boost::function2<void,float,char>
        >
    ));
}
//]

#if !defined BOOST_NO_CXX11_HDR_FUNCTIONAL
#include <functional>

//[test__is_adaptable_unary_function__std_functional
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_unary_function<
            std::hash<char const*>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_unary_function<
            std::function<float&(int)>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_unary_function<
            std::function<bool(char)>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_unary_function<
            std::function<void(void*)>
        >
    ));
//<-
#if !defined BOOST_NO_CXX11_RVALUE_REFERENCES
//->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            std::function<bool&&(char,char)>
        >
    ));
//<-
#endif
//->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            std::function<double&(short,long)>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_unary_function<
            std::function<void(float,char)>
        >
    ));
}
//]
#endif  // BOOST_NO_CXX11_HDR_FUNCTIONAL

