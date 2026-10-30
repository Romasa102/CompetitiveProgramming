#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
#define all(x)  begin(x), end(x)
#define sz(x) (int)(x).size()
/**
 * Author: Stanford
 * Date: Unknown
 * Source: Stanford Notebook
 * Description: Min-cost max-flow.
 *  If costs can be negative, call setpi before maxflow, but note that negative cost cycles are not supported.
 *  To obtain the actual flow, look at positive values only.
 * Status: Tested on kattis:mincostmaxflow, stress-tested against another implementation
 * Time: $O(F E \log(V))$ where F is max flow. $O(VE)$ for setpi.
 */

 #include <bits/extc++.h> /// include-line, keep-include

const ll INF = numeric_limits<ll>::max() / 4;

struct MCMF {
	struct edge {
		int from, to, rev;
		ll cap, cost, flow;
	};
	int N;
	vector<vector<edge>> ed;
	vector<int> seen;
	vector<ll> dist, pi;
	vector<edge*> par;

	MCMF(int N) : N(N), ed(N), seen(N), dist(N), pi(N), par(N) {}

	void addEdge(int from, int to, ll cap, ll cost) {
		if (from == to) return;
		ed[from].push_back(edge{ from,to,sz(ed[to]),cap,cost,0 });
		ed[to].push_back(edge{ to,from,sz(ed[from])-1,0,-cost,0 });
	}

	void path(int s) {
		fill(all(seen), 0);
		fill(all(dist), INF);
		dist[s] = 0; ll di;

		__gnu_pbds::priority_queue<pair<ll, int>> q;
		vector<decltype(q)::point_iterator> its(N);
		q.push({ 0, s });

		while (!q.empty()) {
			s = q.top().second; q.pop();
			seen[s] = 1; di = dist[s] + pi[s];
			for (edge& e : ed[s]) if (!seen[e.to]) {
				ll val = di - pi[e.to] + e.cost;
				if (e.cap - e.flow > 0 && val < dist[e.to]) {
					dist[e.to] = val;
					par[e.to] = &e;
					if (its[e.to] == q.end())
						its[e.to] = q.push({ -dist[e.to], e.to });
					else
						q.modify(its[e.to], { -dist[e.to], e.to });
				}
			}
		}
		repp(i,0,N) pi[i] = min(pi[i] + dist[i], INF);
	}

	pair<ll, ll> maxflow(int s, int t) {
		ll totflow = 0, totcost = 0;
		while (path(s), seen[t]) {
			ll fl = INF;
			for (edge* x = par[t]; x; x = par[x->from])
				fl = min(fl, x->cap - x->flow);

			totflow += fl;
			for (edge* x = par[t]; x; x = par[x->from]) {
				x->flow += fl;
				ed[x->to][x->rev].flow -= fl;
			}
		}
		repp(i,0,N) for(edge& e : ed[i]) totcost += e.cost * e.flow;
		return {totflow, totcost/2};
	}

	// If some costs can be negative, call this before maxflow:
	void setpi(int s) { // (otherwise, leave this out)
		fill(all(pi), INF); pi[s] = 0;
		int it = N, ch = 1; ll v;
		while (ch-- && it--)
			repp(i,0,N) if (pi[i] != INF)
			  for (edge& e : ed[i]) if (e.cap)
				  if ((v = pi[i] + e.cost) < pi[e.to])
					  pi[e.to] = v, ch = 1;
		assert(it >= 0); // negative cost cycle
	}
};

int main(){
    ll H,W;
    cin >> H >> W;
    char a[H][W];
    MCMF mcmf(H*W * 2);
    //W*i+j
    P startP;
    P endP;
    rep(i,H){
        rep(j,W){
            cin >> a[i][j];
            if(a[i][j]=='o'){
                mcmf.addEdge(W*i+j,W*H+i,1,1);
                mcmf.addEdge(W*i+j,W*H+j+H,1,1);
                mcmf.addEdge(W*H+i,W*i+j,1,1);
                mcmf.addEdge(W*H+j+H,W*i+j,1,1);
            }
            if(a[i][j]=='S'){
                startP = {i,j};
                mcmf.addEdge(W*i+j,W*H+i,INF,1);
                mcmf.addEdge(W*i+j,W*H+j+H,INF,1);
                mcmf.addEdge(W*H+i,W*i+j,INF,1);
                mcmf.addEdge(W*H+j+H,W*i+j,INF,1);
            }
            if(a[i][j]=='T'){
                endP ={i,j};
                mcmf.addEdge(W*i+j,W*H+i,INF,1);
                mcmf.addEdge(W*i+j,W*H+j+H,INF,1);
                mcmf.addEdge(W*H+i,W*i+j,INF,1);
                mcmf.addEdge(W*H+j+H,W*i+j,INF,1);
            }
        }
    }
    if(startP.first == endP.first || startP.second == endP.second){
        cout << -1 << endl;
        return 0;
    }
    cout << mcmf.maxflow(startP.first * W + startP.second,endP.first * W + endP.second).first << endl;
}