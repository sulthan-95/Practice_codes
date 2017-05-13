#include<iostream>

#include<string.h>

using namespace std;

int maxi(int a,int b)

{

	if(a>=b)

		return a;

	else

		return b;

}

int main(int rags,char *argv[])

{

	char str1[100],str2[100];

	int n,co=0,c[100][100],j=0;

	cin>>n;

	cin>>str1;
	for(int i=n-1;i>=0;i--)
		str2[j++]=str1[i];

	//str2=strrev(str1);

	//n=strlen(str1);
	str2[j]='\0';
	cout<<str2<<"\n";

	/*for(int i=0;i<=n;i++)

		c[i][0]=0;

	for(int i=0;i<=n;i++)

		c[0][i]=0;*/

	for(int i=0;i<=n;i++)

	{

		for(int j=0;j<=n;j++)

		{

			if(i==0||j==0)

				c[i][j]=0;

			else if(str1[i-1]==str2[j-1])

				c[i][j]=c[i-1][j-1]+1;

			else 

				c[i][j]=maxi(c[i-1][j],c[i][j-1]);

			//co=maxi(co,c[i+1][j+1]);

		}

	}

	for(int i=0;i<=n;i++)

	{

		for(int j=0;j<=n;j++)

		{

			cout<<c[i][j]<<" ";

		}

		cout<<"\n";

	}

	cout<<"The maximum subarray length is "<<c[n][n]<<endl;

	return 0;

}
