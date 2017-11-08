#include<iostream>
#include<vector>
#include<cmath>
#include<conio.h>
#include "log.h"
using namespace std;

int min(int a[],int n)
{
	int min=100000;
	for(int i=0;i<n;i++)
	{
		if(a[i]<min)
		{
			min=a[i];
		}
	}

	return min;
}

int indexOf(int num,int arr[],int max)
{

	int index;

	for(int i=0;i<max;i++)
	{
		if(num==arr[i])
		{
			index=i;
		}
	}

	return index;
}

void show(vector <int> v)
{
	for(int i=0;i<v.size();i++)
	{
		cout<<"  "<<v[i];
	}
}
bool isEqual(int arr[],int arr2[],int k)
{
	for(int i=0;i<k;i++)
	{
		if(arr[i]==arr2[i])
		{
			return true;
		}
	}
	return false;
}
int check_mean(int mym,int obj[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(mym!=obj[i])
		{
			continue;
		}
		else
		{
			cout<<"mean accepted";
			return 1;
		}
	}
	return 0;

}
int mean(vector <int> v)
{
	int sum=0;
	for(int i=0;i<v.size();i++)
	{
		sum=sum+v[i];

	}

	return (sum/v.size());
}
int main()
{
	setLogConfiguration("xyx.txt");

	int n,k,ch;
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
	int object[15],cluster[5],i,j,old[50],row[50],itr=1;

	vector<vector<int> > group ;

	cout<<"\nEnter the elements :\n";
		writeToLog("log3",__LINE__);
	for(i=0;i<n;i++)
	{
		
		cout<<"\nEnter "<<(i+1)<<"no";
		cin>>object[i];

		char szName[50]={0};
		cout<<"\nEnter name";
		cin>>szName;

		char szTemp[50]={0};
		sprintf(szTemp, "User has entered: %d name:%s", object[i],szName);
		writeToLog(szTemp,__LINE__);
	}

	cout<<"\n do you want to provide mean if yes(1) if no(0)";
	cin>>ch;

	if(ch==0)
	{
		for(i=0;i<k;i++)
		{
			cluster[i]=object[i];
		}
				for(i=0;i<k;i++)
				{
					vector<int> newgroup;
					group.push_back(newgroup);
				}
		writeToLog("log5",__LINE__);
				do
				{
					for(i=0;i<n;i++)
					{
						for(int j=0;j<k;j++)
						{
							row[j]=abs(cluster[j]-object[i]);
						}
						group[indexOf(min(row,k),row,k)].push_back(object[i]);
					}
					for(j=0;j<k;j++)
					{
						if(group[j].empty())
						{
							old[j]=cluster[j];
							cluster[j]=mean(group[j]);
						}
					}
					if( isEqual(old,cluster,k))
					{
						for(i=0;i<k;i++)
						{
							group[i].clear();
						}
					}
					itr++;
				}while(isEqual(old,cluster,k));

				for(i=0;i<k;i++)
				{
					cout<<"\nGroup"<<(i+1)<<":";
					show(group[i]);

			writeToLog("log6",__LINE__);
				cout<<"\nNumber of iteration:"<<itr;

	}


/*	else
	{
		for(i=0;i<k;i++)
		{
			int flag=0;
			cout<<"\nEnter mean"<<(i+1);
			cin>>cluster[i];
			while(true)
			{
				flag=check_mean(cluster[i],object,n);
				if(flag == 1)	break;
				else if(flag == 0)
				{
					cout<<"\nEntered mean is not correct again enter mean";
					cin>>cluster[i];
				}
			}
		}
		for(i=0;i<k;i++)
		{
			vector<int> newgroup;
			group.push_back(newgroup);
		}

		do
		{
			for(i=0;i<n;i++)
			{
				for(int j=0;j<k;j++)
				{
					row[j]=abs(cluster[j]-object[i]);
				}
				group[indexOf(min(row,k),row,k)].push_back(object[i]);
			}
			for(j=0;j<k;j++)
			{
				if(group[j].empty())
				{
					old[j]=cluster[j];
					cluster[j]=mean(group[j]);
				}
			}
			if( isEqual(old,cluster,k))
			{
				for(i=0;i<k;i++)
				{
					group[i].clear();
				}
			}
			itr++;
		}while(isEqual(old,cluster,k));
*/
		for(i=0;i<k;i++)
		{
			cout<<"\nGroup"<<(i+1)<<":";
			show(group[i]);


		}
		cout<<"\nNumber of iteration:"<<itr;

	}

	EndLogConfiguration();
	_getch();
	return 0;

}


