#ifndef TNTREEITEM_H
#define TNTREEITEM_H

#include <string>
#include <memory>

#include "Trapezium.h"
#include "Rhombus.h"
#include "Pentagon.h"

class TNTreeItem {
public:
    TNTreeItem();
    TNTreeItem(std::string id, const std::shared_ptr<Figure> &figure);
    friend std::ostream& operator<<(std::ostream& os, const TNTreeItem& obj);
    
    void SetSon(std::shared_ptr<TNTreeItem> son);
    void SetBrother(std::shared_ptr<TNTreeItem> brother);
    std::shared_ptr<TNTreeItem> GetSon();
    std::shared_ptr<TNTreeItem> GetBrother();
    std::shared_ptr<Figure> GetFigure() const;
    std::string getId();
    
    virtual ~TNTreeItem();
private:
    std::string id;
    std::shared_ptr<Figure> figure;

    std::shared_ptr<TNTreeItem> son;
    std::shared_ptr<TNTreeItem> brother;
};

#endif  /* TNTREEITEM_H */
