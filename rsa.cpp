/*
Jatin Patil
1032221837
RSA Encryption/Decryption
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout << "\033[1;32mRSA Encryption/Decryption\033[1;0m" << endl;
    pair<int, int> primes;  //any random prime numbers
    cout << "Enter your primes (p,q) : ";
    cin >> primes.first >> primes.second;

    int n = primes.first * primes.second;  
    int phi_n = (primes.first - 1) * (primes.second - 1);
    cout << "phi_n is " << phi_n << endl;

    //now, we select e such that 1<e<phi_n
    int e;
    for(int i = 2; i < phi_n; i++)
    {
        if(gcd(phi_n, i) == 1)
        {
            e = i;
            cout << "e is " << e << endl;
            break;
        }
    }

    //now, we find k such that k<e and d should be a whole number
    int k;
    int d;
    for(int i = 0; i < e; i++)
    {
        d = (1 + i*(phi_n));
        if(d % e == 0)
        {
            k = i;
            d /= e;
            cout << "d is " << d << endl;
            break;
        }
    }

    //check that M < n after accepting
    int plaintext;  //ie. M, such that M<n
    cout << "Please enter the plaintext you want to transmit : ";
    cin >> plaintext;
    while(plaintext >= n)
    {
        cout << "Please enter the value of plaintext such that it is smaller : ";
        cin >> plaintext;
    }

    //now, performing encryption
    int ciphertext = int(pow(plaintext, e)) % n;
    //performing decryption
    int decrypted = int(pow(ciphertext, d)) % n;

    cout << "\033[1;31mCiphertext : \033[1;0m" << ciphertext << endl;
    cout << "\033[1;32mDecrypted text : \033[1;0m" << decrypted << endl;
    return 0;
}