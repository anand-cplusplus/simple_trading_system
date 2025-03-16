#include "Order.hpp"
#include <ctime>

Order::Order(string order_id, string user_id, string order_type, string stock_symbol, int quantity, double price)
    : order_id(order_id), user_id(user_id), order_type(order_type), stock_symbol(stock_symbol),
      quantity(quantity), price(price), status("ACCEPTED"),  rejection_reason("") {
    order_accepted_timestamp = time(0);  // Current timestamp
}

void Order::rejectOrder(const string& reason) {
  status = "REJECTED";
  rejection_reason = reason;
}