#include <iostream>
#include <cstdio>

// Top coder : https://www.topcoder.com/community/competitive-programming/tutorials/binary-search

// index start from 1
int binary_search(int n, int target) {
    int lo = 1, hi = n;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (A[mid] == target)
            return mid;
        else if (A[mid] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return 0;
}

// requires: hi > max-possible
// baekjoon/1654.cpp / 조건식만 뒤집으면 밑에것을 풀 수 있다?
// 문제는 lo 가 0 이면 0을 테스트하기에 0 div 문제 발생
//        lo 가 1 이면 1이 답으로 ; 최종 테스트 추가 필요
binary_search(lo, hi, p):
    while lo < hi:
        mid = lo + (hi - lo)/2
        if p(mid) == true:
           hi = mid
        else:
           lo = mid+1
    if p(lo) == false:
        complain // p(x) is false for all x in S!
    return lo // lo is the least x for which p(x) is true


binary_search(lo, hi, p):
   while lo < hi:
      mid = lo + (hi-lo+1)/2
      if p(mid) == true:
         hi = mid-1
      else:
         lo = mid
          
   if p(lo) == true:
      complain                // p(x) is true for all x in S!
      
   return lo         // lo is the greatest x for which p(x) is false


// jongman 5.1 binary_search
// n > max available( 10이 가능 최대라면 11을 넣어야;)
//
// (boj:1300) - (lo:1 + 1 < hi:2) 이러면 테스트 안하게 되고, hi가 2로 나온다
//               lo = 0, hi = max+1
int binarysearch(const vector<int>& A, int x) {
    int n = A.size();
    // 0 이 min value (lo:-1 + 1 < hi:1) -> mid:0 (작으면 hi:0 답 0, 크면 hi:1 - 범위 벗어나네)
    int lo = -1, hi = n;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (A[mid] < x)
            lo = mid;
        else
            hi = mid;
    }
    return hi;
}

// 10815.cpp - 같은 수 찾기
// 1654.cpp - 최대 길이 찾기
// 1300.cpp - k랑 같은 범위 찾기
