/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:32:35 by wmozella          #+#    #+#             */
/*   Updated: 2022/03/07 22:18:02 by wmozella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **list)
{
	t_list	*end;
	t_list	*tmp;

	end = (*list);
	tmp = (*list);
	(*list) = (*list)->next;
	while (end->next != NULL)
		end = end->next;
	end->next = tmp;
	end->next->next = NULL;
}

void	ft_ra_rb_rr(t_list **list_a, t_list **list_b, char c)
{
	if (c == 'a')
	{
		ft_rotate(list_a);
		write(1, "ra\n", 3);
	}
	else if (c == 'b')
	{
		ft_rotate(list_b);
		write(1, "rb\n", 3);
	}
	else
	{
		ft_rotate(list_a);
		ft_rotate(list_b);
		write(1, "rr\n", 3);
	}
}

void	ft_reverse_rotate(t_list **list)
{
	t_list	*head;
	t_list	*tmp;

	head = (*list);
	while (head->next->next != NULL)
		head = head->next;
	tmp = head->next;
	head->next = NULL;
	tmp->next = (*list);
	(*list) = tmp;
}

void	ft_rra_rrb_rrr(t_list **list_a, t_list **list_b, char c)
{
	if (c == 'a')
	{
		ft_reverse_rotate(list_a);
		write(1, "rra\n", 4);
	}
	else if (c == 'b')
	{
		ft_reverse_rotate(list_b);
		write(1, "rrb\n", 4);
	}
	else
	{
		ft_reverse_rotate(list_a);
		ft_reverse_rotate(list_b);
		write(1, "rrr\n", 4);
	}
}
