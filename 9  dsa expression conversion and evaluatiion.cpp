#include<iostream>
#include<string.h>
using namespace std;
struct stack1
{
    char stack[20];
    int top=-1;
}st;
struct stack12
{
    int s1[20];
    int top1=-1;
}st1;
void push(char x)
{
    st.stack[++st.top]=x;
}
char pop()
{
    if(st.top==-1)
    {
        return -1;
    }
    else
    {
        return st.stack[st.top--];
    }
}
void push1(int t)
{
    st1.top1++;
    st1.s1[st1.top1]=t;
    
}
int pop1()
{
    int a;
    a=st1.s1[st1.top1];
    st1.top1--;
    return a;
}
int priority(char x)
{
    if(x=='(')
    {
        return 0;
    }
    if(x=='+' ||x=='-')
    {
        return 1;
    }
    if(x=='*'||x=='/')
    {
        return 2;
    }
    
}
int main()
{
    int i=1;
    do
    {
    int choice;
    cout<<"\n1. For Infix to Postfix Expression";
    cout<<"\n2. For Expression Evaluation      ";
    cout<<"\n3.Exit                            ";
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            char exp[20];
            char *e,x;
            cout<<"\nEnter Infix expression  ";
            cin>>exp;
            e=exp;
            while(*e!='\0')
            {
                if((isalnum(*e))  && (*e!='(') &&(*e!=')'))
                {
                    cout<<(*e);
                }
                else if(*e=='(')
                {
                    push(*e);
                }
                else if(*e==')')
                {
                    while((x=pop())!='(')
                    {
                        cout<<x;
                    }
                }
                else
                {
                    while(priority(st.stack[st.top])>=priority(*e))
                    {
                        cout<<pop();
                    }
                    push(*e);
                         
                }
                e++;
            }
            while(st.top!=(-1))
            {
                cout<<pop();
            }
        }break;
        case 2:
        {
          char exp[20];
            int len;
            int i;
            int d;
            int x,y,z;
            cout<<"\n Enter expression to be evluated\n";
            cin>>exp;
            len=strlen(exp);
            for(i=0;i<len;i++)
            {
        
                    if(exp[i]>=48 &&exp[i]<=57)
                    {

                         push1(exp[i]-'0');
                    }

                     else if(exp[i]>=42 &&exp[i]<=47)
                    {
                    x=pop1();
                    y=pop1();
                    switch(exp[i])
                    {
                    case '+':push1(y+x);
                    break;
                    case '-':push1(y-x);
                    break;
                    case '*':push1(y*x);
                    break;
                    case '/':push1(y/x);
                    break;

                    }

                    }
                }
                cout<<pop1();
            
            
            
        }break;
        case 3:i=0;break;
    }
    }while(i);
}