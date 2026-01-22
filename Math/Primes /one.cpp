// This is the code for Sieve of Erastothenes

#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll is_prime[1000001];
void sieve()
{
    ll n = 1e6;
    for (ll i = 0; i <= n; i++)
    {
        is_prime[i] = 1;
    }
    // sieve
    is_prime[0] = 0, is_prime[1] = 0;
    for (ll i = 2; i * i <= n; i++)
    {
        if (is_prime[i])
        {
            for (ll j = i * i; j <= n; j += i)
            {
                is_prime[j] = 0;
            }
        }
    }
}
int main()
{
    // finding primes in a range ;
    ll l, r;
    cin >> l >> r;
    sieve();
    cout << "Primes upto n are :" << "\n";
    for (ll i = l; i <= r; i++)
    {
        if (is_prime[i])
            cout << i << " ";
    }
    cout << "\n";
    return 0;
}