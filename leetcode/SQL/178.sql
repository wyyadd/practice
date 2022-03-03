# Write your MySQL query statement below
SELECT
  s.score,
  (SELECT COUNT(DISTINCT score) FROM Scores WHERE score > s.score) + 1 AS 'rank'
FROM Scores s
ORDER BY s.score DESC;
