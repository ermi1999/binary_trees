#include "binary_trees.h"

/**
 * count_size - measures the size of a binary tree.
 * @tree: is a pointer to the root node of the tree to measure the size.
 * @size: a pointer to the counter of the size.
 * Return: nothing.
 */
void count_size(const binary_tree_t *tree, size_t *size)
{
	if (tree == NULL)
		return;
	count_size(tree->left, size);
	count_size(tree->right, size);
	(*size)++;
}

/**
 * binary_tree_size - measures the size of a binary tree.
 * @tree: is a pointer to the root node of the tree to measure the size.
 * Return: the size of the tree.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);
	count_size(tree, &size);
	return (size);	
}
