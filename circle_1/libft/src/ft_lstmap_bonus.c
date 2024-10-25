/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmoril <jesmoril@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:27:24 by jesmoril          #+#    #+#             */
/*   Updated: 2024/09/25 20:27:26 by jesmoril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*t;

	if (!lst)
		return (0);
	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	t = new;
	t->content = f(lst->content);
	while (lst->next)
	{
		lst = lst->next;
		t->next = malloc(sizeof(t_list));
		if (!t->next)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		t->next->content = f(lst->content);
		t = t->next;
	}
	t->next = NULL;
	return (new);
}
