#include<istream>
using namespace std;
int len(char *s){
	char *p=s;
	while(*p){
		p++;
	}
	return p-s;
}
int main()
{
	printf("%d\n",len(NULL));
	return 0;
}
