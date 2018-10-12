#include<iostream>
#define size 5
using namespace std;
class cq
{
private:
    struct queue
    {
        int que[size];
        int front,rear;
    }q;
public:cq()
{
    q.front=-1;
    q.rear=-1;
}
    int qfull()
    {
        if(q.front==((q.rear+1)%size))
            return 1;
        else 
            return 0;
    }
    int qempty()
    {
        if(q.front==-1)
        {
            return 1;
        }
        else 
            return 0;
    }
    void accept(int item)
    {
        if(q.front==-1)
        {
            q.front=0;
            q.rear=0;
            q.que[q.rear]=item;
            q.rear=(q.rear+1)%size;
        }
        else if(qfull())
        {
            cout<<"\nWait order is currently Full";
            
        }
        else
        {
            q.que[q.rear]=item;
            q.rear=(q.rear+1)%size;
        }
    }
    void ready()
    {
        int t;
        cout<<"\nEnter the order number  ";
        cin>>t;
        cout<<"\norder no  "<<t<<" is ready";
        q.front=(q.front+1)%size;
    }
    void display()
    {
        int i;
        i=q.front;
        while(i!=q.rear)
        {
            cout<<q.que[i];
            i=(i+1)%size;
        }
    }
};
int main()
{
    cq s1,s2,s3;
    int c;
    int order;int i=1;
    do
    {
        cout<<"\n1.Add order in queue  ";
        cout<<"\n2.For item ready      ";
        cout<<"\n3.To Display Queue    ";
        cout<<"\n4.Exit";
        cin>>c;
        switch(c)
        {
            case 1:cout<<"\nEnter order no     ";
            cin>>order;
            s1.accept(order);
            break;
            case 2:s1.ready();break;
            case 3:s1.display();break;
            case 4:i=0;break;
        }
    }while(i);
}
