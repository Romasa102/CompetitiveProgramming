#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,D,K;
    cin >> N >> D >> K;
    P PS[N];//first:startT second:position(0or1)
    rep(i,N)cin >> PS[i].second >> PS[i].first;
    sort(PS,PS+N);
    vector<ll> Pos0;
    vector<ll> Pos1;
    vector<ll> PosIndex0;
    vector<ll> PosIndex1;
    rep(i,N){
        if(PS[i].second==1){
            Pos0.push_back(PS[i].first);
            PosIndex0.push_back(i);
        }
        if(PS[i].second==2){
            Pos1.push_back(PS[i].first);
            PosIndex1.push_back(i);
        }
    }
    ll dp[N+1][2];
    rep(i,N+1)rep(j,2)dp[i][j]=0;
    rep(i,N){
        if(PS[i].second==1){
            dp[i][0]++;
            if(!Pos1.empty()){
                ll nextindF1 = lower_bound(Pos1.begin(), Pos1.end(), PS[i].first+dp[i][0]*K+D+1)-Pos1.begin();
                if(PosIndex1[nextindF1]>=i && PosIndex1[nextindF1]<N){
                    dp[PosIndex1[nextindF1]][1]=max(dp[PosIndex1[nextindF1]][1],dp[i][0]);
                }
            }
            if(i+1<N&&PS[i+1].second==1){
                dp[i+1][0]=max(dp[i+1][0],dp[i][0]);
            }
        }else{
            dp[i][1]++;
            if(!Pos0.empty()){
                ll nextindF0 = lower_bound(Pos0.begin(), Pos0.end(), PS[i].first+dp[i][1]*K+D+1)-Pos0.begin();
                if(PosIndex0[nextindF0]>=i && PosIndex0[nextindF0]<N){
                    dp[PosIndex0[nextindF0]][0]=max(dp[PosIndex0[nextindF0]][0],dp[i][1]);
                }
            }
            if(i+1<N&&PS[i+1].second==2){
                dp[i+1][1]=max(dp[i+1][1],dp[i][1]);
            }
        }
        dp[i+1][1]=max(dp[i+1][1],dp[i][1]);
        dp[i+1][0]=max(dp[i+1][0],dp[i][0]);
    }
    cout << max(dp[N][0],dp[N][1]) << endl;
}