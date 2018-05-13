// Copyright (C) 2011-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_POLICY_SELECTOR_UNARY_PREDICATE_NEGATION_HPP
#define BOOST_CONCEPT_POLICY_SELECTOR_UNARY_PREDICATE_NEGATION_HPP

namespace boost { namespace concept { namespace policy {
namespace _detail { namespace metafunction {

    template <typename Pred>
    class unary_negation_predicate
    {
        Pred _f;

     public:
        typedef typename Pred::result_type result_type;
        typedef typename Pred::argument_type argument_type;

        unary_negation_predicate();

        unary_negation_predicate(Pred const& f);

        result_type operator()(argument_type argument) const;
    };

    template <typename Pred>
    inline unary_negation_predicate<Pred>::unary_negation_predicate() : _f()
    {
    }

    template <typename Pred>
    inline unary_negation_predicate<Pred>::unary_negation_predicate(
        Pred const& f
    ) : _f(f)
    {
    }

    template <typename Pred>
    inline typename unary_negation_predicate<Pred>::result_type
        unary_negation_predicate<Pred>::operator()(
            typename unary_negation_predicate<Pred>::argument_type argument
        ) const
    {
        return !_f(argument);
    }
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::policy

#include <boost/concept/policy/selector_fwd.hpp>
#include <boost/mpl/apply.hpp>

//[reference__unary_predicate_negation_selector
namespace boost { namespace concept { namespace policy {

    template <typename Selector>
    struct unary_predicate_negation_selector
    {
        template <typename T>
        struct apply
        {
            typedef ::boost::concept::policy::_detail::metafunction
                    ::unary_negation_predicate<
                        typename ::boost::mpl::apply1<Selector,T>::type
                    >
                    type;
        };
    };
}}}  // namespace boost::concept::policy
//]

#endif  // include guard

