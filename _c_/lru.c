#include<stdio.h>

#include<stdlib.h>

int fr[3];
int cnt[3];
int min()
{
	int min=cnt[0],i,j=0;
	for(i=1;i<3;i++)
	{
		if(cnt[i]<min)
		{
			min=cnt[i];
			j=i;
		}
	}
	return j;
}
void main()

{

	void display();

	printf("\nenter how many pages:");

	int i,j,n;

	scanf("%d",&n);

	int *page;

	page =(int *)malloc(sizeof(int)*n);

	printf("\nenter the pages:\n");

	for(i=0;i<n;i++)

		scanf("%d",&page[i]);

	int flag1=0,flag2=0,pf=0,frsize=3,top=0,cou=0;

	for(i=0;i<3;i++)

	{

		fr[i]=-1;
		cnt[i]=0;

	}

	for(j=0;j<n;j++)

	{

		flag1=0;

		flag2=0;

		for(i=0;i<3;i++)

		{

			if(fr[i]==page[j])

			{
				cou+=1;
				cnt[i]=cou;
				flag1=1;

				flag2=1;

				break;

			}

		}

		if(flag1==0)

		{

			for(i=0;i<frsize;i++)

			{

				if(fr[i]==-1)

				{
					cou+=1;
					cnt[i]=cou;				
	
					fr[i]=page[j];

					flag2=1;

					break;

				}

			}

		}



		if(flag2==0)

		{

			top=min();

			fr[top]=page[j];
			cou+=1;
			cnt[top]=cou;

			pf++;


		}

		display();
	}

}

void display()

{

	int i;

	printf("\n");

	for(i=0;i<3;i++)

		printf("%d\t",fr[i]);

}
