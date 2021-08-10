#include "LinkedList.hpp"

#include "gtest/gtest.h"


TEST( LinkedList, Contruct ) { ASSERT_NO_THROW( LinkedList<int> l ); }

TEST( LinkedList, Empty )
{
  LinkedList<int> l;
  EXPECT_TRUE( l.empty() );
}

TEST( LinkedList, Push_Front )
{
  LinkedList<int> l;
  l.push_front( 5 );
  l.push_front( 10 );

  EXPECT_EQ( l.front()->val, 10 );
  EXPECT_EQ( l.front()->next->val, 5 );
}

class LinkedListTest : public ::testing::Test
{
protected:
  void SetUp() override
  {
    list.push_front( 1 );
    list.push_front( 2 );
    list.push_front( 3 );
    list.push_front( 4 );
    list.push_front( 5 );
    list.push_front( 6 );
  }

  // void TearDown() override {}

  LinkedList<int> list;
};

TEST_F( LinkedListTest, Pop_Front )
{
  EXPECT_EQ( list.front()->val, 6 );
  list.pop_front();
  EXPECT_EQ( list.front()->val, 5 );
  list.pop_front();
  EXPECT_EQ( list.front()->val, 4 );
  list.pop_front();
  EXPECT_EQ( list.front()->val, 3 );
  list.pop_front();
  EXPECT_EQ( list.front()->val, 2 );
  list.pop_front();
  EXPECT_EQ( list.front()->val, 1 );
  list.pop_front();
  EXPECT_EQ( list.front(), nullptr );
  EXPECT_THROW( list.pop_front();, std::out_of_range );
}

TEST_F( LinkedListTest, Clear )
{
  EXPECT_FALSE( list.empty() );
  list.clear();
  EXPECT_TRUE( list.empty() );
}

TEST_F( LinkedListTest, Insert_After )
{
  auto * node = list.front();
  node        = node->next->next;

  EXPECT_EQ( node->val, 4 );
  EXPECT_EQ( node->next->val, 3 );
  list.insert_after( node, 100 );
  EXPECT_EQ( node->next->val, 100 );
  EXPECT_EQ( node->next->next->val, 3 );
}

TEST_F( LinkedListTest, Erase_After )
{
  auto * node = list.front();
  node        = node->next->next;

  EXPECT_EQ( node->val, 4 );
  EXPECT_EQ( node->next->val, 3 );
  list.erase_after( node );
  EXPECT_EQ( node->next->val, 2 );
}