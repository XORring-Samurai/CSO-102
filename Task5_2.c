#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

struct queue
{
	struct node *front;
	struct node *rear;
};

void IsEmpty(struct node **head);
void IsFull(struct node **head);
void PeekFront(struct node **head);
void PeekRear(struct node **tail);
void addFront(struct node **head, int data);
void addRear(struct node **tail, int data);
void DrawFront(struct node **head);
void DrawRear(struct node **tail);

int main()
{
	int n, m, i;
	struct queue q;
	scanf("%d %d", &n, &m);
	
	if(n==0)
	q.front=q.rear=NULL;
	
	for(i=1; i<=n; i++)
	{
		struct node *newnode;
		newnode = (struct node *)malloc(sizeof(struct node));
		
		newnode->data=i;
		
		if(i==1)
		{
			newnode->prev=NULL;
			newnode->next=NULL;
			q.front=q.rear=newnode;
		}
		else
		{
			q.rear->next=newnode;
			newnode->prev=q.rear;
			newnode->next=NULL;
			q.rear=newnode;
		}
	}
   
	while(m!=0)
	{
		char c[10];
		scanf("%s", c);
		
			
		if(!strcmp(c, "IsEmpty"))
		{
			IsEmpty(&q.front);
		}
		
		if(!strcmp(c, "IsFull"))
		{
			IsFull(&q.front);
		}
		
		if(!strcmp(c, "PeekFront"))
		{
			PeekFront(&q.front);
		}
		
		if(!strcmp(c, "PeekRear"))
		{
			PeekRear(&q.rear);
		}
		
		if(!strcmp(c, "addFront"))
		{
			int c_no;
			scanf("%d", &c_no);
			addFront(&q.front, c_no);
		}
		
		if(!strcmp(c, "addRear"))
		{
			int c_no;
			scanf("%d", &c_no);
			addRear(&q.rear, c_no);
		}
		
		if(!strcmp(c, "DrawFront"))
		{
			PeekFront(&q.front);
			DrawFront(&q.front);
		}
		
		if(!strcmp(c, "DrawRear"))
		{
			PeekRear(&q.rear);
			DrawRear(&q.rear);
		}
		m--;
	}
	
	return 0;
}

void IsEmpty(struct node **head)
{
	if(*head==NULL)
	printf("Yes");
	else
	printf("No");
}

void IsFull(struct node **head)
{
	struct node *current;
	int c=0;
	current = *head;
	while(current!=NULL)
	{
		c++;
		current=current->next;
	}
	if(c==52)
	printf("Yes");
	else
	printf("No");
}

void PeekFront(struct node **head)
{
	if(*head==NULL)
	return;
	else
	printf("%d", (*head)->data);
}

void PeekRear(struct node **tail)
{
	if(*tail==NULL)
	return;
	else
	printf("%d", (*tail)->data);
}

void addFront(struct node **head, int data)
{
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	if(*head==NULL)
	{
		newnode->next=NULL;
		newnode->prev=NULL;
		*head = newnode;
	}
	else
	{
		newnode->next=*head;
		(*head)->prev=newnode;
		newnode->prev=NULL;
		*head=newnode;
	}	
}

void addRear(struct node **tail, int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=data;
	if(*tail==NULL)
	{
		newnode->next=NULL;
		newnode->prev=NULL;
		*tail = newnode;
	}
	else
	{
		(*tail)->next=newnode;
		newnode->prev=*tail;
		newnode->next=NULL;
		*tail=newnode;
	}
}

void DrawFront(struct node **head)
{
	struct node *p;
	if(*head==NULL)
	return;
	else
	{
		if((*head)->next!=NULL)
		{
			p=(*head)->next;
	     	free(*head);
		    *head = p;
		    (*head)->prev=NULL;
		}
		else
		{
			free(*head);
			*head = NULL;
		}
		
	}
}

void DrawRear(struct node **tail)
{
	struct node *p;
	if(*tail==NULL)
	return;
	else
	{
		if((*tail)->prev != NULL)
		{
			p=(*tail)->prev;
		    free(*tail);
		    *tail = p;
		    (*tail)->next=NULL;
		}
		else
		{
			free(*tail);
			*tail=NULL;
		}
		
	}
}


