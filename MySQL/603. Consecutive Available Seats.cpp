Question Link: https://leetcode.com/problems/consecutive-available-seats/

SQL Schema
Table: Cinema

+-------------+------+
| Column Name | Type |
+-------------+------+
| seat_id     | int  |
| free        | bool |
+-------------+------+
seat_id is an auto-increment primary key column for this table.
Each row of this table indicates whether the ith seat is free or not. 1 means free while 0 means occupied.
 
Write an SQL query to report all the consecutive available seats in the cinema.
Return the result table ordered by seat_id in ascending order.


Input: 
Cinema table:
+---------+------+
| seat_id | free |
+---------+------+
| 1       | 1    |
| 2       | 0    |
| 3       | 1    |
| 4       | 1    |
| 5       | 1    |
+---------+------+
Output: 
+---------+
| seat_id |
+---------+
| 3       |
| 4       |
| 5       |
+---------+

// Approach 1: Using Join
SELECT DISTINCT c1.seat_id
FROM Cinema c1 
JOIN Cinema c2
WHERE (abs(c1.seat_id-c2.seat_id) = 1 AND c1.free=1 AND c2.free=1)
ORDER BY c1.seat_id
      

// Approach 2: Window functions
SELECT seat_id 
FROM (SELECT seat_id, CASE WHEN ((LAG(free) OVER (ORDER BY seat_id) = 1 
                                 OR LEAD(free) OVER (ORDER BY seat_id) = 1)
                                 AND free = 1) THEN 1 ELSE 0 END as is_consecutive FROM Cinema) c
WHERE (c.is_consecutive=1)
ORDER BY seat_id

// Approach 3: co-related sub-queries
SELECT seat_id 
FROM Cinema 
WHERE (free = 1 AND ((seat_id+1 IN (SELECT seat_id FROM Cinema WHERE free = 1)) 
                     OR (seat_id-1 IN (SELECT seat_id FROM Cinema WHERE free = 1))))
