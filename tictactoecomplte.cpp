#include<bits/stdc++.h>
// X==2 ' '==1 O==3
using namespace std;
char s[3][3];
int a[10]={0};
int check();
//////////
bool com(const pair<int,int> &a,const pair<int,int> &b)
{
	return(a.second>b.second);
}
/////////
bool comp(const pair<int,int> &a,const pair<int,int> &b)
{
	if(a.second==6&&b.second==6)
	{
		return (a.first>b.first);
	}
	else if(a.second==6)
	{
		return 0;
	}
	else if(b.second==6)
	{
		return 1;
	}
	else if(a.second==b.second)
	{
		if((a.first)%2&&(b.first)%2)
		{
			return((b.first)>a.first);
		}
		else if((a.first)%2)
		{
			return 1;
		}
		else if((b.first)%2)
		{
			return 0;
		}
		else
		{
			return(a.second>b.second);
		}
	}
	else
	{
		return (a.second>b.second);
	}
	
}
///////////////
void show()
{
	cout<<endl;
	int i=0;
	while(i<3)
	{	int j=0; 
	while(j<3)
	{
		cout<<s[i][j]<<"	";
		++j;
	}
	++i;
	cout<<endl<<endl<<endl;
	}
	
}
///////////
void intialize()
{
	int i=0;
	int k=1;
	while(i<3)
	{	int j=0; 
	while(j<3)
	{
		s[i][j]=48+k;
		a[k]=1;
		++k;
		++j;
	}
	++i;
	}
	
}

