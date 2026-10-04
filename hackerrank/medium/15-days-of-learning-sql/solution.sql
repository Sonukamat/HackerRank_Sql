/*
Enter your query here.
*/
SELECT
    s.submission_date,

    COUNT(DISTINCT CASE
        WHEN s.hacker_id IN (
            SELECT s2.hacker_id
            FROM Submissions s2
            WHERE s2.submission_date <= s.submission_date
            GROUP BY s2.hacker_id
            HAVING COUNT(DISTINCT s2.submission_date)
                   = DATEDIFF(s.submission_date, '2016-03-01') + 1
        )
        THEN s.hacker_id
    END) AS unique_hackers,

    (
        SELECT s3.hacker_id
        FROM Submissions s3
        WHERE s3.submission_date = s.submission_date
        GROUP BY s3.hacker_id
        ORDER BY COUNT(*) DESC, s3.hacker_id ASC
        LIMIT 1
    ) AS hacker_id,

    (
        SELECT h.name
        FROM Hackers h
        JOIN Submissions s4
            ON h.hacker_id = s4.hacker_id
        WHERE s4.submission_date = s.submission_date
        GROUP BY h.hacker_id, h.name
        ORDER BY COUNT(*) DESC, h.hacker_id ASC
        LIMIT 1
    ) AS name

FROM Submissions s
WHERE s.submission_date BETWEEN '2016-03-01' AND '2016-03-15'
GROUP BY s.submission_date
ORDER BY s.submission_date;
