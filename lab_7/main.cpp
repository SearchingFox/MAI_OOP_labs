#include <iostream>

#include "TList.h"
#include "TTree.h"

#include "Trapezium.h"
#include "Pentagon.h"
#include "Rhombus.h"

void menu(void) {
    std::cout << "'h'  or 'help'      - display the help." << std::endl;
    std::cout << "'r'  or 'remove'    - remove the figure." << std::endl;
    std::cout << "'p'  or 'print'     - output the tree." << std::endl;
    std::cout << "'it'                - insert a trapezium into the tree." << std::endl;
    std::cout << "'ir'                - insert a rhombus into the tree." << std::endl;
    std::cout << "'ip'                - insert a pentagon into the tree." << std::endl;
    std::cout << "'q'  or 'quit'      - exit the program." << std::endl;
}

int main(void) {
  TTree<TList<Figure>, std::shared_ptr<Figure>> tree;
  int index;
  std::string action;

  std::cout << "Type 'h' or 'help' to get help." << std::endl;
    while (1) {
        std::cin.clear();
        std::cin.sync();
        std::cout << "> ";
        std::cin >> action;

        if (action == "q" || action == "quit") {
            break;
        } else if (action == "it") {
            Trapezium fig;

            std::cin >> fig;
            tree.insert(std::make_shared<Trapezium>(fig));
        } else if (action == "ir") {
            Rhombus fig;

            std::cin >> fig;
            tree.insert(std::make_shared<Rhombus>(fig));
        } else if (action == "ip") {
            Pentagon fig;

            std::cin >> fig;
            tree.insert(std::make_shared<Pentagon>(fig));
        } else if (action == "r" || action == "remove") {
            std::cout << "1 - by type\n2 - lesser than square\n";
            std::cin >> index;
            if (index == 1) {
                std::cout << "1) rhombus\n2) trapezium\n3) pentagon\n";
                std::cout << "Enter type:" << std::endl;
                std::cin >> index;
                tree.removeByType(index);
            } else if (index == 2) {
                double sqr = 0.0;
                std::cout << "Enter square:" << std::endl;
                std::cin >> sqr;
                tree.removeLesser(sqr);
            }
        } else if (action == "p" || action == "print") {
                tree.inorder();
        } else if (action == "help" || action == "h") {
                menu();
        }
    }
    return 0;
}
