/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:19:32 by wmozella          #+#    #+#             */
/*   Updated: 2022/03/11 20:11:07 by wmozella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char	*str);
int		main(int argc, char **argv);
void	ft_create_list_a(int argc, char **argv, int *arr, t_list **list_a);
void	ft_put_back(t_list **list, long int i);
t_list	*ft_create_list(long int i);
void	sort_arr(int *arr, int argc);
void	ft_check_doublicate(int argc, char **argv);
void	ft_check_sort(t_list **list_a);
void	ft_index(int *arr, int argc, t_list **list_a);
void	ft_free(t_list **list);
void	ft_rotate(t_list **list);
void	ft_ra_rb_rr(t_list **list_a, t_list **list_b, char c);
void	ft_reverse_rotate(t_list **list);
void	ft_rra_rrb_rrr(t_list **list_a, t_list **list_b, char c);
void	ft_swap(t_list **list);
void	sa_sb_ss(t_list **list_a, t_list **list_b, char c);
void	ft_list_out(t_list **list_out, t_list **list_in);
void	ft_pa_pb(t_list **list_a, t_list **list_b, char c);
void	ft_sort(t_list **list_a, t_list **list_b, int argc);
void	ft_sort_for_three(t_list **list_a, t_list **list_b);
int		ft_count(t_list *list);
void	ft_sort_for_five_end(t_list **list_a, t_list **list_b);
void	ft_sort_for_five(t_list **list_a, t_list **list_b, int argc);
int		ft_max(t_list **list_b, int i);
void	ft_sort_b(t_list **list_a, t_list **list_b, int argc);
void	ft_sort_for_100(t_list **list_a, t_list **list_b, int argc);
void	ft_sort_for_500(t_list **list_a, t_list **list_b, int argc);

#endif