#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n,s;
    cin>>n>>s;
    vector<int>t(n);
    for(int i=0;i<n;i++)cin>>t[i];
    sort(t.begin(),t.end());
    double ans=1e18;
    for(int a=0;a<=n;a++){
        int b=max(0,2*(-a-s+2*n-1)),c=n-a-b;
        if(a<0||b<0||c<0||(b==0&&a>0))continue;
        double d=0;
        if(c!=0){
            d=max(d,(double)t.back());
        }
        if(a+b!=0)d=max(d,(double)t[a+b-1]/0.6);
        if(a!=0){
            d=max(d,(double)t[a-1]/0.3);
        }
        ans=min(ans,d);
    }
    fixed(cout);
    cout<<setprecision(10)<<ans<<'\n';
}