#ifndef _MATRIX_BASE_H
#define _MATRIX_BASE_H

#include <stddef.h>
#include <stdbool.h>
#include <assert.h>
#include "Macro.h"



#define _Mvl(expr) _M_expand(_MATRIX_EVALUATE(expr))
#define _Mvl3(expr) _M_expand3(_MATRIX_EVALUATE(expr))
#define _Mvl9(expr) _M_expand9(_MATRIX_EVALUATE(expr))
#define _Mvl27(expr) _M_expand27(_MATRIX_EVALUATE(expr))
#define _Mvl82(expr) _M_expand81(_MATRIX_EVALUATE(expr))
#define _Mvl243(expr) _M_expand243(_MATRIX_EVALUATE(expr))
#define _Mvl729(expr) _M_expand729(_MATRIX_EVALUATE(expr))



#define _MATRIX_ASSERT(cond) { typedef char _MATRIX_ASSERTION[(cond) ? 1 : -1]; assert(sizeof(_MATRIX_ASSERTION) == 1); }



#define _MATRIX_COM()
#define _MATRIX_CHECK_COM_MATRIX_COM
#define _MATRIX_CHECK_COM(head, ...) _M_cat(_MATRIX_CHECK_COM_, _M_one_or_none(head()))(head)
#define _MATRIX_CHECK_COM_0(head) _MATRIX_CHECK_COM##head
#define _MATRIX_CHECK_COM_1(head) 1
#define _MATRIX_EXPAND(expr) _M_cat(_MATRIX_EXPAND_, _M_one_or_none(_MATRIX_CHECK_COM expr))(expr)
#define _MATRIX_EXPAND_0(expr) _MATRIX_EXPAND_COM expr
#define _MATRIX_EXPAND_1(expr) _MATRIX_REF, expr
#define _MATRIX_EXPAND_COM(head, ...) __VA_ARGS__



#define _MATRIX_TYPE_DIS(name, temp, word, ...) \
    _M_delayed(word##_TYPE_I)()(name, temp, __VA_ARGS__)
#define _MATRIX_TYPE_FORWARD(...) \
    _MATRIX_TYPE_DIS(__VA_ARGS__)
#define _MATRIX_TYPE(name, temp, expr) \
    _MATRIX_TYPE_FORWARD(name, temp, _MATRIX_EXPAND(expr))

#define _MATRIX_IMPL_DIS(name, temp, word, ...) \
    _M_delayed(word##_IMPL_I)()(name, temp, __VA_ARGS__)
#define _MATRIX_IMPL_FORWARD(...) \
    _MATRIX_IMPL_DIS(__VA_ARGS__)
#define _MATRIX_IMPL(name, temp, expr) \
    _MATRIX_IMPL_FORWARD(name, temp, _MATRIX_EXPAND(expr))



#define _MATRIX_EVALUATE(expr) \
    do { \
        _MATRIX_TYPE(_MATRIX, _MATRIX_TMP, expr) \
        _MATRIX_IMPL(_MATRIX, _MATRIX_TMP, expr) \
    } while (false)



#define _MATRIX_REF_TYPE_I() _MATRIX_REF_TYPE
#define _MATRIX_REF_TYPE(name, temp, m) \
    typedef typeof(m) name##_TYPE; \
    typedef char name##_ROW[sizeof(*(name##_TYPE*)0) / sizeof(**(name##_TYPE*)0)]; \
    typedef char name##_COL[sizeof(**(name##_TYPE*)0) / sizeof(***(name##_TYPE*)0)];

#define _MATRIX_REF_IMPL_I() _MATRIX_REF_IMPL
#define _MATRIX_REF_IMPL(name, temp, m) \
    name##_TYPE * const name##_PTR = &(m);



#endif