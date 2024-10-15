#ifndef MASS_VECTOR_
#include "vector.h"
#define MASS_VECTOR_
#endif /* MASS_VECTOR_ */

#ifndef MASS_LIST_
#define MASS_LIST_

typedef struct v_node {
	vec_t			*vec;
	struct v_node	*next;
} v_node;

typedef struct v_list {
	v_node		*head;
	v_node		*tail;
	unsigned	m_cnt;
	unsigned	f_cnt;
} v_list;


void list_init(v_list *list);
void list_insert(v_list *list, vec_t *vec);
void list_del(v_list *list);

#endif /* MASS_LIST_ */
