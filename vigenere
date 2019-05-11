#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char cipher_char(char plain_char, int key);
int get_shift(char char_key);

int main(int argc, string argv[])
{
    string key;
    if (argc == 2)
    {
        for(int i=0;i<strlen(argv[1]);i++)
        {
            if(!isalpha(argv[1][i]))
            {
                printf("Usage: ./vigenere keyword\n");
                return 1;
            }
        key = argv[1];
        }
    }
    else
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
  
    string text = get_string("plaintext: ");
    printf("ciphertext: ");
    int j = 0;
    for(int i=0;i<strlen(text);i++)
    {
        int int_key = get_shift(key[j]);
        char ciphered_char = cipher_char(text[i],int_key);
        if (isalpha(text[i])) j++;
        printf("%c", ciphered_char);
        if(j==strlen(key)) j = 0;
    }
    printf("\n");
}

char cipher_char(char plain_char, int key)
{
    if (!isalpha(plain_char)) return plain_char;
    
    int plain_ascii = plain_char;
    int cipher_ascii = plain_ascii + key;    
    if (islower(plain_char) && cipher_ascii > 122)
    {
        cipher_ascii = cipher_ascii - 26;
    }
    if (isupper(plain_char) && cipher_ascii > 90)
    {
        cipher_ascii = cipher_ascii - 26;
    }
    
    return cipher_ascii;
}

int get_shift(char char_key)
{
    int int_key = char_key;
    if (islower(char_key))
    {
        int_key = int_key - 97;
    }
    if (isupper(char_key))
    {
        int_key = int_key - 65;
    }
    return int_key;
}
