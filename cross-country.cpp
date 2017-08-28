#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int mat[2002][2002]={0};
int main()
{
   int tt;
   cin>>tt;
   while(tt--)
   {
     vector<int>ag;

     int val;
     cin>>val;
     //cout<<"here"<<endl;
     if(val)
     {
      ag.pb(val);
      cin>>val;	
     while(val) {ag.pb(val);cin>>val;}
     //for(int i=0;i<ag.size();i++) cout<<ag[i]<<" ";cout<<endl;
     int ans=0;
     while(true)
     {
     	vector<int>tom;
     	cin>>val;
     	if(val)
     	{
     	  tom.pb(val);cin>>val;		
        while(val) {tom.pb(val);cin>>val;	}

        memset(mat,0,sizeof(mat));
           //lcs
        for(int i=0;i<tom.size();i++)
          for(int j=0;j<ag.size();j++)
             {
               if(tom[i]!=ag[j]) mat[i+1][j+1]=max(mat[i][j+1],mat[i+1][j]);
               else mat[i+1][j+1]=mat[i][j]+1;

             }   
        ans=max(ans,mat[tom.size()][ag.size()]);

        }
       else break; 
     }
     cout<<ans<<endl;
    }

   }
	return 0;
}
