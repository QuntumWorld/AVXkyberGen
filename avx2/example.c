#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "kem.h"
#include "randombytes.h"
#include <time.h>

int main(void)
{
  uint8_t pk[CRYPTO_PUBLICKEYBYTES];
  uint8_t sk[CRYPTO_SECRETKEYBYTES];
  uint8_t ct[CRYPTO_CIPHERTEXTBYTES];
  uint8_t key_a[CRYPTO_BYTES];
  uint8_t key_b[CRYPTO_BYTES];


  clock_t t;
  t = clock();
   //Alice generates a public key
  crypto_kem_keypair(pk, sk);
  t = clock() - t;
  double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
   printf("%f@@", time_taken * 1000);


  //Bob derives a secret key and creates a response
  crypto_kem_enc(ct, key_b, pk);

  //Alice uses Bobs response to get her shared key
  crypto_kem_dec(key_a, ct, sk);
  size_t i;
   for (i = 0; i < KYBER_PUBLICKEYBYTES; i++)
  {
    printf("%02hhx", pk[i]);
  }
  printf("@@");
  for (i = 0; i < KYBER_SECRETKEYBYTES; i++)
  {
    printf("%02hhx", sk[i]);
  }

/*
 
  
  printf("\n");
 
  printf("@@");
  for (i = 0; i < KYBER_SSBYTES; i++)
  {
    printf("%02hhx", key_a[i]);
  }
  printf("\n");
  printf("@@");
  for (i = 0; i < KYBER_SSBYTES; i++)
  {
    printf("%02hhx", key_b[i]);
  }
  printf("\n");
*/
  return 0;
}