INSERT INTO menu
VALUES (19, 2, 'greek pizza', 800);

INSERT INTO menu
VALUES ((SELECT MAX(id) + 1 FROM menu), (SELECT id FROM pizzeria WHERE name = 'Dominos'), 'sicilian pizza', 900);

INSERT INTO person_visits
VALUES ((SELECT MAX(id) + 1 FROM person_visits), (SELECT id FROM person WHERE name = 'Denis'),
        (SELECT id FROM pizzeria WHERE name = 'Dominos'), '2022-02-24');
INSERT INTO person_visits
VALUES ((SELECT MAX(id) + 1 FROM person_visits), (SELECT id FROM person WHERE name = 'Irina'),
        (SELECT id FROM pizzeria WHERE name = 'Dominos'), '2022-02-24');

INSERT INTO person_order
VALUES ((SELECT MAX(id) + 1 FROM person_order), (SELECT id FROM person WHERE name = 'Denis'),
        (SELECT id FROM menu WHERE pizza_name = 'sicilian pizza'), '2022-02-24');
INSERT INTO person_order
VALUES ((SELECT MAX(id) + 1 FROM person_order), (SELECT id FROM person WHERE name = 'Irina'),
        (SELECT id FROM menu WHERE pizza_name = 'sicilian pizza'), '2022-02-24');

UPDATE menu
SET price = price * 0.9
WHERE pizza_name='greek pizza';

INSERT INTO person_order
SELECT (SELECT MAX(id) FROM person_order) + gs,
       gs,
       (SELECT id FROM menu WHERE pizza_name = 'greek pizza'),
       '2022-02-25'
FROM generate_series((SELECT MIN(id) FROM person), (SELECT MAX(id) FROM person), 1) gs;

DELETE FROM person_order
WHERE order_date='2022-02-25';

DELETE FROM menu
WHERE pizza_name='greek pizza';

INSERT INTO person_visits
VALUES ((SELECT MAX(id) + 1 FROM person_visits),
        (SELECT id FROM person WHERE name = 'Dmitriy'), (SELECT pi.id
                                                         FROM menu m
                                                                  JOIN pizzeria pi ON pi.id = m.pizzeria_id
                                                         WHERE pi.name != 'Papa Johns'
                                                           AND m.price < 800
                                                         LIMIT 1), '2022-01-08');
