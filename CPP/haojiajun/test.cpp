#include <iostream>

using namespace std;

void myitoa(__int128_t v, char* s)
{
    char temp;
    int i=0, j;

    while(v >0) {
        s[i++] = v % 10 + '0';
        v /= 10;
    }
    s[i] = '\0';

    j=0;
    i--;
    while(j < i) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        j++;
        i--;
    }
}

int main()
{
    __uint128_t n = 0;

    n = ~n;
    int count = 0;
    while(n > 0) {
        count++;
        n >>= 1;
    }

    cout << "count=" << count << endl;
    cout << "__uint128_t size=" << sizeof(__uint128_t) << endl;
    cout << endl;

    cout << "__int128_t size=" << sizeof(__int128_t) << endl;

    __int128_t x = 1100000000000000L;
    __int128_t y = 2200000000000000L;
    char s[40];

    x *= y;

    myitoa(x, s);

    cout << "x=" << s << endl;

    return 0;
}
