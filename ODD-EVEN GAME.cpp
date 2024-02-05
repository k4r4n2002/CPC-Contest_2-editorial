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
    int n;
    cin >> n;
    int f = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        f |= (x & 1); // if(odd) f=1
    }
    cout << (f ? "first" : "second") << endl;
}
