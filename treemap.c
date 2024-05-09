#include "treemap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode TreeNode;

struct TreeNode {
  Pair *pair;
  TreeNode *left;
  TreeNode *right;
  TreeNode *parent;
};

struct TreeMap {
  TreeNode *root;
  TreeNode *current;
  int (*lower_than)(void *key1, void *key2);
};

int is_equal(TreeMap *tree, void *key1, void *key2) {
  if (tree->lower_than(key1, key2) == 0 && tree->lower_than(key2, key1) == 0)
    return 1;
  else
    return 0;
}

TreeNode *createTreeNode(void *key, void *value) {
  TreeNode *new = (TreeNode *)malloc(sizeof(TreeNode));
  if (new == NULL)
    return NULL;
  new->pair = (Pair *)malloc(sizeof(Pair));
  new->pair->key = key;
  new->pair->value = value;
  new->parent = new->left = new->right = NULL;
  return new;
}

TreeMap *createTreeMap(int (*lower_than)(void *key1, void *key2)) {
  TreeMap *tree = (TreeMap *)malloc(sizeof(TreeMap));
  tree->root = NULL;
  tree->current = NULL;
  tree->lower_than = lower_than;
  return tree;
  // new->lower_than = lower_than;
  return NULL;
}

Pair *searchTreeMap(TreeMap *tree, void *key) {
  /*
      if (tree == NULL || tree->root == NULL) return NULL;
      TreeNode *aux = tree->root;

      while (tree->current != NULL)
      {
          if (is_equal(tree, tree->current->pair->key, key) == 1){
              return tree->current->pair;
          }
          else {
              if (tree->lower_than(key, tree->current->pair->key) == 1){
                  tree->current = tree->current->left;
              }
              else{
                  tree->current = tree->current->right;
              }
          }

      } */
  return NULL;
}

void insertTreeMap(TreeMap *tree, void *key, void *value) 
{
    TreeNode *node = createTreeNode(key, value);
    TreeNode *aux = tree->root;
    while (aux) 
    {
        if (is_equal(tree, aux->pair->key, key))
        return;
        if (tree->lower_than(key, aux->pair->key)) 
        {
            if (aux->left)
            aux = aux->left;
            else 
            {
                aux->left = node;
                node->parent = aux;
                tree->current = node;
                return;
            }
        } 
        else 
        {
            if (aux->right)
            aux = aux->right;
        else 
        {
            aux->right = node;
            node->parent = aux;
            tree->current = node;
            return;
        }
    }
}

  TreeNode *minimum(TreeNode * x) {
    while (x->left != NULL) {
      x = x->left;
    }
    return x;
  }

  void removeNode(TreeMap * tree, TreeNode * node) {
    /*
    if (node->left == NULL && node->right == NULL)
    {
        if (node->parent->left == node)
        {
            node->parent->left = NULL;
        }
        else
        {
            node->parent->right = NULL;
        }
    }
    else
    {
        if (node->left == NULL)
        {
            if (node->parent->left == node)
            {
                node->parent->left = node->right;
                node->right->parent = node->parent;
            }
            else
            {
                node->parent->right = node->right;
                node->right->parent = node->parent;
            }
        }
        else
        {
            if (node->right == NULL)
            {
                if (node->parent->left == node)
                {
                    node->parent->left = node->left;
                    node->left->parent = node->parent;
                }
            }
        }
    }
    */
  }

  void eraseTreeMap(TreeMap * tree, void *key) {
    if (tree == NULL || tree->root == NULL)
      return;

    if (searchTreeMap(tree, key) == NULL)
      return;
    TreeNode *node = tree->current;
    removeNode(tree, node);
  }

  Pair *upperBound(TreeMap * tree, void *key) {
    /*
    TreeNode *aux = tree->root;
    while (aux != NULL)
    {
        if (is_equal(tree, aux->pair->key, key) == 1)
        {
            return aux->pair;
        }
        else
        {
            if (tree->lower_than(key, aux->pair->key) == 1)
            {
                aux = aux->left;
            }
            else
            {
                aux = aux->right;
            }
        }
    }
    */

    return NULL;
  }

  Pair *firstTreeMap(TreeMap * tree) {

    if (tree == NULL || tree->root == NULL)
      return NULL;
    TreeNode *aux = minimum(tree->root);
    tree->current = aux;
    return aux->pair;
  }

  Pair *nextTreeMap(TreeMap * tree) {
    if (tree == NULL)
      return NULL;
    TreeNode *next = tree->current;
    if (next == tree->root || next->right) {
      next = minimum(next->right);
      tree->current = next;
      return tree->current->pair;
    } else if (next->right == NULL) {
      TreeNode *temp = next;
      while (next->parent) {
        temp = next;
        next = next->parent;
        if (next->left == temp) {
          tree->current = next;
          return tree->current->pair;
        }
      }
      return NULL;
    }
    return NULL;
  }