#ifndef TNTREE_H
#define TNTREE_H

#include <string>
#include <memory>

#include "TNTreeItem.h"
#include "Trapezium.h"
#include "Rhombus.h"
#include "Pentagon.h"

class TNTree {
public:
    TNTree();
    TNTree(const TNTree& orig);
    friend std::ostream& operator<<(std::ostream& os, const TNTree& tree);

    void Insert(std::string parent_id, std::string id, std::shared_ptr<Figure> &figure);
    void Remove(std::string id);
    void PrintTree();
    void PrintItem(std::string id);
    void SetNull(std::shared_ptr<TNTreeItem> treeItem);
    std::shared_ptr<TNTreeItem> getHead();
    bool IsEmpty() const;

    virtual ~TNTree();
private:
    std::shared_ptr<TNTreeItem> head;

    std::shared_ptr<TNTreeItem> FindNode(std::shared_ptr<TNTreeItem> node, std::string id);
    void print_nodes(std::shared_ptr<TNTreeItem> treeItem, size_t num);
    void node_remove(std::shared_ptr<TNTreeItem> treeItem, std::string id);
};
#endif /* TNTREE_H */
