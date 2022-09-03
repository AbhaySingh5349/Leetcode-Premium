Question Link: https://leetcode.com/problems/get-the-second-most-recent-activity/

SQL Schema
Table: UserActivity

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| username      | varchar |
| activity      | varchar |
| startDate     | Date    |
| endDate       | Date    |
+---------------+---------+
There is no primary key for this table. It may contain duplicates.
This table contains information about the activity performed by each user in a period of time.
A person with username performed an activity from startDate to endDate.
 
Write an SQL query to show the second most recent activity of each user.

If the user only has one activity, return that one. A user cannot perform more than one activity at the same time.

Input: 
UserActivity table:
+------------+--------------+-------------+-------------+
| username   | activity     | startDate   | endDate     |
+------------+--------------+-------------+-------------+
| Alice      | Travel       | 2020-02-12  | 2020-02-20  |
| Alice      | Dancing      | 2020-02-21  | 2020-02-23  |
| Alice      | Travel       | 2020-02-24  | 2020-02-28  |
| Bob        | Travel       | 2020-02-11  | 2020-02-18  |
+------------+--------------+-------------+-------------+
Output: 
+------------+--------------+-------------+-------------+
| username   | activity     | startDate   | endDate     |
+------------+--------------+-------------+-------------+
| Alice      | Dancing      | 2020-02-21  | 2020-02-23  |
| Bob        | Travel       | 2020-02-11  | 2020-02-18  |
+------------+--------------+-------------+-------------+
Explanation: 
The most recent activity of Alice is Travel from 2020-02-24 to 2020-02-28, before that she was dancing from 2020-02-21 to 2020-02-23.
Bob only has one record, we just take that one.

// Approach : Using commom table expression
WITH cte as(
    SELECT *, ROW_NUMBER() OVER(PARTITION BY username ORDER BY startDate DESC) as rnk,
              COUNT(startDate) OVER(PARTITION BY username) as activity_cnt
    FROM UserActivity
)

SELECT username, activity, startDate, endDate 
FROM cte
WHERE (rnk=2 OR (activity_cnt=1 AND rnk=1))
