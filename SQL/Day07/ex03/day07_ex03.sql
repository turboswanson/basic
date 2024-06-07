SELECT t1.name,(COALESCE(t1.count,0)+COALESCE(t2.count,0)) AS total_count
FROM
(
    (SELECT pz.name,COUNT(*) AS count
    FROM person_visits AS pv
    JOIN pizzeria AS pz
    ON pz.id = pv.pizzeria_id
    GROUP BY 1
    ) AS t1

    FULL JOIN

    (SELECT pz.name,COUNT(*) AS count
    FROM person_order AS po
    JOIN menu AS m
    ON m.id = po.menu_id
    JOIN pizzeria AS pz
    ON pz.id = m.pizzeria_id
    GROUP BY 1
 
    ) AS t2
    ON t1.name = t2.name
)
ORDER BY 2 DESC,1;