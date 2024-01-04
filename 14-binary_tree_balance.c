#include "binary_trees.h"

/**
 * get_height - gets the height of a binary tree node.
 * @tree: pointer to the root node.
 * @Return: the height of the node.
 */
int get_height(const binary_tree_t *tree)
{
	int h_left, h_right;

	if (tree == NULL)
		return (-1);

	h_left = tree->left ? 1 + get_height(tree->left) : 0;
	h_right = tree->right ? 1 + get_height(tree->right) : 0;

	return ((h_left > h_right) ? h_left : h_right);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the balance factor.
 * Return: the balance.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int h_left, h_right;

	if (tree == NULL)
		return (0);
	h_left = get_height(tree->left);
	h_right = get_height(tree->right);
	printf("%d : %d\n", h_left, h_right);
	return (h_left - h_right);
}
