#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (left_height > right_height ? left_height + 1 : right_height + 1);
}

/**
 * binary_tree_balance - Measures balance factor of a binary tree
 * @tree: tree to go through
 * Return: balanced factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    int left_height = (int)binary_tree_height(tree->left);
    int right_height = (int)binary_tree_height(tree->right);

    return left_height - right_height;
}

/**
 * tree_is_perfect - function that says if a tree is perfect or not
 * it has to be the same quantity of levels in left as right, and also
 * each node has to have 2 nodes or none
 * @tree: tree to check
 * @height: height of the tree
 * @level: current level
 * Return: 1 if is perfect, 0 otherwise
 */
int tree_is_perfect(const binary_tree_t *tree, int height, int level)
{
    if (tree == NULL)
        return 1;

    if (tree->left == NULL && tree->right == NULL)
        return (height == level + 1);

    if (tree->left == NULL || tree->right == NULL)
        return 0;

    return tree_is_perfect(tree->left, height, level + 1) &&
           tree_is_perfect(tree->right, height, level + 1);
}

/**
 * binary_tree_is_perfect - perfect or not a tree
 * @tree: tree to check
 * Return: 1 is it is or 0 if not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    int height = (int)binary_tree_height(tree);
    return tree_is_perfect(tree, height, 0);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    if (tree->left && tree->left->n > tree->n)
        return (0);

    if (tree->right && tree->right->n > tree->n)
        return (0);

    if (!binary_tree_is_heap(tree->left) || !binary_tree_is_heap(tree->right))
        return (0);

    return (1);
}
