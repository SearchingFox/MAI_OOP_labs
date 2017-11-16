#include <iostream>
#include <string>

#include "TNTreeItem.h"

TNTreeItem::TNTreeItem() {
    this->brother = nullptr;
    this->son = nullptr;
    this->id = "";
}

TNTreeItem::TNTreeItem(std::string id, const std::shared_ptr<Figure> &figure) {
    this->figure = figure;
    this->brother = nullptr;
    this->son = nullptr;
    this->id = id;
}

void TNTreeItem::SetSon(std::shared_ptr<TNTreeItem> son) {
    this->son = son;
}

void TNTreeItem::SetBrother(std::shared_ptr<TNTreeItem> brother) {
    this->brother = brother;
}

std::shared_ptr<Figure> TNTreeItem::GetFigure() const {
    return this->figure;
}

std::shared_ptr<TNTreeItem> TNTreeItem::GetSon() {
    return this->son;
}

std::shared_ptr<TNTreeItem> TNTreeItem::GetBrother() {
    return this->brother;
}

std::string TNTreeItem::getId() {
    return this->id;
}

std::ostream& operator<<(std::ostream& os, const TNTreeItem& obj) {
    os << obj.figure << std::endl;
    return os;
}

TNTreeItem::~TNTreeItem() {
    //delete brother;
    //delete son;
}
