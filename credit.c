#include <cs50.h>
#include <stdio.h>

int get_digits_sum(int digits);
int get_grades(long number);
int get_digit(long number, int pos);
bool is_valid(long number, int grades);

int main(void)
{
    long card_number = get_long("Card: ");
    int grades = get_grades(card_number);
    int first_digit = get_digit(card_number,1);
    int second_digit = get_digit(card_number,2);
    
    if(first_digit == 4 && (grades == 13 || grades == 16)) 
    {
        if(is_valid(card_number,grades))
        {
            printf("VISA\n");
        } 
        else
        {
            printf("INVALID\n");    
        }
    }
    else if(first_digit == 3 && grades == 15)
    {
        if(second_digit == 4 || second_digit == 7)
        {
            if(is_valid(card_number,grades)) 
            {
                printf("AMEX\n");
            } 
            else 
            {
                printf("INVALID\n");   
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if(first_digit == 5 && grades == 16)
    {
        if(second_digit == 1 || second_digit == 2 || second_digit == 3 || second_digit == 4 || second_digit == 5)
        {
            if(is_valid(card_number,grades))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int get_grades(long number)
{
   int grades = 0;
   while(number > 0)
   {
       number /= 10;
       grades += 1;
    }
    return grades;
}

int get_digit(long number, int pos)
{
    int digit;
    int grades = get_grades(number);
    for (int i = 0; i<grades-pos+1;i++)
    {
        digit = number % 10;
        number /= 10;
    }
    return digit;
}

bool is_valid(long number, int grades)
{
    int control_sum = 0;
    bool odd = false;
    
    while(number > 0)
    {
        int digit = number % 10;
        number /= 10;
        if(odd)
        {
            control_sum += get_digits_sum(digit*2);
            odd = false;
        }
        else
        {
            control_sum += digit;
            odd = true;
        }
    }
    if(control_sum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int get_digits_sum(int digits)
{
    int result = digits/10;
    result += digits % 10;
    return result;    
}
