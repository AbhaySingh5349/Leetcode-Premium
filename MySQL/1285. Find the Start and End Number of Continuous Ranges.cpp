Question Link: https://leetcode.com/problems/find-the-start-and-end-number-of-continuous-ranges/

SQL Schema
Table: Logs

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| log_id        | int     |
+---------------+---------+
log_id is the primary key for this table.
Each row of this table contains the ID in a log Table.
 
Write an SQL query to find the start and end number of continuous ranges in the table Logs.

Return the result table ordered by start_id.

Input: 
Logs table:
+------------+
| log_id     |
+------------+
| 1          |
| 2          |
| 3          |
| 7          |
| 8          |
| 10         |
+------------+
Output: 
+------------+--------------+
| start_id   | end_id       |
+------------+--------------+
| 1          | 3            |
| 7          | 8            |
| 10         | 10           |
+------------+--------------+
Explanation: 
The result table should contain all ranges in table Logs.
From 1 to 3 is contained in the table.
From 4 to 6 is missing in the table
From 7 to 8 is contained in the table.
Number 9 is missing from the table.
Number 10 is contained in the table.

// Approach 1: Using commom table expression
WITH cte as(
    SELECT log_id, log_id-ROW_NUMBER() OVER (ORDER BY log_id) as diff
    FROM Logs
)

SELECT MIN(log_id) as start_id, MAX(log_id) as end_id 
FROM cte
GROUP BY diff
      

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
