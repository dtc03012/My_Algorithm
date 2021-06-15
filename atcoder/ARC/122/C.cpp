#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
typedef pair<int,int> pi;
typedef pair<lld,lld> pl;
typedef pair<int,lld> pil;
typedef pair<lld,int> pli;
typedef vector<int> vit;
typedef vector<vit> vitt;
typedef vector<lld> vlt;
typedef vector<vlt> vltt;
typedef vector<pi> vpit;
typedef vector<vpit> vpitt;
typedef long double ld;
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define mk(a,b) make_pair(a,b)
bool isrange(int y,int x,int n,int m){
	 if(0<=y&&y<n&&0<=x&&x<m) return true;
	 return false;
}
int dy[4] = {1,0,-1,0},dx[4]={0,1,0,-1},ddy[8] = {1,0,-1,0,1,1,-1,-1},ddx[8] = {0,1,0,-1,1,-1,1,-1};


void solve(int tc){
	lld n;
	cin >> n;
	vector<lld> v;
	lld f1 = 1,f2 = 1;
	v.push_back(f1);
	while(f1+f2<1e18){
		v.push_back(f1+f2);
		lld tmp = f1;
		f1 = f1 + f2;
		f2 = tmp;
	}
	vector<int> k;
	for(int e=sz(v)-1;e>=0;e--){
		if(n>=v[e]){
			k.push_back(e);
			n -= v[e];
		}
	}
	vector<int> ans;
	int t[66][2];
	memset(t,0,sizeof(t));
	if(sz(k)){
		vector<int> v;
		for(int e=0;e<=(k[0]/2);e++){
			v.push_back(4);
			v.push_back(3);
		}
		int lim = (k[0]/2);
		for(int e=0;e<sz(k);e++){
			int now = k[e] / 2;
			t[lim-now][k[e]%2] = 1;
		}
		for(int e=0;e<sz(v);e+=2){
			if(t[e/2][0]) ans.push_back(2);
			if(t[e/2][1]) ans.push_back(1);
			ans.push_back(4);
			ans.push_back(3);
		}
	}
	cout << sz(ans) << "\n";
	lld k1 = 0,k2 = 0;
	for(int e=0;e<sz(ans);e++){
		 cout << ans[e] << "\n";
		 if(ans[e]==1) k1++;
		 else if(ans[e]==2) k2++;
		 else if(ans[e]==3) k1 = k1 + k2;
		 else k2 = k1 + k2;
	}
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}