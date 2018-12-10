#include "..\Lab3-Stack\Stack.h"

#include "gtest.h"

TEST(Stack, can_create_stack__with_positive_size)
{
  ASSERT_NO_THROW(TStack <int> s(5));
}

TEST(TStack, cant_create_stack_with_negative_size)
{
	ASSERT_ANY_THROW(TStack <int> s(-5));
}

TEST(TStack, cant_push_elem)
{
	TStack <int> s(5);
	for (int i = 0; i < 5; i++)
		s.Push(i);
	ASSERT_ANY_THROW(s.Push(6));//пытается добавить в полный стек
}

TEST(TStack, can_pop_elem)
{
	TStack <int> s(5);
	for (int i = 0; i<5; i++)
		s.Push(i);
	EXPECT_EQ(4, s.Pop());//возвращает 4
}

TEST(TStack, cant_pop_elem)
{
	TStack <int> s(0);
	ASSERT_ANY_THROW(s.Pop());
}

TEST(TStack, stack_is_empty_return_true)
{
	TStack <int> s(5);
	EXPECT_EQ(true, s.IsEmpty());
}

TEST(TStack, stack_is_full_return_true)
{
	TStack <int> s(5);
	for (int i = 0; i<5; i++)
		s.Push(i);
	EXPECT_EQ(true, s.IsFull());
}