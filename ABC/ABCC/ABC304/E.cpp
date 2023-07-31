#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
ll find(ll parent[],ll num){
    if(parent[num] == num){
        return num;
    }
    return find(parent,parent[num]);
}
int main(){
    ll N,M;
    cin >> N >> M;
    vector<P> uv(M);
    ll rank[N];
    ll parent[N];
    rep(i,N){
        rank[i] = 1;
        parent[i] = i;
    }
    rep(i,M){
        cin >> uv[i].first >> uv[i].second;
        ll E1 = find(parent,uv[i].first-1);
        ll E2 = find(parent,uv[i].second-1);
        if(E1 != E2){
            if(rank[E1] > rank[E2]){    
                parent[E2] = E1;
                rank[E1] += rank[E2];
                rank[E2] = 0;
            }else{
                parent[E1] = E2;
                rank[E2] += rank[E1];
                rank[E1] = 0;
            }
        }
    }
    ll K;
    cin >> K;
    vector<P> xy(K);
    map<P,ll> connection;
    rep(i,K){
        cin >> xy[i].first >> xy[i].second;
        ll F  = find(parent,xy[i].first-1);
        ll S = find(parent,xy[i].second-1);
        if(F > S){
            swap(F,S);
        }
        connection[{F,S}] = 1;
    }
    ll Q;
    cin >> Q;
    rep(i,Q){
        bool Noo = false;
        int merge1,merge2;
        cin >> merge1 >> merge2;
        ll M1 = find(parent,merge1-1);
        ll M2 = find(parent,merge2-1);
        if(M1>M2){
            swap(M1,M2);
        }
        if(connection.count({M1,M2})){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }
}