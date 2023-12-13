

#include <bits/stdc++.h>

#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define fi first
#define se second
#define INF    0x3f3f3f3f
#define NEGINF 0xC0C0C0C0
#define LINF   0x3f3f3f3f3f3f3f3fLL
#define EPS 1e-10
#define PI 2 * acos(0)
#define NULO -1
#define endl '\n'
using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;



const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

int cmp(double x, double y = 0, double tol = EPS){ return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1; }

map<string, int> mapa;
int idx;

int insere(string s){
	if(mapa.find(s)!=mapa.end())return mapa[s];
	return mapa[s]=idx++;
}

int main(){
	string o,d,a,b,c;
	int n,origem, destino;
	while(scanf("%d ",&n) and n){
		vector< vector<pair<int,string> > > adj(n*2+10,vector<pair<int, string> >());
		idx=0;
		cin>>o>>d;
		mapa.clear();
		origem=insere(o);
		destino=insere(d);
		rep(i,0,n){
			cin>>a>>b>>c;
			adj[insere(a)].pb(mp(insere(b),c));
			adj[insere(b)].pb(mp(insere(a),c));
			//cout<<a<<b<<" ";
			//printf("%d %d\n",insere(b),insere(a));
		}

		int dist[4005][26];
		rep(i,0,4005)
			rep(j,0,26)
				dist[i][j]=1<<30;
		//memset(dist,1<<30,sizeof dist);
		rep(i,0,26)
			dist[origem][i]=0;	
		pq<pair<int,char>,vector<pair<int,char> >, greater<pair<int,char> > > q;
		q.push(mp(origem,o[0]));
		while(!q.empty()){
			pair<int,char> front=q.top(); q.pop();
			int v = front.fi;
			char cx = front.se;
			rep(i,0,adj[v].size()){
				pair<int,string> aux = adj[v][i];
				int u = aux.fi;
				char c = aux.se[0];
				if(c == cx) continue;
				if(dist[u][c-'a']>=dist[v][cx-'a']+aux.se.size()){
					//printf("%d\n",u);
					dist[u][c-'a']=dist[v][cx-'a']+aux.se.size();
					q.push(mp(u,c));
				}
			}
		}
		int ans=1<<30;
		rep(i,0,26)
			ans=min(ans,dist[destino][i]);
		if(ans==1<<30)printf("\timpossivel\n");
		else printf("%d\n",ans);	
	}
		


return 0;
}
