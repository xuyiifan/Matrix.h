#ifndef _MATRIX_TRIVIAL_CALL_H
#define _MATRIX_TRIVIAL_CALL_H

#include "MatrixDetailTrivial.h"



#define _Mcl(...) \
    (_MATRIX_COM, _MATRIX_CAL, __VA_ARGS__,)

#define _Mrt(...) \
    (_MATRIX_COM, _MATRIX_RET, __VA_ARGS__,)



#define _MATRIX_CAL_TYPE_LIST_I() _MATRIX_CAL_TYPE_LIST
#define _MATRIX_CAL_TYPE_LIST(name, temp, x, ...) \
    _M_cat(_MATRIX_CAL_TYPE_LIST_, _M_one_or_none(x))(name, temp, x, __VA_ARGS__)
#define _MATRIX_CAL_TYPE_LIST_0(...)
#define _MATRIX_CAL_TYPE_LIST_1(name, temp, x, cate, ...) \
    _M_cat(_MATRIX_CAL_TYPE_LIST_NOT_T_, _MATRIX_CHECK_NOT_T(cate))(name, temp, x, cate, __VA_ARGS__)
#define _MATRIX_CAL_TYPE_LIST_NOT_T_0(name, temp, x, T, ...) \
    _MATRIX_TYPE(temp, temp##_TMP, x) \
    _MATRIX_ASSERT(sizeof(name##_ROW) == sizeof(temp##_COL) && sizeof(name##_COL) == sizeof(temp##_ROW)) \
    _M_delayed(_MATRIX_CAL_TYPE_LIST_I)()(name, temp##I, __VA_ARGS__)
#define _MATRIX_CAL_TYPE_LIST_NOT_T_1(name, temp, x, cate, ...) \
    _M_cat(_MATRIX_CAL_TYPE_LIST_NOT_x_, _MATRIX_CHECK_NOT_x(cate))(name, temp, x, cate, __VA_ARGS__)
#define _MATRIX_CAL_TYPE_LIST_ASSERT_MATRIX_x(name, temp) \
    _MATRIX_ASSERT(sizeof(name##_ROW) == sizeof(temp##_X_ROW) && sizeof(temp##_X_COL) == sizeof(temp##_Y_ROW) && sizeof(name##_COL) == sizeof(temp##_Y_COL))
#define _MATRIX_CAL_TYPE_LIST_ASSERT_MATRIX_xT(name, temp) \
    _MATRIX_ASSERT(sizeof(name##_ROW) == sizeof(temp##_X_ROW) && sizeof(temp##_X_COL) == sizeof(temp##_Y_COL) && sizeof(name##_COL) == sizeof(temp##_Y_ROW))
#define _MATRIX_CAL_TYPE_LIST_ASSERT_MATRIX_Tx(name, temp) \
    _MATRIX_ASSERT(sizeof(name##_ROW) == sizeof(temp##_X_COL) && sizeof(temp##_X_ROW) == sizeof(temp##_Y_ROW) && sizeof(name##_COL) == sizeof(temp##_Y_COL))
#define _MATRIX_CAL_TYPE_LIST_ASSERT_MATRIX_TxT(name, temp) \
    _MATRIX_ASSERT(sizeof(name##_ROW) == sizeof(temp##_X_COL) && sizeof(temp##_X_ROW) == sizeof(temp##_Y_COL) && sizeof(name##_COL) == sizeof(temp##_Y_ROW))
#define _MATRIX_CAL_TYPE_LIST_NOT_x_0(name, temp, x, cate, y, ...) \
    _MATRIX_TYPE(temp##_X, temp##_X_TMP, x) \
    _MATRIX_TYPE(temp##_Y, temp##_Y_TMP, y) \
    _MATRIX_CAL_TYPE_LIST_ASSERT##cate(name, temp) \
    _M_delayed(_MATRIX_CAL_TYPE_LIST_I)()(name, temp##I, __VA_ARGS__)
#define _MATRIX_CAL_TYPE_LIST_NOT_x_1(name, temp, x, ...)\
    _MATRIX_TYPE(temp, temp##_TMP, x) \
    _MATRIX_ASSERT(sizeof(name##_ROW) == sizeof(temp##_ROW) && sizeof(name##_COL) == sizeof(temp##_COL)) \
    _M_delayed(_MATRIX_CAL_TYPE_LIST_I)()(name, temp##I, __VA_ARGS__)

#define _MATRIX_CAL_TYPE_I() _MATRIX_CAL_TYPE
#define _MATRIX_CAL_TYPE(name, temp, f, x, ...) \
    _MATRIX_TYPE(name, temp##_RES, x) \
    _M_delayed(_MATRIX_CAL_TYPE_LIST_I)()(name, temp##_I, __VA_ARGS__)

#define _MATRIX_CAL_IMPL_LIST_I() _MATRIX_CAL_IMPL_LIST
#define _MATRIX_CAL_IMPL_LIST(temp, x, ...) \
    _M_cat(_MATRIX_CAL_IMPL_LIST_, _M_one_or_none(x))(temp, x, __VA_ARGS__)
#define _MATRIX_CAL_IMPL_LIST_0(...)
#define _MATRIX_CAL_IMPL_LIST_1(temp, x, cate, ...) \
    _M_cat(_MATRIX_CAL_IMPL_LIST_NOT_T_, _MATRIX_CHECK_NOT_T(cate))(temp, x, cate, __VA_ARGS__)
#define _MATRIX_CAL_IMPL_LIST_NOT_T_0(temp, x, T, ...) \
    _MATRIX_IMPL(temp, temp##_TMP, x) \
    _M_delayed(_MATRIX_CAL_IMPL_LIST_I)()(temp##I, __VA_ARGS__)
#define _MATRIX_CAL_IMPL_LIST_NOT_T_1(temp, x, cate, ...) \
    _M_cat(_MATRIX_CAL_IMPL_LIST_NOT_x_, _MATRIX_CHECK_NOT_x(cate))(temp, x, cate, __VA_ARGS__)
#define _MATRIX_CAL_IMPL_LIST_NOT_x_0(temp, x, cate, y, ...) \
    _MATRIX_IMPL(temp##_X, temp##_X_TMP, x) \
    _MATRIX_IMPL(temp##_Y, temp##_Y_TMP, y) \
    _M_delayed(_MATRIX_CAL_IMPL_LIST_I)()(temp##I, __VA_ARGS__)
#define _MATRIX_CAL_IMPL_LIST_NOT_x_1(temp, x, ...) \
    _MATRIX_IMPL(temp, temp##_TMP, x) \
    _M_delayed(_MATRIX_CAL_IMPL_LIST_I)()(temp##I, __VA_ARGS__)

#define _MATRIX_CAL_IMPL_DOT_I() _MATRIX_CAL_IMPL_DOT
#define _MATRIX_CAL_IMPL_DOT(temp, x, ...) \
    _M_cat(_MATRIX_CAL_IMPL_DOT_, _M_one_or_none(x))(temp, x, __VA_ARGS__)
#define _MATRIX_CAL_IMPL_DOT_0(...)
#define _MATRIX_CAL_IMPL_DOT_1(temp, x, cate, ...) \
    _M_cat(_MATRIX_CAL_IMPL_DOT_NOT_T_, _MATRIX_CHECK_NOT_T(cate))(temp, x, cate, __VA_ARGS__)
#define _MATRIX_CAL_IMPL_DOT_NOT_T_0(temp, x, T, ...) \
    _M_delayed(_MATRIX_CAL_IMPL_DOT_I)()(temp##I, __VA_ARGS__)
#define _MATRIX_CAL_IMPL_DOT_NOT_T_1(temp, x, cate, ...) \
    _M_cat(_MATRIX_CAL_IMPL_DOT_NOT_x_, _MATRIX_CHECK_NOT_x(cate))(temp, x, cate, __VA_ARGS__)
#define _MATRIX_CAL_IMPL_DOT_NOT_x_0(temp, x, cate, y, ...) \
    _MATRIX_DOT_MAKE(temp, x, cate, y) \
    _M_delayed(_MATRIX_CAL_IMPL_DOT_I)()(temp##I, __VA_ARGS__)
#define _MATRIX_CAL_IMPL_DOT_NOT_x_1(temp, x, ...) \
    _M_delayed(_MATRIX_CAL_IMPL_DOT_I)()(temp##I, __VA_ARGS__)

#define _MATRIX_CAL_IMPL_EXPR_I() _MATRIX_CAL_IMPL_EXPR
#define _MATRIX_CAL_IMPL_EXPR(temp, f, invoke, x, ...) \
    _M_cat(_MATRIX_CAL_IMPL_EXPR_, _M_one_or_none(x))(temp, f, invoke, x, __VA_ARGS__)
#define _MATRIX_CAL_IMPL_EXPR_0(temp, f, invoke, _, ...) invoke(f, __VA_ARGS__)
#define _MATRIX_CAL_IMPL_EXPR_1(temp, f, invoke, x, cate, ...) \
    _M_cat(_MATRIX_CAL_IMPL_EXPR_NOT_T_, _MATRIX_CHECK_NOT_T(cate))(temp, f, invoke, x, cate, __VA_ARGS__)
#define _MATRIX_CAL_IMPL_EXPR_NOT_T_0(temp, f, invoke, x, T, ...) \
    _M_delayed(_MATRIX_CAL_IMPL_EXPR_I)()(temp##I, f, invoke, __VA_ARGS__, (*temp##_PTR)[_MATRIX_J][_MATRIX_I])
#define _MATRIX_CAL_IMPL_EXPR_NOT_T_1(temp, f, invoke, x, cate, ...) \
    _M_cat(_MATRIX_CAL_IMPL_EXPR_NOT_x_, _MATRIX_CHECK_NOT_x(cate))(temp, f, invoke, x, cate, __VA_ARGS__)
#define _MATRIX_CAL_IMPL_EXPR_NOT_x_0(temp, f, invoke, x, cate, y, ...) \
    _M_delayed(_MATRIX_CAL_IMPL_EXPR_I)()(temp##I, f, invoke, __VA_ARGS__, temp##_DOT)
#define _MATRIX_CAL_IMPL_EXPR_NOT_x_1(temp, f, invoke, x, ...) \
    _M_delayed(_MATRIX_CAL_IMPL_EXPR_I)()(temp##I, f, invoke, __VA_ARGS__, (*temp##_PTR)[_MATRIX_I][_MATRIX_J])

#define _MATRIX_CAL_IMPL_ACCUMULATE(name, temp, f, invoke, ...) \
    { \
        _M_delayed(_MATRIX_CAL_IMPL_LIST_I)()(temp##_I, __VA_ARGS__) \
        for (size_t _MATRIX_I = 0; _MATRIX_I != sizeof(name##_ROW); ++_MATRIX_I) \
        { \
            for (size_t _MATRIX_J = 0; _MATRIX_J != sizeof(name##_COL); ++_MATRIX_J) \
            { \
                _M_delayed(_MATRIX_CAL_IMPL_DOT_I)()(temp##_I, __VA_ARGS__) \
                _M_delayed(_MATRIX_CAL_IMPL_EXPR_I)()(temp##_I, f, invoke, __VA_ARGS__, (*name##_PTR)[_MATRIX_I][_MATRIX_J]); \
            } \
        } \
    }

#define _MATRIX_CAL_IMPL_INVOKE(f, ...) f(__VA_ARGS__)
#define _MATRIX_CAL_IMPL_I() _MATRIX_CAL_IMPL
#define _MATRIX_CAL_IMPL(name, temp, f, x, ...) \
    _MATRIX_IMPL(name, temp##_RES, x) \
    _MATRIX_CAL_IMPL_ACCUMULATE(name, temp, f, _MATRIX_CAL_IMPL_INVOKE, __VA_ARGS__)



#define _MATRIX_RET_TYPE_LIST_I() _MATRIX_RET_TYPE_LIST
#define _MATRIX_RET_TYPE_LIST(temp, x, ...) \
    _M_cat(_MATRIX_RET_TYPE_LIST_, _M_one_or_none(x))(temp, x, __VA_ARGS__)
#define _MATRIX_RET_TYPE_LIST_0(...)
#define _MATRIX_RET_TYPE_LIST_1(temp, x, cate, ...) \
    _M_cat(_MATRIX_RET_TYPE_LIST_NOT_T_, _MATRIX_CHECK_NOT_T(cate))(temp, x, cate, __VA_ARGS__)
#define _MATRIX_RET_TYPE_LIST_NOT_T_0(temp, x, T, ...) \
    _MATRIX_TYPE(temp, temp##_TMP, x) \
    _M_delayed(_MATRIX_RET_TYPE_LIST_I)()(temp##I, __VA_ARGS__)
#define _MATRIX_RET_TYPE_LIST_NOT_T_1(temp, x, cate, ...) \
    _M_cat(_MATRIX_RET_TYPE_LIST_NOT_x_, _MATRIX_CHECK_NOT_x(cate))(temp, x, cate, __VA_ARGS__)
#define _MATRIX_RET_TYPE_LIST_NOT_x_0(temp, x, cate, y, ...) \
    _MATRIX_TYPE(temp##_X, temp##_X_TMP, x) \
    _MATRIX_TYPE(temp##_Y, temp##_Y_TMP, y) \
    _M_delayed(_MATRIX_RET_TYPE_LIST_I)()(temp##I, __VA_ARGS__)
#define _MATRIX_RET_TYPE_LIST_NOT_x_1(temp, x, ...)\
    _MATRIX_TYPE(temp, temp##_TMP, x) \
    _M_delayed(_MATRIX_RET_TYPE_LIST_I)()(temp##I, __VA_ARGS__)

#define _MATRIX_RET_TYPE_EXPR_I() _MATRIX_RET_TYPE_EXPR
#define _MATRIX_RET_TYPE_EXPR(temp, f, x, ...) \
    _M_cat(_MATRIX_RET_TYPE_EXPR_, _M_one_or_none(x))(temp, f, x, __VA_ARGS__)
#define _MATRIX_RET_TYPE_EXPR_0(temp, f, _, ...) f(__VA_ARGS__)
#define _MATRIX_RET_TYPE_EXPR_1(temp, f, x, cate, ...) \
    _M_cat(_MATRIX_RET_TYPE_EXPR_NOT_T_, _MATRIX_CHECK_NOT_T(cate))(temp, f, x, cate, __VA_ARGS__)
#define _MATRIX_RET_TYPE_EXPR_NOT_T_0(temp, f, x, T, ...) \
    _M_delayed(_MATRIX_RET_TYPE_EXPR_I)()(temp##I, f, __VA_ARGS__, (***(temp##_TYPE*)0))
#define _MATRIX_RET_TYPE_EXPR_NOT_T_1(temp, f, x, cate, ...) \
    _M_cat(_MATRIX_RET_TYPE_EXPR_NOT_x_, _MATRIX_CHECK_NOT_x(cate))(temp, f, x, cate, __VA_ARGS__)
#define _MATRIX_RET_TYPE_EXPR_NOT_x_0(temp, f, x, cate, y, ...) \
    _M_delayed(_MATRIX_RET_TYPE_EXPR_I)()(temp##I, f, __VA_ARGS__, ((***(temp##_X_TYPE*)0) * (***(temp##_Y_TYPE*)0)))
#define _MATRIX_RET_TYPE_EXPR_NOT_x_1(temp, f, x, ...) \
    _M_delayed(_MATRIX_RET_TYPE_EXPR_I)()(temp##I, f, __VA_ARGS__, (***(temp##_TYPE*)0))

#define _MATRIX_RET_TYPE_ASSERT_I() _MATRIX_RET_TYPE_ASSERT
#define _MATRIX_RET_TYPE_ASSERT(name, temp, x, ...) \
    _M_cat(_MATRIX_RET_TYPE_ASSERT_, _M_one_or_none(x))(name, temp, x, __VA_ARGS__)
#define _MATRIX_RET_TYPE_ASSERT_0(...)
#define _MATRIX_RET_TYPE_ASSERT_1(name, temp, x, cate, ...) \
    _M_cat(_MATRIX_RET_TYPE_ASSERT_NOT_T_, _MATRIX_CHECK_NOT_T(cate))(name, temp, x, cate, __VA_ARGS__)
#define _MATRIX_RET_TYPE_ASSERT_NOT_T_0(name, temp, x, T, ...) \
    _MATRIX_ASSERT(sizeof(name##_ROW) == sizeof(temp##_COL) && sizeof(name##_COL) == sizeof(temp##_ROW)) \
    _M_delayed(_MATRIX_RET_TYPE_ASSERT_I)()(name, temp##I, __VA_ARGS__)
#define _MATRIX_RET_TYPE_ASSERT_NOT_T_1(name, temp, x, cate, ...) \
    _M_cat(_MATRIX_RET_TYPE_ASSERT_NOT_x_, _MATRIX_CHECK_NOT_x(cate))(name, temp, x, cate, __VA_ARGS__)
#define _MATRIX_RET_TYPE_ASSERT_NOT_x_0(name, temp, x, cate, y, ...) \
    _MATRIX_ASSERT_MAKE##cate(name, temp) \
    _M_delayed(_MATRIX_RET_TYPE_ASSERT_I)()(name, temp##I, __VA_ARGS__)
#define _MATRIX_RET_TYPE_ASSERT_NOT_x_1(name, temp, x, ...) \
    _MATRIX_ASSERT(sizeof(name##_ROW) == sizeof(temp##_ROW) && sizeof(name##_COL) == sizeof(temp##_COL)) \
    _M_delayed(_MATRIX_RET_TYPE_ASSERT_I)()(name, temp##I, __VA_ARGS__)

#define _MATRIX_RET_TYPE_RES_FINAL(name, temp, f, row, col, xnum, ...) \
    typedef char name##_ROW[row]; \
    typedef char name##_COL[col]; \
    typedef typeof(_M_delayed(_MATRIX_RET_TYPE_EXPR_I)()(temp##I, f, __VA_ARGS__, xnum)) name##_TYPE[sizeof(name##_ROW)][sizeof(name##_COL)]; \
    _M_delayed(_MATRIX_RET_TYPE_ASSERT_I)()(name, temp##I, __VA_ARGS__)
#define _MATRIX_RET_TYPE_RES(name, temp, f, x, cate, ...) \
    _M_cat(_MATRIX_RET_TYPE_RES_NOT_T_, _MATRIX_CHECK_NOT_T(cate))(name, temp, f, x, cate, __VA_ARGS__)
#define _MATRIX_RET_TYPE_RES_NOT_T_0(name, temp, f, x, T, ...) \
    _MATRIX_RET_TYPE_RES_FINAL(name, temp, f, sizeof(temp##_COL), sizeof(temp##_ROW), (***(temp##_TYPE*)0), __VA_ARGS__)
#define _MATRIX_RET_TYPE_RES_NOT_T_1(name, temp, f, x, cate, ...) \
    _M_cat(_MATRIX_RET_TYPE_RES_NOT_x_, _MATRIX_CHECK_NOT_x(cate))(name, temp, f, x, cate, __VA_ARGS__)
#define _MATRIX_RET_TYPE_RES_NOT_x_0(name, temp, f, x, cate, y, ...) \
    _MATRIX_XT_TYPE_RES##cate(name, temp, f, _MATRIX_RET_TYPE_RES_FINAL, __VA_ARGS__)
#define _MATRIX_RET_TYPE_RES_NOT_x_1(name, temp, f, x, ...) \
    _MATRIX_RET_TYPE_RES_FINAL(name, temp, f, sizeof(temp##_ROW), sizeof(temp##_COL), (***(temp##_TYPE*)0), __VA_ARGS__)

#define _MATRIX_RET_TYPE_I() _MATRIX_RET_TYPE
#define _MATRIX_RET_TYPE(name, temp, f, ...) \
    _M_delayed(_MATRIX_RET_TYPE_LIST_I)()(temp##_I, __VA_ARGS__) \
    _MATRIX_RET_TYPE_RES(name, temp##_I, f, __VA_ARGS__)

#define _MATRIX_RET_IMPL_INVOKE(f, x, ...) x = f(__VA_ARGS__)

#define _MATRIX_RET_IMPL_I() _MATRIX_RET_IMPL
#define _MATRIX_RET_IMPL(name, temp, f, ...) \
    name##_TYPE name##_DATA, * const name##_PTR = &name##_DATA; \
    _MATRIX_CAL_IMPL_ACCUMULATE(name, temp, f, _MATRIX_RET_IMPL_INVOKE, __VA_ARGS__)



#endif