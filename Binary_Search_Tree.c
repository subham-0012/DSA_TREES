#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;
void Insert(int key)
{
    struct Node *t=root;
    struct Node *r,*p;
    if(root==NULL)
    {
        p=(struct Node *)malloc(sizeof(struct Node));
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t!=NULL)
    {
        r=t;
        if(key<t->data)
        {
            t=t->lchild;
        }
        else if(key>t->data)
        {
            t=t->rchild;
        }
        else
            return;
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    if(key<r->data)
    {
        r->lchild=p;
    }
    else
    {
        r->rchild=p;
    }
}
int height(struct Node *root)
{
    int x = 0, y = 0;
    if (root == 0)
    {
        return 0;
    }
    else
    {
        x = height(root->lchild);
        y = height(root->rchild);
        if (x > y)
        {
            return x + 1;
        }
        return y + 1;
    }
}
void Inorder(struct Node* p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}
struct Node* Search(int key)
{
    struct Node *t=root;
    while(t!=NULL)
    {
        if(key==t->data)
        {
            return t;
        }
        else if(key<t->data)
        {
            t=t->lchild;
        }
        else
        {
            t=t->rchild;
        }
    }
    return NULL;
}
struct Node *RInsert(struct Node *p,int key)
{
    if(p==NULL)
    {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key<p->data)
    {
        p->lchild=RInsert(p->lchild,key);
    }
    else if (key>p->data)
    {
        p->rchild=RInsert(p->rchild,key);
    }
    return p;
}
struct Node *Inpre(struct Node *p)
{
    while(p!=NULL&&p->lchild!=NULL)
    {
        p=p->lchild;
    }
    return p;
}
struct Node *InSucc(struct Node *p)
{
    while (p!=NULL && p->rchild != NULL)
    {
        p = p->rchild;
    }
    return p;
}
struct Node *Delete(struct Node *p,int key)
{
    struct Node *q;
    if(p==NULL)
    {
        return NULL;
    }
    if(p->lchild==NULL&&p->rchild==NULL)
    {
        if(p==root)
        {
            root=NULL;
        }
        free(p);
        return NULL;
    }
    if(key<p->data)
    {
        p->lchild=Delete(p->lchild,key);
    }
    else if(key>p->data)
    {
        p->rchild=Delete(p->rchild,key);
    }
    else
    {
        if(height(p->lchild)>height(p->rchild))
        {
            q=Inpre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}
int main()
{
    // root=RInsert(root,10);
    // RInsert(root,5);
    // RInsert(root,20);
    // RInsert(root,8);
    // RInsert(root,30);
    // Delete(root,20);
    // Inorder(root);


    // Insert(10);
    // Insert(5);
    // Insert(20);
    // Insert(8);
    // Insert(30);
    // Inorder(root);


    // struct Node *temp=Search(20);
    // if(temp!=NULL)
    // {
    //     printf("element %d is found\n",temp->data);
    // }
    // else
    // {
    //     printf("element %d is found\n", temp->data);
    // }
    return 0;
}