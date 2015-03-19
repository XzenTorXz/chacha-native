/*
Copyright (C) 2014 insane coder (http://insanecoding.blogspot.com/, http://chacha20.insanecoding.org/)

Permission to use, copy, modify, and distribute this software for any
purpose with or without fee is hereby granted, provided that the above
copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#ifndef CHACHA20_SIMPLE_H
#define CHACHA20_SIMPLE_H
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <gsimd.h>
#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

#ifdef __cplusplus
extern "C"
{
#endif
typedef svec<4,uint32_t> uint32x4;
typedef struct
{
  uint32_t schedule[16];
  uint32_t keystream[16];
  size_t available;
} chacha20_ctx;

typedef struct
{
  uint32x4 a;
  uint32x4 b;
  uint32x4 c;
  uint32x4 d;
} simd_ctx;
//Call this to initilize a chacha20_ctx, must be called before all other functions
void chacha20_setup(chacha20_ctx *ctx, const uint8_t *key, size_t length, const uint8_t *nonce);

//Raw keystream for the current block, convert output to uint8_t[] for individual bytes. Counter is incremented upon use
bool chacha20_block(chacha20_ctx *ctx, uint32_t output[16]);

//Encrypt an arbitrary amount of plaintext, call continuously as needed
bool chacha20_encrypt(chacha20_ctx *ctx, const uint8_t *in, uint8_t *out, size_t length);

#ifdef __cplusplus
}
#endif

#endif