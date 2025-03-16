#ifndef TRADINGSYSTEM_H
#define TRADINGSYSTEM_H

#include <unordered_map>
#include <string>
#include "User.hpp"
#include "OrderBook.hpp"
#include <mutex>
using namespace std;

class TradingSystem {
private:
    unordered_map<string, User> users;
    unordered_map<string, OrderBook*> order_books;  // Use pointers to avoid copying OrderBook
    mutex mtx;  // Mutex for thread-safety

public:
    void register_user(string user_id, string username, string phone_number, string email_id);
    void place_order(Order order);
    void cancel_order(string order_id, string stock_symbol);
    void query_order_status(string order_id, string stock_symbol);
    void match_orders(string stock_symbol);
    ~TradingSystem();
};

#endif
