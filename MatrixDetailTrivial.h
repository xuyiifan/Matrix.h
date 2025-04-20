#ifndef _MATRIX_XT_H
#define _MATRIX_XT_H

#include "MatrixDetailBase.h"



#define $T$ \
    ,_MATRIX_T

#define $ \
    ,_MATRIX_x,

#define $T \
    ,_MATRIX_xT,

#define T$ \
    ,_MATRIX_Tx,

#define T$T \
    ,_MATRIX_TxT,



#define _MATRIX_T()
#define _MATRIX_CHECK_NOT_T_MATRIX_T
#define _MATRIX_CHECK_NOT_T_0(token) _M_one_or_none(_MATRIX_CHECK_NOT_T##token)
#define _MATRIX_CHECK_NOT_T_1(token) 1
#define _MATRIX_CHECK_NOT_T(token) _M_cat(_MATRIX_CHECK_NOT_T_, _M_one_or_none(token()))(token)
#define _MATRIX_x()
#define _MATRIX_xT()
#define _MATRIX_Tx()
#define _MATRIX_TxT()
#define _MATRIX_CHECK_NOT_x_MATRIX_x
#define _MATRIX_CHECK_NOT_x_MATRIX_xT
#define _MATRIX_CHECK_NOT_x_MATRIX_Tx
#define _MATRIX_CHECK_NOT_x_MATRIX_TxT
#define _MATRIX_CHECK_NOT_x_0(token) _M_one_or_none(_MATRIX_CHECK_NOT_x##token)
#define _MATRIX_CHECK_NOT_x_1(token) 1
#define _MATRIX_CHECK_NOT_x(token) _M_cat(_MATRIX_CHECK_NOT_x_, _M_one_or_none(token()))(token)



#define _MATRIX_DOT_COL_MATRIX_x(temp) sizeof(temp##_X_COL)
#define _MATRIX_DOT_COL_MATRIX_xT(temp) sizeof(temp##_X_COL)
#define _MATRIX_DOT_COL_MATRIX_Tx(temp) sizeof(temp##_X_ROW)
#define _MATRIX_DOT_COL_MATRIX_TxT(temp) sizeof(temp##_X_ROW)
#define _MATRIX_DOT_MAKE_MATRIX_x(temp) (*temp##_X_PTR)[_MATRIX_I][_MATRIX_K] * (*temp##_Y_PTR)[_MATRIX_K][_MATRIX_J]
#define _MATRIX_DOT_MAKE_MATRIX_xT(temp) (*temp##_X_PTR)[_MATRIX_I][_MATRIX_K] * (*temp##_Y_PTR)[_MATRIX_J][_MATRIX_K]
#define _MATRIX_DOT_MAKE_MATRIX_Tx(temp) (*temp##_X_PTR)[_MATRIX_K][_MATRIX_I] * (*temp##_Y_PTR)[_MATRIX_K][_MATRIX_J]
#define _MATRIX_DOT_MAKE_MATRIX_TxT(temp) (*temp##_X_PTR)[_MATRIX_K][_MATRIX_I] * (*temp##_Y_PTR)[_MATRIX_J][_MATRIX_K]
#define _MATRIX_DOT_MAKE(temp, x, cate, y) \
    typeof((***(temp##_X_TYPE*)0) * (***(temp##_Y_TYPE*)0)) temp##_DOT = 0; \
    for (size_t _MATRIX_K = 0; _MATRIX_K != _MATRIX_DOT_COL##cate(temp); ++_MATRIX_K) \
    { \
        temp##_DOT += _MATRIX_DOT_MAKE##cate(temp); \
    }



#define _MATRIX_ASSERT_MAKE_MATRIX_x(name, temp) \
    _MATRIX_ASSERT(sizeof(name##_ROW) == sizeof(temp##_X_ROW) && sizeof(temp##_X_COL) == sizeof(temp##_Y_ROW) && sizeof(name##_COL) == sizeof(temp##_Y_COL))
#define _MATRIX_ASSERT_MAKE_MATRIX_xT(name, temp) \
    _MATRIX_ASSERT(sizeof(name##_ROW) == sizeof(temp##_X_ROW) && sizeof(temp##_X_COL) == sizeof(temp##_Y_COL) && sizeof(name##_COL) == sizeof(temp##_Y_ROW))
#define _MATRIX_ASSERT_MAKE_MATRIX_Tx(name, temp) \
    _MATRIX_ASSERT(sizeof(name##_ROW) == sizeof(temp##_X_COL) && sizeof(temp##_X_ROW) == sizeof(temp##_Y_ROW) && sizeof(name##_COL) == sizeof(temp##_Y_COL))
#define _MATRIX_ASSERT_MAKE_MATRIX_TxT(name, temp) \
    _MATRIX_ASSERT(sizeof(name##_ROW) == sizeof(temp##_X_COL) && sizeof(temp##_X_ROW) == sizeof(temp##_Y_COL) && sizeof(name##_COL) == sizeof(temp##_Y_ROW))


#define _MATRIX_XT_TYPE_RES_MATRIX_x(name, temp, f, then, ...) \
    _MATRIX_ASSERT(sizeof(temp##_X_COL) == sizeof(temp##_Y_ROW)) \
    then(name, temp, f, sizeof(temp##_X_ROW), sizeof(temp##_Y_COL), ((***(temp##_X_TYPE*)0) * (***(temp##_Y_TYPE*)0)), __VA_ARGS__)
#define _MATRIX_XT_TYPE_RES_MATRIX_xT(name, temp, f, then, ...) \
    _MATRIX_ASSERT(sizeof(temp##_X_COL) == sizeof(temp##_Y_COL)) \
    then(name, temp, f, sizeof(temp##_X_ROW), sizeof(temp##_Y_ROW), ((***(temp##_X_TYPE*)0) * (***(temp##_Y_TYPE*)0)), __VA_ARGS__)
#define _MATRIX_XT_TYPE_RES_MATRIX_Tx(name, temp, f, then, ...) \
    _MATRIX_ASSERT(sizeof(temp##_X_ROW) == sizeof(temp##_Y_ROW)) \
    then(name, temp, f, sizeof(temp##_X_COL), sizeof(temp##_Y_COL), ((***(temp##_X_TYPE*)0) * (***(temp##_Y_TYPE*)0)), __VA_ARGS__)
#define _MATRIX_XT_TYPE_RES_MATRIX_TxT(name, temp, f, then, ...) \
    _MATRIX_ASSERT(sizeof(temp##_X_ROW) == sizeof(temp##_Y_COL)) \
    then(name, temp, f, sizeof(temp##_X_COL), sizeof(temp##_Y_ROW), ((***(temp##_X_TYPE*)0) * (***(temp##_Y_TYPE*)0)), __VA_ARGS__)

#endif