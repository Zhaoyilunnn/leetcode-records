cmake_minimum_required(VERSION 3.15)
project(leetcode_record)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(leetcode_record
        problems_tree.cpp
        findContentChildren.cpp
        function_defs.h
        longestPalindrome.cpp
        main.cpp
        distributeCandies.cpp
        removeDuplicates.cpp
        findContinuousSequence.cpp
        problems_dp_greedy.cpp
        canThreePartsEqualSum.cpp
        lengthOfLIS.cpp
        problems_dfs_bfs.cpp
        luckyNumbers.cpp problems_string.cpp isRectangleOverlap.cpp getLeastNumbers.cpp minIncrementForUnique.cpp problems_list.cpp surfaceArea.cpp numRookCaptures.cpp problems_topology_sort.cpp hasGroupSizeX.cpp lastRemaining.cpp sortArray.cpp gameOfLife.cpp movingCount.cpp problems_backtracking.cpp intersection.cpp mergeIntervals.cpp problems_binary_search.cpp problems_bitwise_ops.cpp problems_math.cpp twoSum.cpp maximalSquare.cpp)
