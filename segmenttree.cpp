#include <iostream>
#include <vector>
#include "segmenttree.h"

SegmentTree::SegmentTree(std::vector<Entity*> gameobjects) {
    // tree.resize(4 * n);
    buildTree(gameobjects, 0, gameobjects.size() - 1, 0);
}

int SegmentTree::buildTree(std::vector<Entity*> gameobjects, int leftIndex, int rightIndex, int nodeIndex) {
    Nodes.push_back(Node());

    if (leftIndex == rightIndex) {
        // leaf node
        Nodes[nodeIndex].gameobject = gameobjects[leftIndex];
        Nodes[nodeIndex].isLeaf = true;
    } else {
        // non-leaf node
        int midIndex = (leftIndex + rightIndex) / 2;
        int leftChildIndex = buildTree(gameobjects, leftIndex, midIndex, nodeIndex*2+1);
        int rightChildIndex = buildTree(gameobjects, midIndex+1, rightIndex, nodeIndex*2+2);
        SDL_UnionRect(&Nodes[leftChildIndex].gameobject->rect, &Nodes[rightChildIndex].gameobject->rect, &Nodes[nodeIndex].gameobject->rect);
        Nodes[nodeIndex].isLeaf = false;
        Nodes[nodeIndex].leftChildIndex = leftChildIndex;
        Nodes[nodeIndex].rightChildIndex = rightChildIndex;
        }

    return nodeIndex;
}

bool SegmentTree::intersection(Entity &r1, Entity &r2) {
  SDL_Rect *r1p = &r1.rect;
  SDL_Rect *r2p = &r2.rect;
  return !(r2p->x > (r1p->x + r1p->w) ||
           (r2p->x + r2p->w) < r1p->x ||
           r2p->y > (r1p->y + r1p->h) ||
           (r2p->y + r2p->h) < r1p->y);
}

std::vector<Entity*> SegmentTree::queryTree(Entity &obj1) {
    std::vector<Entity*> result;
    if (intersection(rect, obj2.rect)) {
        if (Nodes[nodeIndex].isLeaf) {
            result.push_back(Nodes[nodeIndex].gameobject);
        } else {
            queryTree(rect, nodeIndex*2+1, Nodes[Nodes[nodeIndex].leftChildIndex].gameobject, result);
            queryTree(rect, nodeIndex*2+2, Nodes[Nodes[nodeIndex].rightChildIndex].gameobject, result);
        }
    }  
};