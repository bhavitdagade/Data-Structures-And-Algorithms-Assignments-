


#include <iostream>
using namespace std;
class sparse
{
private:int i1,j1,k1;
        int r1,c1,i,j,k,a1[50][50],b1[20][20],b3[20][20];int d[20][20],p1[20][20],t[20][20];
 public :
        void get1();
      
        void formsparse1();
        
        void printsparse1();
       
        void transpose1();
        
      
       void fastt();
       void addition(sparse,sparse);
        void printadd();
};
void sparse::get1()

{ cout<<"\nfor matrix 1";
cout<<"\nenter number of rows  ";
cin>>r1;
cout<<"\n enter number of columns   ";
cin>>c1;
cout<<"\n now....enter your matrix";
for(i=0;i<r1;i++)
    {
     for(j=0;j<c1;j++)
     {
     cin>>a1[i][j];
     }
    }
cout<<"\n and your input matrix1 is   \n";
for(i=0;i<r1;i++)
    {
     for(j=0;j<c1;j++)
     {
     cout<<a1[i][j];
     }
     cout<<"\n";
    }

}

void sparse::formsparse1()
{
    b1[0][0]=r1;
    b1[0][1]=c1;
    k1=1;
    for(i=0;i<r1;i++)
    {
     for(j=0;j<c1;j++)
     {
        if(a1[i][j]!=0)
        {
        b1[k1][0]=i;
        b1[k1][1]=j;
        b1[k1][2]=a1[i][j];
        k1++;
        } 
     }
    

    }b1[0][2]=k1-1;

}
void sparse :: printsparse1()
{
    cout<<"your sparse matrix is ";
    for(i=0;i<b1[0][2]+1;i++)
    {
     for(j=0;j<3;j++)
     {
         cout<<b1[i][j];
     }
     cout<<endl;
    }
    
}


void sparse::transpose1()
{
int m,n,terms;
int c,d,e=1;
m=b1[0][0];
n=b1[0][1];
terms=b1[0][2];
p1[0][0]=n;
p1[0][1]=m;
p1[0][2]=terms;
if(e<=terms)
{
  for(c=0;c<n;c++)
  {
    for(d=1;d<=terms;d++)

        {
            if(b1[d][1]==c)
            {
            p1[e][0]=b1[d][1];
            p1[e][1]=b1[d][0];
            p1[e][2]=b1[d][2];
            e++;
            }
        }
        if(e>terms)
        break;

  }
}
cout<<"\nand your transpose sparse matrix1 is n\n";
    for(i=0;i<e;i++)
    {
     for(j=0;j<3;j++)
     {
     cout<<p1[i][j]<<" ";
     }
     cout<<"\n";
     }

}

void sparse:: addition(sparse x,sparse y )
{ 
   
        if((x.b1[0][0]==y.b1[0][0])&&(x.b1[0][1]==y.b1[0][1]))
        {
            i1=1;j1=1;k1=1;
            b3[0][0]=y.b1[0][0];
            b3[0][1]=y.b1[0][1];
             while(i1<=x.b1[0][2]&&j1<=y.b1[0][2])
            {
            if(x.b1[i1][0]==y.b1[j1][0])
            {
                if(x.b1[i1][1]==y.b1[j1][1])
                {
                    b3[k1][0]=x.b1[i1][0];
                    b3[k1][1]=x.b1[i1][1];
                    b3[k1][2]=x.b1[i1][2]+y.b1[j1][2];
                    i1++;j1++;k1++;
                }
                else if(x.b1[i1][1]<y.b1[j1][1])
                {
                    b3[k1][0]=x.b1[i1][0];
                    b3[k1][1]=x.b1[i1][1];
                    b3[k1][2]=x.b1[i1][2];
                    i1++;k1++;
                }
                else //if(x.b1[i1][1]>y.b1[j1][1])
                {
                    b3[k1][0]=y.b1[j1][0];
                    b3[k1][1]=y.b1[j1][1];
                    b3[k1][2]=y.b1[j1][2];
                    j1++;k1++;
                }
                
            }
            else if(x. b1[i1][0]<y.b1[j1][0])
            {
                 b3[k1][0]=x.b1[i1][0];
                    b3[k1][1]=x.b1[i1][1];
                    b3[k1][2]=x.b1[i1][2];
                    i1++;k1++;
            }
            else //if( x.b1[i1][0]>y.b1[j1][0])
            {
                b3[k1][0]=y.b1[j1][0];
                    b3[k1][1]=y.b1[j1][1];
                    b3[k1][2]=y.b1[j1][2];
                    j1++;k1++;
            }
          }
            while(j1<=y.b1[0][2])
            {
                 b3[k1][0]=y.b1[j1][0];
                    b3[k1][1]=y.b1[j1][1];
                    b3[k1][2]=y.b1[j1][2];
                    j1++;k1++;
                
            }
             
            while(i1<=x.b1[0][2])
            {
                b3[k1][0]=x.b1[i1][0];
                    b3[k1][1]=x.b1[i1][1];
                    b3[k1][2]=x.b1[i1][2];
                    i1++;k1++;
            }
            b3[0][0]=k1-1;
               
       
      } 
    
 else
        {
            cout<<"\naddition is not posssible";
        }
}
void sparse :: printadd()
{
    cout<<"\nand your addition sparse matrix 2 is n\n";
    for(i1=0;i1<k1+1;i1++)
    {
     for(j1=0;j1<3;j1++)
     {
     cout<<b3[i1][j1]<<" ";
     }
     cout<<"\n";
     }
}
void sparse::fastt()
{
	int nz;int j;
	r1=b1[0][0];
	c1=b1[0][1];
	nz=b1[0][2];
	t[0][0]=b1[0][1];
	t[0][1]=b1[0][0];
	t[0][2]=nz;
	int rterms[c1],rpos[c1];
for(i=0;i<c1;i++)
 {
 	rterms[i]=0;
 }
for(i=1;i<=nz;i++)
{
 	 rterms[b1[i][1]]++;
}
	rpos[0]=1;
for(i=1;i<c1;i++)
 {
 	rpos[i]=rpos[i-1]+rterms[i-1];
 }
 for(i=1;i<=nz;i++)
 {
 
 	j=rpos[b1[i][1]];
 	t[j][0]=b1[i][1];
 	t[j][1]=b1[i][0];
 	t[j][2]=b1[i][2];
 	rpos[b1[i][1]]++;
 }
 cout<<"\nnow your fast transpose is \n";
  for(i=0;i<nz;i++)
    {
     for(j=0;j<3;j++)
     {
         cout<<t[i][j]<<"  ";
     }
     cout<<endl;
    }
}
int main()
{
  char another='y';
  int q;sparse s1,s2;
  while(another=='y')
  {
	cout<<"\n1for inserting matrix 1\n2 for showing its values and sparse and \n3 for its transpose\n4 for its fast transpose\n5 for 	addtion of two sparses\n ";
	cin>>q;
	switch(q)
	{
		case 1:s1.get1();break;
		case 2:s1.formsparse1();s1.printsparse1();break;
		case 3:s1.formsparse1();s1.transpose1();break;
		case 4:s1.formsparse1();s1.fastt();break;
		case 5:s1.get1();s2.get1();s1.formsparse1();s2.formsparse1();s1.addition(s1,s2);s1.printadd();break;
		default: cout<<"\nplease enter something meaningful\n";

}
cout<<"\ndo you want to continue y/n\n";
cin>>another;
}
}











