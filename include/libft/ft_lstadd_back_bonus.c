/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:39:25 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/02/08 18:40:06 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp && temp->next)
		temp = temp->next;
	temp->next = new;
}

/*#include <stdio.h>
int main()
{
	t_list *first;

	first = NULL;
	t_list a;
	t_list b;
	t_list c;
	t_list d;

	first = &a;
	a.next = &b;
	a.content = ft_strdup("soy A, aaaaa");
	b.next = &c;
	b.content = ft_strdup("soy B, bbbbb");
	c.next = NULL;
	c.content = ft_strdup("soy C, zzzzz");

	d.next = NULL;
	d.content = ft_strdup("soy D, dddddd");

	t_list *tmp;
	tmp = first;
	printf("Lista al empezar \n");
	while(tmp)
	{
		printf("%s\n", tmp->content);
		tmp = tmp->next;		
	}
	ft_lstadd_back(&first, &d);
	tmp = first;
	printf("Lista al terminar \n");
	while(tmp)
	{
		printf("%s\n", tmp->content);
		tmp = tmp->next;		
	}
}*/