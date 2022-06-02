
#include "del_dup_egdes.h"

void btree_print(void *item)
{
	t_edge eitem = *(t_edge *)item;
	printf("%lu %lu\n", eitem.e[0], eitem.e[1]);
	//printf("%i\n", *(int *)item);
}

int cmp_x(t_edge *i1, t_edge *i2)
{
	t_edge ei1 = *(t_edge *)i1;
	t_edge ei2 = *(t_edge *)i2;
	return (ei1.e[0] - ei2.e[0]);
}

t_edge *remove_egdes_double(t_edge *edges, size_t *egdes_size)
{
	t_btree	*mytree = NULL;
	size_t i;

	i = 0;
	while (i < *egdes_size)
	{
		btree_insert_data(&mytree, &edges[i], (int (*) (void *, void *))&cmp_x);
		i++;
	}
	btree_apply_infix(mytree, &btree_print);
	return (edges);
}

// void remove(int argc, char **argv)
// {
// 	t_btree	*mytree = NULL;

// 	int i = 0;

// 	while (i < len)
// 	{
// 		btree_insert_data(&mytree, &arr[i], (int (*) (void *, void *))&cmp);
// 		i++;
// 	}
// 	btree_apply_infix(mytree, &btree_print);
// 	int x = 0;
// 	while (x < 100)
// 	{
// 		t_btree *target = btree_search_node(mytree, &x,(int (*)(void *, void *)) cmp);
// 		if (target)
// 			printf("we found %i\n", *(int *)target->item);
// 		x++;
// 	}
// }
