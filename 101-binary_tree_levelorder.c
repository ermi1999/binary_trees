#include "binary_trees.h"

/**
 * print_level - prints an the tree values using their level.
 * @tree: is a pointer to the root node of the tree to traverse..
 * @i: is the level count.
 * @func: is a pointer to a function to call for each node.
 */
void print_level(const binary_tree_t *tree, size_t i, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (i == 0)
		func(tree->n);
	else
	{
		print_level(tree->left, i - 1, func);
		print_level(tree->right, i - 1, func);
	}
}

/**
 * get_height - gets the height of the tree.
 * @tree: is a pointer to the root of the tree.
 * Return: The tree height.
 */

size_t get_height(const binary_tree_t *tree)
{
	size_t h_left, h_right;

	h_left = tree->left ? 1 + get_height(tree->left) : 0;
	h_right = tree->right ? 1 + get_height(tree->left) : 0;

	return (h_left > h_right ? h_left : h_right);
}

/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal.
 * @tree: is a pointer to the root node of the tree to traverse.
 * @func: is a pointer to a function to call for each node.
 * Return: nothing.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (tree == NULL)
		return;

	height = get_height(tree);

	for (i = 0; i <= height; i++)
		print_level(tree, i, func);
}
