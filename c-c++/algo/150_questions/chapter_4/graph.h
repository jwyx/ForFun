#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#define INFINITE_POSITIVE 100

enum color {
  WHITE = 0,
  GRAY,
  BLACK,
};

typedef struct node {
  int d;    // distance
  color c;  // color
  node* p;  // parent
  char name; // node name
  vector<node*> adjs; // adjs list
  int d_time;
  int f_time;
} node;

// 图的表示
// undirected graph & directed graph
//
// r - s    t - u
// |   |  / | / |
// v   w  - x - y
//
// start node: s
//
// 1. adjacent list

node nodes[8];

void create_graph_adjs_list(node nodes[], int len)
{
  char names[8] = { 'r', 's', 't', 'u', 'v', 'w', 'x', 'y' };

  for (int i = 0; i < len; i ++) {
    nodes[i].d = INFINITE_POSITIVE;
    nodes[i].name = names[i];
    nodes[i].c = WHITE;
    nodes[i].p = NULL;
  }

  // 'r'
  nodes[0].adjs.push_back(&nodes['v'-'r']);
  nodes[0].adjs.push_back(&nodes['s'-'r']);

  // 's'
  nodes[1].adjs.push_back(&nodes['r'-'r']);
  nodes[1].adjs.push_back(&nodes['w'-'r']);

  // 't'
  nodes[2].adjs.push_back(&nodes['w'-'r']);
  nodes[2].adjs.push_back(&nodes['x'-'r']);
  nodes[2].adjs.push_back(&nodes['u'-'r']);

  // 'u'
  nodes[3].adjs.push_back(&nodes['t'-'r']);
  nodes[3].adjs.push_back(&nodes['x'-'r']);
  nodes[3].adjs.push_back(&nodes['y'-'r']);

  // 'v'
  nodes[4].adjs.push_back(&nodes['r'-'r']);

  // 'w'
  nodes[5].adjs.push_back(&nodes['t'-'r']);
  nodes[5].adjs.push_back(&nodes['s'-'r']);
  nodes[5].adjs.push_back(&nodes['x'-'r']);

  // 'x'
  nodes[6].adjs.push_back(&nodes['t'-'r']);
  nodes[6].adjs.push_back(&nodes['w'-'r']);
  nodes[6].adjs.push_back(&nodes['y'-'r']);

  // 'y'
  nodes[7].adjs.push_back(&nodes['u'-'r']);
  nodes[7].adjs.push_back(&nodes['x'-'r']);

}

void print_adjs_list(node nodes[], int len)
{
  for (int i = 0; i < len; i ++) {
    cout << nodes[i].name << ": ";
    vector<node*>::iterator it;
    for (it = nodes[i].adjs.begin(); it < nodes[i].adjs.end(); it ++) {
      cout << (**it).name << " ";
    }
    cout << endl;
  }
}


// 2. adjacent matrix
#define INIT_BYTE (128)
int adjs_matrix[8][8];
// 节约空间的存储模式
unsigned char adjs_matrix_byte[8];

void create_graph_adjs_matrix(node nodes[], int adjs_m[][8], unsigned char adjs_m_b[], int len)
{
  char names[8] = { 'r', 's', 't', 'u', 'v', 'w', 'x', 'y' };

  for (int i = 0; i < len; i ++) {
    nodes[i].d = INFINITE_POSITIVE;
    nodes[i].name = names[i];
    nodes[i].c = WHITE;
    nodes[i].p = NULL;
  }

  // 'r'
  adjs_m[0]['v'-'r'] = 1;
  adjs_m[0]['s'-'r'] = 1;
  adjs_m_b[0] ^= (INIT_BYTE >> ('v'-'r'));
  adjs_m_b[0] ^= (INIT_BYTE >> ('s'-'r'));

  // 's'
  adjs_m[1]['r'-'r'] = 1;
  adjs_m[1]['w'-'r'] = 1;
  adjs_m_b[1] ^= (INIT_BYTE >> ('r'-'r'));
  adjs_m_b[1] ^= (INIT_BYTE >> ('w'-'r'));

  // 't'
  adjs_m[2]['w'-'r'] = 1;
  adjs_m[2]['x'-'r'] = 1;
  adjs_m[2]['u'-'r'] = 1;
  adjs_m_b[2] ^= (INIT_BYTE >> ('w'-'r'));
  adjs_m_b[2] ^= (INIT_BYTE >> ('x'-'r'));
  adjs_m_b[2] ^= (INIT_BYTE >> ('u'-'r'));

  // 'u'
  adjs_m[3]['t'-'r'] = 1;
  adjs_m[3]['x'-'r'] = 1;
  adjs_m[3]['y'-'r'] = 1;
  adjs_m_b[3] ^= (INIT_BYTE >> ('t'-'r'));
  adjs_m_b[3] ^= (INIT_BYTE >> ('x'-'r'));
  adjs_m_b[3] ^= (INIT_BYTE >> ('y'-'r'));

  // 'v'
  adjs_m[4]['r'-'r'] = 1;
  adjs_m_b[4] ^= (INIT_BYTE >> ('r'-'r'));

  // 'w'
  adjs_m[5]['t'-'r'] = 1;
  adjs_m[5]['s'-'r'] = 1;
  adjs_m[5]['x'-'r'] = 1;
  adjs_m_b[5] ^= (INIT_BYTE >> ('t'-'r'));
  adjs_m_b[5] ^= (INIT_BYTE >> ('s'-'r'));
  adjs_m_b[5] ^= (INIT_BYTE >> ('x'-'r'));

  // 'x'
  adjs_m[6]['t'-'r'] = 1;
  adjs_m[6]['w'-'r'] = 1;
  adjs_m[6]['y'-'r'] = 1;
  adjs_m_b[6] ^= (INIT_BYTE >> ('t'-'r'));
  adjs_m_b[6] ^= (INIT_BYTE >> ('w'-'r'));
  adjs_m_b[6] ^= (INIT_BYTE >> ('y'-'r'));

  // 'y'
  adjs_m[7]['u'-'r'] = 1;
  adjs_m[7]['x'-'r'] = 1;
  adjs_m_b[7] ^= (INIT_BYTE >> ('u'-'r'));
  adjs_m_b[7] ^= (INIT_BYTE >> ('x'-'r'));

}

void print_adjs_matrix(int adjs_m[][8], unsigned char adjs_m_b[], int len)
{
  for (int i = 0; i < len; i ++) {
    cout << static_cast<char>(i+'r') << ": ";
    for (int j = 0; j < len; j ++) {
      if (adjs_m[i][j])
        cout << static_cast<char>(j+'r') << " ";
    }
    cout << endl;
  }

  cout << "===========" << endl;

  for (int i = 0; i < len; i ++) {
    cout << static_cast<char>(i+'r') << ": ";
    for (int j = 0; j < len; j ++) {
      if (adjs_m_b[i] & (INIT_BYTE >> j))
        cout << static_cast<char>(j+'r') << " ";
    }
    cout << endl;
  }
}

int adjs_list_test(int argc, char* argv[])
{
  create_graph_adjs_list(nodes, 8);
  print_adjs_list(nodes, 8);
  return 0;
}

int adjs_matrix_test(int argc, char* argv[])
{
  create_graph_adjs_matrix(nodes, adjs_matrix, adjs_matrix_byte, 8);
  print_adjs_matrix(adjs_matrix, adjs_matrix_byte, 8);
  return 0;
}

#endif

