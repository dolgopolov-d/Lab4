#include "queue.h"
#include <gtest.h>

TEST(TQueue, can_create_queue)
{
	ASSERT_NO_THROW(TQueue q);
}
TEST(TQueue, cant_pop_empty_queue)
{
	TQueue q;
	ASSERT_ANY_THROW(q.Pop());
}
TEST(TQueue, can_check_empty_queue)
{
	TQueue q;
	EXPECT_TRUE(q.IsEmpty());
}
TEST(TQueue, can_check_full_queue)
{
	TQueue q;
	TProgram v;
	for (int i=0;i<MaxMemSize;i++)
		q.Put(v);
	EXPECT_TRUE(q.IsFull());
}
TEST(TQueue, cant_put_in_full_queue)
{
	TQueue q;
	TProgram v;
	for (int i = 0; i<MaxMemSize; i++)
		q.Put(v);
	ASSERT_ANY_THROW(q.Put(v));
}
TEST(TQueue, cant_get_first_element_of_empty_queue)
{
	TQueue q;
	ASSERT_ANY_THROW(q.FirstEl());
}