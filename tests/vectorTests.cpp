#include "vector.hpp"

#include "gtest/gtest.h"

TEST( vector, Create_Vector ) { ASSERT_NO_THROW( vector<int> v ); }

TEST( vector, Size )
{
  vector<int> v;
  EXPECT_EQ( v.size(), 0 );
  EXPECT_EQ( v.max_size(), 1 );
}

TEST( vector, Push_Back )
{
  vector<int> v;

  v.push_back( 10 );
  v.push_back( 18 );

  EXPECT_EQ( v.at( 0 ), 10 );
  EXPECT_EQ( v.at( 1 ), 18 );
}