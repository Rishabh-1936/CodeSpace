#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p32;
const ll mod = 1000000007;
vector<vector<pair<ll, ll>>> edges;
ll n, m;

void dijsktra() 
{
    set<pair<ll, ll>> setds; // for getting node in ascending order of their
    weight till now.
    vector dist(n+1, LLONG_MAX);

    dist[1] = 0;     // starting from node 1.
    setds.insert(make_pair(0, 1));

    while(!setds.empty()) 
    {
	    pair<ll, ll> minWeightNode = (*setds.begin());

	    for(auto child : edges[minWeightNode.second]) {
		    ll node = child.first;
 		    ll w = child.second;
 		    ll tillDist = minWeightNode.first + w;

 		    if(tillDist < dist[node]) {
 			    if(dist[node] != LLONG_MAX) {
 				    setds.erase(make_pair(dist[node], node));
 			    }
 			    dist[node] = tillDist;
 			    setds.insert(make_pair(tillDist, node));
 		    }
 	    }
 	    setds.erase((*setds.begin()));
    }

    for(ll i=1; i<=n; i++) printf("%lld ", dist[i]);

}

void solve() 
{
    cin>>n>>m;
    edges.resize(n+1);

    for(ll i=0; i<m; i++) {
        ll s, d, w;
        scanf("%lld %lld %lld", &s, &d, &w);
        edges[s].push_back(make_pair(d, w));
    }
    dijsktra();
}

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int main() {
    init_code();
    ll t;
    // cin>>t;
    t = 1;
    while(t--) {
	    solve();
    }

    return 0;
}