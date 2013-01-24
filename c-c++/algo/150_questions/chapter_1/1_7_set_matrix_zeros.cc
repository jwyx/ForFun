// ...
// 3. design algorithm (the naive method + how to improve it)
//  naive method:
//    extra NxN matrix, scan all nodes and if 0, fill the row and column in new matrix
//  why we need extra space?
//    because what we need is "fill and not destroy what we will looking for"
//    know which row and column should be filled with zeros
//    move column information and fill at the end of row and column
// 4.
