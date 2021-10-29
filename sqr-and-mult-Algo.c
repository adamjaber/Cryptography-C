#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// finding x^e mod m using square and multiply algorithm
//

void reverse(int *arr, int n)
{
    int aux[n];

    for (int i = 0; i < n; i++)
    {
        aux[n - 1 - i] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = aux[i];
    }
}
int check(int *arr, int *arr2, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] != arr2[i])
            return 0;
    }
    return 1;
}
int Exponent(long long x, long long e, long long p)
{
    int arr[64];
    int i = 0;
    int exp = e;
    while (e > 0)               // number in binary array
    {
        arr[i] = e % 2;
        e = e / 2;
        i++;
    }
  
    int arr2[64];
    for (int j = 0; j < 64; j++)
    {
        arr2[j] = 0;
    }
    reverse(arr, i);            //reverse the array

    printf("%d in binary is: ",exp);
    int mul = x;
    int t = 1;
    arr2[0] = 1;
    exp /= 2;
    while (exp != 0)            // sqr and mult
    {
        x *= x;
        x = x % p;
        arr2[t] = 0;

        if (arr[t] != arr2[t])
        {
            x = x * mul;
            arr2[t] = 1;
            x = x % p;
        }
        t++;
        exp /= 2;
    }
    for (int j = 0; j < i; j++)
    {
        printf("%d", arr[j]);
    }
    printf("\n");

    return x;
}

int main(int argc, char const *argv[])
{

    int arr[64];
    printf("the answer is %d", Exponent(2, 79, 101));
}