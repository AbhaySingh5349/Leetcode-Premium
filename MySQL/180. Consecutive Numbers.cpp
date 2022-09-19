Question Link: https://leetcode.com/problems/consecutive-numbers/

SQL Schema
Table: Logs

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| num         | varchar |
+-------------+---------+
id is the primary key for this table.
id is an autoincrement column.
 
Write an SQL query to find all numbers that appear at least three times consecutively.

Input: 
Logs table:
+----+-----+
| id | num |
+----+-----+
| 1  | 1   |
| 2  | 1   |
| 3  | 1   |
| 4  | 2   |
| 5  | 1   |
| 6  | 2   |
| 7  | 2   |
+----+-----+
Output: 
+-----------------+
| ConsecutiveNums |
+-----------------+
| 1               |
+-----------------+
Explanation: 1 is the only number that appears consecutively for at least three times.

// Approach 1: Using sub-queries
SELECT DISTINCT num as ConsecutiveNums
FROM Logs
WHERE (id + 1, num) in (SELECT * FROM Logs) and (id + 2, num) in (SELECT * FROM Logs)
