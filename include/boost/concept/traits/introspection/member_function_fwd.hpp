// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_FWD_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_FWD_HPP

//[reference__has_base__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr
      , typename ResultIfNoBase
    >
    struct has_base;
}}}  // namespace boost::concept::traits
//]

//[reference__has_clear__fwd
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct has_clear;
}}}  // namespace boost::concept::traits
//]

//[reference__has_pop__fwd
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct has_pop;
}}}  // namespace boost::concept::traits
//]

//[reference__has_pop_back__fwd
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct has_pop_back;
}}}  // namespace boost::concept::traits
//]

//[reference__has_pop_front__fwd
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct has_pop_front;
}}}  // namespace boost::concept::traits
//]

//[reference__has_swap__fwd
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct has_swap;
}}}  // namespace boost::concept::traits
//]

//[reference__has_merge__fwd
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct has_merge;
}}}  // namespace boost::concept::traits
//]

//[reference__has_push__fwd
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct has_push;
}}}  // namespace boost::concept::traits
//]

//[reference__has_push_back__fwd
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct has_push_back;
}}}  // namespace boost::concept::traits
//]

//[reference__has_push_front__fwd
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct has_push_front;
}}}  // namespace boost::concept::traits
//]

//[reference__has_deallocate__fwd
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct has_deallocate;
}}}  // namespace boost::concept::traits
//]

//[reference__has_deallocate_clone__fwd
namespace boost { namespace concept { namespace traits {

    template <typename T, typename U>
    struct has_deallocate_clone;
}}}  // namespace boost::concept::traits
//]

//[reference__has_rehash__fwd
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct has_rehash;
}}}  // namespace boost::concept::traits
//]

#include <boost/concept/policy/use_default.hpp>

//[reference__has_compressed_pair_first__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr = ::boost::concept::policy::use_default
    >
    struct has_compressed_pair_first;
}}}  // namespace boost::concept::traits
//]

//[reference__has_compressed_pair_second__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr = ::boost::concept::policy::use_default
    >
    struct has_compressed_pair_second;
}}}  // namespace boost::concept::traits
//]

//[reference__has_get_allocator__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr = ::boost::concept::policy::use_default
    >
    struct has_get_allocator;
}}}  // namespace boost::concept::traits
//]

//[reference__has_value__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr = ::boost::concept::policy::use_default
    >
    struct has_value;
}}}  // namespace boost::concept::traits
//]

//[reference__has_key__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr = ::boost::concept::policy::use_default
    >
    struct has_key;
}}}  // namespace boost::concept::traits
//]

//[reference__has_mapped__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr = ::boost::concept::policy::use_default
    >
    struct has_mapped;
}}}  // namespace boost::concept::traits
//]

//[reference__has_hash_function__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr = ::boost::concept::policy::use_default
    >
    struct has_hash_function;
}}}  // namespace boost::concept::traits
//]

//[reference__has_key_eq__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr = ::boost::concept::policy::use_default
    >
    struct has_key_eq;
}}}  // namespace boost::concept::traits
//]

//[reference__has_key_comp__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr = ::boost::concept::policy::use_default
    >
    struct has_key_comp;
}}}  // namespace boost::concept::traits
//]

//[reference__has_value_comp__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr = ::boost::concept::policy::use_default
    >
    struct has_value_comp;
}}}  // namespace boost::concept::traits
//]

//[reference__has_origin__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr = ::boost::concept::policy::use_default
    >
    struct has_origin;
}}}  // namespace boost::concept::traits
//]

//[reference__has_shape__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr = ::boost::concept::policy::use_default
    >
    struct has_shape;
}}}  // namespace boost::concept::traits
//]

//[reference__has_strides__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr = ::boost::concept::policy::use_default
    >
    struct has_strides;
}}}  // namespace boost::concept::traits
//]

//[reference__has_index_bases__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr = ::boost::concept::policy::use_default
    >
    struct has_index_bases;
}}}  // namespace boost::concept::traits
//]

//[reference__has_start__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename Param = ::boost::concept::policy::use_default
      , typename ResultPlaceholderExpr = ::boost::concept::policy::use_default
    >
    struct has_start;
}}}  // namespace boost::concept::traits
//]

//[reference__has_finish__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename Param = ::boost::concept::policy::use_default
      , typename ResultPlaceholderExpr = ::boost::concept::policy::use_default
    >
    struct has_finish;
}}}  // namespace boost::concept::traits
//]

//[reference__has_stride__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename Param = ::boost::concept::policy::use_default
      , typename ResultPlaceholderExpr = ::boost::concept::policy::use_default
    >
    struct has_stride;
}}}  // namespace boost::concept::traits
//]

