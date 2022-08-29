Question Link: https://leetcode.com/problems/project-employees-ii/

SQL Schema
Table: Project

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| project_id  | int     |
| employee_id | int     |
+-------------+---------+
(project_id, employee_id) is the primary key of this table.
employee_id is a foreign key to Employee table.
Each row of this table indicates that the employee with employee_id is working on the project with project_id.
 
Write an SQL query that reports all the projects that have the most employees.

Input: 
Project table:
+-------------+-------------+
| project_id  | employee_id |
+-------------+-------------+
| 1           | 1           |
| 1           | 2           |
| 1           | 3           |
| 2           | 1           |
| 2           | 4           |
+-------------+-------------+

Output: 
+-------------+
| project_id  |
+-------------+
| 1           |
+-------------+

// Approach 1: Using commom table expression
WITH cte as(
    SELECT project_id, COUNT(*) as cnt
    FROM Project
    GROUP BY project_id
)

SELECT project_id
FROM cte 
WHERE cnt IN(SELECT MAX(cnt) FROM cte)
      

// Approach 2: Using co-related subqueries
SELECT project_id
FROM Project
GROUP BY project_id
HAVING COUNT(employee_id) = (SELECT MAX(p.cnt) FROM (SELECT COUNT(employee_id) as cnt
                                                   FROM Project
                                                   GROUP BY project_id) as p
