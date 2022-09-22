Question Link: https://leetcode.com/problems/first-and-last-call-on-the-same-day/

SQL Schema
Table: Calls

+--------------+----------+
| Column Name  | Type     |
+--------------+----------+
| caller_id    | int      |
| recipient_id | int      |
| call_time    | datetime |
+--------------+----------+
(caller_id, recipient_id, call_time) is the primary key for this table.
Each row contains information about the time of a phone call between caller_id and recipient_id.
 
Write an SQL query to report the IDs of the users whose first and last calls on any day were with the same person. 
Calls are counted regardless of being the caller or the recipient.

Input: 
Calls table:
+-----------+--------------+---------------------+
| caller_id | recipient_id | call_time           |
+-----------+--------------+---------------------+
| 8         | 4            | 2021-08-24 17:46:07 |
| 4         | 8            | 2021-08-24 19:57:13 |
| 5         | 1            | 2021-08-11 05:28:44 |
| 8         | 3            | 2021-08-17 04:04:15 |
| 11        | 3            | 2021-08-17 13:07:00 |
| 8         | 11           | 2021-08-17 22:22:22 |
+-----------+--------------+---------------------+
Output: 
+---------+
| user_id |
+---------+
| 1       |
| 4       |
| 5       |
| 8       |
+---------+
Explanation: 
On 2021-08-24, the first and last call of this day for user 8 was with user 4. User 8 should be included in the answer.
Similarly, user 4 on 2021-08-24 had their first and last call with user 8. User 4 should be included in the answer.
On 2021-08-11, user 1 and 5 had a call. This call was the only call for both of them on this day. 
Since this call is the first and last call of the day for both of them, they should both be included in the answer.

// Approach 1: Using common table expression
WITH cte1 as(
    SELECT caller_id as p1, call_time, recipient_id as p2 FROM Calls
    UNION 
    SELECT recipient_id as p1, call_time, caller_id as p2 FROM Calls
), cte2 as(
    SELECT p1, DATE(call_time) as call_date,
           FIRST_VALUE(p2) OVER(PARTITION BY p1, DATE(call_time) ORDER BY call_time ASC) as first_call_id,
           LAST_VALUE(p2) OVER(PARTITION BY p1, DATE(call_time) ORDER BY call_time ASC ROWS BETWEEN UNBOUNDED PRECEDING AND UNBOUNDED FOLLOWING) as last_call_id
    FROM cte1
)

SELECT DISTINCT p1 as user_id
FROM cte2
WHERE first_call_id = last_call_id
GROUP BY p1, call_date
ORDER BY p1


// Approach 2: Using common table expression
WITH cte1 as(
    SELECT caller_id as p1, call_time, recipient_id as p2 FROM Calls
    UNION 
    SELECT recipient_id as p1, call_time, caller_id as p2 FROM Calls
), cte2 as(
    SELECT p1, p2, DATE(call_time) as call_date,
           RANK() OVER(PARTITION BY p1, DATE(call_time) ORDER BY call_time ASC) as first_call,
           RANK() OVER(PARTITION BY p1, DATE(call_time) ORDER BY call_time DESC) as last_call
    FROM cte1
)

SELECT DISTINCT c1.p1 as user_id
FROM cte2 c1 INNER JOIN cte2 c2
ON (c1.p1 = c2.p1 AND c1.p2 = c2.p2 AND c1.first_call=1 AND c2.last_call=1)
