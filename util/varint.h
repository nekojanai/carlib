/* ============================================================================
  authors: github.com/nekojanai  
  SPDX-License-Identifier: MIT
 =========================================================================== */
#include <stdint.h>
#include <endian.h>

// Encodes a given uint64_t as uleb128
static inline uint8_t* encode_varint(uint64_t v, uint8_t *p)
{
  uint64_t cur_bytes = 1, max_bytes = 128;
  while (v >= max_bytes && cur_bytes < 9)
  {
    v -= max_bytes;
    max_bytes <<= 7;
    ++cur_bytes;
  };
  while (--cur_bytes)
  {
    *p++ = 128 | (v & 127);
    v >>= 7;
  };
  *p++ = v;
  return p;
}

// Decodes a given uleb128
static inline const uint8_t* decode_varint(uint64_t *v, const uint8_t *p)
{
  uint64_t bytes_processed = 0, cur_byte = 0, cur_bit = 0;
  *v = 0;
  do
  {
    bytes_processed += cur_byte;
    *v |= (uint64_t)(*p & 127) << cur_bit;
    cur_byte = 1LU << (cur_bit += 7);
  }
  while((*p++ & 128) && cur_bit < 63);
  if (cur_bit == 63)
  {
    *v |= (uint64_t)(p[-1]) << 56;
  }
  *v += bytes_processed;
  return p;
}
