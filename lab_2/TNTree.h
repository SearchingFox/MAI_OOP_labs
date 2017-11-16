#ifndef TNTREE_H
#define TNTREE_H

#include <iostream>
#include <string>

#include "Trapezium.h"
#include "TNTreeItem.h"

class TNTree {
public:
    TNTree();
    TNTree(const TNTree& orig);

    void Insert(TNTree* tree, std::string parent_id, std::string id, Trapezium &trapezium);
    void Remove(std::string id);
    void node_remove(TNTreeItem* TNTree, std::string id);
    void PrintTree(TNTreeItem* treeit, size_t num);
    void PrintItem(TNTree* tree, std::string id);
    void SetNull(TNTreeItem* t);
    TNTreeItem* getHead();
    bool IsEmpty();

    virtual ~TNTree();
private:
    TNTreeItem* head;

    TNTreeItem* FindNode(TNTreeItem* node, std::string id);
};
#endif /* TNTREE_H */
