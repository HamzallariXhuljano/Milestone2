/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:03:31 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/09 21:34:05 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap	*fft_lstnew(int	content)
{
	t_swap	*newnode;

	newnode = (t_swap *)malloc(sizeof(t_swap));
	if (newnode == NULL)
		return (NULL);
	newnode -> content = content;
	newnode -> next = NULL;
	return (newnode);
}
void	free_list(t_swap *swap)
{
	t_swap	*tmp;

	while(swap)
	{
		tmp = swap;
		swap = swap->next;
		free(tmp);
	}
}
void	free_one(t_swap **swap)
{
	t_swap *tmp;

	if (swap && *swap)
	{
		tmp = *swap;
		*swap = tmp->next;
		free(tmp);
	}
}

void	print_lst(t_swap *swap)
{
	t_swap	*tmp;
	tmp = swap;
	while (tmp)
	{
		if(tmp->next == NULL)
		{
			ft_printf("%d\n",tmp -> content);
			break;
		}
		ft_printf("%d--",tmp -> content);
		tmp = tmp -> next;
	}
}

t_swap	*lastnode(t_swap **swap)
{
	t_swap	*tmp;

	tmp = *swap;
	if(!tmp || !tmp->next)
		return (NULL);
	while(tmp->next)
		tmp = tmp->next;
	return(tmp);
}

t_swap	*lastnode1(t_swap **swap)
{
	t_swap	*tmp;

	tmp = *swap;
	if(!tmp || !tmp->next)
		return (NULL);
	while(tmp->next->next)
		tmp = tmp->next;
	return(tmp);
}
int	fft_lstsize(t_swap *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}

int	index_a(t_swap *a, int n)
{
	int	i;
	t_swap	*tmp;

	i = 0;
	tmp = a;
	while(tmp->next)
	{
		if(tmp->content < n && (tmp->next->content > n))
			return (i + 1);
		i++;
		tmp = tmp->next;
	}
	if (tmp->content < n)
		return (i + 1);
	return (0);
}
