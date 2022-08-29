Question Link: https://leetcode.com/problems/customers-who-bought-all-products/

SQL Schema
Table: Customer

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| customer_id | int     |
| product_key | int     |
+-------------+---------+
There is no primary key for this table. It may contain duplicates.
product_key is a foreign key to Product table.
 

Table: Product

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| product_key | int     |
+-------------+---------+
product_key is the primary key column for this table.
 

Write an SQL query to report the customer ids from the Customer table that bought all the products in the Product table.

Input: 
Customer table:
+-------------+-------------+
| customer_id | product_key |
+-------------+-------------+
| 1           | 5           |
| 2           | 6           |
| 3           | 5           |
| 3           | 6           |
| 1           | 6           |
+-------------+-------------+
Product table:
+-------------+
| product_key |
+-------------+
| 5           |
| 6           |
+-------------+
Output: 
+-------------+
| customer_id |
+-------------+
| 1           |
| 3           |
+-------------+
Explanation: 
The customers who bought all the products (5 and 6) are customers with IDs 1 and 3.

// Approach 1: Using commom table expression
WITH cte as(
    SELECT customer_id, product_key
    FROM Customer 
    GROUP BY customer_id, product_key
)

SELECT customer_id 
FROM cte
GROUP BY customer_id HAVING COUNT(*) = (SELECT COUNT(*) FROM Product)
      

// Approach 2:
WITH cte as(
    SELECT customer_id, COUNT(DISTINCT product_key) as key_count
    FROM Customer 
    GROUP BY customer_id
)

SELECT customer_id 
FROM cte
WHERE key_count = (SELECT COUNT(*) FROM Product)

// Approach 3: Using Group By
SELECT customer_id
FROM customer
GROUP BY customer_id
HAVING COUNT(DISTINCT product_key) = (SELECT COUNT(*) FROM product);
