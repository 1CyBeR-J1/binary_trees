#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1, if tree is a valid BST
 *         0, if not valid BST or tree is NULL
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return(binary_tree_bst_valid(tree, INT_MIN, INT_MAX));
}

/**
 * binary_tree_bst_valid - checks if its a valid BST
 * @tree: pointer to the root node of the tree
 * @min: minimum value for the current node
 * @max: maximum value for the current node
 *
 * Return: 1 if valid BST, 0 otherwise
 */

int binary_tree_bst_valid(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (binary_tree_bst_valid(tree->left, min, tree->n - 1) &&
		binary_tree_bst_valid(tree->right, tree->n + 1, max));
}
