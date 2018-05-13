// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_ARCHETYPE_INDEXABLE_ITERATOR_HPP
#define BOOST_CONCEPT_ARCHETYPE_INDEXABLE_ITERATOR_HPP

#include <boost/iterator.hpp>

//[reference__indexable_iterator_archetype
namespace boost { namespace concept {

    template <typename T>
    struct indexable_iterator_archetype
    {
        typedef indexable_iterator_archetype<T> self;
        typedef ::std::bidirectional_iterator_tag iterator_category;
        typedef T value_type;
        typedef T const& reference;
        typedef T* pointer;
        typedef ::std::ptrdiff_t difference_type;
        indexable_iterator_archetype();
        self& operator=(self const&);
        bool operator==(self const&) const;
        bool operator!=(self const&) const;
        reference operator*() const;
        self& operator++();
        self operator++(int);
        self& operator--();
        self operator--(int);
        self& operator+=(difference_type);
        self operator+(difference_type);
        self& operator-=(difference_type);
        self operator-(difference_type);
        difference_type operator-(self const&) const;
        reference operator[](difference_type) const;
        bool operator<(self const&) const;
        bool operator<=(self const&) const;
        bool operator>(self const&) const;
        bool operator>=(self const&) const;
    };
}}  // namespace boost::concept

template <typename T>
::boost::concept::indexable_iterator_archetype<T>
    operator+(
        typename ::boost::concept::indexable_iterator_archetype<T>
        ::difference_type
      , ::boost::concept::indexable_iterator_archetype<T> const&
    );
//]

#endif  // include guard

