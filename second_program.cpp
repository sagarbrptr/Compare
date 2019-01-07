#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define hell 1000000007
#define hell1 1000000006
#define pb push_back
#define x first
#define y second
#define all(v) v.begin(),v.end()
#define MAXL 1000005
using namespace std;
vector<ll>adj[400005],visited(400005,0),prime(MAXL,0);
vector<string>dict;
ll mM(ll a,ll b,ll mod){ll res = 0;a %= mod;while(b){if (b & 1)res = (res + a) % mod;a = (2 * a) % mod;b >>= 1;}return res;}
ll fpow(ll x,ll y,ll p){x=x%p;ll res=1;while(y){if(y&1)res=mM(res,x,p);res%=p;if(res<0)res=(res+p)%p;y=y>>1;x=mM(x,x,p);if(x<0)x=(x+p)%p;x%=p;}return res;}
ll inv(ll n){return fpow(n,hell-2,hell);}
ll modmul(ll x,ll y){return mM(x,y,hell);}
ll modadd(ll x,ll y){ll temp=x%hell+y%hell;temp%=hell;if(temp<0)temp = (temp+hell)%hell;return temp;}
void dfs(ll src)
{
	visited[src] = 1;
	for(auto e:adj[src])
		if(!visited[e])
			dfs(e);
}
void sieve(){
	prime[1] = 1;
	for(int i=2;i<MAXL;i++)
		if(prime[i]==0)
			for(int j=i;j<MAXL;j+=i)
				prime[j] = i;
}
void gcd(ll a,ll b)
{
	if(a==0)
		return;
	gcd(b%a,a);
}
void permute(string s,int l,int r)
{
	int i;
	if(l==r)
		dict.pb(s);
	else
	{
		for(int i=l;i<=r;i++)
		{
			swap(s[l],s[i]);
			permute(s,l+1,r);
			swap(s[l],s[i]);
		}
	}
}
int main(){
	ios
	ll t=1;
	//cin >> t;
	//t = 1;
	//sieve();
	while(t--){
		ll n,k,q;
		cin >> n >> k >> q;
		vector<ll>a(n);
		for(int i=0;i<n;i++)
			cin >> a[i];
		sort(a.begin(),a.end());
		ll mn = min(n-k,q);
		priority_queue<ll>pq;
		for(int i=0;i<n;i++)
			pq.push(a[i]);
		if(n==1)
		{
			cout << a[0] << "\n";
		}
		else if(n==2)
		{
			if(k==2)
				cout << modmul(a[1],a[0]) << "\n";
			else if(q==0 && k==1)
				cout << a[1] << "\n";
			else if(k==1)
				cout << a[0]*a[1] << "\n";
		}
		else
		{
			while(mn--)
			{
				ll temp1 = pq.top();
				pq.pop();
				ll temp2 = pq.top();
				pq.pop();
				ll temp3 = pq.top();
				pq.pop();
				ll temp4 = temp2 + temp3;
				pq.push(temp4);
				pq.push(temp1);
				//cout << temp1 << " " << temp2 << " " << temp3 << "\n";
			}
			ll ans = 1;
			vector<ll>v;
			while(!pq.empty())
			{
				ll temp1 = pq.top();
				pq.pop();
				v.pb(temp1);
			}
			//for(int i=0;i<n;i++)
				//	cout << v[i] << " ";
			//cout << "\n";
			for(int i=0;i<k;i++)
				ans = modmul(ans,v[i]);
			cout << ans << "\n";
		}
	}
}
