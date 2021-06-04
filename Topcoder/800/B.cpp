#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
typedef pair<int,int> pi;
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define mk(a,b) make_pair(a,b)
class SlotMachineHacking{
public:
	int win(vector <string> reels, vector <int> steps){
		vector<int> wh;
		for(int e=0;e<sz(reels);e++){
			int xx = -1;
			for(int p=0;p<sz(reels[e]);p++){
				if(reels[e][p]=='c') xx = p;
			}
			wh.push_back(xx);
		}
		for(int e=0;e<sz(steps);e++){
			steps[e] %= sz(reels[e]);
		}
		vector<pi> v;
		for(int e=0;e<sz(steps);e++){
			v.push_back(mk(steps[e],steps[e]));
		}
		for(int p=1;p<1000000;p++){
			bool suc = true;
			for(int q=0;q<sz(v);q++){
				if(v[q].x!=wh[q]) suc = false;
			}
			if(suc) return p - 1;
			for(int q=0;q<sz(v);q++){
				v[q].x = (v[q].x + v[q].y)%sz(reels[q]);
			}
		}
		return -1;
	}
};
void solve(int tc){
	vector<string> v;
	vector<int> v2;
	for(int e=0;e<3;e++){
		string a;
		cin >> a;
		v.push_back(a);
	}
	for(int e=0;e<3;e++){
		int k;
		scanf("%d",&k);
		v2.push_back(k);
	}
	SlotMachineHacking gh;
	printf("%d\n",gh.win(v,v2));
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	/*
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}