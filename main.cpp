#include <iostream>
#include "TradingSystem.hpp"

int main() {
    TradingSystem trading_system;

    // Register users
    trading_system.register_user("1", "Alice", "1234567890", "alice@example.com");
    trading_system.register_user("2", "Bob", "0987654321", "bob@example.com");

    // Place orders
    trading_system.place_order(Order("ORDER1", "1", "BUY", "AAPL", 100, 150.0));
    trading_system.place_order(Order("ORDER2", "2", "SELL", "AAPL", 50, 148.0));
    trading_system.place_order(Order("ORDER3", "1", "SELL", "AAPL", 50, 149.0));
    trading_system.place_order(Order("ORDER4", "2", "SELL", "AAPL", -50, 148.0));  // Invalid quantity
    trading_system.place_order(Order("ORDER5", "1", "BUY", "", 50, 149.0));  // Invalid stock symbol

    // Query order status
    trading_system.query_order_status("ORDER1", "AAPL");
    
    // Match orders (execute trades)
    trading_system.match_orders("AAPL");

    // Cancel order
    trading_system.cancel_order("ORDER3", "AAPL");
    trading_system.query_order_status("ORDER3", "AAPL");

    // Match orders again after cancel
    trading_system.match_orders("AAPL");

    return 0;
}