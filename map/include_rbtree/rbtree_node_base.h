#ifndef __rbtree_node_base_h
#define __rbtree_node_base_h

#include <stddef.h>

typedef struct RBTree_node_base *RBTree_link;

enum class RBTree_color {
    RED = 0,
    BLACK = 1,
};

// 红黑树结点, 包含指向父结点的指针,
// 以及指向左右子结点的指针,
// 不包含数据
struct RBTree_node_base {
	RBTree_link parent;
	RBTree_link left;
	RBTree_link right;
    RBTree_color color;
} RBTree_node_base;

// 返回以结点x为根的子树的最小元素的指针,
inline
RBTree_link tree_minimum(RBTree_link x, RBTree_link nil)
{
	while (x->left != nil)
		x = x->left;
	return x;
}

// 返回以结点x为根的子树的最大元素的指针,
inline
RBTree_link tree_maximum(RBTree_link x, RBTree_link nil)
{
	while (x->right != nil)
		x = x->right;
	return x;
}

// 返回以结点x的后继结点
inline
RBTree_link tree_successor(RBTree_link x, RBTree_link nil)
{
	if (x->right != nil)
		return tree_minimum(x->right, nil);

	auto y = x->parent;
	while (y != nil && x == y->right) {
		x = y;
		y = y->parent;
	}	
	return y;
}

// 返回以结点x的前驱结点
inline
RBTree_link tree_predecessor(RBTree_link x, RBTree_link nil)
{
	if (x->left != nil)
		return tree_maximum(x->left, nil);

	auto y = x->parent;
	while (y != nil && x == y->left) {
		x = y;
		y = y->parent;
	}	
	return y;
}

// 返回以结点x为根结点的子树的结点个数
inline
int tree_size(RBTree_link x, RBTree_link nil)
{
    if (x == nil)
        return 0;

    return 1+tree_size(x->left, nil)+tree_size(x->right, nil);
}

#endif
