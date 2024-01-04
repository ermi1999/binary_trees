#include "binary_trees.h"

/**
 * is_perfect - checks if the tree is a perfect tree.
 * @tree: pointer to the root of the tree.
 * @depth: the depth of the left side of the tree.
 * @level: the current level.
 * Return: 1 if it is perfect 0 otherwise.
 */

int is_perfect(const binary_tree_t *tree, int depth, int level)
{
	if (tree == NULL)
		return (1);

	if (!tree->left && !tree->right)
	{
		if (depth == level + 1)
			return (1);
		else
			return (0);
	}

	if (!tree->left || !tree->right)
		return (0);

	return ((is_perfect(tree->left, depth, level + 1) &&
				is_perfect(tree->right, depth, level + 1)) ? 1 : 0);
}

/**
 * find_depth - finds the depth of the left side of the tree.
 * @tree: is a pointer to the root node.
 * Return: the depth.
 */
int find_depth(const binary_tree_t *tree)
{
	int depth = 0;

	while (tree != NULL)
	{
		depth++;
		tree = tree->left;
	}
	return (depth);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if binary tree is perfect otherwise 0.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth;

	if (tree == NULL)
		return (0);

	depth = find_depth(tree);

	return (is_perfect(tree, depth, 0));
}

