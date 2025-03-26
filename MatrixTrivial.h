#ifndef _MATRIX_TRIVIAL_H
#define _MATRIX_TRIVIAL_H

#include "MatrixXT.h"



#define _Mst(...) \
    (_MATRIX_COM, _MATRIX_SET, __VA_ARGS__,)

#define _Mgt(...) \
    (_MATRIX_COM, _MATRIX_GET, __VA_ARGS__,)



#define _MATRIX_SET_TYPE_LIST_I() _MATRIX_SET_TYPE_LIST
#define _MATRIX_SET_TYPE_LIST(name, temp, op, ...) \
    _M_cat(_MATRIX_SET_TYPE_LIST_, _M_one_or_none(op))(name, temp, op, __VA_ARGS__)
#define _MATRIX_SET_TYPE_LIST_0(...)
#define _MATRIX_SET_TYPE_LIST_1(name, temp, op, x, cate, ...) \
    _M_cat(_MATRIX_SET_TYPE_LIST_NOT_T_, _MATRIX_CHECK_NOT_T(cate))(name, temp, op, x, cate, __VA_ARGS__)
#define _MATRIX_SET_TYPE_LIST_NOT_T_0(name, temp, op, x, T, ...) \
    _MATRIX_TYPE(temp, temp##_TMP, x) \
    _MATRIX_ASSERT(sizeof(name##_ROW) == sizeof(temp##_COL) && sizeof(name##_COL) == sizeof(temp##_ROW)) \
    _M_delayed(_MATRIX_SET_TYPE_LIST_I)()(name, temp##I, __VA_ARGS__)
#define _MATRIX_SET_TYPE_LIST_NOT_T_1(name, temp, op, x, cate, ...) \
    _M_cat(_MATRIX_SET_TYPE_LIST_NOT_x_, _MATRIX_CHECK_NOT_x(cate))(name, temp, op, x, cate, __VA_ARGS__)
#define _MATRIX_SET_TYPE_LIST_ASSERT_MATRIX_x(name, temp) \
    _MATRIX_ASSERT(sizeof(name##_ROW) == sizeof(temp##_X_ROW) && sizeof(temp##_X_COL) == sizeof(temp##_Y_ROW) && sizeof(name##_COL) == sizeof(temp##_Y_COL))
#define _MATRIX_SET_TYPE_LIST_ASSERT_MATRIX_xT(name, temp) \
    _MATRIX_ASSERT(sizeof(name##_ROW) == sizeof(temp##_X_ROW) && sizeof(temp##_X_COL) == sizeof(temp##_Y_COL) && sizeof(name##_COL) == sizeof(temp##_Y_ROW))
#define _MATRIX_SET_TYPE_LIST_ASSERT_MATRIX_Tx(name, temp) \
    _MATRIX_ASSERT(sizeof(name##_ROW) == sizeof(temp##_X_COL) && sizeof(temp##_X_ROW) == sizeof(temp##_Y_ROW) && sizeof(name##_COL) == sizeof(temp##_Y_COL))
#define _MATRIX_SET_TYPE_LIST_ASSERT_MATRIX_TxT(name, temp) \
    _MATRIX_ASSERT(sizeof(name##_ROW) == sizeof(temp##_X_COL) && sizeof(temp##_X_ROW) == sizeof(temp##_Y_COL) && sizeof(name##_COL) == sizeof(temp##_Y_ROW))
#define _MATRIX_SET_TYPE_LIST_NOT_x_0(name, temp, op, x, cate, y, ...) \
    _MATRIX_TYPE(temp##_X, temp##_X_TMP, x) \
    _MATRIX_TYPE(temp##_Y, temp##_Y_TMP, y) \
    _MATRIX_SET_TYPE_LIST_ASSERT##cate(name, temp) \
    _M_delayed(_MATRIX_SET_TYPE_LIST_I)()(name, temp##I, __VA_ARGS__)
#define _MATRIX_SET_TYPE_LIST_NOT_x_1(name, temp, op, x, ...)\
    _MATRIX_TYPE(temp, temp##_TMP, x) \
    _MATRIX_ASSERT(sizeof(name##_ROW) == sizeof(temp##_ROW) && sizeof(name##_COL) == sizeof(temp##_COL)) \
    _M_delayed(_MATRIX_SET_TYPE_LIST_I)()(name, temp##I, __VA_ARGS__)

#define _MATRIX_SET_TYPE_I() _MATRIX_SET_TYPE
#define _MATRIX_SET_TYPE(name, temp, x, ...) \
    _MATRIX_TYPE(name, temp##_RES, x) \
    _M_delayed(_MATRIX_SET_TYPE_LIST_I)()(name, temp##_I, __VA_ARGS__)

#define _MATRIX_SET_IMPL_LIST_I() _MATRIX_SET_IMPL_LIST
#define _MATRIX_SET_IMPL_LIST(temp, op, ...) \
    _M_cat(_MATRIX_SET_IMPL_LIST_, _M_one_or_none(op))(temp, op, __VA_ARGS__)
#define _MATRIX_SET_IMPL_LIST_0(...)
#define _MATRIX_SET_IMPL_LIST_1(temp, op, x, cate, ...) \
    _M_cat(_MATRIX_SET_IMPL_LIST_NOT_T_, _MATRIX_CHECK_NOT_T(cate))(temp, op, x, cate, __VA_ARGS__)
#define _MATRIX_SET_IMPL_LIST_NOT_T_0(temp, op, x, T, ...) \
    _MATRIX_IMPL(temp, temp##_TMP, x) \
    _M_delayed(_MATRIX_SET_IMPL_LIST_I)()(temp##I, __VA_ARGS__)
#define _MATRIX_SET_IMPL_LIST_NOT_T_1(temp, op, x, cate, ...) \
    _M_cat(_MATRIX_SET_IMPL_LIST_NOT_x_, _MATRIX_CHECK_NOT_x(cate))(temp, op, x, cate, __VA_ARGS__)
#define _MATRIX_SET_IMPL_LIST_NOT_x_0(temp, op, x, cate, y, ...) \
    _MATRIX_IMPL(temp##_X, temp##_X_TMP, x) \
    _MATRIX_IMPL(temp##_Y, temp##_Y_TMP, y) \
    _M_delayed(_MATRIX_SET_IMPL_LIST_I)()(temp##I, __VA_ARGS__)
#define _MATRIX_SET_IMPL_LIST_NOT_x_1(temp, op, x, ...) \
    _MATRIX_IMPL(temp, temp##_TMP, x) \
    _M_delayed(_MATRIX_SET_IMPL_LIST_I)()(temp##I, __VA_ARGS__)

#define _MATRIX_SET_IMPL_DOT_I() _MATRIX_SET_IMPL_DOT
#define _MATRIX_SET_IMPL_DOT(temp, op, ...) \
    _M_cat(_MATRIX_SET_IMPL_DOT_, _M_one_or_none(op))(temp, op, __VA_ARGS__)
#define _MATRIX_SET_IMPL_DOT_0(...)
#define _MATRIX_SET_IMPL_DOT_1(temp, op, x, cate, ...) \
    _M_cat(_MATRIX_SET_IMPL_DOT_NOT_T_, _MATRIX_CHECK_NOT_T(cate))(temp, op, x, cate, __VA_ARGS__)
#define _MATRIX_SET_IMPL_DOT_NOT_T_0(temp, op, x, T, ...) \
    _M_delayed(_MATRIX_SET_IMPL_DOT_I)()(temp##I, __VA_ARGS__)
#define _MATRIX_SET_IMPL_DOT_NOT_T_1(temp, op, x, cate, ...) \
    _M_cat(_MATRIX_SET_IMPL_DOT_NOT_x_, _MATRIX_CHECK_NOT_x(cate))(temp, op, x, cate, __VA_ARGS__)
#define _MATRIX_SET_IMPL_DOT_NOT_x_0(temp, op, x, cate, y, ...) \
    _MATRIX_DOT_MAKE(temp, x, cate, y) \
    _M_delayed(_MATRIX_SET_IMPL_DOT_I)()(temp##I, __VA_ARGS__)
#define _MATRIX_SET_IMPL_DOT_NOT_x_1(temp, op, x, ...) \
    _M_delayed(_MATRIX_SET_IMPL_DOT_I)()(temp##I, __VA_ARGS__)

#define _MATRIX_SET_IMPL_EXPR_I() _MATRIX_SET_IMPL_EXPR
#define _MATRIX_SET_IMPL_EXPR(temp, op, ...) \
    _M_cat(_MATRIX_SET_IMPL_EXPR_, _M_one_or_none(op))(temp, op, __VA_ARGS__)
#define _MATRIX_SET_IMPL_EXPR_0(...)
#define _MATRIX_SET_IMPL_EXPR_1(temp, op, x, cate, ...) \
    _M_cat(_MATRIX_SET_IMPL_EXPR_NOT_T_, _MATRIX_CHECK_NOT_T(cate))(temp, op, x, cate, __VA_ARGS__)
#define _MATRIX_SET_IMPL_EXPR_NOT_T_0(temp, op, x, T, ...) \
    op (*temp##_PTR)[_MATRIX_J][_MATRIX_I] _M_delayed(_MATRIX_SET_IMPL_EXPR_I)()(temp##I, __VA_ARGS__)
#define _MATRIX_SET_IMPL_EXPR_NOT_T_1(temp, op, x, cate, ...) \
    _M_cat(_MATRIX_SET_IMPL_EXPR_NOT_x_, _MATRIX_CHECK_NOT_x(cate))(temp, op, x, cate, __VA_ARGS__)
#define _MATRIX_SET_IMPL_EXPR_NOT_x_0(temp, op, x, cate, y, ...) \
    op temp##_DOT _M_delayed(_MATRIX_SET_IMPL_EXPR_I)()(temp##I, __VA_ARGS__)
#define _MATRIX_SET_IMPL_EXPR_NOT_x_1(temp, op, x, ...) \
    op (*temp##_PTR)[_MATRIX_I][_MATRIX_J] _M_delayed(_MATRIX_SET_IMPL_EXPR_I)()(temp##I, __VA_ARGS__)

#define _MATRIX_SET_IMPL_ACCUMULATE(name, temp, ...) \
    { \
        _M_delayed(_MATRIX_SET_IMPL_LIST_I)()(temp##_I, __VA_ARGS__) \
        for (size_t _MATRIX_I = 0; _MATRIX_I != sizeof(name##_ROW); ++_MATRIX_I) \
        { \
            for (size_t _MATRIX_J = 0; _MATRIX_J != sizeof(name##_COL); ++_MATRIX_J) \
            { \
                _M_delayed(_MATRIX_SET_IMPL_DOT_I)()(temp##_I, __VA_ARGS__) \
                (*name##_PTR)[_MATRIX_I][_MATRIX_J] _M_delayed(_MATRIX_SET_IMPL_EXPR_I)()(temp##_I, __VA_ARGS__); \
            } \
        } \
    }
#define _MATRIX_SET_IMPL_I() _MATRIX_SET_IMPL
#define _MATRIX_SET_IMPL(name, temp, x, ...) \
    _MATRIX_IMPL(name, temp##_RES, x) \
    _MATRIX_SET_IMPL_ACCUMULATE(name, temp, __VA_ARGS__)



#define _MATRIX_GET_TYPE_LIST_I() _MATRIX_GET_TYPE_LIST
#define _MATRIX_GET_TYPE_LIST(temp, op, ...) \
    _M_cat(_MATRIX_GET_TYPE_LIST_, _M_one_or_none(op))(temp, op, __VA_ARGS__)
#define _MATRIX_GET_TYPE_LIST_0(...)
#define _MATRIX_GET_TYPE_LIST_1(temp, op, x, cate, ...) \
    _M_cat(_MATRIX_GET_TYPE_LIST_NOT_T_, _MATRIX_CHECK_NOT_T(cate))(temp, op, x, cate, __VA_ARGS__)
#define _MATRIX_GET_TYPE_LIST_NOT_T_0(temp, op, x, T, ...) \
    _MATRIX_TYPE(temp, temp##_TMP, x) \
    _M_delayed(_MATRIX_GET_TYPE_LIST_I)()(temp##I, __VA_ARGS__)
#define _MATRIX_GET_TYPE_LIST_NOT_T_1(temp, op, x, cate, ...) \
    _M_cat(_MATRIX_GET_TYPE_LIST_NOT_x_, _MATRIX_CHECK_NOT_x(cate))(temp, op, x, cate, __VA_ARGS__)
#define _MATRIX_GET_TYPE_LIST_NOT_x_0(temp, op, x, cate, y, ...) \
    _MATRIX_TYPE(temp##_X, temp##_X_TMP, x) \
    _MATRIX_TYPE(temp##_Y, temp##_Y_TMP, y) \
    _M_delayed(_MATRIX_GET_TYPE_LIST_I)()(temp##I, __VA_ARGS__)
#define _MATRIX_GET_TYPE_LIST_NOT_x_1(temp, op, x, ...)\
    _MATRIX_TYPE(temp, temp##_TMP, x) \
    _M_delayed(_MATRIX_GET_TYPE_LIST_I)()(temp##I, __VA_ARGS__)

#define _MATRIX_GET_TYPE_EXPR_I() _MATRIX_GET_TYPE_EXPR
#define _MATRIX_GET_TYPE_EXPR(temp, op, ...) \
    _M_cat(_MATRIX_GET_TYPE_EXPR_, _M_one_or_none(op))(temp, op, __VA_ARGS__)
#define _MATRIX_GET_TYPE_EXPR_0(...)
#define _MATRIX_GET_TYPE_EXPR_1(temp, op, x, cate, ...) \
    _M_cat(_MATRIX_GET_TYPE_EXPR_NOT_T_, _MATRIX_CHECK_NOT_T(cate))(temp, op, x, cate, __VA_ARGS__)
#define _MATRIX_GET_TYPE_EXPR_NOT_T_0(temp, op, x, T, ...) \
    op (***(temp##_TYPE*)0) _M_delayed(_MATRIX_GET_TYPE_EXPR_I)()(temp##I, __VA_ARGS__)
#define _MATRIX_GET_TYPE_EXPR_NOT_T_1(temp, op, x, cate, ...) \
    _M_cat(_MATRIX_GET_TYPE_EXPR_NOT_x_, _MATRIX_CHECK_NOT_x(cate))(temp, op, x, cate, __VA_ARGS__)
#define _MATRIX_GET_TYPE_EXPR_NOT_x_0(temp, op, x, cate, y, ...) \
    op ((***(temp##_X_TYPE*)0) * (***(temp##_Y_TYPE*)0)) _M_delayed(_MATRIX_GET_TYPE_EXPR_I)()(temp##I, __VA_ARGS__)
#define _MATRIX_GET_TYPE_EXPR_NOT_x_1(temp, op, x, ...) \
    op (***(temp##_TYPE*)0) _M_delayed(_MATRIX_GET_TYPE_EXPR_I)()(temp##I, __VA_ARGS__)

#define _MATRIX_GET_TYPE_ASSERT_I() _MATRIX_GET_TYPE_ASSERT
#define _MATRIX_GET_TYPE_ASSERT(name, temp, op, ...) \
    _M_cat(_MATRIX_GET_TYPE_ASSERT_, _M_one_or_none(op))(name, temp, op, __VA_ARGS__)
#define _MATRIX_GET_TYPE_ASSERT_0(...)
#define _MATRIX_GET_TYPE_ASSERT_1(name, temp, op, x, cate, ...) \
    _M_cat(_MATRIX_GET_TYPE_ASSERT_NOT_T_, _MATRIX_CHECK_NOT_T(cate))(name, temp, op, x, cate, __VA_ARGS__)
#define _MATRIX_GET_TYPE_ASSERT_NOT_T_0(name, temp, op, x, T, ...) \
    _MATRIX_ASSERT(sizeof(name##_ROW) == sizeof(temp##_COL) && sizeof(name##_COL) == sizeof(temp##_ROW)) \
    _M_delayed(_MATRIX_GET_TYPE_ASSERT_I)()(name, temp##I, __VA_ARGS__)
#define _MATRIX_GET_TYPE_ASSERT_NOT_T_1(name, temp, op, x, cate, ...) \
    _M_cat(_MATRIX_GET_TYPE_ASSERT_NOT_x_, _MATRIX_CHECK_NOT_x(cate))(name, temp, op, x, cate, __VA_ARGS__)
#define _MATRIX_GET_TYPE_ASSERT_NOT_x_0(name, temp, op, x, cate, y, ...) \
    _MATRIX_ASSERT_MAKE##cate(name, temp) \
    _M_delayed(_MATRIX_GET_TYPE_ASSERT_I)()(name, temp##I, __VA_ARGS__)
#define _MATRIX_GET_TYPE_ASSERT_NOT_x_1(name, temp, op, x, ...) \
    _MATRIX_ASSERT(sizeof(name##_ROW) == sizeof(temp##_ROW) && sizeof(name##_COL) == sizeof(temp##_COL)) \
    _M_delayed(_MATRIX_GET_TYPE_ASSERT_I)()(name, temp##I, __VA_ARGS__)

#define _MATRIX_GET_TYPE_RES_FINAL(name, temp, _, row, col, xnum, ...) \
    typedef char name##_ROW[row]; \
    typedef char name##_COL[col]; \
    typedef typeof(xnum _M_delayed(_MATRIX_GET_TYPE_EXPR_I)()(temp##I, __VA_ARGS__)) name##_TYPE[sizeof(name##_ROW)][sizeof(name##_COL)]; \
    _M_delayed(_MATRIX_GET_TYPE_ASSERT_I)()(name, temp##I, __VA_ARGS__)
#define _MATRIX_GET_TYPE_RES(name, temp, x, cate, ...) \
    _M_cat(_MATRIX_GET_TYPE_RES_NOT_T_, _MATRIX_CHECK_NOT_T(cate))(name, temp, x, cate, __VA_ARGS__)
#define _MATRIX_GET_TYPE_RES_NOT_T_0(name, temp, x, T, ...) \
    _MATRIX_GET_TYPE_RES_FINAL(name, temp, 0, sizeof(temp##_COL), sizeof(temp##_ROW), (***(temp##_TYPE*)0), __VA_ARGS__)
#define _MATRIX_GET_TYPE_RES_NOT_T_1(name, temp, x, cate, ...) \
    _M_cat(_MATRIX_GET_TYPE_RES_NOT_x_, _MATRIX_CHECK_NOT_x(cate))(name, temp, x, cate, __VA_ARGS__)
#define _MATRIX_GET_TYPE_RES_NOT_x_0(name, temp, x, cate, y, ...) \
    _MATRIX_XT_TYPE_RES##cate(name, temp, 0, _MATRIX_GET_TYPE_RES_FINAL, __VA_ARGS__)
#define _MATRIX_GET_TYPE_RES_NOT_x_1(name, temp, x, ...) \
    _MATRIX_GET_TYPE_RES_FINAL(name, temp, 0, sizeof(temp##_ROW), sizeof(temp##_COL), (***(temp##_TYPE*)0), __VA_ARGS__)

#define _MATRIX_GET_TYPE_I() _MATRIX_GET_TYPE
#define _MATRIX_GET_TYPE(name, temp, ...) \
    _M_delayed(_MATRIX_GET_TYPE_LIST_I)()(temp##_I, =, __VA_ARGS__) \
    _MATRIX_GET_TYPE_RES(name, temp##_I, __VA_ARGS__)

#define _MATRIX_GET_IMPL_I() _MATRIX_GET_IMPL
#define _MATRIX_GET_IMPL(name, temp, ...) \
    name##_TYPE name##_DATA, * const name##_PTR = &name##_DATA; \
    _MATRIX_SET_IMPL_ACCUMULATE(name, temp, =, __VA_ARGS__)



#endif