// 1. understand question
//  the format of input int[N][N]
//  clockwise or counter clockwise
//  the range of N
// 2. example to solidify the understanding
//  int a[4][4]
// 3. design algorithm
//  temp = top-left
//  top-left = bottom-left
//  bottom-left = bottom-right
//  bottom-right = top-right
//  top-right = temp
//
//  pseudocode
//    for i < N/2
//      for j = i, j < N - 1 -i
//        temp = a[i][j]
//        a[i][j] = a[N-1-j][i]
//        a[N-1-j][i] = a[N-1-i][N-1-j]
//        a[N-1-i][N-1-j] = a[j][N-1-i]
//        a[j][N-1-i] = temp
//
// 4. explain your algorithm
// 5. coding and talking
// 6. ask question if necessary
// 7. verify with example
// 8. check error and special cases
// 9. analyze the big-O; time O(N^2), space O(1)
// 10. test
