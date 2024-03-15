#include<iostream>
#include<cstdio>
using namespace std;

typedef struct
{
	int x;
	int y;
}Node;

typedef struct
{
	Node data[1005];
	int length;
}SqList;

void init(SqList &a);
void input(SqList &a);
void add(SqList a, SqList b, SqList &c);
void output(SqList a);

int main()
{
	SqList a,b,c;

	init(a);
	init(b);
	init(c);
	
	input(a);
	input(b);
	
	add(a, b, c);
		
	output(c);
	return 0; 
}

void init(SqList &a)
{
	a.length=0;
}

void input(SqList &a)
{
	cin>>a.length;
	for(int i=1; i<=a.length; i++)
	{
		cin>>a.data[i].x>>a.data[i].y;
	}
}

void output(SqList a)
{
	if(a.data[1].x==0)
		cout<<"0"<<" "<<"0";
	else
	for(int i=1; i<=a.length; i++)
	{
		cout<<a.data[i].x<<" "<<a.data[i].y;
		if(i<a.length) cout<<" ";
	}
}

void add(SqList a, SqList b, SqList &c)
{
	int i=1,j=1,k=1;
	while(i<=a.length && j<=b.length)
	{
		if(a.data[i].y > b.data[j].y)
		{
			c.data[k].y=a.data[i].y;
			c.data[k].x=a.data[i].x;
			i++;
		}
		else if(a.data[i].y == b.data[j].y)
		{
			if(a.data[i].x + b.data[j].x != 0)
			{
				c.data[k].x=a.data[i].x + b.data[j].x;
				c.data[k].y=a.data[i].y;
				i++; j++;
			}
			else if(a.data[i].x + b.data[j].x == 0)
			{
				i++; j++;
				continue;
			}
			
		}
		else if(a.data[i].y < b.data[j].y)
		{
			c.data[k].y=b.data[j].y;
			c.data[k].x=b.data[j].x;
			j++;
		}
		k++; c.length++; 
	}
	if(i>a.length)
	{
		while(j<=b.length)
		{
			c.data[k].x=b.data[j].x;
			c.data[k].y=b.data[j].y;
			k++; j++; c.length++;
		}
	}
	else
	while(i<=a.length)
		{
			c.data[k].x=a.data[i].x;
			c.data[k].y=a.data[i].y;
			k++; i++; c.length++;
		}
}

