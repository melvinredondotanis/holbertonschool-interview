#include "binary_trees.h"

/**
 * binary_tree_size - goes through a binary tree using pre-order traversal
 * @tree: parent of node.
 * Return: nothing.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * insert_node - insert the new node to correct position
 * @root: double pointer to root of max heap
 * @node: new node to insert
 */
void insert_node(heap_t **root, heap_t *node)
{
	heap_t *aux = *root;
	size_t size, mask;

	size = binary_tree_size(aux) + 1;

	for (mask = 1; mask <= size; mask <<= 1)
		;
	mask >>= 2;

	while (mask > 0)
	{
		if (size & mask)
		{
			if (aux->right)
				aux = aux->right;
			else
			{
				aux->right = node;
				node->parent = aux;
				aux = NULL;
			}
		}
		else
		{
			if (aux->left)
				aux = aux->left;
			else
			{
				aux->left = node;
				node->parent = aux;
				aux = NULL;
			}
		}

		if (!aux)
			return;
		mask >>= 1;
	}
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: a double pointer to the root node of the Heap
 * @value: value store in the node to be inserted
 * Return: a pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;
	int temp;

	if (!root)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (!(*root))
	{
		*root = new_node;
		return (new_node);
	}

	insert_node(root, new_node);

	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		temp = new_node->parent->n;
		new_node->parent->n = new_node->n;
		new_node->n = temp;
		new_node = new_node->parent;
	}

	return (new_node);
}
