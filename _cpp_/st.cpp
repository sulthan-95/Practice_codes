#include<iostream>
#include<string>
using namespace std;
class Solution {

public:

    string reverseVowels(string s) {

        int i=0,j=s.length();
	while(i<=j)

        {
	  
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')

            {

                if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'){

                    char t=s[i];

                    s[i]=s[j];

                    s[j]=t;

                    //i++;

                    //j--;

                }

                else{
                j--;
		continue;
		}

            }

            else if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')

            {

                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){

                    char t=s[i];

                    s[i]=s[j];

                    s[j]=t;

                    //j--;

                    //i++;

                }

                else{

                i++;
		continue;
		}

            }


                i++;

                j--;
           //cout<<s<<"\n"<<i<<"\n"<<j<<endl;

        }

        return s;

    }

};
int main()
{
	Solution a;
	string s="hello";
	cout<<a.reverseVowels(s)<<endl;
	//cout<<s.length()<<endl;
	return 0;
}
