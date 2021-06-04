#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define mk(a,b) make_pair(a,b)
using namespace std;
const int MAX = 1e6 + 100;
class ConstantSegment{
public:
	vector<int> v[MAX];
	int sendSomeHome(int N, int K, int M, vector <int> Pprefix, int seed){
		vector<int> P(N);
		int L = Pprefix.size();
		for (int i=0; i<L; ++i) P[i] = Pprefix[i];
		long long state = seed;
		for (int i=L; i<N; ++i) {
		    state = (state * 1103515245 + 12345) % (1LL << 31);
		    P[i] = (state / 16) % M;
		}
		for(int e=0;e<N;e++){
			v[P[e]].push_back(e);
		}
		int ans = 1e9;
		for(int e=0;e<M;e++){
			if(sz(v[e])<K) continue;
			int tot = 0,ll = -1;
			for(int p=0;p<K;p++){
				if(ll!=-1) tot += v[e][p] - ll - 1;
				ll = v[e][p]; 
			}
			ans = min(ans,tot);
			for(int p=K;p<sz(v[e]);p++){
				int diff = v[e][p-K+1] - v[e][p-K] - 1;
				tot -= diff;
				tot += v[e][p] - v[e][p-1] - 1;
				ans = min(ans,tot);
			}
		}
		if(ans==1e9) ans = -1;
		return ans;
	}
};