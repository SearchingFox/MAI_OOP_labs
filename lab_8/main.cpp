#include <iostream>

#include "TList.h"

#include "Trapezium.h"
#include "Rhombus.h"
#include "Pentagon.h"

void menu(void) {
    std::cout << "it    insert trapezium" << std::endl;
    std::cout << "ir    insert rhombus" << std::endl;
    std::cout << "ip    insert pentagon" << std::endl;
    std::cout << "p     print" << std::endl;
    std::cout << "s     sort" << std::endl;
    std::cout << "d     delete item" << std::endl;
    std::cout << "q     quit" << std::endl;
}

int main(void) {
    TList<Figure> list;
    int index;
    std::string action;
    
    menu();
    while (1) {
        std::cin.clear();
        std::cin.sync();
        std::cout << "> ";
        std::cin >> action;

        if (action == "q" || action == "quit") {
            break;
        } else if (action == "it") {
            Trapezium fig;

            std::cin >> fig >> index;
            list.Push(std::make_shared<Trapezium>(fig), index);
        } else if (action == "ir") {
            Rhombus fig;

            std::cin >> fig >> index;
            list.Push(std::make_shared<Rhombus>(fig), index);
        } else if (action == "ip") {
            Pentagon fig;

            std::cin >> fig >> index;
            list.Push(std::make_shared<Pentagon>(fig), index);
        } else if (action == "s") {
            std::cout << "1 regular sort\n2 parallel sort\n";
            std::cin >> index;
            if (index == 1) {
                list.sort();
            } else if (index == 2) {
                list.parallelSort();
            } 
        } else if (action == "p") {
            for (const auto& i : list) {
                i->Print();
            }
        } else if (action == "d") {
            std::cout << "Enter index of item:" << std::endl;
            std::cin >> index;
            if (list.Pop(index))
                std::cout << "Item was removed" << std::endl;
            else
                std::cout << "Item was not removed" << std::endl;
        }
    }

    return 0;
}