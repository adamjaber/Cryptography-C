// given two number find GCD and LCM of two integers
// given x= a mod p
// and   x= b mad q  
// find x using inverse and GCD

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void GCD (int a, int b , int* gcd , int* m, int*n)
{

    if(b>a)
    {
        int tmp=a;
        a=b;
        b=tmp;
    }
    if(b==0)
    {
        *m=1;
        *n=0;
        *gcd=a;
        return;
    }

        GCD(b,a%b,gcd,m,n);
        int tmpm=*m;
        int tmpn=*n;
        *m=tmpn;
        *n=tmpm-tmpn*(a/b);
    
}
int inverse(long long a, long long p)  // use inverse to find m
{
int gcd1,m,n;
GCD(a,p,&gcd1,&m,&n);
if(m<0)
    m=m+p;
return m;
}
int Solve_System(int a,int p,int b,int q)
{
    return ((a*p*inverse(a,p)+b*q*inverse(b,q))%(q*p));
    

}
int main(int argc, char const *argv[])
{
    long long a=9;
    long long p=7;
    int b=4;
    int q=1;

    printf("x = %d\n",Solve_System(a,p,b, q));

    


    return 0;
}
