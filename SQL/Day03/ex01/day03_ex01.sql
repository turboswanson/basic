SELECT m.id
FROM menu as m
EXCEPT
SELECT po.menu_id
FROM person_order AS po
ORDER BY 1;