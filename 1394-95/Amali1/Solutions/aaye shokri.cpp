#include "libmean.h"
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
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef complex<double> point;
template <typename T> using os =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}
int a[102];
int n;
vi v;
inline void ask(){
	vi u;
	For(i,0,5)
		u.pb(v[i]);
	map<int,int> mp;
	map<int,int> which;
	For(i,0,u.size()){
		int nx = 0;
		int b[5];
		For(j,0,u.size())	if(j - i)	b[nx ++] = u[j] + 1;
		int sum = Meandian(b[0], b[1], b[2], b[3]) * 2;
		mp[sum] ++;
		which[sum] = u[i];
	}
	int sum = 0, x = 0;
	rep(p, mp){
		if(p.y == 1)
			x = p.x;
		else
			sum += 2 * p.x;
	}
	int val = (sum - 2 * x)/4;
	int ind = which[x];
	a[ind] = val;
	v.erase(find(all(v), ind));
}
int main(void){
	n = Init();
	For(i,0,n)
		v.pb(i);
	fill(a,a+n,-1);
	while(v.size() >= 5)
		ask();
	Solution(a);
	return 0;
}
