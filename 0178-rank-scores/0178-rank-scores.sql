# Write your MySQL query statement below
select score,dense_rank() over (order by score desc) as 'rank' from Scores order by score desc; #dense_rank() is inbuilt sql fxn 