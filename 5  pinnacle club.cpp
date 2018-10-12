#include<iostream>
using namespace std;
struct node
{
    char name[20];
    int prn;
    node* next;
};
class pinna
{
private:int cou;  
public:
    node *cn,*nn,*header=NULL;
       node *header1;
    node *header2;
    pinna()
    {
          header1=NULL;
    header2=NULL;
    }
    node* accept();
    void display(node *header);
    void count(node *header);
    void d_mem(node *header);
    void add(node *header);
    void rev(node *cn);
    void extra();
    void concate(node *a,node *b);
};
node* pinna:: accept()
{
    int a;
    
    cout<<"\nEnter Count of members";
    cin>>a;
    while(a)
    {
        nn=new node;
        cout<<"\nName\t";
        cin>>nn->name;
        cout<<"\nPRN NO\t";
        cin>>nn->prn;
        nn->next=NULL;
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
            nn->next=NULL;
        }
        a--;
    }
    return header;
}
void pinna::display(node *head)
{
    cn=head;
    cout<<"President\t";
    cout<<cn->name<<"\t";
    cout<<cn->prn<<"\n";
    cn=cn->next;
    while(cn->next!=NULL)
    {
        cout<<"Member\t\t";
        cout<<cn->name<<"\t";
        cout<<cn->prn<<"\n";
        cn=cn->next;
    }
    cout<<"Secretary\t";
    cout<<cn->name<<"\t";
    cout<<cn->prn<<"\n";
    
}


void pinna::d_mem(node *header)
{
    int test;
    int temp;
    int c=1;
    cout<<"\nEnter Prn no";
    cin>>test;
    cn=header;
    while(cn->next!=NULL)
           {
              temp=cn->prn;
              if(test==temp)
              {

                  cout<<"\nMEMBER IS Found";
                  break;
              }
              c++;
              cn=cn->next;
           }
    if(c==1)
    {
        cn=header;
        header=cn->next;
    }
    else if(c>1 && c<cou)
    {
        cn->next=cn->next->next;

    }
    else if(c==cou)
    {
        cn=header;
           while(cn->next->next!=NULL)
           {
               cn=cn->next;
           }
           cn->next=NULL;
    }
}
   void pinna::count(node *header)
   {
       cou=0;
       cn=header;
       while(cn!=NULL)
       {
           cou++;
           cn=cn->next;
       }
       cout<<"\nTotal nodes are"<<cou;
   }

void pinna ::add(node *header)
{
    int c;
    cout<<"\n1.update president";
    cout<<"\n2.adding member";
    cout<<"\n3.update secretary";
    cin>>c;
    switch(c)
    {
        case 1:
        {
            cn=header;
               cout<<"\nName\t";
               cin>>cn->name;
               cout<<"\nPRN NO\t";
               cin>>cn->prn;
             
               cout<<"\nPresident updated succesfully";
        }break;
        case 2:
        {
            nn=new node;
            cout<<"\nName\t";
            cin>>nn->name;
            cout<<"\nPRN NO\t";
            cin>>nn->prn;
        
            int i;
            cn=header;
            for(i=1;i<cou-1;i++)
            {
                cn=cn->next;
            }
            nn->next=cn->next;
            cn->next=nn;
             cout<<"\nMemeber added succesfully";
        }
            break;
        case 3:{
            cn=header;
            while(cn->next!=NULL)
            {
                cn=cn->next;
            }
            cout<<"\nName\t";
            cin>>cn->name;
            cout<<"\nPRN NO\t";
            cin>>cn->prn;
            cout<<"\nSecretary updated succesfully";
        }break;
        
    
  
    }
}
void pinna::rev(node *cn)
{
    if(cn->next!=NULL)
    {
        rev(cn->next);
    }
    cout<<cn->name<<"\t"<<cn->prn<<"\n";
           
}
void pinna :: extra()
{
    cn=header;
    rev(cn);
}
void pinna ::concate(node *a,node *b)
{
    node *sn;
           sn=a;
    while(sn->next!=NULL)
    {
        sn=sn->next;
    }
    sn->next=b;
    cout<<"\nconctenation done\n";
     
    
}
int main()
{
    pinna s1,s2,s3,s4,s9;
    int c;
    int d;
    int i=1;
    cout<<"1. link 1";
    
    cin>>c;
    switch(c)
    {
        case 1:
            do
            {
            cout<<"\n1. store memebers";
            cout<<"\n2.add/update president/members/seretary";
            cout<<"\n3.delete members,president,secretary";
            cout<<"\n4.Display";
            cout<<"\n5 Reverse node";
            cout<<"\n6 concatenation";
            cout<<"\n7.i=0"<<"\t";
            cin>>d;
            switch(d)
            {
                case 1:s1.header1=s1.accept();break;
                case 2:s1.count(s1.header1);s1.add(s1.header1);break;
                case 3:s1.count(s1.header1);s1.d_mem(s1.header1);break;
                case 4:s1.display(s1.header1);break;
                case 5:s1.extra();break;
                case 6:{
                        s1.header1=s1.accept();
                        s9.header1=s9.accept();
                        s1.concate(s1.header1,s9.header1);
                        s1.display(s1.header1);
                }
                break;
                case 7:i=0;break;   
            }
            }while(i);break;
            
        
            
            
    }
            
}
