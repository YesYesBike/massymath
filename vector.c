#include <math.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "vector.h"


vec_t *vec(v_list *list, double x, double y, double z)
{
	vec_t *ret = malloc(sizeof(vec_t));
	ret->x = x;
	ret->y = y;
	ret->z = z;

	list_insert(list, ret);

	return ret;
}


void vec_del(v_list *list, vec_t *p)
{
	v_node *rp = list->head;
	v_node *bef = rp;
	while (rp != NULL) {
		if (rp->vec == p)
			break;
		bef = rp;
		rp = rp->next;
	}

	if (rp == NULL)
		return;

	if (rp == list->head)
		list->head = list->head->next;
	
	if (rp == list->tail)
		list->tail = bef;

	free(rp->vec);
	free(rp);
	(list->f_cnt)++;
}

vec_t *vec_add(v_list *list, vec_t *a, vec_t *b)
{
	double x = a->x + b->x;
	double y = a->y + b->y;
	double z = a->z + b->z;
	vec_t *ret = vec(list,x,y,z);

	return ret;
}


vec_t *vec_add_l(v_list *vlist, vec_t **list, int size)
{
	double x=0, y=0, z=0;
	for (int i=0; i<size; i++) {
		x += list[i]->x;
		y += list[i]->y;
		z += list[i]->z;
	}
	vec_t *ret = vec(vlist,x,y,z);

	return ret;
}


vec_t *vec_add_n(v_list *list, int n, ...)
{
	va_list ap;
	va_start(ap, n);
	double x=0, y=0, z=0;

	for (int i=0; i<n; i++) {
		vec_t vec = *(va_arg(ap, vec_t*));
		x += vec.x;
		y += vec.y;
		z += vec.z;
	}

	vec_t *ret = vec(list, x,y,z);
	va_end(ap);
	return ret;
}


double vec_len(vec_t *a)
{
	//return hypot(a.x, a.y);
	double x = a->x;
	double y = a->y;
	double z = a->z;
	return sqrt(x*x + y*y + z*z);
}


vec_t *vec_sca(v_list *list, vec_t *a, double n)
{
	double x=0, y=0, z=0;
	x = a->x * n;
	y = a->y * n;
	z = a->z * n;
	
	vec_t *ret = vec(list, x,y,z);
	return ret;
}


void vec_print(vec_t *a)
{
	//printf("x:%lf y:%lf\n", a);
	//printf("x:%lf y:%lf z:%lf\n", a);
	printf("x:%lf ", a->x);
	printf("y:%lf ", a->y);
	printf("z:%lf\n", a->z);
}


vec_t *vec_rev(v_list *list, vec_t *a)
{
	double x=0, y=0, z=0;
	x = -(a->x);
	y = -(a->y);
	z = -(a->z);

	vec_t *ret = vec(list, x,y,z);
	return ret;
}


vec_t *vec_sub(v_list *list, vec_t *a, vec_t *b)
{
	double x = a->x - b->x;
	double y = a->y - b->y;
	double z = a->z - b->z;

	vec_t *ret = vec(list,x,y,z);
	return ret;
}


double vec_dist(vec_t *a, vec_t *b)
{
	//return hypot((a.x-b.x), (a.y-b.y));
	double d_x = a->x - b->x;
	double d_y = a->y - b->y;
	double d_z = a->z - b->z;
	return sqrt(d_x*d_x + d_y*d_y + d_z*d_z);
}


/*
vec_t vec_rot(vec_t v, double a)
{
	//TODO 3D
	vec_t ret;
	pol_t p = vec2pol(v);
	p.a += a;
	ret = pol2vec(p);

	return ret;
}


vec_t pol2vec(pol_t p)
{
	//TODO 3D
	vec_t ret;
	ret.x = p.r * cos(p.a);
	ret.y = p.r * sin(p.a);

	return ret;
}


pol_t vec2pol(vec_t v)
{
	//TODO 3D
	pol_t ret;
	ret.r = vec_len(v);
	ret.a = atan2(v.y, v.x);

	return ret;
}


void pol_print(pol_t p)
{
	//TODO 3D
	printf("r:%f, a:%f\n", p);
}


pol_t pol_move(pol_t p, vec_t v)
{
	//TODO 3D
	pol_t ret;
	vec_t vec = pol2vec(p);
	vec.x += v.x;
	vec.y += v.y;
	ret = vec2pol(vec);

	return ret;
}
*/
