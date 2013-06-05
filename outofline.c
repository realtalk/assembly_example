#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int
call_outofline_asm_add(int x, int y);

uint64_t
call_outofline_asm_rdtsc();

int
main(int argc, char *argv[])
{
  int x = 5, y = 7;
  uint64_t result = 0;

  result = call_outofline_asm_add(x, y);

  printf("out of line asm result: %" PRId64 "\n", result);

  result = call_outofline_asm_rdtsc();

  printf("rdtsc value: %" PRId64 "\n", result);

  return 0;
}