//[reference__has_equal_range__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename Param = ::boost::concept::policy::use_default
      , typename ResultPlaceholderExpr = ::boost::concept::policy::use_default
    >
    struct has_equal_range;
}}}  // namespace boost::concept::traits
//]

//[reference__has_real__fwd
namespace boost { namespace concept { namespace traits {

    template <typename T, typename U = ::boost::concept::policy::use_default>
    struct has_real;
}}}  // namespace boost::concept::traits
//]

//[reference__has_imag__fwd
namespace boost { namespace concept { namespace traits {

    template <typename T, typename U = ::boost::concept::policy::use_default>
    struct has_imag;
}}}  // namespace boost::concept::traits
//]

//[reference__has_reserve__fwd
namespace boost { namespace concept { namespace traits {

    template <typename T, typename U = ::boost::concept::policy::use_default>
    struct has_reserve;
}}}  // namespace boost::concept::traits
//]

//[reference__has_update__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename Param1
      , typename Param2 = ::boost::concept::policy::use_default
    >
    struct has_update;
}}}  // namespace boost::concept::traits
//]

//[reference__has_increase__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename Param1
      , typename Param2 = ::boost::concept::policy::use_default
    >
    struct has_increase;
}}}  // namespace boost::concept::traits
//]

//[reference__has_decrease__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename Param1
      , typename Param2 = ::boost::concept::policy::use_default
    >
    struct has_decrease;
}}}  // namespace boost::concept::traits
//]

//[reference__has_null_vertex__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr = ::boost::concept::policy::use_default
    >
    struct has_null_vertex;
}}}  // namespace boost::concept::traits
//]

#include <boost/mpl/integral_c.hpp>

//[reference__has_insert_element__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename Element = ::boost::concept::policy::use_default
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      , typename SizeArity = _mpl_integral_c_<unsigned char,1>
//<-
#else
      , typename SizeArity = ::boost::mpl::integral_c<unsigned char,1>
#endif
//->
    >
    struct has_insert_element;
}}}  // namespace boost::concept::traits
//]

//[reference__has_erase_element__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      , typename SizeArity = _mpl_integral_c_<unsigned char,1>
//<-
#else
      , typename SizeArity = ::boost::mpl::integral_c<unsigned char,1>
#endif
//->
    >
    struct has_erase_element;
}}}  // namespace boost::concept::traits
//]

//[reference__has_resize__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename U = ::boost::concept::policy::use_default
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      , typename SizeArity = _mpl_integral_c_<unsigned char,1>
//<-
#else
      , typename SizeArity = ::boost::mpl::integral_c<unsigned char,1>
#endif
//->
    >
    struct has_resize;
}}}  // namespace boost::concept::traits
//]

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/mpl/placeholders.hpp>

//[reference__has_empty__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_boolean_expression_<_mpl_placeholder_>
//<-
#else
        ::boost::concept::traits::is_boolean_expression< ::boost::mpl::_>
#endif
//->
    >
    struct has_empty;
}}}  // namespace boost::concept::traits
//]

//[reference__has_full__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_boolean_expression_<_mpl_placeholder_>
//<-
#else
        ::boost::concept::traits::is_boolean_expression< ::boost::mpl::_>
#endif
//->
    >
    struct has_full;
}}}  // namespace boost::concept::traits
//]

#include <boost/concept/traits/introspection/nested_type_fwd.hpp>

//[reference__has_data__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_pointer_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_pointer_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_data;
}}}  // namespace boost::concept::traits
//]

//[reference__has_allocate__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename U = ::boost::concept::policy::use_default
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_allocator_pointer_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_allocator_pointer_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_allocate;
}}}  // namespace boost::concept::traits
//]

//[reference__has_min__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_result_type_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_result_type_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_min;
}}}  // namespace boost::concept::traits
//]

//[reference__has_max__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_result_type_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_result_type_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_max;
}}}  // namespace boost::concept::traits
//]

//[reference__has_numerator__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_int_type_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_int_type_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_numerator;
}}}  // namespace boost::concept::traits
//]

//[reference__has_denominator__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_int_type_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_int_type_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_denominator;
}}}  // namespace boost::concept::traits
//]

//[reference__has_param__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_param_type_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_param_type_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_param;
}}}  // namespace boost::concept::traits
//]

//[reference__has_begin__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_iterator_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_iterator_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_begin;
}}}  // namespace boost::concept::traits
//]

//[reference__has_end__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_iterator_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_iterator_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_end;
}}}  // namespace boost::concept::traits
//]

