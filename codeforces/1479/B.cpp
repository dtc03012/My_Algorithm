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
	 int n;
	 scanf("%d",&n);
	 vector<int> v;
	 for(int e=0;e<n;e++){
	 	int a;
	 	scanf("%d",&a);
	 	if(sz(v)==0) v.push_back(a);
	 	else{
	 		if(sz(v)==1) v.push_back(a);
	 		else{
	 			int f1 = v[sz(v)-2],f2 = v[sz(v)-1];
	 			if(a==f1&&a==f2) continue;
	 			v.push_back(a);
	 		}
	 	}
	 }
	 int ans = sz(v);
	 int lx = -1,wh = -1;
	 for(int e=1;e<sz(v);e++){
	 	if(v[e]==v[e-1]){
	 		if(lx==v[e]){
	 			int err = 0;
	 			for(int p=wh;p<=e-2;p++){
	 				if((p-wh)%2&&v[p]!=v[e]){
	 					err = 1;
	 				}
	 			}
	 			if(err==0) ans--;
	 		}
	 		lx = v[e];
	 		wh = e + 1;
	 	}
	 }
	 printf("%d\n",ans);
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