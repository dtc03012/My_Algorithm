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

const int MAX = 1010;
const int DP1 = 27;
const int DP2 = 77;
const lld MOD1 = 3932;
const lld MOD2 = 2038;
string arr[MAX];
vector<pair<string,int> > v[21];
int ans[MAX],cnt1[MOD1][MOD2],cnt2[MOD1][MOD2];
void solve(int tc){
	int n;
	cin >> n;
	for(int e=0;e<n;e++) cin >> arr[e];
	int q;
	cin >> q;
	for(int e=0;e<q;e++){
		string a;
		cin >> a;
		v[sz(a)].push_back(mk(a,e));
	}
	for(int e=1;e<=20;e++){
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,-1,sizeof(cnt2));
		lld lim1 = 1,lim2 = 1;
		for(int p=0;p<e;p++){
			lim1 = (lim1*DP1)%MOD1;
			lim2 = (lim2*DP2)%MOD2;
		}
		for(int p=0;p<n;p++){
			if(sz(arr[p])<e) continue;
			lld f1 = 0,f2 = 0;
			for(int q=0;q<e;q++){
				f1 = (f1*DP1+(arr[p][q]-'a'+1))%MOD1;
				f2 = (f2*DP2+(arr[p][q]-'a'+1))%MOD2;
			}
			cnt2[f1][f2] = p;
			cnt1[f1][f2]++;
			for(int q=e;q<sz(arr[p]);q++){
				f1 = (f1*DP1)%MOD1;
				f2 = (f2*DP2)%MOD2;
				lld k1 = (arr[p][q-e]-'a'+1)*lim1;
				lld k2 = (arr[p][q-e]-'a'+1)*lim2;
				k1 %= MOD1;
				k2 %= MOD2;
				f1 = (f1-k1+MOD1)%MOD1;
				f2 = (f2-k2+MOD2)%MOD2;
				f1 = (f1+(arr[p][q]-'a'+1))%MOD1;
				f2 = (f2+(arr[p][q]-'a'+1))%MOD2;
				if(cnt2[f1][f2]!=p){
					cnt2[f1][f2] = p;
					cnt1[f1][f2]++;
				}
			}
		}
		for(int p=0;p<sz(v[e]);p++){
			string& now = v[e][p].x;
			int wh = v[e][p].y;
			lld f1 = 0,f2 = 0;
			for(int q=0;q<sz(now);q++){
				f1 = (f1*DP1+(now[q]-'a'+1))%MOD1;
				f2 = (f2*DP2+(now[q]-'a'+1))%MOD2;
			}
			ans[wh] = cnt1[f1][f2];
		}
	}
	for(int e=0;e<q;e++) cout << ans[e] << "\n";
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