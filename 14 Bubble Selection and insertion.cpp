#include <iostream>

using namespace std;
class sort
{
private:int n; double *p;
public:
    void get()
    {

        int i;
        cout<<"\nEnter count of Elements";
        cin>>n;
        p=new double[n];
        cout<<"\nEnter SGPA \n";
        for(i=0;i<n;i++)
        {
            cin>>p[i];
        }


    }
    void display()
    {
        cout<<"\n";
        for(int i=0;i<n;i++)
        {
            cout<<p[i]<<"\t";
        }
    }
    void bubble()
    {
        int pass;
        int i;
        cout<<"\nBUbble sort is";
            for(pass=1;pass<n-1;pass++)
            {
                for(i=0;i<n-pass;i++)
                {
                    if(p[i]>p[i+1])
                    {
                        double temp;
                        temp=p[i];
                        p[i]=p[i+1];
                        p[i+1]=temp;
                    }
                }
            }
    }
    void selection()
    {
    int i;
    int j;
    int min;
    double temp;
    for(i=0;i<n-1;i++)
        {
            min=i;
            {
                for(j=i+1;j<n;j++)
                {
                    if(p[j]<p[min])
                    min=j;
                }
                double temp;
                temp=p[i];

                p[i]=p[min];
                p[min]=temp;
            }
        }
    }
    void insertion()
    {
        double temp;
        int j;
        for(int i;i<n;i++)
        {
            temp=p[i];
            for( j=i-1;temp<p[j] && j>=0;j--)
            {
                p[j+1]=p[j];
            }
            p[j+1]=temp;
        }
    }

};

int main()
{
    sort s1;
    int c;
    int i=1;

   do
   {
        cout<<"\n1.bubble Sort";
        cout<<"\n2.Selection sort    ";
        cout<<"\n3.insertion Sort";
        cout<<"\n4.Exit    ";
        cin>>c;
        switch(c)
        {
            case 1:s1.get();s1.bubble();s1.display();break;
            case 2:s1.get();s1.selection();s1.display();break;
            case 3:s1.get();s1.insertion();s1.display();
            case 4:i=0;break;
        }
    }while(i);

}
