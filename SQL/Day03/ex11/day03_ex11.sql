UPDATE menu AS m
SET price = price -(price*0.1)
WHERE m.pizza_name = 'greek pizza';
