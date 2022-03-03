# Write your MySQL query statement below
# SELECT c.name AS Customers FROM Customers c LEFT OUTER JOIN Orders o ON c.id = o.customerId WHERE o.id IS NULL;
SELECT c.name AS Customers FROM Customers c WHERE NOT EXISTS(SELECT * FROM Orders o WHERE o.customerId = c.id);
