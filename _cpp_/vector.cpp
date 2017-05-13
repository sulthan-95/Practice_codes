//Testing standard library class templates
//element-manipulation function
#include<iostream>
using std::cout;
using std::endl;
#include<vector>
#include<iterator>
#include<algorithm>
#include<exception>
int main()
{
	const int size=6;
	int a[size]={1,2,3,4,5,6};
	std::vector<int>v(a,a+size);
	std::ostream_iterator<int>output(cout," ");
	cout<<"Vector V contains:";
	std::copy(v.begin(),v.end(),output);   //Algorithm used to copy the elements in the range of first and second arguement
											//to the third arguement which is the ostream object in this case -to print output
	cout<<"\nFirst element of v:"<<v.front()<<"\nLast element of v:"<<v.back();
	v[0]=7;
	v.at(2)=10;	//set element at position 2 to 10
	v.insert(v.begin()+1,22); //Insert new element using insert of function
	cout<<"\nContents of vector v after changes:";
	std::copy(v.begin(),v.end(),output);
	/*try{
		v.at(100)=777;//access element out of range
	}
	catch(std::out_of_range e)
	{
		cout<<"\nException:"<<e.what();
	}*/
	v.erase(v.begin());
	cout<<"\nContents of vector v after erase";
	std::copy(v.begin(),v.end(),output);
	v.erase(v.begin(),v.end());
	cout<<"\nAfter erase ,vector v"<<(v.empty()?"is":"is not")<<" empty";
	v.insert(v.begin(),a,a+size);
	cout<<"\nContents of vector v before clear:";
	std::copy(v.begin(),v.end(),output);
	v.clear();		//calls erase to  empty a collection
	cout<<"\nAfter clear ,vector v"<<(v.empty()?"is":"is not")<<" empty";
	cout<<endl;
	return 0;
}

