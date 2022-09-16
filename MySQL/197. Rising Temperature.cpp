Question Link: https://leetcode.com/problems/rising-temperature/

SQL Schema
Table: Weather

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| recordDate    | date    |
| temperature   | int     |
+---------------+---------+
id is the primary key for this table.
This table contains information about the temperature on a certain day.
 
Write an SQL query to find all dates' Id with higher temperatures compared to its previous dates (yesterday).

Input: 
Weather table:
+----+------------+-------------+
| id | recordDate | temperature |
+----+------------+-------------+
| 1  | 2015-01-01 | 10          |
| 2  | 2015-01-02 | 25          |
| 3  | 2015-01-03 | 20          |
| 4  | 2015-01-04 | 30          |
+----+------------+-------------+
Output: 
+----+
| id |
+----+
| 2  |
| 4  |
+----+
Explanation: 
In 2015-01-02, the temperature was higher than the previous day (10 -> 25).
In 2015-01-04, the temperature was higher than the previous day (20 -> 30).

// Approach 1: Using Join
SELECT w2.id 
FROM Weather w1 INNER JOIN Weather w2
ON w2.temperature > w1.temperature AND DATEDIFF(w2.recordDate,w1.recordDate) = 1

// Approach 2: Using sub-queries
SELECT DISTINCT a.Id
FROM Weather a,Weather b
WHERE a.Temperature > b.Temperature AND DATEDIFF(a.Recorddate,b.Recorddate) = 1
