#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <ctime>
using namespace std;

class Order {
public:
    string order_id;
    string user_id;
    string order_type;
    string stock_symbol;
    int quantity;
    double price;
    time_t order_accepted_timestamp;
    string status;  // ACCEPTED, REJECTED, CANCELED
    string rejection_reason;

    Order(string order_id, string user_id, string order_type, string stock_symbol, int quantity, double price);
    void rejectOrder(const string& reason);
};

#endif
