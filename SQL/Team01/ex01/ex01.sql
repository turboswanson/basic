SELECT COALESCE(u.name,'not defined') AS name,
       COALESCE(u.lastname,'not defined') AS lastname,     
       cur.name AS currency_name,
       (cur.rate_to_usd*b.money) AS currency_in_usd
FROM "user" AS u
FULL JOIN balance AS b
ON u.id = b.user_id
JOIN currency AS cur
ON  cur.rate_to_usd = COALESCE((SELECT rate_to_usd
                                FROM currency c
                                WHERE 
                                b.currency_id = c.id AND 
                                c.updated < b.updated
                                ORDER BY c.updated DESC
                                LIMIT 1),

				                (SELECT rate_to_usd
				                FROM currency c
				                WHERE 
                                b.currency_id = c.id AND 
                                c.updated > b.updated
				                ORDER BY c.updated ASC
				                LIMIT 1
				                ))
GROUP BY 1,2,3,4
ORDER BY 1 DESC,2,3;
 




