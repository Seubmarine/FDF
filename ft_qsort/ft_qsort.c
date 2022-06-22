#include "ft_qsort.h"

char	*access(void *p, int index, int size)
{
	return (((char *)p)[index * size]);
}

void	ft_swap(void *a_ptr, void *b_ptr, size_t size)
{
	char	tmp;
	size_t	i;
	char	*a;
	char	*b;

	i = 0;
	a = a_ptr;
	b = b_ptr;
	while (i < size)
	{
		tmp = a[i * size];
		a[i * size] = b[i * size];
		b[i * size] = tmp;
		i++;
	}
}

void	qswap(void *v, size_t left, size_t right, size_t type_size)
{
	char	*v_c = v;
	char	tmp;
	char	*a = v_c + left * type_size;
	char	*b = v_c + right * type_size;
	size_t	i;

	i = 0;
	while (i < type_size)
	{
		tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
		i++;
	}
}

void	qsort(void *v, long left, long right, size_t type_size, int (*comp)(void *, void *)) {
	size_t	i;
	size_t	last;

	if (left >= right)
		return ;
	qswap(v, left, (left + right)/2, type_size);
	last = left;
	for (i = left + 1; i <= right; i++)
		if ((*comp)((char *)v + i * type_size, (char *)v + left * type_size) < 0) /* Here's the function call */
			qswap(v, ++last, i, type_size);
	qswap(v, left, last, type_size);
	qsort(v, left, last-1, type_size, comp);
	qsort(v, last+1, right, type_size, comp);
}

int	cmp(void *a, void *b)
{
	const int	ai = (int) a;
	const int	bi = (int) b;

	return (ai - bi);
}

void	ft_qsort(void *base, size_t nmemb, size_t size,
			int (*compar)(const void *, const void *))
{
	qsort(base, 0, nmemb - 1, size, compar);
}

// int main(void)
// {
// 	int		tab[] = {5, 4, 3, 42, 0, 7, -2847, 2, 1, -1, 42, 55};
// 	const size_t	tab_size = sizeof(tab) / sizeof(tab[0]);
// 	ft_qsort(tab, tab_size, sizeof(tab[0]), &cmp);

// 	for (size_t i = 0; i < tab_size; i++)
// 	{
// 		printf("%i ", tab[i]);
// 	}
// 	printf("\n");
// }