#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{ char cname[25];
  char status[5];
  struct node *next;
};

void add(struct node **head, char *c, char *s, int l1, int l2);
void del(struct node **head);
void display(struct node **head, char *s, int y, int *z);

int main()
{
	struct node *first = NULL;
	int n, m, i=0, j, k;
	char x[100][1000];
	int l[100];
	
	first = (struct node *)malloc(sizeof(struct node));
	scanf("%d %d", &n, &m);
	
	first->cname[0] = 'P';
	first->status[0] = 'N';
	first->status[1]='P';
	first->next = NULL;

	while(m!=0)
	{ char str[10];
	  scanf("%s", str);
	  
	  if(!strcmp(str,"ADD"))
	  { char cname[25], status[5];
	    int l1, l2;
	    scanf("%s %s", cname, status);
	    l1 = strlen(cname);
	    l2 = strlen(status);
	    add(&first, cname, status, l1, l2);
	  }
	  
	  else if(!strcmp(str,"DEL"))
	  del(&first);
	  
	  else 
	  { char s[1000];
	    display(&(first->next), s, 1000, &l[i]);
	    
	    for(j=0; j<strlen(s); j++)
	    x[i][j]=s[j];
	    
		i++;
      }
      
	  m--;
	}
	for(j=0; j<i; j++)
	{ for(k=0; k<l[j]; k++)
	  printf("%c", x[j][k]);
	  printf("\n");
	}
	
	
	return 0;
}

void add (struct node **head, char *c, char *s, int l1, int l2)
{ struct node *p, *q, *newnode;
  int i;
  newnode = (struct node *)malloc(sizeof(struct node));
  p = *head;
  while(p!=NULL)
  { q = p;
    p = p->next;
  }
  if(p==NULL)
  { q->next = newnode;
    newnode->next=NULL;
    
    for(i=0; i<l1; i++)
    newnode->cname[i]=*(c+i);
    
    for(i=0; i<l2; i++)
    newnode->status[i]=*(s+i);
  }
}

void del(struct node **head)
{ struct node *q, *p, *r;
  q = *head;
  p = q->next;
  r = NULL;
  
  if(*head==NULL)
  printf("empty list");
  
  else
  {
    while(p!=NULL)
    { if(q->status[0]=='P')
	  { r->next = p;
	    free(q);
	    q = p;
	    p = p->next;
      }
      else
      {
	  r = q;
      q = p;
      p = p->next;
      }
	}
	if(p==NULL)
	{ if(q->status[0]=='P')
	  { r->next = NULL;
	    free(q);
	  }
	}
  }
}

void display(struct node **head, char *s, int y, int *z)
{ struct node *current, *p;
  int i, j=0, t=0;
  
  current = *head;
  
  if(*head == NULL)
  { for(i=0; i<y; i++)
    s[i]='\0';
  }
  
  else
  { while(current!=NULL)
    { for(i=0; i<strlen(current->cname); i++)
      { s[j]=current->cname[i];
        j++;
      }
      s[j]=' ';
	  j++;
      t = t + strlen(current->cname)+ 1;
	  current=current->next;
	} 
  }
  *z = t;
}
