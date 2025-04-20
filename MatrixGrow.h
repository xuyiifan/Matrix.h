#ifndef _MATRIX_GROW_H
#define _MATRIX_GROW_H

#include "MatrixDetailBase.h"



#define _Mgr(...) \
    (_MATRIX_COM, _MATRIX_GRO, __VA_ARGS__)



#define _MATRIX_GRO_TYPE_I() _MATRIX_GRO_TYPE
#define _MATRIX_GRO_TYPE(name, temp, x, a) \
    _MATRIX_TYPE(name, temp, x) \
    _MATRIX_ASSERT(sizeof(name##_ROW) == sizeof(name##_COL))

#define _MATRIX_GRO_IMPL_I() _MATRIX_GRO_IMPL
#define _MATRIX_GRO_IMPL(name, temp, x, a) \
    _MATRIX_IMPL(name, temp, x) \
    for (size_t _MATRIX_I = 0; _MATRIX_I != sizeof(name##_ROW); ++_MATRIX_I) \
    { \
        (*name##_PTR)[_MATRIX_I][_MATRIX_I] += a; \
    }



#endif