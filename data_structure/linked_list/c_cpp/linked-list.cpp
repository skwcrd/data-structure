#include<stdio.h>

typedef struct Node{
    int data;
    struct Node *next;
}sk_list;

void create(sk_list **n);
int IsEmpty(sk_list *n);
void insert_front(int val,sk_list **n);
void traverse(sk_list *n);

int main(void)
{
    int num;
    sk_list *sk = new sk_list;
    create(&sk);
    insert_front(1,&sk);
    insert_front(2,&sk);
    insert_front(3,&sk);
    insert_front(4,&sk);
    insert_front(5,&sk);
    traverse(sk);
    return 0;
}

void create(sk_list **n)
{
    *n = NULL;
}

int IsEmpty(sk_list *n)
{
    return (n==NULL);
}

void insert_front(int val,sk_list **n)
{
    sk_list *p = new sk_list;
    p->data = val;
    p->next = *n;
    *n = p;
}

void traverse(sk_list *n)
{
    sk_list *p;
    printf("\n");
    if(IsEmpty(n))
        printf("Empty List\n");
    else{
        p = n;
        while(p->next!=NULL)
        {
            printf("%d ",p->data);
            p = p->next;
        }
        printf("%d End of List\n",p->data);
    }
}
