// dfs
#include "graph.h"

// O(V + E)
bool dfs_visit(node &u, char target) {
  if (u.name == target)
    return true;
  u.c = GRAY;
  for (int i = 0; i < u.adjs.size(); i ++) {
    node &v = *u.adjs[i];
    if (v.c == WHITE) {
      v.p = &u;
      if(dfs_visit(v, target))
        return true;
    }
  }
  u.c = BLACK;
  return false;
}

int main(void) {
  adjs_list_test(0, NULL);

  for (int i = 0; i < sizeof(nodes)/sizeof(node); i ++) {
    nodes[i].c = WHITE;
    nodes[i].p = NULL;
  }

  bool result = dfs_visit(nodes[0], 'u');

  // test
  for (int i = 0; i < sizeof(nodes)/sizeof(node); i ++) {
    cout << nodes[i].name << ": "\
      << nodes[i].c << ": ";
      //<< nodes[i].d << ": "\
      << nodes[i].d_time << ": "\
      << nodes[i].f_time << ": ";
    if (nodes[i].p)
      cout << nodes[i].p->name;
    else
      cout << "NULL";
    cout << endl;
  }
  cout << "result: " << result << endl;
}

