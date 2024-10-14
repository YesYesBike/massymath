#include <stdlib.h>
#include "vector.h"

#ifndef MASS_POLYGON_
#define MASS_POLYGON_

typedef struct poly_t {
	vec_t	*pt;
	vec_t	*c;
	int		n;
} poly_t;


poly_t	*poly_make(int n, double r, double a_init, const vec_t *p);
void	poly_destroy(poly_t *pp);
void	poly_print(poly_t *pp);

#endif /* MASS_POLYGON_ */
