Question Link: https://leetcode.com/problems/shortest-distance-in-a-line/

SQL Schema
Table: Point

+-------------+------+
| Column Name | Type |
+-------------+------+
| x           | int  |
+-------------+------+
x is the primary key column for this table.
Each row of this table indicates the position of a point on the X-axis.
 

Write an SQL query to report the shortest distance between any two points from the Point table.

Input: 
Point table:
+----+
| x  |
+----+
| -1 |
| 0  |
| 2  |
+----+
Output: 
+----------+
| shortest |
+----------+
| 1        |
+----------+
Explanation: The shortest distance is between points -1 and 0 which is |(-1) - 0| = 1.

// Approach 1: Using common table expression
WITH cte as(
SELECT MIN(ABS(p1.x-p2.x)) as distance
FROM Point p1
JOIN Point p2
ON (p1.x != p2.x)
)

SELECT MIN(distance) as shortest FROM cte
      

// Approach 2: 
SELECT MIN(ABS(p1.x-p2.x)) as shortest
FROM Point p1
JOIN Point p2
ON (p1.x != p2.x)