//[reference__has_find__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename Param = ::boost::concept::policy::use_default
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_iterator_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_iterator_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_find;
}}}  // namespace boost::concept::traits
//]

//[reference__has_lower_bound__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename Param = ::boost::concept::policy::use_default
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_iterator_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_iterator_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_lower_bound;
}}}  // namespace boost::concept::traits
//]

//[reference__has_upper_bound__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename Param = ::boost::concept::policy::use_default
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_iterator_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_iterator_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_upper_bound;
}}}  // namespace boost::concept::traits
//]

//[reference__has_insert__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename Param1
      , typename Param2 = ::boost::concept::policy::use_default
      , typename Param3 = ::boost::concept::policy::use_default
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_iterator_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_iterator_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_insert;
}}}  // namespace boost::concept::traits
//]

//[reference__has_insert_after__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename Param1
      , typename Param2 = ::boost::concept::policy::use_default
      , typename Param3 = ::boost::concept::policy::use_default
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_iterator_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_iterator_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_insert_after;
}}}  // namespace boost::concept::traits
//]

//[reference__has_erase__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename Param1
      , typename Param2 = ::boost::concept::policy::use_default
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_iterator_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_iterator_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_erase;
}}}  // namespace boost::concept::traits
//]

//[reference__has_erase_after__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename Param1
      , typename Param2 = ::boost::concept::policy::use_default
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_iterator_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_iterator_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_erase_after;
}}}  // namespace boost::concept::traits
//]

//[reference__has_begin1__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_iterator1_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_iterator1_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_begin1;
}}}  // namespace boost::concept::traits
//]

//[reference__has_end1__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_iterator1_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_iterator1_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_end1;
}}}  // namespace boost::concept::traits
//]

//[reference__has_begin2__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_iterator2_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_iterator2_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_begin2;
}}}  // namespace boost::concept::traits
//]

//[reference__has_end2__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_iterator2_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_iterator2_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_end2;
}}}  // namespace boost::concept::traits
//]

//[reference__has_rbegin__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_reverse_iterator_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_reverse_iterator_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_rbegin;
}}}  // namespace boost::concept::traits
//]

//[reference__has_rend__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_reverse_iterator_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_reverse_iterator_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_rend;
}}}  // namespace boost::concept::traits
//]

//[reference__has_rbegin1__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_reverse_iterator1_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_reverse_iterator1_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_rbegin1;
}}}  // namespace boost::concept::traits
//]

//[reference__has_rend1__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_reverse_iterator1_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_reverse_iterator1_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_rend1;
}}}  // namespace boost::concept::traits
//]

//[reference__has_rbegin2__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_reverse_iterator2_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_reverse_iterator2_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_rbegin2;
}}}  // namespace boost::concept::traits
//]

//[reference__has_rend2__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_reverse_iterator2_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_reverse_iterator2_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_rend2;
}}}  // namespace boost::concept::traits
//]

//[reference__has_begin_bucket__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_local_iterator_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_local_iterator_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_begin_bucket;
}}}  // namespace boost::concept::traits
//]

//[reference__has_end_bucket__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_local_iterator_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_local_iterator_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_end_bucket;
}}}  // namespace boost::concept::traits
//]

//[reference__has_ordered_begin__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_ordered_iterator_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_ordered_iterator_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_ordered_begin;
}}}  // namespace boost::concept::traits
//]

//[reference__has_ordered_end__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_ordered_iterator_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_ordered_iterator_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_ordered_end;
}}}  // namespace boost::concept::traits
//]

//[reference__has_front__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_value_type_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_value_type_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_front;
}}}  // namespace boost::concept::traits
//]

//[reference__has_back__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_value_type_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_value_type_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_back;
}}}  // namespace boost::concept::traits
//]

//[reference__has_top__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_value_type_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_value_type_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_top;
}}}  // namespace boost::concept::traits
//]

//[reference__has_capacity__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_capacity_type_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_capacity_type_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_capacity;
}}}  // namespace boost::concept::traits
//]

//[reference__has_max_size__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_size_type_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_size_type_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_max_size;
}}}  // namespace boost::concept::traits
//]

//[reference__has_size1__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_size_type_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_size_type_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_size1;
}}}  // namespace boost::concept::traits
//]

//[reference__has_size2__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_size_type_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_size_type_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_size2;
}}}  // namespace boost::concept::traits
//]

//[reference__has_num_dimensions__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_size_type_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_size_type_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_num_dimensions;
}}}  // namespace boost::concept::traits
//]

//[reference__has_num_elements__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_size_type_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_size_type_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_num_elements;
}}}  // namespace boost::concept::traits
//]

