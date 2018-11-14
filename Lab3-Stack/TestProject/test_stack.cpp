#include "..\Lab3-Stack\Stack.h"

#include "gtest.h"

TEST(Stack, can_create_stack__with_positive_size)
{
  ASSERT_NO_THROW(TStack <int> s(5));
}
