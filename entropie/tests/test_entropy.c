#include <stdio.h>

#include "tests.h"
#include "../lib/entropy.h"

MU_TESTS_INIT

static int test_entropy_occurrences() {
  FILE *input = fopen("test1", "r");
  int counts[256];
  int i;
  for (i = 0; i < 256; i++) {
    counts[i] = 0;
  }

  count_occurrences(input, counts);

  mu_assert_eq("counts", counts['a'], 5);
  mu_assert_eq("counts", counts['b'], 3);
  mu_assert_eq("counts", counts['c'], 1);
  mu_assert_eq("counts", counts['d'], 0);
  
  return 0;
}



static int test_entropy_occurrences2() {
  FILE *input = fopen("test2", "r");
  int counts[256];
  int i;
  for (i = 0; i < 256; i++) {
    counts[i] = 0;
  }
 
  count_occurrences(input, counts);

  mu_assert_eq("counts", counts['a'], 3);
  mu_assert_eq("counts", counts['b'], 2);
  mu_assert_eq("counts", counts['c'], 0);
  mu_assert_eq("counts", counts['d'], 4);
  
  return 0;
}






static int test_entropy_function() {
   FILE *input = fopen("test1", "r");
  int counts[256];
  int i;
  struct file_stat f;
  for (i = 0; i < 256; i++) {
    counts[i] = 0;
  }

  count_occurrences(input, counts);

  f = entropy(counts);
  printf("Entropy %2f \n", round(f.entropy * 100) / 100 );
  mu_assert_eq("entropy", round(f.entropy * 100) / 100, 1.35);
  
  return 0;
}


static int all_tests() {
   mu_run_test(test_entropy_occurrences);
   mu_run_test(test_entropy_occurrences2);
   mu_run_test(test_entropy_function);
   return mu_tests_success;
}
 
int main(int argc, char **argv) {
  int result = all_tests();
  if (result != 0) {
    fprintf(stderr, "TESTS FAILED!\n");
  }
  else {
    printf("ALL TESTS PASSED\n");
  }
  printf("Tests run: %d (including %d assertions)\n", mu_tests_run, mu_assert_run);
  
  return result != 0;
}
