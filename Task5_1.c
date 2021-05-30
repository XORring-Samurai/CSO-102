#include<stdio.h>

struct queue
{
	int front, rear, deck[52];
};

int IsEmpty(int *head, int *tail)
{
	if(*head==-1 && *tail==-1)
	return 0;
	else
	return -1;
}

int IsFull(int *head, int *tail)
{
	if(IsEmpty(head, tail))
	{
		if((*head==0 && *tail==51) || (*tail == *head - 1))
		return 0;
		else
		return -1;
	}
	else
	printf("empty deck");
}

void PeekFront(int *head, int *tail, int *arr)
{
	if(IsEmpty(head, tail))
	{
		printf("%d", *(arr+*head));
	}
	else
	printf("empty deck");
}

void PeekRear(int *head, int *tail, int *arr)
{
	if(IsEmpty(head, tail))
	{
		printf("%d", *(arr+*tail));
	}
	else
	printf("empty deck");
}

void addFront(int *head, int *tail, int *arr, int data)
{
	if(IsEmpty(head, tail))
	{
		if(IsFull(head, tail))
		{
			if(*head==0)
			{
				*head=51;
				*(arr+*head)=data;
			}
			else
			{
				(*head)=(*head)-1;
				*(arr+*head)=data;
			}
		}
		else
		printf("deck is full");
	}
	else
	{
		*head=*tail=0;
		*(arr + *head) = data;
	}
}

void addRear(int *head, int *tail, int *arr, int data)
{
	if(IsEmpty(head, tail))
	{
		if(IsFull(head, tail))
		{
			if(*tail==51)
			{
				*tail=0;
				*(arr+*tail)=data;
			}
			else 
			{
				(*tail)=(*tail)+1;
				*(arr+*tail)=data;
			}
		}
		else
		printf("deck is full");
	}
	else
	{
		*head=*tail=0;
		*(arr+*tail)=data;
	}
}

void DrawFront(int *head, int *tail, int *arr)
{
	if(IsEmpty(head, tail))
	{
		if(*head==*tail)
		{
			printf("%d", *(arr+*head));
			*head=*tail=-1;
		}
		else if(*head<51)
		{
			printf("%d", *(arr+*head));
			*(head)=*(head)+1;
		}
		else if(*head==51)
		{
			printf("%d", *(arr+*head));
			*(head)=0;;
		}
	}
	else
	printf("deck is empty");
}

void DrawRear(int *head, int *tail, int *arr)
{
	if(IsEmpty(head, tail))
	{
		if(*head == *tail)
		{
			printf("%d", *(arr+*tail));
			*head = *tail = -1;
		}
		else if(*tail==0)
		{
			printf("%d", *(arr+*tail));
			*tail = 51;
		}
		else if (*tail>0)
		{
			printf("%d", *(arr+*tail));
			*(tail)=*(tail)-1;
		}
	}
	else
	printf("deck is empty");
}

int main()
{
	int n, m, i;
	struct queue q;
	q.front=q.rear=-1;
	
	scanf("%d %d", &n, &m);
	
	for(i=0; i<n; i++)
	{
		q.front=0;
		q.rear++;
		q.deck[i]=i+1;
	}
	
	while(m!=0)
	{
		char c[10];
		scanf("%s", c);
		
		if(!strcmp(c, "IsEmpty"))
		{
			int y;
			y = IsEmpty(&q.front, &q.rear);
			if(y==-1)
			printf("No");
			if(y==0)
			printf("Yes");
		}
		
		if(!strcmp(c, "IsFull"))
		{
			int y;
			y = IsFull(&q.front, &q.rear);
			if(y==-1)
			printf("No");
			if(y==0)
			printf("Yes");
		}
		
		if(!strcmp(c, "PeekFront"))
		{
			PeekFront(&q.front, &q.rear, q.deck);
		}
		
		if(!strcmp(c, "PeekRear"))
		{
			PeekRear(&q.front, &q.rear, q.deck);
		}
		
		if(!strcmp(c, "addFront"))
		{
			int c_no;
			scanf("%d", &c_no);
			
			addFront(&q.front, &q.rear, q.deck, c_no);
		}
		
		if(!strcmp(c, "addRear"))
		{
			int c_no;
			scanf("%d", &c_no);
			
			addRear(&q.front, &q.rear, q.deck, c_no);
		}
		
		if(!strcmp(c, "DrawFront"))
		{
			DrawFront(&q.front, &q.rear, q.deck);
		}
		
		if(!strcmp(c, "DrawRear"))
		{
			DrawRear(&q.front, &q.rear, q.deck);
		}
		
		m--;
	}
	
	return 0;
}


