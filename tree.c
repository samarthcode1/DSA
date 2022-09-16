Binary Tree Create
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
struct Node *root=NULL;
void Treecreate()
{
 struct Node *p,*t;
 int x;
 struct Queue q;
 create(&q,100);

 printf("Eneter root value ");
 scanf("%d",&x);
 root=(struct Node *)malloc(sizeof(struct Node));
 root->data=x;
 root->lchild=root->rchild=NULL;
 enqueue(&q,root);

 while(!isEmpty(q))
 {
 p=dequeue(&q);
 printf("eneter left child of %d ",p->data);
 scanf("%d",&x);
 if(x!=-1)
 {
 t=(struct Node *)malloc(sizeof(struct
Node));
 t->data=x;
 t->lchild=t->rchild=NULL;
 p->lchild=t;
 enqueue(&q,t);
 }
 printf("eneter right child of %d ",p->data);
 scanf("%d",&x);
 if(x!=-1)
 {
 t=(struct Node *)malloc(sizeof(struct
Node));
 t->data=x;
 t->lchild=t->rchild=NULL;
 p->rchild=t;
 enqueue(&q,t);
 }
 }
}
void Preorder(struct Node *p)
{
 if(p)
 {
 printf("%d ",p->data);
 Preorder(p->lchild);
 Preorder(p->rchild);
 }
}
void Inorder(struct Node *p)
{
 if(p)
 {
 Inorder(p->lchild);
 printf("%d ",p->data);
 Inorder(p->rchild);
 }
}
void Postorder(struct Node *p)
{
 if(p)
 {
 Postorder(p->lchild);
 Postorder(p->rchild);
 printf("%d ",p->data);
 }
}
int main()
{
 Treecreate();
 Preorder(root);
 printf("\nPost Order ");
 Postorder(root);

 return 0;
}
Queue Header File
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
 q->Q=(struct Node **)malloc(q->size*sizeof(struct
Node *));
}
void enqueue(struct Queue *q,struct Node *x)
{
 if((q->rear+1)%q->size==q->front)
 printf("Queue is Full");
 else
 {
 q->rear=(q->rear+1)%q->size;
 q->Q[q->rear]=x;
 }
}
struct Node * dequeue(struct Queue *q)
{
 struct Node* x=NULL;

 if(q->front==q->rear)
 printf("Queue is Empty\n");
 else
 {
 q->front=(q->front+1)%q->size;
 x=q->Q[q->front];
 }
 return x;
}
int isEmpty(struct Queue q)
{
 return q.front==q.rear;
}


