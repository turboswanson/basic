WITH RECURSIVE
    routes AS (
        SELECT
            point1 AS tour,
            point1,
            point2,
            cost,
            cost AS summ,
            1 AS step
        FROM cities
        WHERE
            point1 = 'a'
        UNION
        SELECT
            tour || ',' || recurse.point1 AS tour,
            recurse.point1,
            recurse.point2,
            recurse.cost,
            summ + recurse.cost AS summ,
            step + 1
        FROM
            cities AS recurse
            JOIN
                routes
                ON recurse.point1 = routes.point2
        WHERE
            tour NOT LIKE '%' || recurse.point1 || '%'
),
max_steps AS (
    SELECT
        *
    FROM
        routes
    WHERE
        step = (
            SELECT
                MAX(step)
            FROM
                routes
        )
)

SELECT
    summ,
    '{' || tour || ',' || point2 || '}' AS tour
FROM
    max_steps
WHERE
    tour LIKE 'a' || '%'
    AND point2 = 'a'
ORDER BY 1, 2;
