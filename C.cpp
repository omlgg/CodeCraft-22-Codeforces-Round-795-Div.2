#include <bits/stdc++.h>
using namespace std;
 
int n,k;
string s;
 
void inp()
{
    cin >> n >> k;
    cin >> s;
    s = ' ' + s;
}
 
void proc()
{
    int firstans = 0;
    for (int i = 1; i <= n; i++)
    {
        int num = s[i] - '0';
        if (i > 1) firstans += num;
        if (i < n) firstans += num*10;
    }
 
    int pos;
    int sum = firstans;
    if (s[n] == '0')
    {
        pos = -1;
        for (int i = n-1; i > 0; i--)
        if (s[i] == '1')
        {
            if (n-i <= k)
            {
                pos = i;
                k -= n-i;
            }
            break;
        }
        if (pos != -1)
        {
            if (pos == 1) sum -= 9;
            else sum -= 10;
 
            while (pos < n)
            {
                swap(s[pos],s[pos+1]);
                pos++;
            }
        }
    }
    if (s[1] == '0')
    {
        pos = -1;
        for (int i = 2; i < n; i++)
        if (s[i] == '1')
        {
            if (i-1 <= k)
            pos = i;
            break;
        }
        if (pos != -1)
        {
            sum--;
 
            while (pos > 1)
            {
                swap(s[pos],s[pos-1]);
                pos--;
            }
        }
    }
    cout << sum << '\n';
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
