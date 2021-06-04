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
const int MAX = 101010;
map<string,int> mm;
int uf[MAX],val[MAX];
int find(int x){
	if(uf[x]!=x) return uf[x] = find(uf[x]);
	return x;
}
void solve(int tc){
	int n,k,m;
	cin >> n >> k >> m;
	for(int e=1;e<=n;e++){
		string a;
		cin >> a;
		mm[a] = e;
	}
	for(int e=1;e<=n;e++){
		int r;
		cin >> r;
		uf[e] = e;
		val[e] = r;
	}
	for(int e=0;e<k;e++){
		int x;
		cin >> x;
		int rt = -1;
		for(int p=0;p<x;p++){
			int a;
			cin >> a;
			if(rt==-1) rt = a;
			else{
				int f1 = find(rt);
				int f2 = find(a);
				uf[f2] = f1;
				val[f1] = min(val[f1],val[f2]);
			}
		}
	}
	lld ans = 0;
	for(int e=0;e<m;e++){
		string a;
		cin >> a;
		int wh = mm[a];
		wh = find(wh);
		ans += val[wh];
	}
	printf("%lld\n",ans);
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