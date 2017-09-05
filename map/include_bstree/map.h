
// 删除tree中key为k的所有的结点
template <typename K, typename V, typename Deleter = std::default_delete<BSTree_map_node<K,V>>>
int tree_remove(BSTree_map<K,V> *tree, const K &k, Deleter del = Deleter())
{
    int i = 0;
    BSTree_map_node<K,V> *x = NULL;
    while (true) {
        x = tree_search(tree, k);
        if (x == NULL)
            return i;

        tree_delete(tree, x);
        del(x);
        ++i;
    }
}

