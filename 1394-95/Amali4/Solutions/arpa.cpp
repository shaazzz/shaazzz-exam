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
typedef pair<ll,ll>pii;
typedef vector<int> vi;
typedef complex<ll> point;
template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}
//template <typename T> using os =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 8e6 + 100, MAX = 5e5 + 100;
bool bad[maxn];
int p[MAX], nx;
int m;
inline int go(int n, int k, int a){
	rof(i,k-1,-1){
		int nx = p[i] % n;
		if(nx == a)
			a = 0;
		else if(nx > a)
			++ a;
		int t = p[i]/n;
		t %= (n-1);
		if(a){
			a %= m;
			a = (a + t) % m;
			if(!a)
				a = m;
		}
	}
	return a + 1;
}
int main(){
	iOS;
	bad[0] = bad[1] = true;
	For(i,2,maxn)	if(!bad[i]){
		p[nx ++] = i;
		for(int j = i + i; j < maxn; j += i)
			bad[j] = true;
	}
	int n, k, a;
	cin >> n >> k >> a;
	-- a;
	m = n - 1;
	For(i,0,k){
		int nx = p[i] % n;
		int t = p[i]/n;
		t %= (n-1);
		if(a){
			a %= m;
			a -= t;
			a = ((a%m) + m) % m;
			if(!a)
				a = m;
		}
		if(!a)
			a = nx;
		else if(nx >= a)
			-- a;
		a = (a + n) % n;
	}
	int y = (n+a-1) % n;
	int x = (a+1) % n;
	assert(k <= nx);
	cout << go(n, k, x) << ' ' << go(n, k, y) << endl;
	return 0;
}
