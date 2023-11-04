#include "MyQueue.h"

#include <gtest.h>

TEST(TQueue, cant_create_with_zero_size)
{
	ASSERT_ANY_THROW(TQueue<int> s1(0));
}

TEST(TQueue, can_create)
{
	ASSERT_NO_THROW(TQueue<int> s1(10));
}

TEST(TQueue, can_get_size)
{
	TQueue<int> s1(2);
	ASSERT_EQ(2, s1.GetSize());
}

TEST(TQueue, can_get_ind)
{
	TQueue<int> s1(2);
	ASSERT_EQ(0, s1.GetInd());
}

TEST(TQueue, can_get_end)
{
	TQueue<int> s1(2);
	ASSERT_EQ(2, s1.GetEnd());
}

TEST(TQueue, can_get_count)
{
	TQueue<int> s1(2);
	ASSERT_EQ(0, s1.GetCount());
}

TEST(TQueue, can_push_element)
{
	TQueue<int> s1(1);
	ASSERT_NO_THROW(s1.Push(10));
}

TEST(TQueue, cant_push_element_when_queue_is_full)
{
	TQueue<int> s1(1);
	s1.Push(10);
	ASSERT_ANY_THROW(s1.Push(10));
}

TEST(TQueue, can_pop_element)
{
	TQueue<int> s1(1);
	int d;
	s1.Push(10);
	ASSERT_NO_THROW(d = s1.Get());
	EXPECT_EQ(10, d);
}

TEST(TQueue, cant_pop_element_when_queue_is_empty)
{
	TQueue<int> s1(1);
	ASSERT_ANY_THROW(s1.Get());
}

TEST(TQueue, can_check_is_empty)
{
	TQueue<int> s1(2);
	ASSERT_EQ(true, s1.IsEmpty());
	s1.Push(1);
	ASSERT_EQ(false, s1.IsEmpty());
}

TEST(TQueue, can_check_is_full)
{
	TQueue<int> s1(1);
	ASSERT_EQ(false, s1.IsFull());
	s1.Push(1);
	ASSERT_EQ(true, s1.IsFull());
}

TEST(TQueue, can_assign_queue_to_itself)
{
	TQueue<int> s1(2);
	ASSERT_NO_THROW(s1 = s1);
}

TEST(TQueue, can_assign_queues_with_different_sizes)
{
	TQueue<int> s1(2), s2(3);
	ASSERT_NO_THROW(s1 = s2);
}
TEST(TQueue, can_indexing)
{
	TQueue<int> s1(2);
	s1.Push(3);
	s1.Push(4);
	EXPECT_EQ(3, s1[0]);
	s1.Get();
	EXPECT_EQ(4, s1[0]);
	s1.Push(5);
	EXPECT_EQ(5, s1[1]);
}
TEST(TQueue, can_controlled_indexing)
{
	TQueue<int> s1(2);
	ASSERT_NO_THROW(s1.at(0));
	ASSERT_ANY_THROW(s1.at(3));
	s1.Push(3);
	s1.Push(4);
	EXPECT_EQ(3, s1.at(0));
	s1.Get();
	EXPECT_EQ(4, s1.at(0));
	s1.Push(5);
	EXPECT_EQ(5, s1.at(1));

}