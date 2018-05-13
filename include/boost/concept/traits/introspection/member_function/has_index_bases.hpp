// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_INDEX_BASES_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_INDEX_BASES_HPP

#include <boost/utility/declref.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_index_bases_impl
      : ::boost::mpl::apply1<
            ResultPlaceholderExpr
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF_KEYWORD(::boost::declref<T>().index_bases())
#else
          , decltype(::boost::declref<T>().index_bases())
#endif
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/is_raw_pointer_of.hpp>
#include <boost/concept/traits/trivial_access/index_of.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_index_bases_default
      : ::boost::concept::traits::is_raw_pointer_of<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF_KEYWORD(::boost::declref<T>().index_bases())
#else
            decltype(::boost::declref<T>().index_bases())
#endif
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
          , typename ::boost::add_const<
#else
          , typename ::std::add_const<
#endif
                typename ::boost::concept::traits::index_of<T>::type
            >::type
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type/has_index.hpp>
#include <boost/concept/policy/use_default.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_index_bases_impl<T,::boost::concept::policy::use_default>
      : ::boost::mpl::if_<
            ::boost::concept::traits::has_index<T>
          , ::boost::concept::traits::_detail::metafunction
            ::has_index_bases_default<T>
          , ::boost::mpl::false_
        >::type
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
    class has_index_bases
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _ch(
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::add_pointer<
#else
                typename ::std::add_pointer<
#endif
#if defined BOOST_NO_CXX11_DECLTYPE
                    BOOST_TYPEOF_KEYWORD(::boost::declref<B>().index_bases())
#else
                    decltype(::boost::declref<B>().index_bases())
#endif
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _ch(...);

     public:
        typedef ::boost::mpl::bool_<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_index_bases<T>::_ch<T>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                >
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/member_function_fwd.hpp>

//[reference__has_index_bases
namespace boost { namespace concept { namespace traits {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_index_bases
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _is_valid_expression_(_declref_<T>().index_bases())
          , _mpl_eval_if_<
                _std_is_same_<
                    ResultPlaceholderExpr
                  , boost::concept::policy::use_default
                >
              , _mpl_if_<
                    _bct_has_index_<T>
                  , _bct_is_raw_pointer_of_<
                        _decltype_(_declref_<T>().index_bases())
                      , typename _std_add_const_<
                            typename _bct_index_of_<T>::type
                        >::type
                    >
                  , _mpl_false_
                >
              , _mpl_apply1_<
                    ResultPlaceholderExpr
                  , _decltype_(_declref_<T>().index_bases())
                >
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::if_<
            typename ::boost::concept::traits::_detail::metafunction
            ::has_index_bases<T>::type
          , ::boost::concept::traits::_detail::metafunction
            ::has_index_bases_impl<T,ResultPlaceholderExpr>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

