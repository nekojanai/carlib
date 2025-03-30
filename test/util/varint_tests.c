/* ============================================================================
  authors: github.com/nekojanai  
  SPDX-License-Identifier: MIT
============================================================================ */

#include <stdio.h>
#include <unity.h>
#include <unity_fixture.h>

#include <../../util/varint.h>

TEST_GROUP(varint);

TEST_SETUP(varint){};
TEST_TEAR_DOWN(varint){};

static void testEncodeDecode(uint64_t to_encode) {
  printf("\n");
  uint64_t decoded;
  uint8_t r[10], *p;
  p = encode_varint(to_encode, r);
  printf("e: %20lu %20ld\n", to_encode, p - r);

  p = (void *)decode_varint(&decoded, r);
  printf("d: %20lu %20ld\n\n", decoded, p - r);

  TEST_ASSERT_EQUAL(to_encode, decoded);
}

TEST(varint, test00)
{
  testEncodeDecode(1<<24); 
};

TEST(varint, test01)
{
  testEncodeDecode((1 << 14) + 127);
};

TEST(varint, test02)
{
  testEncodeDecode(~0LU); 
};

TEST(varint, test03)
{
  testEncodeDecode((1 << 14) + 127);
};

TEST(varint, test04)
{
  testEncodeDecode(345635437642);
};

TEST(varint, test05)
{
  testEncodeDecode(65460); 
};

TEST(varint, test06)
{
  testEncodeDecode(56);
};

TEST(varint, test07)
{
  testEncodeDecode(150);
};
