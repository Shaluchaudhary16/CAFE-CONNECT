Backckend work

#include <iostream>
#include <vector>
using namespace std;

class Menu {
private:
    string item;
    int price, itemNo;

public:
    Menu(int ItemNo, string Item, int Price) {
        itemNo = ItemNo;
        item = Item;
        price = Price;
    }

    string getItem() {
        return item;
    }

    int getItemNo() {
        return itemNo;
    }

    int getPrice() {
        return price;
    }
};

class Cafe {
private:
    vector<Menu> ve;

public:
    void add(int ItemNo, string Item, int Price) {
        Menu menu(ItemNo, Item, Price);
        ve.push_back(menu);
    }

    void displayMenu() {
        for (int i = 0; i < ve.size(); i++) {
            cout << ve[i].getItemNo() << ". " << ve[i].getItem() << ": " << ve[i].getPrice() << endl;
        }
    }

    void order() {
        displayMenu();

        int ord, quant;
        cout << "Enter item No for order: ";
        cin >> ord;
        cout << "Enter quantity of item: ";
        cin >> quant;

        for (int i = 0; i < ve.size(); i++) {
            if (ord == ve[i].getItemNo()) {
                int total = quant * ve[i].getPrice();
                cout << "Total bill: " << total << endl << endl;
            }
        }
    }

    void giveFeedback() {
        string feedback;
        cout << "Please provide your feedback: ";
        cin.ignore(); // Ignore previous newline character
        getline(cin, feedback);
        cout << "Thank you for your feedback!" << endl;

        // Check if feedback suggests improvement
        if (feedback.find("improve") != string::npos || feedback.find("suggest") != string::npos) {
            cout << "We appreciate your suggestion to improve! We'll take it into consideration." << endl;
        }
    }
};

class AdminPanel {
private:
    string username;
    string password;
    Cafe& cafe;

public:
    AdminPanel(Cafe& c): cafe(c) {
        // You can set username and password here
        // For simplicity, let's hardcode them
        username = "admin";
        password = "admin";
    }

    bool authenticate() {
        string inputUsername, inputPassword;
        cout << "Enter username: ";
        cin >> inputUsername;
        cout << "Enter password: ";
        cin >> inputPassword;
        return (inputUsername == username && inputPassword == password);
    }

    void manageMenu() {
        if (!authenticate()) {
            cout << "Authentication failed!" << endl;
            return;
        }

        int choice;
        cout << "1. Add item to menu" << endl;
        cout << "2. Display menu" << endl;
        cout << "3. Feedback" << endl; // Adding the feedback option
        cout << "4. Exit" << endl; // Adding the exit option
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int itemNo, price;
                string item;
                cout << "Enter item number: ";
                cin >> itemNo;
                cout << "Enter item name: ";
                cin >> item;
                cout << "Enter item price: ";
                cin >> price;
                cafe.add(itemNo, item, price);
                cout << "Item added to menu successfully!" << endl;
                break;
            }
            case 2: {
                cafe.displayMenu();
                break;
            }
            case 3: {
                cafe.giveFeedback();
                break;
            }
            case 4: // Exit option
                cout << "Exiting Admin Panel." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
};

int main() {
    Cafe cafe;
    AdminPanel admin(cafe);

    // Add some initial items to the menu
    cafe.add(1, "Coffee", 100);
    cafe.add(2, "Tea", 50);
    cafe.add(3, "Potato Chips", 50);
    cafe.add(4, "Mango Juice", 100);
    cafe.add(5, "Orange Juice", 80);
    cafe.add(6, "Strawberry Juice", 150);
    cafe.add(7, "Chicken Burger", 180);
    cafe.add(8, "Zinger Burger", 145);

    cout << "<<<<< Cafeteria Menu >>>>>" << endl << endl;
    cout << "1. User Panel" << endl;
    cout << "2. Admin Panel" << endl;
    cout << "3. Exit" << endl;
    // Adding the exit option
      
    cout << "Enter your choice: ";
    int panelChoice;
    cin >> panelChoice;
    switch (panelChoice) {
        case 1:
            cafe.order();
            break;
        case 2:
            admin.manageMenu();
            break;
        case 3: // Exit option
            return 0;
        default:
            cout << "Invalid choice!" << endl;
    }
    return 0;
}