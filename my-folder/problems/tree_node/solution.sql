# Write your MySQL query statement below

select id,
case when p_id is NUll then "Root" 
when id not in (select p_id from Tree where p_id is not null ) then "Leaf"
else "Inner"
end as type
from Tree
order by id ;