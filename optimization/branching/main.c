#include <stdio.h>
#include <stdlib.h>
#include <linux/random.h>

/* in this function, we determine
 * how many of 0-9,10-19,20-29...90-99
 * are in a randomly generated array
 */
int *genArr(int len){
   FILE *urand = fopen("/dev/random","r");
   int *numbers = (int*)malloc(len*sizeof(int)); // each int is 4 bytes
   fgets((char*)numbers, len*4,urand);
   fclose(urand);
   return numbers;
}
int *count10(int *arr, int len){
   int *abacus = malloc(10*sizeof(int));
   for(int i = 0; i < 10; i++){
      abacus[i] = 0;
   }
   for(int i = 0; i < len; i++){
      switch((arr[i] % 100)/10){
         case 0:
            abacus[0] += 1;
            break;
         case 1:
            abacus[1] += 1;
            break;
         case 2:
            abacus[2] += 1;
            break;
         case 3:
            abacus[3] += 1;
            break;
         case 4:
            abacus[4] += 1;
            break;
         case 5:
            abacus[5] += 1;
            break;
         case 6:
            abacus[6] += 1;
            break;
         case 7:
            abacus[7] += 1;
            break;
         case 8:
            abacus[8] += 1;
            break;
         case 9:
            abacus[9] += 1;
            break;
      }
   }

   return abacus;
}
int main(){
   int len = 1000;
   int *arr = genArr(len);
   int *result = count10(arr,len);
   for(int i = 0; i < 100; i+=10){
      printf("[%d-%d]: %d\n", i,i+9, result[i/10]);
   }
   for(int i = 0; i < len; i++){
      printf("%d\n", arr[i]);
   }
   free(arr);
   free(result);
   return 0;
}
