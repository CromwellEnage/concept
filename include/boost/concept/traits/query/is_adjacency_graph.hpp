// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_ADJACENCY_GRAPH_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_ADJACENCY_GRAPH_HPP

#include <boost/utility/declval.hpp>
#include <boost/graph/detail/graph_traits.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <utility>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_same.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_adjacency_graph_ops
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
                ((
                    adjacent_vertices(
                        ::boost::declval<
                            typename ::boost::graph::graph_traits<T>
                            ::vertex_descriptor const
                        >()
                      , ::boost::declval<T const>()
                    )
                ))
              , ::std::pair<
                    typename ::boost::graph::graph_traits<T>
                    ::adjacency_iterator
                  , typename ::boost::graph::graph_traits<T>
                    ::adjacency_iterator
                >
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

#include <boost/tti/detail/dnullptr.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_pointer.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    class has_adjacency_graph_expr
    {
        template <typename B>
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
                    ((
                        adjacent_vertices(
                            ::boost::declval<
                                typename ::boost::graph::graph_traits<B>
                                ::vertex_descriptor const
                            >()
                          , ::boost::declval<B const>()
                        )
                    ))
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef ::boost::mpl::bool_<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_adjacency_graph_expr<T>
                        ::_check<T>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                >
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include \
<boost/concept/traits/introspection/nested_type/has_adjacency_iterator.hpp>
#include <boost/mpl/eval_if.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_convertible.hpp>
#include <boost/type_traits/remove_const.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    class is_adjacency_graph_impl
    {
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
        typedef typename ::boost::remove_const<T>::type _mutable_T;
#else
        typedef typename ::std::remove_const<T>::type _mutable_T;
#endif

     public:
        typedef typename ::boost::mpl::eval_if<
                    typename ::boost::mpl::eval_if<
                        typename ::boost::mpl::if_<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                            ::boost::is_convertible<
#else
                            ::std::is_convertible<
#endif
                                typename ::boost::graph::graph_traits<
                                    _mutable_T
                                >::traversal_category
                              , ::boost::adjacency_graph_tag
                            >
                          , ::boost::concept::traits::has_adjacency_iterator<
                                ::boost::graph::graph_traits<_mutable_T>
                            >
                          , ::boost::mpl::false_
                        >::type
                      , ::boost::concept::traits::_detail::metafunction
                        ::has_adjacency_graph_expr<_mutable_T>
                      , ::boost::mpl::false_
                    >::type
                  , ::boost::concept::traits::_detail::metafunction
                    ::has_adjacency_graph_ops<_mutable_T>
                  , ::boost::mpl::false_
                >::type
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_graph.hpp>

//[reference__is_adjacency_graph
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_adjacency_graph
//<-
#if defined BOOST_CONCEPT_TRAITS_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_is_graph_<T>
          , _mpl_eval_if_<
                typename _mpl_if_<
                    _std_is_convertible_<
                        typename _graph_traits_<
                            typename _std_remove_const_<T>::type
                        >::traversal_category
                    >
                  , _bct_has_adjacency_iterator_<
                        _graph_traits_<
                            typename _std_remove_const_<T>::type
                        >
                    >
                  , _mpl_false_
                >::type
              , _mpl_eval_if_<
                    _is_valid_expression_(
                        adjacent_vertices(
                            _declval_<
                                typename _graph_traits_<
                                    typename _std_add_const_<T>::type
                                >::vertex_descriptor const
                            >()
                          , _declval_<typename _std_add_const_<T>::type>()
                        )
                    )
                  , _mpl_if_<
                      , _std_is_same_<
                            _decltype_(
                                adjacent_vertices(
                                    _declval_<
                                        typename _graph_traits_<
                                            typename _std_add_const_<T>::type
                                        >::vertex_descriptor const
                                    >()
                                  , _declval_<
                                        typename _std_add_const_<T>::type
                                    >()
                                )
                            )
                          , _std_pair_<
                                typename _graph_traits_<
                                    typename _std_remove_const_<T>::type
                                >::adjacency_iterator
                              , typename _graph_traits_<
                                    typename _std_remove_const_<T>::type
                                >::adjacency_iterator
                            >
                        >
                      , _mpl_true_
                      , _mpl_false_
                    >
                  , _mpl_false_
                >
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined BOOST_CONCEPT_TRAITS_CONFIG_DOCUMENTATION
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_graph<T>
          , ::boost::concept::traits::_detail::metafunction
            ::is_adjacency_graph_impl<T>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_TRAITS_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

