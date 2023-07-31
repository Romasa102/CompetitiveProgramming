#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1000000;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll NO,NS,M;
    cin >> NO >> NS >> M;
    vector<vector<ll>> A(NO+NS+100);
    rep(i,M){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        A[a].push_back(b);
        A[b].push_back(a);
    }
    ll dis[NO+NS+100];
    rep(i,(NO+NS)){
        dis[i] = 1000000;
    }
    ll furthestPS = 0;
    ll furthestPDisS = 0;
    ll furthestPE = 0;
    ll furthestPDisE = 0;
    queue<ll> Q;
    Q.push(0);
    dis[0] = 0;
    while(Q.size()){
        ll p = Q.front();
        Q.pop();
        rep(i,A[p].size()){
            if(dis[A[p][i]] == 1000000){
                Q.push(A[p][i]);
                dis[A[p][i]] = dis[p] +1;
                if(dis[A[p][i]] > furthestPDisS){
                    furthestPDisS = dis[A[p][i]];
                }
            }
        }
    }
    Q.push(NO+NS-1);
    dis[NO+NS-1] = 0;
    while(Q.size()){
        ll p = Q.front();
        Q.pop();
        rep(i,A[p].size()){
            if(dis[A[p][i]] == 1000000){
                Q.push(A[p][i]);
                dis[A[p][i]] = dis[p] +1;
                if(dis[A[p][i]] > furthestPDisE){
                    furthestPDisE = dis[A[p][i]];
                }
            }
        }
    }
    cout << furthestPDisE + furthestPDisS << endl;
}