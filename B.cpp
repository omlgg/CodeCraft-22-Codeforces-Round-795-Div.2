#include <bits/stdc++.h>
using namespace std;
 
int n;
int s[100005];
int ans[100005];
int odd,even;
 
void inp()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
}
 
void proc()
{
    for (int i = 1; i <= n; i++)
    {
        bool flag = false;
        if (i > 1 && s[i] == s[i-1]) flag = true;
        if (i < n && s[i] == s[i+1]) flag = true;
        if (!flag)
        {
            cout << "-1\n";
            return;
        }
    }
 
    int i = 1;
    while (i <= n)
    {
        int j = i+1;
        while (j < n && s[j] == s[j+1]) j++;
        for (int k = i+1; k <= j; k++)
            ans[k] = k-1;
        ans[i] = j;
        i = j+1;
    }
 
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ' ;
    cout << '\n';
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
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mult();
    return 0;
}
