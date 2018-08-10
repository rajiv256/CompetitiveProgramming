#include <stdio.h>
 
int fastInput() {
    int val = 0;
    char c = getchar_unlocked();
    while (c<33) c = getchar_unlocked();
    while (c>33) val = (val<<1) + (val<<3) + (c-'0'), c = getchar_unlocked();
    return val;
}
 
int main(void) {
    int t, n;
    t = fastInput();
    while (t--) {
        n = fastInput();
        if (n%5 != 0) printf("%d\n", n);
        else {
            int temp = n, count = 0;
            while (temp%10 == 0) temp /= 10;
            while (temp%5 == 0) {
                temp /= 5;
                count++;
            }
            count = (count+1) >> 1;
            count <<= 1;
            printf("%lld\n", (long long int) n * (1 << count));
        }
    }
    return 0;
} 
