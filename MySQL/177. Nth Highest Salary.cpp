Question Link: https://leetcode.com/problems/nth-highest-salary/

SQL Schema
Table: Employee

+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| salary      | int  |
+-------------+------+
id is the primary key column for this table.
Each row of this table contains information about the salary of an employee.
 
Write an SQL query to report the nth highest salary from the Employee table. If there is no nth highest salary, the query should report null.

Input: 
Employee table:
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
n = 2
Output: 
+------------------------+
| getNthHighestSalary(2) |
+------------------------+
| 200                    |
+------------------------+

// Approach 1: 
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
DECLARE M INT;
SET M = N-1;
  RETURN (
      SELECT DISTINCT salary FROM Employee ORDER BY salary DESC
      LIMIT 1 OFFSET M 
  );
END

// Approach 2:
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      SELECT MAX(e1.Salary)
      FROM employee e1
      WHERE (SELECT COUNT(*) FROM (SELECT DISTINCT Salary FROM Employee) as e2 WHERE e2.Salary > e1.Salary) = N - 1
  );
END
