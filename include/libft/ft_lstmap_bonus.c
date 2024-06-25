/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:55:57 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/02/08 18:56:48 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_rt;
	t_list	*aux;
	t_list	*pt;
	void	*context;

	pt = lst;
	lst_rt = NULL;
	while (pt)
	{
		context = f(pt->content);
		if (!context)
			ft_lstclear(&lst_rt, del);
		if (!context)
			return (NULL);
		aux = ft_lstnew(context);
		if (!aux)
			ft_lstclear(&lst_rt, del);
		if (!aux)
			return (free(context), NULL);
		ft_lstadd_back(&lst_rt, aux);
		pt = pt->next;
	}
	return (lst_rt);
}
