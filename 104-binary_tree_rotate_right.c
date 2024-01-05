#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree.
 * @tree: is a pointer to the root node of the tree to rotate
 * Return: pointer to the new root.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *root;

	if (tree == NULL)
		return (NULL);

	root = tree->left;
	if (root->right)
		root->right->parent = tree;
	tree->left = root->right;

	if (root)
		root->parent = tree->parent;
	tree->parent = root;
	root->right = tree;

	return (root);
}
