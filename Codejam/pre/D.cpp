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

int ask(int x1,int x2,int x3){
	cout << x1 << " " << x2 << " " << x3 << endl;
	int k;
	cin >> k;
	return k;
}
vector<int> add(vector<int> v,int x,int k){
	vector<int> v1;
	for(int p=0;p<x;p++) v1.push_back(v[p]);
	v1.push_back(k);
	for(int p=x;p<sz(v);p++) v1.push_back(v[p]);
	return v1;
}
void answer(vector<int> v){
	for(int e=0;e<sz(v);e++) cout << v[e] << " ";
	cout << endl;
	int k;
	cin >> k;
	if(k==-1) exit(0);
}
void solve(int tc){
	int t,n,q;
	cin >> t >> n >> q;
	vector<int> v;
	while(t--){
		v.clear();
		int now = ask(1,2,3);
		if(now==1){
			v.push_back(2);
			v.push_back(1);
			v.push_back(3);
		}else if(now==2){
			v.push_back(1);
			v.push_back(2);
			v.push_back(3);
		}else if(now==3){
			v.push_back(1);
			v.push_back(3);
			v.push_back(2);
		}
		for(int p=4;p<=n;p++){
			int ll = 0,rr = (sz(v)/2) - 1,mid;
			bool suc = false;
			while(ll<=rr){
				mid = (ll+rr)/2;
				int rmid = mid * 2;
				int now = ask(v[rmid],v[rmid+1],p);
				if(now==p){
					v = add(v,rmid+1,p);
					suc = true;
					break;
				}else if(now==v[rmid+1]){
					ll = mid + 1;
				}else{
					if(rmid==0){
						v = add(v,0,p);
						suc = true;
						break;
					}
					rr = mid - 1;
				}
			}
			if(!suc){
				int rnow = ll * 2;
				if(sz(v)%2==0){
					if(rnow==sz(v)){
						v.push_back(p);
						continue;
					}
				}
				int now = ask(v[rnow],v[rnow-1],p);
				if(now==p){
					v = add(v,rnow,p);
				}else if(now==v[rnow]){
					v.push_back(p);
				}
			}
		}
		answer(v);

	}
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}