#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<int> d(n);
        vector<int> a(n);

        for (i = 0; i < n; i++)
        {
            cin >> d[i];
        }

        a[0] = d[0];

        for (i = 1; i < n; i++)
        {
            if (d[i] == 0)
            {
                a[i] = a[i - 1];
            }

            else
            {
                if (a[i - 1] - d[i] >= 0)
                {
                    cout << "-1" << endl;
                    break;
                }
                else
                {
                    a[i] = a[i - 1] + d[i];
                }
            }
        }

        if (i == n)
        {
            for (i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
