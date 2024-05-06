#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treemap.h"

typedef struct TreeNode TreeNode;


struct TreeNode {
    Pair* pair;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
};

struct TreeMap {
    TreeNode * root;
    TreeNode * current;
    int (*lower_than) (void* key1, void* key2);
};

int is_equal(TreeMap* tree, void* key1, void* key2){
    if(tree->lower_than(key1,key2)==0 &&  
        tree->lower_than(key2,key1)==0) return 1;
    else return 0;
}


TreeNode * createTreeNode(void* key, void * value) {
    TreeNode * new = (TreeNode *)malloc(sizeof(TreeNode));
    if (new == NULL) return NULL;
    new->pair = (Pair *)malloc(sizeof(Pair));
    new->pair->key = key;
    new->pair->value = value;
    new->parent = new->left = new->right = NULL;
    return new;
}

TreeMap * createTreeMap(int (*lower_than) (void* key1, void* key2))
{
    TreeMap *tree = (TreeMap *)malloc(sizeof(TreeMap));
    tree->root = NULL;
    tree->current = NULL;
    tree->lower_than = lower_than;
    return tree;
    //new->lower_than = lower_than;
    return NULL;
}


void insertTreeMap(TreeMap * tree, void* key, void * value) 
{

    TreeNode *aux = (TreeNode *) malloc(sizeof(TreeNode));
    aux->pair = (Pair *) malloc(sizeof(Pair));
    aux->pair->key = key;
    aux->pair->value = value;
    aux->left = NULL;
    aux->right = NULL;
    aux->parent = NULL;
    if (tree == NULL || tree->root == NULL)
    {
        tree->root = createTreeNode(key, value);
    }
    else
    {
        TreeNode *aux = tree->root;
        while (aux != NULL)
        {
            if (tree->lower_than(key, aux->pair->key) == 1)
            {
                if (aux->left == NULL)
                {
                    aux->left = createTreeNode(key, value);
                }
                else
                {
                    aux = aux->left;
                }
            }
            else if (tree->lower_than(key, aux->pair->key) == 1)
            {
                if (aux->right == NULL)
                {
                    aux->right = createTreeNode(key, value);
                }
                else
                {
                    aux = aux->right;
                }
            }
        }
    }
}

TreeNode * minimum(TreeNode * x)
{
    if (x == NULL) return NULL;
    while (x->left != NULL)
    {
        x = x->left;
        
    }

}


void removeNode(TreeMap * tree, TreeNode* node) {

}

void eraseTreeMap(TreeMap * tree, void* key){
    if (tree == NULL || tree->root == NULL) return;

    if (searchTreeMap(tree, key) == NULL) return;
    TreeNode* node = tree->current;
    removeNode(tree, node);

}




Pair * searchTreeMap(TreeMap * tree, void* key) {
    return NULL;
}


Pair * upperBound(TreeMap * tree, void* key) {
    return NULL;
}

Pair * firstTreeMap(TreeMap * tree) {
    return NULL;
}

Pair * nextTreeMap(TreeMap * tree) {
    return NULL;
}
