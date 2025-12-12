#include<iostream>
#include<string>
#include "Invoice.h"

using namespace std;

int main(){
    Invoice product;
    string input;
    int number;

    cout << "Enter product number: " << endl;
    cin >> input;
    product.setPartNumber(input);
    cout << "Enter description: " << endl;
    cin >> input;
    product.setDescription(input);
    cout << "Enter quantity: " << endl;
    cin >> number;
    product.setQuantity(number);
    cout << "Enter price: " << endl;
    cin >> number;
    product.setPrice(number);

    cout << "Product number: " 
         << product.getPartNumber() << endl;
    cout << "Description: " 
         << product.getDescription() << endl;
    cout << "Price per unit: " 
         << product.getPrice() << endl;
    cout << "Quantity: " 
         << product.getQuantity() << endl;
    cout << "Total price: " 
         << product.getInvoiceAmount() << endl;

}
