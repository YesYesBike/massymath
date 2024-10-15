#include <stdlib.h>
#include <stdio.h>
#include "list.h"


/*
 * g/[fm]_cnt/norm I//
 * g/[fm]_cnt/norm ^2x
 *
 */

void list_init(v_list *list)
{
	list->head = malloc(sizeof(v_node));
	list->head->vec = NULL;
	list->head->next = NULL;
	list->tail = list->head;
	list->m_cnt = 1;
	list->f_cnt = 0;
}


void list_insert(v_list *list, vec_t *vec)
{
	if (list->head->vec == NULL) {
		list->head->vec = vec;
	} else {
		v_node *new_node = malloc(sizeof(v_node));
		(list->m_cnt)++;
		new_node->vec = vec;
		new_node->next = NULL;
		list->tail->next = new_node;
		list->tail = new_node;
	}
}


void list_del(v_list *list)
{
	while (list->head != NULL) {
		v_node *rp = list->head;
		list->head = list->head->next;
		if (rp->vec != NULL)
			free(rp->vec);
		free(rp);
		(list->f_cnt)++;
	}

	printf("malloc: %d\nfree: %d\n", list->m_cnt, list->f_cnt);
}
