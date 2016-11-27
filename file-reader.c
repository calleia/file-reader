#include <stdio.h>
#include <stdlib.h>

char *read(char *filename) {
  FILE *fp;
  long lSize;
  char *buffer;
  size_t result;

  fp = fopen(filename, "r");
  if (fp==NULL) {
    fputs("ERROR: input file not found.\n", stderr);
    exit(1);
  }

  // obtain file size:
  fseek (fp , 0 , SEEK_END);
  lSize = ftell(fp);
  rewind (fp);

  // allocate memory to contain the whole file:
  buffer = (char*) malloc(sizeof(char) * lSize);
  if (buffer == NULL) {
    fputs("ERROR: unable to allocate memory.\n", stderr);
    exit(2);
  }

  // copy the file into the buffer:
  result = fread (buffer, 1, lSize, fp);
  if (result != lSize) {
    fputs ("ERROR: input file can NOT be read.\n", stderr);
    exit(3);
  }

  // terminate
  fclose (fp);

  return buffer;
}


void write(char *filename, char *buffer)
{
  FILE *fp;

  //fputs(buffer, stdout); //debug

  fp = fopen(filename, "wb");
  //fwrite(buffer, sizeof(char), sizeof(buffer), fp);
  fputs(buffer, fp);
  fclose(fp);
  free (buffer);
}

int main(int argc, char *argv[]) {
  write(argv[2], read(argv[1]));
}
