#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //prompt user
    long card = get_long("Card Number: ");
    
    //remainders
    long a = card % 10;
    long b = card % 100;
    long c = card % 1000;
    long d = card % 10000;
    long e = card % 100000;
    long f = card % 1000000;
    long g = card % 10000000;
    long h = card % 100000000;
    long i = card % 1000000000;
    long j = card % 10000000000;
    long k = card % 100000000000;
    long l = card % 1000000000000;
    long m = card % 10000000000000;
    long n = card % 100000000000000;
    long o = card % 1000000000000000;
    long p = card % 10000000000000000;
    
    //digit values
    b = ((b - a) / 10) * 2;
    c = ((c - b) / 100);
    d = ((d - c) / 1000) * 2;
    e = ((e - d) / 10000);
    f = ((f - e) / 100000) * 2;
    g = ((g - f) / 1000000);
    h = ((h - g) / 10000000) * 2;
    i = ((i - h) / 100000000);
    j = ((j - i) / 1000000000) * 2;
    k = ((k - j) / 10000000000);
    l = ((l - k) / 100000000000) * 2;
    m = ((m - l) / 1000000000000);
    n = ((n - m) / 10000000000000) * 2;
    o = ((o - n) / 100000000000000);
    p = ((p - o) / 1000000000000000) * 2;
    
    //after multiplying by 2, new digits
    int bb = b % 10;
    int bbb = (b - bb) / 10;
    int dd = d % 10;
    int ddd = (d - dd) / 10;
    int ff = f % 10;
    int fff = (f - ff) / 10;
    int hh = h % 10;
    int hhh = (h - hh) / 10;
    int jj = j % 10;
    int jjj = (j - jj) / 10;
    int ll = l % 10;
    int lll = (l - ll) / 10;
    int nn = n % 10;
    int nnn = (n - nn) / 10;
    int pp = p % 10;
    int ppp = (p - pp) / 10;
    
    //sum
    int z = a + bb + bbb + c + dd + ddd + e + ff + fff + g + hh + hhh + i + jj + jjj + k + ll + lll + m + nn + nnn + o + pp + ppp;
    
    //number of digits
    int count = 0;
    while (card > 0)
    {
        card = card / 10;
        ++count;
    }
    //amex
    if (z % 10 == 0 && o == 3 && count == 15 && (n / 2 == 4 || n / 2 == 7))
    {
        printf("AMEX\n");
    }
    //mastercard
    else if (z % 10 == 0 && p / 2 == 5 && (o > 0 && o < 6) && count == 16)
    {
        printf("MASTERCARD\n");
    }
    //visa
    else if (z % 10 == 0 && p / 2 == 4 && count == 16)
    {
        printf("VISA\n");
    }
    //visa
    else if (z % 10 == 0 && m == 4 && count == 13)
    {
        printf("VISA\n");
    }
    //invalid
    else
    {
        printf("INVALID\n");
    }
}