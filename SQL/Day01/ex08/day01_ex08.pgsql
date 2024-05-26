SELECT order_date,t.name || '(age:'||t.age||')'
       AS person_information
FROM person_order
NATURAL JOIN
    (SELECT id AS person_id,name,age
     FROM person) AS t
ORDER BY 1,2     
      