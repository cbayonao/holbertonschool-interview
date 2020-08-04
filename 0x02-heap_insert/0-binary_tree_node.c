#include "binary_trees.h"

/**
 * binary_tree_node - create a new tree
 * @parent: parent node
 * @value: value of the node
 * Return: tree
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);
	node->n = value;
	node->left = NULL;
	node->right = NULL;

	if (!parent)
	{
		node->parent = NULL;
		parent = node;
		return (parent);
	}
	else
	{
		node->parent = parent;
		return (node);
	}
}