////////////////
int move()
{
	int j=check();
	if(j>0)
	{
		if(j==1)
		{
			cout<<"Computer Wins"<<endl;
		
		}
		else if(j==2)
		{
			cout<<"You Win"<<endl;
		}
		else 
		{
			cout<<"Draw"<<endl;
		}
		return 0;
	}
	int k;
	cout<<"Enter the Position at which you want to enter"<<endl;
	do
	{
		cin>>k;
		if(a[k]!=1)
		{cout<<"Enter a Valid Position"<<endl;}
	}
	while(a[k]!=1);
	if(k<=3)
	{
		s[0][k-1]='O';
		a[k]=2;
	}
	else if(k<=6)
	{
		s[1][k-4]='O';
		a[k]=2;
	}
	else
	{
		s[2][k-7]='O';
		a[k]=2;
	}
	
	return k;
	
}
int check()
{
	int x[8];
	x[0]=a[1]*a[2]*a[3];
	x[1]=a[4]*a[5]*a[6];
	x[2]=a[7]*a[8]*a[9];
	x[3]=a[1]*a[4]*a[7];
	x[4]=a[2]*a[5]*a[8];
	x[5]=a[3]*a[6]*a[9];
	x[6]=a[1]*a[5]*a[9];
	x[7]=a[3]*a[5]*a[7];
	int i=0;
	while(i<8)
	{
		if(x[i]==8)
		{
			return 2;
		}
		else if(x[i]==27)
		{
			return 1;
		}
		++i;
	}
	i=1;
	bool found=0;
	while(i<10)
	{
		if(a[i]==1)
		{
			found=1;
		}
		++i;
	}
	if(found)
	{
		return 0;
	}
	return 3;
}
/////////////
int work()
{
	int h[3]={0},v[3]={0},d1,d2;
	h[0]=a[1]*a[2]*a[3];
	h[1]=a[4]*a[5]*a[6];
	h[2]=a[7]*a[8]*a[9];
	v[0]=a[1]*a[4]*a[7];
	v[1]=a[2]*a[5]*a[8];
	v[2]=a[3]*a[6]*a[9];
	d1=a[1]*a[5]*a[9];
	d2=a[3]*a[5]*a[7];
	
	int k=check();
	if(k>0)
	{
		if(k==1)
		{
			cout<<"Computer Wins"<<endl;
		
		}
		else if(k==2)
		{
			cout<<"You Win"<<endl;
		}
		else 
		{
			cout<<"Draw"<<endl;
		}
		return 0;
	}
	// the priority order is 9,4,3,2,1,6
	vector< pair<int,int> > poss;// first is index and second is value
	if(a[1]==1)
	{
		poss.push_back(make_pair(1,h[0]));
		poss.push_back(make_pair(1,v[0]));
		poss.push_back(make_pair(1,d1));
	}
	if(a[2]==1)
	{
		poss.push_back(make_pair(2,h[0]));
		poss.push_back(make_pair(2,v[1]));
		
	}
	if(a[3]==1)
	{
		poss.push_back(make_pair(3,h[0]));
		poss.push_back(make_pair(3,v[2]));
		poss.push_back(make_pair(3,d2));
	}
	if(a[4]==1)
	{
		poss.push_back(make_pair(4,h[1]));
		poss.push_back(make_pair(4,v[0]));
	}
	if(a[5]==1)
	{
		poss.push_back(make_pair(5,h[1]));
		poss.push_back(make_pair(5,v[1]));
		poss.push_back(make_pair(5,d1));
		poss.push_back(make_pair(5,d2));
	}
	if(a[6]==1)
	{
		poss.push_back(make_pair(6,h[1]));
		poss.push_back(make_pair(6,v[2]));
	}
	if(a[7]==1)
	{
		poss.push_back(make_pair(7,h[2]));
		poss.push_back(make_pair(7,v[2]));
		poss.push_back(make_pair(7,d2));
	}
	if(a[8]==1)	
	{
		poss.push_back(make_pair(8,h[2]));
		poss.push_back(make_pair(8,v[1]));
	}
	if(a[9]==1)
	{
		poss.push_back(make_pair(9,h[2]));
		poss.push_back(make_pair(9,v[2]));
		poss.push_back(make_pair(9,d1));
	}
	sort(poss.begin(),poss.end(),comp);
	int ghj=0;
		/*while(ghj<poss.size())
		{
			cout<<poss[ghj].first<<endl<<poss[ghj].second<<endl;
			++ghj;
		}*//*correct*/
	
		vector<int> fposs;
		int i=0;
		int qw=poss[0].second;
		while(i<poss.size())
		{
			if(poss[i].second==qw)
			{
				fposs.push_back(poss[i].first);
				//cout<<poss[i].first<<endl;//correct
			}
			else
			{
				break;
			}
			++i;
		}
		vector <pair<int,int> >fposs1;
		i=0;
		while(i<fposs.size())
		{
			int j=fposs[i];
			//cout<<j<<endl;//correct
			int fh=0;
			int sum=0;
			while(fh<poss.size())
			{
				
				if(poss[fh].first==j)
				{
					if(poss[fh].second!=6)
					{
					if(poss[fh].second<=9)
					{
						sum=sum+poss[fh].second;
						//cout<<sum<<endl;
					}
					}
					else
					{
						sum=sum-1;
					}
					
				}
				++fh;
			}
			fposs1.push_back(make_pair(fposs[i],sum));
			++i;
		}
		sort(fposs1.begin(),fposs1.end(),com);
		/*ghj=0;
		while(ghj<fposs1.size())
		{
			cout<<fposs1[ghj].first<<endl<<fposs1[ghj].second<<endl;
			++ghj;
		}*/
	int	x=fposs1[0].first;
	
	
	a[x]=3;
	if(x<=3)
	{
		s[0][x-1]='X';
	}
	else if(x<=6)
	{
		s[1][x-4]='X';
	}
	else if(x<=9)
	{
		s[2][x-7]='X';
	}
	
}
/////////////////////
////////////////////
int main()
{
intialize();
//show();
int gh;
do
{
int j;
int k;
cout<<"If you Want to play first then press 1 else press any no."<<endl;

cin>>j;

if(j==1)
{
	do
{
	system("CLS");
	show();
	move();
	k=work();
	
	
}
while(k!=0);
}
else
{
	do
{
	system("CLS");
	k=work();
	show();
	move();
}
while(k!=0);
}
cout<<"Game Over"<<endl;

cout<<"Press 1 to contuine 2 to exit"<<endl;
cin>>gh;
intialize();
}
while(gh!=2);

	return 0;
}
