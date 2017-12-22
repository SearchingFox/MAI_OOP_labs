#include <string>
#include <iostream>

#include "Figure.h"
#include "TNTreeItem.h"

template <class T> TAllocationBlock
TNTreeItem<T>::ntreeitem_allocator(sizeof(TNTreeItem<T>), 10);

template class TNTreeItem<Figure>;
template std::ostream& operator<<(std::ostream &out, const TNTreeItem<Figure> &obj);

template <class T>
TNTreeItem<T>::TNTreeItem() {
    this->father = nullptr;
    this->brother = nullptr;
    this->son = nullptr;
    this->id = "";
}

template <class T>
TNTreeItem<T>::TNTreeItem(std::string id, const std::shared_ptr<T> &figure) {
    this->id = id;
    this->figure = figure;

    this->son = nullptr;
    this->brother = nullptr;
}

template <class T>
void TNTreeItem<T>::SetSon(std::shared_ptr<TNTreeItem<T>> son) {
    this->son = son;
}

template <class T>
void TNTreeItem<T>::SetBrother(std::shared_ptr<TNTreeItem<T>> brother) {
    this->brother = brother;
}

template <class T>
std::shared_ptr<T> TNTreeItem<T>::GetFigure() const {
    return this->figure;
}

template <class T>
std::shared_ptr<TNTreeItem<T>> TNTreeItem<T>::GetSon() {
    return this->son;
}

template <class T>
std::shared_ptr<TNTreeItem<T>> TNTreeItem<T>::GetBrother() {
    return this->brother;
}

template <class T>
std::string TNTreeItem<T>::getId() {
    return this->id;
}

template<class T>
std::shared_ptr<TNTreeItem<T>> TNTreeItem<T>::Begin() {
    if (!this->son) {
        return this->shared_from_this();
    }
    else {
        auto iter = this->son;
        while (iter->son)
            iter = iter->son;
        return iter;
    }
}

template<class T>
std::shared_ptr<TNTreeItem<T>> TNTreeItem<T>::Next() {
    if (this->brother)
        return this->brother;
    else
        //if (this->father.expired())
        return nullptr;
        //else
        //    return this->father.lock();
}

template <class T>
void *TNTreeItem<T>::operator new(size_t size)
{
    return ntreeitem_allocator.Allocate();
}

template <class T>
void TNTreeItem<T>::operator delete(void *ptr)
{
    ntreeitem_allocator.Deallocate(ptr);
}

template <class T>
std::ostream& operator<<(std::ostream& os, const TNTreeItem<T>& obj) {
    os << obj.figure << std::endl;
    return os;
}
