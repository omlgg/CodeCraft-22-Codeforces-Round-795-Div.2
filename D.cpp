#include <bits/stdc++.h>
#define int long long
#define ll long long
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;
 
const int MAX = 2e5+6;
const int MOD = 1e9+7;
 
struct Data{
	ll L = -10000000000000, R =-10000000000000, S=0, G = -10000000000000;
};
 
int n, m, a[MAX], L[MAX], R[MAX];
Data t[MAX*4];
 
Data Combine(Data a, Data b){
	Data ret;
	ret.L = max(a.L, a.S + b.L);
	ret.R = max(b.R, b.S + a.R);
	ret.G = max({a.G, b.G, a.R + b.L});
	ret.S = a.S + b.S;
	return ret;
}
 
void Update(int id, int l, int r, int pos, int val){
	if (r==l){
		t[id].L = val;
		t[id].R = val;
		t[id].S = val;
		t[id].G = val;
		return;
	}
	int mid = (l+r)/2;
	if (pos<=mid) Update(id*2, l, mid, pos, val);
	else Update(id*2+1, mid+1,r, pos, val);
	t[id] = Combine(t[id*2], t[id*2+1]);
}
 
Data Query(int id, int l, int r, int L, int R){
    if (R<l || r<L)  {
        Data tmp;
        tmp.G = -10000000000000;
        return tmp;
    }
    if (L<=l && r<=R) return t[id];
    int mid = (l+r)/2;
    return Combine(Query(id*2, l, mid , L, R), Query(id*2+1, mid+1,r,L,R));
}
 
 
void inp()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], Update(1,1,n,i,a[i]);
    a[0] = INT_MAX;
    a[n+1] = INT_MAX;
}
 
void proc()
{
    bool invalid = 0;
    stack<int> st;
    st.push(0);
    FOR(i,1,n)
    {
        while (st.size() && a[st.top()] <= a[i]) st.pop();
        L[i] = st.top();
        st.push(i);
    }
 
 
    while (st.size()) st.pop();
    st.push(n+1);
    FORD(i,n,1)
    {
        while (st.size() && a[st.top()] <= a[i]) st.pop();
        R[i] = st.top();
        st.push(i);
    }
 
 
 
    FOR(i,1,n)
    {
        if (a[i] < Query(1,1,n,L[i]+1,R[i]-1).G)
        {
            invalid = true;
        }
    }
    if (invalid) cout << "NO\n";
    else cout << "YES\n";
}
 
void mult()
{
    int t;
	cin >> t;
	while (t--)
    {
        inp();
        proc();
    }
}
 
signed main()
{
	  ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    mult();
	  return 0;
}
