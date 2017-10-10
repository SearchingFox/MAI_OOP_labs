#include <cstring>

#include "Trapezium.h"
#include "Pentagon.h"
#include "Rhombus.h"

int main(int argc, char** argv)
{
    const int size = 16;
    char s[size];
    Trapezium *ptr_tr = nullptr;
    Rhombus   *ptr_rh = nullptr;
    Pentagon  *ptr_pn = nullptr;
    
    std::cout << "Use 'help' or 'h' to get help." << std::endl;
    
    for(;;) {
        std::cout << "> ";
        std::cin.getline(s, size);
        std::cin.clear();
        std::cin.sync();
        
        if (!strcmp(s, "create_trapezium") || !strcmp(s, "cr_tr")) {
            if (ptr_tr != nullptr) delete ptr_tr;
            
            std::cout << "Enter smaller base, larger base, left side and right side:" << std::endl;
            ptr_tr = new Trapezium(std::cin);
        } else if (!strcmp(s, "create_rhombus") || !strcmp(s, "cr_rh")) {
            if (ptr_rh != nullptr) delete ptr_rh;
            
            std::cout << "Enter side and smaller angle:" << std::endl;
            ptr_rh = new Rhombus(std::cin);
        } else if (!strcmp(s, "create_pentagon") || !strcmp(s, "cr_pn")) {
            if (ptr_pn != nullptr) delete ptr_pn;
            
            std::cout << "Enter side:" << std::endl;
            ptr_pn = new Pentagon(std::cin);
        } else if (!strcmp(s, "print_trapezium") || !strcmp(s, "pr_tr")) {
            if(ptr_tr == nullptr) {
                std::cout << "Trapezium doesn't exist." << std::endl;
            } else {
                ptr_tr->Print();
            }
        } else if (!strcmp(s, "print_rhombus") || !strcmp(s, "pr_rh")) {
            if(ptr_rh == nullptr) {
                std::cout << "Rhombus doesn't exist." << std::endl;
            } else {
                ptr_rh->Print();
            }
        } else if (!strcmp(s, "print_pentagon") || !strcmp(s, "pr_pn")) {
            if(ptr_pn == nullptr) {
                std::cout << "Pentagon doesn't exist." << std::endl;
            } else {
                ptr_pn->Print();
            }
        } else if (!strcmp(s, "square_trapezium") || !strcmp(s, "sq_tr")) {
            if(ptr_tr == nullptr) {
                std::cout << "Trapezium doesn't exist." << std::endl;
            } else {
                std::cout << "Square: " << ptr_tr->Square() << std::endl;
            }
        } else if (!strcmp(s, "square_rhombus") || !strcmp(s, "sq_rh")) {
            if(ptr_rh == nullptr) {
                std::cout << "Rhombus doesn't exist." << std::endl;
            } else {
                std::cout << "Square: " << ptr_rh->Square() << std::endl;
            }
        } else if (!strcmp(s, "square_pentagon") || !strcmp(s, "sq_pn")) {
            if(ptr_pn == nullptr) {
                std::cout << "Pentagon doesn't exist." << std::endl;
            } else {
                std::cout << "Square: " << ptr_pn->Square() << std::endl;
            }
        } else if (!strcmp(s, "quit") || !strcmp(s, "exit") || !strcmp(s, "q")) {
            if (ptr_tr != nullptr) {
                delete ptr_tr;
            }
            if (ptr_rh != nullptr) {
                delete ptr_rh;
            }
            if (ptr_pn != nullptr) {
                delete ptr_pn;
            }
            break;
        } else if (!strcmp(s, "help") || !strcmp(s, "h")) {
            std::cout << "Commands 'create_trapezium' and 'cr_tr' create new trapezium with your parameters." << std::endl;
            std::cout << "Commands 'create_rhombus' and 'cr_rh' create new rhombud with your parameters." << std::endl;
            std::cout << "Commands 'create_pentagon' and 'cr_pn' create new pentagon with your parameters." << std::endl;
            std::cout << "Commands 'print_trapezium' and 'pr_tr' output parameters of trapezium." << std::endl;
            std::cout << "Commands 'print_rhomb' and 'pr_rh' output parameters of rhombus."  << std::endl;
            std::cout << "Commands 'print_pentagon' and 'pr_pn' output parameters of pentagon."  << std::endl;
            std::cout << "Commands 'square_trapezium' and 'sq_tr' output square of trapezium." << std::endl;
            std::cout << "Commands 'square_rhombus' and 'sq_rh' output square of rhombus." << std::endl;
            std::cout << "Commands 'square_pentagon' and 'sq_pn' output square of pentagon." << std::endl;
            std::cout << "Commands 'quit', 'exit' and 'q' exit the program." << std::endl;
        }
    }
    return 0;
}
