#ifndef TNTREE_H
#define TNTREE_H

#include <string>
//#include <memory>

#include "TNTreeItem.h"
#include "Figure.h"
// #include "Trapezium.h"
// #include "Pentagon.h"
// #include "Rhombus.h"

template <class T>
class TNTree {
public:
    TNTree();
    TNTree(const TNTree<T>& orig);
    template <class A> friend std::ostream& operator<<(std::ostream& os, const TNTree<A>& tree);

    void Insert(std::string parent_id, std::string id, const std::shared_ptr<T> &figure);
    void Remove(std::string id);
    void PrintTree() const;
    void PrintItem(std::string id);
    void SetNull(std::shared_ptr<TNTreeItem<T>> treeItem);
    std::shared_ptr<TNTreeItem<T>> getHead();
    bool IsEmpty() const;

    virtual ~TNTree() {};
private:
    std::shared_ptr<TNTreeItem<T>> head;

    std::shared_ptr<TNTreeItem<T>> FindNode(std::shared_ptr<TNTreeItem<T>> node, std::string id);
    void print_nodes(std::shared_ptr<TNTreeItem<T>> treeItem, size_t num) const;
    void node_remove(std::shared_ptr<TNTreeItem<T>> treeItem, std::string id);
};
#endif /* TNTREE_H */
