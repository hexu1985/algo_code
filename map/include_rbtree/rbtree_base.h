#ifndef __rbtree_base_h
#define __rbtree_base_h

#include <utility>
#include "rbtree_node_base.h"

// 红黑树, 满足如下性质的二叉搜索树:
// 1) 每个结点或是红色的, 或是黑色的;
// 2) 根结点是黑色的;
// 3) 每个结点(NIL)是黑色的;
// 4) 如果一个结点是红色的, 则它的两个子结点都是黑色的,
//    (任何路径上不存在连续的黑色结点);
// 5) 对每个结点, 从该结点到其所有后代叶结点的简单路径上,
//    均包含相同数目的黑色结点.
struct RBTree_base {
	RBTree_link root;
    RBTree_node_base nil;
};

// 初始化红黑树
inline
void tree_init(RBTree_base *tree)
{
    RBTree_link nil = &tree->nil;
    nil->left = nil->right = nil->parent = nil;
    nil->color = RBTree_color::BLACK;
	tree->root = nil;
}

// 判断红黑树是否为空,
inline
bool tree_is_empty(const RBTree_base *tree)
{
	return (tree->root == &tree->nil);
}

// 获取红黑树的NIL结点
inline
RBTree_link tree_nil(const RBTree_base *tree)
{
    return (RBTree_link) &tree->nil;
}

/**
 * 在结点x上做左旋
 *
 *        |                     |
 *        x                     y
 *       / \       =====>      / \
 *      a   y                 x   c
 *         / \               / \
 *        b   c             a   b
 */
inline
void tree_left_rotate(RBTree_base *tree, RBTree_link x)
{
    auto y = x->right;
    x->right = y->left;
    if (y->left != tree_nil(tree)) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == tree_nil(tree)) {
        tree->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}
    
/**
 * 在结点x上做右旋
 *
 *          |                 |
 *          x                 y 
 *         / \               / \
 *        y   c    =====>   a   x
 *       / \                   / \
 *      a   b                 b   c
 */
inline
void tree_right_rotate(RBTree_base *tree, RBTree_link x)
{
    auto y = x->left;
    x->left = y->right;
    if (y->right != tree_nil(tree)) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == tree_nil(tree)) {
        tree->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->right = x;
    x->parent = y;
}

/**
 * 插入结点后恢复搜索树的红黑性质
 * ()  -> 红色结点
 * []  -> 黑色结点
 * 
 * 1) z的叔结点y是红色的
 *            |                              |          
 *           [C]                      new z (C) 
 *        __/   \__                      __/   \__      
 *       /         \       =======>     /         \
 *     (A)         (D) y              [A]         [D]
 *    /   \       /   \              /   \       /   \
 *   a    (B) z  d     e            a    (B)    d     e 
 *       /   \                          /   \
 *      b     c                        b     c          
 *
 * 2) z的叔结点y是黑色的且z是一个右孩子
 *            |                                |
 *           [C]                              [C]
 *        __/   \__                        __/   \__
 *       /         \       =======>       /         \
 *     (A)          d y                 (B)          d y
 *    /   \                            /   \
 *   a    (B) z                    z (A)    c
 *       /   \                      /   \
 *      b     c                    a     b
 *
 * 3) z的叔结点y是黑色的且z是一个左孩子
 *               |                             |
 *              [C]                           [B]
 *           __/   \__                     __/   \__
 *          /         \     =======>      /         \
 *        (B)          d y            z (A)         (C)
 *       /   \                         /   \       /   \
 *   z (A)    c                       a     b     c     d
 *    /   \
 *   a     b
 */
