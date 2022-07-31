#include <bits/stdc++.h>
#define ll long long
#define lowbit(x) x & -x
using namespace std;
const int N = 2e5 + 10;
ll n, res;
int a[N], tr[N];
void add(int x, int k)
{
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += k;
}
int ask(int x)
{
    int sum = 0;
    for (int i = x; i >= 1; i -= lowbit(i)) sum += tr[i];
    return sum;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        res += ask(n) - ask(a[i]);
        add(a[i], 1);
    }
    cout << res;
    return 0;
}