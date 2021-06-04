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

	const int MAX = 505050;
	int go[MAX];
	void solve(int tc){
		string s;
		cin >> s;
		vector<string> v;
		string xx = "";
		for(int e=0;e<sz(s);e++){
			if(s[e]=='R'){
				v.push_back(xx);
				xx = "";
			}else xx += s[e];
		}
		v.push_back(xx);
		string tot = "";
		for(int e=0;e<sz(v);e++){
			int diff = sz(v) - e - 1;
			if(diff%2) reverse(all(v[e]));
		}
		string f1 = "",f2 = "";
		if(sz(v)%2){
			for(int e=sz(v)-2;e>=1;e-=2) f1 += v[e];
			for(int e=0;e<sz(v);e+=2) f2 += v[e];
			tot = f1 + f2;
		}else{
			for(int e=1;e<sz(v);e+=2) f1 += v[e];
			for(int e=sz(v)-2;e>=0;e-=2) f2 += v[e];
			tot = f2 + f1;
		}
		stack<char> S;
		for(int e=0;e<sz(tot);e++){
			if(sz(S)==0) S.push(tot[e]);
			else{
				if(S.top()==tot[e]) S.pop();
				else S.push(tot[e]);
			}
		}
		string ans = "";
		while(!S.empty()){
			ans += S.top();
			S.pop();
		}
		reverse(all(ans));
		cout << ans;
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