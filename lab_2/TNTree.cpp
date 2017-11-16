#include <string>

#include "TNTree.h"
#include "TNTreeItem.h"

TNTree::TNTree() {
    head = nullptr;
}

TNTree::TNTree(const TNTree& orig) {
    head = orig.head;
}

void TNTree::Insert(TNTree* tree, std::string parent_id, std::string id, Trapezium &trapezium) {
    if (!tree->head) { 
        tree->head = new TNTreeItem(id, trapezium);
        return;
    }
    else {
        TNTreeItem *parent_node = FindNode(tree->head, parent_id);
        if (parent_node) {
            if (!parent_node->GetSon()) {
                parent_node->SetSon(new TNTreeItem(id, trapezium));
            }
            else {
                TNTreeItem *brother = parent_node->GetSon();
                while (brother->GetBrother()) {
                    brother = brother->GetBrother();
                }
                brother->SetBrother(new TNTreeItem(id, trapezium));
            }
        }
        else {
            std::cout << "Error: no such parent_id." << '\n';
        }
    }
}

TNTreeItem* TNTree::FindNode(TNTreeItem* treeItem, std::string id) {
    if (treeItem->getId() == id) {
        return treeItem;
    }
    if (treeItem->GetSon()) {
        TNTreeItem* tr = FindNode(treeItem->GetSon(), id);
        if (tr != nullptr) {
            return tr;
        }
    }
    if (treeItem->GetBrother()) {
        TNTreeItem* tr = FindNode(treeItem->GetBrother(), id);
        if (tr != nullptr) {
            return tr;
        }
    }
    return nullptr;
}

bool TNTree::IsEmpty() {
    return head == nullptr;
}

void TNTree::node_remove(TNTreeItem* treeItem, std::string id) {
    if (treeItem->GetSon()) {
        if (treeItem->GetSon()->getId() == id) {
            TNTreeItem *tr = treeItem->GetSon();
            treeItem->SetSon(treeItem->GetSon()->GetBrother());
            SetNull(tr->GetBrother());// = nullptr;
            delete tr;
            return;
        }
        else {
            node_remove(treeItem->GetSon(), id);
        }
    }
    if (treeItem->GetBrother()) {
        if (treeItem->GetBrother()->getId() == id) {
            TNTreeItem *tr = treeItem->GetBrother();
            treeItem->SetBrother(treeItem->GetBrother()->GetBrother());
            SetNull(tr->GetBrother());// = nullptr;
            delete tr;
            return;
        }
        else {
            node_remove(treeItem->GetBrother(), id);
        }
    }
}

void TNTree::SetNull(TNTreeItem* t)
{
    t = nullptr;
}

TNTreeItem* TNTree::getHead()
{
    return this->head;
}

void TNTree::Remove(std::string id)
{
    if (head->getId() == id) {
        //std::cout << "*";
        //TNTreeItem* tr = 
        head = head->GetSon();
        //head = tr;
        //delete tr;
    } else {
        TNTree::node_remove(head, id);
   }
}

void TNTree::PrintTree(TNTreeItem* treeItem, size_t num) {
    if (treeItem) {
        for (int i = 0; i < num; ++i) {
            printf("\t");
        }
        std::cout << treeItem->getId()<< '\n';
        if (treeItem->GetSon()) {
            PrintTree(treeItem->GetSon(), num + 1);
        }
        if (treeItem->GetBrother()) {
            PrintTree(treeItem->GetBrother(), num);
        }
    }
}

void TNTree::PrintItem(TNTree* tree, std::string id)
{
    TNTreeItem* tmp = FindNode(tree->head, id);
    if(tmp) {
        std::cout << tmp->getId();
        tmp->GetTrapezium().Print();
    }
    delete tmp;
}



TNTree::~TNTree() {
    delete head;
}
