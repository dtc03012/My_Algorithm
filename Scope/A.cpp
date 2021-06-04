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

int all[3666];
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=0;e<n;e++){
		int h1,s1,h2,s2;
		scanf("%2d:%2d ~ %2d:%2d",&h1,&s1,&h2,&s2);
		int f1 = h1*60 + s1;
		int f2 = h2*60 + s2;
		for(int e=f1;e<=f2;e++) all[e]++;
	}
	int ll = 1e9,rr = -1e9;
	for(int e=0;e<3600;e++){
		if(all[e]==n){
			ll = min(ll,e);
			rr = max(rr,e);
		}
	}
	if(ll==1e9){
		printf("-1");
		return;
	}
	int h1 = ll/60,s1 = ll%60;
	int h2 = rr/60,s2 = rr%60;
	printf("%02d:%02d ~ %02d:%02d\n",h1,s1,h2,s2);
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