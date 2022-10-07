#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//#include <windows.h>
// Com a seed 0x633e0518
// plaintext 123456789
// temos a cifra 78 34 e2 3f 51 17 d4 38 aa 0
// 00 5f 3e 12 c0 bd 8d 16 
// f0 fd 75 99
// fa ef 39 9a
// 4b 96 21 a1
// 43 16 23 71
// 65 fb 27 4b

//Seed do desafio 5a 35 b1 62

int main(int argc, char **argv)
{
FILE * arquivo;
unsigned long semente;
 //unsigned char encrypt1[] = "123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
 unsigned char encrypt2[] = "HTB123456789abcdefghijklmnopqrstuvwxyzACDEFGIJKLMNOPQRSUVWXYZ";
 unsigned char possib[] = "HTB123456789abcdefghijklmnopqrstuvwxyzACDEFGIJKLMNOPQRSUVWXYZ";
 unsigned char plainText[28];
 //unsigned char cipher[] = {0x78, 0x34, 0xe2, 0x3f, 0x51, 0x17, 0xd4, 0x38, 0xaa, 0x0}; 
 unsigned char cipher[] = {0x00,0x5f,0x3e,0x12,0xc0,0xbd,0x8d,0x16,0xf0,0xfd,0x75,0x99,0xfa,0xef,0x39,0x9a,0x4b,0x96,0x21,0xa1,0x43,0x16,0x23,0x71,0x65,0xfb,0x27,0x4b};
 unsigned long int seed = 0x62b1355a;//62b1355a;//5a35b162; //0x633e0518;
 unsigned char rand1;
 unsigned char rand2; 
 unsigned char rand3;
 unsigned char result1;
 unsigned char result2;
 unsigned char result3;
 unsigned char result4;
 unsigned char *ptrRand1;
 unsigned char *ptrRand2; 
 unsigned char *ptrResult1;
 unsigned char *ptrResult2;
 ptrRand1 = &rand1;
 ptrRand2 = &rand2;
 ptrResult1 = &result1;
 ptrResult2 = &result2;
 printf("%lx\n",seed);
 srand(seed);
 //Utilizacao
 // cipher é a msg cifrada do arquivo .enc menos a seed
 // seed = semente que vem no arquivo .enc
 // encrypt1 é o vetor com os caracteres para comparacao
 // encrypt2 é o vetor que vai ser alterado e cifrado e deve iniciar com valor igual a encrypt1
 // plainText é onde será salvo os caracteres que coincidirem
 // possib é de onde será tirado os caracteres para preencher o PlainText
 
 // k loopa pela cifra
 for (int k = 0; k < 29 ; k++)
 {
 printf("Inicio rodada %d\n",k);
 rand1 = rand();
 rand2 = rand();
 rand3 = rand2;
 printf("\n");
	 for (int i = 0 ; i < 61 ; i++)
	 { 
		 for (unsigned char z = 0 ; z < 255 ; z++)
		 {
			 rand2 = rand3;
			 result1 = *(ptrRand1)^z;
			 *(encrypt2 + i) =  *ptrResult1; 			 
			 rand2 = rand2&7;		 						
			 result2 = 8 - *ptrRand2;				  
			 result3 = *ptrResult1 << *(ptrRand2);			 
			 result4 = *ptrResult1 >> result2;			 
			 result2 = result3 | result4;					
			 *(encrypt2 + i) = *ptrResult2;	
			 	 
			 if (cipher[k] == encrypt2[i])
			 {
				 plainText[k] = z;
			 } 
		 }
	}
	printf("Encrypt: %s\n",encrypt2);
}
printf("cipher: %s\n",cipher);
printf("plaintext: %s\n\n",plainText);

for (int i = 0 ; i < 28 ; i++)
{
	printf("%x ",cipher[i]);
}
  printf("\n");
for (int i = 0 ; i < 28 ; i++)
{
	printf("%x ",plainText[i]);
}
  printf("\n");
  //Codigo da Leitura da Seed no arquivo encriptado
  arquivo = fopen("flagoriginal.txt","rb");  
  fread(&semente,1,4,arquivo); 
  printf("semente %lx\n",semente);
  fclose(arquivo);

 
  return 0;
}

