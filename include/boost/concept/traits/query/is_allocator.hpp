// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_ALLOCATOR_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_ALLOCATOR_HPP

#include <boost/concept/traits/query/is_equality_comparable.hpp>
#include <boost/concept/traits/introspection/member_function/has_allocate.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_deallocate.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_allocator
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_equality_comparable<T>
          , ::boost::mpl::if_<
                ::boost::concept::traits::has_allocate<T>
              , ::boost::concept::traits::has_deallocate<T>
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/trivial_access/other_of.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename Rebind>
    struct has_allocator_rebind_other
      : ::boost::concept::traits::_detail::metafunction::is_allocator<
            typename ::boost::concept::traits::other_of<Rebind>::type
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type/has_other.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <
        typename T
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      , typename _VoidPtrRebind = typename ::boost::remove_const<
            typename ::boost::remove_reference<T>::type
#else
      , typename _VoidPtrRebind = typename ::std::remove_const<
            typename ::std::remove_reference<T>::type
#endif
        >::type::BOOST_NESTED_TEMPLATE rebind<void*>
    >
    struct has_allocator_rebind
      : ::boost::mpl::if_<
            ::boost::concept::traits::has_other<_VoidPtrRebind>
          , ::boost::concept::traits::_detail::metafunction
            ::has_allocator_rebind_other<_VoidPtrRebind>
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/introspection/nested_template/has_rebind.hpp>

//[reference__is_allocator
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_allocator
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
          _bct_is_equality_comparable_<T>
        , _mpl_eval_if_<
            _bct_has_allocate_<T>
          , _mpl_eval_if_<
              _bct_has_deallocate_<T>
            , _mpl_eval_if_<
                _bct_has_rebind_<T>
              , _mpl_eval_if_<
                  _bct_has_other_<
                    typename _std_remove_const_<
                      typename _std_remove_reference_<T>::type
                    >::type::template rebind<void*>
                  >
                , _mpl_eval_if_<
                    _bct_is_equality_comparable_<
                      typename _bct_other_of_<
                        typename _std_remove_const_<
                          typename _std_remove_reference_<T>::type
                        >::type::template rebind<void*>
                      >::type
                    >
                  , _mpl_if_<
                      _bct_has_allocate_<
                        typename _bct_other_of_<
                          typename _std_remove_const_<
                            typename _std_remove_reference_<T>::type
                          >::type::template rebind<void*>
                        >::type
                      >
                    , _bct_has_deallocate_<
                        typename _bct_other_of_<
                          typename _std_remove_const_<
                            typename _std_remove_reference_<T>::type
                          >::type::template rebind<void*>
                        >::type
                      >
                    , _mpl_false_
                    >
                  , _mpl_false_
                  >
                , _mpl_false_
                >
              , _mpl_false_
              >
            , _mpl_false_
            >
          , _mpl_false_
          >
        , _mpl_false_
        >::type
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::_detail::metafunction
            ::is_allocator_impl<T>
          , ::boost::mpl::if_<
                ::boost::concept::traits::has_rebind<T>
              , ::boost::concept::traits::_detail::metafunction
                ::has_allocator_rebind<T>
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

