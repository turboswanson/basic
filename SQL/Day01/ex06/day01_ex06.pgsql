SELECT action_date,person.name AS person_name
FROM
    (SELECT order_date AS action_date,person_id
    FROM person_order
    INTERSECT
    SELECT visit_date,person_id
    FROM person_visits) as t
JOIN person
ON t.person_id = person.id
ORDER BY 1, 2 DESC;