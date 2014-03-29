#include "binary_sort_tree.h"
#include <stdio.h>
#include <stdlib.h>


BinarySortTree::~BinarySortTree()
{
    delete_tree();
}

int BinarySortTree::init(void *elem_arr, int arr_len, int elem_size)
{
    if (elem_arr == NULL || arr_len <= 0 || elem_size <= 0)
    {
        printf("init, invalid parameter!\n");
        return E_FAILURE;
    }

    int elem_length = arr_len / elem_size;
    ptree_ = (BSTree)malloc(sizeof(NODE) * elem_length);
    if (ptree_ == NULL)
    {
        printf("init, malloc function failed!\n");
        return E_FAILURE;
    }
    memset(ptree_, 0, sizeof(NODE) * elem_length);

    for (int offset = 0; offset < arr_len; offset += elem_size)
    {
        void *elemS = (char *)elem_arr + offset;
        if (insert_node(elemS, elem_size) == E_FAILURE)
        {
            printf("insert node failed!\n");
            return E_FAILURE;
        }
    }

    return E_SUCCESS;
}

int BinarySortTree::insert(void *elemS, int elem_size, CMP_FUNC cmp)
{
    if (elemS == NULL || elem_size <= 0 || cmp == NULL)
    {
        printf("insert, invalid parameter!\n")
        return E_FAILURE;
    }

    BSTree ptree = NULL;
    if (find_node(ptree_, NULL, ptree, elemS, elem_size, cmp) == E_FAILURE)
    {
        BSTree pNew = (BSTree)malloc(sizeof(Node));
        if (pNew == NULL)
        {
            printf("insert, alloc function failed!\n");
            return E_FAILURE;
        }

        pNew->data = malloc(elem_size);
        if (pNew->data == NULL)
        {
            printf("insert, failed on malloc function!\n");
            return E_FAILURE;
        }
        memcpy(pNew->data, elemS, elemS);

        //root node
        if (ptree = NULL)
        {
            ptree = pNew;
        }
        else if (cmp(elemS, ptree_->lNode->node) < 0)
        {
            ptree->lNode = pNew;
        }
        else
        {
            ptree->lRight = pNew;
        }
    }
    else
    {
        printf("element exsit!\n");
    }

    return E_SUCCESS;
}

int BinarySortTree::delete(void *elemS, int elem_size, CMP_FUNC cmp)
{
    if (elemS == NULL || elem_size <= 0 || cmp == NULL)
    {
        printf("delete, invalid parameter!\n")
        return E_FAILURE;
    }

}


int BinarySortTree::find_node(BSTree ptree, BSTree parent, BSTree &p, void *elemS, int elem_size, CMP_FUNC cmp)
{
    if (elemS == NULL || elem_size <= 0 || cmp == NULL || ptree == NULL)
    {
        printf("find_node, invalid parameter!\n")
        return E_FAILURE;
    }

    if (ptree == NULL)
    {
    	p = parent;
        printf("find_node failed !\n");
        return E_FAILURE;
    }

    int result = cmp(ptree->data, elemS);
    if (result == 0)
    {
    	p = ptree;
    	return E_SUCCESS;
    }
    else if(result > 0)
    {
    	return find_node(ptree->lNode, parent, p, elemS, elem_size);
    }
    else
    {
    	return find_node(ptree->rNode, parent, p, elemS, elem_size);
    }


}

//middle order traverse
void BinarySortTree::traverse_tree()
{

}

void BinarySortTree::delete_tree()
{

}
