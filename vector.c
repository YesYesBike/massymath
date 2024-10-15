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
	double d_x = a->x - b->x;
	double d_y = a->y - b->y;
	double d_z = a->z - b->z;
	return sqrt(d_x*d_x + d_y*d_y + d_z*d_z);
}
