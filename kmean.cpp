#include<iostream>
#include<conio.h>
#include "log.h"
using namespace std;

int main()
{
	setLogConfiguration("xyx.txt");

	int n,k;
	int object[15],i;
	cout<<"\nEnter total no of items:\n";
	cin>>n;
	writeToLog("log1", __LINE__);
	cout<<"\nEnter no of clusters :\n";
	cin>>k;

	while(n<k)
	{
		cout<<"incorrect no of cluster provide another no";
		cin>>k;
	}
		writeToLog("log2",__LINE__);


	cout<<"\nEnter the elements :\n";
		writeToLog("log3",__LINE__);
	for(i=0;i<n;i++)
	{
		
		cout<<"\nEnter "<<(i+1)<<"no : ";
		cin>>object[i];

		char szName[50]={0};
		cout<<"\nEnter name:";
		cin>>szName;

		char szTemp[50]={0};
		sprintf(szTemp, "User has entered: %d name:%s", object[i],szName);
		writeToLog(szTemp,__LINE__);
	}

	EndLogConfiguration();
	_getch();
	return 0;

}


