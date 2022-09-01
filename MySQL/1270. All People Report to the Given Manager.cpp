Question Link: https://leetcode.com/problems/all-people-report-to-the-given-manager/

SQL Schema
Table: Employees

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| employee_id   | int     |
| employee_name | varchar |
| manager_id    | int     |
+---------------+---------+
employee_id is the primary key for this table.
Each row of this table indicates that the employee with ID employee_id and name employee_name reports his work to his/her direct manager with manager_id
The head of the company is the employee with employee_id = 1.
 

Write an SQL query to find employee_id of all employees that directly or indirectly report their work to the head of the company.

The indirect relation between managers will not exceed three managers as the company is small.

Input: 
Employees table:
+-------------+---------------+------------+
| employee_id | employee_name | manager_id |
+-------------+---------------+------------+
| 1           | Boss          | 1          |
| 3           | Alice         | 3          |
| 2           | Bob           | 1          |
| 4           | Daniel        | 2          |
| 7           | Luis          | 4          |
| 8           | Jhon          | 3          |
| 9           | Angela        | 8          |
| 77          | Robert        | 1          |
+-------------+---------------+------------+
Output: 
+-------------+
| employee_id |
+-------------+
| 2           |
| 77          |
| 4           |
| 7           |
+-------------+
Explanation: 
The head of the company is the employee with employee_id 1.
The employees with employee_id 2 and 77 report their work directly to the head of the company.
The employee with employee_id 4 reports their work indirectly to the head of the company 4 --> 2 --> 1. 
The employee with employee_id 7 reports their work indirectly to the head of the company 7 --> 4 --> 2 --> 1.
The employees with employee_id 3, 8, and 9 do not report their work to the head of the company directly or indirectly. 

// Approach 1: Using commom table expression

WITH cte as(
    SELECT e1.employee_id, e2.manager_id // storing manger id of immediate manager
    FROM Employees e1 LEFT JOIN Employees e2
    ON e1.manager_id = e2.employee_id
)

// storing manger id of manager of immediate manager
SELECT e1.employee_id
FROM cte e1 LEFT JOIN cte e2
ON e1.manager_id = e2.employee_id
WHERE e2.manager_id=1 AND e1.employee_id!=1
      

// Approach 2: Using commom table expression 
WITH Report_Head as(
    SELECT employee_id FROM Employees
    WHERE manager_id=1 AND employee_id!=1
), Second_Layer_Report as(
    SELECT employee_id FROM Employees
    WHERE manager_id IN (SELECT employee_id FROM Report_Head)
), Third_Layer_Report as(
    SELECT employee_id FROM Employees
    WHERE manager_id IN (SELECT employee_id FROM Second_Layer_Report)
)


// Approach 2: Using Recursive commom table expression 
SELECT employee_id FROM Report_Head
UNION
SELECT employee_id FROM Second_Layer_Report
UNION
SELECT employee_id FROM Third_Layer_Report

WITH recursive Cte AS (
    # Anchor
    SELECT employee_id, 0 as recursion_count
    FROM Employees
    WHERE manager_id = 1 AND employee_id != 1
    
    UNION ALL
    
    # Recursive no.
    SELECT e.employee_id, recursion_count+1
    FROM CTE c INNER JOIN Employees e ON c.employee_id = e.manager_id
    WHERE recursion_count < 2
)

SELECT employee_id
FROM cte
