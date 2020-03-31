cmake_minimum_required(VERSION 3.15)
project(leetcode_record)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(leetcode_record
        buildTree.cpp
        findContentChildren.cpp
        function_defs.h
        getAllElements.cpp
        longestPalindrome.cpp
        main.cpp
        minimumTotal.cpp
        numTrees.cpp
        uniquePaths.cpp
        zigzagLevelOrder.cpp
        distributeCandies.cpp
        removeDuplicates.cpp
        findContinuousSequence.cpp
        Problems_DP.cpp
        diameterOfBinaryTree.cpp
        canThreePartsEqualSum.cpp
        lengthOfLIS.cpp
        Problems_DFS_BFS.cpp
        luckyNumbers.cpp Problems_String.cpp isRectangleOverlap.cpp getLeastNumbers.cpp minIncrementForUnique.cpp Problems_List.cpp surfaceArea.cpp numRookCaptures.cpp Problems_TopologySort.cpp hasGroupSizeX.cpp lastRemaining.cpp sortArray.cpp)
