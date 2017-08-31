//gcd on tree with zero 
// dfs on tree

#include<bits/stdc++.h>
using namespace std;


vector<vector<int> >adj;   //to resised later according to need
vector<int>vis;
vector<int>ans;
vector<int>val;
vector<int>divisor;            //contains divisor of root in sorted order
vector<int>ct;          // contains ct of div[i] 
void dfs1(int s)
{
  vis[s]=1;
    
  for(auto u: adj[s])
  {
  	if(!vis[u])
  	{
  		ans[u]=__gcd(ans[s],val[u]);
  		dfs1(u);
  	}
  }	
}

void dfs2(int s,int len)
{
  vis[s]=1;
  for(int i=0;i<divisor.size();i++)
  {
     if(val[s]%divisor[i]==0)
       ct[i]+=1;
   if(ct[i]>=len)
     ans[s]=max(ans[s],divisor[i]);
  }

  for(auto u : adj[s])
  	if(!vis[u])
  		dfs2(u,len+1);

 for(int i=0;i<divisor.size();i++)
    if(val[s]%divisor[i]==0)
     ct[i]-=1; 	

}

int main()
{
   int n;
   cin>>n;
   adj.resize(n);vis.resize(n);val.resize(n);ans.resize(n);
  
  for(int i=0;i<n;i++)cin>>val[i];
  int a,b;
  for(int i=0;i<n-1;i++)
  {
       cin>>a>>b;
       a-=1;b-=1;
      adj[a].push_back(b);
      adj[b].push_back(a);
  } 
    int vertex=val[0];
    val[0]=0;           //first make root node =0
    dfs1(0);
   val[0]=vertex;
   for(int i=0;i<n;i++)vis[i]=0;
    for(int i=1;i*i<=vertex;i++)
    {
    	if(vertex%i==0)
    	{
    		divisor.push_back(i);
    		divisor.push_back(vertex/i);

    		if(i*i==vertex) divisor.pop_back();
    	}
    }
    sort(divisor.begin(), divisor.end());
    ct.resize(divisor.size());

    dfs2(0,0);
   
   for(int i=0;i<ans.size();i++)
   	cout<<ans[i]<<' ';
 
  return 0;
}
