# Write your MySQL query statement below
# select v.customer_id , count(v.visit_id) as count_no_trans 
# from Visits v
# left join Transactions t
# on v.visit_id=t.transaction_id 
# group by  customer_id 
# order by count_no_trans desc;
# # where v.visit_id is null;
select customer_id, count(v.visit_id) as count_no_trans
from visits v
natural left join transactions t
where t.visit_id is null
group by customer_id
order by count_no_trans desc