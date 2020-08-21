// Demuestra el uso de funciones por referencia
#include <stdio.h>
#include <windows.h>
void swapr(int *x, int *y);
void swapv(int x, int y);
int main() {
 int x = 5, y = 10;
 printf("---------------------------------------------------\n");
 printf("Llamada por valor \n");
 printf("Main. Antes del swap; x: %d, y: %d \n",x,y);
 swapv(x,y);
 printf("Main. Despues del swap; x: %d, y: %d \n",x,y);
 printf("---------------------------------------------------\n");
 printf("Llamada por referencia \n");
 printf("Main. Antes del swap; x: %d, y: %d \n",x,y);
 swapr(&x,&y);
 printf("Main. Despues del swap; x: %d, y: %d \n",x,y);
 printf("---------------------------------------------------\n");
 system("pause");
 return 0;
}
void swapr(int *px, int *py) {
 int temp;
 printf("Swapr. Antes del swap; *px: %d, *py: %d\n",*px,*py);
 temp = *px;
 *px = *py;
 *py = temp;
 printf("Swapr. Despues del swap; *px: %d, *py: %d\n",*px,*py);
}
void swapv(int x, int y) {
 int temp;
 printf("Swapv. Antes del swap; x: %d, y: %d\n",x,y);
 temp = x;
 x = y;
 y = temp;
 printf("Swapv. Despues del swap; x: %d, y: %d\n",x,y);
}
