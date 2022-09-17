Question Link: https://leetcode.com/problems/page-recommendations/

SQL Schema
Table: Friendship

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user1_id      | int     |
| user2_id      | int     |
+---------------+---------+
(user1_id, user2_id) is the primary key for this table.
Each row of this table indicates that there is a friendship relation between user1_id and user2_id.
 

Table: Likes

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| user_id     | int     |
| page_id     | int     |
+-------------+---------+
(user_id, page_id) is the primary key for this table.
Each row of this table indicates that user_id likes page_id.
 

Write an SQL query to recommend pages to the user with user_id = 1 using the pages that your friends liked. It should not recommend pages you already liked.

Input: 
Friendship table:
+----------+----------+
| user1_id | user2_id |
+----------+----------+
| 1        | 2        |
| 1        | 3        |
| 1        | 4        |
| 2        | 3        |
| 2        | 4        |
| 2        | 5        |
| 6        | 1        |
+----------+----------+
Likes table:
+---------+---------+
| user_id | page_id |
+---------+---------+
| 1       | 88      |
| 2       | 23      |
| 3       | 24      |
| 4       | 56      |
| 5       | 11      |
| 6       | 33      |
| 2       | 77      |
| 3       | 77      |
| 6       | 88      |
+---------+---------+
Output: 
+------------------+
| recommended_page |
+------------------+
| 23               |
| 24               |
| 56               |
| 33               |
| 77               |
+------------------+
Explanation: 
User one is friend with users 2, 3, 4 and 6.
Suggested pages are 23 from user 2, 24 from user 3, 56 from user 3 and 33 from user 6.
Page 77 is suggested from both user 2 and user 3.
Page 88 is not suggested because user 1 already likes it.

// Approach 1: Using commom table expression
WITH friends as(
    SELECT user2_id as user_id FROM Friendship WHERE user1_id=1
    UNION ALL 
    SELECT user1_id as user_id FROM Friendship WHERE user2_id=1
), user_pages as(
    SELECT page_id FROM Likes
    WHERE user_id=1
), friends_pages as(
    SELECT l.page_id 
    FROM Likes l RIGHT JOIN friends f
    ON l.user_id = f.user_id 
    WHERE l.page_id IS NOT NULL
)

SELECT DISTINCT page_id as recommended_page
FROM friends_pages
WHERE page_id NOT IN (SELECT page_id FROM user_pages)
                   
 
// Approach 2: Using commom table expression
WITH friends as(
    SELECT CASE WHEN user1_id=1 THEN user2_id
                ELSE user1_id
                END as user_id
    FROM Friendship
    WHERE user1_id=1 OR user2_id=1
), user_pages as(
    SELECT page_id FROM Likes
    WHERE user_id=1
), friends_pages as(
    SELECT l.page_id 
    FROM Likes l RIGHT JOIN friends f
    ON l.user_id = f.user_id 
    WHERE l.page_id IS NOT NULL
)

SELECT DISTINCT page_id as recommended_page
FROM friends_pages
WHERE page_id NOT IN (SELECT page_id FROM user_pages)

                                           
// Approach 3: Using co-related subqueries
SELECT DISTINCT page_id as recommended_page
FROM (SELECT CASE WHEN user1_id=1 THEN user2_id
                  WHEN user2_id=1 THEN user1_id
                  END as user_id
      FROM Friendship) f LEFT JOIN Likes l
      ON f.user_id = l.user_id
      WHERE l.page_id IS NOT NULL AND page_id NOT IN (SELECT page_id FROM Likes WHERE user_id=1)
