    #include<iostream>

    typedef long long int ll;

    using namespace std;

    void mult(ll m[2][2], ll m2[2][2], ll mod)
    {
        ll a = (m[0][0] * m2[0][0]) % mod + (m[0][1] * m2[1][0]) % mod;
        ll b = (m[0][0] * m2[0][1]) % mod + (m[0][1] * m2[1][1]) % mod;
        ll c = (m[1][0] * m2[0][0]) % mod + (m[1][1] * m2[1][0]) % mod;
        ll d = (m[1][0] * m2[0][1]) % mod + (m[1][1] * m2[1][1]) % mod;

        m[0][0] = a % mod;
        m[0][1] = b % mod;
        m[1][0] = c % mod;
        m[1][1] = d % mod;
    }

    int getBit_64(ll n, int shiftLeft)
    {
        ll mask = (ll)1 << shiftLeft;

        if((n & mask) != 0)
            return 1;

        return 0;
    }

    int msb_64(ll n)
    {
        for(int i = 63; i >= 0; i--)
        {
            if(getBit_64(n, i) == 1)
                return i;
        }

        return -1;
    }

    ll fibRapido(ll n, ll mod)
    {
        if(n == 0)
            return 0;

        int msbN = msb_64(n);

        ll resp[2][2] = {{1,0},{0,1}}; // matriz identidade
        ll fator[2][2] = {{1,1},{1,0}};

        for(int i = 0; i <= msbN; i++)
        {
            if(getBit_64(n, i) == 1)
            {
                mult(resp, fator, mod);
            }

            mult(fator, fator, mod);
        }

        return resp[0][1];
    }

    ll pisano(ll m)
    {
        ll a = 0, b = 1, c = a + b;

        for (int i = 0; i < m * m; i++)
        {
            c = (a + b) % m;
            a = b;
            b = c;
            if (a == 0 && b == 1)
                return i + 1;
        }
    }

    int main()
    {
        ll n, m, k, p, aux;

        while(cin >> n >> m)
        {
            k = pisano(m);
            p = pisano(k);

            aux = fibRapido(n % p, k);
            aux = fibRapido(aux, m);

            cout << aux << endl;
        }

        return 0;
    }
