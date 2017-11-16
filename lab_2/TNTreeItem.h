#ifndef TNTREEITEM_H
#define TNTREEITEM_H

#include <string>

#include "Trapezium.h"

class TNTreeItem {
public:
    TNTreeItem();
    TNTreeItem(std::string id, const Trapezium& trapezium);
    friend std::ostream& operator<<(std::ostream& os, const TNTreeItem& obj);
    
    void SetSon(TNTreeItem* son);
    void SetBrother(TNTreeItem* brother);
    TNTreeItem* GetSon();
    TNTreeItem* GetBrother();
    Trapezium GetTrapezium() const;
    std::string getId();
    
    virtual ~TNTreeItem();
private:
    Trapezium trapezium;
    std::string id;
    TNTreeItem *son;
    TNTreeItem *brother;
};

#endif  /* TNTREEITEM_H */
