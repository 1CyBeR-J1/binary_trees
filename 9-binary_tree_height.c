#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * tree: pointer to the root node of the tree to measure the height
 *
 * Return: 0, if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	l_height = binary_tree_height(tree->left);
	r_height = height_tree_height(tree->right);

	return ((l_height > r_height ? l_height : r_height) + 1);
}