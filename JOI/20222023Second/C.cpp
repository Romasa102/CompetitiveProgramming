#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
P find(vector<vector<P>> parent,P num){
    if(parent[num.first][num.second] == num){
        return num;
    }
    return find(parent,parent[num.first][num.second]);
}
int main(){
    ll H,W;
    cin >> H >>W;
    ll A[H][W];
    rep(i,H){
        rep(j,W){
            cin >> A[i][j];
        }
    }
    vector<vector<P>> parent(H, vector<P>(W));
    rep(i,H){
        rep(j,W){
            parent[i][j] = {i,j};
        }
    }
    rep(i,H){
        rep(j,W){
            if(i+1 != H && A[i][j]==A[i+1][j]){
                parent[i][j] = find(parent,{i+1,j});
            }
            if(i-1 >= 0 && A[i][j]==A[i-1][j]){
                parent[i][j] = find(parent,{i-1,j});
            }
            if(j+1 != W && A[i][j]==A[i][j+1]){
                parent[i][j] = find(parent,{i,j+1});
            }
            if(j-1 >= 0 && A[i][j]==A[i][j-1]){
                parent[i][j] = find(parent,{i,j-1});
            }
        }
    }
    rep(i,H){
        rep(j,W){
            if(i+1 != H && A[i][j]==A[i+1][j]){
                parent[i][j] = find(parent,{i+1,j});
            }
            if(i-1 >= 0 && A[i][j]==A[i-1][j]){
                parent[i][j] = find(parent,{i-1,j});
            }
            if(j+1 != W && A[i][j]==A[i][j+1]){
                parent[i][j] = find(parent,{i,j+1});
            }
            if(j-1 >= 0 && A[i][j]==A[i][j-1]){
                parent[i][j] = find(parent,{i,j-1});
            }
        }
    }
    ll maxAns = 0;
    map<P,ll> size;
    rep(i,H){
        rep(j,W){
            size[find(parent,parent[i][j])]++;
            maxAns = max(maxAns,size[find(parent,parent[i][j])]);
        }
    }
    map<P,map<ll,ll>> m;
    map<P,map<ll,set<P>>> adjacent;

    rep(i,H){
        rep(j,W){
            if(i+1 != H && A[i][j]!=A[i+1][j]){
                adjacent[parent[i][j]][A[i+1][j]].insert(parent[i+1][j]);
            }
            if(i-1 >= 0 && A[i][j]!=A[i-1][j]){
                adjacent[parent[i][j]][A[i-1][j]].insert(parent[i-1][j]);
            }
            if(j+1 != W && A[i][j]!=A[i][j+1]){
                adjacent[parent[i][j]][A[i][j+1]].insert(parent[i][j+1]);
            }
            if(j-1 >= 0 && A[i][j]!=A[i][j-1]){
                adjacent[parent[i][j]][A[i+1][j-1]].insert(parent[i][j-1]);
            }
        }
    }
    



    
}