/*
#include <stdio.h>

int main() {
  FILE *inputFile;
  inputFile = fopen("input.txt","r");

  if (inputFile == NULL) {
    fprintf(stderr, "An error occurred, check if the input file exists.\n");

    return 0;
  }

  fprintf(stdout, "Works fine. ;)\n");
  fclose(inputFile);

  return 0;
}
*/

/*
OBJETIVO:

função para ler arquivo que retorna um pointeiro para o conteúdo da memória.
função para grava um arquivo que recebe como parâmetro o ponteito criado pela função de leitura.
*/

/* fread example: read an entire file */
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;
  long lSize;
  char *buffer;
  size_t result;

  //fp = fopen ( "myfile.bin" , "rb" );
  fp = fopen ( "input.txt" , "r" );
  if (fp==NULL) {fputs ("An error occurred, check if the input file exists.\n",stderr); exit (1);}

  // get file size:
  fseek (fp, 0, SEEK_END);
  lSize = ftell(fp);
  rewind(fp);

  // allocate memory to store the whole file:
  buffer = (char*) malloc (sizeof(char)*lSize);
  if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

  // copy the file into the buffer:
  result = fread (buffer,1,lSize,fp);
  if (result != lSize) {fputs ("Reading error",stderr); exit (3);}

  /* the whole file is now loaded in the memory buffer. */

  // terminate
  fclose(fp);
  free(buffer);
  return 0;
}