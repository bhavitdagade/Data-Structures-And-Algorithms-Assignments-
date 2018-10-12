
#include<iostream>
using namespace std;

class stack
{
private:char a[30];
	char b[30];
	int top;
public:stack()
{
	top=-1;
}
void push(char s)
{
	//top++;
	b[++top]=s;
}
int stack_empty()
{
	if(top==-1)
	return 1;
	else 
	return 0;
}
void pop()
{
	char w;
	w=b[top];
	top--;
}

int cal(int e)
{
	int i;
	cin>>a;
	
	char r;
	
	for(i=0;i<e;i++)	
	{
		if(a[i]=='[' ||a[i]=='('||a[i]=='{')
		{
		push(a[i]);
               
		}
		else if(a[i]==']' ||a[i]==')'||a[i]=='}')
		{
		
			if(a[i]==']')
			{
                            r=b[top];
                           
                            if(r=='[')
                            { pop();
                            }
                            else 
                                return 1;
			}
			if(a[i]==')')
			{
			 r=b[top];
                          if(r=='(')
                            { pop();
                            }
                            else 
                                return 1;
                            
			}
			if(a[i]=='}')
			{
			 r=b[top];
                          if(r=='{')
                            { pop();
                            }
                            else 
                                return 1; 
			}
			
			
				
			
		}
	}
        if(top!=-1)
			{
                            
                            return  1;
			}
      
	
}
};
int main()
{
	int l;
	int m;
	stack s1;
	cout<<"\nEnter the length";
	cin>>l;
	
	m=s1.cal(l);
	if(m==1)
	{
		cout<<"\n unbalanced";
	}
        else
	{
		cout<<"\n balanced";
	}
	
}
