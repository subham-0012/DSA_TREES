#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};
void create(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(struct Node**)malloc(q->size*sizeof(struct Node *));
}
void enqueue(struct Queue *q,struct Node *x)
{
    if((q->rear+1)%q->size==q->front)
    {
        printf("Queue is Full");
    }
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}
struct Node* dequeue(struct Queue *q)
{
    struct Node* x=NULL;
    if(q->front==q->rear)
    {
        printf("Queue is empty");
    }
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}
struct Node *root=NULL;
void TreeCreate()
{
    struct Node *p,*t;
    int x;
    struct Queue q;
    create(&q,100);
    printf("Enter Root Value: ");
    scanf("%d",&x);
    root=(struct Node*)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=0;
    enqueue(&q,root);
    while(!isEmpty(q))
    {
        p=dequeue(&q);
        printf("enter left child of %d: ",p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = 0;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("enter right child of %d: ",p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = 0;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}
void preorder(struct Node *p)
{
    if(p)
    {
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}
void postorder(struct Node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}
void LevelOrder(struct Node *p)
{
    struct Queue q;
    create(&q,100);
    printf("%d ",p->data);
    enqueue(&q,p);
    while(!isEmpty(q))
    {
        p=dequeue(&q);
        if(p->lchild)
        {
            printf("%d ",p->lchild->data);
            enqueue(&q,p->lchild);
        }
        if(p->rchild)
        {
            printf("%d ",p->rchild->data);
            enqueue(&q, p->rchild);
        }
    }
}
int count(struct Node *root)
{
    if(root)
    {
        return count(root->lchild)+count(root->rchild)+1;
    }
}
int height(struct Node *root)
{
    int x=0,y=0;
    if(root==0)
    {
        return 0;
    }
    else
    {
        x=height(root->lchild);
        y=height(root->rchild);
        if(x>y)
        {
            return x+1;
        }
        return y+1;
    }
}
int main()
{
    TreeCreate();
    // preorder(root);
    // Inorder(root);
    // postorder(root);
    // LevelOrder(root);
}