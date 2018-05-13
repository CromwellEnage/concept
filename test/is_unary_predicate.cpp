// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/traits/query/is_unary_function.hpp>
#include <boost/concept/traits/query/is_boolean_expression.hpp>
#include <boost/mpl/placeholders.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

#include <boost/concept_archetype.hpp>
#include <boost/concept/archetype/indexable_iterator.hpp>
#include <boost/concept/archetype/mutable_indexable_iterator.hpp>

//[test__is_unary_predicate__archetypes
MPL_TEST_CASE()
{
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::boolean_archetype
          , int
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::equality_comparable_archetype<>
          , int
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::less_than_comparable_archetype<>
          , int
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::comparable_archetype<>
          , int
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::addable_archetype<>
          , int
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::subtractable_archetype<>
          , int
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::multipliable_archetype<>
          , int
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::dividable_archetype<>
          , int
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::modable_archetype<>
          , int
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::void_generator_archetype
          , int
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::generator_archetype<char>
          , char
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_unary_function<
            boost::unary_function_archetype<short,char>
          , char
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::binary_function_archetype<int,short,char>
          , short
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::input_iterator_archetype<char>
          , char
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::input_iterator_archetype_no_proxy<char>
          , char
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::output_iterator_archetype<char>
          , char
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::input_output_iterator_archetype<char>
          , char
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::forward_iterator_archetype<char>
          , char
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::mutable_forward_iterator_archetype<char>
          , char
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::bidirectional_iterator_archetype<char>
          , char
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::mutable_bidirectional_iterator_archetype<char>
          , char
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::concept::indexable_iterator_archetype<char>
          , char
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::concept::mutable_indexable_iterator_archetype<char>
          , char
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::random_access_iterator_archetype<char>
          , char
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::mutable_random_access_iterator_archetype<char>
          , char
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    //->
}
//]

#include <functional>

//[test__is_unary_predicate__std_adaptors
MPL_TEST_CASE()
{
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            std::plus<int>
          , int
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            std::minus<int>
          , int
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            std::multiplies<int>
          , int
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            std::divides<int>
          , int
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            std::modulus<int>
          , int
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_unary_function<
            std::negate<int>
          , int
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            std::equal_to<int>
          , int
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            std::not_equal_to<int>
          , int
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            std::less<int>
          , int
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            std::greater<int>
          , int
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            std::less_equal<int>
          , int
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            std::greater_equal<int>
          , int
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    //->
    //...
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            std::logical_and<bool>
          , bool
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            std::logical_or<bool>
          , bool
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_unary_function<
            std::logical_not<bool>
          , bool
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            std::bit_and<unsigned>
          , unsigned
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            std::bit_or<unsigned>
          , unsigned
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            std::bit_xor<unsigned>
          , unsigned
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
}
//]

#include <boost/function.hpp>
#include <boost/functional/hash.hpp>
#include <boost/config.hpp>

//[test__is_unary_predicate__boost_adaptors
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_unary_function<
            boost::hash<char const*>
          , char const*
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_unary_function<
            boost::function1<float&,int>
          , int
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
//<-
#if !defined BOOST_NO_CXX11_RVALUE_REFERENCES
//->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_unary_function<
            boost::function1<bool&&,char>
          , char
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
//<-
#endif
//->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::function1<void,void*>
          , void*
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
//<-
#if !defined BOOST_NO_CXX11_RVALUE_REFERENCES
//->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::function2<bool&&,char,char>
          , char
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
//<-
#endif
//->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::function2<double&,short,long>
          , short
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            boost::function2<void,float,char>
          , float
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
}
//]

#if !defined BOOST_NO_CXX11_HDR_FUNCTIONAL
#include <functional>

//[test__is_unary_predicate__std_functional
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_unary_function<
            std::hash<char const*>
          , char const*
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_unary_function<
            std::function<float&(int)>
          , int
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_unary_function<
            std::function<bool(char)>
          , char
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            std::function<void(void*)>
          , void*
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
//<-
#if !defined BOOST_NO_CXX11_RVALUE_REFERENCES
//->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            std::function<bool&&(char,char)>
          , char
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
//<-
#endif
//->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            std::function<double&(short,long)>
          , short
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_unary_function<
            std::function<void(float,char)>
          , float
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
}
//]
#endif  // BOOST_NO_CXX11_HDR_FUNCTIONAL

