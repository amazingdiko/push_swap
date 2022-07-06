/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:19:29 by wmozella          #+#    #+#             */
/*   Updated: 2022/03/10 22:31:25 by wmozella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_arr(int *arr, int argc)
{
	int	i;
	int	b;
	int	nb;

	i = 0;
	b = 0;
	nb = 0;
	while (b < argc - 2)
	{
		while (i < (argc - 1) - b - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				nb = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = nb;
			}
			i ++;
		}
		b ++;
		i = 0;
	}
}

t_list	*ft_create_list(long int i)
{
	t_list	*el;

	el = malloc(sizeof(t_list));
	if (el == NULL)
		return (NULL);
	el->data = i;
	el->next = NULL;
	return (el);
}

void	ft_put_back(t_list **list, long int i)
{
	t_list	*new;
	t_list	*tmp;

	if (*list)
	{
		new = ft_create_list(i);
		tmp = *list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*list = ft_create_list(i);
}

void	ft_create_list_a(int argc, char **argv, int *arr, t_list **list_a)
{
	int	i;
	int	k;

	i = 0;
	k = 1;
	while (k < argc)
	{
		arr[i] = ft_atoi(argv[k]);
		ft_put_back(list_a, arr[i]);
		i ++;
		k ++;
	}
}

int	main(int argc, char **argv)
{
	t_list		*list_a;
	t_list		*list_b;
	int			*arr;
	int			i;

	i = 0;
	arr = malloc(sizeof(char *) * (argc - 1));
	if (arr == NULL)
		return (0);
	ft_create_list_a(argc, argv, arr, &list_a);
	sort_arr(arr, argc);
	ft_check_doublicate(argc, argv);
	ft_check_sort(&list_a);
	ft_index(arr, argc, &list_a);
	ft_sort(&list_a, &list_b, argc);
	free (arr);
	ft_free(&list_a);
}
