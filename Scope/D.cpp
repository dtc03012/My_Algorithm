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

const int MAX = 111;
double mm[5];
int kk[5];
string arr1[MAX],arr2[MAX];
struct inf{
	int type,y,x,wh;
};
bool comp(inf a,inf b){
	if(a.type!=b.type) return a.type < b.type;
	if(kk[a.wh]!=kk[b.wh]) return kk[a.wh] > kk[b.wh];
	if(a.y!=b.y) return a.y < b.y;
	return a.x < b.x;
}
vector<inf> v;
void solve(int tc){
	for(int e=0;e<5;e++){
		cin >> mm[e];
		kk[e] = (int)(mm[e]*10);
	}
	int n,m;
	cin >> n >> m;
	vector<inf> v;
	for(int e=0;e<n;e++) cin >> arr1[e];
	for(int e=0;e<n;e++) cin >> arr2[e];
	for(int e=0;e<n;e++){
		for(int p=0;p<m;p++){
			if(arr1[e][p]=='Y'){
				v.push_back({0,e,p,arr2[e][p]-'A'});
			}else if(arr1[e][p]=='O'){
				v.push_back({1,e,p,arr2[e][p]-'A'});
			}
		}
	}
	sort(all(v),comp);
	for(int e=0;e<sz(v);e++){
		printf("%c %.1lf %d %d\n",char(v[e].wh+'A'),mm[v[e].wh],v[e].y,v[e].x);
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