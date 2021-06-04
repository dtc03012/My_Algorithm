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

const int MAX = 8000505;
bool gg[MAX];
int go[MAX][3],base = 1,v[505050],pt;
int get_rt(int rt,int os,int n){
	if(os%n==0) return rt;
	int kk = (os/n);
	kk %= (n-1);
	for(int p=0;p<=kk;p++) rt = go[rt][1];
	return rt;
}
void solve(int tc){
	memset(go,-1,sizeof(go));
	int n,k,a;
	cin >> n >> k >> a;
	for(int e=2;e<MAX;e++){
		if(gg[e]==0){
			if(pt<k) v[pt++] = e;
			for(int p=e*2;p<MAX;p+=e) gg[p] = 1;
		}
	}
	int rt = base,now = base;
	go[base][0] = a;
	int nx_pt = a + 1;
	if(nx_pt==n+1) nx_pt = 1;
	for(int e=0;e<n-1;e++){
		base++;
		go[base][0] = nx_pt;
		go[now][1] = base;
		go[base][2] = now;
		nx_pt++;
		if(nx_pt==n+1) nx_pt = 1;
		now = base;
	}
	go[now][1] = rt;
	go[rt][2] = now;
	now = rt;
	for(int e=0;e<k;e++){
		int nx_rt = get_rt(rt,v[e],n);
		go[go[rt][2]][1] = go[rt][1];
		go[go[rt][1]][2] = go[rt][2];
		int diff = v[e];
		if(e) diff -= v[e-1];
		for(int p=0;p<diff;p++) now = go[now][1];
		go[rt][2] = now;
		go[rt][1] = go[now][1];
		go[go[rt][1]][2] = rt;
		go[go[rt][2]][1] = rt;
		now = rt;
		rt = nx_rt;
	}
	while(go[rt][0]!=a) rt = go[rt][1];
	cout << go[go[rt][1]][0] << " " << go[go[rt][2]][0] << "\n";
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