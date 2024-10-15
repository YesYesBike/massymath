#include <math.h>
#ifndef MASS_VECTOR_
#define	MASS_VECTOR_

typedef struct vector {
	double x;
	double y;
	double z;
} vec_t;

typedef struct pol_t {
	double r;
	double a;
	//double z;
} pol_t;

vec_t	vec_add(vec_t a, vec_t b);
vec_t	vec_sub(vec_t a, vec_t b);
vec_t 	vec_add_l(vec_t *list, int size);
vec_t 	vec_add_n(int n, ...);
vec_t	vec_sub_n(int n, ...);
double	vec_len(vec_t a);
vec_t	vec_sca(vec_t a, double n);
void	vec_print(vec_t a);
double	vec_dist(vec_t a, vec_t b);
vec_t	vec_rot(vec_t v, double a);
vec_t	vec_rev(vec_t a);
vec_t	pol2vec(pol_t p);
pol_t 	vec2pol(vec_t v);
void	pol_print(pol_t a);
pol_t	pol_move(pol_t p, vec_t v);

#endif	/* MASS_VECTOR_ */
