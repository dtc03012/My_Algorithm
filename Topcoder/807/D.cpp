#include <bits/stdc++.h>

using namespace std;
typedef long long int lld;
class Flagpole{
public:
	long long build(vector <int> segments, long long LO, long long HI){
		vector<lld> res1,res2;
		int len = (int)segments.size();
		int lim = (len)/2;
		lld tot = 0;
		for(int e=0;e<(1ll<<lim);e++){
			lld f1 = 0;
			for(int p=0;p<lim;p++){
				if(e&(1<<p)) f1 += segments[p];
			}
			res1.push_back(f1);
		}
		int rlim = len - lim;
		for(int e=0;e<(1ll<<rlim);e++){
			lld f1 = 0;
			for(int p=0;p<rlim;p++){
				if(e&(1<<p)) f1 += segments[p+lim];
			}
			res2.push_back(f1);
		}
		sort(res2.begin(),res2.end());
		for(int e=0;e<(int)res1.size();e++){
			int lw = lower_bound(res2.begin(),res2.end(),LO-res1[e]+1) - res2.begin();
			int rw = lower_bound(res2.begin(),res2.end(),HI-res1[e]+1) - res2.begin();
			tot += rw - lw;
		}
		return tot;
	}
};

int main(void){
	Flagpole gh;
	vector<int> v = {10, 10, 10, 10, 10};
	cout << gh.build(v,9,49);
}