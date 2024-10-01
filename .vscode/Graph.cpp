#include "Graph.h"

template <class verType, class edgeType> Graph<verType, edgeType>::Graph(bool direct, edgeType noEdge) {
    this->directed = direct;
    this->noEdge = noEdge;
    verts = 0;
    edges = 0;
    maxVertex = DefaultNumVertex;

    verList = new verType[maxVertex];
    edgeMatrix = new edgeType *[maxVertex];
    for (int i = 0; i < maxVertex; i++) {
        edgeMatrix[i] = new edgeType[maxVertex];
    }
    for (int i = 0; i < maxVertex; i++) {
        for (int j = 0; j < maxVertex; j++) {
            if (i == j) {
                edgeMatrix[i][j] = 0;
            } else {
                edgeMatrix[i][j] = noEdge;
            }
        }
    }
}

template <class verType, class edgeType> Graph<verType, edgeType>::~Graph() {
    delete[] verList;
    for (int i; i < maxVertex; i++) {
        delete[] edgeMatrix[i];
    }
    delete[] edgeMatrix;
}

template <class verType, class edgeType> int Graph<verType, edgeType>::getVertex(verType vertex) const {
    int i;
    for (i = 0; i < verts; i++) {
        if (verList[i] == vertex) {
            return i;
        }
    }
    return -1;
}

template <class verType, class edgeType> bool Graph<verType, edgeType>::existEdge(verType vertex1, verType vertex2) const {
    int i, j;
    for (i = 0; i < verts; i++) {
        if (verList[i] == vertex1) {
            break;
        }
    }
    for (j = 0; j < verts; j++) {
        if (verList[j] == vertex2) {
            break;
        }
    }
    if ((i == verts) || (j == verts)) {
        return false;
    }
    if (i == j) {
        return false;
    }
    if (edgeMatrix[i][j] == noEdge) {
        return false;
    }
    return true;
}

template <class verType, class edgeType> void Graph<verType, edgeType>::removeVertex(verType vertex) {
    int i, j, k;
    int pos;
    for (i = 0; i < verts; i++) {
        if (verList[i] == vertex) {
            break;
        }
    }
    pos = i;
    if (pos == verts) {
        return;
    }
    for (j = pos; j < verts; j++) {
        verList[j] = verList[j + 1];
    }
    for (j = 0; j < verts; j++) {
        if ((j != pos) && (edgeMatrix[pos][j] != noEdge)) {
            edges--;
        }
    }
    if (directed) {
        for (k = 0; k < verts; k++) {
            if ((k != pos) && (edgeMatrix[k][pos] != noEdge)) {
                edges--;
            }
        }
    }
    for (j = pos; j < verts - 1; j++) {
        for (k = 0; k < verts; k++) {
            edgeMatrix[j][k] = edgeMatrix[j + 1][k];
        }
    }
    for (j = 0; j < verts; j++) {
        for (k = pos; k < verts - 1; k++) {
            edgeMatrix[j][k] = edgeMatrix[j][k + 1];
        }
    }
    verts--;
}