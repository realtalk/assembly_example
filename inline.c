#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int
call_inline_asm_addition(int x, int y)
{
  printf("let's do an add: %d, %d\n", x, y);

  asm volatile ("addl %%ebx,%%eax"
      : "=a" (x)           /* output operands */
      :  "a" (x), "b" (y)  /* input operands  */
      );

  return x;
}

uint64_t
call_inline_asm_rdtsc()
{
  uint32_t eax_lo = 0, edx_hi = 0;
  uint64_t now = 0;

  asm volatile("rdtsc"
      : "=a" (eax_lo), "=d" (edx_hi)  /* output operands */
  );

  now = ((uint64_t) eax_lo) | ((uint64_t) (edx_hi) << 32);

  return now;
}

int
main(int argc, char *argv[])
{
  int x = 5, y = 7;
  uint64_t result = 0;

  result = call_inline_asm_addition(x, y);

  printf("inline asm result: %" PRId64 "\n", result);

  result = call_inline_asm_rdtsc();

  printf("rdtsc value: %" PRId64 "\n", result);

  return 0;
}

