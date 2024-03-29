/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 23:44:54 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/10 12:28:53 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void		swap(s_swap *swap)
{
	int	tmp;

	tmp = swap->array[0];
	swap->array[0] = swap->array[1];
	swap->array[1] = tmp;
}

void	reverse_rotate(s_swap *reverse_rotate)
{
	int	tmp;
	int	size;
	
	int		i;
	i = 0;
	size = reverse_rotate->size - 1;
	while (size > 0)
	{
		tmp = reverse_rotate->array[size - 1];
		reverse_rotate->array[size - 1] = reverse_rotate->array[size];
		reverse_rotate->array[size] = tmp;
		size--;
	}
}

void	rotate(s_swap *rotate)
{
	int	tmp;
	int	size;
	int i;
	
	size = rotate->size - 1;
	i = 0;
	while (i < size)
	{
		tmp = rotate->array[i];
		rotate->array[i] = rotate->array[i + 1];
		rotate->array[i + 1] = tmp;
		i++;
	}
}

void		sort_3(s_swap *sorting)
{
	if (sorting->array[0] > sorting->array[1] && sorting->array[0] < sorting->array[2] && sorting->array[1] < sorting->array[2])
	{
		swap(sorting);
		ft_putstr("sa\n");
	}
	else if (sorting->array[0] > sorting->array[1] && sorting->array[1] > sorting->array[2])
	{
		swap(sorting);
		reverse_rotate(sorting);
		ft_putstr("sa\nrra\n");
	}
	else if(sorting->array[0] > sorting->array[1] && sorting->array[0] > sorting->array[2] && sorting->array[1] < sorting->array[2])
	{
		rotate(sorting);
		ft_putstr("ra\n");
	}
	else if (sorting->array[0] < sorting->array[1] && sorting->array[1] > sorting->array[2] && sorting->array[0] < sorting->array[2])
	{
		swap(sorting);
		rotate(sorting);
		ft_putstr("sa\nra\n");
	}
	else if (sorting->array[0] < sorting->array[1] && sorting->array[1] > sorting->array[2] && sorting->array[0] > sorting->array[2])
	{
		reverse_rotate(sorting);
		ft_putstr("rra\n");
	}  
}

int		min_value(int	*array, int size)
{
	int	i;
	int	min;

	i = 1;
	min = array[0];
	while (i < size)
	{
		if (min > array[i])
			min = array[i];
		i++;
	}
	return (min);
}