CREATE MATERIALIZED VIEW mv_dmitriy_visits_and_eats AS
SELECT pz.name
FROM person_visits AS pv
JOIN pizzeria AS pz
ON pz.id = pv.pizzeria_id
JOIN menu AS m
ON m.pizzeria_id = pz.id
WHERE pv.person_id = (SELECT p.id FROM person AS p WHERE p.name = 'Dmitriy')
AND pv.visit_date = '2022-01-08' AND m.price < 800; 
