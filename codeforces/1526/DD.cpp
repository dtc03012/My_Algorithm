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

const int MAX = 1e5 + 100;
string xx = "ANTO";
int seg[MAX*4],start= 1;
void add(int x){
	x += start;
	seg[x] += 1;
	for(int e=(x/2);e>=1;e/=2) seg[e] = seg[e*2] + seg[e*2+1];
}
int getn(int l,int r){
	l += start;
	r += start;
	int ans = 0;
	while(l<=r){
		if(l&1) ans += seg[l++];
		if(!(r&1)) ans += seg[r--];
		l >>= 1;
		r >>= 1;
	}
	return ans;	
}
int cnt[26],num[26];
vector<int> pos[26];
void solve(int tc){
	string a;
	cin >> a;
	start = 1;
	while(start<=sz(a)) start *= 2;
	for(int e=0;e<26;e++){
		cnt[e] = 0;
		pos[e].clear();
	}
	for(int e=0;e<sz(a);e++){
		cnt[a[e]-'A']++;
		pos[a[e]-'A'].push_back(e);
	}
	vector<char> v;
	v.push_back('A');
	v.push_back('N');
	v.push_back('T');
	v.push_back('O');
	sort(all(v));
	lld val = -1;
	string ans = "";
	do{
		for(int e=0;e<start*2;e++) seg[e] = 0;
		memset(num,0,sizeof(num));
		string now = "";
		for(int e=0;e<sz(v);e++){
			for(int p=0;p<cnt[v[e]-'A'];p++) now += v[e];
		}
		lld tot = 0;
		for(int e=0;e<sz(a);e++){
			int x = now[e] - 'A';
			int wh = pos[x][num[x]++];
			int rwh = wh + getn(wh,sz(a)-1);
			tot += rwh - e;
			add(wh);
		}
		if(tot>val){
			val = tot;
			ans = now;
		}
	}while(next_permutation(all(v)));
	cout << ans << "\n";
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