#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,T,Q;
    cin >> N >> T >> Q;//T<10^18
    ll A[N],D[N];
    vector<ll> moveL;
    vector<ll> moveR;
    rep(i,N){
        cin >> A[i] >> D[i];
        if(D[i]==1){
            moveL.push_back(A[i]);
        }else{
            moveR.push_back(A[i]);
        }
        //if D[i]==1 people move ++ else --
    }
    ll X[Q];
    vector<P> VIP;
    rep(i,Q){
        cin >> X[i];
        VIP.push_back({A[X[i]-1],D[X[i]-1]});
    }
    sort(A,A+N);
    sort(D,D+N);
    sort(moveL.begin(),moveL.end());
    sort(moveR.begin(),moveR.end());
    rep(i,VIP.size()){
        ll a = VIP[i].first;
        ll d = VIP[i].second;
        if(d==1){
            if(upper_bound(moveR.begin(),moveR.end(),a) == moveR.end()){
                cout << T + a << endl;
                continue;
            }
            ll near = *upper_bound(moveR.begin(),moveR.end(),a);
            ll nearL = *(lower_bound(moveL.begin(),moveL.end(),near)-1);
            if(abs(near-a) < 2*T){
                ll ans = 0;
                if(nearL > a){
                    ans = (nearL+near)/2;
                    if(abs(a-ans)>=T){
                        cout << a+T << endl;
                        continue;
                    }
                }else{
                    ans = (near + a) / 2;
                }
                cout << ans << endl;
                continue;
            }
            cout << a+T << endl;
        }else{
            if(upper_bound(moveL.begin(),moveL.end(),a) == moveL.begin()){
                cout << a - T << endl;
                continue;
            }
            ll near = *(upper_bound(moveL.begin(),moveL.end(),a)-1);
            ll nearR = *upper_bound(moveR.begin(),moveR.end(),near);
            if(abs(a-near) < 2*T){
                ll ans = 0;
                if(nearR < a){
                    ans = (nearR+near)/2;
                    if(abs(a-ans)>=T){
                        cout << a-T << endl;
                        continue;
                    }
                }else{
                    ans = (near + a) / 2;
                }
                cout << ans << endl;
                continue;
            }
            cout << a-T << endl;
        }
    }
}