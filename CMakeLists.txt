cmake_minimum_required(VERSION 3.15)
project(leetcode_record)

set(CMAKE_CXX_STANDARD 14)

add_executable(leetcode_record
        numTrees.cpp function_defs.h main.cpp minimumTotal.cpp longestPalindrome.cpp maxSubArray.cpp uniquePaths.cpp climbStairs.cpp rob.cpp findContentChildren.cpp buildTree.cpp zigzagLevelOrder.cpp getAllElements.cpp)
