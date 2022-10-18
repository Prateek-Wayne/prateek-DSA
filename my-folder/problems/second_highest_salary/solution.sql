# Write your MySQL query statement below

# select if (count(salary)>1 ,max(salary) ,null ) as SecondHighestSalary 
# from Employee
# where salary < (select max(salary) from Employee);
# select max(salary) as SecondHighestSalary from Employee
# where salary not in (select max(salary) from Employee)
# ;
select max(salary) as  SecondHighestSalary
from Employee
where salary not in (select max(salary) from Employee)
;
