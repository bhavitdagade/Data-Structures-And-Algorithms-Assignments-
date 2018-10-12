
	
	

#include <cstdlib>
#include<iostream>
using namespace std;
class set
{
private:
    int cric, bad,num,i=0,j=0,k=0,flag;
    int c[20],b[20],d[20];int arr[20];
 public:  
    void get();
    void union1();
    void inter();
    void onlycric();
    void onlybad();
    void ncnorb();
};
void set:: get()
{   
    cout<<"\nenter  total number of students class      ";
    cin>>num;
    cout<<"\nenter total roll numbers of class    ";
    cout<<"\n";
    for(i=0;i<num;i++)
    {
        cout<<"\nenter roll number  ";
        cin>>arr[i];
    }
    cout<<"\nenter students playing cricket      ";
    cin>>cric;
    for(i=0;i<cric;i++)
    {
        cout<<"\nenter roll number  ";
        cin>>c[i];
    }
    cout<<"\nenter number of students playing badminton";
    cin>>bad;
    for(i=0;i<bad;i++)
    {
        cout<<"\nenter roll number  ";
        cin>>b[i];
    }
 }
void set::union1()
{ flag=0;
    for(i=0;i<cric;i++)
    {
        d[k]=c[i];
        k++;
    }
    for(j=0;j<bad;j++)
    { 
        for(i=0;i<cric;i++)
        {
            if(b[j]==c[i])
            {
                flag=1;break;
            }
        }
        if(flag==0)
        {
            d[k]=b[j];
            k++;
        }
        flag=0;
    }
    cout<<"\ntherefoe the union is     ";
    for(i=0;i<k;i++)
    {
        cout<<d[i]<<" ,";
    }
}
void set:: onlycric()
{    cout<<"\nthe student sonly playing cricket are";flag=0;
    for(i=0;i<cric;i++)
    {
         for(j=0;j<bad;j++)
         {
             if(c[i]==b[j])
             { 
                 flag=1;break;
             }
                        
         }
         if(flag==0)
         {
                cout<<c[i]<<" ";
         }flag=0;
    }
}
void set:: onlybad()
{    cout<<"\nthe students only playing badminton  are";flag=0;
   for(j=0;j<bad;j++)
    {
         for(i=0;i<cric;i++)
         {
             if(c[i]==b[j])
             {flag=1;break;}
         }
         if(flag==0)
         {             
                cout<<b[j]<<" ";
         }flag=0;
    }
 }
void set::ncnorb()
{  flag=0;
    cout<<"\nstudents playing neither cricket nor badminton are    ";
    for(i=0;i<num;i++)
    {
      for(j=0;j<k;j++)  
      {
          if(arr[i]==d[j])
          { flag=1;break;}
      }
      if(flag==0)
      {
          cout<<" "<<arr[i];
      }flag=0;
    }
}
void  set::inter()
{
    cout<<"\nStudents Who plays BOTH  ";
     for(j=0;j<bad;j++)
    {
        for(i=0;i<cric;i++)
        {
            if(b[j]==c[i])
            {
                cout<<c[i];
            }
        }
     }
    
}
int main(int argc, char** argv) 
{
    set s1;
    s1.get();
    s1.union1();
    s1.inter();
    s1.onlycric();
    s1.onlybad();
    s1.ncnorb();
    return 0;
}


