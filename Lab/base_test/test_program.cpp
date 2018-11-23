#include "program.h"
#include <gtest.h>

TEST(TProgram, can_assign_program)
{
	TProgram f;
	TProgram q;
	ASSERT_NO_THROW(f = q);
}