// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/traits/query/is_adaptable_binary_func.hpp>
#include <boost/concept/traits/query/is_boolean_expression.hpp>
#include <boost/mpl/placeholders.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

#include <boost/concept_archetype.hpp>
#include <boost/concept/archetype/indexable_iterator.hpp>
#include <boost/concept/archetype/mutable_indexable_iterator.hpp>

//[test__is_adaptable_binary_predicate__archetypes
MPL_TEST_CASE()
{
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::boolean_archetype
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::equality_comparable_archetype<>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::less_than_comparable_archetype<>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::comparable_archetype<>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::addable_archetype<>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::subtractable_archetype<>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::multipliable_archetype<>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::dividable_archetype<>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::modable_archetype<>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    //->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::void_generator_archetype
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::generator_archetype<char>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::unary_function_archetype<short,char>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::binary_function_archetype<int,short,char>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    //...
    //<-
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::input_iterator_archetype<char>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::input_iterator_archetype_no_proxy<char>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::output_iterator_archetype<char>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::input_output_iterator_archetype<char>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::forward_iterator_archetype<char>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::mutable_forward_iterator_archetype<char>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::bidirectional_iterator_archetype<char>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::mutable_bidirectional_iterator_archetype<char>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::concept::indexable_iterator_archetype<char>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::concept::mutable_indexable_iterator_archetype<char>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::random_access_iterator_archetype<char>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::mutable_random_access_iterator_archetype<char>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    //->
}
//]

#include <functional>

//[test__is_adaptable_binary_predicate__std_adaptors
MPL_TEST_CASE()
{
    //<-
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_binary_function<
            std::plus<int>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_binary_function<
            std::minus<int>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_binary_function<
            std::multiplies<int>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_binary_function<
            std::divides<int>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_binary_function<
            std::modulus<int>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            std::negate<int>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_binary_function<
            std::equal_to<int>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_binary_function<
            std::not_equal_to<int>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_binary_function<
            std::less<int>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_binary_function<
            std::greater<int>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_binary_function<
            std::less_equal<int>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_binary_function<
            std::greater_equal<int>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    //->
    //...
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_binary_function<
            std::logical_and<bool>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_binary_function<
            std::logical_or<bool>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            std::logical_not<bool>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_binary_function<
            std::bit_and<unsigned>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_binary_function<
            std::bit_or<unsigned>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_binary_function<
            std::bit_xor<unsigned>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
}
//]

#include <boost/function.hpp>
#include <boost/functional/hash.hpp>

//[test__is_adaptable_binary_predicate__boost_adaptors
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::hash<char const*>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::function1<float&,int>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
//<-
#if !defined BOOST_NO_CXX11_RVALUE_REFERENCES
//->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::function1<bool&&,char>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
//<-
#endif
//->
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::function1<void,void*>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
//<-
#if !defined BOOST_NO_CXX11_RVALUE_REFERENCES
//->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::function2<bool&&,char,char>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
//<-
#endif
//->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::function2<double&,short,long>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            boost::function2<void,float,char>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
}
//]

#include <boost/config.hpp>

#if !defined BOOST_NO_CXX11_HDR_FUNCTIONAL
#include <functional>

//[test__is_adaptable_binary_predicate__std_functional
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            std::hash<char const*>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            std::function<float&(int)>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            std::function<bool(char)>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            std::function<void(void*)>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
//<-
#if !defined BOOST_NO_CXX11_RVALUE_REFERENCES
//->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_binary_function<
            std::function<bool&&(char,char)>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
//<-
#endif
//->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_adaptable_binary_function<
            std::function<double&(short,long)>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_adaptable_binary_function<
            std::function<void(float,char)>
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
}
//]
#endif  // BOOST_NO_CXX11_HDR_FUNCTIONAL

