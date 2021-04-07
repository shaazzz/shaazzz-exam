#include <bits/stdc++.h>
using namespace std;


const int MAXN = 1005;

int N;
int cows [MAXN];
int best [MAXN][2], best2 [MAXN][2];

inline void mini (int &a, int b)
{
    if (b < a) a = b;
}

int main ()
{
    memset (best, 63, sizeof (best));

    scanf ("%d", &N);

    for (int i = 1; i <= N; i++)
	scanf ("%d", cows + i);

    cows [++N] = 0;

    sort (cows + 1, cows + N + 1);

    for (int i = 1; i <= N; i++)
	if (cows [i] == 0)
	    best [i][0] = 0;


    for (int len = 1; len < N; len++)
    {
	int ccount = N - len;

	memset (best2, 63, sizeof (best2));

	for (int i = 1; i + len <= N + 1; i++)
	{
	    mini (best2 [i - 1][0], best [i][0] + ccount * (cows [i] - cows [i - 1]));
	    mini (best2 [i - 1][0], best [i][1] + ccount * (cows [i + len - 1] - cows
[i - 1]));

	    mini (best2 [i][1], best [i][0] + ccount * (cows [i + len] - cows [i]));
	    mini (best2 [i][1], best [i][1] + ccount * (cows [i + len] - cows [i + len
- 1]));
	}

	memcpy (best, best2, sizeof (best));
    }

    printf ("%d\n", min(best [1][0] , best [1][1]));

    return 0;
}
