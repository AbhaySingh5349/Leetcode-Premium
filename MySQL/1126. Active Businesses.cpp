Question Link: https://leetcode.com/problems/active-businesses/

SQL Schema
Table: Events

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| business_id   | int     |
| event_type    | varchar |
| occurences    | int     | 
+---------------+---------+
(business_id, event_type) is the primary key of this table.
Each row in the table logs the info that an event of some type occurred at some business for a number of times.
 
The average activity for a particular event_type is the average occurences across all companies that have this event.
An active business is a business that has more than one event_type such that their occurences is strictly greater than the average activity for that event.

Write an SQL query to find all active businesses.

Input: 
Events table:
+-------------+------------+------------+
| business_id | event_type | occurences |
+-------------+------------+------------+
| 1           | reviews    | 7          |
| 3           | reviews    | 3          |
| 1           | ads        | 11         |
| 2           | ads        | 7          |
| 3           | ads        | 6          |
| 1           | page views | 3          |
| 2           | page views | 12         |
+-------------+------------+------------+
Output: 
+-------------+
| business_id |
+-------------+
| 1           |
+-------------+
Explanation:  
The average activity for each event can be calculated as follows:
- 'reviews': (7+3)/2 = 5
- 'ads': (11+7+6)/3 = 8
- 'page views': (3+12)/2 = 7.5
The business with id=1 has 7 'reviews' events (more than 5) and 11 'ads' events (more than 8), so it is an active business.

// Approach 1: Using commom table expression with SUM
WITH cte as(
    SELECT *, AVG(occurences) OVER (PARTITION BY event_type) as avg_occurance
    FROM Events
)
 
SELECT business_id
FROM cte
GROUP BY business_id
HAVING SUM( CASE WHEN occurences>avg_occurance THEN 1 ELSE 0 END) > 1
      

// Approach 2: Using commom table expression with COUNT
WITH cte as(
    SELECT *, AVG(occurences) OVER (PARTITION BY event_type) as avg_occurance
    FROM Events
)

SELECT business_id
FROM cte
WHERE occurences>avg_occurance
GROUP BY business_id
HAVING COUNT(event_type) > 1

// Approach 2: Using JOIN
SELECT business_id 
FROM (SELECT event_type, avg(occurences) as avg_occurences   
      FROM events as e1
      GROUP BY event_type
     ) as e1
JOIN events as e2 ON e1.event_type = e2.event_type   
WHERE e2.occurences > e1.avg_occurences             
GROUP BY business_id
HAVING COUNT(e1.event_type) > 1 
