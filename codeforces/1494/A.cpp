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
	string a;
	cin >> a;
	vector<char> v;
	v.push_back('A');
	v.push_back('B');
	v.push_back('C');
	bool suc = false;
	do{
		for(int e=0;e<8;e++){
			string now = "";
			for(int p=0;p<sz(a);p++){
				for(int q=0;q<3;q++){
					if(a[p]==v[q]){
						if(e&(1<<q)) now += "(";
						else now += ")";
					}
				}
			}
			int tot = 0,ck = 0;
			for(int e=0;e<sz(now);e++){
				if(now[e]=='(') tot++;
				else tot--;
				if(tot<0) ck++;
			}
			if(tot!=0) ck++;
			if(!ck) suc = true;
		}
	}while(next_permutation(all(v)));
	if(suc) printf("YES\n");
	else printf("NO\n");
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