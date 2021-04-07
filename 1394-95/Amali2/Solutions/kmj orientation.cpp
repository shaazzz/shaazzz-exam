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
const int maxn = 1e5 + 100, mod = 1e9 + 7;
vi adj[maxn];
int N, M;
int n, m;
int dp[maxn];
bool mark[maxn];
inline void dfs(int v){
	mark[v] = true;
	++ N;
	dp[v] = 1;
	rep(u, adj[v]){
		++ M;
		if(!mark[u]){
			dfs(u);
			dp[v] = (dp[v] + dp[u]) % mod;
		}
	}
}
int main(){
	int ans = 1;
	scanf("%d %d", &n, &m);
	while(m--){
		int v, u;
		scanf("%d %d", &v, &u);
		-- v, -- u;
		adj[v].pb(u);
		adj[u].pb(v);
	}
	For(i,0,n)	if(!mark[i]){
		N = M = 0;
		dfs(i);
		M /= 2;
		if(M > N){
			cout << 0 << endl;
			return 0;
		}
		ans = (ans * 1LL * (M < N ? dp[i] : 2)) % mod;
	}
	printf("%d\n", ans);
	return 0;
}
