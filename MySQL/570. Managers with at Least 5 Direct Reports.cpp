Question Link: https://leetcode.com/problems/managers-with-at-least-5-direct-reports/

SQL Schema
Table: Employee

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| department  | varchar |
| managerId   | int     |
+-------------+---------+
id is the primary key column for this table.
Each row of this table indicates the name of an employee, their department, and the id of their manager.
If managerId is null, then the employee does not have a manager.
No employee will be the manager of themself.

Write an SQL query to report the managers with at least five direct reports.

Input: 
Employee table:
+-----+-------+------------+-----------+
| id  | name  | department | managerId |
+-----+-------+------------+-----------+
| 101 | John  | A          | None      |
| 102 | Dan   | A          | 101       |
| 103 | James | A          | 101       |
| 104 | Amy   | A          | 101       |
| 105 | Anne  | A          | 101       |
| 106 | Ron   | B          | 101       |
+-----+-------+------------+-----------+
Output: 
+------+
| name |
+------+
| John |

// Approach 1: Using corelated queries
SELECT name 
FROM Employee 
WHERE id IN (SELECT managerId 
             FROM Employee 
             GROUP BY managerId 
             HAVING COUNT(managerId) >= 5)

// Approach 2: Using Self-Join
SELECT e1.name
FROM (SELECT managerId, COUNT(*) as id_count FROM Employee GROUP BY managerId) e2
JOIN Employee e1
ON (e1.id = e2.managerId AND e2.id_count>=5)
