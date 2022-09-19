Question Link: https://leetcode.com/problems/the-most-recent-orders-for-each-product/

SQL Schema
Table: Orders

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| order_id      | int     |
| order_date    | date    |
| customer_id   | int     |
| product_id    | int     |
+---------------+---------+
order_id is the primary key for this table.
This table contains information about the orders made by customer_id.
There will be no product ordered by the same user more than once in one day.
 

Table: Products

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| product_name  | varchar |
| price         | int     |
+---------------+---------+
product_id is the primary key for this table.
This table contains information about the Products.
 
Write an SQL query to find the most recent order(s) of each product.
Return the result table ordered by product_name in ascending order and in case of a tie by the product_id in ascending order. 
If there still a tie, order them by order_id in ascending order.

Input: 
Customers table:
+-------------+-----------+
| customer_id | name      |
+-------------+-----------+
| 1           | Winston   |
| 2           | Jonathan  |
| 3           | Annabelle |
| 4           | Marwan    |
| 5           | Khaled    |
+-------------+-----------+
Orders table:
+----------+------------+-------------+------------+
| order_id | order_date | customer_id | product_id |
+----------+------------+-------------+------------+
| 1        | 2020-07-31 | 1           | 1          |
| 2        | 2020-07-30 | 2           | 2          |
| 3        | 2020-08-29 | 3           | 3          |
| 4        | 2020-07-29 | 4           | 1          |
| 5        | 2020-06-10 | 1           | 2          |
| 6        | 2020-08-01 | 2           | 1          |
| 7        | 2020-08-01 | 3           | 1          |
| 8        | 2020-08-03 | 1           | 2          |
| 9        | 2020-08-07 | 2           | 3          |
| 10       | 2020-07-15 | 1           | 2          |
+----------+------------+-------------+------------+
Products table:
+------------+--------------+-------+
| product_id | product_name | price |
+------------+--------------+-------+
| 1          | keyboard     | 120   |
| 2          | mouse        | 80    |
| 3          | screen       | 600   |
| 4          | hard disk    | 450   |
+------------+--------------+-------+
Output: 
+--------------+------------+----------+------------+
| product_name | product_id | order_id | order_date |
+--------------+------------+----------+------------+
| keyboard     | 1          | 6        | 2020-08-01 |
| keyboard     | 1          | 7        | 2020-08-01 |
| mouse        | 2          | 8        | 2020-08-03 |
| screen       | 3          | 3        | 2020-08-29 |
+--------------+------------+----------+------------+
Explanation: 
keyboard's most recent order is in 2020-08-01, it was ordered two times this day.
mouse's most recent order is in 2020-08-03, it was ordered only once this day.
screen's most recent order is in 2020-08-29, it was ordered only once this day.
The hard disk was never ordered and we do not include it in the result table.

// Approach 1: Using common table expression
WITH cte as(
    SELECT product_id, order_id, order_date
    FROM Orders o1
    WHERE (o1.product_id, o1.order_date) IN (SELECT o2.product_id, MAX(o2.order_date) 
                                             FROM Orders o2 GROUP BY o2.product_id
                                            )
)

SELECT p.product_name, p.product_id, c.order_id, c.order_date
FROM Products p LEFT JOIN cte c
ON (p.product_id = c.product_id)
WHERE c.product_id IS NOT NULL
ORDER BY p.product_name, p.product_id, c.order_id

// Approach 2: Using window function
SELECT product_name, product_id, order_id, order_date
FROM (SELECT product_name, P.product_id, order_id, order_date, RANK() OVER (PARTITION BY product_name ORDER BY order_date DESC) rnk
      FROM Orders O INNER JOIN Products P
      On O.product_id = P.product_id
     ) temp
WHERE rnk = 1
ORDER BY product_name, product_id, order_id
