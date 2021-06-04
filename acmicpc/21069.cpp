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


vector<int> f(int x){
	vector<int> v;
	int tmp = x;
	for(int e=2;e*e<=x;e++){
		if(tmp%e==0){
			v.push_back(e);
			while(tmp%e==0) tmp/=e;
		}
	}
	if(tmp!=1) v.push_back(tmp);
	return v;
}
void solve(int tc){
	int k;
	cin >> k;
	vector<int> v1 = f(k);
	vector<int> v2 = f(k+1);
	set<int> s;
	for(int e=0;e<sz(v1);e++) s.insert(v1[e]);
	for(int e=0;e<sz(v2);e++) s.insert(v2[e]);
	printf("%d\n",sz(s));
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}