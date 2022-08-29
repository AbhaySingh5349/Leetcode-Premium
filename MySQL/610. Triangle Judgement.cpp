Question Link: https://leetcode.com/problems/triangle-judgement/

SQL Schema
Table: Triangle

+-------------+------+
| Column Name | Type |
+-------------+------+
| x           | int  |
| y           | int  |
| z           | int  |
+-------------+------+
(x, y, z) is the primary key column for this table.
Each row of this table contains the lengths of three line segments.

Write an SQL query to report for every three line segments whether they can form a triangle.

Input: 
Triangle table:
+----+----+----+
| x  | y  | z  |
+----+----+----+
| 13 | 15 | 30 |
| 10 | 20 | 15 |
+----+----+----+
Output: 
+----+----+----+----------+
| x  | y  | z  | triangle |
+----+----+----+----------+
| 13 | 15 | 30 | No       |
| 10 | 20 | 15 | Yes      |
+----+----+----+----------+

// Approach 1: Using flow control statement CASE
SELECT x,y,z, CASE WHEN x+y > z AND y+z > x AND z+x > Y THEN 'Yes'
                   ELSE 'No'
              END as 'triangle'
FROM Triangle 
      
// Approach 2: Using flow control statement CASE
SELECT x,y,z, CASE WHEN GREATEST(x,y,z) < x + y + z - GREATEST(x,y,z) THEN 'Yes'
                   ELSE 'No'
              END as 'triangle'
FROM Triangle 

// Approach 2: Using flow control statement IF
SELECT x,y,z, IF(x+y>z AND x+z>y AND y+z>x, 'Yes','No') as triangle
FROM Triangle
