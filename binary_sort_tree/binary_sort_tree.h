#ifndef _BINARY_SORT_TREE_H_
#define _BINARY_SORT_TREE_H_

#include <stdlib.h>

#define E_FAILURE -1
#define E_SUCCESS 0

typedef struct Node
{
    void *data;
    struct Node *lNode;
    struct Node *rNode;
} Node, *BSTree;

typedef int (*CMP_FUNC)(void *elem1, void *elem2);

class BinarySortTree
{
public:
    BinarySortTree(): root_(NULL) {} ;
    ~BinarySortTree();
    int delete_node(void *key, CMP_FUNC cmp);
    int find_node(void *key, CMP_FUNC cmp) const;
    int insert_node(void *key, unsigned int elem_size, CMP_FUNC cmp);
    int init(void *elem_arr, unsigned int arr_len, unsigned int elem_size, CMP_FUNC cmp);

private:
    int erase(BSTree &ptree);
    int destroy_tree(BSTree ptree);
    int insert(CMP_FUNC cmp, BSTree pNew, BSTree ptree);
    int erase_node(BSTree &ptree, void *key, CMP_FUNC cmp);
    int search_node(void *key, CMP_FUNC cmp, BSTree ptree) const;

private:
    BSTree root_;
};



#endif