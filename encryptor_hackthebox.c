#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//#include <windows.h>

int main(int argc, char **argv)
{
 unsigned char encrypt[] = "123456789";
 unsigned long int seed = 0x633e0518;
 unsigned char rand1;
 unsigned char result1;
 unsigned char result2;
 unsigned char result3;
 unsigned char result4;
 unsigned char *ptrRand1;
 unsigned char *ptrResult1;
 unsigned char *ptrResult2;
 ptrRand1 = &rand1;
 ptrResult1 = &result1;
 ptrResult2 = &result2;
 printf("%lx\n",seed);
 srand(seed);
 for (int i = 0 ; i < 9 ; i++)
 {
		 rand1 = rand();//first rand--------------
		 printf("Rand 1 Byte %x\n",*(ptrRand1));
		 printf("Encrypt Char %x\n",*(encrypt + i)); 
		 result1 = *(ptrRand1)^*(encrypt + i); //XOR Rand and Char
		 printf("Encrypt Char first update %x\n", *ptrResult1);
		 *(encrypt + i) =  *ptrResult1; // update char
		 
		 
		 rand1 = rand(); //call rand----------
		 printf("Rand 2 %x\n",rand1);
		 rand1 = rand1&7;		 
		 printf("Rand 2 after AND %x\n",*(ptrRand1));
		 	
		 result2 = 8 - *ptrRand1;		
		  
		 result3 = *ptrResult1 << *(ptrRand1);
		 
		 result4 = *ptrResult1 >> result2;
		 
		 result2 = result3 | result4;
		 
		 
		 printf("%x\n",result2);			
		 *(encrypt + i) = *ptrResult2;
		 //memset((encrypt+i), *ptrResult2, 1);
		 printf("%x %x\n",*ptrResult2, *(encrypt + i) );		
		 printf("%s\n\n\n",encrypt);	 
		 // DECRYPT
		 
}

for (int i = 0 ; i < 10 ; i++)
{
	printf("%x ",encrypt[i]);
}
  /*
  Codigo da Leitura da Seed no arquivo encriptado
  arquivo = fopen("flag.enc","rb");  
  fread(&semente,1,4,arquivo); 
  printf("semente %x\n",semente);
  fclose(arquivo);
*/

 
  return 0;
}

