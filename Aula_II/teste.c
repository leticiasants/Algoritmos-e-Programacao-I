#include <stdio.h>
#include <stdlib.h>

int *boba(){
    int n;
    scanf("%d", &n);
    int* b = (int*) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &(b[i]));
    }
    return b;
}

int main(void) {

    int n = 1000000;

    int* a = (int*) malloc(n * sizeof(int));
    for(int i = 0; i < 10; i++){
        a[i] = 0;
    }

    if(a == NULL) {
        printf("Deu erro na alocação\n");
        exit(-1);
    }
    for(int i = 0; i < 10; i++){
        printf("%d\n", a[i]);
    }

    

    return 0;
}
