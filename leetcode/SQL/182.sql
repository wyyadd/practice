# Write your MySQL query statement below
SELECT p.email FROM Person p GROUP BY p.email HAVING COUNT(p.id) > 1;
