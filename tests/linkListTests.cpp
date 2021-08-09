#include "LinkedList.hpp"
#include "gtest/gtest.h"

TEST(LinkedList, Contruct){
	ASSERT_NO_THROW( LinkedList<int> l );
}