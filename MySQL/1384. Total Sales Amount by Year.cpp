Question Link: https://leetcode.com/problems/total-sales-amount-by-year/

SQL Schema
Table: Product

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| product_name  | varchar |
+---------------+---------+
product_id is the primary key for this table.
product_name is the name of the product.
 

Table: Sales

+---------------------+---------+
| Column Name         | Type    |
+---------------------+---------+
| product_id          | int     |
| period_start        | date    |
| period_end          | date    |
| average_daily_sales | int     |
+---------------------+---------+
product_id is the primary key for this table. 
period_start and period_end indicate the start and end date for the sales period, and both dates are inclusive.
The average_daily_sales column holds the average daily sales amount of the items for the period.
The dates of the sales years are between 2018 to 2020.
 
Write an SQL query to report the total sales amount of each item for each year, with corresponding product_name, product_id, product_name, and report_year.
Return the result table ordered by product_id and report_year.

Input: 
Product table:
+------------+--------------+
| product_id | product_name |
+------------+--------------+
| 1          | LC Phone     |
| 2          | LC T-Shirt   |
| 3          | LC Keychain  |
+------------+--------------+
Sales table:
+------------+--------------+-------------+---------------------+
| product_id | period_start | period_end  | average_daily_sales |
+------------+--------------+-------------+---------------------+
| 1          | 2019-01-25   | 2019-02-28  | 100                 |
| 2          | 2018-12-01   | 2020-01-01  | 10                  |
| 3          | 2019-12-01   | 2020-01-31  | 1                   |
+------------+--------------+-------------+---------------------+
Output: 
+------------+--------------+-------------+--------------+
| product_id | product_name | report_year | total_amount |
+------------+--------------+-------------+--------------+
| 1          | LC Phone     |    2019     | 3500         |
| 2          | LC T-Shirt   |    2018     | 310          |
| 2          | LC T-Shirt   |    2019     | 3650         |
| 2          | LC T-Shirt   |    2020     | 10           |
| 3          | LC Keychain  |    2019     | 31           |
| 3          | LC Keychain  |    2020     | 31           |
+------------+--------------+-------------+--------------+
Explanation: 
LC Phone was sold for the period of 2019-01-25 to 2019-02-28, and there are 35 days for this period. Total amount 35*100 = 3500. 
LC T-shirt was sold for the period of 2018-12-01 to 2020-01-01, and there are 31, 365, 1 days for years 2018, 2019 and 2020 respectively.
LC Keychain was sold for the period of 2019-12-01 to 2020-01-31, and there are 31, 31 days for years 2019 and 2020 respectively.

// Approach 1: Using Recursive commom table expression
WITH RECURSIVE years as (
    # Anchor
    SELECT 2018 as sales_year
    
    UNION
    
    # Recursive
    SELECT sales_year + 1
    FROM years
    WHERE sales_year < 2020
)

SELECT s.product_id, p.product_name, CONVERT(y.sales_year, CHAR) as report_year,
       s.average_daily_sales * (DATEDIFF(
       CASE WHEN YEAR(s.period_end) > y.sales_year THEN concat_ws('-', y.sales_year, '12-31') ELSE s.period_end END,
       CASE WHEN YEAR(s.period_start) < y.sales_year THEN concat_ws('-', y.sales_year, '01-01') ELSE s.period_start END
       ) + 1) as total_amount
FROM Sales s
    JOIN years y ON y.sales_year BETWEEN YEAR(s.period_start) AND YEAR(s.period_end)
    JOIN Product p ON p.product_id = s.product_id
ORDER BY product_id, report_year
      

// Approach 2: Using UNION
SELECT a.product_id, b.product_name, a.report_year, a.total_amount
FROM (
    SELECT product_id, '2018' AS report_year,
           average_daily_sales * (DATEDIFF(LEAST(period_end, '2018-12-31'), GREATEST(period_start, '2018-01-01'))+1) AS total_amount
    FROM Sales
    WHERE YEAR(period_start)<=2018 AND YEAR(period_end)>=2018

    UNION ALL

    SELECT product_id, '2019' AS report_year,
           average_daily_sales * (DATEDIFF(LEAST(period_end, '2019-12-31'), GREATEST(period_start, '2019-01-01'))+1) AS total_amount
    FROM Sales
    WHERE YEAR(period_start)<=2019 AND YEAR(period_end)>=2019

    UNION ALL

    SELECT product_id, '2020' AS report_year,
           average_daily_sales * (DATEDIFF(LEAST(period_end, '2020-12-31'), GREATEST(period_start, '2020-01-01'))+1) AS total_amount
    FROM Sales
    WHERE YEAR(period_start)<=2020 AND YEAR(period_end)>=2020
) a
LEFT JOIN Product b
ON a.product_id = b.product_id
ORDER BY a.product_id, a.report_year