Binary Tree Class(USING CPP)
#include <iostream>
#include<stdio.h>
#include "QueueCpp.h"
using namespace std;
class Tree
{
 Node *root;

public:
 Tree(){root=NULL;}
 void CreateTree();
 void Preorder(){Preorder(root);}
 void Preorder(Node *p);
 void Postorder(){Postorder(root);}
 void Postorder(Node *p);
 void Inorder(){Inorder(root);}
 void Inorder(Node *p);
 void Levelorder(){Levelorder(root);}
 void Levelorder(Node *p);
 int Height(){return Height(root);}
 int Height(Node *root);
};
void Tree::CreateTree()
{
 Node *p,*t;
 int x;
 Queue q(100);

 printf("Eneter root value ");
 scanf("%d",&x);
 root=new Node;
 root->data=x;
 root->lchild=root->rchild=NULL;
 q.enqueue(root);

 while(!q.isEmpty())
 {
 p=q.dequeue();
 printf("eneter left child of %d ",p->data);
 scanf("%d",&x);
 if(x!=-1)
 {
 t=new Node;
 t->data=x;
 t->lchild=t->rchild=NULL;
 p->lchild=t;
 q.enqueue(t);
 }
 printf("eneter right child of %d ",p->data);
 scanf("%d",&x);
 if(x!=-1)
 {
 t=new Node;
 t->data=x;
 t->lchild=t->rchild=NULL;
 p->rchild=t;
 q.enqueue(t);
 }
 }
}
void Tree::Preorder(struct Node *p)
{
 if(p)
 {
 printf("%d ",p->data);
 Preorder(p->lchild);
 Preorder(p->rchild);
 }
}
void Tree::Inorder(struct Node *p)
{
 if(p)
 {
 Inorder(p->lchild);
 printf("%d ",p->data);
 Inorder(p->rchild);
 }
}
void Tree::Postorder(struct Node *p)
{
 if(p)
 {
 Postorder(p->lchild);
 Postorder(p->rchild);
 printf("%d ",p->data);
 }
}
void Tree::Levelorder(struct Node *root)
{
 Queue q(100);

 printf("%d ",root->data);
 q.enqueue(root);

 while(!q.isEmpty())
 {
 root=q.dequeue();
 if(root->lchild)
 {
 printf("%d ",root->lchild->data);
 q.enqueue(root->lchild);
 }
 if(root->rchild)
 {
 printf("%d ",root->rchild->data);
 q.enqueue(root->rchild);
 }
 }
}
int Tree::Height(struct Node *root)
{
 int x=0,y=0;
 if(root==0)
 return 0;
 x=Height(root->lchild);
 y=Height(root->rchild);
 if(x>y)
 return x+1;
 else
 return y+1;

}
int main()
{
 Tree t;
 t.CreateTree();
 cout<<"Preorder ";
 t.Preorder();
 cout<<endl;
 cout<<"Inorder ";
 t.Inorder();
 cout<<endl<<endl;

 return 0;
}

Binary Tree Class
#include <iostream>
#include<stdio.h>
#include "QueueCpp.h"
using namespace std;
class Tree
{
 Node *root;

public:
 Tree(){root=NULL;}
 void CreateTree();
 void Preorder(){Preorder(root);}
 void Preorder(Node *p);
 void Postorder(){Postorder(root);}
 void Postorder(Node *p);
 void Inorder(){Inorder(root);}
 void Inorder(Node *p);
 void Levelorder(){Levelorder(root);}
 void Levelorder(Node *p);
 int Height(){return Height(root);}
 int Height(Node *root);
};
void Tree::CreateTree()
{
 Node *p,*t;
 int x;
 Queue q(100);

 printf("Eneter root value ");
 scanf("%d",&x);
 root=new Node;
 root->data=x;
 root->lchild=root->rchild=NULL;
 q.enqueue(root);

 while(!q.isEmpty())
 {
 p=q.dequeue();
 printf("eneter left child of %d ",p->data);
 scanf("%d",&x);
 if(x!=-1)
 {
 t=new Node;
 t->data=x;
 t->lchild=t->rchild=NULL;
 p->lchild=t;
 q.enqueue(t);
 }
 printf("eneter right child of %d ",p->data);
 scanf("%d",&x);
 if(x!=-1)
 {
 t=new Node;
 t->data=x;
 t->lchild=t->rchild=NULL;
 p->rchild=t;
 q.enqueue(t);
 }
 }
}
void Tree::Preorder(struct Node *p)
{
 if(p)
 {
 printf("%d ",p->data);
 Preorder(p->lchild);
 Preorder(p->rchild);
 }
}
void Tree::Inorder(struct Node *p)
{
 if(p)
 {
 Inorder(p->lchild);
 printf("%d ",p->data);
 Inorder(p->rchild);
 }
}
void Tree::Postorder(struct Node *p)
{
 if(p)
 {
 Postorder(p->lchild);
 Postorder(p->rchild);
 printf("%d ",p->data);
 }
}
void Tree::Levelorder(struct Node *root)
{
 Queue q(100);

 printf("%d ",root->data);
 q.enqueue(root);

 while(!q.isEmpty())
 {
 root=q.dequeue();
 if(root->lchild)
 {
 printf("%d ",root->lchild->data);
 q.enqueue(root->lchild);
 }
 if(root->rchild)
 {
 printf("%d ",root->rchild->data);
 q.enqueue(root->rchild);
 }
 }
}
int Tree::Height(struct Node *root)
{
 int x=0,y=0;
 if(root==0)
 return 0;
 x=Height(root->lchild);
 y=Height(root->rchild);
 if(x>y)
 return x+1;
 else
 return y+1;

}
int main()
{
 Tree t;
 t.CreateTree();
 cout<<"Preorder ";
 t.Preorder();
 cout<<endl;
 cout<<"Inorder ";
 t.Inorder();
 cout<<endl<<endl;

 return 0;
}



