#include <iostream>
#define size 5

using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
};
class dq
{
    public:node *nn; node *front;
    node *rear;
    dq()
    {
        front=NULL;
        rear=NULL;
    }
    void insert_r()
    {
        nn=new node;
        nn->next=NULL;
        nn->prev=NULL;

        cout<<"\nEnter data    ";
        cin>>nn->data;
        if(front==NULL && rear==NULL)
        {
            front=nn;
            rear=nn;
        }
        else
            {
                rear->next=nn;
                nn->prev=rear;
                rear=nn;
            }
    }
    void insert_f()
    {
         nn=new node;
        nn->next=NULL;
        nn->prev=NULL;

        cout<<"\nEnter data    ";
        cin>>nn->data;
        if(front==NULL && rear==NULL)
        {
            front=nn;
            rear=nn;
        }
        else
            {
                nn->next=front;
                front->prev=nn;
                front=nn;

            }

    }
    void delete_f()
    {
            if(front==NULL)
            cout<<"\nElement cannont be deleted as no presence of element ";
            else
            {
            front=front->next;
            }
    }
    void delete_e()
    {
        if(front==NULL)
            cout<<"\nElement cannont be deleted as no presence of element ";
            else
            {
            rear=rear->prev;
            rear->next=NULL;
            }

    }
    void display()
    {
        cout<<"\nDequeue   is";
        node *cn;
        cn=front;
        while(cn!=NULL)
        {
            cout<<cn->data<<"\t";
            cn=cn->next;
        }

    }
};

int main()
{

    dq s1;
    int c;
    int i=1;
    do
    {
        cout<<"\n1.adding element at front   ";
        cout<<"\n2.adding element at end     ";
        cout<<"\n3.deleting element at front ";
        cout<<"\n4.deleting element at end   ";
        cout<<"\n5.Displaying Elements       ";
        cout<<"\n6.Exit                      ";
        cin>>c;
            switch(c)
            {
                case 1:s1.insert_f();s1.display();break;
                case 2:s1.insert_r();s1.display();break;
                case 3:s1.delete_f();s1.display();break;
                case 4:s1.delete_e();s1.display();break;
                case 5:s1.display();break;
                case 6:i=0;break;
            }
    }while(i);
}
