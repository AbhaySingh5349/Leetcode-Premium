Question Link: https://leetcode.com/problems/department-highest-salary/

SQL Schema
Table: Employee

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| id           | int     |
| name         | varchar |
| salary       | int     |
| departmentId | int     |
+--------------+---------+
id is the primary key column for this table.
departmentId is a foreign key of the ID from the Department table.
Each row of this table indicates the ID, name, and salary of an employee. It also contains the ID of their department.
 

Table: Department

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
+-------------+---------+
id is the primary key column for this table.
Each row of this table indicates the ID of a department and its name.
 
Write an SQL query to find employees who have the highest salary in each of the departments.

Input: 
Employee table:
+----+-------+--------+--------------+
| id | name  | salary | departmentId |
+----+-------+--------+--------------+
| 1  | Joe   | 70000  | 1            |
| 2  | Jim   | 90000  | 1            |
| 3  | Henry | 80000  | 2            |
| 4  | Sam   | 60000  | 2            |
| 5  | Max   | 90000  | 1            |
+----+-------+--------+--------------+
Department table:
+----+-------+
| id | name  |
+----+-------+
| 1  | IT    |
| 2  | Sales |
+----+-------+
Output: 
+------------+----------+--------+
| Department | Employee | Salary |
+------------+----------+--------+
| IT         | Jim      | 90000  |
| Sales      | Henry    | 80000  |
| IT         | Max      | 90000  |
+------------+----------+--------+
Explanation: Max and Jim both have the highest salary in the IT department and Henry has the highest salary in the Sales department.

// Approach 1: Using common table expression
WITH cte as(
    SELECT *, MAX(salary) OVER(PARTITION BY departmentId) as max_salary
    FROM Employee
)

SELECT d.name as department, c.name as employee, c.max_salary as salary
FROM cte c INNER JOIN Department d 
ON (d.id = c.departmentId)
WHERE c.salary = c.max_salary

// Approach 2: Using Join
SELECT d.name as department, e.name as employee, salary
FROM Employee e INNER JOIN Department d
ON (d.id = e.departmentId)
WHERE (e.departmentId, e.salary) IN (SELECT departmentId, MAX(salary) 
                                     FROM Employee GROUP BY departmentId
                                    )
