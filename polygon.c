#include <stdlib.h>
#include "polygon.h"

poly_t *poly_make(int n, double r, double a_init, const vec_t *p)
{
	poly_t *ret = malloc(sizeof(poly_t));
	ret->c = malloc(sizeof(vec_t));
	ret->pt = malloc(sizeof(vec_t)*n);
	ret->n = n;

	double x_inc = 0, y_inc = 0;
	if (p != NULL) {
		x_inc = p->x;
		y_inc = p->y;
	}

	ret->c->x = x_inc;
	ret->c->y = y_inc;

	pol_t temp = {r, a_init};
	double a_inc = 2*M_PI/n;

	ret->pt[0] = pol2vec(temp);
	ret->pt[0].x += x_inc;
	ret->pt[0].y += y_inc;

	for (int i=1; i<n; i++) {
		temp.a += a_inc;
		ret->pt[i] = pol2vec(temp);
		ret->pt[i].x += x_inc;
		ret->pt[i].y += y_inc;
	}

	return ret;
}


void poly_destroy(poly_t *pp)
{
	free(pp->c);
	free(pp->pt);
	free(pp);
}


void poly_print(poly_t *pp)
{
	vec_print(*(pp->c));
	for (int i=0; i<pp->n; i++)
		vec_print(pp->pt[i]);
}
