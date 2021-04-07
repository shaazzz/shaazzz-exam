#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> edge;

const int maxc = 26;
vector<string> vs;
vector<string> as;
int N;
int adj[maxc][maxc];
int deg[maxc];
struct node {
	node *child[maxc];
	bool is_end;
	node() {
		for (int i = 0; i < maxc; i++) child[i] = NULL;
		is_end = false;
	}
	void insert(string &s, int i, int id) {
		if (i == s.size()) {
			is_end = true;
			return;
		}
		int t = s[i] - 'a';
		if (child[t] == NULL) {
			//doesn't exist
			child[t] = new node(); // make a new node
		}
		child[t]->insert(s, i + 1, id);
	}
	bool dfs(string &s, int i) {
		if (i == s.size()) {
			return true;
		}
		if (is_end) return false;
		int t = s[i] - 'a';
		for (int j = 0; j < maxc; j++) {
			if (j != t && child[j] != NULL) {
				adj[t][j] = 1;
			}
		}
		return child[t]->dfs(s, i + 1);
	}
};
bool check() {
// if has cycle return false, else return true
	for (int i = 0; i < maxc; i++) {
		for (int j = 0; j < maxc; j++) {
			if (adj[i][j]) {
				deg[j]++; // incoming to node j
			}
		}
	}
	queue<int> q;
	for (int i = 0; i < maxc; i++) {
		if (deg[i] == 0) q.push(i);
	}
	int c = 0;
	while (q.size()) {
		int cur = q.front();
		q.pop();
		c++;
		for (int i = 0; i < maxc; i++) {
			if (adj[cur][i]) {
				deg[i]--;
				if (deg[i] == 0) q.push(i);
			}
		}
	}
	return c == maxc;
}
node *root = new node();
int main() {
	int ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		vs.push_back(s);
		root->insert(s, 0, i);
	}
	for (int i = 0; i < N; i++) {
		memset(adj, 0, sizeof(adj));
		memset(deg, 0, sizeof(deg));
		if (root->dfs(vs[i], 0) && check()) {
			ans++;
			as.push_back(vs[i]);
		}
	}
	cout << ans << '\n';
	for (int i = 0; i < ans; i++) {
		cout << as[i] << '\n';
	}

}