//[reference__has_max_bucket_count__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_size_type_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_size_type_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_max_bucket_count;
}}}  // namespace boost::concept::traits
//]

//[reference__has_bucket_count__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_size_type_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_size_type_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_bucket_count;
}}}  // namespace boost::concept::traits
//]

//[reference__has_size__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename Param = ::boost::concept::policy::use_default
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_size_type_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_size_type_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_size;
}}}  // namespace boost::concept::traits
//]

//[reference__has_count__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename Param = ::boost::concept::policy::use_default
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_size_type_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_size_type_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_count;
}}}  // namespace boost::concept::traits
//]

//[reference__has_extract__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename Param = ::boost::concept::policy::use_default
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_node_type_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_node_type_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_extract;
}}}  // namespace boost::concept::traits
//]

//[reference__has_get_start__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename Param = ::boost::concept::policy::use_default
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_index_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_index_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_get_start;
}}}  // namespace boost::concept::traits
//]

//[reference__has_get_finish__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename Param = ::boost::concept::policy::use_default
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_index_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_index_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_get_finish;
}}}  // namespace boost::concept::traits
//]

#include <boost/concept/traits/introspection_fwd.hpp>

//[reference__has_assign__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename Value = ::boost::concept::policy::use_default
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_convertible_to_cref_of_<
            _mpl_placeholder_
//<-
#else
        ::boost::concept::traits::is_convertible_to_cref_of<
            ::boost::mpl::_
#endif
//->
          , T
        >
    >
    struct has_assign;
}}}  // namespace boost::concept::traits
//]

//[reference__has_allocate_clone__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename U
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_raw_pointer_of_<_mpl_placeholder_,U>
//<-
#else
        ::boost::concept::traits::is_raw_pointer_of< ::boost::mpl::_,U>
#endif
//->
    >
    struct has_allocate_clone;
}}}  // namespace boost::concept::traits
//]

#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/add_const.hpp>
#else
#include <type_traits>
#endif

//[reference__has_cbegin__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_iterator_of_<
            _mpl_placeholder_
          , typename _std_add_const_<T>::type
        >
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
        ::boost::concept::traits::is_iterator_of<
            ::boost::mpl::_
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
          , typename ::boost::add_const<T>::type
#else
          , typename ::std::add_const<T>::type
#endif
        >
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    >
    struct has_cbegin;
}}}  // namespace boost::concept::traits
//]

//[reference__has_cend__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_iterator_of_<
            _mpl_placeholder_
          , typename _std_add_const_<T>::type
        >
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
        ::boost::concept::traits::is_iterator_of<
            ::boost::mpl::_
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
          , typename ::boost::add_const<T>::type
#else
          , typename ::std::add_const<T>::type
#endif
        >
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    >
    struct has_cend;
}}}  // namespace boost::concept::traits
//]

//[reference__has_crbegin__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_reverse_iterator_of_<
            _mpl_placeholder_
          , typename _std_add_const_<T>::type
        >
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
        ::boost::concept::traits::is_reverse_iterator_of<
            ::boost::mpl::_
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
          , typename ::boost::add_const<T>::type
#else
          , typename ::std::add_const<T>::type
#endif
        >
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    >
    struct has_crbegin;
}}}  // namespace boost::concept::traits
//]

//[reference__has_crend__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_reverse_iterator_of_<
            _mpl_placeholder_
          , typename _std_add_const_<T>::type
        >
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
        ::boost::concept::traits::is_reverse_iterator_of<
            ::boost::mpl::_
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
          , typename ::boost::add_const<T>::type
#else
          , typename ::std::add_const<T>::type
#endif
        >
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    >
    struct has_crend;
}}}  // namespace boost::concept::traits
//]

//[reference__has_cbegin_bucket__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_local_iterator_of_<
            _mpl_placeholder_
          , typename _std_add_const_<T>::type
        >
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
        ::boost::concept::traits::is_local_iterator_of<
            ::boost::mpl::_
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
          , typename ::boost::add_const<T>::type
#else
          , typename ::std::add_const<T>::type
#endif
        >
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    >
    struct has_cbegin_bucket;
}}}  // namespace boost::concept::traits
//]

//[reference__has_cend_bucket__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_local_iterator_of_<
            _mpl_placeholder_
          , typename _std_add_const_<T>::type
        >
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
        ::boost::concept::traits::is_local_iterator_of<
            ::boost::mpl::_
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
          , typename ::boost::add_const<T>::type
#else
          , typename ::std::add_const<T>::type
#endif
        >
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    >
    struct has_cend_bucket;
}}}  // namespace boost::concept::traits
//]

#include <boost/mpl/bool.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/is_same.hpp>
#else
#include <boost/mpl/if.hpp>
#endif

