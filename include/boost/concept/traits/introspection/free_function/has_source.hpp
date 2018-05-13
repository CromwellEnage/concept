// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_FREE_FUNCTION_HAS_SOURCE_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_FREE_FUNCTION_HAS_SOURCE_HPP

#include <boost/utility/declval.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_source_impl
      : ::boost::mpl::apply1<
            ResultPlaceholderExpr
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF_KEYWORD
#else
          , decltype
#endif
            ((source(::boost::declval<Param>(), ::boost::declval<T>())))
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/graph/graph_traits.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Param>
    struct has_source_impl_default
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
      : ::boost::is_same<
#else
      : ::boost::mpl::if_<
            ::std::is_same<
#endif
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF_KEYWORD
#else
                decltype
#endif
                ((source(::boost::declval<Param>(), ::boost::declval<T>())))
              , typename ::boost::graph_traits<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                    typename ::boost::remove_const<T>::type
#else
                    typename ::std::remove_const<T>::type
#endif
                >::vertex_descriptor
            >
#if !defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
          , ::boost::mpl::true_
          , ::boost::mpl::false_
        >::type
#endif
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include \
<boost/concept/traits/introspection/nested_type/has_vertex_descriptor.hpp>
#include <boost/concept/policy/use_default.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Param>
    struct has_source_impl<T,Param,::boost::concept::policy::use_default>
      : ::boost::mpl::if_<
            ::boost::concept::traits::has_vertex_descriptor<
                ::boost::graph_traits<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                    typename ::boost::remove_const<T>::type
#else
                    typename ::std::remove_const<T>::type
#endif
                >
            >
          , ::boost::concept::traits::_detail::metafunction
            ::has_source_impl_default<T,Param>
          , ::boost::mpl::false_
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/tti/detail/dnullptr.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_pointer.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    class has_source
    {
        template <typename B, typename P>
        static ::boost::type_traits::yes_type
            _check(
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::add_pointer<
#else
                typename ::std::add_pointer<
#endif
#if defined BOOST_NO_CXX11_DECLTYPE
                    BOOST_TYPEOF_KEYWORD
#else
                    decltype
#endif
                    ((source(::boost::declval<P>(), ::boost::declval<B>())))
                >::type
            );

        template <typename B, typename P>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef typename ::boost::mpl::if_c<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_source<T,Param,ResultPlaceholderExpr>
                        ::_check<T,Param>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                  , ::boost::concept::traits::_detail::metafunction
                    ::has_source_impl<T,Param,ResultPlaceholderExpr>
                  , ::boost::mpl::false_
                >::type
                type;
    };

    template <typename T, typename ResultPlaceholderExpr>
    struct has_source_default
      : ::boost::concept::traits::_detail::metafunction::has_source<
            T
          , typename ::boost::graph_traits<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::remove_const<T>::type
#else
                typename ::std::remove_const<T>::type
#endif
            >::edge_descriptor
          , ResultPlaceholderExpr
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include \
<boost/concept/traits/introspection/nested_type/has_edge_descriptor.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename ResultPlaceholderExpr>
    class has_source<
        T
      , ::boost::concept::policy::use_default
      , ResultPlaceholderExpr
    > : public ::boost::mpl::if_<
            ::boost::concept::traits::has_edge_descriptor<
                ::boost::graph_traits<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                    typename ::boost::remove_const<T>::type
#else
                    typename ::std::remove_const<T>::type
#endif
                >
            >
          , ::boost::concept::traits::_detail::metafunction
            ::has_source_default<T,ResultPlaceholderExpr>
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/free_function_fwd.hpp>

//[reference__has_source
namespace boost { namespace concept { namespace traits {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_source
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            typename _mpl_if_<
                _std_is_same_<Param,boost::concept::policy::use_default>
              , _bct_has_edge_descriptor_<
                    _graph_traits_<typename _std_remove_const_<T>::type>
                >
              , _mpl_true_
            >::type
          , _mpl_eval_if_<
                _is_valid_expression_(
                    source(
                        _declval_<
                            typename _mpl_if_<
                                _std_is_same_<
                                    Param
                                  , boost::concept::policy::use_default
                                >
                              , typename _graph_traits_<
                                    typename _std_remove_const_<T>::type
                                >::edge_descriptor
                              , Param
                            >::type
                        >()
                      , _declval_<T>()
                    )
                )
              , _mpl_eval_if_<
                    _std_is_same_<Param,boost::concept::policy::use_default>
                  , _mpl_apply1_<
                        ResultPlaceholderExpr
                      , _decltype_(
                            source(
                                _declval_<
                                    typename _graph_traits_<
                                        typename _std_remove_const_<T>::type
                                    >::edge_descriptor
                                >()
                              , _declval_<T>()
                            )
                        )
                    >
                  , _mpl_apply1_<
                        ResultPlaceholderExpr
                      , _decltype_(
                            source(
                                _declval_<Param>()
                              , _declval_<T>()
                            )
                        )
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
        ::has_source<T,Param,ResultPlaceholderExpr>::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

