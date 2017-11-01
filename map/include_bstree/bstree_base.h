#ifndef __bstree_base_h
#define __bstree_base_h

#include <utility>
#include "bstree_node_base.h"

// 二叉搜索树
struct BSTree_base {
	BSTree_link root;
};

// 初始化二叉搜索树
inline
void tree_init(BSTree_base *tree)
{
	tree->root = NULL;
}

// 判断二叉搜索树是否为空,
inline
bool tree_is_empty(const BSTree_base *tree)
{
	return (tree->root == NULL);
}

/**
 * 用另一棵子树替换一棵子树并成为其父结点的孩子结点:
 * 用一个以v为根的子树来替换一棵以u为根的子树时,
 * 结点u的父结点就变为v的父结点, 并且最后v成为u的父结点的相应孩子.
 *
 *         q           
 *         |         |
 *         B u       E v
 *        / \       / \
 *       A   C     D   F
 *
 *              ||
 *              \/
 *         q           
 *         |         |  
 *         E v       B u
 *        / \       / \
 *       D   F     A   C
 *
 */
inline
void tree_transplant(BSTree_base *tree, BSTree_link u, BSTree_link v)
{
	if (u->parent == NULL) {            // u为树的根结点
		tree->root = v;
	} else if (u == u->parent->left) {  // u为父结点的左子树
		u->parent->left = v;
	} else {                            // u为父结点的右子树
		u->parent->right = v;
	}

    if (v != NULL)
        v->parent = u->parent;
}

/**
 * 从一棵二叉搜索树中删除一个结点z, 整个策略分为三种基本情况:
 * 1)如果z没有孩子结点, 那么只是简单的将它删除, 并修改它的父结点, 
 *   用NIL作为孩子来替换z;
 * 2)如果z只有一个孩子, 那么将这个孩子提升到树中z的位置上, 
 *   并修改z的父结点, 用z的孩子还替换z;
 * 3)如果z有两个孩子, 那么找z的后继y(一定在z的右子树中),
 *   并让y占据树中z的位置; z的原来右子树部分成为y的新的右子树,
 *   并且z的左子树成为y的新的左子树.
 *
 * a): 情况1和情况2的一部分(z只有一个右孩子)
 *        q             q
 *        |             |
 *        A z  =====>   B r
 *       / \           / \
 *     NIL  B r
 *         / \
 *
 * b): 情况2的另一部分(z只有一个左孩子)
 *        q             q
 *        |             |
 *        B z  =====>   A l
 *       / \           / \
 *    l A  NIL
 *     / \
 *
 * c): 情况3的一部分(z的后继y正好为z的右孩子)
 *           q                       q
 *           |                       |
 *           B z                     C y
 *        __/ \__     =====>      __/ \__
 *       /       \               /       \
 *    l A         C y         l A         D x
 *    /   \     /   \         /   \     /   \
 *            NIL    D x
 *                  / \
 *
 * d): 情况3的另一部分(z的后继y不是z的右孩子)
 *         q                       q                             q
 *         |                       |                             |
 *         B z                     B z       C y                 C y
 *     __/   \__    ======>    __/         /   \   =====>    __/   \__
 *    /         \             /          NIL    E r         /         \
 * l A           E r       l A                /   \      l A           E r
 * /   \       /   \       /   \           x D           /   \       /   \
 *          y C                             / \                   x D
 *          /   \                                                  / \
 *        NIL  x D                   
 *              / \
 *
 */
inline
void tree_delete(BSTree_base *tree, BSTree_link z)
{
	if (z->left == NULL)
		tree_transplant(tree, z, z->right);     // a)
	else if (z->right == NULL)          
		tree_transplant(tree, z, z->left);      // b)
	else {
		auto y = tree_minimum(z->right);
		if (y->parent != z) {
			tree_transplant(tree, y, y->right); // d)
			y->right = z->right;                // d)
			y->right->parent = y;               // d)
		} 
		tree_transplant(tree, z, y);            // c)
		y->left = z->left;                      // c)
		y->left->parent = y;                    // c)
	}
}

// 获取二叉树结点个数
inline
int tree_size(const BSTree_base *tree)
{
    return tree_size(tree->root);
}

// 交换两棵二叉树
inline 
void tree_swap(BSTree_base *tree1, BSTree_base *tree2)
{
    std::swap(tree1->root, tree2->root);
}

#endif
