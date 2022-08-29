Question Link: https://leetcode.com/problems/sales-analysis-ii/

SQL Schema
Table: Product

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| product_id   | int     |
| product_name | varchar |
| unit_price   | int     |
+--------------+---------+
product_id is the primary key of this table.
Each row of this table indicates the name and the price of each product.
Table: Sales

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| seller_id   | int     |
| product_id  | int     |
| buyer_id    | int     |
| sale_date   | date    |
| quantity    | int     |
| price       | int     |
+-------------+---------+
This table has no primary key, it can have repeated rows.
product_id is a foreign key to the Product table.
Each row of this table contains some information about one sale.
 
Write an SQL query that reports the buyers who have bought S8 but not iPhone. Note that S8 and iPhone are products present in the Product table.

Input: 
Product table:
+------------+--------------+------------+
| product_id | product_name | unit_price |
+------------+--------------+------------+
| 1          | S8           | 1000       |
| 2          | G4           | 800        |
| 3          | iPhone       | 1400       |
+------------+--------------+------------+
Sales table:
+-----------+------------+----------+------------+----------+-------+
| seller_id | product_id | buyer_id | sale_date  | quantity | price |
+-----------+------------+----------+------------+----------+-------+
| 1         | 1          | 1        | 2019-01-21 | 2        | 2000  |
| 1         | 2          | 2        | 2019-02-17 | 1        | 800   |
| 2         | 1          | 3        | 2019-06-02 | 1        | 800   |
| 3         | 3          | 3        | 2019-05-13 | 2        | 2800  |
+-----------+------------+----------+------------+----------+-------+
Output: 
+-------------+
| buyer_id    |
+-------------+
| 1           |
+-------------+
Explanation: The buyer with id 1 bought an S8 but did not buy an iPhone. The buyer with id 3 bought both.
      

// Approach 1: Using co-related subqueries
SELECT DISTINCT(buyer_id)
FROM Sales
WHERE buyer_id IN (SELECT buyer_id
                   FROM Sales s LEFT JOIN Product p
                   ON s.product_id = p.product_id
                   WHERE p.product_name = 'S8'
                   ) 
      AND 
      buyer_id NOT IN (SELECT buyer_id
                       FROM Sales s LEFT JOIN Product p
                       ON s.product_id = p.product_id
                       WHERE p.product_name = 'iPhone'
                       )
                                           
                                           
// Approach 2: Using GROUP BY
SELECT s.buyer_id
FROM Product p JOIN Sales s
ON (p.product_id = s.product_id)
GROUP BY s.buyer_id
HAVING SUM(p.product_name = 'S8 ') > 0 AND SUM(p.product_name = 'iphone ') = 0
