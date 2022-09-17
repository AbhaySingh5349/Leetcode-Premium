Question Link: https://leetcode.com/problems/biggest-single-number/

SQL Schema
Table: MyNumbers

+-------------+------+
| Column Name | Type |
+-------------+------+
| num         | int  |
+-------------+------+
There is no primary key for this table. It may contain duplicates.
Each row of this table contains an integer.
 
A single number is a number that appeared only once in the MyNumbers table.
Write an SQL query to report the largest single number. If there is no single number, report null.

Input: 
MyNumbers table:
+-----+
| num |
+-----+
| 8   |
| 8   |
| 3   |
| 3   |
| 1   |
| 4   |
| 5   |
| 6   |
+-----+
Output: 
+-----+
| num |
+-----+
| 6   |
+-----+
Explanation: The single numbers are 1, 4, 5, and 6.
Since 6 is the largest single number, we return it.

// Approach 1: Using common table expression
WITH cte as(
    SELECT num FROM MyNumbers
    GROUP BY num
    HAVING COUNT(*)=1
)

SELECT MAX(num) as num FROM cte

// Approach 2: Using sub-queries
SELECT MAX(num) as num FROM (SELECT num FROM MyNumbers
                             GROUP BY num
                             HAVING COUNT(*)=1
                            ) as sub
