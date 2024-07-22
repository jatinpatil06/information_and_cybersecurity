#include<iostream>
using namespace std;

string encrypt(string plaintext, string encrypted, int shift)
{
    //Encryption logic
    for(int i = 0; i < plaintext.length(); i++)
    {
        if(plaintext[i] == ' ')
            encrypted += ' ';
        else
        {
            int letter_value = (plaintext[i] - 65);
            letter_value = ((letter_value + shift) % 26) + 65;
            encrypted += (char)letter_value;
        }
    }
    return encrypted;
}

string decrypt(string encrypted, string decrypted, int shift)
{
    //Decryption logic
    for(int i = 0; i < encrypted.length(); i++)
    {
        if(encrypted[i] == ' ')
            decrypted += ' ';
        else
        {
            int letter_value = (encrypted[i] - 65);
            letter_value = ((letter_value - shift + 26) % 26 + 65);
            decrypted += (char)letter_value;
        }
    }
    return decrypted;
}
int main()
{
    string plaintext;
    string encrypted;
    string decrypted;
    int shift;

    //Accepting the required values
    cout << "Enter the shift value : ";
    cin >> shift;
    cin.ignore();
    cout << "Enter the plaintext : ";
    getline(cin, plaintext);
    
    encrypted = encrypt(plaintext, encrypted, shift);
    decrypted = decrypt(encrypted, decrypted, shift);
    cout << "\nEncrypted message : " << encrypted;
    cout << "\nDecrypted message : " << decrypted;
    return 0;
}