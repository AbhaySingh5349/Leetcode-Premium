Question Link: https://leetcode.com/problems/delete-duplicate-emails/

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
 
Write an SQL query to delete all the duplicate emails, keeping only one unique email with the smallest id.
After running your script, the answer shown is the Person table. The driver will first compile and run your piece of code and then show the Person table.

Input: 
Person table:
+----+------------------+
| id | email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
| 3  | john@example.com |
+----+------------------+
Output: 
+----+------------------+
| id | email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
+----+------------------+
Explanation: john@example.com is repeated two times. We keep the row with the smallest Id = 1.
 
// WRONG APPROACH:
DELETE FROM Person 
WHERE Id NOT IN (SELECT MIN(Id) FROM Person GROUP BY Email)
GROUP BY Email

// Approach 1: Using Join
DELETE p2
FROM Person p1 JOIN Person p2
ON p1.Email = p2.Email
WHERE p1.id< p2.id;

// Approach 2: Using sub-queries
DELETE FROM Person 
WHERE Id NOT IN (SELECT * FROM (SELECT MIN(Id) FROM Person GROUP BY Email) as p);

// Approach 3:
DELETE p1 FROM Person p1, Person p2
WHERE p1.email = p2.email AND p1.id > p2.id
