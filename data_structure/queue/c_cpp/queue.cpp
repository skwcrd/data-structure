#include<stdio.h>
#include<conio.h>

typedef struct queue_dat
{
	int data;
	queue_dat *next;
}queue_node;

typedef struct
{
	int count;
	queue_node *front;
	queue_node *rear;
}queue;

int IsEmpty(queue *q)
{
	return(q->front==NULL);
}

void create_queue(queue **n)
{
	*n=new queue;
	(*n)->front=NULL;
	(*n)->rear=NULL;
	(*n)->count=0;
}

void enq(int en_data,queue **n)
{
	queue_node *new_node;
	new_node = new queue_node;
	new_node->data=en_data;
	new_node->next=NULL;

	if(IsEmpty(*n))
	{
		(*n)->front=new_node;
	}else
	{
		(*n)->rear->next=new_node;
	}

	(*n)->rear=new_node;
	(*n)->count++;
}

void deq(int *de_data,queue **n)
{
	queue_node *q;
	q=(*n)->front;

	if(!IsEmpty(*n))
	{
		*de_data=q->data;
		(*n)->front=q->next;
		if((*n)->front==NULL) (*n)->rear=NULL;
		(*n)->count--;
		delete q;
	}else
	{
		*de_data=NULL;
	}
}

void front(int *front_data,queue **n)
{
	if(!IsEmpty(*n))
	{
		*front_data=(*n)->front->data;
	}else
	{
		*front_data=NULL;
	}
}

void rear(int *rear_data,queue **n)
{
	if(!IsEmpty(*n))
	{
		*rear_data=(*n)->rear->data;
	}else
	{
		*rear_data=NULL;
	}
}

int count_queue(queue **n)
{
   return((*n)->count);
}

void clear_queue(queue **n)
{
   int dummy;
   while(!IsEmpty(*n))
   {
	deq(&dummy,n);
   }
}


void destroy_queue(queue **n)
{
	clear_queue(n);
	delete n;
}

int main(void)
{
	queue *q;
	int n;

	create_queue(&q);

	printf("\nEnqueue 1,2,3");
	enq(1,&q);
	enq(2,&q);
	enq(3,&q);

	deq(&n,&q); printf("\n Dequeue %d ",n);
	deq(&n,&q); printf("\n Dequeue %d ",n);
	deq(&n,&q); printf("\n Dequeue %d ",n);
	deq(&n,&q); printf("\n Dequeue %d ",n);

	printf("\nEnqueue 1,2,3,4,5");
	enq(1,&q);
	enq(2,&q);
	enq(3,&q);
	enq(4,&q);
	enq(5,&q);

	deq(&n,&q); printf("\n Dequeue %d ",n);
	printf("\nQueue has %d member",count_queue(&q));

	printf("\nEnqueue 6");
	enq(6,&q);

	deq(&n,&q); printf("\n Dequeue %d ",n);
	deq(&n,&q); printf("\n Dequeue %d ",n);
	front(&n,&q); printf("\n Front queue %d ",n);
	rear(&n,&q); printf("\n Rear queue %d ",n);

	printf("\nQueue has %d member",count_queue(&q));

	clear_queue(&q);

	printf("\nQueue has %d member after clear queue",count_queue(&q));

	destroy_queue(&q);

	return 0;
}
