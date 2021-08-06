#include "Vector.hpp"

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

class VectorTest : public ::testing::Test
{
protected:
  void SetUp() override
  {
    v.push_back( 1 );
    v.push_back( 2 );
    v.push_back( 3 );
    v.push_back( 4 );
    v.push_back( 5 );
    v.push_back( 6 );
  }

  // void TearDown() override {}

  vector<int> v;
};

TEST_F( VectorTest, Size )
{
  EXPECT_EQ( v.size(), 6 );
  EXPECT_EQ( v.max_size(), 8 );
}

TEST_F( VectorTest, At )
{
  EXPECT_EQ( v.at( 0 ), 1 );
  EXPECT_EQ( v.at( 1 ), 2 );
  EXPECT_EQ( v.at( 2 ), 3 );
  EXPECT_EQ( v.at( 3 ), 4 );
  EXPECT_EQ( v.at( 4 ), 5 );
  EXPECT_EQ( v.at( 5 ), 6 );
  EXPECT_THROW( v.at( 6 ), std::out_of_range );
}

TEST_F( VectorTest, Pop_Back )
{
  v.pop_back();
  EXPECT_EQ( v.at( 0 ), 1 );
  EXPECT_EQ( v.at( 1 ), 2 );
  EXPECT_EQ( v.at( 2 ), 3 );
  EXPECT_EQ( v.at( 3 ), 4 );
  EXPECT_EQ( v.at( 4 ), 5 );
  EXPECT_THROW( v.at( 5 ), std::out_of_range );
}

TEST_F( VectorTest, Insert )
{
  v.insert( 2, 15 );
  EXPECT_EQ( v.at( 0 ), 1 );
  EXPECT_EQ( v.at( 1 ), 2 );
  EXPECT_EQ( v.at( 2 ), 15 );
  EXPECT_EQ( v.at( 3 ), 3 );
  EXPECT_EQ( v.at( 4 ), 4 );
  EXPECT_EQ( v.at( 5 ), 5 );
  EXPECT_EQ( v.at( 6 ), 6 );
  EXPECT_EQ( v.size(), 7 );
}

TEST_F( VectorTest, Erase )
{
  v.erase( 2 );
  EXPECT_EQ( v.at( 0 ), 1 );
  EXPECT_EQ( v.at( 1 ), 2 );
  EXPECT_EQ( v.at( 2 ), 4 );
  EXPECT_EQ( v.at( 3 ), 5 );
  EXPECT_EQ( v.at( 4 ), 6 );
  EXPECT_EQ( v.size(), 5 );
}

TEST_F( VectorTest, Clear )
{
  v.clear();
  EXPECT_EQ( v.size(), 0 );
}