LevelOrder Traversal
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"
struct Node *root=NULL;
void Treecreate()
{
 struct Node *p,*t;
 int x;
 struct Queue q;
 create(&q,100);

 printf("Eneter root value ");
 scanf("%d",&x);
 root=(struct Node *)malloc(sizeof(struct Node));
 root->data=x;
 root->lchild=root->rchild=NULL;
 enqueue(&q,root);

 while(!isEmpty(q))
 {
 p=dequeue(&q);
 printf("eneter left child of %d ",p->data);
 scanf("%d",&x);
 if(x!=-1)
 {
 t=(struct Node *)malloc(sizeof(struct Node));
 t->data=x;
 t->lchild=t->rchild=NULL;
 p->lchild=t;
 enqueue(&q,t);
 }
 printf("eneter right child of %d ",p->data);
 scanf("%d",&x);
 if(x!=-1)
 {
 t=(struct Node *)malloc(sizeof(struct Node));
 t->data=x;
 t->lchild=t->rchild=NULL;
 p->rchild=t;
 enqueue(&q,t);
 }
 }
}
void LevelOrder(struct Node *root)
{
 struct Queue q;
 create(&q,100);

 printf("%d ",root->data);
 enqueue(&q,root);

 while(!isEmpty(q))
 {
 root=dequeue(&q);
 if(root->lchild)
 {
 printf("%d ",root->lchild->data);
 enqueue(&q,root->lchild);
 }
 if(root->rchild)
 {
 printf("%d ",root->rchild->data);
 enqueue(&q,root->rchild);
 }
 }
}
int main()
{
 Treecreate();

 LevelOrder(root);
 return 0;
}


Count and Height of a Tree
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"
struct Node *root=NULL;
void Treecreate()
{
 struct Node *p,*t;
 int x;
 struct Queue q;
 create(&q,100);

 printf("Eneter root value ");
 scanf("%d",&x);
 root=(struct Node *)malloc(sizeof(struct Node));
 root->data=x;
 root->lchild=root->rchild=NULL;
 enqueue(&q,root);

 while(!isEmpty(q))
 {
 p=dequeue(&q);
 printf("eneter left child of %d ",p->data);
 scanf("%d",&x);
 if(x!=-1)
 {
 t=(struct Node *)malloc(sizeof(struct Node));
 t->data=x;
 t->lchild=t->rchild=NULL;
 p->lchild=t;
 enqueue(&q,t);
 }
 printf("eneter right child of %d ",p->data);
 scanf("%d",&x);
 if(x!=-1)
 {
 t=(struct Node *)malloc(sizeof(struct Node));
 t->data=x;
 t->lchild=t->rchild=NULL;
 p->rchild=t;
 enqueue(&q,t);
 }
 }
}
int count(struct Node *root)
{
 if(root)
 return count(root->lchild)+count(root->rchild)+1;
 return 0;
}
int height(struct Node *root)
{
 int x=0,y=0;
 if(root==0)
 return 0;
 x=height(root->lchild);
 y=height(root->rchild);
 if(x>y)
 return x+1;
 else
 return y+1;

}
int main()
{
 Treecreate();

 printf(“%d”,count(root));
 printf(“%d”,height(root));
 return 0;
}
