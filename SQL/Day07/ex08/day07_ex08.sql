SELECT p.address,pz.name,COUNT(*)
FROM person_order AS po
JOIN menu AS m
ON m.id = po.menu_id
JOIN pizzeria AS pz
ON pz.id = m.pizzeria_id
JOIN person AS p
ON p.id = po.person_id
GROUP BY p.address,pz.name
ORDER BY 1,2;