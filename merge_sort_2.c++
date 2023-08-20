
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
  
  #define ll long long int
  
  ll cntt=0;
  
  vector<ll>mergeleftright(vector<ll>left,vector<ll>right){
      
      ll size1=left.size();
      ll size2=right.size();
      
      vector<ll>ans(size1+size2,0);
      
      ll i=0;
      ll j=0;
      
      ll k=0;
      
      while(i<size1 && j<size2){
          
          if(left[i]<=right[j]){
              ans[k]=left[i];
              i++;
              k++;
          }
          else{
              ans[k]=right[j];
              cntt+=(size1-i);
              j++;
              k++;
          }
          
      }
      while(i<size1){
          ans[k]=left[i];
          i++;
          k++;
      }
      while(j<size2){
          ans[k]=right[j];
          j++;
          k++;
      }
      
      return ans;
      
  }
  
  vector<ll>merge(long long arr[],ll n,ll l,ll h){
      
      if(l==h) {
          return {arr[l]};
      }
      
      ll mid=(l+h)/2;
      
      vector<ll>left=merge(arr,n,l,mid);
      vector<ll>right=merge(arr,n,mid+1,h);
      
      vector<ll>final=mergeleftright(left,right);
      
      return final;
      
      
  }
    
    long long int inversionCount(long long arr[], long long N)
    {
      
         merge(arr,N,0,N-1);
         
         return cntt;
    }

};