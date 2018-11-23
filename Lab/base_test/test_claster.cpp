#include "claster.cpp"
#include <gtest.h>

TEST(TClaster, can_create_claster)
{
	ASSERT_NO_THROW(TClaster q);
}
TEST(TClaster, not_losing_programs)
{
	TClaster q;
	q.DoTact();
	EXPECT_EQ(q.GetAllProgs(), q.GetDone() + q.GetNotDone() + q.GetRejected() + q.GetRunningNow());
}