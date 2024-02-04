#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *parent;
    struct node *left;
    struct node *right;
    int data;
    int color;
}node;

typedef struct rbtree
{
    node *root;
    node *NIL;
}rbtree;

node *new_node(int data)
{
    node *n = malloc(sizeof(node));

    n->parent = NULL;
    n->left = NULL;
    n->right = NULL;
    n->data = data;
    n->color = 1;

    return n;
}
rbtree *new_rbtree()
{
    rbtree *t = malloc(sizeof(rbtree));
    node *nil_node = malloc(sizeof(node));

    nil_node->parent = NULL;
    nil_node->right = NULL;
    nil_node->left = NULL;
    nil_node->data = 0;
    nil_node->color = 0;
    t->NIL = nil_node;
    t->root = t->NIL;
    
    return t;
}
void left_rotation(rbtree *t,node *x)
{
    //x의 오른쪽 자식 노드 y 선언 
    node *y = x->right;
    //y의 왼쪽 자식노드를 x의 오른쪽 자식노드로 변경 
    x->right = y->left;
    //y의 자식노드가 NIL이 아니면, y의 왼쪽 자식노드의 부모를 x로 변경
    if (y->left != t->NIL)
        y->left->parent = x;
    //y의 부모노드를 x의 부모로 변경
    y->parent = x->parent;
    //x is root
    if(x->parent == t->NIL)
        t->root = y;
    // x is left child
    else if(x == x->parent->left)
        x->parent->left = y;
    else //x is right child
        x->parent->right = y;
    // y의 왼쪽 자식을 x로 
    y->left = x;
    // x의 부모를 y로 
    x->parent = y;
}
void right_rotation(rbtree *t,node *x)
{
    node *y = x->left;
    x->left = y->right;
    if(y->right != t->NIL)
        y->right->parent = x;
    y->parent = x->parent;
    //x is root
    if(x->parent == t->NIL)
        t->root = y;
    // x is left child 
    else if (x==x->parent->left)
        x->parent->left = y;
    else // x is right child
        x->parent->right = y;
    y->right = x;
    x->parent = y;
}
void insert_fixup(rbtree *t,node *z)
{
    while(z->parent->color == 1)
    {
        if (z->parent == z->parent->left) // z.parent is left child
        {
            node *y = z->parent->parent->right; // uncle of z
            if (y->color == 1) // case 1 
            {
                z->parent->color = 0;
                y->color = 0;
                z->parent->parent->color = 1;
                z = z->parent->parent;
            }else // case 2 or 3
            {
                if (z== z->parent->right) // case 2 
                {
                    z = z->parent; // marked z.parent as new z
                    left_rotation(t,z);
                }
                // case 3 
                z->parent->color = 0; //made parent black
                z->parent->parent->color = 1; // made grandparent red
                right_rotation(t,z->parent->parent);
            }
        }else // z.parent is right child
        {
            node *y = z->parent->parent->left; // uncle of z 
            if (y->color == 1) // case 1 
            {
                z->parent->color = 0;
                y->color = 0;
                z->parent->parent->color = 1;
                z = z->parent->parent;
            }else
            {
                if (z==z->parent->left)
                {
                    z = z->parent;
                    right_rotation(t,z);
                }
                z->parent->color = 0;
                z->parent->parent->color = 1;
                left_rotation(t,z->parent->parent);
            }
        }
    }
    // tree의 root를 black 으로
    t->root->color = 0;
}
void insert(rbtree *t,node *n)
{
    node *y = t->NIL;
    node *temp = t->root;

    while(temp != t->NIL)
    {
        y = temp;
        if(n->data < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    n->parent = y;
    if(y == t->NIL)
        t->root = n;
    else if (n->data < y->data)
        y->left = n;
    else
        y->right = n;
    n->left = t->NIL;
    n->right = t->NIL;
    n->color = 1;
    insert_fixup(t,n);
}



