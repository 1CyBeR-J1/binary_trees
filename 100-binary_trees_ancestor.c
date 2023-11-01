#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes
 * NULL, If no common ancestor was found
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	const binary_tree_t *node1 = first;

	while (node1 != NULL)
	{
		const binary_tree_t *node2 = second;

		while (node2 != NULL)
		{
			if (node1 == node2)
				return ((binary_tree_t *)node1);
			node2 = node2->parent;
		}
		node1 = node1->parent;
	}

	return (NULL);
}
