#include <stdio.h>
#include "vector.h"
#include "polygon.h"

int main(void)
{
	vec_t v = {1, 1};
	poly_t *poly = poly_make(4, 1, 0, &v);
	poly_print(poly);
	poly_destroy(poly);

	return 0;
}
