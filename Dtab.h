#ifndef DTAB_H
#define DTAB_H

#include <stdlib.h>

#define Dtab(T) struct {T *array; int len, cap;}

#define Dtab_init(d)\
	((d)->array = NULL, (d)->len = 0, (d)->cap = 0)

#define Dtab_grow(d, n)\
	(((d)->len += n) > (d)->cap ?\
	*((void**)(&((d)->array))) = realloc(\
		(d)->array,\
		sizeof(*((d)->array))*((d)->cap = (d)->len*2)\
	) : 0, 0)

#define Dtab_shrink(d, n)\
	(((d)->len -= n) < (d)->cap/4 ?\
	*((void**)(&((d)->array))) = realloc(\
		(d)->array,\
		sizeof(*((d)->array))*((d)->cap = (d)->len)\
	) : 0, 0)

#define Dtab_destroy(d)\
	free((d)->array)

#endif
