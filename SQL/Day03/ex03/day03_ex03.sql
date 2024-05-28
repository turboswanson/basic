(SELECT pz.name AS pizzeria_name
FROM pizzeria AS pz
JOIN person_visits AS pv
ON pv.pizzeria_id = pz.id
JOIN person AS p
ON p.id = pv.person_id
WHERE p.gender = 'male'
EXCEPT ALL
SELECT pz.name AS pizzeria_name
FROM pizzeria AS pz
JOIN person_visits AS pv
ON pv.pizzeria_id = pz.id
JOIN person AS p
ON p.id = pv.person_id
WHERE p.gender = 'female')
UNION ALL
(SELECT pz.name AS pizzeria_name
FROM pizzeria AS pz
JOIN person_visits AS pv
ON pv.pizzeria_id = pz.id
JOIN person AS p
ON p.id = pv.person_id
WHERE p.gender = 'female'
EXCEPT ALL
SELECT pz.name AS pizzeria_name
FROM pizzeria AS pz
JOIN person_visits AS pv
ON pv.pizzeria_id = pz.id
JOIN person AS p
ON p.id = pv.person_id
WHERE p.gender = 'male')
ORDER BY 1;
