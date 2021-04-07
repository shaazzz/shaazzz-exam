#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
//#define rep(i, c) for(auto &(i) : (c))
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
//template <typename T> using os =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 1e5 + 100;
int a[maxn], b[maxn], n;
const ll inf = 1LL << 60;
ll dp[maxn];
vi v, u;
inline ll ask(){
	For(i,0,v.size())
		if(v[i] == u[i])
			return inf;
	ll ans = 0LL;
	For(i,0,v.size())
		ans += abs(v[i] - u[i]);
	return ans;
}
int main(){
	iOS;
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	For(i,0,n)
		cin >> a[i] >> b[i];
	sort(a, a + n);
	sort(b, b + n);
	fill(dp, dp + maxn, inf);
	if(a[0] != b[0])	dp[0] = abs(a[0] - b[0]);
	For(i,1,n){
		v.clear();
		u.clear();
		For(j,1,4)	if(i - j + 1 >= 0){
			v.pb(a[i - j + 1]);
			u.pb(b[i - j + 1]);
			sort(all(v));
			sort(all(u));
			do{
				smin(dp[i], (i - j < 0 ? 0LL : dp[i-j]) + ask());
			}while(next_permutation(all(v)));
		}
	}
	cout << dp[n-1] << endl;
	return 0;
}

