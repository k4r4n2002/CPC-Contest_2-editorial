
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

;
int v[500010];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
 
    cin>>n>>k;
    for(int i = 0;i<n;i++) cin>>v[i];
    
    int ans = 1;
    int lans(0),rans(0);
    map<int,int> cnt;
    int diff = 1;
    int l = 0,r = 1;
    cnt[v[0]]++;
    
    while(r<n){

        if(diff<k){
            if(cnt[v[r]]==0) diff++;// element that is to be included in the window is not present in map, we got a new element
            cnt[v[r]]++;// update in map
            r++;// increase the window
        }else{
            if(cnt[v[r]]==0){// new element on right of window
                cnt[v[l]]--;//we need to shrink the left side the window
                if(cnt[v[l]]==0) diff--;// if it was only occurence of the elemnt our diff count decreases
                l++;// shrink
            }else{
                cnt[v[r]]++;// we already have an occurence in our map 
                // in otehr words if we add this element, it does not increase number of distinct elements in our window
                r++;
            }
        }   
 
        if(ans<r-l){// update the answer
            ans = r-l;
            lans = l;
            rans = r-1;
        }
    }
 
    cout<<lans+1<<" "<<rans+1<<endl;// 1- based indexing
 
    return 0;
}