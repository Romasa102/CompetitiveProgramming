#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
ll w,h,n;
ll compress(ll *x1,ll *x2,ll W){
    vector<ll> xs;
    rep(i,n){//N is the number of the point in x1
        for(ll d=-1; d<=1;d++){
            ll tx1 = x1[i] + d;
            ll tx2 = x2[i] + d;
            if(1<=tx1&&tx1<=W)xs.push_back(tx1);
            if(1<=tx2&&tx2<=W)xs.push_back(tx2);
        }
    }
    sort(xs.begin(),xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    rep(i,n){
        x1[i]= lower_bound(xs.begin(),xs.end(),x1[i])-xs.begin();
        x2[i]= lower_bound(xs.begin(),xs.end(),x2[i])-xs.begin();
    }
    return xs.size();
}
int main(){
    P xyd[4] = {{0,1},{0,-1},{1,0},{-1,0}};
    cin >> w >> h >> n;
    ll LX[n],RX[n];
    ll LY[n],RY[n];
    rep(i,n){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        LX[i]=a;RX[i]=c;
        LY[i]=b;RY[i]=d;
    }
    w = compress(LX,RX,w);
    h = compress(LY,RY,h);
    bool G[w][h];
    rep(i,w)rep(j,h)G[i][j]=false;
    rep(i,n){
        repp(j,LX[i],RX[i]+1){
            repp(k,LY[i],RY[i]+1){
                G[j][k]=true;
            }
        }
    }
    rep(i,h){
        rep(j,w){
            if(G[j][i]){
                cout << "#";
            }else{
                cout << ".";
            }
        }cout << endl;
    }
    bool visited[w][h];
    ll ans = 0;
    rep(i,w)rep(j,h)visited[i][j]=false;
    rep(i,w){
        rep(j,h){
            if(G[i][j]||visited[i][j])continue;
            ans++;
            queue<P> Q;
            Q.push({i,j});
            while(!Q.empty()){
                P cur = Q.front();
                visited[cur.first][cur.second]=true;
                Q.pop();
                rep(k,4){
                    if(0>cur.first+xyd[k].first&&cur.first+xyd[k].first>=w)continue;
                    if(0>cur.second+xyd[k].second&&cur.second+xyd[k].second>=h)continue;
                    if(G[cur.first+xyd[k].first][cur.second+xyd[k].second])continue;
                    if(!visited[cur.first+xyd[k].first][cur.second+xyd[k].second]){
                        Q.push({cur.first+xyd[k].first,cur.second+xyd[k].second});
                    }
                }
            }
        }
    }
    cout << ans << endl;
}