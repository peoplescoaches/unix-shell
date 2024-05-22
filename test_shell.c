#include "test-framework/unity.h"
#include <stdbool.h>

void setUp(void)
{
}

void tearDown(void)
{
}

static void test(void)
{
   TEST_ASSERT_FALSE(false);
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test);

   return UNITY_END();
}
