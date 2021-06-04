#include <iostream>
 
using namespace std;
 
int main()
{
    int n; cin >> n;
 
    int s = 0, e = n + 1;
    while(e - s > 6)
    {
        int m1 = (2 * s + e) / 3;
        int m2 = (s + 2 * e) / 3;
        cout << "? " << m1 << endl; cout.flush();
        int x; cin >> x;
        cout << "? " << m2 << endl; cout.flush();
        int y; cin >> y;
 
        if(x >= y) s = m1 - 1;
        else e = m2 + 1;
    }
 
    for(int i = s + 1; i < e; ++i)
    {
        cout << "? " << i << endl; cout.flush();
        int x; cin >> x;
 
        if(i > 1)
        {
            cout << "? " << i - 1 << endl; cout.flush();
            int y; cin >> y;
            if(y <= x) continue;
        }
 
        if(i < n)
        {
            cout << "? " << i + 1 << endl; cout.flush();
            int y; cin >> y;
            if(y <= x) continue;
        }
 
        cout << "! " << i << endl; cout.flush();
        return 0;
    }
}