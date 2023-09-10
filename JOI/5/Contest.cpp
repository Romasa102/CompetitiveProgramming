#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M,T,X,Y;
    cin >> N >> M >> T >> X >> Y;
    ll p[M];
    repp(i,1,M+1){
        cin >> p[i];
    }
    ll time[Y];
    ll people[Y];
    ll problem[Y];
    string result[Y];
    ll ans[N+1];
    rep(i,N+1){
        ans[i] = 0;
    }
    map<P,P> contests;//people,prblem -> timeO,incorrectC
    rep(i,Y){
        cin >> time[i] >> people[i] >> problem[i] >> result[i];
        if(result[i] == "open"){
            contests[{people[i],problem[i]}] = {time[i],0};
        }
        if(result[i] == "incorrect"){
            contests[{people[i],problem[i]}].second++;
        }
        if(result[i] == "correct"){
            ans[people[i]] += max(X,p[problem[i]]-(time[i] - contests[{people[i], problem[i]}].first)-(120*contests[{people[i],problem[i]}].second));
        }
    }
    repp(i,1,N+1){
        cout << ans[i] << endl;
    }
}