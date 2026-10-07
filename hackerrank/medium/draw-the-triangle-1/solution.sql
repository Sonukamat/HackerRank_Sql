/*
Enter your query here.
*/
with recursive numbers as (
    select 20 as n 
    union all
    select n-1
    from numbers
    where n >1
)
select repeat('* ',n)
from numbers;
