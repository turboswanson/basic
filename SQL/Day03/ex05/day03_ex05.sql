SELECT pz.name AS pizzeria_name
FROM person_visits AS pv
JOIN pizzeria AS pz
ON pz.id = pv.pizzeria_id
JOIN person AS p
ON p.name = 'Andrey'
WHERE pv.person_id = p.id
EXCEPT 
SELECT pz.name AS pizzeria_name
FROM person_order AS po
JOIN menu AS m
ON m.id = po.menu_id
JOIN pizzeria AS pz
ON pz.id = m.pizzeria_id
JOIN person AS p
ON p.name = 'Andrey'
WHERE p.id = po.person_id 
ORDER BY 1; 