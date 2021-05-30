#include<stdio.h>
#include<string.h>

struct stack
{ int top1;
  int top2;
  char symbol[100];
};

void push (struct stack *s, char index);
void pop (struct stack *s);
int prec (char c);

int main()
{
  char infix[100], postfix[100];
  struct stack s1;
  int l, i, j=0, k;
  
  gets(infix);
  l = strlen(infix);
  s1.top1 = 0;
  s1.top2 = -1;
  
  for(i=0; i<l; i++)
  { 
    if(infix[i]>=49 && infix[i]<=57)
      { postfix[j]=infix[i];
        j++;
	  }

	else if(infix[i]=='(')
	push (&s1, infix[i]);
	
	  else if(infix[i]==')')
	  { while(s1.symbol[s1.top2]!='(')
	    { if(s1.symbol[s1.top2]!='(')
	      { postfix[j]=s1.symbol[s1.top2];
	        j++;
		  }
		  pop(&s1);
	    }
	    pop(&s1);
	  }
	
	  else
	  {  if(s1.top1==0)
	     push(&s1, infix[i]);
	   
	     else
	     { if( prec(s1.symbol[s1.top2]) > prec(infix[i]))
           { 
		    while(prec(s1.symbol[s1.top2]) >= prec(infix[i]))
		    { postfix[j]=s1.symbol[s1.top2];
              j++;
              pop(&s1);
            }
            push(&s1,infix[i]);
         }
         else if( prec(s1.symbol[s1.top2]) < prec(infix[i]))
         push(&s1, infix[i]);
         
         else 
         { postfix[j]=s1.symbol[s1.top2];
           j++;
		   pop(&s1);
           push(&s1, infix[i]);
		 }
	   }
	}
	if(i==l-1)
    { while(s1.top1!=0)
      { postfix[j]=s1.symbol[s1.top2];
        j++;
        pop(&s1);
	  }
	}
   }
  
   puts(postfix);
  
  return 0;
}
int prec(char c)
{ if(c=='+'||c=='-')
  return 1;
  if(c=='/'||c=='*')
  return 2;
  if(c=='(')
  return 0;
}
void push (struct stack *s, char index)
{ s->symbol[s->top1] = index;
  s->top1++;
  s->top2++;
}
void pop (struct stack *s)
{ s->top2--;
  s->top1--;
}
