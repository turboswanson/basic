SELECT p.name AS person_name,m.pizza_name,m.price,
       ROUND(m.price*((100-pd.discount)/100),2) AS discount_price,
       pz.name AS pizzeria_name
FROM person AS p
JOIN person_order AS po
ON po.person_id = p.id
JOIN menu AS m
ON m.id = po.menu_id
JOIN pizzeria AS pz
ON pz.id = m.pizzeria_id
JOIN person_discounts AS pd
ON p.id = pd.person_id AND pd.pizzeria_id = pz.id
ORDER BY 1,2;
