// Copyright (C) 2011-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_POLICY_SELECTOR_BINARY_PREDICATE_NEGATION_HPP
#define BOOST_CONCEPT_POLICY_SELECTOR_BINARY_PREDICATE_NEGATION_HPP

namespace boost { namespace concept { namespace policy {
namespace _detail { namespace metafunction {

    template <typename Pred>
    class binary_negation_predicate
    {
        Pred _f;

     public:
        typedef typename Pred::result_type result_type;
        typedef typename Pred::first_argument_type first_argument_type;
        typedef typename Pred::second_argument_type second_argument_type;

        binary_negation_predicate();

        binary_negation_predicate(Pred const& f);

        result_type
            operator()(
                first_argument_type lhs
              , second_argument_type rhs
            ) const;
    };

    template <typename Pred>
    inline binary_negation_predicate<Pred>::binary_negation_predicate() : _f()
    {
    }

    template <typename Pred>
    inline binary_negation_predicate<Pred>::binary_negation_predicate(
        Pred const& f
    ) : _f(f)
    {
    }

    template <typename Pred>
    inline typename binary_negation_predicate<Pred>::result_type
        binary_negation_predicate<Pred>::operator()(
            typename binary_negation_predicate<Pred>::first_argument_type lhs
          , typename binary_negation_predicate<Pred>::second_argument_type rhs
        ) const
    {
        return !_f(lhs, rhs);
    }
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::policy

#include <boost/concept/policy/selector_fwd.hpp>
#include <boost/mpl/apply.hpp>

//[reference__binary_predicate_negation_selector
namespace boost { namespace concept { namespace policy {

    template <typename Selector>
    struct binary_predicate_negation_selector
    {
        template <typename T>
        struct apply
        {
            typedef ::boost::concept::policy::_detail::metafunction
                    ::binary_negation_predicate<
                        typename ::boost::mpl::apply1<Selector,T>::type
                    >
                    type;
        };
    };
}}}  // namespace boost::concept::policy
//]

#endif  // include guard

