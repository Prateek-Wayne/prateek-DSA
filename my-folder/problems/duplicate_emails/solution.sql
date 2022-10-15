# Write your MySQL query statement below
# Solution 1
# select email
# from person
# group by email   
# having count(email)>1;
select email
from
(select email,count(email)
 as c
from person
group by email) as sq
where c>1; 