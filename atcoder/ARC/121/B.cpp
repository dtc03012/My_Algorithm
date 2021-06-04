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

vector<pair<lld,int> > v1,v2;
vector<lld> v[3];
void solve(int tc){
	int n;
	cin >> n;
	for(int e=0;e<n*2;e++){
		lld x;
		char y[2];
		cin >> x >> y;
		if(y[0]=='B') v[0].push_back(x);
		else if(y[0]=='R') v[1].push_back(x);
		else v[2].push_back(x);
	}
	for(int e=0;e<3;e++) sort(all(v[e]));
	int f1 = -1,f2 = -1,f3 = -1;
	for(int e=0;e<3;e++){
		if(sz(v[e])%2){
			if(f1==-1) f1 = e;
			else if(f2==-1) f2 = e;
		}else{
			f3 = e;
		}
	}
	if(f1==-1){
		cout << "0";
	}else{
		lld ans1 = 1e18;
		for(int e=0;e<sz(v[f1]);e++){
			lld x = v[f1][e];
			int wh = lower_bound(all(v[f2]),x) - v[f2].begin();
			if(wh!=sz(v[f2])){
				ans1 = min(ans1,abs(v[f2][wh]-x));
			}
			if(wh){
				wh--;
				ans1 = min(ans1,abs(v[f2][wh]-x));
			}
		}
		for(int e=0;e<sz(v[f3]);e++){
			lld x = v[f3][e];
			int wh = lower_bound(all(v[f1]),x) - v[f1].begin();
			lld ans2 = 1e18;
			if(wh!=sz(v[f1])){
				ans2 = min(ans2,abs(v[f1][wh]-x));
			}
			if(wh){
				wh--;
				ans2 = min(ans2,abs(v[f1][wh]-x));
			}
			v1.push_back(mk(ans2,e));
		}
		for(int e=0;e<sz(v[f3]);e++){
			lld x= v[f3][e];
			int wh = lower_bound(all(v[f2]),x) - v[f2].begin();
			lld ans3 = 1e18;
			if(wh!=sz(v[f2])){
				ans3 = min(ans3,abs(v[f2][wh]-x));
			}
			if(wh){
				wh--;
				ans3 = min(ans3,abs(v[f2][wh]-x));
			}
			v2.push_back(mk(ans3,e));
		}
		sort(all(v1));
		sort(all(v2));
		lld ans2 = 1e18;
		for(int e=0;e<min(sz(v1),3);e++){
			for(int p=0;p<min(sz(v2),3);p++){
				if(v1[e].y!=v2[p].y){
					ans2 = min(ans2,v1[e].x+v2[p].x);
				}
			}
		}
		cout << min(ans1,ans2);
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