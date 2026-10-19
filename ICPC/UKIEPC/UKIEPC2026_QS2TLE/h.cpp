#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int k,n;
    cin>>k>>n;
    vector<string>s(n);
    for(int i=0;i<n;i++)cin>>s[i];
    vector<string>v(s);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    vector<vector<int>>adj(k,vector<int>(k,0));
    for(int i=0;i<n-1;i++){
        adj[lower_bound(v.begin(),v.end(),s[i])-v.begin()][lower_bound(v.begin(),v.end(),s[i+1])-v.begin()]++;
        adj[lower_bound(v.begin(),v.end(),s[i+1])-v.begin()][lower_bound(v.begin(),v.end(),s[i])-v.begin()]++;
    }
    vector<array<ll,2>>dp(1<<(v.size()),array<ll,2>{(ll)1e18,-1});
    dp[0]={0,-1};
    for(int i=0;i<(1<<v.size());i++){
        int cnt=0;
        for(int j=0;j<v.size();j++){
            if(!(i&(1<<j)))continue;
            for(int l=0;l<v.size();l++){
                if(i&(1<<l))continue;
                cnt+=adj[j][l];
            }
        }
        for(int l=0;l<v.size();l++){
            if(i&(1<<l))continue;
            dp[i+(1<<l)]=min(dp[i+(1<<l)],array<ll,2>{dp[i][0]+cnt,l});
        }
    }
    int cur=(1<<v.size())-1;
    vector<string>ans;
    while(dp[cur][1]!=-1){
        ans.push_back(v[dp[cur][1]]);
        cur-=1<<dp[cur][1];
    }
    set<string>st(v.begin(),v.end());
    while(ans.size()<k){
        for(int i=0;i<26;i++){for(int j=0;j<26;j++){
            string t=string(1,'a'+i)+string(1,'a'+j);
            if(!st.count(t))ans.push_back(t);
            if(ans.size()==k)break;
        }if(ans.size()==k)break;}
    }
    for(string i:ans)cout<<i<<' ';
    cout<<'\n';
}