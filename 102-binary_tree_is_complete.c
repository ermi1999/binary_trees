#include "binary_trees.h"

/**
 * count_tree - counts the nodes in the tree.
 * @tree: is a pointer to root node.
 * Return: The count.
 */
int count_tree(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + count_tree(tree->left) + count_tree(tree->right));
}

/**
 * is_complete - checks if the tree is complete.
 * @tree: is a pointer to the root of the tree.
 * @index: the current index to keep track of if
 * it is passed from the value of number of nodes.
 * @number_of_nodes: the count of the number of nodes in the tree.
 * Return: 1 if it is complete 0 otherwise.
 */

int is_complete(const binary_tree_t *tree, int index, int number_of_nodes)
{
	if (tree == NULL)
		return (1);

	if (index >= number_of_nodes)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, number_of_nodes) &&
			is_complete(tree->right, 2 * index + 2, number_of_nodes));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete.
 * @tree: is a pointer to the root node of the tree to check.
 * Return: 1 if the tree is complete otherwise 0.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_complete(tree, 0, count_tree(tree)));
}
