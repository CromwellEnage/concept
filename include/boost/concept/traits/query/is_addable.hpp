// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_ADDABLE_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_ADDABLE_HPP

#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/declval.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/typeof/typeof.hpp>
#endif

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/is_convertible.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Addend, typename Sum>
    struct is_addable_impl
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      : ::boost::is_convertible<
#else
      : ::boost::mpl::if_<
            ::std::is_convertible<
#endif
#if defined(BOOST_NO_CXX11_DECLTYPE)
                BOOST_TYPEOF_KEYWORD(
                    ::boost::declval<T>() + ::boost::declval<Addend>()
                )
#else
                decltype(::boost::declval<T>() + ::boost::declval<Addend>())
#endif
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
              , typename ::boost::remove_const<
                    typename ::boost::remove_reference<Sum>::type
                >::type
#else
              , typename ::std::remove_const<
                    typename ::std::remove_reference<Sum>::type
                >::type
#endif
            >
#if !defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
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

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/add_pointer.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Addend>
    class has_addition_op
    {
        template <typename B, typename D>
        static ::boost::type_traits::yes_type
            _check(
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::add_pointer<
#else
                typename ::std::add_pointer<
#endif
#if defined(BOOST_NO_CXX11_DECLTYPE)
                    BOOST_TYPEOF_KEYWORD(
                        ::boost::declval<B>() + ::boost::declval<D>()
                    )
#else
                    decltype(::boost::declval<B>() + ::boost::declval<D>())
#endif
                >::type
            );

        template <typename B, typename D>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::boost::concept::traits::_detail::metafunction
                ::has_addition_op<T,Addend>::BOOST_NESTED_TEMPLATE
                _check<T,Addend>(BOOST_TTI_DETAIL_NULLPTR)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>

//[reference__is_addable
namespace boost { namespace concept { namespace traits {

    template <typename T, typename Addend, typename Sum>
    struct is_addable
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _is_valid_expression_(
                _declval_<T>() + _declval_<Addend>()
            )
          , _mpl_eval_if_<
                _std_is_same_<Sum,boost::concept::policy::use_default>
              , _mpl_eval_if_<
                    _std_is_convertible_<
                        _decltype_(
                            _declval_<T>() + _declval_<Addend>()
                        )
                      , typename _std_remove_const_<
                            typename _std_remove_reference_<T>::type
                        >::type
                    >
                  , _mpl_if_<
                        _std_is_const_<T>
                      , _mpl_true_
                      , _bct_is_addition_assignable_<T,Addend>
                    >
                  , _mpl_false_
                >
              , _mpl_if_<
                    _std_is_convertible_<
                        _decltype_(
                            _declval_<T>() + _declval_<Addend>()
                        )
                      , typename _std_remove_const_<
                            typename _std_remove_reference_<Sum>::type
                        >::type
                    >
                  , _mpl_true_
                  , _mpl_false_
                >
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::if_<
            typename ::boost::concept::traits::_detail::metafunction
            ::has_addition_op<T,Addend>::type
          , ::boost::concept::traits::_detail::metafunction
            ::is_addable_impl<T,Addend,Sum>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#include <boost/concept/traits/query/is_addition_assignable.hpp>
#include <boost/concept/policy/use_default.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/config/workaround.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS) || ( \
        BOOST_WORKAROUND(BOOST_MSVC, >= 1700) && \
        BOOST_WORKAROUND(BOOST_MSVC, < 1800) \
    )
#include <boost/type_traits/is_const.hpp>
#endif

namespace boost { namespace concept { namespace traits {

    template <typename T, typename Addend>
    struct is_addable<T,Addend,::boost::concept::policy::use_default>
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_addable<T,Addend,T>
          , ::boost::mpl::if_<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS) || ( \
        BOOST_WORKAROUND(BOOST_MSVC, >= 1700) && \
        BOOST_WORKAROUND(BOOST_MSVC, < 1800) \
    )
                ::boost::is_const<T>
#else
                ::std::is_const<T>
#endif
              , ::boost::mpl::true_
              , ::boost::concept::traits::is_addition_assignable<T,Addend>
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace boost::concept::traits

#endif  // include guard

