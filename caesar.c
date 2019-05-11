#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char cipher_char(char plain_char, int key);

int main(int argc, string argv[])
{
    int key = 0;
    if (argc == 2)
    {
        for(int i=0;i<strlen(argv[1]);i++)
        {
            if(!isdigit(argv[1][i]))
            {
                printf("%c",argv[1][i]);
                printf("Usage: ./caesar key\n");
                return 1;
            }
        key = atoi(argv[1]) % 26;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
  
    string text = get_string("plaintext: ");
    printf("ciphertext: ");
    for(int i=0;i<strlen(text);i++)
    {
        printf("%c", cipher_char(text[i],key));
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
