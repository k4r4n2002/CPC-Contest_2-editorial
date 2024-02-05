#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>

using namespace std;

#define int long long
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q, l, r;
        cin >> n >> q;
        vector<int> a(n + 3), pre(n + 3);
        vector<pair<int, int>> queries;
        // memset()
        while (q--)
        {
            cin >> l >> r;
            queries.push_back({l, r});
            a[l]++;
            a[r + 1]--;
        }
        for (int i = 1; i <= n; i++)
        {
            a[i] += a[i - 1];
        }
        for (auto x : queries)
        {
            a[x.second + 1] -= (x.second - x.first + 1);
        }
        for (int i = 1; i <= n; i++)
            a[i] += a[i - 1];
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}
