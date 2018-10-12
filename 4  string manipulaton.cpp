#include<iostream>
#include<string.h>

using namespace std;
class string1
{
private:char s1[10];char s2[10];char s3[40];char s4[30];int i;
public: void get();
	void length();
	void copy();
	void compare();
	void cat();
	void display();
	void get1();
	void reverse();
	void freq();
	void alphanum();

};
void string1::get()
{	
	cout<<"\nEnter first string     ";
	cin>>s1;
	cout<<"\nEnter second string    ";
	cin>>s2;
}
void string1::get1()
{	
	cout<<"\nEnter string     ";
	cin>>s1;
	
}
void string1 ::display()
{
	cout<<"\nand your first string is as follows   ";
	cout<<s1;
	cout<<"\nand your second string is as follows   ";
	cout<<s2;
}
void string1::length()
{
	get1();
 	int count=0,count1=0;int l,l1;
	for(i=0;s1[i]!='\0';i++)
	{
		count++;
	}
	cout<<"\n length of string1 is   "<<count;
	
	l=strlen(s1);
	
	cout<<"\n length of string1 is (using function)  "<<l;
	
	
}
void string1::copy()
{ int num;
	get();
	cout<<"\ndo you want to copy 1.s1 to s2\n or 2.s2 to s1\n3 for nothing";
	cin>>num;
	switch(num)
	{
		case 1:
		{
			for(i=0;s1[i]!='\0';i++)
			{
			s2[i]=s1[i];
			}
			s2[i]='\0';
			cout<<"\n now s2 becomes   "<<s2;
			cout<<"\nand by using fnction its is  ";
			
			strcpy(s2,s1);
			cout<<"\n now s2 becomes   ";
			cout<<" "<<s2;
			break;
		}
		case 2:
		{
			for(i=0;s2[i]!='\0';i++)
			{
			s1[i]=s2[i];
			}
			s1[i]='\0';
			cout<<"\n noe s1 becomes   "<<s1;
			cout<<"\nand by using fnction its is  ";
		strcpy(s1,s2);
		cout<<"\n now s1 becomes   ";
		cout<<" "<<s1;break;
		case 3: break;
		}
	}
	
}
void string1::compare()
{
	get();
	int l;int flag;
	l=strcmp(s1,s2);
	cout<<" and result is"<<l;
	cout<<"\nand now comparing through manually  ";
	for(i=0;s1[i]!='\0';i++)

	{
		if(s1[i]!=s2[i])
			{	
				flag=0;
				break;
			}
		else flag=1;

	}
	if(flag==1)
	cout<<"\nstring are equal";
	else
	cout<<"\n strrings are unequal";


}
void string1::cat()
{	int k=0;
	get();
	int l;int flag;
	strcat(s1,s2);
	cout<<s1	;

	cout<<"\nand now comparing through manually  ";
	for(i=0;s1[i]!='\0';i++)
	{
	s3[i]=s1[i];
	k++;
	}
	for(i=0;s2[i]!='\0';i++)
	{
	s3[k]=s2[i];
	k++;
	}
	cout<<"\nand concatin manually is"<<s3;
	
	cout<<"\n and through function is  ";
	

}
void string1::reverse()
{	char s3[30];
	get1();int k;int j=0;
	for(i=0;s1[i]!='\0';i++)
	{
		

	}
	for(k=i-1;k>=0;k--)
	{
		s3[j]=s1[k];
		j++;
	}s3[k]='\0';
	cout<<"\n reversed string is   "<<s3<<"\n";
	
}
void string1::freq()
{	int counter=0;int flag=0;
	get1();char j;int arr[20];
	
	for(j='a';j<='z';j++)
	{	counter=0;
		for(i=0;s1[i]!='\0';i++)
		{
			if(s1[i]==j)
			{
			counter++;
			flag=1;
			}
			
			
		}
		if(flag==1)
		cout<<"\ncount of  "<<j<<"is "<<counter;
		flag=0;	
	}
}
void string1:: alphanum()
{
	get1();int k=0;
	for(i=0;s1[i]!='\0';i++)
	{
		if((s1[i]>=65 &&s1[i]<=90)||(s1[i]>=97 &&s1[i]<=122))
		{
			s3[k]=s1[i];
			k++;
		}
		
	}s3[k]='\0';
	cout<<"\nthe new string is"<<s3<<"\n";
}
int main()
{
	int value;char ch;
	do
	{
	cout<<"Follow Followin Choices";
	cout<<"\n 1 LENGTH";
	cout<<"\n 2 COPY";
	cout<<"\n 3 COMPARE";
	cout<<"\n 4 CONCATE";
	cout<<"\n 5 REVERSE";
	cout<<"\n 6 FREQ";
	cout<<"\n 7 ALPHANUMERIC";
	
	cin>>value;
	string1 a1;
	switch(value)
	{
		case 1:a1.length(); break;
		case 2:a1.copy();break;
		case 3:a1.compare();break;
		case 4:a1.cat();break;
		case 5:a1.reverse();break;
		case 6:a1.freq();break;
		case 7:a1.alphanum();break;
	}
	cout<<"\n do you wanna continue   y/n      ";
	cin>>ch;
	}
	while(ch=='y');
}

	

