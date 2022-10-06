# Write your MySQL query statement below
SELECT c.name as 'Customers'    FROM Customers c LEFT JOIN Orders o ON c.id =o.customerId where o.customerId IS NULL ;
