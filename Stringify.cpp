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

const int N = 1000100;

using namespace std;

bool subsequence(string& s1, string& s2)
{
    int n = s1.length(), m = s2.length();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (s1[i] == s2[j])
            j++;
        i++;
    }
    /*If j reaches end of s2,that mean we found all
    characters of s2 in s1,
    so s2 is subsequence of s1, else not*/
    return j == m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, p;
    cin>>s>>p;
    
    int n=s.length(), m= p.size();
    vector<int> a(n);
    for(int i=0; i<n ;i++){
        cin>>a[i];
        a[i]--;
    }
    auto check =[&](int mid){// can i delete mid elements
        //if i delete first mid elements, then I'll be left with elements at indices mid....n-1(0-based)
        string temp="";
        vector<int> v;
        
        for(int i=mid; i<n ;i++) v.push_back(a[i]);//indices all the elemnts that will be left in string temp;
        sort(v.begin(), v.end());// they have to be in the order they are supposed to be

        for(auto x: v) temp+=s[x];

        return subsequence(temp, p);// is p a subsequence of temp;


    };

    
    int lo=0, hi=n, mid, ans;
    while(lo<=hi){
        mid=(lo+hi)>>1;
        if(check(mid)){
            ans=mid;
            lo=mid+1;
        }
        else hi=mid-1;
    }
    cout<<ans;


        
}
