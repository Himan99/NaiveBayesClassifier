#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>

using namespace std;

int main()
{
	char a[100];
	int i=0;
	ifstream file;
	ofstream fileout,fileout1;
	file.open("car.txt",ios::in);
	fileout.open("test1.txt",ios::out);
	// fileout1.open("car2.txt",ios::out);

	while(!file.eof())
	{
		file.getline(a,100);
		// srand(time(NULL));
		if((rand()%101)%20==0)
		{	//cout<<"y";
			fileout<<a<<"\n";
		}
	}
	// cout<<"y";
	return 0;
}