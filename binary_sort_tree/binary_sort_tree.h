#ifndef _BINARY_SORT_TREE_H_
#define _BINARY_SORT_TREE_H_


#define E_FAILURE -1
#define E_SUCCESS 0

typedef struct Node
{
    void *data;
    struct Node *lNode;
    struct Node *rNode;
} Node, *BSTree;

typedef int (*cmp)(void *elem1, void *elem2) CMP_FUNC;

class BinarySortTree
{
public:
    BinarySortTree(): root_(NULL) {}
    ~BinarySortTree();
    int init(void *elem_arr, int arr_len, int elem_size, CMP_FUNC cmp);
    int insert_node(void *key, int elem_size, CMP_FUNC cmp);
    int delete_noe(void *key, CMP_FUNC cmp);
    int find_node(void *key, CMP_FUNC cmp) const;

private:
    int erase(BSTree &ptree);
    int destroy_tree(BSTree ptree);
    int delete(BSTree &ptree, void *key, CMP_FUNC cmp);
    int search_node(BSTree ptree, BSTree parent, BSTree &p, void *key, CMP_FUNC cmp) const;

private:
    BSTree root_;
};



#endif