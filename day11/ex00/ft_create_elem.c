/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:32:03 by jadawson          #+#    #+#             */
/*   Updated: 2017/11/08 16:18:15 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list *ft_create_elem(void *data)
{
	t_list	*list;

	list = malloc (sizeof(t_list));
	if(list)
	{
		list->data = data;
		list->next = NULL;
	}
	return (list);
}
