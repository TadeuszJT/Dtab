#ifndef DTAB_H
#define DTAB_H

#include <string.h>

#define Dtab(T) struct {T *array; int len, cap;}

#define Dtab_init(d)\
	((d)->array = malloc(0), (d)->len = 0, (d)->cap = 0, 1)

#define Dtab_grow(d, n)\
	(((d)->len += n) > (d)->cap ?\
	(d)->array = realloc(\
		(d)->array,\
		sizeof(*((d)->array))*((d)->cap = (d)->len*2)\
	) : (d)->array)

#define Dtab_shrink(d, n)\
	(((d)->len -= n) < (d)->cap/4 ?\
	(d)->array = realloc(\
		(d)->array,\
		sizeof(*((d)->array))*((d)->cap = (d)->len)\
	) : (d)->array)

#define Dtab_destroy(d)\
	free((d)->array)

#endif
