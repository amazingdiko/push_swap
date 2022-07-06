/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:51:09 by wmozella          #+#    #+#             */
/*   Updated: 2022/03/10 22:31:02 by wmozella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_doublicate(int argc, char **argv)
{
	int	b;
	int	k;

	k = 1;
	while (k < argc)
	{
		b = k + 1;
		while (b < argc)
		{
			if (ft_atoi(argv[k]) == ft_atoi(argv[b]))
			{
				write(1, "Error\n", 6);
				exit (1);
			}
			b ++;
		}
		k ++;
	}
}

void	ft_check_sort(t_list **list_a)
{
	t_list	*list;
	int		i;

	i = 0;
	list = *list_a;
	while (list->next)
	{
		if (list->data > list->next->data)
		{
			i = 1;
			break ;
		}
		list = list->next;
	}
	if (i == 0)
	{
		write (1, "Already sorted!\n", 16);
		exit (1);
	}
}

void	ft_index(int *arr, int argc, t_list **list_a)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *list_a;
	while (tmp)
	{
		while (i < argc - 1)
		{
			if (tmp->data == arr[i])
				tmp->index = i;
			i ++;
		}
		tmp = tmp->next;
		i = 0;
	}
}

void	ft_free(t_list **list)
{
	t_list	*dell;

	while (*list)
	{
		dell = *list;
		*list = (*list)->next;
		free(dell);
	}
}
