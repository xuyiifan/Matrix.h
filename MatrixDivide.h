#ifndef _MATRIX_DIVIDE_H
#define _MATRIX_DIVIDE_H

#include "MatrixDetailBase.h"
#include <float.h>
#include <tgmath.h>
#include <string.h>



#define _Mdv(...) \
    (_MATRIX_COM, _MATRIX_DIV, __VA_ARGS__)

#define _Mnv(...) \
    (_MATRIX_COM, _MATRIX_INV, __VA_ARGS__)

#define I$ \
    ,_MATRIX_Ix,

#define IT$ \
    ,_MATRIX_ITx,

#define $I \
    ,_MATRIX_xI,

#define $IT \
    ,_MATRIX_xIT,



#define _MATRIX_DIV_TYPE_PROPER(name, temp, x, xrow, y, yrow) \
    _MATRIX_TYPE(name, temp##_Y_TMP, y) \
    _MATRIX_TYPE(temp##_X, temp##_X_TMP, x) \
    _MATRIX_ASSERT(sizeof(temp##_X_ROW) == sizeof(temp##_X_COL) && sizeof(temp##_X##xrow) == sizeof(name##yrow))
#define _MATRIX_DIV_TYPE_PROPER_MATRIX_Ix(name, temp, x, y) \
    _MATRIX_DIV_TYPE_PROPER(name, temp, x, _ROW, y, _ROW)
#define _MATRIX_DIV_TYPE_PROPER_MATRIX_ITx(name, temp, x, y) \
    _MATRIX_DIV_TYPE_PROPER(name, temp, x, _COL, y, _ROW)
#define _MATRIX_DIV_TYPE_PROPER_MATRIX_xI(name, temp, x, y) \
    _MATRIX_DIV_TYPE_PROPER(name, temp, y, _COL, x, _COL)
#define _MATRIX_DIV_TYPE_PROPER_MATRIX_xIT(name, temp, x, y) \
    _MATRIX_DIV_TYPE_PROPER(name, temp, y, _ROW, x, _COL)
#define _MATRIX_DIV_TYPE_I() _MATRIX_DIV_TYPE
#define _MATRIX_DIV_TYPE(name, temp, x, cate, y) \
    _MATRIX_DIV_TYPE_PROPER##cate(name, temp, x, y)

#if __STDC_VERSION__ >= 201112L
#   define _MATRIX_EPSILON(n) _Generic(n, float : FLT_EPSILON, double : DBL_EPSILON, long double : LDBL_EPSILON, \
                                          float complex : FLT_EPSILON, double complex : DBL_EPSILON, long double complex : LDBL_EPSILON, default : 1)
#elif defined(_ARM_GENERIC1)
#   define _MATRIX_EPSILON(n) __generic(n, , , DBL_EPSILON, FLT_EPSILON, LDBL_EPSILON, DBL_EPSILON, FLT_EPSILON, LDBL_EPSILON)
#endif

#define _MATRIX_CHECK_ZERO(n) (fabs(n) < _MATRIX_EPSILON(n))

#define _MATRIX_SCALAR_SWAP(x, y) \
    typeof(x) * const _MATRIX_X = &(x); \
    typeof(y) * const _MATRIX_Y = &(y); \
    const typeof(*_MATRIX_X) _MATRIX_T = *_MATRIX_X; \
    *_MATRIX_X = *_MATRIX_Y; \
    *_MATRIX_Y = _MATRIX_T;

#define _MATRIX_DIV_IMPL_REDUCE(name, temp, xvis, yvis, row, col) \
    for (size_t _MATRIX_I = 0; _MATRIX_I != row; ++_MATRIX_I) \
    { \
        if (_MATRIX_CHECK_ZERO(xvis(*temp##_X_PTR, _MATRIX_I, _MATRIX_I))) \
        { \
            for (size_t _MATRIX_J = _MATRIX_I + 1; _MATRIX_J != row; ++_MATRIX_J) \
            { \
                if (_MATRIX_CHECK_ZERO(xvis(*temp##_X_PTR, _MATRIX_J, _MATRIX_I))) { continue; } \
                else \
                { \
                    for (size_t _MATRIX_K = _MATRIX_I; _MATRIX_K != row; ++_MATRIX_K) \
                    { \
                        _MATRIX_SCALAR_SWAP(xvis(*temp##_X_PTR, _MATRIX_I, _MATRIX_K), xvis(*temp##_X_PTR, _MATRIX_J, _MATRIX_K)) \
                    } \
                    for (size_t _MATRIX_K = 0; _MATRIX_K != col; ++_MATRIX_K) \
                    { \
                        _MATRIX_SCALAR_SWAP(yvis(*name##_PTR, _MATRIX_I, _MATRIX_K), yvis(*name##_PTR, _MATRIX_J, _MATRIX_K)) \
                    } \
                    break; \
                } \
            } \
        } \
        { \
            const typeof(***(temp##_X_TYPE*)0) _MATRIX_T = 1 / xvis(*temp##_X_PTR, _MATRIX_I, _MATRIX_I); \
            for (size_t _MATRIX_J = _MATRIX_I + 1; _MATRIX_J != row; ++_MATRIX_J) \
            { \
                xvis(*temp##_X_PTR, _MATRIX_I, _MATRIX_J) *= _MATRIX_T; \
            } \
            for (size_t _MATRIX_J = 0; _MATRIX_J != col; ++_MATRIX_J) \
            { \
                yvis(*name##_PTR, _MATRIX_I, _MATRIX_J) *= _MATRIX_T; \
            } \
        } \
        for (size_t _MATRIX_J = _MATRIX_I + 1; _MATRIX_J != row; ++_MATRIX_J) \
        { \
            const typeof(***(temp##_X_TYPE*)0) _MATRIX_T = xvis(*temp##_X_PTR, _MATRIX_J, _MATRIX_I); \
            for (size_t _MATRIX_K = _MATRIX_I + 1; _MATRIX_K != row; ++_MATRIX_K) \
            {\
                xvis(*temp##_X_PTR, _MATRIX_J, _MATRIX_K) -= _MATRIX_T * xvis(*temp##_X_PTR, _MATRIX_I, _MATRIX_K); \
            } \
            for (size_t _MATRIX_K = 0; _MATRIX_K != col; ++_MATRIX_K) \
            {\
                yvis(*name##_PTR, _MATRIX_J, _MATRIX_K) -= _MATRIX_T * yvis(*name##_PTR, _MATRIX_I, _MATRIX_K); \
            } \
        } \
    } \
    for (size_t _MATRIX_I = row; _MATRIX_I--; ) \
    { \
        for (size_t _MATRIX_J = 0; _MATRIX_J != _MATRIX_I; ++_MATRIX_J) \
        { \
            const typeof(***(temp##_X_TYPE*)0) _MATRIX_T = xvis(*temp##_X_PTR, _MATRIX_J, _MATRIX_I); \
            for (size_t _MATRIX_K = 0; _MATRIX_K != col; ++_MATRIX_K) \
            { \
                yvis(*name##_PTR, _MATRIX_J, _MATRIX_K) -= _MATRIX_T * yvis(*name##_PTR, _MATRIX_I, _MATRIX_K); \
            } \
        } \
    }
#define _MATRIX_DIV_IMPL_Y_PROPER_MATRIX_Ix(name, temp, x, y) \
    _MATRIX_IMPL(name, temp##_Y_TMP, y)
#define _MATRIX_DIV_IMPL_Y_PROPER_MATRIX_ITx(name, temp, x, y) \
    _MATRIX_IMPL(name, temp##_Y_TMP, y)
#define _MATRIX_DIV_IMPL_Y_PROPER_MATRIX_xI(name, temp, x, y) \
    _MATRIX_IMPL(name, temp##_Y_TMP, x)
#define _MATRIX_DIV_IMPL_Y_PROPER_MATRIX_xIT(name, temp, x, y) \
    _MATRIX_IMPL(name, temp##_Y_TMP, x)
#define _MATRIX_DIV_IMPL_X_PROPER_MATRIX_Ix(temp, x, y) \
    _MATRIX_IMPL(temp##_X, temp##_X_TMP, x)
#define _MATRIX_DIV_IMPL_X_PROPER_MATRIX_ITx(temp, x, y) \
    _MATRIX_IMPL(temp##_X, temp##_X_TMP, x)
#define _MATRIX_DIV_IMPL_X_PROPER_MATRIX_xI(temp, x, y) \
    _MATRIX_IMPL(temp##_X, temp##_X_TMP, y)
#define _MATRIX_DIV_IMPL_X_PROPER_MATRIX_xIT(temp, x, y) \
    _MATRIX_IMPL(temp##_X, temp##_X_TMP, y)
#define _MATRIX_VISIT(a, _MATRIX_I, _MATRIX_J) (a)[_MATRIX_I][_MATRIX_J]
#define _MATRIX_VISIT_T(a, _MATRIX_I, _MATRIX_J) (a)[_MATRIX_J][_MATRIX_I]
#define _MATRIX_DIV_IMPL_REDUCE_MATRIX_Ix(name, temp) \
    _MATRIX_DIV_IMPL_REDUCE(name, temp, _MATRIX_VISIT, _MATRIX_VISIT, sizeof(name##_ROW), sizeof(name##_COL))
#define _MATRIX_DIV_IMPL_REDUCE_MATRIX_ITx(name, temp) \
    _MATRIX_DIV_IMPL_REDUCE(name, temp, _MATRIX_VISIT_T, _MATRIX_VISIT, sizeof(name##_ROW), sizeof(name##_COL))
#define _MATRIX_DIV_IMPL_REDUCE_MATRIX_xI(name, temp) \
    _MATRIX_DIV_IMPL_REDUCE(name, temp, _MATRIX_VISIT_T, _MATRIX_VISIT_T, sizeof(name##_COL), sizeof(name##_ROW))
#define _MATRIX_DIV_IMPL_REDUCE_MATRIX_xIT(name, temp) \
    _MATRIX_DIV_IMPL_REDUCE(name, temp, _MATRIX_VISIT, _MATRIX_VISIT_T, sizeof(name##_COL), sizeof(name##_ROW))
#define _MATRIX_DIV_IMPL_I() _MATRIX_DIV_IMPL
#define _MATRIX_DIV_IMPL(name, temp, x, cate, y) \
    _MATRIX_DIV_IMPL_Y_PROPER##cate(name, temp, x, y) \
    { \
        _MATRIX_DIV_IMPL_X_PROPER##cate(temp, x, y) \
        _MATRIX_DIV_IMPL_REDUCE##cate(name, temp) \
    }



#define _MATRIX_INV_TYPE_I() _MATRIX_INV_TYPE
#define _MATRIX_INV_TYPE(name, temp, x) \
    _MATRIX_TYPE(temp##_X, temp##_X_TMP, x) \
    _MATRIX_ASSERT(sizeof(temp##_X_ROW) == sizeof(temp##_X_COL)) \
    typedef temp##_X_TYPE name##_TYPE; \
    typedef temp##_X_ROW name##_ROW; \
    typedef temp##_X_COL name##_COL;

#define _MATRIX_INV_IMPL_I() _MATRIX_INV_IMPL
#define _MATRIX_INV_IMPL(name, temp, x) \
    name##_TYPE name##_DATA = {}, * const name##_PTR = &name##_DATA; \
    for (size_t _MATRIX_I = 0; _MATRIX_I < sizeof(name##_ROW); ++_MATRIX_I) \
    { \
        name##_DATA[_MATRIX_I][_MATRIX_I] = 1; \
    } \
    { \
        _MATRIX_IMPL(temp##_X, temp##_X_TMP, x) \
        _MATRIX_DIV_IMPL_REDUCE_MATRIX_Ix(name, temp) \
    }



#endif