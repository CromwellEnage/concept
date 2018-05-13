// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_INDEXABLE_TRAVERSAL_ITERATOR_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_INDEXABLE_TRAVERSAL_ITERATOR_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_bidir_traversal_iterator.hpp>
#include <boost/concept/traits/query/is_readable_iterator.hpp>
#include <boost/concept/traits/_detail/metafunction/is_indexable_iterator.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

//[reference__is_indexable_traversal_iterator
namespace boost { namespace concept { namespace traits {

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
          typename _mpl_if_<
            _bct_is_bidirectional_traversal_iterator_<T>
          , _bct_is_readable_iterator_<T>
          , _mpl_false_
          >::type
        , _mpl_eval_if_<
            _bct_is_additive_<
              typename _std_remove_const_<
                typename _std_remove_reference_<T>::type
              >::type
            , typename _std_add_const_<
                typename _bct_iterator_difference_of_<T>::type
              >::type
            >
          , _mpl_eval_if_<
              _bct_is_comparable_<T>
            , _mpl_eval_if_<
                _is_valid_expression_(
                  _bct_declref_<
                    typename _std_remove_const_<
                      typename _std_remove_reference_<T>::type
                    >::type
                  >()[
                    _declval_<
                      typename _std_add_const_<
                        typename _bct_iterator_difference_of_<T>::type
                      >::type
                    >()
                  ]
                )
              , _mpl_eval_if_<
                  IsStrict
                , _mpl_eval_if_<
                    _std_is_convertible_<
                      _decltype_(
                        _bct_declref_<
                          typename _std_remove_const_<
                            typename _std_remove_reference_<T>::type
                          >::type
                        >()[
                          _declval_<
                            typename _std_add_const_<
                              typename _bct_iterator_difference_of_<T>::type
                            >::type
                          >()
                        ]
                      )
                    , typename _iterator_value_<
                        _std_iterator_traits_<
                          typename _std_remove_const_<
                            typename _std_remove_reference_<T>::type
                          >::type
                        >
                      >::type
                    >
                  , _mpl_if_<
                      _std_is_convertible_<
                        _decltype_(
                          _bct_declref_<
                            typename _std_remove_const_<
                              typename _std_remove_reference_<T>::type
                            >::type
                          >()[
                            _declval_<
                              typename _std_add_const_<
                                typename _bct_iterator_difference_of_<T>::type
                              >::type
                            >()
                          ]
                        )
                      , _decltype_(
                          *(
                            _bct_declref_<
                              typename _std_remove_const_<
                                typename _std_remove_reference_<T>::type
                              >::type
                            >() + _declval_<
                              typename _std_add_const_<
                                typename _bct_iterator_difference_of_<T>::type
                              >::type
                            >()
                          )
                        )
                      >
                    , _mpl_true_
                    , _mpl_false_
                    >
                  , _mpl_false_
                  >
                , _mpl_true_
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
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_bidirectional_traversal_iterator<T>
          , ::boost::mpl::if_<
                ::boost::concept::traits::is_readable_iterator<T>
              , ::boost::concept::traits::_detail::metafunction
                ::is_indexable_iterator<T,IsStrict>
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

#include <iterator>

namespace boost { namespace concept { namespace traits {

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::std::reverse_iterator<T>
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T,IsStrict>
    {
    };

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::std::reverse_iterator<T> const
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T,IsStrict>
    {
    };

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::std::reverse_iterator<T>&
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T,IsStrict>
    {
    };

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::std::reverse_iterator<T> const&
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T,IsStrict>
    {
    };
}}}  // namespace boost::concept::traits

#include <boost/move/move.hpp>

namespace boost { namespace concept { namespace traits {

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::move_iterator<T>
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T,IsStrict>
    {
    };

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::move_iterator<T> const
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T,IsStrict>
    {
    };

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::move_iterator<T>&
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T,IsStrict>
    {
    };

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::move_iterator<T> const&
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T,IsStrict>
    {
    };
}}}  // namespace boost::concept::traits

#include <boost/iterator/reverse_iterator.hpp>

namespace boost { namespace concept { namespace traits {

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::iterators::reverse_iterator<T>
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T,IsStrict>
    {
    };

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::iterators::reverse_iterator<T> const
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T,IsStrict>
    {
    };

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::iterators::reverse_iterator<T>&
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T,IsStrict>
    {
    };

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::iterators::reverse_iterator<T> const&
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T,IsStrict>
    {
    };
}}}  // namespace boost::concept::traits

#include <boost/intrusive/detail/reverse_iterator.hpp>

namespace boost { namespace concept { namespace traits {

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::intrusive::reverse_iterator<T>
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T,IsStrict>
    {
    };

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::intrusive::reverse_iterator<T> const
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T,IsStrict>
    {
    };

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::intrusive::reverse_iterator<T>&
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T,IsStrict>
    {
    };

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::intrusive::reverse_iterator<T> const&
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T,IsStrict>
    {
    };
}}}  // namespace boost::concept::traits

#include <boost/ptr_container/detail/void_ptr_iterator.hpp>

namespace boost { namespace concept { namespace traits {

