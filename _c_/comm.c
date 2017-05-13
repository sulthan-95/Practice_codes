//Gonna Print Command Line Arguements
#include<stdio.h>
int main(int argc,char *argv[])
{
	if(argc<2)	//argc should be 2 for correct execution
	{
		printf("usage:%s file name \n",argv[0]);
		//We print argv[0] assumig it is the program name
	}
	else
	{
		//We assume argv[1] is a file name to open
		FILE *file=fopen(argv[1],"r");
		//Fopen returns 0, the NULL pointer on failure//
		if(file==0)
			printf("Could not open file..\n");
		else
		{
			int x;
			//Read one chraracter at a time from file stopping at EOF which indicates the end of file//
			while((x=fgetc(file))!=EOF)
			{
				printf("%c\n",x);
			}
			fclose(file);
		}
	}
	return 0;
}
