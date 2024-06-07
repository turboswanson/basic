SELECT p.name
FROM person_order AS po
JOIN person AS p
ON p.id = po.person_id
GROUP BY 1
ORDER BY 1;