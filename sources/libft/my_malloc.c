/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:08:18 by tcardair          #+#    #+#             */
/*   Updated: 2025/05/20 18:08:26 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// How to use ?
// 1. Ininitialize
//      list = NULL;
//      list = my_malloc(list, sizeof(t_list *));
//
//      or
//
//      list = NULL;
//      something = my_malloc(&list, sizeof(t_list *));
//
// 2. Free
//      if(list)
//          my_free(list);
void	*my_malloc(t_list **list, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(1, size);
	if (!ptr)
		return (NULL);
	if (list)
	{
		if (!*list)
			*list = ft_lstnew(ptr);
		else
			ft_lstadd_back(list, ft_lstnew(ptr));
	}
	return (ptr);
}

void	my_free(t_list **list)
{
	if (list && *list)
	{
		ft_lstclear(list, free);
		*list = NULL;
	}
}

int	check_list(t_list **list, void *data)
{
	t_list	*temp;

	if (!list || !*list || !data)
		return (0);
	temp = *list;
	while (temp)
	{
		if (temp->content == data)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	my_addtolist(t_list **list, void *data)
{
	t_list	*temp;

	if (!(list && data))
		return ;
	if (check_list(list, data) == 1)
		return ;
	temp = ft_lstnew(data);
	ft_lstadd_back(list, temp);
}
