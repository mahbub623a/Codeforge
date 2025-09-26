#include<bits/stdc++.h>
using namespace std;

// Find the power
int power(int a, unsigned long long b, int res = 1)
{
    for (; b != 0; b /= 2, a *= a)
        if (b & 1)
            res *= a;
    return res;
}

// Find the power Modulo
int power(int a, unsigned long long b, int mod,  int res = 1)
{
    a %= mod;
    for (; b != 0; b /= 2, a = (a * a) % mod)
        if (b & 1)
            res = (res * a) % mod;
    return res;
}

// Is power
bool isPower(int n, int x)
{
    if (x <= 1)
        return n == 1;
    double logResult = log(n) / log(x);
    return fabs(logResult - round(logResult)) < 1e-9;
}

// Sub string check
bool subString(string main, string sub)
{
    if (main.find(sub) != string::npos)
        return true;
    else
        return false;
}

// Digit sum
int digitSum(int k)
{
    int sum = 0;
    for (; k > 0; k /= 10)
        sum += k % 10;
    return sum;
}

// Find divisor of a number
vector<int> divisors(int n)
{
    vector<int> div;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (i != n / i)
                div.push_back(n / i);
        }
    }
    return div;
}

// Count the number of divisor
void divisorCount(int x) {
    vector<int> v(x + 1, 0);
    for (int i = 1; i <= x; i++) {
        for (int j = i; j <= x; j += i)
            v[j]++;
    }
    cout << v[x] << endl;
}

// Check prime or not
bool prime(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return n > 1;
}

// Find prime 1 to n
void sieve(int n)
{
    vector<bool> primes(n+1, true);
    primes[0] = primes[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (primes[i])
            for (int j = i * i; j <= n; j += i)
                primes[j] = false;
    }
}

// Find prime factor of a number
vector<int> primeFactor(int n)
{
    vector<int> prime;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            prime.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        prime.push_back(n);
    return prime;
}

// Binary Search
int binary(vector<int> v, int t) {
    int l = 0,
        r = v.size() - 1;

    while(l <= r) {
        int i = l + (r - l) / 2;
        if(t == v[i]) return i;
        else if(v[i] < t) l = i + 1;
        else r = i - 1;
    } 
    return -1;
}

// Find last index of target value
int binaryLast(vector<int> v, int t) {
    int l = 0,
        r = v.size() - 1;

    while(l < r) {
        int i = l + (r - l + 1) / 2; // ceil
        if(v[i] <= t) l = i;
        else r = i - 1;
    }
    return (v[l] == t ? l : -1);
}

// Find the first index of target value
int bianryFirst(vector<int> v, int t) {
    int l = 0,
        r = v.size() - 1;
    
    while(l < r) {
        int i = l + (r - l) / 2; // floor
        if(v[i] >= t) r = i;
        else l = i + 1;
    }
    return (v[l] == t ? l : -1);
}