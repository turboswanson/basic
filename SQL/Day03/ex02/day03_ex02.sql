SELECT m.pizza_name,m.price,pz.name AS pizzeria_name
FROM menu AS m
JOIN
    (SELECT m.id
     FROM menu as m
     EXCEPT
     SELECT po.menu_id
     FROM person_order AS po
     ORDER BY 1) as p1
ON p1.id = m.id
JOIN pizzeria as pz
ON pz.id = m.pizzeria_id
ORDER BY 1,2;     