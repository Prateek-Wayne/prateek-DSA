# Write your MySQL query statement below
select w1.id
from weather w1,weather w2
where w1.temperature >w2.temperature and datediff(w1.recordDate,w2.recordDate)=1;
