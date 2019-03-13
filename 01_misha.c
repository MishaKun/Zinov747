#include <stdio.h>
#include<stdlib.h>

struct node { 
 	int v;
	struct node *next;
} node;

struct list{		
	struct node* first;	
} list;

int isEmpty(struct list* struc)
{
	return struc->first==NULL;
}

struct node* find(struct list* struc,int value)
{
	struct node *t=struc->first;
	while(t->v!=value){
		if(t->next!=NULL)
			t=t->next;
		else
			return 0;
	}
	return t;
}

void init(struct list* struc,int value)
{
	struct node* t;
	t = (struct node*)malloc(sizeof(struct node));
	t->v=value;
	t->next=NULL;
	struc->first = t;
}

int push_back(struct list* struc, int x)
{
	if(isEmpty(struc)==1)
		init (struc,x);
	else
	{
		struct node* t = (struct node*)malloc(sizeof(struct node));
		t->v=x;
		t->next=NULL;
		struct node* te = struc->first;
		while(te->next!=NULL)
			te=te->next;
		te->next=t;
	}
	return 0;
}

int push_front(struct list* struc,int x) 
{
	if(isEmpty(struc)==1)
		init (struc,x);
	else
	{
		struct node *t = (struct node*)malloc(sizeof(struct node));
		t->v=x;
		t->next=struc->first;
		struc->first=t;
	}
	return 0;
}

int clear(struct list* struc)
{
	if(isEmpty(struc)==1)
	{
		struct node *t=struc->first;
		struct node *te=NULL;
		while(t!=NULL)
		{
			te=t->next;
			free(t);
			t=te;
		}
		struc->first=NULL;
	}
}

void _remove(struct list* struc, struct node *t){
	if(t!=NULL){
		if (t==struc->first)
			struc->first=t->next;
		else
		{
			struct node *te = (struct node*)malloc(sizeof(struct node));
			te=struc->first;
			while(te->next!=t)
				te=te->next;
			te->next = t->next;
		}
		free(t);
	}
}

int removeFirst(struct list* struc, int x)
{
	struct node* element = find(struc,x);
	if (element!=NULL){
		_remove(struc,element);
		return 0;
	}
	return -1;
}

int insertAfter	(struct list* struc,int num, int value)
{
	struct node *te = malloc(sizeof(node));
	te->v=value;

	struct node* t = struc->first;
	struct node* prev_t = struc->first;
	
	for (int i = 1;i<num+1;i++)
	{
		prev_t=t;
		t=t->next;
		if(t==NULL) 
			return -1;
	}
	prev_t->next=te;
	te->next=t;
	return 0;   
}

void print(struct list* struc)
{
	struct node* t=struc->first;
	while(t->next!=NULL)
	{
		printf("%d ", t->v);
		t=t->next;
	}
	printf("%d\n", t->v);
}

int main()
{
	int a,y,k[3],m,t,j,x,z;
    struct list* list=(struct list*)malloc(sizeof(struct list));	
	scanf("%d",&a);
	for (int i=0;i<a;i++)
	{
		scanf("%d",&y);
		push_back(list,y);
	}
	print(list);
        scanf("%d%d%d",&k[0],&k[1],&k[2]);
	for(int i=0;i<3;i++){
		if(find(list,k[i])!=NULL)
			printf("1 ");
		else
			printf("0 ");
	}
	printf("\n");
	scanf("%d",&m);
	push_back(list,m);
	print(list);
	scanf("%d",&t);
	push_front(list,t);
	print(list);
	scanf("%d%d",&j,&x);
	insertAfter(list,j,x);
	print(list);
	scanf("%d",&z);
	removeFirst(list,z);
	print(list);
	clear(list);
	return 0;
}
