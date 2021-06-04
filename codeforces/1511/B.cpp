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

pl v[10];
bool isprime(lld x){
	for(lld p=2;p*p<=x;p++){
		if(x%p==0) return false;
	}
	return true;
}
void solve(int tc){
	int a,b,c;
	cin >> a >> b >> c;
	a = a - c + 1;
	b = b - c + 1;
	lld k1 = 0,k2 = 0,k3 = 1;
	for(int p=0;p<c-1;p++) k3 *= 10;
	k1 = k3;
	k2 = k3;
	if(a==b){
		k1 *= v[a].x;
		k2 *= v[a].y;
	}else{
		k1 *= v[a].x;
		k2 *= v[b].x;
	}
	cout << k1 << " " <<k2 << "\n";
}


int main(void){
	lld st = 1;
	for(int e=1;e<10;e++){
		int a = -1,b = -1;
		for(lld p=st;p<st*10;p++){
			if(isprime(p)){
				if(a==-1) a = p;
				else if(b==-1){
					b = p;
					break;
				}
			}
		} 
		v[e] = mk(a,b);
		st *= 10;
	}
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