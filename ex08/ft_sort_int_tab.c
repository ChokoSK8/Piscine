#include <unistd.h>
#define MIN(x, y) x < y ? x : y

void 	ft_swap(int *a, int *b)
{
	int *temp;

	*temp = *a;
	*a = *b;
	*b = *a;
}

void ft_sort_int_tab(int *tab, int size)
{
	int counter;
	int i;
	int min;

	counter = -1;

	while (++counter < size - 1)
	{
		i = counter;
		while (++i < size)
			min = MIN(tab[counter], tab[i]);
		char c = min;
		write(1, &c, 1);
		tab[counter] = min;
	}
}

int main ()
{
	int *tab;
    *tab = 8;
	tab[1] = 2;	
	tab[2] = 9;	
	tab[3] = 1;	
	tab[4] = 5;	
	tab[5] = 3;	
	ft_sort_int_tab( tab, 6);
}
