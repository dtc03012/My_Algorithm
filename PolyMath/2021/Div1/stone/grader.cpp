/** PMCC2 Div1B. Stone - Grader
    Code by 79brue
*/
#include "stone.h"
#include <cstdio>
#include <cassert>
#include <vector>

namespace {
    int t, n;
    int arr[602] = {0};
    bool ok = 1;
    int query_count;
}

int investigate(std::vector<int> location){ /// investigate function
    query_count++;
    if(query_count > 5*n || (int)location.size() > n+5 || location.empty()){ /// check array size
        ok = 0;
        return -1;
    }
    int bits = 0; /// store information by bitmask
    for(auto x: location){
        if(!((-5 <= x && x <= -1) || (1 <= x && x <= n))){ /// check element range
            ok = 0;
            return -1;
        }
        if(x<0) bits |= 1<<(-x);
        else bits |= (1 << arr[x]);
    }
    return __builtin_popcount(bits);
}

int main(){
    int n_sum = 0;
    scanf("%d", &t); /// input test case
    while(t--){ /// repeat the following procedures
        assert(scanf("%d", &n) == 1); /// input n
        for(int i=1; i<=n; i++) assert(scanf("%d", &arr[i]) == 1); /// input array

        n_sum += n;
        assert(1 <= n && n <= 600);
        assert(n_sum <= 600);
        for(int i=1; i<=n; i++) assert(1 <= arr[i] && arr[i] <= 5);

        ok = 1, query_count = 0;
        std::vector<int> ret = find_stone(n); /// find_stone
        for(int i=1; i<=n; i++){ /// check if accepted
            if(ret[i-1] != arr[i]) ok = 0;
        }
        printf("%s (used %d queries, n=%d)\n", ok ? "Correct" : "Incorrect", query_count, n); /// print verdict10
    }
}
