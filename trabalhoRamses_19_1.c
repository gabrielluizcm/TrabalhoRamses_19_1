#include <stdio.h>
/*Os resultados gerados por esse programa não são exatos
visto a impossibilidade de verificar carry em somas na
linguagem C*/

//variáveis globais -> não fazer isso nunca mais
unsigned char registradorA = 0, registradorB = 0,resultadoMSB = 0, resultadoLSB = 0, carry = 0, i = 0;
unsigned char vetor[55];

void rotateRightx4()
{
  while(registradorB < 4)
  {
    carry = registradorA % 2;
    registradorA = registradorA / 2;
    if (carry)
      registradorA += 128;
    registradorB++;
  }
}

void inverteLSB()
{
  registradorB = 0;
  registradorA = vetor[i];
  rotateRightx4();
  registradorA += resultadoMSB;
  resultadoMSB = registradorA;
  printf("\nLSB parcial: %d", resultadoMSB);
  i++;
}

void inverteMSB()
{
  registradorB = 0;
  registradorA = vetor[i];
  rotateRightx4();
  registradorA += resultadoLSB;
  resultadoLSB = registradorA;
  i++;
  inverteLSB();
}

void inverteResultado()
{
  registradorB = 0;
  registradorA = resultadoMSB;
  rotateRightx4();
  registradorB = registradorA;
  registradorA = resultadoLSB;
  resultadoLSB = registradorB;
  registradorB = 0;
  rotateRightx4();
  resultadoMSB = registradorA;
}

int main(void) {

  vetor[0] = 16;
  vetor[1] = 32;
  vetor[2] = 48;
  vetor[3] = 64;
  vetor[4] = 80;
  vetor[5] = 96;
  vetor[6] = 0;
  vetor[7] = 0;
  /*vetor[8] = 5;
  vetor[9] = 0;
  vetor[10] = 6;
  vetor[11] = 0;
  vetor[12] = 7;
  vetor[13] = 0;
  vetor[14] = 8;
  vetor[15] = 0;
  vetor[16] = 0;
  vetor[17] = 0;*/

  while ((vetor[i] || vetor[i+1]) != 0)
  {
    inverteMSB();
  }
  inverteResultado();

  printf("\nResultado MSB: %d\nResultado LSB: %d", resultadoMSB, resultadoLSB);

  return 0;
}
