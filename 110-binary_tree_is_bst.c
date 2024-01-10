#include "binary_trees.h"
/**
 * find_max - finds the maximum value in the tree.
 * @tree: a pinter to the root of the tree.
 * Return: the maximum value.
 */
int find_max(const binary_tree_t *tree)
{
	int left_max, right_max, value;

	if (tree == NULL)
		return (0);
	left_max = find_max(tree->left);
	right_max = find_max(tree->right);

	value = tree->n;
	if (left_max > value)
		value = left_max;
	if (right_max > value)
		value = right_max;

	return (value);
}

/**
 * find_min - finds the minimum value in a binary tree.
 * @tree: is a pointer to the root tree.
 * Return: the minimum value.
 */
int find_min(const binary_tree_t *tree)
{
	int left_min, right_min, value;

	if (tree == NULL)
		return (1000000000);

	left_min = find_min(tree->left);
	right_min = find_min(tree->right);

	value = tree->n;
	if (left_min < value)
		value = left_min;
	if (right_min < value)
		value = right_min;

	return (value);
}

/**
 * is_bst - checks if the tree is a valid binary tree.
 * @tree: is apointer to the root tree.
 * Return: 0 if the tree is not valid 1 if it is valid.
 */
int is_bst(const binary_tree_t *tree)
{
	int left_max, right_min;

	if (tree == NULL)
		return (1);

	left_max = find_max(tree->left);
	right_min = find_min(tree->right);

	if (left_max >= tree->n || right_min <= tree->n)
		return (0);

	return (is_bst(tree->left) && is_bst(tree->right));
}

/**
 * binary_tree_is_bst - checks if the tree is a valid binary tree.
 * @tree: is a pointer to the root of the tree.
 * Return: 0 if the tree is not valid 1 if it is valid.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst(tree));
}
