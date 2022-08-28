Question Link: https://leetcode.com/problems/count-student-number-in-departments/

SQL Schema
Table: Student

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| student_id   | int     |
| student_name | varchar |
| gender       | varchar |
| dept_id      | int     |
+--------------+---------+
student_id is the primary key column for this table.
dept_id is a foreign key to dept_id in the Department tables.
Each row of this table indicates the name of a student, their gender, and the id of their department.
 

Table: Department

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| dept_id     | int     |
| dept_name   | varchar |
+-------------+---------+
dept_id is the primary key column for this table.
Each row of this table contains the id and the name of a department.
 

Write an SQL query to report the respective department name and number of students majoring in each department for all departments in the Department table (even ones with no current students).

Return the result table ordered by student_number in descending order. In case of a tie, order them by dept_name alphabetically.

Input: 
Student table:
+------------+--------------+--------+---------+
| student_id | student_name | gender | dept_id |
+------------+--------------+--------+---------+
| 1          | Jack         | M      | 1       |
| 2          | Jane         | F      | 1       |
| 3          | Mark         | M      | 2       |
+------------+--------------+--------+---------+
Department table:
+---------+-------------+
| dept_id | dept_name   |
+---------+-------------+
| 1       | Engineering |
| 2       | Science     |
| 3       | Law         |
+---------+-------------+
Output: 
+-------------+----------------+
| dept_name   | student_number |
+-------------+----------------+
| Engineering | 2              |
| Science     | 1              |
| Law         | 0              |
+-------------+----------------+

// Approach 1: Using co-related sub-queries
SELECT d.dept_name, (SELECT COUNT(*) FROM Student s WHERE s.dept_id = d.dept_id) as student_number
FROM Department d
ORDER BY student_number DESC, dept_name

// Approach 2: Using Join
SELECT d.dept_name, IFNULL(s.student_number,0) as student_number
FROM (SELECT dept_id, COUNT(*) as student_number FROM Student GROUP BY dept_id) s 
RIGHT OUTER JOIN Department d
ON (s.dept_id = d.dept_id)
ORDER BY s.student_number DESC, d.dept_name ASC

// Approach 3: Using Join
SELECT dept_name, IFNULL(COUNT(student_id),0) as student_number
FROM Student s
RIGHT OUTER JOIN Department d
ON (s.dept_id = d.dept_id)
GROUP BY dept_name
ORDER BY student_number DESC, d.dept_name ASC
