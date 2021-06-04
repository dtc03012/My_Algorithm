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
void solve(int tc){
	 int n;
	cin >> n;
	vector<pair<string,int> > v;
	int k;
	cin >> k;
	cout << "1\n";
	v.push_back(mk("1",1));
	for(int e=1;e<n;e++){
		int k;
		cin >> k;
		string newv = "";
		int lastv = 0;
		for(int p=sz(v)-1;p>=0;p--){
			if(k==1){
				newv = v[p].x + ".1";
				break;
			}else{
				bool suc = false;
				if(v[p].y==k-1){
					int lastx = -1;
					for(int q=sz(v[p].x)-1;q>=0;q--){
						if(v[p].x[q]=='.'){
							lastx = q;
							break;
						}
					}
					for(int q=0;q<=lastx;q++) newv += v[p].x[q];
					string vv = "";
					int tmp = k;
					while(tmp){
						vv += char((tmp%10)+'0');
						tmp /= 10;
					}
					reverse(all(vv));
					newv += vv;
					suc = true;
					lastv++;
					break;
				}else lastv++;
			}
		}
		for(int p=0;p<lastv;p++) v.pop_back();
		v.push_back(mk(newv,k));
		cout << newv << "\n";
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