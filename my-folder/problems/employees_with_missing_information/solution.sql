# Write your MySQL query statement below
# select Employees.employee_id from Employees right join Salaries on Employees.employee_id=Salaries.employee_id
# where name is null or Employees.employee_id is null or Salaries.employee_id is null order by employee_id 
# ;

SELECT e.employee_id  
FROM Employees e
LEFT JOIN Salaries s
ON s.employee_id=e.employee_id
WHERE s.salary IS NULL
 
UNION

SELECT s.employee_id 
FROM Salaries S
LEFT JOIN Employees e ON e.employee_id=s.employee_id
WHERE e.name IS NULL

ORDER BY employee_id;