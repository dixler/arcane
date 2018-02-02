#include <stdlib.h>
#include <stdio.h>
/*
 * In this program,  we illustrate means
 * of doing mass capitalization on strings
 */
char *init_naive(char letter, long len){
   char *str = (char *)malloc(len*sizeof(char));
   for(long i = 0; i < len; i++){
      str[i] = letter;
   }
   return str;
}

// TODO
char *init_speed(char letter, long len){
   char *str = (char *)malloc(len*sizeof(char));
   long *ptr = (long*)str;

   long rem = len % 8;   // we can handle 8 capitalizations at a time
   long rounds = len / 8;   // we can handle 8 capitalizations at a time

   long compressed = 0x0000000000000000;
   for(long i = 0; i < 8; i++){
      compressed <<= 8;
      compressed += letter;
   }

   for(long i = 0; i < rounds; i++){
      ptr[i] += compressed; // fast capitalization
   }
   // Cleanup
   if(rem > 0) ptr[rounds] += (compressed >> (8*(8-rem))); // fast capitalization

   return str;
}

void cap_naive(char *str, long len){
   for(long i = 0; i < len; i++){
      // TODO
      str[i] += ' '; // simple capitalization
   }
}
void cap_speed(char *str, long len){
   long *ptr = (long*)str;

   long rem = len % 8;   // we can handle 8 capitalizations at a time
   long rounds = len / 8;   // we can handle 8 capitalizations at a time

   for(long i = 0; i < rounds; i++){
      // TODO
      ptr[i] += 0x2020202020202020; // fast capitalization
   }
   // Cleanup
   if(rem > 0) ptr[rounds] += (0x2020202020202020 >> (8*(8-rem))); // fast capitalization
}
int main(){
   unsigned long len = 0xffffffff;
   char *str;

#ifdef naive
   //*
   str = init_naive('A', len);
   //printf("%s\n", str);
   cap_naive(str, len);
   //printf("%s\n", str);
   // */
#endif


#ifdef speed
   //*
   str = init_speed('B', len);
   //printf("%s\n", str);
   cap_speed(str, len);
   //printf("%s\n", str);
   // */
#endif
   return 0;
}
