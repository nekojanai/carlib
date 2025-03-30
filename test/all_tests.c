/* ============================================================================
  authors: github.com/nekojanai  
  SPDX-License-Identifier: MIT
============================================================================ */
#include <unity_fixture.h>

static void RunAllTests(void)
{
  RUN_TEST_GROUP(varint);
}

int main(int argc, const char * argv[])
{
  return UnityMain(argc, argv, RunAllTests);
}
