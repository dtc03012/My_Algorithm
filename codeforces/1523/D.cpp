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

const int MAX = 202020;
const int NNMAX = 10000;
const int NMAX = 1000;
const int NMAX = 20000;
string arr[MAX];
int cnt[MAX];
void solve(int tc){
	clock_t start = clock();
	int n,m,k;
	cin >> n >> m >> k;
	if(n<NNMAX){
	vector<pair<bitset<n>,pli> > v;
	for(int e=0;e<n;e++) cin >> arr[e];
	int lim = (n/2);
	if(n%2) lim++;
	bitset<n> bs;
	for(int e=0;e<n;e++) bs[e] = 1;
	v.push_back(mk(bs,mk(0,0)));
	for(int e=0;e<m;e++){
		clock_t end = clock();
		if((double)(end - start) / CLOCKS_PER_SEC > 2.8)break;
		int len = sz(v);
		bitset<n> now;
		for(int q=0;q<n;q++) if(arr[q][e]=='1') now[q] = 1;
		for(int p=0;p<len;p++){
			if(cnt[p]) continue;
			bitset<n> xx = now & v[p].x;
			if(xx.count()<lim) continue;
			lld now2 = v[p].y.x ^ (1ll<<e);
			int now3 = v[p].y.y + 1;
			bool flag = false;
			for(int q=0;q<len;q++){
				bitset<n> kk = v[q].x & xx;
				if(kk == xx&&v[q].y.y>=now3){
					flag = true;
				}else if(kk == v[q].x&&v[q].y.y<now3){
					cnt[q] = 1;
				}
			}
			if(flag) continue;
			v.push_back(mk(xx,mk(now2,now3)));
		}
	}
	int ans = 0;
	lld bit = 0;
	for(int e=0;e<sz(v);e++){
		if(v[e].y.y>ans){
			ans = v[e].y.y;
			bit = v[e].y.x;
		}
	}
	for(int e=0;e<m;e++){
		if(bit&(1ll<<e)) cout << "1";
		else cout << "0";
	}
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}