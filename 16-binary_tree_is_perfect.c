#include "binary_trees.h"

/**
 * binary_tree_is_perfect -  checks if a binary tree is perfect
 * tree: pointer to the root node of the tree to check
 *
 * Return: 0, if tree is NULL
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int l_height;
	int r_height;

	if (tree == NULL)
		return (0);

	l_height = binary_tree_is_perfect(tree->left);
	r_height = binary_tree_is_perfect(tree->right);

	if (l_height == r_height)
	{
		if (tree->left == NULL && tree->right == NULL)
			return (1);

		return (binary_tree_is_perfect(tree->left) &&
			binary_tree_is_perfect(tree->right));
	}

	return (0);
}

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

