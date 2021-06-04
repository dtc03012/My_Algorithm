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

int cnt[26];
bool can(int n,int k){
	for(int p=0;p<26;p++){
		int xx = cnt[p]%k;
		if(xx){
			xx = k - xx;
			if(xx>n) return false;
			n -= xx;
		}
	}
	if(n%k) return false;
	return true;
}
void makes(string& xx,int n,int k){
	string last = "";
	for(int p=0;p<26;p++){
		int yy = cnt[p]%k;
		if(yy){
			yy = k - yy;
			for(int q=0;q<yy;q++) last += char(p+'a');
			n -= yy;
		}
	}
	for(int p=0;p<n;p++) xx += "a";
	xx += last;
}
void solve(int tc){
	memset(cnt,0,sizeof(cnt));
	int n,k;
	cin >> n >> k;
	string a;
	cin >> a;
	int wh = -1,whn = -1;
	for(int e=0;e<n;e++){
		if(a[e]=='z'){
			cnt[a[e]-'a']++;
		}else{
			for(int p=25;p>=a[e]-'a'+1;p--){
				cnt[p]++;
				if(can(n-e-1,k)){
					wh = e;
					whn = p;
				}
				cnt[p]--;
			}
			cnt[a[e]-'a']++;
		}
	}
	if(can(0,k)){
		cout << a << "\n";
	}
	else if(wh==-1) cout << "-1\n";
	else{
		memset(cnt,0,sizeof(cnt));
		string xx = "";
		for(int e=0;e<wh;e++){
			cnt[a[e]-'a']++;
			xx += a[e];
		}
		xx += char(whn+'a');
		cnt[whn]++;
		makes(xx,n-wh-1,k);
		cout << xx << "\n";
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