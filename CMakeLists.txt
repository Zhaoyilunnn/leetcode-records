cmake_minimum_required(VERSION 3.15)
project(leetcode_record)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(leetcode_record
        buildTree.cpp
        climbStairs.cpp
        findContentChildren.cpp
        function_defs.h
        getAllElements.cpp
        longestPalindrome.cpp
        main.cpp
        maxSubArray.cpp
        minimumTotal.cpp
        numTrees.cpp
        rob.cpp
        uniquePaths.cpp
        zigzagLevelOrder.cpp
        distributeCandies.cpp
        removeDuplicates.cpp
        findContinuousSequence.cpp
        coinChange.cpp
        diameterOfBinaryTree.cpp
        canThreePartsEqualSum.cpp
        gcdOfStrings.cpp
        lengthOfLIS.cpp
        generalBFSAndDFSProblems.cpp
        luckyNumbers.cpp generalStringProblems.cpp isRectangleOverlap.cpp getLeastNumbers.cpp minIncrementForUnique.cpp)
