#include<stdio.h>
#include<stdlib.h>

#include "lib/entropy.h"

int main(int argc, char **argv) {

  if (argc <= 1) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    exit(1);
  }
  FILE *file = fopen(argv[1], "r");
  /* À COMPLÉTER */

  fclose(file);
  exit(0);
}
