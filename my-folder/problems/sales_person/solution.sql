# Write your MySQL query statement below
SELECT name
FROM SalesPerson
WHERE sales_id NOT IN (
    SELECT Orders.sales_id
    FROM Orders
    JOIN Company
    ON Orders.com_id = Company.com_id
    WHERE Company.name = 'RED'
);