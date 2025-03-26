#ifndef _MACRO_H
#define _MACRO_H

#define _M_cat(x, y) _MACRO_CAT(x, y)
#define _MACRO_CAT(x, y) x ## y

#define _M_one_or_none(...) _MACRO_OR_MID(__VA_ARGS__)
#define _MACRO_OR_MID(...) _MACRO_IF(_, ##__VA_ARGS__, 1, 0)
#define _MACRO_IF(_, ph, n, ...) n

#define _M_delayed(f) f _MACRO_BLOCK()
#define _MACRO_BLOCK()

#define _M_expand(...) __VA_ARGS__
#define _M_expand3(...) _M_expand(_M_expand(_M_expand(__VA_ARGS__)))
#define _M_expand9(...) _M_expand3(_M_expand3(_M_expand3(__VA_ARGS__)))
#define _M_expand27(...) _M_expand9(_M_expand9(_M_expand9(__VA_ARGS__)))
#define _M_expand81(...) _M_expand27(_M_expand27(_M_expand27(__VA_ARGS__)))
#define _M_expand243(...) _M_expand81(_M_expand81(_M_expand81(__VA_ARGS__)))
#define _M_expand729(...) _M_expand243(_M_expand243(_M_expand243(__VA_ARGS__)))

#endif