// Problem Link: https://leetcode.com/problems/human-traffic-of-stadium/

with cte as(
select s1.id as id1,s2.id as id2,s3.id as id3 from Stadium s1
join Stadium s2
on s1.id+1=s2.id
join Stadium s3
on s1.id+2=s3.id
where s1.people>=100 and s2.people>=100 and s3.people>=100
),cte1 as(
select id1 as ids from cte
union
select id2 from cte
union
select id3 from cte
)
select id,visit_date,people from Stadium
where id in(select ids from cte1)
order by 2;
