#include "binary_trees.h"

/**
 * count_nodes - counts the nodes with at least 1 child in a binary tree.
 * @tree: a pointer to the root node of the tree to count the number of nodes.
 * @count: a pointer to the counter.
 * Return: nothing.
 */

void count_nodes(const binary_tree_t *tree, size_t *count)
{
	if (tree == NULL)
		return;
	count_nodes(tree->left, count);
	count_nodes(tree->right, count);
	if (tree->right || tree->left)
		(*count)++;
}

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: a pointer to the root node of the tree to count the number of nodes
 * Return: the count of the nodes.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree == NULL)
		return(0);
	count_nodes(tree, &count);
	return (count);
}

