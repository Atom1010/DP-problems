#include <iostream>
#include <vector>
using namespace std;

int coindp (int n, int a[],int s,vector<int> &dp)
{
  if(n==0)  return 0;
  int ans=INT32_MAX;
  for(int i=0;i<s;i++)
  {
    if(n-a[i]>=0)
    {
    int subAns=0;
    if(dp[n-a[i]]!=-1)
    {
      subAns=dp[n-a[i]];
    }
    else{
      subAns=coindp(n-a[i],a,s,dp);
    }
    if(subAns!=INT32_MAX && subAns + 1 < ans)
    {
        ans=subAns+1;
        //cout<<ans<<endl;
    }
    }
    
  }
  dp[n]=ans;
  return ans;
}

int main() {
  int n=18;
  int a[]={1,7,5};
  vector<int> dp(n+1,-1);
  dp[0]=0;
  int s=sizeof(a)/sizeof(a[0]);
  int ans=coindp(n,a,s,dp);
  for(int i=0;i<n+1;i++)
    cout<<i<<"="<<dp[i]<<" ";
  //cout<<ans<<endl;
  return 0;
}
