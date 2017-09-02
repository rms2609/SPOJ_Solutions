#include <bits/stdc++.h>
using namespace std;

map<long,long>mp;  // once calculated values can be used next time
map<long,long> :: iterator p;
long change(long val)
{
  if(val<5) return val;
  p=mp.find(val);
  if(p==mp.end())
  {
    long sum=max(val,change(val/4)+change(val/3)+change(val/2));  // whatever is greater between val and change 
     mp[val]=sum;
     return sum;
  }
  else return (*p).second;
}

int main()
{
   long n;
   while(cin>>n)
   {
   	cout<<change(n)<<endl;
   }

	return 0;
}