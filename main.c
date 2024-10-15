#include <stdio.h>
#include "vector.h"
#include "polygon.h"

int main(void)
{
	vec_t v1 = {2, 2, 2};
	vec_t v2 = {1, 1, 1};
	vec_t v3 = {1, 1, 1};
	vec_t list[] = {v1, v2, v3};
	vec_t v = vec_sub_n(3, v1, v2, v3);
	vec_print(v);
	//printf("%f\n", vec_dist(v1,v2));
	//printf("%f\n", sqrt(3));

	return 0;
}
