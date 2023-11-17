#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll n,m;
    cin >> n >> m;
    ll x[n],y[n];
    rep(i,n)cin >> x[i] >> y[i];
    ll a[m],b[m],c[m];
    rep(i,m)cin >> a[i] >> b[i] >> c[i];
    map<ll,vector<P>> rout;
    rep(i,m){
        rout[a[i]-1].push_back({b[i]-1,c[i]});
        rout[b[i]-1].push_back({a[i]-1,c[i]});
    }
    priority_queue<pair<ll,P>,vector<pair<ll,P>>,greater<pair<ll,P>>> pq;//price,currentPosition,previousPosition
    ll dis[n][n];
    rep(i,n)rep(j,n)dis[i][j]=1LL<<32;
    for(P i:rout[0]){
        dis[0][i.first]=i.second;
        pq.push({i.second,{i.first,0}});
    }
    bool visited[n];
    rep(i,n)visited[i]=false;
    while(!pq.empty()){
        ll priceC = pq.top().first;
        ll curP = pq.top().second.first;
        ll prevP = pq.top().second.second;
        visited[curP]=true;
        pq.pop();
        if(priceC>dis[prevP][curP])continue;
        for(P i:rout[curP]){
            double cL = (x[i.first]-x[curP])*(x[i.first]-x[curP])+(y[i.first]-y[curP])*(y[i.first]-y[curP]);
            double bL = (x[prevP]-x[curP])*(x[prevP]-x[curP])+(y[prevP]-y[curP])*(y[prevP]-y[curP]);
            double aL = (x[prevP]-x[i.first])*(x[prevP]-x[i.first])+(y[prevP]-y[i.first])*(y[prevP]-y[i.first]);
            //cout <<"angle of " << i.first << " " << curP << " " << prevP   << " is "<< acos((bL+cL-aL)/(2*sqrt(bL)* sqrt(cL)))/M_PI*180 <<endl;
            if((bL+cL-aL)<=0 || prevP == i.first){
                if(!visited[i.first]){
                    if(dis[curP][i.first]>dis[prevP][curP]+i.second){
                        dis[curP][i.first]=min(dis[curP][i.first],dis[prevP][curP]+i.second);
                        pq.push({dis[curP][i.first],{i.first,curP}});
                    }
                }
            }
        }
    }
    if(!visited[1]){
        cout << -1 << endl;
        return 0;
    }
    ll ans = 1LL<<32;
    rep(i,n){
        ans = min(ans,dis[i][1]);
    }
    cout << ans << endl;
}