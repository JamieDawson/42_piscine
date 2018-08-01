/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:11:08 by jadawson          #+#    #+#             */
/*   Updated: 2017/11/10 14:11:12 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_suffix_prefix(t_btree *root, void (*applyf)(void *))
{
	if (root == 0)
		return ;
	if (root->left)
		btree_apply_prefix(root->left, applyf);
	if (root->right)
		btree_apply_prefix(root->right, applyf);
	if (root->item)
		applyf(root->item);
}
