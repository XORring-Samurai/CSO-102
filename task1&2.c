#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct stack
{ int top1;
  int top2;
  int *ptr;
};

void push1 (struct stack *a1, int b1, int *c1);
void pop1 (struct stack *a1, int *c1);
void push2 (struct stack *a2, int b2, int *c2);
void pop2 (struct stack *a2, int *c2);

int main()
{ int n, m, operation, stack_no, index;
  static int *h_l, *s_p, *m_c, *n_r;
  struct stack s1, s2;
  int i, top_2, top_1, j=0, k, t;
  float sum=0, mean, median, s_d, sum1;
  int count=1, p=0, mode,c=1, l=0;
  float y3,z3, y2,z2;
  int x3, x2, x1, rem;

  
  
  printf("enter the time duration of the podcast");
  scanf("%d",&n);
  printf("enter the number of steps performed by howard's laptop");
  scanf("%d",&m);
  h_l = (int*)malloc(n*sizeof(int));
  s_p = (int*)malloc(n*sizeof(int));
  s2.top2=n-1;
  s2.ptr=h_l;
  s1.top1=0;
  s1.ptr=h_l;
  top_2 = n;
  top_1 = -1;
  
  do
  { printf("1=push, 2=pop");
    scanf("%d",&operation);
    printf("1=stack1, 2=stack2");
    scanf("%d",&stack_no);
    printf("input index, -1 if operation=pop");
    scanf("%d",&index);
    if(index!=-1)
    { s_p[j]=index;
      j++;
	}
    
    if(operation==1)
    { if(stack_no==1)
      push1 (&s1, index, &top_1);
      if(stack_no==2)
      push2 (&s2, index, &top_2);
    }
    if(operation==2)
    { if(stack_no==1)
      pop1 (&s1, &top_1);
      if(stack_no==2)
      pop2 (&s2, &top_2);
    }
    m--;
  }while(m!=0);
  
  for(i=0;i<j;i++)
  { for(k=i+1; k<j; k++)
    { if(s_p[i]>s_p[k])
      { t = s_p[i];
        s_p[i] = s_p[k];
        s_p[k] = t;
	  }
	}
  }
  
  for(i=0;i<j;i++)
  sum = sum + s_p[i];
  mean = sum/j;
  x2 = mean * 10;
  y2 = x2;
  z2 = x2/10;
  printf("%.1f ",z2);
  
  if(j%2==0)
  median = (s_p[j/2]+s_p[j/2 - 1])/2;
  else
  median = s_p[j/2];
  
  x1=median*10;
  rem=x1%10;
  if(rem%2==0)
  printf("%.0f ",median);
  else
  printf("%.1f ",median);
 
  
  
  for(i=0;i<j-1;i++)
  { if(s_p[i]!=s_p[i+1])
    count++;
  }
  
  m_c = (int*)malloc(count*2* sizeof(int));
  n_r = (int*)malloc(count * sizeof(int));
  
  n_r[0]=s_p[0];
  for(i=0;i<j-1;i++)
  { if(s_p[i]!=s_p[i+1])
    {n_r[c]=s_p[i+1];
     c++;
    }
  }
  
  for(i=0;i<count*2;i++)
  { if((i+1)%2!=0)
    m_c[i]=1;
    if((i+1)%2==0)
    m_c[i]=n_r[(i-1)/2];
  }
  
  for(i=0;i<j-1;i++)
  { if(s_p[i]==s_p[i+1])
	m_c[p]++;
    if(s_p[i]!=s_p[i+1])
    p=p+2;
  }
  
  for(i=0;i<count*2-2;i++)
  { if(m_c[i]==m_c[i+2])
    l++;
  }
  if(l==count-1)
  printf("  ");
  else
  {
  c=m_c[0];
  for(i=0;i<count*2;i=i+2)
  {   if(c<m_c[i])
      c = m_c[i];
  }
  for(i=0;i<count*2;i++)
  { if(c==m_c[i])
    {
	mode = m_c[i+1];
    printf("%d ",mode);
    }
  }
  }
  
  for(i=0;i<j;i++)
  sum1 = sum1 + pow((s_p[i]-mean),2);
  s_d = sqrt(sum1/j);
  x3 = s_d*100;
  y3 = x3;
  z3 = y3/100;
  printf("%.2f",z3);
  
  
  printf("\n");
  for(i=top_1;i>=0;i--)
  printf("%d ",h_l[i]);
  printf("\n");
  for(i=top_2; i<n; i++)
  printf("%d ",h_l[i]);
  return 0;
}


void push1 (struct stack *a1, int b1, int *c1)
{ *(a1->ptr+a1->top1)= b1;
  a1->top1++;
  (*c1)++;
}
void pop1 (struct stack *a1, int *c1)
{ a1->top1--;
  (*c1)--;
}
void push2 (struct stack *a2, int b2, int *c2)
{ *(a2->ptr + a2->top2)= b2;
  a2->top2--;
  (*c2)--;
}
void pop2 (struct stack *a2, int *c2)
{ a2->top2++;
  (*c2)++;
}

