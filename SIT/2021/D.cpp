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
	int n,a,b;
	string s;
	cin >> n >> a >> b >> s;
	vector<pi> v;
	for(int e=0;e<n-1;e++){
		if(s[e]=='0'&&s[e+1]=='0'&&a){
			v.push_back(mk(e+1,e+2));
			s[e] = '1';
			s[e+1] = '1';
			e++;
			a--;
		}
	}
	if(a){
		printf("NO\n");
		return;
	}
	int tot = 0;
	for(int e=0;e<n;e++){
		if(s[e]=='0') tot++;
	}
	if(tot>=b){
		printf("YES\n");
		for(int e=0;e<sz(v);e++) printf("%d %d\n",v[e].x,v[e].y);
		for(int e=0;e<n;e++){
			if(s[e]=='0'&&b){
				printf("%d\n",e+1);
				b--;
			}
		}
	}else{
		printf("NO\n");
	}
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	/*
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}