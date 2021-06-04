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

int can[33];
void solve(int tc){
	int n;
	scanf("%d",&n);
	vector<int> v1,v2;
	for(int e=0;e<n-1;e++){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		v1.push_back(c);
		v2.push_back(d);
	}
	for(int e=0;e<sz(v1);e++){
		for(int p=30;p>=0;p--){
			if(v1[e]&(1<<p)){
				if(can[p]==0){
					can[p] = v1[e];
					break;
				}else{
					v1[e] ^= can[p];
				}
			}
		}
	}
	bool suc = true;
	for(int e=0;e<sz(v2);e++){
		int rl = v2[e];
		for(int p=30;p>=0;p--){
			if(v2[e]&(1<<p)){
				if(can[p]) v2[e] ^= can[p];
			}
		}
		if(v2[e]) suc = false;
	}
	if(suc) printf("YES\n");
	else printf("NO\n");
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