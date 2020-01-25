#include<stdio.h>
#include<malloc.h>

struct node{
	int value, visited;
	struct node *firstChild, *nextSib;
};


struct node *makeTree(struct node *);
struct node *makeFirstChild(struct node *, int);
struct node *makeNextSib(struct node *, int);
struct node *checkNode(struct node *);
void print_tree(struct node *);

void main(){
	struct node *genTree;
	genTree = NULL;
	makeTree(genTree);
}

struct node *makeTree(struct node *tempTree){
	struct node *head, *p, *root;
	int n, x, firstChild, nextSib, index, value_first;
	if(tempTree == NULL){
		printf("\nEnter your root node value:- ");
		scanf("%d", &x);
		head = (struct node *)malloc(sizeof(struct node));
		head ->value = x;
		head->nextSib = NULL;
		head->firstChild = makeFirstChild(head, x);
		root = head;
	}
	head = checkNode(head);
	print_tree(root);
	printf("\n");
}


void print_tree(struct node *head){
	if(head != NULL){
		printf("%d->", head->value);
		if(head->firstChild != NULL){
			print_tree(head->firstChild);
			print_tree(head->nextSib);
		}else if(head->nextSib != NULL){
			print_tree(head->firstChild);
			print_tree(head->nextSib);
		}
	}
}

struct node *checkNode(struct node *head){
	struct node *prev_node;
	int prev_value;
	if(head->firstChild != NULL && head->visited == 0){
		head = head->firstChild;
		prev_value = head->value;
		head->firstChild = makeFirstChild(head, prev_value);
		checkNode(head);
		head->visited = 1;
		head->nextSib = makeNextSib(head, prev_value);
		checkNode(head);
		return head;
	}
	if(head->nextSib != NULL){
		head = head->nextSib;
		prev_value = head->value;
		head->firstChild = makeFirstChild(head, prev_value);
		checkNode(head);
		head->visited = 1;
		head->nextSib = makeNextSib(head, prev_value);
		checkNode(head);
		return head;
	}
}

struct node *makeFirstChild(struct node *temp, int node_value){
	int val;
	struct node *p;
	p = (struct node *)malloc(sizeof(struct node));
	p->visited = 0;
	printf("\nEnter the value of First Child of %d:- ", node_value);
	scanf("%d", &val);
	if(val == -1){
		return NULL;
	}else{
		p->value = val;
		return p;
	}
}

struct node *makeNextSib(struct node *temp, int node_value){
	int val;
	struct node *p;
	p->visited = 0;
	p = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the value of Next Sib of %d:- ", node_value);
	scanf("%d", &val);
	if(val == -1){
		return NULL;
	}else{
		p->value = val;
		return p;
	}
}
