Question Link: https://leetcode.com/problems/ads-performance/

SQL Schema
Table: Ads

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| ad_id         | int     |
| user_id       | int     |
| action        | enum    |
+---------------+---------+
(ad_id, user_id) is the primary key for this table.
Each row of this table contains the ID of an Ad, the ID of a user, and the action taken by this user regarding this Ad.
The action column is an ENUM type of ('Clicked', 'Viewed', 'Ignored').
 

A company is running Ads and wants to calculate the performance of each Ad.

Performance of the Ad is measured using Click-Through Rate (CTR) where: CTR = (click count)/(click count + views count)

Write an SQL query to find the ctr of each Ad. Round ctr to two decimal points.

Return the result table ordered by ctr in descending order and by ad_id in ascending order in case of a tie.



Input: 
Ads table:
+-------+---------+---------+
| ad_id | user_id | action  |
+-------+---------+---------+
| 1     | 1       | Clicked |
| 2     | 2       | Clicked |
| 3     | 3       | Viewed  |
| 5     | 5       | Ignored |
| 1     | 7       | Ignored |
| 2     | 7       | Viewed  |
| 3     | 5       | Clicked |
| 1     | 4       | Viewed  |
| 2     | 11      | Viewed  |
| 1     | 2       | Clicked |
+-------+---------+---------+
Output: 
+-------+-------+
| ad_id | ctr   |
+-------+-------+
| 1     | 66.67 |
| 3     | 50.00 |
| 2     | 33.33 |
| 5     | 0.00  |
+-------+-------+
Explanation: 
for ad_id = 1, ctr = (2/(2+1)) * 100 = 66.67
for ad_id = 2, ctr = (1/(1+2)) * 100 = 33.33
for ad_id = 3, ctr = (1/(1+1)) * 100 = 50.00
for ad_id = 5, ctr = 0.00, Note that ad_id = 5 has no clicks or views.
Note that we do not care about Ignored Ads.

// Approach 1: Using commom table expression
WITH cte as(
    SELECT ad_id, SUM(CASE WHEN action = 'Clicked' THEN 1 ELSE 0 END) as clicks,
                  SUM(CASE WHEN action = 'Viewed' THEN 1 ELSE 0 END) as views
    FROM Ads
    GROUP BY ad_id
)

SELECT ad_id, IFNULL(ROUND(100*(clicks / (clicks+views)), 2), 0.00) as ctr
FROM cte
ORDER BY ctr DESC, ad_id

// Approach 2: 
SELECT ad_id, IFNULL(ROUND(AVG(CASE WHEN action = 'Clicked' THEN 1
                                    WHEN action = 'Viewed' THEN 0
                                    ELSE NULL END)*100,2), 0.00) AS ctr
FROM Ads
GROUP BY ad_id
ORDER BY ctr DESC, ad_id
