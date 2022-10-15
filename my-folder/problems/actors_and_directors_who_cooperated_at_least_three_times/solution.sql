# Write your MySQL query statement below

# select actor_id,director_id
# from 
# (select 
# actor_id ,director_id ,count(timestamp) as c
# from ActorDirector
# group by actor_id
# ) 
# as temp
# where c>2
# and actor_id=director_id;
select actor_id,director_id
from 
ActorDirector
group by actor_id,director_id
having count(timestamp)>2;