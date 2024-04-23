//
// Created by Sugar on 2022/8/18.
//

#include "Graph.h"


/*
 * Function: findShortestPath
 * Usage: std::vector<Arc *> path = findShortestPate(start, finish);
 * Description:
 *      Finds the shortest path between the nodes start and finish
 *    using Dijkstra's algorithm, which keeps track of the shortest
 *    paths in a priority queue.
 *    The function returns a vector of arcs, which is empty if start
 *    and finish are the same node or if no path exits.
 */
std::vector<Arc *> findShortestPath(Node *start, Node *finish){

    std::vector<Arc *> path; // tracks the shortest path.
    PriorityQueue<std::vector<Arc*>, double> queue;// (path, cost)
    std::map<std::string, double> fixed;
    // Map [ Node->name : cost ]
    // the cost of going from the 'start' node to the 'start node is 0.

    while (start != finish){
        if (!fixed.contains(start->name)){
            fixed.emplace(start->name, getPathCost(path));
            for (Arc *arc : start->arcs){
                if (!fixed.contains(arc->finish->name)){
                    path.emplace_back(arc);
                    queue.enqueue(path, getPathCost(path));
                    path.pop_back();
                }
            }
        }
        if (queue.isEmpty()){
            path.clear();
            return path;
        }
        path = queue.dequeue();
        start = path[path.size() - 1]->finish;
    }
    return path;
}


double getPathCost(const std::vector<Arc *> & path){
    double cost = 0;
    for (auto arc : path){
        cost += arc->cost;
    }
    return cost;
}
