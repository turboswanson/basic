SELECT p.name
FROM person AS p
JOIN person_order as po
ON po.person_id = p.id
JOIN menu AS m
ON m.id = po.menu_id
WHERE ((p.address = 'Moscow' OR p.address = 'Samara') AND p.gender = 'male')
       AND (m.pizza_name = 'pepperoni pizza' OR m.pizza_name = 'mushroom pizza')
ORDER BY 1 DESC;       