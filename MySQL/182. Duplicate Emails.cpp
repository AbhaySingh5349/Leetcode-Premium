Question Link: https://leetcode.com/problems/duplicate-emails/

SQL Schema
Table: Person

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| email       | varchar |
+-------------+---------+
id is the primary key column for this table.
Each row of this table contains an email. The emails will not contain uppercase letters.
 
Write an SQL query to report all the duplicate emails.

Input: 
Person table:
+----+---------+
| id | email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+
Output: 
+---------+
| Email   |
+---------+
| a@b.com |
+---------+
Explanation: a@b.com is repeated two times.

// Approach 1: Using common table expression
WITH cte as(
    SELECT email, COUNT(*) as cnt FROM Person 
    GROUP BY email
)

SELECT email FROM cte WHERE cnt>1

// Approach 2: Using sub-queries
SELECT email FROM (SELECT email, COUNT(*) as cnt
                   FROM Person GROUP BY email
                  ) as sub
WHERE sub.cnt>1

// Approach 3:
SELECT email FROM Person 
GROUP BY email
HAVING COUNT(*)>1
