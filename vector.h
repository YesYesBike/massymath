#include <math.h>

#ifndef MASS_VECTOR_
#define	MASS_VECTOR_

typedef struct vector {
	double x;
	double y;
	double z;
} vec_t;

#ifndef MASS_LIST_
#include "list.h"
#define MASS_LIST_
#endif /* MASS_LIST_ */


vec_t	*vec(v_list *list, double x, double y, double z);
void	vec_del(v_list *list, vec_t *p);
vec_t	*vec_add(v_list *list, vec_t *a, vec_t *b);
vec_t	*vec_sub(v_list *list, vec_t *a, vec_t *b);
vec_t	*vec_add_l(v_list *vlist, vec_t **list, int size);
vec_t	*vec_add_n(v_list *list, int n, ...);
double	vec_len(vec_t *a);
vec_t	*vec_sca(v_list *list, vec_t *a, double n);
void	vec_print(vec_t *a);
double	vec_dist(vec_t *a, vec_t *b);
vec_t	*vec_rev(v_list *list, vec_t *a);

#endif	/* MASS_VECTOR_ */
