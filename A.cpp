#include <bits/stdc++.h>
using namespace std;
 
int n;
int a[100005];
int odd,even;
 
void inp()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}
 
void proc()
{
    odd = even = 0;
    for (int i = 1; i <= n; i++)
    {
        odd += a[i]%2;
        even += 1-a[i]%2;
    }
    cout << min(odd,even) << '\n';
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
