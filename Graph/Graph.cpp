//
//  Graphh.cpp
//  Algorithms
//
//  Created by Harshavardhan K K on 29/01/18.
//  Copyright © 2018 Harshavardhan K. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

#include "Utilities.h"

using namespace std;

template <typename T>

class GraphNode {
    
    T data;
    vector<GraphNode> connections;
    
public:
    
    GraphNode(T data) {
        this->data = data;
    }
    
    void add_connection(T data) {
        GraphNode node(data);
        connections.push_back(node);
    }

    size_t degree() {
        return connections.size();
    }
    
    vector<GraphNode>& get_connections() {return connections; }
    
    T& get_data() { return data; }
    
    friend ostream & operator << (ostream &out, GraphNode& node) {
        out << node.get_data();
        
        return out;
    }

    bool operator == (GraphNode& rhs) {

        if(this->get_data() == rhs.get_data()) {
            return true;
        }

        return false;
    }
};

template <typename T> 

class Graph {

    vector< GraphNode<T> > nodes;

    //MARK:- Helpers
    GraphNode<T>* search(vector< GraphNode<T> >& list, T key) {

        size_t length = list.size();

        for(size_t i = 0; i < length; i++) {
            if(list[i].get_data() == key) {
                return &list[i];
            }
        }

        return NULL;
    }

public:

    Graph(T start) {
        GraphNode<T> node(start);
        nodes.push_back(node);
    }

    Graph() {}

    GraphNode<T>* get_node(T data) {

        GraphNode<T>* node = search(nodes, data); 

        if(node == NULL) {
            cout << data << " not found\n";
            return NULL;
        } 

        return node;
    }

    void add_edge(T nodeA, T nodeB) {

        GraphNode<T> child(nodeA);
        GraphNode<T> child2(nodeB);

        bool foundA = false;
        bool foundB = false;

        size_t length = nodes.size();

        for(size_t i = 0; i < length; i++) {

            if(nodes[i] == child) {
                nodes[i].add_connection(nodeB);
                cout << child << " is found\n";
                foundA = true;
            }

            if(nodes[i] == child2) {
                nodes[i].add_connection(nodeA);
                cout << child2 << " is found\n";
                foundB = true;
            }

            if(foundA && foundB) {
                cout << "Edge between " << child << " and " << child2 << " already exists\n";
                return;
            }

        }

        if(!foundB) {
            child2.add_connection(nodeA);
            nodes.push_back(child2);
            foundB = true;
        }

        if(!foundA) {
            child.add_connection(nodeB);
            nodes.push_back(child);
            foundA = true;
        }

        if(!foundA && !foundB) {
            
            child.add_connection(nodeB);
            child2.add_connection(nodeA);

            nodes.push_back(child);
            nodes.push_back(child2);
        }

        cout << "Added edge between " << child << " and " << child2 << '\n';

    }

    void bread_first_search(T node) {

        bool visited[INT16_MAX];
        //string bfs;

        GraphNode<T>* start = search(nodes, node);
        queue< GraphNode<T> > queue;

        if(start != NULL) {
            cout << "Using " << node << " source node\n";

            queue.push(*start);

            visited[start->get_data()] = true;

            while(!queue.empty()) {

                GraphNode<T> child = queue.front();
                cout << child << " ";
                queue.pop();

                //Temporary work around over accessing the correct node object. Queue.pop: is misbehaving with the data. 
                //Use pointers/references in the next iteration of updates
                child = *(this->get_node(child.get_data()));

                size_t length = child.degree();
                vector< GraphNode<T> > connections = child.get_connections();

                for(size_t i = 0; i < length; i++) {

                    if(!visited[connections[i].get_data()]) {
                        queue.push(connections[i]);
                        visited[connections[i].get_data()] = true;
                    }

                }
            }

        } else {
            cout << node << " not found. Aborting BFS..\n";
        }

        cout << "\nBFS done\n";

    }

};

void test_graph_node() {
    
    GraphNode<string> node("hello");

    node.add_connection("hi");
    node.add_connection("hola");

    display(node.get_connections());
    
}

void test_graph() {
    Graph<char> graph('A');
    graph.add_edge('A', 'B');
    graph.add_edge('B', 'C');
    graph.add_edge('C', 'E');
    graph.add_edge('A', 'G');
    graph.add_edge('E', 'D');
    graph.add_edge('E', 'F');
    graph.add_edge('A', 'N');

    //display(graph.get_node('C')->get_connections());

    GraphNode<char> *node = graph.get_node('C');
    display(node->get_connections());

    graph.bread_first_search('A');

}

int main(int argc, char** argv) {
    //test_graph_node();
    test_graph();

    return 0;
}
