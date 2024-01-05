#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree.
 * @tree: a pointer to the root node of the tree to rotate.
 * Return: a pointer to the new root.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp;

	if (tree == NULL)
		return (NULL);

	temp = tree->right;
	if (temp->left)
		temp->left->parent = tree;
	tree->right = temp->left;
	if (temp)
		temp->parent = tree->parent;
	tree->parent = temp;
	temp->left = tree;

	return (temp);
}
