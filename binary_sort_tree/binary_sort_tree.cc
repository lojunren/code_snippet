#include "binary_sort_tree.h"
#include <stdio.h>
#include <string.h>


BinarySortTree::~BinarySortTree()
{
    BSTree ptree = root_;
    destroy_tree(ptree);
}

int BinarySortTree::init(void *elem_arr, unsigned int arr_len, unsigned int elem_size, CMP_FUNC cmp)
{
    if (elem_arr == NULL || arr_len == 0 || elem_size == 0)
    {
        printf("init, invalid parameter!\n");
        return E_FAILURE;
    }

    for (unsigned int index = 0; index < arr_len; index ++)
    {
        char *elemS = (char *)elem_arr + index * elem_size;
        if (insert_node(elemS, elem_size, cmp) == E_FAILURE)
        {
            printf("insert node failed!\n");
            return E_FAILURE;
        }
    }

    return E_SUCCESS;
}

int BinarySortTree::destroy_tree(BSTree ptree)
{
    if (ptree != NULL)
    {
        destroy_tree(ptree->lNode);
        destroy_tree(ptree->rNode);
        free(ptree->data);
        free(ptree);
    }

    return E_SUCCESS;
}

int BinarySortTree::find_node(void *key, CMP_FUNC cmp) const
{
    if (key == NULL || cmp == NULL)
    {
        printf("find_node, invalid parameter!\n");
        return E_FAILURE;
    }

    return search_node(key, cmp, root_);
}

int BinarySortTree::insert_node(void *key, unsigned int elem_size, CMP_FUNC cmp)
{
    if (key == NULL || elem_size <= 0 || cmp == NULL)
    {
        printf("insert, invalid parameter!\n");
        return E_FAILURE;
    }

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

    memcpy(pNew->data, key, elem_size);
    pNew->lNode = NULL;
    pNew->rNode = NULL;

    //root is NULL
    if (root_ == NULL)
    {
        root_ = pNew;
    }
    else
    {
        return insert_node(cmp, pNew, root_);
    }

    return E_SUCCESS;
}

int BinarySortTree::insert_node(CMP_FUNC cmp, BSTree pNew, BSTree ptree)
{
    int result = cmp(ptree->data, pNew->data);
    if (result > 0)
    {
        if (ptree->lNode != NULL)
        {
            insert_node(cmp, pNew, ptree->lNode);
        }
        else
        {
            ptree->lNode = pNew;
        }
    }
    else if (result <= 0)
    {
        if (ptree->rNode != NULL)
        {
            insert_node(cmp, pNew, ptree->rNode);
        }
        else
        {
            ptree->rNode = pNew;
        }
    }

    return E_SUCCESS;
}

int BinarySortTree::delete_node(void *key, CMP_FUNC cmp)
{
    if (key == NULL || cmp == NULL)
    {
        printf("delete_node, invalid parameter!\n");
        return E_FAILURE;
    }

    if ( (root_ == NULL) || (search_node(key, cmp, root_) == E_FAILURE))
    {
        return E_FAILURE;
    }

    delete_node(key, cmp, root_);

    return E_SUCCESS;
}

int BinarySortTree::delete_node(void *key, CMP_FUNC cmp, BSTree &ptree)
{
    int result = cmp(ptree->data, key);

    if (result == 0)
    {
        return delete_node(ptree);
    }
    else if (result > 0)
    {
        return delete_node(key, cmp, ptree->lNode);
    }
    else
    {
        return delete_node(key, cmp, ptree->rNode);
    }

}

int BinarySortTree::delete_node(BSTree &ptree)
{
    BSTree q, s;
    if (ptree->rNode == NULL)
    {
        q = ptree;
        ptree = ptree->lNode;

        free(q->data);
        free(q);
    }
    else if (ptree->lNode == NULL)
    {
        q = ptree;
        ptree = ptree->rNode;

        free(q->data);
        free(q);
    }
    else
    {
        s = ptree->lNode;
        while (s->rNode != NULL)
        {
            s = s->rNode;
        }

        s->rNode = ptree->rNode;
        q = ptree;
        ptree = ptree->lNode;

        free(q->data);
        free(q);
    }

    return E_SUCCESS;
}

int BinarySortTree::search_node(void *key, CMP_FUNC cmp, BSTree ptree) const
{

    if (ptree != NULL)
    {
        int result = cmp(ptree->data, key);
        if (result == 0)
        {
            return E_SUCCESS;
        }
        else if (result > 0)
        {
            return search_node(key, cmp, ptree->lNode);
        }
        else
        {
            return search_node(key, cmp, ptree->rNode);
        }
    }

    return E_FAILURE;
}
