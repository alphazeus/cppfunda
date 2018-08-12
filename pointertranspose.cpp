#include<iostream>
#include<stdio.h>
using namespace std;

void disp(int *mat,int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			cout<<*(mat+j+i*row)<<" ";
		}		
		cout<<"\n";
	}
}
void transpose(int *mat,int row,int col)
{
	int temp,i,j;
	for(i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(i<j)
			{
				temp=*(mat+j+i*col);
				*(mat+j+i*col)=*(mat+i+j*row);
				*(mat+i+j*row)=temp;
			}
		}
	}
}

int main()
{
	int row,col,i,j;
	cout<<"Enter the no of Rows:";
	cin>>row;
	cout<<"Enter the no of Columns:";
	cin>>col;
	int *mat=(int *)malloc(row*col*sizeof(int));
	cout<<"Numbers Row by row:";
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			cin>>*(mat+j+i*row);
		}
	}
	disp(mat,row,col);
	transpose(mat,row,col);
	disp(mat,row,col);
	return 0;
}