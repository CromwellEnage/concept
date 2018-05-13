// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#if !defined(BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_DEF)

#include <boost/move/utility_core.hpp>
#include <boost/type_traits/declval.hpp>
#include <boost/preprocessor/cat.hpp>

#define BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_FORWARD_ARGUMENT(z, n, p) \
    ::boost::forward<BOOST_PP_CAT(p, n)>( \
        ::boost::declval<BOOST_PP_CAT(p, n)>() \
    )
/**/

#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/seq/elem.hpp>

#define BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_CALL_Z(z, n, seq) \
    BOOST_PP_SEQ_ELEM(0, seq)( \
        BOOST_PP_CAT(BOOST_PP_ENUM_, z)( \
            n \
          , BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_FORWARD_ARGUMENT \
          , BOOST_PP_SEQ_ELEM(1, seq) \
        ) \
    )
/**/

#define BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_CALL(n, seq) \
    BOOST_PP_SEQ_ELEM(0, seq)( \
        BOOST_PP_ENUM( \
            n \
          , BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_FORWARD_ARGUMENT \
          , BOOST_PP_SEQ_ELEM(1, seq) \
        ) \
    )
/**/

#include <boost/preprocessor/punctuation/comma.hpp>
#include <boost/preprocessor/repetition/enum_trailing_params.hpp>

#define BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_TAIL_1_Z(z, n) \
    BOOST_PP_COMMA() F BOOST_PP_ENUM_TRAILING_PARAMS_Z(z, n, P)
#define BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_TAIL_0_Z(z, n)
#define BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_TAIL_1_N(n) \
    BOOST_PP_COMMA() F BOOST_PP_ENUM_TRAILING_PARAMS(n, P)
#define BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_TAIL_0_N(n)

#include <boost/concept/policy/use_default.hpp>
#include <boost/tti/detail/dnullptr.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/control/expr_iif.hpp>
#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/facilities/intercept.hpp>
#include <boost/preprocessor/repetition/enum_trailing_binary_params.hpp>

#define BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_DEF_Z(z, n, seq) \
    template < \
        typename F \
        BOOST_PP_ENUM_TRAILING_PARAMS_Z(z, BOOST_PP_INC(n), typename P) \
    > \
    class BOOST_PP_SEQ_ELEM(1, seq)< \
        F \
        BOOST_PP_ENUM_TRAILING_PARAMS_Z(z, BOOST_PP_INC(n), P) \
    > \
    { \
        template <typename B> \
        static ::boost::type_traits::yes_type \
            _check( \
                typename BOOST_PP_SEQ_ELEM(5, seq)< \
                    BOOST_PP_SEQ_ELEM(4, seq)(( \
                        BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_CALL_Z( \
                            z \
                          , BOOST_PP_INC(n) \
                          , (BOOST_PP_SEQ_ELEM(2, seq))(P) \
                        ) \
                    )) \
                >::type \
            ); \
        template <typename B> \
        static ::boost::type_traits::no_type _check(...); \
     public: \
        typedef BOOST_PP_SEQ_ELEM(3, seq)< \
            sizeof( \
                BOOST_PP_SEQ_ELEM(0, seq) BOOST_PP_SEQ_ELEM(1, seq)< \
                    F \
                    BOOST_PP_ENUM_TRAILING_PARAMS_Z(z, BOOST_PP_INC(n), P) \
                >::BOOST_NESTED_TEMPLATE _check<F>(BOOST_TTI_DETAIL_NULLPTR) \
            ) == sizeof(::boost::type_traits::yes_type) \
            BOOST_PP_IIF( \
                BOOST_PP_SEQ_ELEM(6, seq) \
              , BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_TAIL_1_Z \
              , BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_TAIL_0_Z \
            )(z, BOOST_PP_INC(n)) \
        > type; \
    };
/* BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_DEF_Z */

#define BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_DEF(n, seq) \
    template < \
        typename F \
        BOOST_PP_ENUM_TRAILING_BINARY_PARAMS( \
            n \
          , typename P \
          , = ::boost::concept::policy::use_default BOOST_PP_INTERCEPT \
        ) \
    > \
    class BOOST_PP_SEQ_ELEM(1, seq) \
    { \
        template <typename B> \
        static ::boost::type_traits::yes_type \
            _check( \
                typename BOOST_PP_SEQ_ELEM(5, seq)< \
                    BOOST_PP_SEQ_ELEM(4, seq)(( \
                        BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_CALL( \
                            n \
                          , (BOOST_PP_SEQ_ELEM(2, seq))(P) \
                        ) \
                    )) \
                >::type \
            ); \
        template <typename B> \
        static ::boost::type_traits::no_type _check(...); \
     public: \
        typedef BOOST_PP_SEQ_ELEM(3, seq)< \
            sizeof( \
                BOOST_PP_SEQ_ELEM(0, seq) BOOST_PP_SEQ_ELEM(1, seq)< \
                    F \
                    BOOST_PP_ENUM_TRAILING_PARAMS(n, P) \
                >::BOOST_NESTED_TEMPLATE _check<F>(BOOST_TTI_DETAIL_NULLPTR) \
            ) == sizeof(::boost::type_traits::yes_type) \
            BOOST_PP_IIF( \
                BOOST_PP_SEQ_ELEM(6, seq) \
              , BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_TAIL_1_N \
              , BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_TAIL_0_N \
            )(n) \
        > type; \
    }; \
    template <typename F> \
    class BOOST_PP_SEQ_ELEM(1, seq)< \
        F \
        BOOST_PP_ENUM_TRAILING_PARAMS( \
            n \
          , ::boost::concept::policy::use_default BOOST_PP_INTERCEPT \
        ) \
    > \
    { \
        template <typename B> \
        static ::boost::type_traits::yes_type \
            _check( \
                typename BOOST_PP_SEQ_ELEM(5, seq)< \
                    BOOST_PP_SEQ_ELEM(4, seq)((BOOST_PP_SEQ_ELEM(2, seq)())) \
                >::type \
            ); \
        template <typename B> \
        static ::boost::type_traits::no_type _check(...); \
     public: \
        typedef BOOST_PP_SEQ_ELEM(3, seq)< \
            sizeof( \
                BOOST_PP_SEQ_ELEM(0, seq) BOOST_PP_SEQ_ELEM(1, seq)< \
                    F \
                    BOOST_PP_ENUM_TRAILING_PARAMS( \
                        n \
                      , ::boost::concept::policy::use_default \
                        BOOST_PP_INTERCEPT \
                    ) \
                >::BOOST_NESTED_TEMPLATE _check<F>(BOOST_TTI_DETAIL_NULLPTR) \
            ) == sizeof(::boost::type_traits::yes_type) \
            BOOST_PP_IIF( \
                BOOST_PP_SEQ_ELEM(6, seq) \
              , BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_TAIL_1_N \
              , BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_TAIL_0_N \
            )(0) \
        > type; \
    };
/* BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_DEF */

#endif  // BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_DEF

