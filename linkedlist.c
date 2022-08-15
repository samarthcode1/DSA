Display a Linked List
#include <stdio.h>
#include <stdlib.h>
struct Node
{
 int data;
 struct Node *next;
}*first=NULL;
void create(int A[],int n)
{
 int i;
 struct Node *t,*last;
 first=(struct Node *)malloc(sizeof(struct Node));
 first->data=A[0];
 first->next=NULL;
 last=first;

 for(i=1;i<n;i++)
 {
 t=(struct Node*)malloc(sizeof(struct Node));
 t->data=A[i];
 t->next=NULL;
 last->next=t;
 last=t;
 }
}
void Display(struct Node *p)
{
 while(p!=NULL)
 {
 printf("%d ",p->data);
 p=p->next;
 }
}
void RDisplay(struct Node *p)
{
 if(p!=NULL)
 {
 RDisplay(p->next);
 printf("%d ",p->data);

 }
}
int main()
{
 struct Node *temp;
 int A[]={3,5,7,10,25,8,32,2};
 create(A,8);

 Display(first);

 return 0;
}


Count and Sum Linked List
#include <stdio.h>
#include <stdlib.h>
struct Node
{
 int data;
 struct Node *next;
}*first=NULL;
void create(int A[],int n)
{
 int i;
 struct Node *t,*last;
 first=(struct Node *)malloc(sizeof(struct Node));
 first->data=A[0];
 first->next=NULL;
 last=first;

 for(i=1;i<n;i++)
 {
 t=(struct Node*)malloc(sizeof(struct Node));
 t->data=A[i];
 t->next=NULL;
 last->next=t;
 last=t;
 }
}
int count(struct Node *p)
{
 int l=0;
 while(p)
 {
 l++;
 p=p->next;
 }
 return l;
}
int Rcount(struct Node *p)
{
 if(p!=NULL)
 return Rcount(p->next)+1;
 else
 return 0;
}
int sum(struct Node *p)
{
 int s=0;

 while(p!=NULL)
 {
 s+=p->data;
 p=p->next;
 }
 return s;
}
int Rsum(struct Node *p)
{
 if(p==NULL)
 return 0;
 else
 return Rsum(p->next)+p->data;
}
int main()
{
 int A[]={3,5,7,10,25,8,32,2};
 create(A,8);

 printf(“Count %d\n”,count(first));
 printf(“Sum %d\n”,sum(first);



 return 0;
}
        
        Max element from Linked List
#include <stdio.h>
#include <stdlib.h>
struct Node
{
 int data;
 struct Node *next;
}*first=NULL;
void create(int A[],int n)
{
 int i;
 struct Node *t,*last;
 first=(struct Node *)malloc(sizeof(struct Node));
 first->data=A[0];
 first->next=NULL;
 last=first;

 for(i=1;i<n;i++)
 {
 t=(struct Node*)malloc(sizeof(struct Node));
 t->data=A[i];
 t->next=NULL;
 last->next=t;
 last=t;
 }
}
int Max(struct Node *p)
{
 int max=INT32_MIN;

 while(p)
 {
 if(p->data>max)
 max=p->data;
 p=p->next;
 }
 return max;

}
int RMax(struct Node *p)
{
 int x=0;

 if(p==0)
 return INT32_MIN;
 x=RMax(p->next);
 if(x>p->data)
 return x;
 else
 return p->data;
}
int main()
{
 int A[]={3,5,7,10,25,8,32,2};
 create(A,8);

 printf(“Max %d\n”,Max(first);



 return 0;
}
