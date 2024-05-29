CREATE VIEW v_price_with_discount AS
SELECT p.name,m.pizza_name,m.price,round(m.price-m.price*0.1) AS discount_price
FROM person_order AS po
JOIN person AS p
ON po.person_id = p.id
JOIN menu AS m
ON m.id = po.menu_id
ORDER BY 1,2;