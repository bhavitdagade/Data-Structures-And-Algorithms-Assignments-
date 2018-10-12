

#include <cstdlib>
#include<iostream>
using namespace std;

struct node {
    char status;
    node *next;
    node *prev;
};

class cinema {
private:
public:
    node *cn;
    node *nn;
    node *header = NULL;
    void initial()
    {   int j;
        for(j=0;j<7;j++)
        {
            nn=new node;
            nn->status='A';
            nn->next=NULL;
            nn->prev=NULL;
            cn=header;
            if(header==NULL)
            {
                header=nn;
                nn->next=header;
                nn->prev=header;
                
            }
            else
            {
                cn=header;
                nn->status='A';
                while(cn->next!=header)
                {
                    cn=cn->next;
                }
                cn->next=nn;
                nn->prev=cn;
                nn->next=header;
                header->prev=nn;
            }
                
        }
    }
    
    void display()
    {
        cn=header;
        do
        {
            cout<<cn->status;
            cout<<"  ";
            cn=cn->next;
        }while(cn!=header);
        cout<<"\n";
    }
    void book(int x)
    {
        int i;
        cn=header;
        for(i=1;i<x;i++)
        {
            cn=cn->next;
        }
        if(cn->status=='A')
        {
            cout<<"\n it is avilable for booking and your seat is booked\n";
            cn->status='B';
        }
        else
        {
            cout<<"\n Sorry seat is booked  \n";
        }
    }
    void cancel(int y)
    {
        int i;
        cn=header;
        for(i=1;i<y;i++)
        {
            cn=cn->next;
        }
        if(cn->status=='B')
        {
            cout<<"\n yep now its is available   \n";
            cn->status='A';
        }
        else
        {
            cout<<"\n Sorry seat is alredady available  \n";
        }
        
    }
};

int main(int argc, char** argv) {
    cinema s1[10];
    int a;
    int i = 1;int j;
    int row;
    int col;
    do {
        cout << "\nEnter (1) to see the status of bookings\n";
        cout << "Enter (2) to book ticket\n";
        cout << "Enter (3) to cancel the ticket bookings\n";
        cout << "Enter (4) to exit              ";
        cin>>a;
        switch (a) {
            case 1:for(i=0;i<10;i++)
            {
                s1[i].initial();
            }
            for(i=0;i<10;i++)
            {
                s1[i].display();
            }
            break;
            case 2:cout<<"\nEnter row and column repectively  to book seat \n ";
                   cin>>row>>col;
                    if((row>0&&row<11)&&(col>0&&col<8))
                    {
                        s1[row-1].book(col);
                        
                    }
                   for(i=0;i<10;i++)
            {
                s1[i].display();
            }break;
            case 3:cout<<"\nEnter row and column repectively  to CANCEL seat \n ";
                   cin>>row>>col;
                    if((row>0&&row<11)&&(col>0&&col<8))
                    {
                        s1[row-1].cancel(col);
                        
                    }
                   for(i=0;i<10;i++)
            {
                s1[i].display();
            }
                break;
            case 4:i = 0;break;


        }
    } while (i);
    return 0;
}


