#ifndef _MATRIX_PARTITION_H
#define _MATRIX_PARTITION_H

#include "MatrixDetailBase.h"



#define _Mpt(...) \
    (_MATRIX_COM, _MATRIX_PAR, __VA_ARGS__)



#define _MATRIX_PAR_TYPE_I() _MATRIX_PAR_TYPE
#define _MATRIX_PAR_TYPE(name, temp, x, a, b, n, m) \
    _MATRIX_TYPE(temp##_FROM, temp##_FROM_TMP, x) \
    typedef char name##_ROW_OFFSET[a]; \
    typedef char name##_COL_OFFSET[b]; \
    typedef char name##_ROW[n]; \
    typedef char name##_COL[m]; \
    typedef temp##_FROM_TYPE name##_TYPE; \
    _MATRIX_ASSERT(sizeof(name##_ROW) <= sizeof(temp##_FROM_ROW)  \
                && sizeof(name##_ROW_OFFSET) <= sizeof(temp##_FROM_ROW) - sizeof(name##_ROW) \
                && sizeof(name##_COL) <= sizeof(temp##_FROM_COL) \
                && sizeof(name##_COL_OFFSET) <= sizeof(temp##_FROM_COL) - sizeof(name##_COL))

#define _MATRIX_PAR_IMPL_I() _MATRIX_PAR_IMPL
#define _MATRIX_PAR_IMPL(name, temp, x, a, b, n, m) \
    _MATRIX_IMPL(temp##_FROM, temp##_FROM_TMP, x) \
    name##_TYPE * const name##_PTR = (name##_TYPE*)&(*temp##_FROM_PTR)[sizeof(name##_ROW_OFFSET)][sizeof(name##_COL_OFFSET)];

#endif