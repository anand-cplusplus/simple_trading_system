#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <deque>
#include <string>
#include "Order.hpp"
#include <mutex>
using namespace std;

class OrderBook {
private:
    deque<Order> buy_orders;
    deque<Order> sell_orders;
    mutex mtx;  // Mutex for thread-safety

public:
    void place_order(Order order);
    void cancel_order(string order_id);
    void match_orders();
    deque<Order>& get_buy_orders();
    deque<Order>& get_sell_orders();
};

#endif
