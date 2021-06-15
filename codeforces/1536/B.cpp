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

vector<string> res;
map<string,int> ck;
void dfs(string v,int len){
	if(len==3) return;
	for(int e=0;e<26;e++){
		string nv = v + char(e+'a');
		res.push_back(nv);
		dfs(nv,len+1);
	}
}
bool comp(string& a,string& b){
	if(sz(a)!=sz(b)) return sz(a) < sz(b);
	return a < b;
}
void solve(int tc){
	ck.clear();
	int n;
	string a;
	cin >> n >> a;
	for(int e=0;e<n;e++){
		string xx = "";
		for(int p=e;p<min(n,e+3);p++){
			xx += a[p];
			ck[xx] = 1;
		}
	}
	for(int e=0;e<sz(res);e++){
		if(ck[res[e]]==0){
			cout << res[e] << "\n";
			return;
		}
	}
}


int main(void){
	dfs("",0);
	sort(all(res),comp);
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