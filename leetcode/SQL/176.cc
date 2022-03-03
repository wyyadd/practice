# Write your MySQL query statement below
# SELECT salary AS SecondHighestSalary FROM Employee ORDER BY salary DESC LIMIT 1, 1;
SELECT 
    IFNULL((SELECT DISTINCT Salary 
     FROM Employee 
     ORDER BY Salary DESC 
     LIMIT 1, 1), NULL) AS SecondHighestSalary;
