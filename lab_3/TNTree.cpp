#include <string>
#include <iostream>

#include "TNTree.h"
#include "TNTreeItem.h"

TNTree::TNTree()
{
    head = nullptr;
}

TNTree::TNTree(const TNTree& orig)
{
    head = orig.head;
}

void TNTree::Insert(std::string parent_id, std::string id, std::shared_ptr<Figure> &figure)
{
    if (!this->head) {
        this->head = std::make_shared<TNTreeItem>(id, figure);
        return;
    }
    else {
        std::shared_ptr<TNTreeItem> parent_node = FindNode(this->head, parent_id);
        if (parent_node) {
            if (!parent_node->GetSon()) {
                parent_node->SetSon(std::make_shared<TNTreeItem>(id, figure));
            }
            else {
                std::shared_ptr<TNTreeItem> brother = parent_node->GetSon();
                while (brother->GetBrother()) {
                    brother = brother->GetBrother();
                }
                brother->SetBrother(std::make_shared<TNTreeItem>(id, figure));
            }
        }
        else {
            std::cout << "Error: no such parent_id." << std::endl;
        }
    }
}

std::shared_ptr<TNTreeItem> TNTree::FindNode(std::shared_ptr<TNTreeItem> treeItem, std::string id)
{
    if (treeItem->getId() == id) {
        return treeItem;
    }
    if (treeItem->GetSon()) {
        std::shared_ptr<TNTreeItem> tr = FindNode(treeItem->GetSon(), id);
        if (tr != nullptr) {
            return tr;
        }
    }
    if (treeItem->GetBrother()) {
        std::shared_ptr<TNTreeItem> tr = FindNode(treeItem->GetBrother(), id);
        if (tr != nullptr) {
            return tr;
        }
    }
    return nullptr;
}

bool TNTree::IsEmpty() const
{
    return head == nullptr;
}

void TNTree::node_remove(std::shared_ptr<TNTreeItem> treeItem, std::string id)
{
    if (treeItem->GetSon()) {
        if (treeItem->GetSon()->getId() == id) {
            std::shared_ptr<TNTreeItem> tr = treeItem->GetSon();
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
            std::shared_ptr<TNTreeItem> tr = treeItem->GetBrother();
            treeItem->SetBrother(treeItem->GetBrother()->GetBrother());
            SetNull(tr->GetBrother());
            return;
        }
        else {
            node_remove(treeItem->GetBrother(), id);
        }
    }
}

void TNTree::SetNull(std::shared_ptr<TNTreeItem> treeItem)
{
    treeItem = nullptr;
}

std::shared_ptr<TNTreeItem> TNTree::getHead()
{
    return this->head;
}

void TNTree::Remove(std::string id)
{
    if (head->getId() == id) {
        head = head->GetSon();
    } else {
        TNTree::node_remove(head, id);
   }
}

void TNTree::PrintTree()
{
    if (this->head != nullptr) {
        print_nodes(this->head, 0);
    }
}

void TNTree::print_nodes(std::shared_ptr<TNTreeItem> treeItem, size_t num) {
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

void TNTree::PrintItem(std::string id)
{
    std::shared_ptr<TNTreeItem> tmp = FindNode(this->head, id);
    if(tmp) {
        std::cout << tmp->getId();
        tmp->GetFigure()->Print();
    }
}

TNTree::~TNTree() {
}
