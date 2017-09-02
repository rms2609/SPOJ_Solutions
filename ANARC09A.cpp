#include<bits/stdc++.h>
using namespace std;

int solve(string str)
{
  int n=str.length();
  int a=0,ans=0;
  for(int i=0;i<n;i++)
  {
  	if(str[i]=='{')a++;
  	if(str[i]=='}')a--;
  	if(a<0) {ans++;a+=2;}
  	else if(a>=n-i){ans++;a-=2;}
  }
  return ans;
}

int main()
{
	int cs=1;
	while(true)
	{
		string str;cin>>str;
		if(str[0]=='-') break;

		cout<<cs++<<". "<<solve(str)<<endl;
	}
  return 0;
}