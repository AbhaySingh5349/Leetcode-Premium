Question Link: https://leetcode.com/problems/product-price-at-a-given-date/

SQL Schema
Table: Products

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| new_price     | int     |
| change_date   | date    |
+---------------+---------+
(product_id, change_date) is the primary key of this table.
Each row of this table indicates that the price of some product was changed to a new price at some date.
 
Write an SQL query to find the prices of all products on 2019-08-16. Assume the price of all products before any change is 10.

Input: 
Products table:
+------------+-----------+-------------+
| product_id | new_price | change_date |
+------------+-----------+-------------+
| 1          | 20        | 2019-08-14  |
| 2          | 50        | 2019-08-14  |
| 1          | 30        | 2019-08-15  |
| 1          | 35        | 2019-08-16  |
| 2          | 65        | 2019-08-17  |
| 3          | 20        | 2019-08-18  |
+------------+-----------+-------------+
Output: 
+------------+-------+
| product_id | price |
+------------+-------+
| 2          | 50    |
| 1          | 35    |
| 3          | 10    |
+------------+-------+

// Approach 1: Using commom table expression
WITH cte1 as (
    SELECT distinct product_id
    FROM Products
), cte2 as (
    SELECT *, ROW_NUMBER() OVER(PARTITION BY product_id ORDER by change_date DESC) as row_num
    FROM Products
    WHERE change_date <= '2019-08-16'
)

SELECT cte1.product_id, IFNULL(cte2.new_price, 10) as price
FROM cte1 LEFT JOIN cte2 
ON cte1.product_id = cte2.product_id AND cte2.row_num = 1
      

// Approach 2: Using UNION
SELECT product_id, 10 as price
FROM Products
GROUP BY product_id
HAVING (MIN(change_date) > "2019-08-16")

UNION

SELECT p2.product_id, new_price
FROM Products p2
WHERE (p2.product_id, p2.change_date) IN(SELECT product_id, MAX(change_date)
                                         FROM Products
                                         WHERE change_date <= "2019-08-16"
                                         GROUP BY product_id
                                         )
