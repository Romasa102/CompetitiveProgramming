#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
ll H,W;
bool graph[5000][5000];
P parent[5000][5000];
P find(P a){
    if(parent[a.first][a.second]==a){
        return a;
    }
    return parent[a.first][a.second]=find(parent[a.first][a.second]);
}
void Union(P a,P b){
    parent[find(a).first][find(a).second]=find(b);
}
int main(){
    cin >> H >> W;
    ll Q;
    rep(i,H){
        rep(j,W){
            graph[i][j]=false;
            parent[i][j]={i,j};
        }
    }
    cin >> Q;
    rep(i,Q){
        ll que;
        cin >> que;
        if(que == 1){
            ll r,c;
            cin >> r >> c;
            r--;c--;
            graph[r][c]=true;
            if(r+1<H&&graph[r+1][c]){
                Union({r,c},{r+1,c});
            }
            if(r-1>=0&&graph[r-1][c]){
                Union({r,c},{r-1,c});
            }
            if(c+1<W&&graph[r][c+1]){
                Union({r,c},{r,c+1});
            }
            if(c-1>=0&&graph[r][c-1]){
                Union({r,c},{r,c-1});
            }
        }else{
            ll r,c,rb,cb;
            cin >> r >> c >> rb >> cb;
            r--;c--;rb--;cb--;
            if(!graph[r][c]||!graph[rb][cb]){
                cout << "No" << endl;
                continue;
            }
            if(find({r,c})==find({rb,cb})){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
}