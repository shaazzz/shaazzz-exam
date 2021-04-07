#include <bits/stdc++.h>
using namespace std;

inline int in() { int x; scanf("%d", &x); return x; }
const int N = 200002;

vector <int> ms;
int cnt[N], w[N], mass[N], n, m;

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		w[i] = in();
	for(int i = 0; i < m; i++)
		ms.push_back(mass[i] = in());
		
	sort(mass, mass + m);
	sort(ms.begin(), ms.end());
	ms.resize(unique(ms.begin(), ms.end()) - ms.begin());
	assert(ms.size() <= 30);
	
	for(int i = 0; i < n; i++)
		for(int j = ms.size() - 1; j >= 0; j--)
		{
			cnt[j] += w[i] / ms[j];
			w[i] %= ms[j];
		}
	long long have = 0;
	int ans = 0, pointer = 0;
	for(int i = 0; i < m; i++)
	{
		if(have < mass[i])
		{
			while(pointer < ms.size() && (cnt[pointer] == 0 || ms[pointer] < mass[i]))
			{
				pointer++;
				have = 0;
			}
			if(pointer < ms.size())
			{
				have = ms[pointer];
				cnt[pointer]--;
			}
			else
				break;
		}
		have -= mass[i];
		ans++;
	}
	cout << ans << endl;
}
