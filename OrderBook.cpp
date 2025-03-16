#include "OrderBook.hpp"
#include <iostream>

void OrderBook::place_order(Order order) {
    lock_guard<mutex> lock(mtx);  // Lock to ensure thread-safety

    if (order.order_type == "BUY") {
        buy_orders.push_back(order);
    } else if (order.order_type == "SELL") {
        sell_orders.push_back(order);
    }
}

void OrderBook::cancel_order(string order_id) {
    lock_guard<mutex> lock(mtx);

    // Cancel in buy orders
    for (auto& order : buy_orders) {
        if (order.order_id == order_id) {
            order.status = "CANCELED";
            return;
        }
    }

    // Cancel in sell orders
    for (auto& order : sell_orders) {
        if (order.order_id == order_id) {
            order.status = "CANCELED";
            return;
        }
    }
}

void OrderBook::match_orders() {
    lock_guard<mutex> lock(mtx);

    while (!buy_orders.empty() && !sell_orders.empty()) {
        Order& buy_order = buy_orders.front();
        Order& sell_order = sell_orders.front();

        // Match orders if buy price >= sell price
        if (buy_order.price >= sell_order.price) {
            // Create a trade
            cout << "Trade Executed: "
                 << "BUY Order ID: " << buy_order.order_id << " and SELL Order ID: " << sell_order.order_id
                 << " for " << min(buy_order.quantity, sell_order.quantity) << " shares at price: " << sell_order.price << endl;

            // Update quantities
            int quantity_traded = min(buy_order.quantity, sell_order.quantity);
            buy_order.quantity -= quantity_traded;
            sell_order.quantity -= quantity_traded;

            // Remove fully executed orders
            if (buy_order.quantity == 0) {
                buy_orders.pop_front();
            }
            if (sell_order.quantity == 0) {
                sell_orders.pop_front();
            }
        } else {
            break;
        }
    }
}

deque<Order>& OrderBook::get_buy_orders() {
    return buy_orders;
}

deque<Order>& OrderBook::get_sell_orders() {
    return sell_orders;
}
