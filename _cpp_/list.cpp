//Testing Standard Library class List
#include<iostream>
using std::cout;
using std::endl;
#include<list>
#include<iterator>
#include<algorithm>
template<class T>
void printlist(const std::list<T> &listref);
int main()
{
    const int size=4;
    int a[size]={2,6,8,4};
    std::list<int>values,othervalues;
    values.push_front(1);
    values.push_front(2);
    values.push_back(4);
    values.push_back(3);
    cout<<"\nValues contains: ";
    printlist(values);
    values.sort();
    othervalues.insert(othervalues.begin(),a,a+size);
    cout<<"\nother values contains:";
    printlist(othervalues);
    values.splice(values.end(),othervalues,othervalues.begin(),othervalues.end());
    cout<<"\nafter splice values contains..";
    printlist(values);
    values.sort();
    cout<<"\nValues contains: ";
    printlist(values);
    othervalues.insert(othervalues.begin(),a,a+size);
    othervalues.sort();
    cout<<"\nOthervalues contains:";
    printlist(othervalues);
    values.merge(othervalues);
    cout<<"\nAfter merge:\nValues contains: ";
    printlist(values);
    cout<<"\nOthervalues contains:";
    printlist(othervalues);
    values.pop_front();
    values.pop_back();  //all sequence container
    cout<<"\nAfter pop front and pop back contains:\n";
    printlist(values);
    values.unique();
    cout<<"\nAfter unique values contains:";
    printlist(values);
    //method swap is available in all containers
    values.swap(othervalues);
    cout<<"\nAfter swap:\nValues contains:";
    printlist(values);
    cout<<"\nOther values contains ";
    printlist(othervalues);
    othervalues.assign(4,27);
    cout<<"\nAfter assign values contains..";
    printlist(othervalues);
    values.merge(othervalues);
    cout<<"\nValues contains :";
    printlist(values);
    values.remove(27);
    cout<<"\nAfter remove,values contains..";
    printlist(values);
    cout<<endl;
    return 0;
}
template<class T>
void printlist(const std::list<T> &listref)
{
    if(listref.empty())
        cout<<"\nList is empty";
    else{
        std::ostream_iterator<T> output(cout," ");
        std::copy(listref.begin(),listref.end(),output);
    }
}
