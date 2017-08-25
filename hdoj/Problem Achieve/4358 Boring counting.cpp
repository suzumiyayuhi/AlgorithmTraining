    #include <iostream>    
    #include <sstream>    
    #include <algorithm>    
    #include <vector>    
    #include <queue>    
    #include <stack>    
    #include <map>    
    #include <set>    
    #include <bitset>    
    #include <cstdio>    
    #include <cstring>    
    #include <cstdlib>    
    #include <cmath>    
    #include <climits>    
    #define maxn 100005  
    #define eps 1e-6   
    #define mod 10007   
    #define INF 99999999    
    #define lowbit(x) (x&(-x))    
    //#define lson o<<1, L, mid    
    //#define rson o<<1 | 1, mid+1, R    
    typedef long long LL;  
    using namespace std;  
      
    char s[maxn];  
    int t[maxn], t2[maxn], c[maxn], sa[maxn];  
    void build(int n, int m)  
    {  
        int i, *x = t, *y = t2, k, p;  
        for(i = 0; i < m; i++) c[i] = 0;  
        for(i = 0; i < n; i++) c[x[i] = s[i]]++;  
        for(i = 1; i < m; i++) c[i] += c[i-1];  
        for(i = n-1; i >= 0; i--) sa[--c[x[i]]] = i;  
        for(k = 1; k <= n; k<<=1) {  
            p = 0;  
            for(i = n-k; i < n; i++) y[p++] = i;  
            for(i = 0; i < n; i++) if(sa[i] >= k) y[p++] = sa[i] - k;  
            for(i = 0; i < m; i++) c[i] = 0;  
            for(i = 0; i < n; i++) c[x[y[i]]]++;  
            for(i = 1; i < m; i++) c[i] += c[i-1];  
            for(i = n-1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];  
            swap(x, y), p = 1, x[sa[0]] = 0;  
            for(i = 1; i < n; i++)  
                x[sa[i]] = y[sa[i]] == y[sa[i-1]] && y[sa[i]+k] == y[sa[i-1]+k] ? p-1 : p++;  
            if(p >= n) break;  
            m = p;  
        }  
    }  
    int rank[maxn], height[maxn];  
    void getheight(int n)  
    {  
        int i, j, k = 0;  
        for(i = 0; i <= n; i++) rank[sa[i]] = i;  
        for(i = 0; i < n; i++) {  
            if(k) k--;  
            j = sa[rank[i]-1];  
            while(s[i+k] == s[j+k]) k++;  
            height[rank[i]] = k;  
        }  
    }  
    void debug(int n)  
    {  
        int i;  
        for(i = 0; i < n; i++)  
            printf("%d   %d\n", height[i], i);  
    }  
    int solve(int p, int n)  
    {  
        int ans = 0, _min, _max, i;  
        _min = INF, _max = 0;  
        for(i = 1; i <= n; i++) {  
            if(height[i] >= p) {  
                _max = max(_max, sa[i]);  
                _min = min(_min, sa[i]);  
                _max = max(_max, sa[i-1]);  
                _min = min(_min, sa[i-1]);  
            }  
            else {  
                if(_max - _min >= p) ans++;  
                _max = 0;  
                _min = INF;  
            }  
        }  
        if(_max - _min >= p) ans++;  
        return ans;  
    }  
    void work(void)  
    {  
        int n = strlen(s), ans, p;  
        build(n+1, 128);  
        getheight(n);  
        ans = 0;  
        for(p = 1; p <= (n>>1); p++)  
            ans += solve(p, n);  
        printf("%d\n", ans);  
    }  
    int main(void)  
    {  
        while(scanf("%s", s)!=EOF) {  
            if(s[0] == '#') break;  
            work();  
        }  
        return 0;  
    }  
