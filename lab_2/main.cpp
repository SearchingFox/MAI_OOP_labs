#include <iostream>
#include <string>

#include "TNTree.h"
#include "Trapezium.h"

int main(int argc, char** argv)
{
    TNTree *tree = new TNTree();
    std::string action;

    std::cout << "Type 'h' or 'help' to get help." << std::endl;
    while (1) {
        std::cin.clear();
        std::cin.sync();
        std::cout << "> ";
        std::cin >> action;
       
        if (action == "q" || action == "quit") {
            if (tree != nullptr) {
                delete tree;
            }
            break;
        } else if (action == "i" || action == "insert") {
            size_t size_a, size_b, size_c, size_d;
            std::string parent_id, id;
            std::cout << "Enter parent id: ";
            std::cin >> parent_id;
            std::cout << "Enter node id: ";
            std::cin >> id;
            std::cout << "Enter Trapezium's sides:\n";
            if (!(std::cin >> size_a >> size_b >> size_c >> size_d)) {
                std::cout << "Incorrect value." << std::endl;
                continue;
            }
            Trapezium* n = new Trapezium(size_a, size_b, size_c, size_d);
            tree->Insert(tree, parent_id, id, *n);
            delete n;
        } else if (action == "r" || action == "Remove") {
            std::string id;
            if (!(std::cin >> id)) {
                std::cout << "Incorrect value." << std::endl;
                continue;
            }
            tree->Remove(id);
        } else if (action == "d" || action == "destroy") {
            delete tree;
            tree = new TNTree();
            std::cout << "The tree was deleted." << std::endl;
        } else if (action == "p" || action == "print") {
            if (!tree->IsEmpty()) {
                tree->PrintTree(tree->getHead(), 0);
            }
            else {
                std::cout << "The tree is empty." << std::endl;
            }
        } else if (action == "pi" || action == "printitem") {
            std::string id;
            std::cout << "Enter item id: ";
            std::cin >> id;

            tree->PrintItem(tree, id);
        } else if (action == "help" || action == "h") {
            std::cout << "'h'  or 'help'      - display the help." << std::endl;
            std::cout << "'r'  or 'Remove'    - Remove the trapezium with area s." << std::endl;
            std::cout << "'d'  or 'destroy'   - delete the tree." << std::endl;
            std::cout << "'p'  or 'print'     - output the tree." << std::endl;
            std::cout << "'i'  or 'insert'    - insert a trapezium into the tree." << std::endl;
            std::cout << "'pi' or 'printitem' - print item by id." << std::endl;
            std::cout << "'q'  or 'quit'      - exit the program." << std::endl;
        }
    }
    
    return 0;
}

