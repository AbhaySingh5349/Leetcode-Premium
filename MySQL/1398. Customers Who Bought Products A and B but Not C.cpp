Question Link: https://leetcode.com/problems/customers-who-bought-products-a-and-b-but-not-c/

SQL Schema
Table: Customers

+---------------------+---------+
| Column Name         | Type    |
+---------------------+---------+
| customer_id         | int     |
| customer_name       | varchar |
+---------------------+---------+
customer_id is the primary key for this table.
customer_name is the name of the customer.
 

Table: Orders

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| order_id      | int     |
| customer_id   | int     |
| product_name  | varchar |
+---------------+---------+
order_id is the primary key for this table.
customer_id is the id of the customer who bought the product "product_name".
 
Write an SQL query to report the customer_id and customer_name of customers who bought products "A", "B" but did not buy the product "C" .

Input: 
Customers table:
+-------------+---------------+
| customer_id | customer_name |
+-------------+---------------+
| 1           | Daniel        |
| 2           | Diana         |
| 3           | Elizabeth     |
| 4           | Jhon          |
+-------------+---------------+
Orders table:
+------------+--------------+---------------+
| order_id   | customer_id  | product_name  |
+------------+--------------+---------------+
| 10         |     1        |     A         |
| 20         |     1        |     B         |
| 30         |     1        |     D         |
| 40         |     1        |     C         |
| 50         |     2        |     A         |
| 60         |     3        |     A         |
| 70         |     3        |     B         |
| 80         |     3        |     D         |
| 90         |     4        |     C         |
+------------+--------------+---------------+
Output: 
+-------------+---------------+
| customer_id | customer_name |
+-------------+---------------+
| 3           | Elizabeth     |
+-------------+---------------+
Explanation: Only the customer_id with id 3 bought the product A and B but not the product C.

// Approach : Using common table expression
WITH cte as(
    SELECT customer_id
    FROM Orders
    GROUP BY customer_id
    HAVING SUM(product_name='A')>0 AND SUM(product_name='B')>0 AND SUM(product_name='C')=0 
)

SELECT c.customer_id, c.customer_name FROM Customers c 
                                      WHERE c.customer_id IN (SELECT customer_id FROM cte)
