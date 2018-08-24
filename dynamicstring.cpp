#include<iostream>
//#include<string.h>
using namespace std;

int main()
{
	string str,word[10];
	int i=0,j=0,k=0;
	cout<<"Enter the text:";
	getline(cin,str);
	
	int start=0;
	for(i=0;i<str.length();i++)
	{
		if(str[i]==' ')
		{	
			word[j]=str.substr(start,i-start);
			start=i+1;
			j++;
		}
	}
	word[j]=str.substr(start,i-start);
	
	cout<<"Required words:\n";
	for(i=0;i<=j;i++)
	{
		cout<<word[i]<<"\n";
	}
}