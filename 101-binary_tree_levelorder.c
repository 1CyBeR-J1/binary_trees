#include "binary_trees.h"

/**
 * print_level - print the node at a level
 * @tree: pointer to the root node of the tree to tranverse
 * @func: pointer to the function to call node
 *
 * Return: Nothing
 */

void print_level(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else
	{
		print_level(tree->left, func, level - 1);
		print_level(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal
 *
 * @tree:  pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * The value in the node must be passed as a parameter to this function.
 *
 * Return: Nothing
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level, i;

	if (tree == NULL || func == NULL)
		return;

	level = binary_tree_height(tree) + 1;

	for (i = 1; i <= level; i++)
		print_level(tree, func, i);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to
 * measure the height
 *
 * Return: 0, if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_height, r_height;

	if (tree == NULL)
		return (0);

	l_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	r_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (l_height > r_height ? l_height : r_height);
}