    template <typename VoidIter, typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::void_ptr_iterator<VoidIter,T>
      , IsStrict
    > : ::boost::concept::traits
        ::is_indexable_traversal_iterator<VoidIter,IsStrict>
    {
    };

    template <typename VoidIter, typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::void_ptr_iterator<VoidIter,T> const
      , IsStrict
    > : ::boost::concept::traits
        ::is_indexable_traversal_iterator<VoidIter,IsStrict>
    {
    };

    template <typename VoidIter, typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::void_ptr_iterator<VoidIter,T>&
      , IsStrict
    > : ::boost::concept::traits
        ::is_indexable_traversal_iterator<VoidIter,IsStrict>
    {
    };

    template <typename VoidIter, typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::void_ptr_iterator<VoidIter,T> const&
      , IsStrict
    > : ::boost::concept::traits
        ::is_indexable_traversal_iterator<VoidIter,IsStrict>
    {
    };
}}}  // namespace boost::concept::traits

#include <boost/numeric/ublas/detail/iterator.hpp>

namespace boost { namespace concept { namespace traits {

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::numeric::ublas::reverse_iterator_base<T>
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T,IsStrict>
    {
    };

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::numeric::ublas::reverse_iterator_base<T> const
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T>
    {
    };

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::numeric::ublas::reverse_iterator_base<T>&
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T,IsStrict>
    {
    };

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::numeric::ublas::reverse_iterator_base<T> const&
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T,IsStrict>
    {
    };
}}}  // namespace boost::concept::traits

namespace boost { namespace concept { namespace traits {

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::numeric::ublas::reverse_iterator_base1<T>
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T,IsStrict>
    {
    };

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::numeric::ublas::reverse_iterator_base1<T> const
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T,IsStrict>
    {
    };

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::numeric::ublas::reverse_iterator_base1<T>&
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T,IsStrict>
    {
    };

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::numeric::ublas::reverse_iterator_base1<T> const&
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T,IsStrict>
    {
    };
}}}  // namespace boost::concept::traits

namespace boost { namespace concept { namespace traits {

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::numeric::ublas::reverse_iterator_base2<T>
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T,IsStrict>
    {
    };

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::numeric::ublas::reverse_iterator_base2<T> const
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T,IsStrict>
    {
    };

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::numeric::ublas::reverse_iterator_base2<T>&
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T,IsStrict>
    {
    };

    template <typename T, typename IsStrict>
    struct is_indexable_traversal_iterator<
        ::boost::numeric::ublas::reverse_iterator_base2<T> const&
      , IsStrict
    > : ::boost::concept::traits::is_indexable_traversal_iterator<T,IsStrict>
    {
    };
}}}  // namespace boost::concept::traits

#endif  // include guard

