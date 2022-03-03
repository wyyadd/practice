# Write your MySQL query statement below
SELECT t.Department, e2.name AS Employee, e2.salary AS Salary
FROM (
  SELECT MAX(salary) AS Salary, d.name AS Department, d.id FROM Employee e, Department d WHERE e.departmentId = d.id 
GROUP BY d.name, d.id
) AS t, Employee e2 
WHERE e2.DepartmentId = t.id AND e2.salary = t.Salary;
