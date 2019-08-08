#include<stdio.h>
#include<conio.h>

typedef struct node{
	int data;
	node *left;
	node *right;
}tree_node;

typedef struct{
	tree_node *root;
	int count;
}tree;

typedef struct stack_node{
	tree_node *tnode;
	stack_node *next;
}stack;

int IsEmpty_st(stack *);
void create_st(stack **);
void push(tree_node *,stack **);
void pop(tree_node **,stack **);
void clear_st(stack **);

int IsEmpty(tree *);
void create_tree(tree **);
void Insert_BST(int,tree *);
void Delete_BST(int,tree *);
void inorder1(tree_node *);
void preorder1(tree_node *);
void inorder(tree_node *);
void preorder(tree_node *);
void postorder(tree_node *);
void inorder_re(tree_node *);
void preorder_re(tree_node *);
void postorder_re(tree_node *);

int main(void)
{
	tree *b;
	create_tree(&b);

	printf("\nInsert 2, 8, 5, 4, 7, 9, 3, 1 to BST");

	Insert_BST(2,b);
	Insert_BST(8,b);
	Insert_BST(5,b);
	Insert_BST(4,b);
	Insert_BST(7,b);
	Insert_BST(9,b);
	Insert_BST(3,b);
	Insert_BST(1,b);

	printf("\n\nDelete 4, 1, 6 in BST");

	Delete_BST(4,b);
	Delete_BST(1,b);
	Delete_BST(6,b);

	printf("\n\nInsert 6, 9, 11, 8, 1 to BST");

	Insert_BST(6,b);
	Insert_BST(9,b);
	Insert_BST(11,b);
	Insert_BST(8,b);
	Insert_BST(1,b);

	printf("\n\nTraverse Inorder :");
	inorder(b->root);
	printf("\nTraverse Preorder :");
	preorder(b->root);
	printf("\nTraverse Postorder :");
	postorder(b->root);

	printf("\n\nTraverse Inorder Recursive :");
	inorder_re(b->root);
	printf("\nTraverse Preorder Recursive :");
	preorder_re(b->root);
	printf("\nTraverse Postorder Recursive :");
	postorder_re(b->root);
	return 0;
}

int IsEmpty_st(stack *st)
{
	return(st == NULL);
}

void create_st(stack **st)
{
	stack *p;
	p = NULL;
	*st = p;
}

void push(tree_node *push_v,stack **st)
{
	stack *p,*tp;
	p = new stack;
	p->tnode = push_v;
	tp = *st;
	if(IsEmpty_st(tp)){
		p->next = NULL;
	}
	else{
		p->next = tp;
	}
	*st = p;
}

void pop(tree_node **pop_v,stack **st)
{
	stack *p;
	p = *st;
	if(!IsEmpty_st(p)){
		*pop_v = p->tnode;
		*st = p->next;
		delete p;
	}
}

void clear_st(stack **st)
{
	stack *p;
	tree_node *tr;
	p = *st;
	while(p!=NULL){
		pop(&tr,&p);
	}
	*st = p;
}

int IsEmpty(tree *t)
{
	return(t->root == NULL);
}

void create_tree(tree **newtree)
{
	*newtree = new tree;
	(*newtree)->root = NULL;
	(*newtree)->count = 0;
}

void Insert_BST(int ins_v,tree *t)
{
	tree_node *p,*prev,*tp;
	p = new tree_node;
	p->data = ins_v;
	p->left = NULL;
	p->right = NULL;
	if(IsEmpty(t)){
		t->root = p;
		t->count = 1;
	}
	else{
		tp = t->root;
		while(tp != NULL){
			prev = tp;
			if(p->data == tp->data){
				printf("\nValue %d Already Exists",p->data);
				tp = NULL;
			}
			else if(p->data > tp->data){
				tp = tp->right;
			}
			else{
				tp = tp->left;
			}
		}
		if(p->data > prev->data){
		    prev->right = p;
			t->count++;
		}
		else if(p->data < prev->data){
		    prev->left = p;
			t->count++;
		}
	}
}

void Delete_BST(int del_v,tree *t)
{
	tree_node *p,*prev,*tp;
	int tmp;
	if(IsEmpty(t)){
		printf("\nEmpty Tree");
	}
	else{
        p = t->root;
		while((p != NULL)&&(p->data != del_v)){
            prev = p;
			if(p->data<del_v)
                p = p->right;
			else
                p = p->left;
		}
		if(p == NULL){
			printf("\nNot found %d in tree.",del_v);
		}
		else{
			if((p->left == NULL)&&(p->right == NULL)){
				if(p == t->root)
					t->root = NULL;
				else{
					if(prev->data > del_v)
                        prev->left = NULL;
					else
                        prev->right = NULL;
				}
				delete p;
				t->count--;
			}
			else if((p->left == NULL)||(p->right == NULL)){
				if(p==t->root){
					if(p->right == NULL)
                        t->root = p->left;
					else
                        t->root = p->right;
				}
				else{
					if(prev->data > del_v){
						if(p->right == NULL)
                            prev->left = p->left;
						else
                            prev->left = p->right;
					}
					else{
						if(p->right == NULL)
                            prev->right = p->left;
						else
                            prev->right = p->right;
					}
				}
				delete p;
				t->count--;
			}
			else{
				tp = p->right;
				while(tp->left != NULL){
                    tp = tp->left;
                }
				tmp = tp->data;
				Delete_BST(tmp,t);
				t->count--;
				p->data = tmp;
			}
		}
	}
}

void inorder1(tree_node *tree)
{
	stack *st;
	tree_node *p;
	create_st(&st);
	p = tree;
	do{
		while(p!=NULL){
			push(p,&st);
			p = p->left;
		}
		if(!IsEmpty_st(st)){
			pop(&p,&st);
			printf(" %d",p->data);
			p = p->right;
		}
	}while((p != NULL)||(!IsEmpty_st(st)));
}

void preorder1(tree_node *tree)
{
	stack *st;
	tree_node *p;
	create_st(&st);
	p = tree;
	do{
		while(p!=NULL){
			printf(" %d",p->data);
			push(p,&st);
			p = p->left;
		}
		if(!IsEmpty_st(st)){
			pop(&p,&st);
			p = p->right;
		}
	}while((p != NULL)||(!IsEmpty_st(st)));
}

void inorder(tree_node *tree)
{
	if(tree!=NULL)
	{
		inorder(tree->left);
		printf(" %d",tree->data);
		inorder(tree->right);
	}
}

void preorder(tree_node *tree)
{
	if(tree!=NULL)
	{
		printf(" %d",tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
}

void postorder(tree_node *tree)
{
	if(tree!=NULL)
	{
		postorder(tree->left);
		postorder(tree->right);
		printf(" %d",tree->data);
	}
}

void inorder_re(tree_node *tree)
{
	if(tree!=NULL)
	{
		inorder_re(tree->right);
		printf(" %d",tree->data);
		inorder_re(tree->left);
	}
}

void preorder_re(tree_node *tree)
{
	if(tree!=NULL)
	{
		printf(" %d",tree->data);
		preorder_re(tree->right);
		preorder_re(tree->left);
	}
}

void postorder_re(tree_node *tree)
{
	if(tree!=NULL)
	{
		postorder_re(tree->right);
	    postorder_re(tree->left);
	    printf(" %d",tree->data);
	}
}
