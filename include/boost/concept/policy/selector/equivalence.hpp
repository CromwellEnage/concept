// Copyright (C) 2011-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_POLICY_SELECTOR_EQUIVALENCE_HPP
#define BOOST_CONCEPT_POLICY_SELECTOR_EQUIVALENCE_HPP

namespace boost { namespace concept { namespace policy {
namespace _detail { namespace metafunction {

    template <typename Pred>
    class equivalence_predicate
    {
        Pred _f;

     public:
        typedef typename Pred::result_type result_type;
        typedef typename Pred::first_argument_type first_argument_type;
        typedef typename Pred::second_argument_type second_argument_type;

        equivalence_predicate();

        equivalence_predicate(Pred const& f);

        result_type
            operator()(
                first_argument_type lhs
              , second_argument_type rhs
            ) const;
    };

    template <typename Pred>
    inline equivalence_predicate<Pred>::equivalence_predicate() : _f()
    {
    }

    template <typename Pred>
    inline equivalence_predicate<Pred>::equivalence_predicate(Pred const& f)
      : _f(f)
    {
    }

    template <typename Pred>
    inline typename equivalence_predicate<Pred>::result_type
        equivalence_predicate<Pred>::operator()(
            typename equivalence_predicate<Pred>::first_argument_type lhs
          , typename equivalence_predicate<Pred>::second_argument_type rhs
        ) const
    {
        return !_f(lhs, rhs) && !_f(rhs, lhs);
    }
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::policy

#include <boost/concept/policy/selector_fwd.hpp>
#include <boost/concept/policy/selector/less_than.hpp>
#include <boost/mpl/apply.hpp>

//[reference__equivalence_selector
namespace boost { namespace concept { namespace policy {

    template <typename Selector>
    struct equivalence_selector
    {
        template <typename T>
        struct apply
        {
            typedef ::boost::concept::policy::_detail::metafunction
                    ::equivalence_predicate<
                        typename ::boost::mpl::apply1<Selector,T>::type
                    >
                    type;
        };
    };
}}}  // namespace boost::concept::policy
//]

#endif  // include guard

