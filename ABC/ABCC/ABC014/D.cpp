#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
vector<vector<ll>> jmp;
vector<ll> visited;
vector<ll> dep;
ll LOG;
ll lcaL(ll a,ll b){
    if(dep[a]==dep[b]){
        //cout << a << b << "same parent" << endl;;
        ll curA = a;
        ll curB = b;
        ll ans = 0;
        for(int i = LOG-1; i >=0; i --){
            if(jmp[curA][i] != jmp[curB][i]){
                ans+=1<<i;
                curA=jmp[curA][i];
                curB=jmp[curB][i];
            }
        }
        return 2*(ans+1);
    }else{
        //cout << a << b << "diff parent" << endl;;
        if(dep[a] > dep[b])swap(a,b);
        ll dif = dep[b] - dep[a];
        ll cur = b;
        rep(i,LOG){
            if(1<<i & dif){
                cur = jmp[cur][i];
            }
        }
        if(a == cur)return dif;
        //cout << a << b << "called next" << endl;;
        return lcaL(a,cur) + dif;
    }
}
int main(){
    ll N;
    cin >> N;
    map<ll,vector<ll>> mp;
    ll x[N-1],y[N-1];
    rep(i,N-1){
        cin >> x[i] >> y[i];
        x[i]--;y[i]--;
        mp[x[i]].push_back(y[i]);
        mp[y[i]].push_back(x[i]);
    }
    ll Nc=N;
    while(Nc>0){
        Nc/=2;
        LOG++;
    }
    queue<P> q;
    q.emplace(0,-1);
    visited.resize(N,false);
    dep.resize(N,-1);
    visited[0]=true;
    dep[0]=0;
    jmp.resize(N,vector<ll>(LOG,0));
    while(!q.empty()){
        auto cur = q.front();q.pop();
        jmp[cur.first][0]=cur.second;
        for(auto i : mp[cur.first]){
            if(!visited[i]){
                visited[i]=true;
                dep[i]=dep[cur.first]+1;
                q.emplace(i, cur.first);
            }
        }
    }
    repp(i,1,LOG){
        rep(j,N){
            if(jmp[j][i-1]==-1){
                jmp[j][i] = -1;
            }else{
                jmp[j][i] = jmp[jmp[j][i-1]][i-1];
            }
        }
    }
    /*rep(i,LOG){
        rep(j,N){
            cout << jmp[j][i] << " ";
        }cout << endl;
    }*/


    ll Q;cin >> Q;
    ll a[Q],b[Q];
    rep(i,Q){
        cin >> a[i] >> b[i];a[i]--;b[i]--;
        cout << lcaL(a[i],b[i]) + 1 << endl;;
    }

}