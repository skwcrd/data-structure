#include<stdio.h>

typedef struct node{
    char data;
	node* next;
}stack_node;

typedef struct{
    int count;
	stack_node* top;
}stack;

void create_stack(stack **st);
int IsEmpty(stack *st);
void push(char val,stack *st);
void pop(char *val,stack *st);
void top(char *val,stack *st);
void clear_stack(stack *st);
int counts(stack *st);
void destroy(stack **st);

int main(void)
{
    stack *S1;
	char c;
	create_stack(&S1);

	push('A',S1);
	push('B',S1);
	push('C',S1);
	push('D',S1);
	push('E',S1);
	push('F',S1);

	clear_stack(S1);

	if(IsEmpty(S1))
        printf("\nStack is EMPTY!!\n");
	else
		printf("\nStack has data.\n");

    destroy(&S1);

	return 0;
}

void create_stack(stack **st)
{
    *st = new stack;
	(*st)->top = NULL;
	(*st)->count = 0;
}

int IsEmpty(stack *st)
{
    return (st->top==NULL);
}

void push(char val,stack *st)
{
    stack_node *p;
	p = new stack_node;
	p->data = val;
	if(IsEmpty(st))
        p->next = NULL;
	else
		p->next = st->top;
	st->top = p;
	st->count++;
}

void pop(char *val,stack *st)
{
    stack_node *p;
	if(IsEmpty(st)){
        *val = NULL;
		printf("\nCan't pop EMPTY stack!!");
	}
	else{
        p = st->top;
		*val = st->top->data;
		st->top = st->top->next;
		st->count--;
        delete p;
	}
}

void top(char *val,stack *st)
{
	if(IsEmpty(st)){
        *val = NULL;
		printf("\nCan't top EMPTY stack!!");
	}
	else
		*val = st->top->data;
}

void clear_stack(stack *st)
{
    char sk;
	while(!IsEmpty(st))
        pop(&sk,st);
}

int counts(stack *st)
{
    return (st->count);
}

void destroy(stack **st)
{
	clear_stack(*st);
	delete *st;
}
