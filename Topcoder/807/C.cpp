#include <bits/stdc++.h>

using namespace std;
typedef long long int lld;
class DistancesBetweenNumbers{
public:
	long long count(int N, vector <int> Aprefix){
		vector<int> A(N);
		int L = Aprefix.size();
		for (int i=0; i<L; ++i) A[i] = Aprefix[i];
		for (int i=L; i<N; ++i) A[i] = (A[i-1] * 1103515245LL + 12345LL) % (1LL << 31);
		int v[10][10];
		memset(v,0,sizeof(v));
		for(int e=0;e<N;e++){
			int xx = A[e];
			for(int p=0;p<10;p++){
				v[p][xx%10]++;
				xx /= 10;
			}
		}
		lld ans = 0;
		for(int e=0;e<10;e++){
			for(int p=0;p<10;p++){
				ans += 1ll*(N-v[e][p])*v[e][p];
			}
		}
		ans /= 2;
		return ans;
	}
};