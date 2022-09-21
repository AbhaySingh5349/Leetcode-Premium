Question Link: https://leetcode.com/problems/maximum-transaction-each-day/

SQL Schema
Table: Transactions

+----------------+----------+
| Column Name    | Type     |
+----------------+----------+
| transaction_id | int      |
| day            | datetime |
| amount         | int      |
+----------------+----------+
transaction_id is the primary key for this table.
Each row contains information about one transaction.
 
Write an SQL query to report the IDs of the transactions with the maximum amount on their respective day. 
Return the result table ordered by transaction_id in ascending order.

Input: 
Transactions table:
+----------------+--------------------+--------+
| transaction_id | day                | amount |
+----------------+--------------------+--------+
| 8              | 2021-4-3 15:57:28  | 57     |
| 9              | 2021-4-28 08:47:25 | 21     |
| 1              | 2021-4-29 13:28:30 | 58     |
| 5              | 2021-4-28 16:39:59 | 40     |
| 6              | 2021-4-29 23:39:28 | 58     |
+----------------+--------------------+--------+
Output: 
+----------------+
| transaction_id |
+----------------+
| 1              |
| 5              |
| 6              |
| 8              |
+----------------+
Explanation: 
"2021-4-3"  --> We have one transaction with ID 8, so we add 8 to the result table.
"2021-4-28" --> We have two transactions with IDs 5 and 9. The transaction with ID 5 has an amount of 40, while the transaction with ID 9 has an amount of 21. We only include the transaction with ID 5 as it has the maximum amount this day.
"2021-4-29" --> We have two transactions with IDs 1 and 6. Both transactions have the same amount of 58, so we include both in the result table.
We order the result table by transaction_id after collecting these IDs.

// Approach 1: Using common table expression
WITH cte1 as(
    SELECT transaction_id, DATE_FORMAT(day, '%Y-%m-%d') as day, amount
    FROM Transactions
), cte2 as(
    SELECT transaction_id, MAX(amount) OVER(PARTITION BY day) as max_amount, amount
    FROM cte1
)

SELECT transaction_id
FROM cte2
WHERE amount=max_amount
ORDER BY transaction_id

// Approach 2: Using sub-queries
SELECT transaction_id
FROM Transactions
WHERE (Date(day),amount) IN (SELECT Date(day), MAX(amount)
                             FROM Transactions
                             GROUP BY Date(day)
                             )
ORDER BY transaction_id
