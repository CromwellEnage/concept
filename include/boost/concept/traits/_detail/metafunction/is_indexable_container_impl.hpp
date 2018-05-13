// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_INDEXABLE_CONTAINER_IMPL_HPP
#define \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_INDEXABLE_CONTAINER_IMPL_HPP

#include <boost/utility/declref.hpp>
#include <boost/utility/declval.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
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

    template <typename Result, typename T>
    struct is_result_same_as_dereferenced_begin
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
      : ::boost::is_same<
#else
      : ::boost::mpl::if_<
            ::std::is_same<
#endif
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF_KEYWORD(*::boost::declref<T>().begin())
#else
                decltype(*::boost::declref<T>().begin())
#endif
              , Result
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

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_convertible.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename Result, typename T, typename Subscript>
    struct is_result_same_as_at
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
                (::boost::declref<T>().at(::boost::declval<Subscript>()))
              , Result
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

    template <typename T, typename Subscript, typename Result>
    class has_container_indexing_operator
    {
        template <typename B, typename S>
        static ::boost::type_traits::yes_type
            _check_at(
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
                    (::boost::declref<B>().at(::boost::declval<S>()))
                >::type
            );

        template <typename B, typename S>
        static ::boost::type_traits::no_type _check_at(...);

     public:
        typedef typename ::boost::mpl::if_c<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_container_indexing_operator<T,Subscript,Result>
                        ::_check_at<T,Subscript>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                  , ::boost::concept::traits::_detail::metafunction
                    ::is_result_same_as_at<Result,T,Subscript>
                  , ::boost::concept::traits::_detail::metafunction
                    ::is_result_same_as_dereferenced_begin<Result,T>
                >::type
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query/is_subscriptable.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/eval_if.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_const.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    class is_indexable_container_impl
    {
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
        typedef typename ::boost::add_const<typename T::size_type>::type _Siz;
#else
        typedef typename ::std::add_const<typename T::size_type>::type _Siz;
#endif

     public:
        typedef typename ::boost::mpl::eval_if<
                    ::boost::concept::traits::is_subscriptable<
                        T const
                      , _Siz
                      , ::boost::concept::traits::_detail::metafunction
                        ::has_container_indexing_operator<
                            T
                          , _Siz
                          , ::boost::mpl::_
                        >
                    >
                  , ::boost::concept::traits::is_subscriptable<
                        T
                      , _Siz
                      , ::boost::concept::traits::_detail::metafunction
                        ::has_container_indexing_operator<
                            T
                          , _Siz
                          , ::boost::mpl::_
                        >
                    >
                  , ::boost::mpl::if_<
                        ::boost::concept::traits::is_subscriptable<
                            T const
                          , _Siz
                        >
                      , ::boost::concept::traits::is_subscriptable<
                            T
                          , _Siz
                        >
                      , ::boost::mpl::false_
                    >
                >::type
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include \
<boost/concept/traits/_detail/metafunction/is_reversible_cont_impl.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename UMFC>
    struct is_indexable_container
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::_detail::metafunction
            ::is_reversible_container_impl<T,UMFC>
          , ::boost::concept::traits::_detail::metafunction
            ::is_indexable_container_impl<T>
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

