#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>

using namespace std;

int getindex1(char a)
{
	int i;
	char c[5]="vhml";
	for ( i = 0; i < 4; ++i)
	{
		if(a==c[i])
		{
			break;

		}
	}
	return i;
}

int getindex2(char a)
{
	char c[5]="lmh";
	for (int i = 0; i < 3; ++i)
	{
		if(a==c[i])
			return i;
	}
}

class car
{
public:
	int arr[4];
	double total=0;
	car()
	{
		for (int i = 0; i < 4; ++i)
		{
			arr[i]=0;
		}
	}
	void caltotal()
	{
		for (int i = 0; i < 4; ++i)
		{
			total+=arr[i];
		}
	}
	void disp()
	{
		for (int i = 0; i < 4; ++i)
		{
			cout<<arr[i]<<" ";
		}
		cout<<total;
	}
};

int main()
{
	car mat[6][4];
	int r,c,i,j;
	string buy,maint,lug,saf,result;
	int door,person;
	fstream file;
	file.open("car.txt",ios::in);
	while(1)
	{
		file>>buy>>maint>>door>>person>>lug>>saf>>result;
		switch(result[0])
		{
			case 'u':c=0;
			break ;
			case 'a':c=1;
			break ;
			case 'g':c=2;
			break;
			case 'v':c=3;
			break;
			default: cout<<"wrong";
		}
		r=0;
		i=getindex1(buy[0]);
		mat[r][c].arr[i]++;
		r=1;
		i=getindex1(maint[0]);
		mat[r][c].arr[i]++;
		r=2;
		mat[r][c].arr[door-2]++;
		r=3;
		mat[r][c].arr[person-2]++;
		r=4;
		i=getindex2(lug[0]);
		mat[r][c].arr[i]++;
		r=5;
		i=getindex2(saf[0]);
		mat[r][c].arr[i]++;
		if(file.eof()) break;
	}
	i=0;j=0;
	for ( i = 0; i < 6; ++i)
	{
		for ( j = 0; j < 4; ++j)
		{
			mat[i][j].caltotal();
			mat[i][j].disp();
			cout<<"|";
		}
		cout<<"\n";
	}
	file.close();
	file.open("test1.txt",ios::in);
	int line=0,count=0;
	while(1)
	{
		file>>buy>>maint>>door>>person>>lug>>saf>>result;
		if(file.eof()) break;
		int k[6];
		int t=0;
		k[0]=getindex1(buy[0]);
		k[1]=getindex1(maint[0]);
		k[2]=door-2;
		k[3]=person-2;
		k[4]=getindex2(lug[0]);
		k[5]=getindex2(saf[0]);
		double p1,p2,p3,p4=1,max=0;
		for ( j = 0; j < 4; ++j)
		{ 
			p4=1;
			for ( i = 0; i < 6; ++i)
			{
				p1=double(mat[i][j].arr[k[i]])/mat[i][j].total;
				p4*=p1;
			}
			p4*=mat[0][j].total/1728;
			if(max<p4)
			{
				max=p4;
				t=j;
			}
		}
		cout<<++line<<" "<<t<<" "<<"\n";
		switch(result[0])
		{
			case 'u':c=0;
			break ;
			case 'a':c=1;
			break ;
			case 'g':c=2;
			break;
			case 'v':c=3;
			break;
			default: cout<<"wrong";
		}
		if(c==t)count++;
	}
	cout<<count;
	file.close();
	return 0;
}