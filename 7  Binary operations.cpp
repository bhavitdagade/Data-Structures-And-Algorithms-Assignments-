#include<iostream>
using namespace std;
struct node
{
    int bit;
    node *next;
    node *prev;
};
class a
{
private:
public: node *cn;
        node *header=NULL;

        node *nn;
        node *cn1;
        node *header1=NULL;

        node *nn1;
void accept();
void display();
void one_comp();
void two_comp();
void addition(a y,a z);
};
void a::accept()
{   int a;
    int i=1;
    cout<<"\nEnter total no of bits    ";
    cin>>a;
    header=NULL;
    while(i<=a)
    {
        cout<<"\nEnter bit      ";
        nn=new node;
        nn->next=nn->prev=NULL;
        cin>>nn->bit;
        if(header==NULL)
        {
            header=nn;
        }
        else
        {
            cn=header;
            while(cn->next!=NULL)
            {
                cn=cn->next;
            }
            cn->next=nn;
            nn->prev=cn;
            nn->next=NULL;
        }
        i++;
    }
    cout<<"\nBinary number is    ";
    display();
}
void a::one_comp()
{
    cn = header;
    while (cn != NULL)
    {
        if (cn->bit == 1)
        {
        cn->bit = 0;
        }
        else if (cn->bit == 0)
        {
        cn->bit = 1;
        }

        cn = cn->next;

    }
    cout<<"\n1's compliment is     ";
    display();


}
void a::two_comp()
{
    
    int carry = 1;
    node *ln;
    cn = header;
    while (cn != NULL)
    {
    ln = cn;
    cn = cn->next;
    }
    node *x;
    x = ln;
    while (x != NULL)
    {
        if ((x->bit == 1) && (carry == 0))
        {
        x->bit = 1;
        carry = 0;
        }
        else if ((x->bit == 0) && (carry == 1))
        {
        x->bit = 1;
        carry = 0;
        }
        else if ((x->bit == 1) && (carry == 1))
        {
        x->bit = 0;
        carry = 1;
        }
        x = x->prev;

        }
        cout<<"\nTwo's Compliment is   ";
        display();
}
void  a:: addition(a y,a z)
{
    header1=NULL;
    int sum=0;
    int carry=0;
    node *ln1;
    node *ln2;
    ln1=y.header;
    ln2=z.header;

    while(ln1->next!=NULL)
    {
        ln1=ln1->next;
    }

    while(ln2->next!=NULL)
    {

        ln2=ln2->next;
    }

    while(ln1!=NULL &&ln2!=NULL)
    {
        sum=(ln1->bit+ln2->bit +carry)%2;
        carry=(ln1->bit+ln2->bit +carry)/2;
        ln1=ln1->prev;
        ln2=ln2->prev;
        nn1=new node;
        nn1->bit=sum;
        nn1->next=nn1->prev=NULL;
        if(header1==NULL)
        {
            header1=nn1;
        }
        else
        {
        nn1->next=header1;
        header1->prev=nn1;
        header1=nn1;
        }
    }
    while(ln2==NULL && ln1!=NULL)
    {
         sum=(ln1->bit +carry)%2;
        carry=(ln1->bit +carry)/2;
        ln1=ln1->prev;

        nn1=new node;
        nn1->bit=sum;
        nn1->next=nn1->prev=NULL;
        if(header1==NULL)
        {
           header1=nn1;
        }
        else
        {
        nn1->next=header1;
        header1->prev=nn1;
        header1=nn1;
        }
    }
    while(ln1==NULL  && ln2!=NULL)
    {
        sum=(ln2->bit+carry)%2;
        carry=(ln2->bit+carry)/2;
        ln2=ln2->prev;

         nn1=new node;
        nn1->bit=sum;
        nn1->next=nn1->prev=NULL;
        if(header1==NULL)
        {
            header1=nn1;
        }
        else
        {
        nn1->next=header1;
        header1->prev=nn1;
        header1=nn1;
        }
    }
    if(carry==1)
    {
         nn1=new node;
        nn1->bit=carry;
        nn1->next=nn1->prev=NULL;
         nn1=new node;
        nn1->bit=carry;
        nn1->next=nn1->prev=NULL;
        if(header1==NULL)
        {
            header1=nn1;
        }
        else
        {
        nn1->next=header1;
        header1->prev=nn1;
        header1=nn1;
        }
    }
    cout<<"\nSum is  \t";
    cn1=header1;

    while(cn1!=NULL)
    {
        cout<<cn1->bit<<"\t";
        cn1=cn1->next;
    }
}
void a::display()
{
    cn=header;

    while(cn!=NULL)
    {
        cout<<cn->bit<<"\t";
        cn=cn->next;
    }
}

int main()
{

    a s1,s2,s3;
    int c;
    int i=1;
    do
    {
    cout<<"\nEnter (1). for 1's compliment     ";
    cout<<"\nEnter (2). for 2's compliment     ";
    cout<<"\nEnter (3). ADDition               ";
    cout<<"\nEnter (4). Exit               ";
    cin>>c;
    switch(c)
    {
        case 1:s1.accept();s1.one_comp();break;
        case 2: s1.accept();s1.one_comp();s1.two_comp();break;
        case 3:s1.accept(); s2.accept(); s3.addition(s1,s2);break;
        case 4:i=0;break;
    }


    }while(i);
}

