// almost like minimum coin change problem i edited here for dynamic pro
#include<bits/stdc++.h>
using namespace std;
#define inf 99999999
int coin[2010]; //coint[i] contains coin used till ith kg of apples
int price[2010]; // price[i] contains min price for purchasing i kg of apples
int main()
{   
    int tt;
	cin>>tt;
	while(tt--)
	{
     int n,k;
     cin>>n>>k;
     int A[k+1];
     for(int i=1;i<=k;i++)cin>>A[i];
      memset(coin,0,sizeof(coin));
     for(int i=1;i<=k;i++)price[i]=inf;
      price[0]=0;

      for(int i=1;i<=k;i++)
        if(A[i]!=-1)
            for(int j=i;j<=k;j++)
            {

                if(price[j]>price[j-i]+A[i] and coin[j-i]<n )
                {
                    price[j]=price[j-i]+A[i];
                    coin[j]=coin[j-i]+1;
                }
            }

      if(price[k]>=inf) cout<<"-1\n";  
      else cout<<price[k]<<endl; 
    }

	return 0;
}
