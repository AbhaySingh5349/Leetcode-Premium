Question Link: https://leetcode.com/problems/customer-placing-the-largest-number-of-orders/

SQL Schema
Table: Orders

+-----------------+----------+
| Column Name     | Type     |
+-----------------+----------+
| order_number    | int      |
| customer_number | int      |
+-----------------+----------+
order_number is the primary key for this table.
This table contains information about the order ID and the customer ID.

Write an SQL query to find the customer_number for the customer who has placed the largest number of orders.

Input: 
Orders table:
+--------------+-----------------+
| order_number | customer_number |
+--------------+-----------------+
| 1            | 1               |
| 2            | 2               |
| 3            | 3               |
| 4            | 3               |
+--------------+-----------------+
Output: 
+-----------------+
| customer_number |
+-----------------+
| 3               |
+-----------------+
Explanation: 
The customer with number 3 has two orders, which is greater than either customer 1 or 2 because each of them only has one order. 
So the result is customer_number 3.

// Approach 1: co-related sub-queries
SELECT customer_number 
FROM (SELECT customer_number ,COUNT(customer_number) as orders_count 
      FROM Orders 
      GROUP BY customer_number
      ) sub1 
WHERE (sub1.orders_count = ( SELECT MAX(sub2.orders_count) FROM (SELECT COUNT(customer_number) as orders_count 
                                                       FROM Orders 
                                                       GROUP BY customer_number
                                                       ) sub2)
      )
      

// Approach 2: co-related sub-queries
SELECT customer_number 
FROM Orders 
GROUP BY customer_number 
HAVING COUNT(customer_number) = (SELECT MAX(orders_count) FROM (SELECT COUNT(customer_number) as orders_count 
                                                  FROM Orders 
                                                  GROUP BY customer_number
                                                  ) sub
                  )
