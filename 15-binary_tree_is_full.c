#include "binary_trees.h"

/**
 * is_not_full - checks if the the tree is full.
 * @tree: pointer to the root of the node.
 * @not_full: pointer to the counter of not_full.
 * Return: nothing.
 */

void is_not_full(const binary_tree_t *tree, int *not_full)
{
	if (tree == NULL)
		return;
	if ((tree->left && !tree->right) || (!tree->left && tree->right))
		(*not_full)++;
	is_not_full(tree->left, not_full);
	is_not_full(tree->right, not_full);
}

/**
 * binary_tree_is_full - checks if a binary tree is full.
 * @tree: is a pointer to the root node of the tree to check.
 * Return: 1 if the tree is full 0 otherwise.
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int not_full = 0;

	is_not_full(tree, &not_full);
	if (not_full)
		return (0);
	return (1);
}

