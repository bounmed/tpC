#include <stdio.h>
#include <stdlib.h>
/*
Fonction recursive qui calcule 2 puissance n
*/
int rec1(int n) {
    if (n == 0)
        return 1;
    else
        return 2*rec1(n-1);

}
/*
Fonction recursive qui calcule 2 puissance n
*/
int rec2(int n) {
    if (n == 0)
        return 1;
    else
        return rec2(n-1) + rec2(n-1);
}



int main () {
    printf("%d puissance %d est égal à %d avec la fonction rec1\n", 2, 3, rec1(3));
    printf("%d puissance %d est égal à %d avec la fonction rec2\n", 2, 3, rec1(3));
    printf("%d puissance %d est égal à %d avec la fonction rec1\n", 2, 5, rec1(5));
    printf("%d puissance %d est égal à %d avec la fonction rec2\n", 2, 5, rec1(5));
}
