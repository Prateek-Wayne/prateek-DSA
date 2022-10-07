# Write your MySQL query statement below
# select employee_id ,salary as'bonus' from Employees
# where not mod(employee_id,2)=0 and name not like 'M%' bonus=0;


# if (mod(employee_id,2)=0 and name not like 'M%',bonus=0,bonus=salary);


# where not mod(employee_id,2)=0 and name not like 'M%';
select employee_id ,if(mod(employee_id ,2) !=0 and name not like 'M%',salary,0) as 'bonus' 
from Employees order by employee_id ;