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
	lld x,y;
	cin >> x  >> y;
	if(x==y){
		printf("0");
	}else if(y<x){
		printf("%lld",x-y);
	}else{
		lld rans = 1e18;
		lld k = 1,e = 0;
		while(k*x<=3e18){
			lld tot = abs(y - k*x);
			lld ans = e + (tot/k);
			tot %= k;
			while(tot){
				if((tot&3)==3){
					tot++;
					ans++;
				}
				else if(tot&1){
					tot--;
					ans++;
				}
				tot /= 2;
			}
			rans = min(rans,ans);
			k *= 2;
			e++;
		}
		printf("%lld\n",rans);
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
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}