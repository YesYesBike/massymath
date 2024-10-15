#include <stdio.h>
#include "vector.h"
#include "list.h"

int main(void)
{
	v_list list;
	list_init(&list);

	vec_t *a = vec(&list, -1, -1, 2);
	double len = vec_len(a);
	vec_t *b = vec_sca(&list, a, 1/len);
	len = vec_len(b);

	vec_print(b);
	printf("%f\n", len);

	list_del(&list);

	return 0;
}
