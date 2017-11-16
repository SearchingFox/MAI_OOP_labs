#include <iostream>
#include <string>

#include "TNTreeItem.h"
#include "Trapezium.h"

TNTreeItem::TNTreeItem() {
    this->brother = nullptr;
    this->son = nullptr;
    this->id = "";
}

TNTreeItem::TNTreeItem(std::string id, const Trapezium& trapezium) {
    this->trapezium = trapezium;
    this->brother = nullptr;
    this->son = nullptr;
    this->id = id;
}

void TNTreeItem::SetSon(TNTreeItem* son) {
    this->son = son;
}

void TNTreeItem::SetBrother(TNTreeItem* brother) {
    this->brother = brother;
}

// double TNTreeItem::Square() {
//     return trapezium.Square();
// }

Trapezium TNTreeItem::GetTrapezium() const {
    return this->trapezium;
}

TNTreeItem* TNTreeItem::GetSon() {
    return this->son;
}

TNTreeItem* TNTreeItem::GetBrother() {
    return this->brother;
}

std::string TNTreeItem::getId() {
    return this->id;
}

std::ostream& operator<<(std::ostream& os, const TNTreeItem& obj) {
    os << obj.trapezium << std::endl;
    return os;
}

TNTreeItem::~TNTreeItem() {
    delete brother;
    delete son;
}
