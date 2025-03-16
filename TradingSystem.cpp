#include "TradingSystem.hpp"
#include <iostream>

void TradingSystem::register_user(string user_id, string username, string phone_number, string email_id) {
    lock_guard<mutex> lock(mtx);
    users[user_id] = User(user_id, username, phone_number, email_id);
}

void TradingSystem::place_order(Order order) {
    lock_guard<mutex> lock(mtx);

    if (order.quantity <= 0) {
        order.rejectOrder("Quantity must be greater than 0.");
    } else if (order.price <= 0) {
        order.rejectOrder("Price must be greater than 0.");
    } else if (order.order_type != "BUY" && order.order_type != "SELL") {
        order.rejectOrder("Invalid order type. Must be 'BUY' or 'SELL'.");
    } else if (order.stock_symbol.empty()) {
        order.rejectOrder("Stock symbol is required.");
    } else {
        if (order_books.find(order.stock_symbol) == order_books.end()) {
            order_books[order.stock_symbol] = new OrderBook();
        }
        order_books[order.stock_symbol]->place_order(order);
    }

    if (order.status == "REJECTED") {
        cout << "Order " << order.order_id << " rejected: " << order.rejection_reason << endl;
    }
}

void TradingSystem::cancel_order(string order_id, string stock_symbol) {
    lock_guard<mutex> lock(mtx);

    if (order_books.find(stock_symbol) != order_books.end()) {
        order_books[stock_symbol]->cancel_order(order_id);
    }
}

void TradingSystem::query_order_status(string order_id, string stock_symbol) {
    lock_guard<mutex> lock(mtx);

    if (order_books.find(stock_symbol) != order_books.end()) {
        OrderBook* order_book = order_books[stock_symbol];
        for (auto& order : order_book->get_buy_orders()) {
            if (order.order_id == order_id) {
                cout << "Order Status is " << order.status << " for Order ID: " << order_id << endl;
                return;
            }
        }
        for (auto& order : order_book->get_sell_orders()) {
            if (order.order_id == order_id) {
                cout << "Order Status is " << order.status << " for Order ID: " << order_id << endl;
                return;
            }
        }
        cout << "Order not found for Order ID: "<< order_id << endl;
    }
}

void TradingSystem::match_orders(string stock_symbol) {
    lock_guard<mutex> lock(mtx);

    if (order_books.find(stock_symbol) != order_books.end()) {
        order_books[stock_symbol]->match_orders();
    }
}

TradingSystem::~TradingSystem() {
    for (auto& entry : order_books) {
        delete entry.second;
    }
}
