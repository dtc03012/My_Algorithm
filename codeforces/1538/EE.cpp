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

struct inf{
	string pre,suf,org;
	lld ans;
	int sz;
};
int find(string& a,int l,int r){
	int ans = 0;
	for(int e=l;e<=r;e++){
		if(e+3<sz(a)){
			if(a[e]=='h'&&a[e+1]=='a'&&a[e+2]=='h'&&a[e+3]=='a') ans++;
		}
	}
	return ans;
}
void solve(int tc){
	int n;
	cin >> n;
	map<string,inf> ck;
	for(int e=0;e<n;e++){
		string f1,ope;
		cin >> f1 >> ope;
		if(ope==":="){
			string f2;
			cin >> f2;
			ck[f1] = {f2,f2,f2,find(f2,0,sz(f2)-4),sz(f2)};
		}else{
			string k1,k2,ope2;
			cin >> k1 >> ope2 >> k2;
			lld ans1 = ck[k1].ans + ck[k2].ans;
			string nans = ck[k1].suf + ck[k2].pre;
			ans1 += find(nans,max(0,sz(ck[k1].suf)-3),sz(ck[k1].suf)-1);
			string vv = "";
			string pre = "",suf = "",org = "";
			if(ck[k1].sz>=20){
				pre = ck[k1].pre;
			}else{
				pre = ck[k1].org + ck[k2].pre;
			}
			if(ck[k2].sz>=20){
				suf = ck[k2].suf;
			}else{
				suf = ck[k1].suf + ck[k2].org;
			}
			org = ck[k1].pre + ck[k2].suf;
			ck[f1] = {pre,suf,org,ans1,sz(org)};
		}
		if(e==n-1) cout << ck[f1].ans << "\n";
	}	
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