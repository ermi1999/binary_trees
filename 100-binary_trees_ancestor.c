#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes.
 * @first: is a pointer to the first node.
 * @second: is a pointer to the second node.
 * Return: pointer to the common ancestor.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *temp;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second->parent)
		return (second->parent);

	if (second == first->parent)
		return (first->parent);

	if (first->parent == NULL || second->parent == NULL)
		return (NULL);

	temp = second;

	while (first->parent)
	{
		while (second->parent)
		{
			if (first->parent == second->parent)
				return (first->parent);
			second = second->parent;
		}
		second = temp;
		first = first->parent;
	}
	return (NULL);
}
