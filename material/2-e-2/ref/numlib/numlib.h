#include <stdint.h>
#include <stdio.h>

// Skip spaces in file.
void skipspaces(FILE *f);

// All functions return 1 on format failure, and EOF if the first read
// is EOF.

int read_uint_ascii(FILE *f, uint32_t *out);

int write_uint_ascii(FILE *f, uint32_t x);

int write_uint_le(FILE *f, uint32_t x);

int read_uint_le(FILE *f, uint32_t *out);
