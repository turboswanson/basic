INSERT INTO person_visits(id,person_id,pizzeria_id,visit_date)
VALUES(
        (SELECT MAX(id)+1 FROM person_visits),
        (SELECT p.id FROM person AS p WHERE p.name = 'Dmitriy'),
        (SELECT pz.id
         FROM pizzeria AS pz
         JOIN menu AS m
         ON m.price < 800 AND m.pizzeria_id = pz.id
         WHERE pz.name != 'Papa Johns'
         ORDER BY 1
         LIMIT 1
         ),'2022-01-08');

REFRESH MATERIALIZED VIEW mv_dmitriy_visits_and_eats;
