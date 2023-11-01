#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 0, if tree is NULL
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree);

	return (binary_tree_is_complete_recr(tree, 0, size));
}

/**
 * binary_tree_is_complete_recr - checks if binary tree is complet
 * @tree: pointer to the root of the tree
 * @i: node index
 * @size: size of nodes in the tree
 *
 * Return: 1, if tree is complete
 *         0, if not complete
 */

int binary_tree_is_complete_recr(const binary_tree_t *tree, size_t i,
		size_t size)
{
	if (tree == NULL)
		return (1);

	if (i >= size)
		return (0);

	return (binary_tree_is_complete_recr(tree->left, 2 * i + 1, size) &&
		binary_tree_is_complete_recr(tree->right, 2 * i + 2, size));
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: 0, if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
