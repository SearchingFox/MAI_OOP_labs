#include <string>
#include <memory>
#include <iostream>

#include "TNTree.h"
#include "TNTreeItem.h"

template class TNTree<Figure>;
template std::ostream& operator<<(std::ostream &os, const TNTree<Figure> &obj);

template <class T>
TNTree<T>::TNTree()
{
    head = nullptr;
}

template <class T>
TNTree<T>::TNTree(const TNTree<T>& orig)
{
    head = orig.head;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const TNTree<T>& tree) {
    tree.PrintTree();
    os << "";
    return os;
}

template <class T>
void TNTree<T>::Insert(std::string parent_id, std::string id, const std::shared_ptr<T> &figure)
{
    if (!this->head) {
        this->head = std::make_shared<TNTreeItem<T>>(id, figure);
        return;
    }
    else {
        std::shared_ptr<TNTreeItem<T>> parent_node = FindNode(this->head, parent_id);
        if (parent_node) {
            if (!parent_node->GetSon()) {
                parent_node->SetSon(std::make_shared<TNTreeItem<T>>(id, figure));
            }
            else {
                std::shared_ptr<TNTreeItem<T>> brother = parent_node->GetSon();
                while (brother->GetBrother()) {
                    brother = brother->GetBrother();
                }
                brother->SetBrother(std::make_shared<TNTreeItem<T>>(id, figure));
            }
        }
        else {
            std::cout << "Error: no such parent_id." << std::endl;
        }
    }
}

template <class T>
std::shared_ptr<TNTreeItem<T>> TNTree<T>::FindNode(std::shared_ptr<TNTreeItem<T>> treeItem, std::string id)
{
    if (treeItem->getId() == id) {
        return treeItem;
    }
    if (treeItem->GetSon()) {
        std::shared_ptr<TNTreeItem<T>> tr = FindNode(treeItem->GetSon(), id);
        if (tr != nullptr) {
            return tr;
        }
    }
    if (treeItem->GetBrother()) {
        std::shared_ptr<TNTreeItem<T>> tr = FindNode(treeItem->GetBrother(), id);
        if (tr != nullptr) {
            return tr;
        }
    }
    return nullptr;
}

template <class T>
bool TNTree<T>::IsEmpty() const
{
    return head == nullptr;
}

template <class T>
void TNTree<T>::node_remove(std::shared_ptr<TNTreeItem<T>> treeItem, std::string id)
{
    if (treeItem->GetSon()) {
        if (treeItem->GetSon()->getId() == id) {
            std::shared_ptr<TNTreeItem<T>> tr = treeItem->GetSon();
            treeItem->SetSon(treeItem->GetSon()->GetBrother());
            SetNull(tr->GetBrother());
            return;
        }
        else {
            node_remove(treeItem->GetSon(), id);
        }
    }
    if (treeItem->GetBrother()) {
        if (treeItem->GetBrother()->getId() == id) {
            std::shared_ptr<TNTreeItem<T>> tr = treeItem->GetBrother();
            treeItem->SetBrother(treeItem->GetBrother()->GetBrother());
            SetNull(tr->GetBrother());
            return;
        }
        else {
            node_remove(treeItem->GetBrother(), id);
        }
    }
}

template <class T>
void TNTree<T>::SetNull(std::shared_ptr<TNTreeItem<T>> treeItem)
{
    treeItem = nullptr;
}

template <class T>
std::shared_ptr<TNTreeItem<T>> TNTree<T>::getHead()
{
    return this->head;
}

template <class T>
void TNTree<T>::Remove(std::string id)
{
    if (head->getId() == id) {
        head = head->GetSon();
    } else {
        TNTree<T>::node_remove(head, id);
   }
}

template <class T>
void TNTree<T>::PrintTree() const
{
    if (this->head != nullptr) {
        print_nodes(this->head, 0);
    }
}

template <class T>
void TNTree<T>::print_nodes(std::shared_ptr<TNTreeItem<T>> treeItem, size_t num) const {
    if (treeItem) {
        for (int i = 0; i < num; ++i) {
            printf("\t");
        }
        std::cout << treeItem->getId()<< '\n';
        if (treeItem->GetSon()) {
            print_nodes(treeItem->GetSon(), num + 1);
        }
        if (treeItem->GetBrother()) {
            print_nodes(treeItem->GetBrother(), num);
        }
    }
}

template <class T>
void TNTree<T>::PrintItem(std::string id)
{
    std::shared_ptr<TNTreeItem<T>> tmp = FindNode(this->head, id);
    if(tmp) {
        std::cout << tmp->getId();
        tmp->GetFigure()->Print();
    }
}
