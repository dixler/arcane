#include <stdlib.h>
#include <string.h>
#include <stdio.h>
union Data {
   long lval;
   char cval;
};
// TODO
// sourced from ../alignment
char *init_speed(char letter, long len){
   len = len - len % 8;   // we can handle 8 capitalizations at a time
   long rem = len % 8;   // we can handle 8 capitalizations at a time
   long rounds = len / 8;   // we can handle 8 capitalizations at a time
   char *str = (char *)malloc(len*sizeof(char));
   long *ptr = (long*)str;

   long compressed = 0x0000000000000000;
   for(long i = 0; i < 8; i++){
      compressed <<= 8;
      compressed += letter;
   }

   for(long i = 0; i < rounds; i++){
      ptr[i] += compressed; // fast capitalization
   }
   // Cleanup
   compressed = 0x0000000000000000;
   if(rem > 0) ptr[rounds] += (compressed >> (8*(8-rem))); // fast capitalization

   return str;
}

int _strcmp(char *a, char *b){
   long *ptr1 = (long*)a;
   long *ptr2 = (long*)b;
   union Data valA;
   union Data valB;
   valA.lval = *ptr1;
   valB.lval = *ptr2;

   for(; valA.lval == valB.lval; ++ptr1, ++ptr2){
      if(valA.cval == 0)
         return 0;
      valA.lval = *ptr1;
      valB.lval = *ptr2;
   }
   //return *(unsigned char *)ptr1 < *(unsigned char *)ptr2 ? -1 : 1;
   return valA.cval < valB.cval ? -1 : 1;
}

int main(){
   long len = 2000000000;
   char *str1 = init_speed('A', len);
   char *str2 = init_speed('A', len);

   printf("comparing:\n");
   printf("%d\n", strcmp(str1, str2));
   printf("%d\n", _strcmp(str1, str2));
   return 0;
}
