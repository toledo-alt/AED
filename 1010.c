#include <stdio.h>

int main(){
    int a, b;
    float c, it1, it2;
    scanf("%d %d %f", &a, &b, &c);
    it1 = b * c;
    scanf("%d %d %f", &a, &b, &c);
    it2 = b * c;
    printf("VALOR A PAGAR: R$ %.2f\n", it1+it2);
    return 0;
}
