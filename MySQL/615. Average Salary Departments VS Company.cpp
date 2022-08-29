Question Link: https://leetcode.com/problems/average-salary-departments-vs-company/

SQL Schema
Table: Salary

+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| employee_id | int  |
| amount      | int  |
| pay_date    | date |
+-------------+------+
id is the primary key column for this table.
Each row of this table indicates the salary of an employee in one month.
employee_id is a foreign key from the Employee table.
 

Table: Employee

+---------------+------+
| Column Name   | Type |
+---------------+------+
| employee_id   | int  |
| department_id | int  |
+---------------+------+
employee_id is the primary key column for this table.
Each row of this table indicates the department of an employee.
 

Write an SQL query to report comparison result (higher/lower/same) of average salary of employees in a department to company's average salary for each month.

Input: 
Salary table:
+----+-------------+--------+------------+
| id | employee_id | amount | pay_date   |
+----+-------------+--------+------------+
| 1  | 1           | 9000   | 2017/03/31 |
| 2  | 2           | 6000   | 2017/03/31 |
| 3  | 3           | 10000  | 2017/03/31 |
| 4  | 1           | 7000   | 2017/02/28 |
| 5  | 2           | 6000   | 2017/02/28 |
| 6  | 3           | 8000   | 2017/02/28 |
+----+-------------+--------+------------+
Employee table:
+-------------+---------------+
| employee_id | department_id |
+-------------+---------------+
| 1           | 1             |
| 2           | 2             |
| 3           | 2             |
+-------------+---------------+
Output: 
+-----------+---------------+------------+
| pay_month | department_id | comparison |
+-----------+---------------+------------+
| 2017-02   | 1             | same       |
| 2017-03   | 1             | higher     |
| 2017-02   | 2             | same       |
| 2017-03   | 2             | lower      |
+-----------+---------------+------------+
Explanation: 
In March, the company's average salary is (9000+6000+10000)/3 = 8333.33...
The average salary for department '1' is 9000, which is the salary of employee_id '1' since there is only one employee in this department. So the comparison result is 'higher' since 9000 > 8333.33 obviously.
The average salary of department '2' is (6000 + 10000)/2 = 8000, which is the average of employee_id '2' and '3'. So the comparison result is 'lower' since 8000 < 8333.33.

With the same formula for the average salary comparison in February, the result is 'same' since both the department '1' and '2' have the same average salary with the company, which is 7000.

// Approach 1: Using commom table expression
WITH cte as(
SELECT s.id, s.employee_id, e.department_id, s.amount, s.pay_date 
FROM Salary s
JOIN Employee e
ON (s.employee_id = e.employee_id)
)

SELECT dept_salary_table.pay_month, department_id, CASE WHEN department_avg>company_avg THEN 'higher'
                                                        WHEN department_avg<company_avg THEN 'lower'
                                                        ELSE 'same'
                                                   END as comparison
FROM (SELECT department_id, AVG(amount) as department_avg, DATE_FORMAT(pay_date, '%Y-%m') as pay_month
      FROM cte 
      GROUP BY department_id, pay_month
     ) as dept_salary_table
JOIN (SELECT AVG(amount) as company_avg, DATE_FORMAT(pay_date, '%Y-%m') as pay_month
      FROM cte 
      GROUP BY pay_month
     ) as company_salary_table
ON dept_salary_table.pay_month = company_salary_table.pay_month
      

// Approach 2:
SELECT dept_salary_table.pay_month, department_id, CASE WHEN department_avg>company_avg THEN 'higher'
                                                        WHEN department_avg<company_avg THEN 'lower'
                                                        ELSE 'same'
                                                   END as comparison
FROM (SELECT department_id, AVG(amount) as department_avg, DATE_FORMAT(pay_date, '%Y-%m') as pay_month
      FROM Salary JOIN employee ON Salary.employee_id = Employee.employee_id
      GROUP BY department_id, pay_month
     ) as dept_salary_table
JOIN (SELECT AVG(amount) as company_avg, DATE_FORMAT(pay_date, '%Y-%m') as pay_month
      FROM Salary
      GROUP BY pay_month
     ) as company_salary_table
ON dept_salary_table.pay_month = company_salary_table.pay_month
