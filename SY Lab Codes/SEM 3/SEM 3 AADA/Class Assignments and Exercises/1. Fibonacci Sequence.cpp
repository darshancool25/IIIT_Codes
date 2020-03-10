//Program to find nth term of fibonacci using matrix exponentiation
#include<bits/stdc++.h>
#define boost ios::sync_with_stdio(false); cin.tie(0)
#define ll      long long int
#define mk      make_pair
#define pb      push_back
#define f     first
#define s     second
#define fo(i,a,b)     for(i=a;i<b;i++)
#define foe(i,a,b)    for(i=a;i<=b;i++)
#define MOD     1000000007

using namespace std;

void Multiply(ll A[2][2], ll B[2][2])
{
    ll mul[2][2], i, j, k;
    //mul[][] is the auxiliary array that stores the result of multiplication
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            mul[i][j] = 0;
            for (k = 0; k < 2; k++)
                mul[i][j] += A[i][k] * B[k][j];
        }
    }
    // storing the multiplication result in A[][]
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            A[i][j] = mul[i][j];  // Updating our matrix
}

void FastPow(ll F[2][2], ll n)
{
    if (n == 0 || n == 1)
        return;
    ll M[2][2] = {{1, 1}, {1, 0}};

    FastPow(F, n / 2);
    Multiply(F, F);

    if (n % 2 != 0)
        Multiply(F, M);
}

ll FiboM(ll n)
{
    ll A[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    FastPow(A, n - 1);
    return A[0][0];
}

ll RecFibo(ll n)
{
    if (n <= 1)
        return n;

    else
        return RecFibo(n - 1) + RecFibo(n - 2);
}
ll FiboDP(ll n)
{
    ll i, arr[n + 1];
    arr[1] = 1;
    arr[2] = 1;
    foe(i, 3, n)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];

}

int main()
{
    // boost;
    ll i, n;
    cout << "Enter value on n : ";
    cin >> n;
    cout << "Matrix Exponentiation [nth Fibo term] : " << FiboM(n) << '\n';
    cout << "Recursive Function [nth Fibo term] : " << RecFibo(n) << '\n';
    cout << "DP array [nth Fibo Term] : " << FiboDP(n) << '\n';
    // foe(i,1,n)
    // cout << fibo(i) << '\n';
}