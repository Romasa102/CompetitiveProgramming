#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll t;
    cin >> t;
    rep(_,t){
        ll n,k;
        cin >> n >> k;
        ll h[n];
        rep(i,n)cin >> h[i];

        priority_queue<pair<ll,P>> pq;
        rep(i,n){
            if(h[i] > h[(i+1)%n]){
                pq.push({h[i]-h[(i+1)%n],{(i+1)%n,i}});
            }else{
                pq.push({h[(i+1)%n]-h[i],{i,(i+1)%n}});
            }
        }
        ll left = -1;
        ll right = 1LL<<60;
        while(right > left + 1){
            ll mid = (left + right + 1)/2;
            cout << "CUR AT " << mid << endl;
            bool condition = true;
            ll curk = k;
            ll g[n];
            rep(i,n) g[i] = h[i];
            auto q = pq;
            auto pushEdge = [&](ll a, ll b){
                if(g[a] > g[b]){
                    q.push({g[a]-g[b],{b,a}});
                }else{
                    q.push({g[b]-g[a],{a,b}});
                }
            };
            while(q.top().first > mid && curk >= 0){
                auto cur = q.top();
                q.pop();
                ll ind1 = cur.second.first;
                ll ind2 = cur.second.second;
                ll diff = cur.first;
                if(g[ind2]- g[ind1] != diff){
                    pushEdge(ind1, ind2);
                    continue;
                }
                curk -= g[ind2]-g[ind1]-mid;
                cout << "used : " <<  g[ind2]-g[ind1]-mid << " to bring " << ind2 << " to " << g[ind1]+mid << endl;
                g[ind2] = g[ind1]+mid;
                pushEdge((ind2-1+n)%n, ind2);
                pushEdge(ind2, (ind2+1)%n);
            }
            if(q.top().first > mid || curk < 0){
                condition = false;
            }
            if(condition){
                right = mid;
            }else{
                left = mid;
            }
        }
        cout << right << '\n';
    }
}