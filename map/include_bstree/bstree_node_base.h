#ifndef __bstree_node_base_h
#define __bstree_node_base_h

#include <stddef.h>

typedef struct BSTree_node_base *BSTree_link;

// 二叉搜索树结点, 包含指向父结点的指针,
// 以及指向左右子结点的指针,
// 不包含数据
struct BSTree_node_base {
	BSTree_link parent;
	BSTree_link left;
	BSTree_link right;
} BSTree_node_base;

// 返回以结点x为根的子树的最小元素的指针,
inline
BSTree_link tree_minimum(BSTree_link x)
{
	while (x->left != NULL)
		x = x->left;
	return x;
}

// 返回以结点x为根的子树的最大元素的指针,
inline
BSTree_link tree_maximum(BSTree_link x)
{
	while (x->right != NULL)
		x = x->right;
	return x;
}

// 返回以结点x的后继结点
inline
BSTree_link tree_successor(BSTree_link x)
{
	if (x->right != NULL)
		return tree_minimum(x->right);

	auto y = x->parent;
	while (y != NULL && x == y->right) {
		x = y;
		y = y->parent;
	}	
	return y;
}

// 返回以结点x的前驱结点
inline
BSTree_link tree_predecessor(BSTree_link x)
{
	if (x->left != NULL)
		return tree_maximum(x->left);

	auto y = x->parent;
	while (y != NULL && x == y->left) {
		x = y;
		y = y->parent;
	}	
	return y;
}

// 返回以结点x为根结点的子树的结点个数
inline
int tree_size(BSTree_link x)
{
    if (x == NULL)
        return 0;

    return 1+tree_size(x->left)+tree_size(x->right);
}

#endif
