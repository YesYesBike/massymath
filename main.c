#include <stdio.h>
#include "vector.h"
#include "list.h"

int main(void)
{
	v_list list;
	list_init(&list);

	vec_t *a = vec(&list, 1, 2, 3);
	vec_t *b = vec(&list, 12, 2, 3);
	printf("%lf\n", vec_dist(a,b));
	list_del(&list);

	return 0;
}