//[reference__has_plus_assign__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename Addend = ::boost::concept::policy::use_default
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_lvalue_reference_of_<_mpl_placeholder_,T>
//<-
#elif defined(BOOST_NO_CXX11_DECLTYPE)
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
        ::boost::is_same< ::boost::mpl::_,T>
#else
        ::boost::mpl::if_<
            ::std::is_same< ::boost::mpl::_,T>
          , ::boost::mpl::true_
          , ::boost::mpl::false_
        >
#endif  // BOOST_NO_CXX11_HDR_TYPE_TRAITS
#else   // !defined(BOOST_NO_CXX11_DECLTYPE)
        ::boost::concept::traits::is_lvalue_reference_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_plus_assign;
}}}  // namespace boost::concept::traits
//]

//[reference__has_minus_assign__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename Difference = ::boost::concept::policy::use_default
      , typename ResultPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_lvalue_reference_of_<_mpl_placeholder_,T>
//<-
#elif defined(BOOST_NO_CXX11_DECLTYPE)
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
        ::boost::is_same< ::boost::mpl::_,T>
#else
        ::boost::mpl::if_<
            ::std::is_same< ::boost::mpl::_,T>
          , ::boost::mpl::true_
          , ::boost::mpl::false_
        >
#endif  // BOOST_NO_CXX11_HDR_TYPE_TRAITS
#else   // !defined(BOOST_NO_CXX11_DECLTYPE)
        ::boost::concept::traits::is_lvalue_reference_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_minus_assign;
}}}  // namespace boost::concept::traits
//]

#if defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
#include <boost/concept/traits/_detail/preprocessor/config.hpp>
#include <boost/preprocessor/repetition/enum_trailing_binary_params.hpp>
#include <boost/preprocessor/facilities/intercept.hpp>
#endif

//[reference__has_reset__fwd
namespace boost { namespace concept { namespace traits {

//<-
#if defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
    template <
        typename T
        BOOST_PP_ENUM_TRAILING_BINARY_PARAMS(
            BOOST_CONCEPT_TRAITS_VARIADIC_ARG_COUNT
          , typename P
          , = ::boost::concept::policy::use_default BOOST_PP_INTERCEPT
        )
    >
#else
//->
    template <typename T, typename... Args>
//<-
#endif
//->
    struct has_reset;
}}}  // namespace boost::concept::traits
//]

//[reference__has_emplace__fwd
namespace boost { namespace concept { namespace traits {

//<-
#if defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
    template <
        typename T
        BOOST_PP_ENUM_TRAILING_BINARY_PARAMS(
            BOOST_CONCEPT_TRAITS_VARIADIC_ARG_COUNT
          , typename P
          , = ::boost::concept::policy::use_default BOOST_PP_INTERCEPT
        )
    >
#else
//->
    template <typename T, typename... Args>
//<-
#endif
//->
    struct has_emplace;
}}}  // namespace boost::concept::traits
//]

//[reference__has_emplace_back__fwd
namespace boost { namespace concept { namespace traits {

//<-
#if defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
    template <
        typename T
        BOOST_PP_ENUM_TRAILING_BINARY_PARAMS(
            BOOST_CONCEPT_TRAITS_VARIADIC_ARG_COUNT
          , typename P
          , = ::boost::concept::policy::use_default BOOST_PP_INTERCEPT
        )
    >
#else
//->
    template <typename T, typename... Args>
//<-
#endif
//->
    struct has_emplace_back;
}}}  // namespace boost::concept::traits
//]

//[reference__has_emplace_front__fwd
namespace boost { namespace concept { namespace traits {

//<-
#if defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
    template <
        typename T
        BOOST_PP_ENUM_TRAILING_BINARY_PARAMS(
            BOOST_CONCEPT_TRAITS_VARIADIC_ARG_COUNT
          , typename P
          , = ::boost::concept::policy::use_default BOOST_PP_INTERCEPT
        )
    >
#else
//->
    template <typename T, typename... Args>
//<-
#endif
//->
    struct has_emplace_front;
}}}  // namespace boost::concept::traits
//]

//[reference__has_emplace_after__fwd
namespace boost { namespace concept { namespace traits {

//<-
#if defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
    template <
        typename T
        BOOST_PP_ENUM_TRAILING_BINARY_PARAMS(
            BOOST_CONCEPT_TRAITS_VARIADIC_ARG_COUNT
          , typename P
          , = ::boost::concept::policy::use_default BOOST_PP_INTERCEPT
        )
    >
#else
//->
    template <typename T, typename... Args>
//<-
#endif
//->
    struct has_emplace_after;
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

