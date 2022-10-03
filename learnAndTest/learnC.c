#define LOCAL
#include <stdio.h>
#include <math.h>

int main(){

    #ifdef LOCAL
    printf("use freopen to redirect here\n");
    #endif

    const double pi = acos(-1.0);
    printf("%lf\n",pi);

    int a[5];
    printf("%d\n",sizeof(a[1]));
    return 0;
}