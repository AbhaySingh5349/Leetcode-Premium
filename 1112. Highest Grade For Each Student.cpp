Question Link: https://leetcode.com/problems/highest-grade-for-each-student/

SQL Schema
Table: Enrollments

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| student_id    | int     |
| course_id     | int     |
| grade         | int     |
+---------------+---------+
(student_id, course_id) is the primary key of this table.

Write a SQL query to find the highest grade with its corresponding course for each student. In case of a tie, find smallest course_id.
Return the result table ordered by student_id in ascending order.

Input: 
Enrollments table:
+------------+-------------------+
| student_id | course_id | grade |
+------------+-----------+-------+
| 2          | 2         | 95    |
| 2          | 3         | 95    |
| 1          | 1         | 90    |
| 1          | 2         | 99    |
| 3          | 1         | 80    |
| 3          | 2         | 75    |
| 3          | 3         | 82    |
+------------+-----------+-------+
Output: 
+------------+-------------------+
| student_id | course_id | grade |
+------------+-----------+-------+
| 1          | 2         | 99    |
| 2          | 2         | 95    |
| 3          | 3         | 82    |
+------------+-----------+-------+

// Approach 1: Using commom table expression
WITH cte as(
    SELECT student_id, course_id, grade , MAX(grade) OVER (PARTITION BY student_id) as max_grade
    FROM Enrollments
    ORDER BY student_id, grade DESC, course_id 
)

SELECT student_id, course_id, grade 
FROM cte 
GROUP BY student_id
      

// Approach 2: Using co-related subqueries
SELECT student_id, MIN(course_id) as course_id, grade
FROM Enrollments
WHERE (student_id, grade) IN (SELECT student_id, MAX(grade)
                              FROM Enrollments
                              GROUP BY student_id
                              )
GROUP BY student_id
ORDER BY student_id
