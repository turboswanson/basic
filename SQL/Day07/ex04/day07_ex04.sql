SELECT p.name,COUNT(*) AS visits_count
FROM person_visits AS pv
JOIN person AS p
ON p.id = pv.person_id
GROUP BY 1
HAVING COUNT(*) > 3;