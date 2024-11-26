/**
 * @brief Menu Order Application
 */

#include <iostream>
#include <map>

/* USER-DEFINED VARIABLES */
enum class MenuOption
{
    FRIES = 1,
    BRUGER,
    CHICKEN
};
enum class itemCost
{
    FRIES = 10,
    BRUGER = 25,
    CHICKEN = 18
};

class MenuOrder
{
    int orderPrice;
    std::map<std::string, int> orderedItems{
        {"FRIES", 0},
        {"BRUGER", 0},
        {"CHICKEN", 0}};

public:
    void showMenu()
    {
        std::cout << "Restaurant Menu List:-\n";
        std::cout << "  1. Fries   [10$] \n";
        std::cout << "  2. Burgers [25$] \n";
        std::cout << "  3. Chicken [18$] \n";
    }
    void selectItem()
    {
        std::cout << "Please choose your order number: ";
        int orderSelect;
        std::cin >> orderSelect;
        std::cout << "Please choose quantity: ";
        int orderQuantity;
        std::cin >> orderQuantity;

        if (orderQuantity <= 0)
        {
            std::cout << "ERROR, Wrong Quantity! \n";
            return;
        }

        switch (orderSelect)
        {
        case static_cast<int>(MenuOption::FRIES):
            orderedItems["FRIES"] = orderQuantity;
            break;
        case static_cast<int>(MenuOption::BRUGER):
            orderedItems["BRUGER"] = orderQuantity;
            break;
        case static_cast<int>(MenuOption::CHICKEN):
            orderedItems["CHICKEN"] = orderQuantity;
            break;
        default:
            std::cout << "ERROR, Wrong Selection! \n";
            break;
        }
    }
    bool exitOrder()
    {
        char mesg_order;
        std::cout << "Do you want to order another item [y/n]? ";
        std::cin >> mesg_order;
        if (mesg_order == 'Y' or mesg_order == 'y')
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    int calculatePrice()
    {
        orderPrice = (orderedItems["FRIES"] * static_cast<int>(itemCost::FRIES)) +
                     (orderedItems["BRUGER"] * static_cast<int>(itemCost::BRUGER)) +
                     (orderedItems["CHICKEN"] * static_cast<int>(itemCost::CHICKEN));
        return orderPrice;
    }
};

/* MAIN FUNCTION */
int main()
{
    MenuOrder userOrder;
    userOrder.showMenu();

    do
    {
        userOrder.selectItem();

    } while (!(userOrder.exitOrder()));

    std::cout << "Total Order Price = " << userOrder.calculatePrice() << "$ \n";

    return 0;
}

/* FUNCTION PROTOTYPE */
// std::istream &operator>>(std::istream &ip_stream, MenuOption &result);

// Operator overloading for istream "cin" to be able to read Enum Class variable
// std::istream &operator>>(std::istream &ip_stream, MenuOption &result)
// {
//     int intOption;

//     ip_stream >> intOption;
//     result = static_cast<MenuOption>(intOption);
//     return ip_stream;
// }