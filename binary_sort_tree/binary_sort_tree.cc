#include "binary_sort_tree.h"
#include <stdio.h>
#include <stdlib.h>


BinarySortTree::~BinarySortTree()
{
    BSTree ptree = root_;
    destroy_tree(ptree);
}

int BinarySortTree::init(void *elem_arr, int arr_len, int elem_size)
{
    if (elem_arr == NULL || arr_len <= 0 || elem_size <= 0)
    {
        printf("init, invalid parameter!\n");
        return E_FAILURE;
    }

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

int BinarySortTree::insert_node(void *key, int elem_size, CMP_FUNC cmp)
{
    if (key == NULL || elem_size <= 0 || cmp == NULL)
    {
        printf("insert, invalid parameter!\n")
        return E_FAILURE;
    }

    BSTree ptree = NULL;
    if (search_node(root_, NULL, ptree, key, cmp) == E_FAILURE)
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
        memcpy(pNew->data, key, elem_size);

        //root node
        if (ptree = NULL)
        {
            ptree = pNew;
        }
        else if (cmp(key, root_->lNode->node) < 0)
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

int BinarySortTree::delete_node(void *key, CMP_FUNC cmp)
{
    if (key == NULL ||  cmp == NULL)
    {
        printf("delete, invalid parameter!\n")
        return E_FAILURE;
    }

    BSTree ptree = root_;
    return delete(ptree, elem_size, cmp);

}

int BinarySortTree::destroy_tree(BSTree ptree)
{
    if(ptree != NULL)
    {
        destroy_tree(ptree->lNode);
        destroy_tree(ptree->lRight);
        free(ptree->data);
        free(ptree);
    }
}

int BinarySortTree::delete(BSTree &ptree, void *key, CMP_FUNC cmp)
{
    if (ptree == NULL)
    {
        printf("delete, ptree is NULL! \n");
        return E_FAILURE;
    }
    else
    {
        int result = cmp(ptree->data, key);
        if (result == 0)
        {
            return erase(ptree);
        }
        else if (result > 0)
        {
            return delete(ptree->lNode, key, cmp);
        }
        else
        {
            return delete(ptree->rNode, key, cmp);
        }
    }
}

int BinarySortTree::erase(BSTree &ptree)
{
    BSTree p, q;
    if (ptree->lNode == NULL)
    {
        p = ptree;
        ptree = p->rNode;
        free(p->data);
        free(p);
    }
    else if (p->rNode == NULL)
    {
        p = ptree;
        ptree = p->lNode;
        free(p->data);
        free(p);
    }
    else
    {
        q = ptree->lNode;

        while (q->rNode)
        {
            q = q->rNode;
        }

        q->rNode = ptree->rNode;
        p = ptree;
        ptree = ptree->lNode;
        free(p->data);
        free(p);
    }

    return E_SUCCESS;
}

int BinarySortTree::find_node(void *key, CMP_FUNC cmp)
{
    if (key == NULL || cmp == NULL)
    {
        printf("find_node, invalid parameter!\n");
        return E_FAILURE;
    }

    BSTree p;
    BSTree ptree = root_;
    return search_node(ptree, NULL, p, key, cmp);
}


int BinarySortTree::search_node(BSTree ptree, BSTree parent, BSTree &p, void *key, CMP_FUNC cmp)
{
    if (key == NULL || cmp == NULL)
    {
        printf("search_node, invalid parameter!\n");
        return E_FAILURE;
    }

    if (ptree == NULL)
    {
        p = parent;
        printf("search_node failed !\n");
        return E_FAILURE;
    }

    int result = cmp(ptree->data, key);
    if (result == 0)
    {
        p = ptree;
        return E_SUCCESS;
    }
    else if (result > 0)
    {
        return search_node(ptree->lNode, parent, p, key, elem_size);
    }
    else
    {
        return search_node(ptree->rNode, parent, p, key, elem_size);
    }

}
