# Write your MySQL query statement below
# select u.name ,sum(amount) as balance 
# from Transactions t
# join Users u
# on t.account =u.account 
# group by  u.name
# having sum(amount) > 10000

select u.name ,sum(t.amount) as balance
from Users u
join Transactions t
on u.account= t.account
group by u.name
having  balance >10000
;
