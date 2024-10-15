#include <math.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "vector.h"

vec_t vec_add(vec_t a, vec_t b)
{
	vec_t ret;
	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;

	return ret;
}


vec_t vec_add_l(vec_t *list, int size)
{
	vec_t ret = {};
	for (int i=0; i<size; i++) {
		ret.x += list[i].x;
		ret.y += list[i].y;
		ret.z += list[i].z;
	}

	return ret;
}


vec_t vec_add_n(int n, ...)
{
	vec_t ret = {};
	va_list ap;
	va_start(ap, n);
	for (int i=0; i<n; i++) {
		vec_t vec = va_arg(ap, vec_t);
		ret.x += vec.x;
		ret.y += vec.y;
		ret.z += vec.z;
	}

	va_end(ap);
	return ret;
}


double vec_len(vec_t a)
{
	//return hypot(a.x, a.y);
	return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}


vec_t vec_sca(vec_t a, double n)
{
	vec_t ret;
	ret.x = a.x * n;
	ret.y = a.y * n;
	ret.z = a.z * n;
	
	return ret;
}


void vec_print(vec_t a)
{
	//printf("x:%lf y:%lf\n", a);
	//printf("x:%lf y:%lf z:%lf\n", a);
	printf("x:%lf ", a.x);
	printf("y:%lf ", a.y);
	printf("z:%lf\n", a.z);
}


vec_t vec_rev(vec_t a)
{
	vec_t ret;
	ret.x = -(a.x);
	ret.y = -(a.y);
	ret.z = -(a.z);

	return ret;
}


vec_t vec_sub(vec_t a, vec_t b)
{
	vec_t ret;
	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;

	return ret;
}


vec_t vec_sub_n(int n, ...)
{
	va_list ap;
	va_start(ap, n);
	vec_t ret = va_arg(ap,vec_t);
	for (int i=0; i<n-1; i++) {
		vec_t vec = va_arg(ap, vec_t);
		ret.x -= vec.x;
		ret.y -= vec.y;
		ret.z -= vec.z;
	}

	va_end(ap);
	return ret;
}


double vec_dist(vec_t a, vec_t b)
{
	//return hypot((a.x-b.x), (a.y-b.y));
	double d_x = a.x - b.x;
	double d_y = a.y - b.y;
	double d_z = a.z - b.z;
	return sqrt(d_x*d_x + d_y*d_y + d_z*d_z);
}


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
