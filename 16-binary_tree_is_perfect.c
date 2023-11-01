#include "binary_trees.h"

/**
 * binary_tree_is_perfect -  checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 0, if tree is NULL
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height = 0, size = 0, power = 0;

	if (tree == NULL)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	height = binary_tree_height(tree);
	size = binary_tree_size(tree);

	power = _pow_recursion(2, height + 1);
	return (power - 1 == size);
}

/**
 * _pow_recursion - power of x to y
 * @x: the number
 * @y: the power
 *
 * Return: result of the pwr or -1, if y is negative
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	else
		return (x * _pow_recursion(x, y - 1));
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


/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: 0, if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_height;
	size_t r_height;

	if (tree == NULL)
		return (0);

//	l_height = binary_tree_height(tree->left);
//	r_height = binary_tree_height(tree->right);
//
//	return ((l_height > r_height ? l_height : r_height) + 1);

	l_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	r_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (l_height > r_height ? l_height : r_height);
}
