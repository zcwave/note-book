//
// Created by Sugar on 2022/8/18.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H


#include <string>
#include <map>
#include <set>
#include <vector>

struct Node;     /* Forward references to these two types so  */
struct Arc;      /* that the C++ compiler can recognize them. */

/*
 * Type: SimpleGraph
 * -----------------
 * This type represents a graph and consists of a set of nodes, a set of
 * arcs, and a map that creates an association between names and nodes.
 */

struct SimpleGraph {
   std::set<Node *> nodes;
   std::set<Arc *> arcs;
   std::map<std::string, Node *> node_map;
};

/*
 * Type: Node
 * ----------
 * This type represents an individual node and consists of the
 * name of the node and the set of arcs from this node.
 */

struct Node {
    std::string name;
    std::set<Arc *> arcs;
};

/*
 * Type: Arc
 * ---------
 * This type represents an individual arc and consists of pointers
 * to the endpoints, along with the cost of traversing the arc.
 */

struct Arc {
    Arc(Node *s, Node *f, double c) : start(s), finish(f), cost(c){}
    Node *start;
    Node *finish;
    double cost;
};


#endif //GRAPH_GRAPH_H
