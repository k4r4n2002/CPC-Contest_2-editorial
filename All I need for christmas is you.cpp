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
#define eps 1e-8

using namespace std;
 
#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<int> r(n);
    for(int i=0; i<n; i++) {
        cin>>r[i];
    }
    sort(r.begin(), r.end());
    for(int i=1 ; i<n ;i++) r[i]+=r[i-1];
    

    while(q--){
        int X; cin>>X;
        cout<<upper_bound(r.begin(), r.end(), X)-r.begin()<<endl;

    }
    
    
}