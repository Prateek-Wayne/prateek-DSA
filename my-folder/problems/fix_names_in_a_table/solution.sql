# Write your MySQL query statement below
# SELECT INITCAP(name) FROM Users;
# SELECT user_id, UPPER(LEFT(name,1))+SUBSTR(name,2) AS name FROM Users;
SELECT user_id,CONCAT(UPPER(LEFT(name,1)),LOWER(SUBSTR(name,2))) AS name FROM Users ORDER BY user_id         ;