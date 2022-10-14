# Write your MySQL query statement below
Select
    stock_name
,   Sum(Case When operation = 'Buy' then price * -1 Else price End) 'capital_gain_loss'
From Stocks
Group By stock_name
Order By capital_gain_loss
