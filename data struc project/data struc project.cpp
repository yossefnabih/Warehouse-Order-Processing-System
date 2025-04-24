#include <iostream>
#include <queue>
#include <string>

// Order structure to hold order details
struct Order {
    int orderId;
    std::string customerName;
    std::string item;
    int quantity;

    // Constructor for creating an order
    Order(int id, const std::string& name, const std::string& itemName, int qty)
        : orderId(id), customerName(name), item(itemName), quantity(qty) {}
};

// Function to display an order
void displayOrder(const Order& order) {
    std::cout << "Order ID: " << order.orderId << "\n"
        << "Customer Name: " << order.customerName << "\n"
        << "Item: " << order.item << "\n"
        << "Quantity: " << order.quantity << "\n";
}

int main() {
    std::queue<Order> orderQueue;
    int choice;
    int orderIdCounter = 1; // To generate unique order IDs

    do {
        std::cout << "\nWarehouse Order Processing System\n";
        std::cout << "1. Add a new order\n";
        std::cout << "2. Process an order\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string customerName, item;
            int quantity;

            std::cout << "Enter customer name: ";
            std::cin.ignore(); // Clear input buffer
            std::getline(std::cin, customerName);

            std::cout << "Enter item name: ";
            std::getline(std::cin, item);

            std::cout << "Enter quantity: ";
            std::cin >> quantity;

            Order newOrder(orderIdCounter++, customerName, item, quantity);
            orderQueue.push(newOrder);

            std::cout << "Order added successfully!\n";
            break;
        }
        case 2:
            if (!orderQueue.empty()) {
                Order currentOrder = orderQueue.front();
                orderQueue.pop();

                std::cout << "Processing the following order:\n";
                displayOrder(currentOrder);
            }
            else {
                std::cout << "No orders to process.\n";
            }
            break;
        case 3:
            std::cout << "Exiting the system.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
