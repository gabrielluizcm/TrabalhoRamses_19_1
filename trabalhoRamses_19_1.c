#include <stdio.h>

//variáveis globais -> não fazer isso nunca mais
//resultado16b vai armazenar o resultado durante o programa para não perder informação do carry
//na etapa final, resultado16b vai ser dividido em duas variáveis de 8 bits
unsigned char registradorA = 0, registradorB = 0,resultadoMSB = 0, resultadoLSB = 0, carry = 0, i = 0;
unsigned short resultado16b = 0;
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
  resultado16b += (registradorA * 256);
  i++;
}

void inverteMSB()
{
  registradorB = 0;
  registradorA = vetor[i];
  rotateRightx4();
  resultado16b += registradorA;
  i++;
  inverteLSB();
}

void inverteResultado()
{
  registradorB = 0;
  resultadoMSB = ((resultado16b & 0xFF00) / 256);
  resultadoLSB = (resultado16b & 0x00FF);
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

  //valores do vetor precisam ser inseridos manualmente, como no Ramses
  vetor[0] = 1;
  vetor[1] = 2;
  vetor[2] = 5;
  vetor[3] = 26;
  vetor[4] = 43;
  vetor[5] = 60;
  vetor[6] = 77;
  vetor[7] = 94;
  vetor[8] = 0;
  vetor[9] = 0;

  while ((vetor[i] || vetor[i+1]) != 0)
  {
    inverteMSB();
  }
  inverteResultado();

  printf("\nResultado MSB: %d\nResultado LSB: %d", resultadoMSB, resultadoLSB);

  return 0;
}
