#include<bits/stdc++.h>
using namespace std;
int co=0;
void find_all_comb(vector<vector<int> > &all,vector<int> &curr,int i,int len,int n,int k)
{
	if(len==k)
	{
		all.push_back(curr);
		co++;
		return;
	}
	while(i<=n)
	{
		curr.push_back(i);
		find_all_comb(all,curr,i+1,len+1,n,k);
		curr.pop_back();
		i++;
	}
}		
int main()
{
	vector<vector<int> >all;
	vector<int> current;
	int n,k;
	cin>>n>>k;
	find_all_comb(all,current,1,0,n,k);
	vector<int> res;
	for(int i=0;i<co;i++)
	{
		for(int l=0;l<k;l++)
			cout<<all[i][l]<<" ";
		cout<<"\n";
	}
	return 0;
}
  
