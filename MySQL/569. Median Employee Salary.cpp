Question Link: https://leetcode.com/problems/median-employee-salary/

SQL Schema
Table: Employee

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| id           | int     |
| company      | varchar |
| salary       | int     |
+--------------+---------+
id is the primary key column for this table.
Each row of this table indicates the company and the salary of one employee.
 
Write an SQL query to find the rows that contain the median salary of each company

Input: 
Employee table:
+----+---------+--------+
| id | company | salary |
+----+---------+--------+
| 1  | A       | 2341   |
| 2  | A       | 341    |
| 3  | A       | 15     |
| 4  | A       | 15314  |
| 5  | A       | 451    |
| 6  | A       | 513    |
| 7  | B       | 15     |
| 8  | B       | 13     |
| 9  | B       | 1154   |
| 10 | B       | 1345   |
| 11 | B       | 1221   |
| 12 | B       | 234    |
| 13 | C       | 2345   |
| 14 | C       | 2645   |
| 15 | C       | 2645   |
| 16 | C       | 2652   |
| 17 | C       | 65     |
+----+---------+--------+
Output: 
+----+---------+--------+
| id | company | salary |
+----+---------+--------+
| 5  | A       | 451    |
| 6  | A       | 513    |
| 12 | B       | 234    |
| 9  | B       | 1154   |
| 14 | C       | 2645   |
+----+---------+--------+
Explanation: 
For company A, the rows sorted are as follows:
+----+---------+--------+
| id | company | salary |
+----+---------+--------+
| 3  | A       | 15     |
| 2  | A       | 341    |
| 5  | A       | 451    | <-- median
| 6  | A       | 513    | <-- median
| 1  | A       | 2341   |
| 4  | A       | 15314  |
+----+---------+--------+
For company B, the rows sorted are as follows:
+----+---------+--------+
| id | company | salary |
+----+---------+--------+
| 8  | B       | 13     |
| 7  | B       | 15     |
| 12 | B       | 234    | <-- median
| 11 | B       | 1221   | <-- median
| 9  | B       | 1154   |
| 10 | B       | 1345   |
+----+---------+--------+
For company C, the rows sorted are as follows:
+----+---------+--------+
| id | company | salary |
+----+---------+--------+
| 17 | C       | 65     |
| 13 | C       | 2345   |
| 14 | C       | 2645   | <-- median
| 15 | C       | 2645   | 
| 16 | C       | 2652   |
+----+---------+--------+

// Approach 1: Using common table expression
WITH cte1 as(
    SELECT *, ROW_NUMBER() OVER(PARTITION BY company ORDER BY salary ASC, id ASC) as row_num
    FROM Employee
    ORDER BY company, row_num
), cte2 as(
    SELECT *, 
    LAST_VALUE(row_num) OVER(PARTITION BY company ROWS BETWEEN UNBOUNDED PRECEDING AND UNBOUNDED FOLLOWING) as cnt
    FROM cte1
)

SELECT id, company, salary FROM cte2
WHERE ((cnt%2=0 AND (row_num = cnt/2 OR row_num = 1 + cnt/2)) OR (cnt%2!=0 AND row_num=(1+cnt)/2))

// Approach 2: Using common table expression
WITH cte as(
    SELECT *,
            ROW_NUMBER() OVER(PARTITION BY company ORDER BY salary ASC, id ASC) as row_num,
            COUNT(id) OVER(PARTITION BY company) as cnt
    FROM Employee
    ORDER BY company
)

SELECT id, company, salary FROM cte
WHERE row_num BETWEEN cnt/2 AND 1 + cnt/2

// Approach 3: Using common table expression
WITH cte as(
    SELECT *, 
    ROW_NUMBER() OVER(PARTITION BY company ORDER BY salary ASC, id ASC) as asc_row_num,
    ROW_NUMBER() OVER(PARTITION BY company ORDER BY salary DESC, id DESC) as desc_row_num
    FROM Employee
    ORDER BY company
)

SELECT id, company, salary
FROM cte 
WHERE ABS(CAST(asc_row_num AS SIGNED) - CAST(desc_row_num AS SIGNED)) BETWEEN 0 AND 1

// Approach 4:
SELECT MIN(A.Id) AS Id, A.Company, A.Salary
FROM Employee A INNER JOIN Employee B
ON A.Company = B.Company
GROUP BY A.Company, A.Salary
HAVING SUM(CASE WHEN B.Salary >= A.Salary then 1 ELSE 0 END) >= COUNT(*)/2
AND SUM(CASE WHEN B.Salary <= A.Salary then 1 ELSE 0 END) >= COUNT(*)/2
