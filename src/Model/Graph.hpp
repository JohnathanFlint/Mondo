/*
 * Grpah.hpp
 *
 *  Created on: May 9, 2017
 *      Author: nwhi5696
 */

#ifndef MODEL_GRAPH_HPP_
#define MODEL_GRAPH_HPP_

#include <set>;
#include <queue>
#include <assert.h>

template <class Type>
class Graph
{
private:
	static const int MAXIMUM = 20;
	bool adjacentMatrix [MAXIMUM][MAXIMUM];
	Type graphData[MAXIMUM];
	int vertexCount;
	void depthFirstTraversal(Graph<Type> graph, int vertex, bool markedVertices[]);

public:
	Graph();
	~Graph();

	void addVertex(const Type& value);
	void addEdge(int source, int target);
	void removeEdge(int source, int target);
	Type& operator [] (int vertex);
	Type operator [] (int vertex) const;
	int size() const;
	bool areConnected(int source, int target) const;
	std::set<int> neighbors(int vertex) const;
	void depthFirstTraversal(Graph<Type> graph, int vertex);
};

template <class Type>
const int Graph<Type> :: MAXIMUM;

template <class Type>
Graph<Type> :: Graph()
{
	this->vertexCount = 0;
}

template <class Type>
Graph<Type> :: ~Graph()
{
	delete [] this->adjacentMatrix;
	delete [] this->graphData;
}

template <class Type>
int Graph<Type> :: size() const
{
	return vertexCount;
}

template <class Type>
void Graph<Type> :: addVertex(const Type& value)
{
	assert(size() < MAXIMUM);
	int newVertexNumber = vertexCount;
	vertexCount++;

	for(int otherVertexNumber = 0; otherVertexNumber < vertexCount; otherVertexNumber++)
	{
		adjacentMatrix[otherVertexNumber][newVertexNumber] = false;
		adjacentMatrix[newVertexNumber][otherVertexNumber] = false;
	}

	graphData[newVertexNumber] = value;
}

template<class Type>
bool Graph<Type> :: areConnected(int source, int target) const
{
	assert(source < size() && target < size);

	bool isEdge = false;
	isEdge = adjacentMatrix[source][target];

	return isEdge;
}

template<class Type>
Type& Graph<Type> :: operator[](int vertex)
{
	assert(vertex < size());
	return graphData[vertex];
}

template<class Type>
Type Graph<Type> :: operator[](int vertex) const
{
	assert(vertex < size());
	return graphData[vertex];
}






#endif /* MODEL_GRAPH_HPP_ */
