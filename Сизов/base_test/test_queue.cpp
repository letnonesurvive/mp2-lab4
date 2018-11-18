#include "Queue.h"
#include <gtest.h>

TEST(TQueue, can_create_queue_with_positive_length)
{
  ASSERT_NO_THROW(TQueue<int> q(5));
}
TEST(TQueue, can_not_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(TQueue<int> q(-5));
}
TEST(TQueue, can_not_create_queue_with_too_large_length)
{
	ASSERT_ANY_THROW(TQueue<int> q(MAXQUEUE+1));
}
TEST(TQueue, can_return_first_elem_of_queue)
{
	TQueue<int> q(5);
	for (int i = 0; i < 5; i++)
		q.Put(i);
	EXPECT_EQ(0, q.GetFirst());
}
TEST(TQueue, can_return_last_elem_of_queue)
{
	TQueue<int> q(5);
	for (int i = 0; i < 5; i++)
		q.Put(i);
	EXPECT_EQ(4, q.GetLast());
}
TEST(TQueue, can_put_and_get_elem_in_queue)
{
	TQueue<int> q(1);
	ASSERT_NO_THROW(q.Put(10));
	ASSERT_NO_THROW(q.Get());
}
TEST(TQueue, method_get_delete_elem_of_queue)
{
	TQueue<int> q(1);
	q.Put(5);
	q.Get();
	EXPECT_NE(5, q.GetFirst());
	//EXPECT_TRUE(q.IsEmpty());
}
TEST(TQueue, can_check_queue_for_empty)
{
	TQueue<int> q(1);
	EXPECT_TRUE(q.IsEmpty());
}
TEST(TQueue, can_check_queue_for_full)
{
	TQueue<int> q(5);
	for (int i = 0; i < 5; i++)
	{
		q.Put(i);
	}
	EXPECT_TRUE(q.IsFull());
}
TEST(TQueue, can_create_copied_queue)
{
	TQueue<int> q1(5);
	for (int i = 0; i < 5; i++)
	{
		q1.Put(i);
	}
	TQueue<int> q2(q1);
	EXPECT_EQ(q1, q2);
}
TEST(TQueue, can_compare_two_queue)
{
	TQueue<int>q1(5),q2(5);
	q1.Put(5);
	q2.Put(5);
	EXPECT_TRUE(q1==q2);
}
TEST(TQueue, two_queue_are_not_equal)
{
	TQueue<int>q1(5), q2(5);
	q1.Put(3);
	EXPECT_FALSE(q1 == q2);
}
TEST(TQueue, can_assign_queue)
{
	TQueue<int>q1(5), q2(5);
	q1.Put(5);
	q2 = q1;
	EXPECT_EQ(q1, q2);
}
TEST(TQueue, assign_operator_change_queue_size)
{
	TQueue<int>q1(10), q2(5);
	q2 = q1;
	EXPECT_NE(q2.Size(), 5);
}
TEST(TQueue, assign_operator_change_queue_first)
{
	TQueue<int>q1(5), q2(5);
	for (int i = 0; i < 5; i++)
	{
		q1.Put(i+1);
		q2.Put(5);
	}
	q2 = q1;
	EXPECT_NE(5, q2.GetFirst());
	//EXPECT_EQ(q2.GetFirst(), 1);
}
TEST(TQueue, assign_operator_change_queue_last)
{
	TQueue<int>q1(5), q2(5);
	for (int i = 0; i < 5; i++)
	{
		q1.Put(i + 1);
		q2.Put(1);
	}
	q2 = q1;
	EXPECT_NE(1, q2.GetLast());
}
TEST(TQueue, two_different_queues_have_different_memories)
{
	TQueue<int> q1(5), q2(5);
	EXPECT_NE(&q1, &q2);
}

