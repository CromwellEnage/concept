// Copyright (C) 2014-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_VALUE_DISTRIBUTION_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_VALUE_DISTRIBUTION_HPP

#include <boost/concept/archetype/value_generator.hpp>
#include <boost/concept/traits/trivial_access/result_type_of.hpp>
#include <boost/concept/traits/declref.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/typeof/typeof.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename ResultPlaceholderExpr>
    struct is_value_distribution_impl
      : ::boost::mpl::apply1<
            ResultPlaceholderExpr
#if defined(BOOST_NO_CXX11_DECLTYPE)
          , BOOST_TYPEOF_KEYWORD(
                ::boost::concept::traits::declref<T>().operator()(
                    ::boost::concept::traits::declref<
                        ::boost::concept::value_generator_archetype<
                            typename ::boost::concept::traits
                            ::result_type_of<T>::type
                        >
                    >()
                )
            )
#else
          , decltype(
                ::boost::concept::traits::declref<T>().operator()(
                    ::boost::concept::traits::declref<
                        ::boost::concept::value_generator_archetype<
                            typename ::boost::concept::traits
                            ::result_type_of<T>::type
                        >
                    >()
                )
            )
#endif  // BOOST_NO_CXX11_DECLTYPE
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query/is_less_than_comparable.hpp>
#include <boost/concept/policy/use_default.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_value_distribution_impl<T,::boost::concept::policy::use_default>
      : ::boost::concept::traits::is_less_than_comparable<
#if defined(BOOST_NO_CXX11_DECLTYPE)
            BOOST_TYPEOF_KEYWORD(
                ::boost::concept::traits::declref<T>().operator()(
                    ::boost::concept::traits::declref<
                        ::boost::concept::value_generator_archetype<
                            typename ::boost::concept::traits
                            ::result_type_of<T>::type
                        >
                    >()
                )
            )
#else
            decltype(
                ::boost::concept::traits::declref<T>().operator()(
                    ::boost::concept::traits::declref<
                        ::boost::concept::value_generator_archetype<
                            typename ::boost::concept::traits
                            ::result_type_of<T>::type
                        >
                    >()
                )
            )
#endif  // BOOST_NO_CXX11_DECLTYPE
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/tti/detail/dnullptr.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/add_pointer.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename ResultPlaceholderExpr>
    class is_value_distribution
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check(
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::add_pointer<
#else
                typename ::std::add_pointer<
#endif
#if defined(BOOST_NO_CXX11_DECLTYPE)
                    BOOST_TYPEOF_KEYWORD(
                        ::boost::concept::traits::declref<B>().operator()(
                            ::boost::concept::traits::declref<
                                ::boost::concept::value_generator_archetype<
                                    typename ::boost::concept::traits
                                    ::result_type_of<B>::type
                                >
                            >()
                        )
                    )
#else
                    decltype(
                        ::boost::concept::traits::declref<B>().operator()(
                            ::boost::concept::traits::declref<
                                ::boost::concept::value_generator_archetype<
                                    typename ::boost::concept::traits
                                    ::result_type_of<B>::type
                                >
                            >()
                        )
                    )
#endif  // BOOST_NO_CXX11_DECLTYPE
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef typename ::boost::mpl::if_c<
            sizeof(
                ::boost::concept::traits::_detail::metafunction
                ::is_value_distribution<T,ResultPlaceholderExpr>
                ::_check<T>(BOOST_TTI_DETAIL_NULLPTR)
            ) == sizeof(::boost::type_traits::yes_type)
          , ::boost::concept::traits::_detail::metafunction
            ::is_value_distribution_impl<T,ResultPlaceholderExpr>
          , ::boost::mpl::false_
        >::type type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/introspection/member_function/has_reset.hpp>
#include <boost/concept/traits/introspection/member_function/has_min.hpp>
#include <boost/concept/traits/introspection/member_function/has_max.hpp>
#include <boost/mpl/eval_if.hpp>

//[reference__is_value_distribution
namespace boost { namespace concept { namespace traits {

    template <typename T, typename ResultPlaceholderExpr>
    struct is_value_distribution
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
          _bct_has_reset_<T>
        , _mpl_eval_if_<
            _bct_has_min_<T>
          , _mpl_eval_if_<
              _bct_has_max_<T>
            , _mpl_eval_if_<
                _is_valid_expression_(
                  _bct_declref_<T>()(
                    _bct_declref_<
                      _bc_value_generator_archetype_<
                        typename _bct_result_type_of_<T>::type
                      >
                    >()
                  )
                )
              , _mpl_eval_if_<
                  _std_is_same_<
                    ResultPlaceholderExpr
                  , boost::concept::policy::use_default
                  >
                , _bct_is_less_than_comparable_<
                    _decltype_(
                      _bct_declref_<T>()(
                        _bct_declref_<
                          _bc_value_generator_archetype_<
                            typename _bct_result_type_of_<T>::type
                          >
                        >()
                      )
                    )
                  >
                , _mpl_apply1_<
                    ResultPlaceholderExpr
                  , _decltype_(
                      _bct_declref_<T>()(
                        _bct_declref_<
                          _bc_value_generator_archetype_<
                            typename _bct_result_type_of_<T>::type
                          >
                        >()
                      )
                    )
                  >
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
            ::boost::concept::traits::has_reset<T>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_min<T>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_max<T>
                  , ::boost::concept::traits::_detail::metafunction
                    ::is_value_distribution<T,ResultPlaceholderExpr>
                  , ::boost::mpl::false_
                >
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

