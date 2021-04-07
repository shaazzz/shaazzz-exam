#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
#define rep(i, c) for(auto &(i) : (c))
#define x first
#define y second
#define pb push_back
#define PB pop_back()
#define iOS ios_base::sync_with_stdio(false)
#define sqr(a) (((a) * (a)))
#define all(a) a.begin() , a.end()
#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define L(x) ((x)<<1)
#define R(x) (((x)<<1)+1)
#define umap unordered_map
#define double long double
typedef long long ll;
typedef pair<int, int>pii;
typedef vector<int> vi;
typedef complex<ll> point;
template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}
//template <typename T> using os =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 3e5 + 100;
int s[maxn];
vi adj[maxn];
ll ans;
pii pls[maxn];
vector<pii> bnd[maxn];
inline void dfs(int v){
	rep(u, adj[v])	dfs(u);
	if(adj[v].empty()){
		int sz = s[v] + 1;
		bnd[v].pb({sz/2, sz - (sz/2)});
		adj[v].clear();
		return ;
	}
	if((int)adj[v].size() == 1){
		int u = adj[v][0];
		bnd[v].swap(bnd[u]);
		bnd[u].clear();
		pls[v] = pls[u];
		int sz = s[v] + 1;
		bnd[v].pb({(sz/2) - pls[v].x, sz - (sz/2) - pls[v].y});
		adj[v].clear();
		return ;
	}
	int x = adj[v][0], y = adj[v][1];
	int mx = 1;
	For(i, 1, min(bnd[x].size(), bnd[y].size()) + 1){
		pii p = *(bnd[x].end() - i), q = *(bnd[y].end() - i);
		int s = p.y + pls[x].y + q.x + pls[y].x;
		smax(mx, (s >> 1));
	}
	ans += 2LL * mx;
	++ mx;
	if(bnd[x].size() < bnd[y].size()){
		bnd[v].swap(bnd[y]);
		bnd[y].clear();
		pls[v] = pls[y];
		pls[v].x -= mx;
		pls[v].y += mx;
		For(i,1,bnd[x].size()+1){
			pii p = *(bnd[x].end() - i), q = *(bnd[v].end() - i);
			int l = p.x + pls[x].x + mx, r = q.y + pls[y].y + mx;
			bnd[v][(int)bnd[v].size()-i] = {l - pls[v].x, r - pls[v].y};
		}
		bnd[x].clear();
	}
	else{
		bnd[v].swap(bnd[x]);
		bnd[x].clear();
		pls[v] = pls[x];
		pls[v].x += mx;
		pls[v].y -= mx;
		For(i,1,bnd[y].size()+1){
			pii p = *(bnd[v].end() - i), q = *(bnd[y].end() - i);
			int l = p.x + pls[x].x + mx, r = q.y + pls[y].y + mx;
			bnd[v][(int)bnd[v].size()-i] = {l - pls[v].x, r - pls[v].y};
		}
		bnd[y].clear();
	}
	int sz = s[v] + 1;
	bnd[v].pb({(sz/2) - pls[v].x, sz - (sz/2) - pls[v].y});
	adj[v].clear();
}
int main(){
	iOS;
	int n;
	string t;
	cin >> n >> t;
	s[0] = t.size();
	For(i,1,n){
		int par;
		cin >> t >> par;
		s[i] = t.size();
		-- par;
		adj[par].pb(i);
	}
	For(i,0,n)
		ans += 3 * (int)s[i] + 6 + 3 * (int)adj[i].size();
	dfs(0);
	cout << ans << endl;
	return 0;
}
