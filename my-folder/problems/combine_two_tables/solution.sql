# # Write your MySQL query statement below
# Insert Address into Person;
select p.firstName ,p.lastName,a.city,a.state
from Person p left join Address  a
on p.personId =a.personId where p.personId is Not null;