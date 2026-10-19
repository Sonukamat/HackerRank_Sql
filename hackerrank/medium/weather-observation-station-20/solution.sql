/*
Enter your query here.
*/
WITH RankedLatitudes AS(
    SELECT
    LAT_N,
    ROW_NUMBER() OVER (ORDER BY LAT_N) AS rn,
    COUNT(*) OVER () AS total_rows
    from STATION
    
)
SELECT ROUND(AVG(LAT_N),4)
FROM RankedLatitudes
where rn IN (
    FLOOR((total_rows + 1)/2),
    FLOOR((total_rows +2)/2)
);
