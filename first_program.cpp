#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll ;
typedef long double ld ;
typedef long long int lli;

using namespace std;

ll mult(ll a,ll b, ll p=mod){return ((a%p)*(b%p))%p;}
ll add(ll a, ll b, ll p=mod){return (a%p + b%p)%p;}
ll sub(ll a, ll b, ll p=mod){return (a%p - b%p + p)%p;}
ll fpow(ll n, ll k, ll p = mod) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n%p; n = n * n%p;} return r;}
ll inv(ll a, ll p = mod) {return fpow(a, p - 2, p);}

int main()
{
	//ios
	int t=1;
	//cin>>t;
	//t=1;
	while(t--)
	{
		// n k q
		// n numbers
		ll n,k,q;
		cin>>n>>k>>q;
		ll a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		multiset<ll>s;
		vector<ll>v;
		int i=n-1;
		for(int j=0;j<k;j++,i--)
		{
			s.insert(a[i]);
		}
		/*for(i=n-1;i>=0&&(n-i)<=k;i--)
		{
			s.insert(a[i]);
		}*/
		i++;
		for(int j=0;j<n-k;j++)
		{
			v.pb(a[j]);
		}
		int j=n-k;
		while(q--&&j>0)
		{
			j--;
			ll largest=a[j];

			//v.pop_back();
			ll smallest=*s.begin();
			s.erase(s.begin());
			s.insert(smallest+largest);
		}
		ll prod=(*s.begin())%mod;
		multiset<ll>::iterator it=s.begin();
		it++;
		for(;it!=s.end();it++)
			prod=mult(prod,*it);
		cout<<prod<<'\n';


	}


}
