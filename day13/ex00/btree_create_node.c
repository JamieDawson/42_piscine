/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:30:28 by jadawson          #+#    #+#             */
/*   Updated: 2017/11/10 11:30:38 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree		*btree_create_node(void *item)
{
	t_btree *parent;

	parent = malloc(sizeof(t_btree));
	parent->item = item;
	parent->left = NULL;
	parent->right = NULL;
	return (parent);
}
