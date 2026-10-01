/*
Enter your query here.
*/
SELECT DISTINCT F1.X, F1.Y
FROM Functions F1
WHERE
    (
        F1.X < F1.Y
        AND EXISTS (
            SELECT 1
            FROM Functions F2
            WHERE F2.X = F1.Y
              AND F2.Y = F1.X
        )
    )
    OR
    (
        F1.X = F1.Y
        AND EXISTS (
            SELECT 1
            FROM Functions F2
            WHERE F2.X = F1.X
              AND F2.Y = F1.Y
        )
        AND (
            SELECT COUNT(*)
            FROM Functions F2
            WHERE F2.X = F1.X
              AND F2.Y = F1.Y
        ) > 1
    )
ORDER BY F1.X, F1.Y;
