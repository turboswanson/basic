CREATE OR REPLACE FUNCTION fnc_person_visits_and_eats_on_date(pperson VARCHAR DEFAULT 'Dmitriy',
                                                              pprice NUMERIC DEFAULT 500,
                                                              pdate DATE DEFAULT '2022-01-08')
RETURNS TABLE (pizzeria_name VARCHAR) AS $$
BEGIN
RETURN QUERY

    SELECT pz.name AS pizzzeria_name
    FROM pizzeria AS pz
    JOIN menu AS m
    ON m.pizzeria_id = pz.id
    JOIN person_visits AS pv
    ON pv.pizzeria_id = pz.id
    JOIN person AS p
    ON p.id = pv.person_id
    WHERE p.name = pperson AND m.price < pprice 
          AND pv.visit_date = pdate;
END;
$$ LANGUAGE plpgsql;                                                               

