/*
Enter your query here.
*/
with recursive numbers(n) as
(
    select 1
    union all
    select n+1
    from numbers
    where n<20
)
select repeat('* ',n)
from numbers;
