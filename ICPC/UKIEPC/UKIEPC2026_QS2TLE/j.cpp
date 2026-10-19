#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n,l;
    cin>>n>>l;
    vector<pair<ll,ll>>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first;
        v[i].second=i;
    }
    sort(v.begin(),v.end());
    ll le=-1e9,ri=1e9;
    while(le<ri){
        ll mid=le+(ri-le+1)/2;
        vector<array<ll,3>>dp(n+1,{(ll)-1e18,1,-1});
        dp[0]={0,0,-1};
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=n;j++){
                dp[j]=max(dp[j],array<ll,3>{dp[i][0]+v[i].first*(j-i)+mid,dp[i][1]-1,i});
            }
        }
        if(-dp.back()[1]>l){
            ri=mid-1;
        }else{
            le=mid;
        }
    }
    vector<array<ll,3>>dp(n+1,{(ll)-1e18,1,-1});
    dp[0]={0,0,-1};
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            dp[j]=max(dp[j],array<ll,3>{dp[i][0]+v[i].first*(j-i)+le,dp[i][1]-1,i});
        }
    }
    vector<int>w;
    int cur=dp[n][2];
    while(cur!=-1){
        w.push_back(cur);
        cur=dp[cur][2];
    }
    reverse(w.begin(),w.end());
    w.push_back(n);
    vector<int>ans(n);
    for(int i=0;i<w.size()-1;i++){
        for(int j=w[i];j<w[i+1];j++){
            ans[v[j].second]=i+1;
        }
    }
    fixed(cout);
    cout<<setprecision(10)<<(double)(dp.back()[0]+dp.back()[1]*le)/n<<'\n';
    for(int i:ans)cout<<i<<' ';
    cout<<endl;
}