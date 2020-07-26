#include <unistd.h>
#include <stdlib.h>

main() {
  char *obrk;
  char *nbrk;
  char *naddr;

  obrk = sbrk(0);
  printf("CURRENT BREAK_ADDRES= 0x%x\n", obrk);
  naddr = malloc(64); // ВЫДЕЛИМ 64 байт из кучи
  printf("malloc(64)\n");
  nbrk = sbrk(0); // NEW BREAK ADDRESS
  printf("New address areas malloc= 0x%x, break address= 0x%x (INCREASE ON %d bytes)\n", naddr, nbrk, nbrk - obrk);
  free(naddr);
  printf("free(0x%x)\n", naddr);
  obrk = sbrk(0);
  printf("NEW BREAK_ADDRESS= 0x%x (INCREASE ON %d bytes)\n", obrk, obrk - nbrk);
}
