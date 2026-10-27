#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
map<ll,set<ll>> mp;


int main(){
    ll N,M;
    cin >> N >> M;
    ll S,T;
    cin >> S >> T;S--;T--;
    ll A[M],B[M];
    rep(i,M){
        ll A,B;
        cin >> A >> B;
        A--;B--;

        mp[A].insert(B);
    }
    priority_queue<P,vector<P>,greater<P>> pq; // cost point;
    vector<ll> visited(N,-1);
    pq.push({0,S});
    while(!pq.empty()){
        P cur = pq.top();
        pq.pop();
        if(visited[cur.second]!=-1)continue;
        visited[cur.second] = cur.first;
        bool firstN = true;
        for(auto i : mp[cur.second]){
            if(firstN){
                if(visited[i] == -1){
                    pq.push({cur.first,i});
                }
                firstN = false;
            }else{
                if(visited[i] == -1){
                    pq.push({cur.first+1,i});
                }
            }
        }
    }
    cout << visited[T] << endl;
}