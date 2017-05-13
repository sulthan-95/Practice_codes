int main()
{
	int a[size],n,i,b[size],r=0;
	cout<<"Enter the no. of integers to be sorted..\n";
	cin>>n;
	cout<<"\nEnter the elements..\n";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	radixsort(a,n);
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}

