// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_REVERSIBLE_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_REVERSIBLE_HPP

#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename PlaceholderExpr>
    struct is_reversible_impl
      : ::boost::mpl::eval_if<
            typename ::boost::mpl::apply1<
                PlaceholderExpr
              , typename T::const_reverse_iterator
            >::type
          , ::boost::mpl::apply1<
                PlaceholderExpr
              , typename T::reverse_iterator
            >
          , ::boost::mpl::false_
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/member_function/has_rbegin.hpp>
#include <boost/concept/traits/introspection/member_function/has_rend.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename PlaceholderExpr>
    class is_reversible
    {
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
        typedef typename ::boost::add_const<T>::type _const_T;
        typedef typename ::boost::remove_const<T>::type _mutable_T;
#else
        typedef typename ::std::add_const<T>::type _const_T;
        typedef typename ::std::remove_const<T>::type _mutable_T;
#endif

     public:
        typedef typename ::boost::mpl::eval_if<
                  ::boost::concept::traits::has_rbegin<_mutable_T>
                , ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_rend<_mutable_T>
                  , ::boost::mpl::eval_if<
                      ::boost::concept::traits::has_rbegin<_const_T>
                    , ::boost::mpl::eval_if<
                        ::boost::concept::traits::has_rend<_const_T>
                      , ::boost::concept::traits::_detail::metafunction
                        ::is_reversible_impl<_mutable_T,PlaceholderExpr>
                      , ::boost::mpl::false_
                      >
                    , ::boost::mpl::false_
                    >
                  , ::boost::mpl::false_
                  >
                , ::boost::mpl::false_
                >::type
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_bidirectional_iterator.hpp>

//[reference__is_reversible
namespace boost { namespace concept { namespace traits {

    template <typename T, typename PlaceholderExpr>
    struct is_reversible
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_has_rbegin_<typename _std_remove_const_<T>::type>
          , _mpl_eval_if_<
                _bct_has_rend_<typename _std_remove_const_<T>::type>
              , _mpl_eval_if_<
                    _bct_has_rbegin_<typename _std_add_const_<T>::type>
                  , _mpl_eval_if_<
                        _bct_has_rend_<typename _std_add_const_<T>::type>
                      , _mpl_eval_if_<
                            typename _mpl_apply1_<
                                PlaceholderExpr
                              , typename _std_remove_const_<T>::type
                                ::const_reverse_iterator
                            >::type
                          , _mpl_apply1_<
                                PlaceholderExpr
                              , typename _std_remove_const_<T>::type
                                ::const_reverse_iterator
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
#else
      : ::boost::concept::traits::_detail::metafunction
        ::is_reversible<T,PlaceholderExpr>::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

