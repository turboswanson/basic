SELECT name
FROM pizzeria
EXCEPT
SELECT DISTINCT name
FROM pizzeria
JOIN person_visits
ON pizzeria.id = person_visits.pizzeria_id


