// 1. understand problem
//  single-linked list or doubly-linked list?
//  space complexity
//  can use constant space?
//  remove all or leave one?
// ...
// 3. if extra buffer, one pass
//      record is not dup
//      if dup remove
//    if no buffer,
//      1. sort, then one pass remove, O(n logn)
//      2. current, check previous elements for dup
//         or current, remove all dups in the rest, O(n^2)
// ...
// TODO: !! and how to sort list
