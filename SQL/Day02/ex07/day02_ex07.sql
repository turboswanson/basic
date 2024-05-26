
SELECT pz.name AS pizzeria_name
FROM pizzeria AS pz
JOIN person_visits AS pv
ON pv.pizzeria_id = pz.id
JOIN person AS p
ON p.id = pv.person_id
JOIN menu AS m
ON m.pizzeria_id = pv.pizzeria_id
WHERE m.price < 800 AND p.name = 'Dmitriy' AND pv.visit_date = '2022-01-08';