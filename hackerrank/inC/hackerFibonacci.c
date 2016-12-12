#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long long list[50];

int handle() {
    long long N;
    scanf ("%lld ", &N);
    int i;
    for (i = 0; i < 50; i++) {
        if (list[i] == N) {
            return 1;
        }
    }
    return 0;
}

int main() {   
    int N;
    scanf ("%d ", &N);
    int i;
    list[0] = 1ll;
    list[1] = 1ll;
    for (i = 2; i < 50; i++) {
        list[i] = list[i - 1] + list[i - 2];
    }
    for (i = 0; i < N; i++) {
        if (handle()) {
            printf ("IsFibo\n");
        } else {
            printf ("IsNotFibo\n");
        }
    }
    return 0;
}
