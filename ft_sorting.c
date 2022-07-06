/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:25:02 by wmozella          #+#    #+#             */
/*   Updated: 2022/03/11 20:10:55 by wmozella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_list **list_a, t_list **list_b, int argc)
{
	if (argc == 3)
		sa_sb_ss(list_a, list_b, 'a');
	else if (argc == 4)
		ft_sort_for_three(list_a, list_b);
	else if (argc == 6)
		ft_sort_for_five(list_a, list_b, argc);
	else if (argc >= 7 && argc <= 101)
		ft_sort_for_100(list_a, list_b, argc);
	else
		ft_sort_for_500(list_a, list_b, argc);
}

void	ft_sort_for_three(t_list **list_a, t_list **list_b)
{
	int	a;
	int	b;
	int	nb;

	a = (*list_a)->data;
	b = (*list_a)->next->data;
	nb = (*list_a)->next->next->data;
	if (a > b && a > nb && nb > b)
		ft_ra_rb_rr(list_a, list_b, 'a');
	else if (a > b && a > nb && b > nb)
	{
		ft_ra_rb_rr(list_a, list_b, 'a');
		sa_sb_ss(list_a, list_b, 'a');
	}
	else if (b > a && b > nb && a > nb)
		ft_rra_rrb_rrr(list_a, list_b, 'a');
	else if (b > a && b > nb && nb > a)
	{
		ft_ra_rb_rr(list_a, list_b, 'a');
		sa_sb_ss(list_a, list_b, 'a');
		ft_rra_rrb_rrr(list_a, list_b, 'a');
	}
	else if (nb > a && nb > b && a > b)
		sa_sb_ss(list_a, list_b, 'a');
}

int	ft_count(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i ++;
		list = list->next;
	}
	return (i);
}

void	ft_sort_for_five_end(t_list **list_a, t_list **list_b)
{
	ft_sort_for_three(list_a, list_b);
	while (ft_count(*list_b) != 0)
	{
		if ((*list_b)->index == 0)
			ft_pa_pb(list_a, list_b, 'a');
		else
		{
			ft_pa_pb(list_a, list_b, 'a');
			ft_ra_rb_rr(list_a, list_b, 'a');
		}
	}
}

void	ft_sort_for_five(t_list **list_a, t_list **list_b, int argc)
{
	t_list	*max_min;

	max_min = *list_a;
	while (ft_count(*list_a) != 3)
	{
		if (max_min->index == 0)
		{
			max_min = max_min->next;
			ft_pa_pb(list_a, list_b, 'b');
		}
		else if (max_min->index == argc - 2)
		{
			max_min = max_min->next;
			ft_pa_pb(list_a, list_b, 'b');
		}
		else
		{
			max_min = max_min->next;
			ft_ra_rb_rr(list_a, list_b, 'a');
		}
	}
	ft_sort_for_five_end(list_a, list_b);
}
