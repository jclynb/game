#ifndef SEGMENTTREE
#define SEGMENTTREE
#include <SDL2/SDL.h>
#include <vector>
#include "entity.h"

class SegmentTree {
    public:
    SegmentTree(std::vector<Entity*> gameobjects);
    ~SegmentTree() = default;

    int buildTree(std::vector<Entity*> gameobjects, int leftIndex, int rightIndex, int nodeIndex);
    void queryTree(Entity &obj1, int nodeIndex, Entity &obj2, std::vector<Entity> result); // FIXME: sus signature
    bool intersection(Entity &r1, Entity &r2);

    private:
    struct Node {
        Entity *gameobject;
        bool isLeaf;    
        int leftChildIndex;
        int rightChildIndex;
    };

    std::vector<Node> Nodes;
};

#endif // SEGMENTTREE