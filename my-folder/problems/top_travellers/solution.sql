# Write your MySQL query statement below
select  u.name,ifnull(sum(r.distance),0)as travelled_distance
from 
Users u
left  join 
Rides r
on 
u.id=r.user_id

group by  u.id
order by 
travelled_distance desc ,u.name 
;

# select u.name, ifnull(sum(r.distance), 0) as travelled_distance
# from users u left outer join rides r
# on u.id= r.user_id
# group by u.id
# order by travelled_distance desc, u.name