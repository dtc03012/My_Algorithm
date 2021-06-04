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

const int MAX = 202020;
int cnt[26],ck[26],now[26];
set<int> s[26];
void solve(int tc){
	string a;
	cin >> a;
	for(int e=0;e<26;e++){
		cnt[e] = ck[e] = 0 ;
	}
	for(int e=sz(a)-1;e>=0;e--){
		int now = a[e] - 'a';
		s[now].insert(e);
	}
	for(int e=0;e<26;e++){
		if(sz(s[e])==0) continue;
		for(int p=0;p<26;p++){
			if(e==p) continue;
			if(sz(s[p])==0) continue;
			if(*s[e].begin()>*prev(s[p].end())){
				cnt[e]++;
			}
		}
	}
	string ans = "";
	priority_queue<pi> q;
	for(int e=0;e<26;e++){
		if(cnt[e]==0&&sz(s[e])){
			now[e] = *s[e].begin();
			q.push(mk(e,*s[e].begin()));
		}
	}
	int lim = -1;
	while(!q.empty()){
		pi x = q.top();q.pop();
		if(now[x.x]!=x.y) continue;
		if(x.y<=lim) continue;
		ck[x.x] = 1; 
		s[x.x].clear();
		ans += char(x.x+'a');
		lim = x.y;
		for(int e=0;e<26;e++){
			if(sz(s[e])){
				for(set<int>::iterator it = s[e].begin();it!=s[e].end();){
					if(*it<=lim) s[e].erase(it++);
					else break;
				}
			}
		}
		memset(cnt,0,sizeof(cnt));
		for(int e=0;e<26;e++){
			if(sz(s[e])==0) continue;
			if(ck[e]) continue;
			for(int p=0;p<26;p++){
				if(e==p) continue;
				if(sz(s[p])==0) continue;
				if(ck[p]) continue;
				if(*s[e].begin()>*prev(s[p].end())){
					cnt[e]++;
				}
			}
		}
		for(int e=0;e<26;e++){
			if(cnt[e]==0&&sz(s[e])&&ck[e]==0){
				q.push(mk(e,*s[e].begin()));
				now[e] = *s[e].begin();
			}
		}
	}
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