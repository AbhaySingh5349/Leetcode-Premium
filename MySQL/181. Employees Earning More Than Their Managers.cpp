Question Link: https://leetcode.com/problems/department-highest-salary/

SQL Schema
Table: Employee

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| salary      | int     |
| managerId   | int     |
+-------------+---------+
id is the primary key column for this table.
Each row of this table indicates the ID of an employee, their name, salary, and the ID of their manager.
 
Write an SQL query to find the employees who earn more than their managers.

Input: 
Employee table:
+----+-------+--------+-----------+
| id | name  | salary | managerId |
+----+-------+--------+-----------+
| 1  | Joe   | 70000  | 3         |
| 2  | Henry | 80000  | 4         |
| 3  | Sam   | 60000  | Null      |
| 4  | Max   | 90000  | Null      |
+----+-------+--------+-----------+
Output: 
+----------+
| Employee |
+----------+
| Joe      |
+----------+
Explanation: Joe is the only employee who earns more than his manager.

// Approach 1: Using Sub-query
SELECT e1.name as 'Employee'
FROM Employee e1
WHERE e1.salary > (SELECT e2.salary FROM Employee e2 
                                    WHERE e1.managerId = e2.id
                  )

// Approach 2: Using Join
SELECT e1.name as 'Employee'
FROM Employee e1 INNER JOIN Employee e2
ON (e1.managerId = e2.id)
WHERE e1.salary > e2.salary
