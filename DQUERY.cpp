/*
   Solution Author: Ramendra Singh
                    CSE KNIT Sultanpur.
*/

// application of MO's Algorithm
#include<bits/stdc++.h>
using namespace std;
int ct[1000005]={0};
int B=1;
struct query
{
	int l,r,ind;
};
bool cmp(query a,query b)
{
	if(a.l/B==b.l/B)
		return a.r<b.r;
	return a.l/B<b.l/B;
}
int main()
{
	int n;
	cin>>n;
	B=max(1,(int)sqrt(n));      //size of each block
	int A[n];                   //use scanf printf bcz of strict time limit
	for(int i=0;i<n;i++)
		scanf("%d",A+i);

	int d;scanf("%d",&d);
	vector<query>q(d);
    int ans[d];

	int L,R,cl=0,cr=0;
	for(int i=0;i<d;i++)
	{
	    scanf("%d%d",&L,&R);
		q[i].l=L-1;
		q[i].r=R-1;
		q[i].ind=i;
	}
	sort(q.begin(),q.end(),cmp);
	int uq=0;
    
	for(int i=0;i<d;i++)
	{
	   L=q[i].l;R=q[i].r;
       while(cl<L)
      {
      	ct[A[cl]]--;
      	if(ct[A[cl]]==0)uq--;
      	cl++;
      }
      while(cl>L)
      {
      	ct[A[cl-1]]++;
      	if(ct[A[cl-1]]==1)uq++;
      	cl--;
      }
      
	   while(cr<=R)
	   {
	   	  ct[A[cr]]++;
	   	  if(ct[A[cr]]==1)uq++;
	   	  cr++;
	   }
	
      
      while(cr>R+1)
	   {
	   	  ct[A[cr-1]]--;
	   	  if(ct[A[cr-1]]==0)uq--;
	   	  cr--;
	   }
	   ans[q[i].ind]=uq;
	}
    
    for(int i=0;i<d;i++)
    	printf("%d\n",ans[i]);
	return 0;
}