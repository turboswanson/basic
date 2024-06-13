WITH last_rate AS(
    SELECT id,MAX(updated) AS updated
    FROM currency
    GROUP BY 1
),
rate AS(
    SELECT cur.id,cur.name,cur.rate_to_usd,cur.updated
    FROM currency AS cur
    JOIN last_rate AS r
    ON r.id = cur.id AND r.updated = cur.updated
)

SELECT  COALESCE(u.name,'not defined') AS name,
        COALESCE(u.lastname,'not defined') AS lastname,
        type,
        SUM(money) AS volume,
        COALESCE(r.name,'not defined') AS currency_name,
        COALESCE(r.rate_to_usd, 1) AS last_rate_to_usd,
        SUM(money)*COALESCE(r.rate_to_usd, 1) AS total_volume_is_usd
FROM balance AS b
FULL JOIN "user" AS u
ON u.id = b.user_id
FULL JOIN rate AS r
ON r.id = b.currency_id
GROUP BY 1,2,3,5,6
ORDER BY 1 DESC,2,3;



