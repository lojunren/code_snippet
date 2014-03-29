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
    BinarySortTree(): ptree_(NULL) {}
    ~BinarySortTree();
    int init(void *elem_arr, int arr_len, int elem_size);
    int insert_node(void *elemS, int elem_size, CMP_FUNC cmp);
    int delete_noe(void *elemS, int elem_size, CMP_FUNC cmp);
    int find_node(BSTree ptree, BSTree parent, BSTree &p, void *elemS, int elem_size, CMP_FUNC cmp);

    void traverse_tree();

private:
    void delete_tree();

private:
    BSTree ptree_;
};



#endif