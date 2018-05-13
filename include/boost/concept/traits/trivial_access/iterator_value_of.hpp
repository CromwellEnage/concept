// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_TRIVIAL_ACCESS_ITERATOR_VALUE_OF_HPP
#define BOOST_CONCEPT_TRAITS_TRIVIAL_ACCESS_ITERATOR_VALUE_OF_HPP

#include <boost/concept/traits/introspection/nested_type/has_value_type.hpp>
#include <boost/mpl/assert.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct value_type_of_insert_iterator
    {
        BOOST_MPL_ASSERT((
            ::boost::concept::traits::has_value_type<
                typename T::container_type
            >
        ));
        typedef typename T::container_type::value_type type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type/has_char_type.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_container_type.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_iterator_value.hpp>
#include <boost/iterator/iterator_traits.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#else
#include <type_traits>
#endif

#if !defined(BOOST_NO_CXX17_ITERATOR_TRAITS)
#include <iterator>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <
        typename T
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      , typename _mutable_T = typename ::boost::remove_const<
            typename ::boost::remove_reference<T>::type
        >::type
#else
      , typename _mutable_T = typename ::std::remove_const<
            typename ::std::remove_reference<T>::type
        >::type
#endif
    >
    struct iterator_value_of
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_char_type<T>
          , ::boost::concept::traits::_detail::metafunction
            ::char_type_of_actual<_mutable_T>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_container_type<T>
              , ::boost::concept::traits::_detail::metafunction
                ::value_type_of_insert_iterator<_mutable_T>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_iterator_value<T>
#if defined(BOOST_NO_CXX17_ITERATOR_TRAITS)
                  , ::boost::iterators::iterator_value<_mutable_T>
#else
                  , ::boost::iterators::iterator_value<
                        ::std::iterator_traits<_mutable_T>
                    >
#endif
                  , ::boost::mpl::false_
                >
            >
        >
    {
    };

    template <typename T, typename CharT, typename Traits>
    struct iterator_value_of< ::std::ostream_iterator<T,CharT,Traits> >
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      : ::boost::remove_const<typename ::boost::remove_reference<T>::type>
#else
      : ::std::remove_const<typename ::std::remove_reference<T>::type>
#endif
    {
    };

    template <typename T, typename CharT, typename Traits>
    struct iterator_value_of< ::std::ostream_iterator<T,CharT,Traits> const>
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      : ::boost::remove_const<typename ::boost::remove_reference<T>::type>
#else
      : ::std::remove_const<typename ::std::remove_reference<T>::type>
#endif
    {
    };

    template <typename T, typename CharT, typename Traits>
    struct iterator_value_of< ::std::ostream_iterator<T,CharT,Traits>&>
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      : ::boost::remove_const<typename ::boost::remove_reference<T>::type>
#else
      : ::std::remove_const<typename ::std::remove_reference<T>::type>
#endif
    {
    };

    template <typename T, typename CharT, typename Traits>
    struct iterator_value_of< ::std::ostream_iterator<T,CharT,Traits> const&>
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      : ::boost::remove_const<typename ::boost::remove_reference<T>::type>
#else
      : ::std::remove_const<typename ::std::remove_reference<T>::type>
#endif
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/trivial_access_fwd.hpp>
#include <boost/type_erasure/is_placeholder.hpp>
#include <boost/mpl/identity.hpp>

//[reference__iterator_value_of
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct iterator_value_of
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _type_erasure_is_placeholder_<T>
          , _mpl_identity_<void>
          , _mpl_eval_if_<
                _bct_has_char_type_<T>
              , _mpl_identity_<
                    typename _std_remove_const_<
                        typename _std_remove_reference_<T>::type
                    >::type::char_type
                >
              , _mpl_eval_if_<
                    _bct_has_container_type_<T>
                  , _mpl_identity_<
                        typename _std_remove_const_<
                            typename _std_remove_reference_<T>::type
                        >::type::container_type::value_type
                    >
                  , _mpl_eval_if_<
                        _bct_has_iterator_value_<T>
                      , _iterator_value_<
                            _std_iterator_traits_<
                                typename _std_remove_const_<
                                    typename _std_remove_reference_<T>::type
                                >::type
                            >
                        >
                      , _mpl_false_
                    >
                >
            >
        >
//<-
#else
      : ::boost::mpl::eval_if<
            ::boost::type_erasure::is_placeholder<T>
          , ::boost::mpl::identity<void>
          , ::boost::concept::traits::_detail::metafunction
            ::iterator_value_of<T>
        >
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#if defined(BOOST_NO_CXX11_TEMPLATE_ALIASES)

namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct iterator_value_of_t
      : ::boost::concept::traits::iterator_value_of<T>::type
    {
    };
}}}  // namespace boost::concept::traits

#endif

#endif  // include guard

