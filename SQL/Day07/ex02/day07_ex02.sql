(SELECT pz.name,COUNT(*),'visit' AS action_type
FROM person_visits AS pv
JOIN pizzeria AS pz
ON pz.id = pv.pizzeria_id
GROUP BY pz.name
ORDER BY 2 DESC,3
LIMIT 3)
UNION
(SELECT pz.name,COUNT(*),'order' AS action_type
FROM person_order AS po
JOIN menu AS m
ON m.id = po.menu_id
JOIN pizzeria AS pz
ON pz.id = m.pizzeria_id
GROUP BY 1
ORDER BY 2 DESC,3
LIMIT 3)
ORDER BY 3,2 DESC;