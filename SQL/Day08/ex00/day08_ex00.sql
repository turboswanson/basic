BEGIN;

UPDATE pizzeria
SET rating = 5.0
WHERE name = 'Pizza Hut';

SELECT *
FROM pizzeria
WHERE name = 'Pizza Hut';

COMMIT;
