#ifndef TNTREEITEM_H
#define TNTREEITEM_H

#include <string>
#include <memory>

#include "TIterator.h"

// #include "Trapezium.h"
// #include "Rhombus.h"
// #include "Pentagon.h"

template <class T> class TNTree;

template <class T>
class TNTreeItem : public std::enable_shared_from_this<TNTreeItem<T>>{
public:
    TNTreeItem();
    TNTreeItem(std::string id, const std::shared_ptr<T> &figure);
    template <class A> friend std::ostream& operator<<(std::ostream& os, const TNTreeItem<A> &obj);
    
    void SetSon(std::shared_ptr<TNTreeItem<T>> son);
    void SetBrother(std::shared_ptr<TNTreeItem<T>> brother);
    std::shared_ptr<TNTreeItem<T>> GetSon();
    std::shared_ptr<TNTreeItem<T>> GetBrother();
    std::shared_ptr<T> GetFigure() const;
    std::string getId();

    std::shared_ptr<TNTreeItem<T>> Begin();
    std::shared_ptr<TNTreeItem<T>> Next();
    
    virtual ~TNTreeItem() {};
private:
    std::string id;
    std::shared_ptr<T> figure;

    std::shared_ptr<TNTreeItem<T>> son;
    std::shared_ptr<TNTreeItem<T>> brother;
    //std::shared_ptr<TNTreeItem<T>> father;    
};

#endif  /* TNTREEITEM_H */
