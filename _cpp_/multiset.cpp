//Testing standard library MULTISET
#include<iostream>
using std::cout;
using std::endl;
#include<set>
#include<iterator>
#include<algorithm>
int main()
{
	const int size=10;
	int a[size]={6,22,9,1,18,30,100,22,85,13};
	typedef std::multiset<int,std::less_equal<int> > ims;
	ims intmultiset;
	std::ostream_iterator<int> output(cout," ");
	cout<<"\nThere are currently "<<intmultiset.count(7)<<" values of 7 in the multiset \n";
	intmultiset.insert(7);
	intmultiset.insert(7);
	cout<<"After inserts, there are  "<<intmultiset.count(7)<<" values of 7 in th multiset ";
	ims::const_iterator result;
	result=intmultiset.find(7);
	if(result!=intmultiset.end())
		cout<<"\nFound value 7\n";
	result=intmultiset.find(10);
	if(result==intmultiset.end())
		cout<<"Didn't find value 10\n";
	intmultiset.insert(a,a+size);
	cout<<"\nAfter insert multiset contains \n";
	std::copy(intmultiset.begin(),intmultiset.end(),output);
	cout<<"\nLower bound of 22:"<<*(intmultiset.lower_bound(22));
	cout<<"\nUpper bound of 22:"<<*(intmultiset.upper_bound(22));
	std::pair<ims::const_iterator,ims::const_iterator> p;
	p=intmultiset.equal_range(22);
	cout<<"\nUSing equal_range of 22 \n Lower bound: "<<*(p.first)<<"\nUpper bound: "<<*(p.second);
	cout<<endl;
	return 0;
}
