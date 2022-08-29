Question Link: https://leetcode.com/problems/sales-analysis-i/

SQL Schema
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
 

Write an SQL query that reports the best seller by total sales price, If there is a tie, report them all.

Input: 
Sales table:
+-----------+------------+----------+------------+----------+-------+
| seller_id | product_id | buyer_id | sale_date  | quantity | price |
+-----------+------------+----------+------------+----------+-------+
| 1         | 1          | 1        | 2019-01-21 | 2        | 2000  |
| 1         | 2          | 2        | 2019-02-17 | 1        | 800   |
| 2         | 2          | 3        | 2019-06-02 | 1        | 800   |
| 3         | 3          | 4        | 2019-05-13 | 2        | 2800  |
+-----------+------------+----------+------------+----------+-------+
Output: 
+-------------+
| seller_id   |
+-------------+
| 1           |
| 3           |
+-------------+
Explanation: Both sellers with id 1 and 3 sold products with the most total price of 2800.

// Approach 1: Using commom table expression
WITH cte as(
    SELECT seller_id, SUM(price) as total_sales
    FROM Sales
    GROUP BY seller_id
)

SELECT seller_id 
FROM cte
WHERE total_sales = (SELECT MAX(total_sales) FROM cte)
      

// Approach 2: Using co-related subqueries
SELECT seller_id FROM Sales
                 GROUP BY seller_id
                 HAVING SUM(PRICE) >= ALL (SELECT SUM(price)
                                           FROM Sales
                                           GROUP BY seller_id
                                           )
                                           
                                           
// Approach 3: Using co-related subqueries
SELECT seller_id FROM Sales
                 GROUP BY seller_id
                 HAVING SUM(price) = (SELECT SUM(price)
                                             FROM sales
                                             GROUP BY seller_id
                                             ORDER BY SUM(price) desc
                                             LIMIT 1
                                      )
