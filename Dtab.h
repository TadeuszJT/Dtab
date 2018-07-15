#ifndef DTAB_H
#define DTAB_H

#include <stdlib.h>

#define Dtab(T) struct {T *array; int len, cap;}

#define Dtab_init(d)\
do {\
	(d)->array = NULL;\
	(d)->len = 0;\
	(d)->cap = 0;\
} while (0)

#define Dtab_grow(d, n)\
do {\
	if (((d)->len += (n)) > (d)->cap) {\
		*(void**)&(d)->array = realloc(\
			(d)->array,\
			sizeof(*(d)->array) * ((d)->cap = (d)->len*2)\
		);\
	}\
} while (0)

#define Dtab_shrink(d, n)\
do {\
	if (((d)->len -= (n)) < (d)->cap*0.25) {\
		*(void**)&(d)->array = realloc(\
			(d)->array,\
			sizeof(*(d)->array) * ((d)->cap = (d)->len)\
		);\
	}\
} while (0)

#define Dtab_destroy(d)\
do {\
	free((d)->array);\
} while (0)

#endif
