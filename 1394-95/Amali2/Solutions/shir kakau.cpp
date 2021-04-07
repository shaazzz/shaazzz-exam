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
const int maxn = 1e5 + 100;
const ll inf = 1LL << 60;
ll mn[maxn * 4], lz[maxn * 4];
int n, h[maxn], w[maxn], L;
inline void add(int id, ll val){
	lz[id] += val;
	mn[id] += val;
	smin(mn[id], inf);
}
inline void shift(int id){
	add(L(id), lz[id]);
	add(R(id), lz[id]);
	lz[id] = 0LL;
}
inline void add(int x, int y, ll val, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y)	return ;
	if(x <= l && r <= y){
		add(id, val);
		return ;
	}
	int mid = (l + r)/2;
	shift(id);
	add(x, y, val, L(id), l, mid);
	add(x, y, val, R(id), mid, r);
	mn[id] = min(mn[L(id)], mn[R(id)]);
}
inline ll ask(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y)	return inf;
	if(x <= l && r <= y)	return mn[id];
	int mid = (l + r)/2;
	shift(id);
	return min(
			ask(x, y, L(id), l, mid),
			ask(x, y, R(id), mid, r)
	);
}
stack <int> s;
ll p[maxn], dp[maxn], q[maxn];
int main(){
	scanf("%d %d", &n, &L);
	For(i,0,n){
		scanf("%d %d", h + i, w + i);
		q[i] = (i ? p[i-1] : 0LL);
		p[i] = q[i] + w[i];
	}
	For(i,0,n){
		add(i, i + 1, h[i]);
		while(!s.empty() && h[s.top()] <= h[i]){
			int y = s.top();
			s.pop();
			int x = 1 + (s.empty() ? -1 : s.top());
			add(x, y + 1, h[i] - h[y]);
		}
		s.push(i);
		int j = lower_bound(q, q + i + 1, p[i] - L) - q;
		dp[i] = ask(j, i + 1);
		if(i + 1 < n)
			add(i + 1, i + 2, dp[i]);
	}
	printf("%lld\n", dp[n - 1]);
	return 0;
}
