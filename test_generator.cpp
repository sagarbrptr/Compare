#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll ;
typedef long double ld ;
typedef long long int lli;

using namespace std;
//reference: geeks
ll mult(ll a,ll b, ll p=mod){
	ll res = 0;
    a %= p;
    while (b)
    {
        if (b & 1)
            res = (res + a) % p;
    		a = (2 * a) % p;
        b >>= 1;
    }
    return res;
}
ll add(ll a, ll b, ll p=mod){return (a%p + b%p)%p;}
ll sub(ll a, ll b, ll p=mod){return (a%p - b%p + p)%p;}
ll fpow(ll n, ll k, ll p = mod) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = mult(r,n,p); n = mult(n,n,p);} return r;}
ll inv(ll a, ll p = mod) {return fpow(a, p - 2, p);}

ll getRandoms(ll lower, ll upper)
{
    //between lower and upper inclusive
    ll num = (rand() %
           (upper - lower + 1)) + lower;
return num;
}
int main()
{
	srand(time(0));
	/*cout<<3<<"\n";
	cout<<5<<" "<<1<<" "<<5<<"\n";
	cout<<0<<" "<<0<<" "<<0<<" "<<0<<" "<<0<<" \n";
	cout<<2<<" "<<1<<" "<<0<<"\n";
	cout<<10000<<" "<<1000<<" \n";
	cout<<1<<" "<<1<<" "<<2<<"\n";
	cout<<111<<" \n";*/
	int t=1;
	//cout<<t<<"\n";

	while(t--)
	{
		//ll sum=0;
		ll n=getRandoms(1,5);
		//n=10000;
		cout<<n<<" "<<getRandoms(1,n)<<" "<<getRandoms(0,100000)<<"\n";
		for(int i=0;i<n;i++)
			cout<<getRandoms(0,10000)<<" ";
		cout<<"\n";
	}


}
