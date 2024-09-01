#include <bits/stdc++.h>
using namespace std;

long long power(int base, int exp) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
        if (result > LLONG_MAX || result < 0) {
            return LLONG_MAX; // If overflow happens, return a large value.
        }
    }
    return result;
}

int NthRoot(int n, int m) {
    int low = 1;
    int high = m;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long ans = power(mid, n);
        cout<<ans<<endl;

        if (ans < m) {
            low = mid + 1;
        } else if (ans > m) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}
int main()
{
    // int n=9;
    // int m=1953125;
    int n=5;
    int m=32768;
    int ans=NthRoot(n,m);
    cout<<ans;
}