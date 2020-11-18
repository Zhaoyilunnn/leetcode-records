cmake_minimum_required(VERSION 3.15)
project(leetcode-records)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(leetcode_record
        problems_tree.cpp
        unassorted/findContentChildren.cpp
        include/algorithms_data_structures.h
        main.cpp
        unassorted/distributeCandies.cpp
        unassorted/removeDuplicates.cpp
        unassorted/findContinuousSequence.cpp
        problems_dp_greedy.cpp
        unassorted/canThreePartsEqualSum.cpp
        problems_dfs_bfs.cpp
        problems_stack.cpp
        unassorted/luckyNumbers.cpp problems_string.cpp unassorted/isRectangleOverlap.cpp unassorted/getLeastNumbers.cpp unassorted/minIncrementForUnique.cpp problems_list.cpp unassorted/surfaceArea.cpp unassorted/numRookCaptures.cpp problems_graph.cpp unassorted/hasGroupSizeX.cpp unassorted/lastRemaining.cpp unassorted/gameOfLife.cpp unassorted/movingCount.cpp problems_backtracking.cpp unassorted/intersection.cpp unassorted/mergeIntervals.cpp problems_binary_search.cpp problems_bitwise_ops.cpp problems_math.cpp unassorted/twoSum.cpp unassorted/maximalSquare.cpp unassorted/subarraySum.cpp problems_prefix.cpp unassorted/productExceptSelf.cpp unassorted/equationPossible.cpp unassorted/isPalindrome.cpp unassorted/threeSum.cpp unassorted/threeSumClosest.cpp unassorted/wordBreak.cpp unassorted/firstMissingPositive.cpp problems_sort.cpp unassorted/intersect.cpp include/objects_oriented.h include/common_libs.h unassorted/validMountainArray.cpp unassorted/canCompleteCircuit.cpp)
