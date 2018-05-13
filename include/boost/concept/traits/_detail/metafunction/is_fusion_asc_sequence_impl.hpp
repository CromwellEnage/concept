// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_FUSION_ASC_SEQUENCE_IMPL_HPP
#define \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_FUSION_ASC_SEQUENCE_IMPL_HPP

#include <boost/utility/declref.hpp>
#include <boost/fusion/sequence/intrinsic/at_key.hpp>
#include <boost/fusion/sequence/intrinsic/value_at_key.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_convertible.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Key>
    struct has_fusion_associative_sequence_access_by_key
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
      : ::boost::is_convertible<
#else
      : ::boost::mpl::if_<
            ::std::is_convertible<
#endif
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF_KEYWORD
#else
                decltype
#endif
                (::boost::fusion::at_key<Key>(::boost::declref<T>()))
              , typename ::boost::fusion::result_of::value_at_key<T,Key>::type
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

    template <typename T, typename Key>
    class has_fusion_assoc_sequence_at_key
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
                    (::boost::fusion::at_key<Key>(::boost::declref<B>()))
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef typename ::boost::mpl::if_c<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_fusion_assoc_sequence_at_key<T,Key>
                        ::_check<T>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                  , ::boost::concept::traits::_detail::metafunction
                    ::has_fusion_associative_sequence_access_by_key<T,Key>
                  , ::boost::mpl::false_
                >::type
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query/is_mpl_boolean_constant.hpp>
#include <boost/concept/traits/introspection/nested_type/has_type.hpp>
#include <boost/fusion/sequence/intrinsic/has_key.hpp>
#include <boost/fusion/sequence/intrinsic/begin.hpp>
#include <boost/fusion/iterator/key_of.hpp>
#include <boost/mpl/eval_if.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/remove_const.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    class is_nonempty_fusion_associative_sequence_impl
    {
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
        typedef typename ::boost::remove_const<T>::type _mutable_T;
#else
        typedef typename ::std::remove_const<T>::type _mutable_T;
#endif
        typedef typename ::boost::fusion::result_of::key_of<
                    typename ::boost::fusion::result_of::begin<T>::type
                >::type
                _Key;

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
                    (::boost::fusion::has_key<_Key>(::boost::declref<B>()))
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef typename ::boost::mpl::eval_if_c<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::is_nonempty_fusion_associative_sequence_impl<T>
                        ::_check<T>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                  , ::boost::mpl::eval_if<
                        ::boost::concept::traits::is_mpl_boolean_constant<
                            ::boost::fusion::result_of
                            ::has_key<_mutable_T,_Key>
                        >
                      , ::boost::mpl::eval_if<
                            ::boost::fusion::result_of
                            ::has_key<_mutable_T,_Key>
                          , ::boost::mpl::eval_if<
                                ::boost::concept::traits::has_type<
                                    ::boost::fusion::result_of
                                    ::value_at_key<T,_Key>
                                >
                              , ::boost::concept::traits
                                ::_detail::metafunction
                                ::has_fusion_assoc_sequence_at_key<T,_Key>
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

#include \
<boost/concept/traits/_detail/metafunction/is_fusion_fwd_sequence_impl.hpp>
#include \
<boost/concept/traits/_detail/metafunction/has_fusion_asc_iterator_ops.hpp>
#include <boost/mpl/apply.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename ItrPredPlaceholderExpr>
    class is_nonempty_fusion_associative_sequence
    {
        typedef typename ::boost::fusion::result_of::begin<T>::type _Itr;

     public:
        typedef typename ::boost::mpl::eval_if<
                    typename ::boost::mpl::eval_if<
                        typename ::boost::mpl::eval_if<
                            typename ::boost::concept::traits
                            ::_detail::metafunction
                            ::is_nonempty_fusion_forward_sequence<
                                T
                              , ItrPredPlaceholderExpr
                            >::type
                          , ::boost::mpl::apply1<ItrPredPlaceholderExpr,_Itr>
                          , ::boost::mpl::false_
                        >::type
                      , ::boost::concept::traits::_detail::metafunction
                        ::has_fusion_associative_iterator_ops<_Itr>
                      , ::boost::mpl::false_
                    >::type
                  , ::boost::concept::traits::_detail::metafunction
                    ::is_nonempty_fusion_associative_sequence_impl<T>
                  , ::boost::mpl::false_
                >::type
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

