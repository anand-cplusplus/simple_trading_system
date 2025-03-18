# simple_trading_system
A simple Trading System using CPP

Design and implement an efficient in-memory trading system similar to a stock exchange, where registered users can place, execute and cancel trades.The system should demonstrate synchronization and concurrency in a multi-threaded environment.
Your system should be able to perform the following items:

Functional Requirements:
Your system should support the following functionalities:
 ● A registered user can place, modify, and cancel his orders.
 ● A usershould be able to query the status of his order
 ● [IMPORTANT]- The system should be able to execute trades based on matching buy and sell orders. A trade is executed when the buy and sell price of two different orders match. (Buy price greater than or equal to Sell Price). If multiple eligible orders can be matched with the same price, match the oldest orders first.
 ● [IMPORTANT]- Concurrent order placement, modification, cancellation, and execution should be handled appropriately.
 ● Thesystem should maintain an order book per symbol, which holds all the current unexecuted orders.
Your system should store at least the following mentioned details.
 ● Userdetails
 ○ UserID
 ○ UserName
 ○ PhoneNumber
 ○ Email Id
 ● Orders
 ○ OrderID
 ○ UserID
 ○ OrderType (Buy/Sell)
 ○ StockSymbol (eg: RELIANCE, WIPRO etc.)
 ○ Quantity
 ○ Price
 ○ OrderAccepted Timestamp
 ○ Status (ACCEPTED, REJECTED, CANCELED)
 ● Trades
 ○ TradeID
 ○ TradeType (Buy/Sell)
 ○ BuyerOrder Id
 ○ Seller Order Id
○ StockSymbol
 ○ Quantity
 ○ Price
 ○ TradeTimestamp
 
Additional functionality, but not compulsory [implement if time permits]: 
● Implement trade expiry. A trade should be automatically canceled if that trade is not executed within a specific time.

Expectation:
 ● Yourcode should be executable (at worst partial running would work) & should be clean.
 ● Yourcode should be adequately refactored, and exceptions should be gracefully handled.
 ● Yourcode should store all the attributes explained under the "Stores" section.
 ● Yourcode should cover all the functionality in the "Supports" section.
 ● Ifyou get extra time, you can code for " Additional functionality, but not compulsory." This will get you extra credit.
 
Guidelines:
 ● Youdon't have to build the user registration part. Consider some dummy users registered and use those in the entire system.
 ● Youshould use the in-memory data structure of your preferred language to store the data but have the right abstractions so that other persistent stores can be plugged in.
Evaluation criteria:
 ● Executable code.
 ● Codereadability and testability
 ● Refactored code
 ● Abstraction
 ● Object-Oriented concepts.
 ● Language proficiency.