inline
void tree_insert_fixup(RBTree_base *tree, RBTree_link z) 
{
    auto y = tree_nil(tree);
    while (z->parent->color == RBTree_color::RED) {
        if (z->parent == z->parent->parent->left) {     // z的父结点为左子数
            y = z->parent->parent->right;
            if (y->color == RBTree_color::RED) {
                z->parent->color = RBTree_color::BLACK;         // Case 1
                y->color = RBTree_color::BLACK;                 // Case 1
                z->parent->parent->color = RBTree_color::RED;   // Case 1
                z = z->parent->parent;                          // Case 1
            } else{
                if (z == z->parent->right) {
                    z = z->parent;                              // Case 2
                    tree_left_rotate(tree, z);                  // Case 2
                }
                z->parent->color = RBTree_color::BLACK;         // Case 3
                z->parent->parent->color = RBTree_color::RED;   // Case 3
                tree_right_rotate(tree, z->parent->parent);     // Case 3
            }
        } else {                                        // z的父结点为右子数
            y = z->parent->parent->left;
            if (y->color == RBTree_color::RED) {
                z->parent->color = RBTree_color::BLACK;         // Case 1
                y->color = RBTree_color::BLACK;                 // Case 1
                z->parent->parent->color = RBTree_color::RED;   // Case 1
                z = z->parent->parent;                          // Case 1
            } else {
                if (z == z->parent->left) {
                    z = z->parent;                              // Case 2
                    tree_right_rotate(tree, z);                 // Case 2
                }
                z->parent->color = RBTree_color::BLACK;         // Case 3
                z->parent->parent->color = RBTree_color::RED;   // Case 3
                tree_left_rotate(tree, z->parent->parent);      // Case 3
            }
        }
    }
    tree->root->color = RBTree_color::BLACK;
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
void tree_transplant(RBTree_base *tree, RBTree_link u, RBTree_link v)
{
	if (u->parent == tree_nil(tree)) {  // u为树的根结点
		tree->root = v;
	} else if (u == u->parent->left) {  // u为父结点的左子树
		u->parent->left = v;
	} else {                            // u为父结点的右子树
		u->parent->right = v;
	}

    v->parent = u->parent;
}

/**
 * 删除结点后恢复搜索树的红黑性质
 *  ()  -> 红色结点
 *  []  -> 黑色结点
 * [[]] -> 双重黑色结点
 *
 * 1) x的兄弟结点w是红色的
 * 
 *                |                                 |
 *               [B]                               [D]
 *            __/   \__                         __/   \__
 *           /         \           =====>      /         \
 *      x [[A]]        (D) w                 (B)         [E]
 *        /   \       /   \                 /   \new w  /   \
 *       a     b    [C]   [E]         x [[A]]   [C]    e     f
 *                  / \   / \            / \    / \
 *                 c   d e   f          a   b  c   d   
 *
 * 2) x的兄弟结点w是黑色, 而且w的两个子结点都是黑色的
 *
 *                |                             |
 *                B c                     new x B c
 *            __/   \__                     __/   \__
 *           /         \        =====>     /         \
 *      x [[A]]        [D] w             [A]         (D)
 *        /   \       /   \             /   \       /   \
 *       a     b    [C]   [E]          a     b    [C]   [E]
 *                  / \   / \                     / \   / \
 *                 c   d e   f                   c   d e   f 
 *                                                        
 * 3) x的兄弟结点w是黑色的, w的左孩子是红色的, w的右孩子是黑色的
 *
 *                |                                |
 *                B c                              B c
 *            __/   \__                        __/   \__
 *           /         \        =====>        /         \
 *      x [[A]]        [D] w             x [[A]]        [C] new w
 *        /   \       /   \                /   \       /   \
 *       a     b    (C)   [E]             a     b     c    (D)
 *                  / \   / \                             /   \
 *                 c   d e   f                           d    [E]
 *                                                            / \
 *                                                           e   f
 *
 * 4) x的兄弟结点w是黑色的, 且w的右孩子是红色的
 *
 *                |                             |
 *                B c                           D c
 *            __/   \__                     __/   \__
 *           /         \        =====>     /         \
 *      x [[A]]        [D] w             [B]         [E]
 *        /   \       /   \             /   \        / \
 *       a     b     C c' (E)         [A]    C c'   e   f   
 *                  / \   / \         / \   / \
 *                 c   d e   f       a   b c   d    new x = T.root
 *
 */
inline
void tree_delete_fixup(RBTree_base *tree, RBTree_link x)
{
    auto w = tree_nil(tree);
    while (x != tree->root && x->color == RBTree_color::BLACK) {
        if (x == x->parent->left) {
            w = x->parent->right;
			if (w->color == RBTree_color::RED) {	                    
                w->color = RBTree_color::BLACK;                 // Case 1
                x->parent->color = RBTree_color::RED;           // Case 1
				tree_left_rotate(tree, x->parent);              // Case 1
                w = x->parent->right;                           // Case 1
			}
            if (w->left->color == RBTree_color::BLACK && w->right->color == RBTree_color::BLACK) {
                w->color = RBTree_color::RED;                   // Case 2
                x = x->parent;                                  // Case 2
            } else {
                if (w->right->color == RBTree_color::BLACK) {
                    w->left->color = RBTree_color::BLACK;       // Case 3
                    w->color = RBTree_color::RED;               // Case 3
                    tree_right_rotate(tree, w);                 // Case 3
                    w = x->parent->right;                       // Case 3
                }
                w->color = x->parent->color;                    // Case 4
                x->parent->color = RBTree_color::BLACK;         // Case 4
                w->right->color = RBTree_color::BLACK;          // Case 4
                tree_left_rotate(tree, x->parent);              // Case 4
                x = tree->root;                                 // Case 4
            }
        } else {    // x是父节点的右子树
            w = x->parent->left;
			if (w->color == RBTree_color::RED) {	                    
                w->color = RBTree_color::BLACK;                 // Case 1
                x->parent->color = RBTree_color::RED;           // Case 1
				tree_right_rotate(tree, x->parent);             // Case 1
                w = x->parent->left;                            // Case 1
			}
            if (w->left->color == RBTree_color::BLACK && w->right->color == RBTree_color::BLACK) {
                w->color = RBTree_color::RED;                   // Case 2
                x = x->parent;                                  // Case 2
            } else {
                if (w->left->color == RBTree_color::BLACK) {
                    w->right->color = RBTree_color::BLACK;      // Case 3
                    w->color = RBTree_color::RED;               // Case 3
                    tree_left_rotate(tree, w);                  // Case 3
                    w = x->parent->left;                        // Case 3
                }
                w->color = x->parent->color;                    // Case 4
                x->parent->color = RBTree_color::BLACK;         // Case 4
                w->left->color = RBTree_color::BLACK;           // Case 4
                tree_right_rotate(tree, x->parent);             // Case 4
                x = tree->root;                                 // Case 4
            }
        }
    }
    x->color = RBTree_color::BLACK;
}

/**
 * 从一棵红黑树中删除一个结点z, 整个策略分为三种基本情况:
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
 *      y A z  =====>   B x
 *       / \           / \
 *     NIL  B x
 *         / \
 *
 * b): 情况2的另一部分(z只有一个左孩子)
 *        q             q
 *        |             |
 *      y B z  =====>   A x
 *       / \           / \
 *    x A  NIL
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
 * PS: 从红黑树删除结点比二叉树多了几行代码. 多出的几行代码
 * 记录结点y的踪迹, y有可能导致红黑树性质破坏: 在结点被移除
 * 或者在树中移动之前, 必须记住y的颜色, 并且记录结点x的踪迹,
 * 将x移至树中y的原来位置, 因为结点x也可能引起红黑性质的破坏.
 */
inline
void tree_delete(RBTree_base *tree, RBTree_link z)
{
    auto x = tree_nil(tree);
    auto y = z;
    auto y_original_color = y->color;
	if (z->left == tree_nil(tree)) {
        x = z->right;
		tree_transplant(tree, z, z->right);     // a)
    } else if (z->right == tree_nil(tree)) {          
        x = z->left;
		tree_transplant(tree, z, z->left);      // b)
    } else {
		y = tree_minimum(z->right, tree_nil(tree));
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;      // x maybe nil
        } else {    // (y->parent != z)
			tree_transplant(tree, y, y->right); // d)
			y->right = z->right;                // d)
			y->right->parent = y;               // d)
		} 
		tree_transplant(tree, z, y);            // c)
		y->left = z->left;                      // c)
		y->left->parent = y;                    // c)
        y->color = z->color;                    // c)
	}
    if (y_original_color == RBTree_color::BLACK)
        tree_delete_fixup(tree, x);
}

// 获取红黑树结点个数
inline
int tree_size(const RBTree_base *tree)
{
    return tree_size(tree->root, tree_nil(tree));
}

// 交换两棵红黑树
inline 
void tree_swap(RBTree_base *tree1, RBTree_base *tree2)
{
    std::swap(tree1->root, tree2->root);
}

#endif
