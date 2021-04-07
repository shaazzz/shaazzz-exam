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
typedef long long ll;
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef complex<double> point;
template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}
template <typename T> using os =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 400 + 10;
vi adj[maxn];
int mc[maxn], mt[maxn];
bool mark[maxn];
int ans;
int n, x[maxn], y[maxn], r[maxn];
inline bool dfs(int v){
	if(mark[v])	return false;
	mark[v] = true;
	rep(u, adj[v])	if(mt[u] == -1 or dfs(mt[u]))
		return mt[u] = v, mc[v] = u, true;
	return false;
}
inline bool ok(int i, int j){
	if(r[i] <= r[j])	return false;
	ll X = x[i] - x[j],
	 Y = y[i] - y[j],
	 dr = r[i] - r[j];
	return (X * X + Y * Y < dr * dr);
}
int main(){
	memset(mt, -1, sizeof mt);
	memset(mc, -1, sizeof mc);
	scanf("%d", &n);
	ans = n;
	For(i,0,n)
		scanf("%d %d %d", x + i, y + i, r + i);
	For(i,0,n)
		For(j,0,n)
			if(ok(i, j))
				adj[i].pb(j);
	bool fnd = true;
	while(fnd){
		fnd = false;
		fill(mark, mark + n, false);
		For(i,0,n)
			if(mc[i] == -1 && dfs(i))
				-- ans, fnd = true;
	}
	cout << ans << endl;
	return 0;
}
